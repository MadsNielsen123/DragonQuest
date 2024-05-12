#include "databasehandler.h"
#include <random>

DatabaseHandler::DatabaseHandler(const QString &username, const QString &password)
{
    mDB = QSqlDatabase::addDatabase("QMYSQL");
    mDB.setHostName("localhost");
    mDB.setDatabaseName("dragon_quest");
    mDB.setUserName(username);
    mDB.setPassword(password);
    if(!mDB.open())
    {
        std::cout << "Failed to open Database" << std::endl;
        exit(0);
    }
    mQ = QSqlQuery(mDB);
}

DatabaseHandler::~DatabaseHandler()
{
    mDB.close();
}

std::vector<Hero> DatabaseHandler::getHeroes()
{
    std::vector<Hero> heroes;
    Hero hero;

    mQ.exec("SELECT * FROM hero");
    while(mQ.next())
    {
        hero.setID(mQ.value(0).toInt());
        hero.setName(mQ.value(1).toString().toStdString());
        hero.setLevel(mQ.value(2).toInt());
        hero.setXP(mQ.value(3).toInt());
        hero.setHP(mQ.value(4).toInt());
        hero.setAP(mQ.value(5).toInt());
        hero.setGold(mQ.value(6).toInt());
        hero.setMP(mQ.value(7).toInt());
        hero.heal();
        heroes.push_back(hero);
    }

    return heroes;
}

unsigned int DatabaseHandler::addHero(const Hero &hero)
{
    mQ.prepare("INSERT INTO hero (name, level, xp, hp, ap, gold, mp) VALUES (:name, :level, :xp, :hp, :ap, :gold, :mp)");
    mQ.bindValue(":name", QString::fromStdString(hero.getName()));
    mQ.bindValue(":level", hero.getLevel());
    mQ.bindValue(":xp", hero.getXP());
    mQ.bindValue(":hp", hero.getHP());
    mQ.bindValue(":ap", hero.getAP());
    mQ.bindValue(":gold", hero.getGold());
    mQ.bindValue(":mp", hero.getMP());
    mQ.exec();

    mQ.exec("SELECT MAX(hero_id) FROM hero");
    mQ.next();
    return mQ.value(0).toUInt();
}

void DatabaseHandler::saveHero(const Hero &hero)
{
    mQ.prepare("UPDATE hero SET level = :level, xp = :xp, hp = :hp, ap = :ap, gold = :gold, mp = :mp WHERE hero_id = :heroId");
    mQ.bindValue(":level", hero.getLevel());
    mQ.bindValue(":xp", hero.getXP());
    mQ.bindValue(":hp", hero.getHP());
    mQ.bindValue(":ap", hero.getAP());
    mQ.bindValue(":heroId", hero.getID());
    mQ.bindValue(":gold", hero.getGold());
    mQ.bindValue(":mp", hero.getMP());
    mQ.exec();
}

std::vector<Monster> DatabaseHandler::getMonsters()
{
    std::vector<Monster> monsters;
    Monster monster;

    mQ.exec("SELECT * FROM monster");
    while(mQ.next())
    {
        monster.setID(mQ.value(0).toInt());
        monster.setName(mQ.value(1).toString().toStdString());
        monster.setLevel(mQ.value(2).toInt());
        monster.setHP(mQ.value(3).toInt());
        monster.setAP(mQ.value(4).toInt());
        monster.setKillXP(mQ.value(5).toInt());
        monster.heal();
        monsters.push_back(monster);
    }

    for(int i=0; i<monsters.size(); ++i)
    {
        mQ.prepare("select element.* from element join monster_element on element.element_id = monster_element.element_id where monster_id = :monsterID");
        mQ.bindValue(":monsterID", monsters[i].getID());
        mQ.exec();

        while(mQ.next())
        {
            monsters[i].addElement(mQ.value(0).toInt(), mQ.value(1).toString().toStdString(), mQ.value(2).toInt(), mQ.value(3).toInt(), mQ.value(4).toInt());
        }
    }

    return monsters;
}

std::vector<Cave> DatabaseHandler::getCaves(const Hero& hero)
{
    std::vector<Cave> caves;
    Cave cave;

    mQ.prepare("SELECT * FROM cave where hero_id = :heroID ORDER BY cave_id DESC LIMIT 5"); //only load hero's last 5 caves
    mQ.bindValue(":heroID", hero.getID());
    mQ.exec();
    while(mQ.next())
    {
        cave.setID(mQ.value(0).toInt());
        cave.setName(mQ.value(1).toString().toStdString());
        cave.setWinGold(mQ.value(2).toInt());
        cave.setWinXP(mQ.value(3).toInt());
        cave.setLevel(mQ.value(4).toInt());
        cave.setConqueredStatus(mQ.value(5).toBool());
        cave.setHeroID(mQ.value(6).toInt());
        caves.push_back(cave);
    }

    return caves;
}

void DatabaseHandler::generateNewCaves(const Hero& hero)
{
    std::string name = "";
    unsigned int gold = 0, xp = 0;
    int level = 1;
    srand((unsigned int)time(NULL));
    for(int i = 0; i<5; ++i)
    {
        //Generate a radnom name
        mQ.exec("SELECT * FROM cave_first_name ORDER BY RAND() LIMIT 1");
        if(mQ.next())
        {
           name = mQ.value(0).toString().toStdString();
        }

        //Weight first row (" Cave") higher
        mQ.exec("SELECT * FROM cave_second_name ORDER BY IF(nr = (SELECT MIN(nr) FROM cave_second_name), RAND() * 0.09, RAND()) LIMIT 1;");
        if(mQ.next())
        {
           name += mQ.value(1).toString().toStdString();
        }


        //Random gold, xp and level
        level = hero.getLevel() + (rand()%7 - 3); //random number between -3 and 3
        if(level < 1)
            level = 1;
        gold = 10*level;
        xp = 125*level;

        //Add cave to database
        mQ.prepare("INSERT INTO cave (name, gold, xp, level, hero_id) VALUES (:name, :gold, :xp, :level, :heroID)");
        mQ.bindValue(":name", QString::fromStdString(name));
        mQ.bindValue(":gold", gold);
        mQ.bindValue(":xp", xp);
        mQ.bindValue(":level", level);
        mQ.bindValue(":heroID", hero.getID());
        mQ.exec();

        //Add monsters to the cave:
        unsigned int levelFilled = 0;
        unsigned int monsterID = 0;
        while(levelFilled < level) //keep filling monster into the cave until sum(monsters levels) adds up to the caves level
        {
            mQ.prepare("SELECT * FROM monster where level<=:maxLevel ORDER BY RAND() LIMIT 1 "); //select a random monster that doesnt surpass caves level
            mQ.bindValue(":maxLevel", level-levelFilled);
            mQ.exec();
            if(mQ.next())
            {
                monsterID = mQ.value(0).toInt();
                levelFilled += mQ.value(2).toInt(); //Add monster's level to cave
                std::cout << std::to_string(level) + " :" + std::to_string(levelFilled) << std::endl;
            }

            //Add the monster to the db
            mQ.prepare("INSERT INTO cave_monster (cave_id, monster_id) VALUES ((SELECT cave_id FROM cave ORDER BY cave_id DESC LIMIT 1), :monsterID)");
            mQ.bindValue(":monsterID", monsterID);
            mQ.exec();

        }

    }
}

void DatabaseHandler::saveCave(const Cave& cave)
{
    mQ.prepare("UPDATE cave SET name = :name, gold = :gold, xp = :xp, level = :level, conquered = :conquered WHERE cave_id = :caveID");
    mQ.bindValue(":name", QString::fromStdString(cave.getName()));
    mQ.bindValue(":gold", cave.getWinGold());
    mQ.bindValue(":xp", cave.getWinXP());
    mQ.bindValue(":level", cave.getLevel());
    mQ.bindValue(":conquered", cave.isConquered());
    mQ.bindValue(":caveID", cave.getID());
    mQ.exec();
}

std::vector<Monster> DatabaseHandler::getCaveMonsters(const Cave& cave)
{
    std::vector<Monster> monsters;
    Monster monster;

    mQ.prepare("select monster.* from cave Join cave_monster ON cave.cave_id = cave_monster.cave_id Join monster ON cave_monster.monster_id = monster.monster_id where cave.cave_id = :caveID");
    mQ.bindValue(":caveID", cave.getID());
    mQ.exec();

    while(mQ.next())
    {
        monster.setID(mQ.value(0).toInt());
        monster.setName(mQ.value(1).toString().toStdString());
        monster.setLevel(mQ.value(2).toInt());
        monster.setHP(mQ.value(3).toInt());
        monster.setAP(mQ.value(4).toInt());
        monster.setKillXP(mQ.value(5).toInt());
        monster.heal();
        monsters.push_back(monster);
    }

    for(Monster& monster: monsters)
    {
        mQ.prepare("select element.* from element join monster_element on element.element_id = monster_element.element_id where monster_id = :monsterID");
        mQ.bindValue(":monsterID", monster.getID());
        mQ.exec();

        while(mQ.next())
        {
            monster.addElement(mQ.value(0).toInt(), mQ.value(1).toString().toStdString(), mQ.value(2).toInt(), mQ.value(3).toInt(), mQ.value(4).toInt());
        }
    }

    return monsters;
}


std::vector<Magic> DatabaseHandler::getBuyableMagics(const Hero &hero)
{
    std::vector<Magic> magics;
    Magic magic;

    //Query that finds available to buy Magics

    mQ.prepare("SELECT m.* FROM magic AS m LEFT JOIN hero_magic AS hm1 ON m.magic_id = hm1.magic_id AND hm1.hero_id = :heroID LEFT JOIN magic AS m2 ON m.upgradeOf = m2.magic_id LEFT JOIN hero_magic AS hm2 ON m2.magic_id = hm2.magic_id AND hm2.hero_id = :heroID WHERE hm1.hero_id IS NULL AND (m.upgradeOf IS NULL OR hm2.hero_id = :heroID)");
    mQ.bindValue(":heroID", hero.getID());
    mQ.exec();

    while(mQ.next())
    {
        magic.setID(mQ.value(0).toInt());
        magic.setName(mQ.value(1).toString().toStdString());
        magic.setDamage(mQ.value(2).toInt());
        magic.setSelfDamage(mQ.value(3).toInt());
        magic.setPrice(mQ.value(4).toInt());
        magic.setElement(mQ.value(5).toInt());
        magic.setRequiredID(mQ.value(6).toInt());
        magics.push_back(magic);
    }

    for(int i = 0; i<magics.size(); ++i)
    {
        mQ.prepare("select name, R, G, B from element where element_id = :elementID");
        mQ.bindValue(":elementID", magics[i].getElement());
        mQ.exec();
        mQ.next();
        magics[i].setElementName(mQ.value(0).toString().toStdString());
        magics[i].setR(mQ.value(1).toInt());
        magics[i].setG(mQ.value(2).toInt());
        magics[i].setB(mQ.value(3).toInt());
    }

    return magics;
}


void DatabaseHandler::giveHeroMagic(const Hero &hero, unsigned int magicID)
{
    mQ.prepare("insert into hero_magic(hero_id, magic_id) VALUES (:heroID, :magicID)");
    mQ.bindValue(":heroID", hero.getID());
    mQ.bindValue(":magicID", magicID);
    mQ.exec();
}

std::vector<Magic> DatabaseHandler::getHeroMagics(const Hero& hero)
{
    std::vector<Magic> magics;
    Magic magic;
    mQ.prepare("SELECT m.* FROM hero_magic AS hm JOIN magic AS m ON hm.magic_id = m.magic_id LEFT JOIN magic AS m_upgrade ON m.magic_id = m_upgrade.upgradeOf LEFT JOIN hero_magic AS hm_upgrade ON m_upgrade.magic_id = hm_upgrade.magic_id AND hm.hero_id = hm_upgrade.hero_id WHERE hm.hero_id = :heroID AND hm_upgrade.hero_id IS NULL");
    mQ.bindValue(":heroID", hero.getID());
    mQ.exec();

    while(mQ.next())
    {
        magic.setID(mQ.value(0).toInt());
        magic.setName(mQ.value(1).toString().toStdString());
        magic.setDamage(mQ.value(2).toInt());
        magic.setSelfDamage(mQ.value(3).toInt());
        magic.setPrice(mQ.value(4).toInt());
        magic.setElement(mQ.value(5).toInt());
        magic.setRequiredID(mQ.value(6).toInt());
        magics.push_back(magic);
    }

    for(int i = 0; i<magics.size(); ++i)
    {
        mQ.prepare("select name, R, G, B from element where element_id = :elementID");
        mQ.bindValue(":elementID", magics[i].getElement());
        mQ.exec();
        mQ.next();
        magics[i].setElementName(mQ.value(0).toString().toStdString());
        magics[i].setR(mQ.value(1).toInt());
        magics[i].setG(mQ.value(2).toInt());
        magics[i].setB(mQ.value(3).toInt());
    }

    return magics;
}

double DatabaseHandler::getDamageModifier(const Magic& magic, Monster& monster)
{
    double modifier = 1;

    //Check Monsters Weakness
    mQ.prepare("SELECT * FROM monster AS m JOIN monster_element AS me ON m.monster_id = me.monster_id JOIN element_weakness AS ew ON me.element_id = ew.element_id WHERE m.monster_id = :monsterID AND ew.weakness_id = :elementID");
    mQ.bindValue(":monsterID", monster.getID());
    mQ.bindValue(":elementID", magic.getElement());
    mQ.exec();
    if(mQ.next()) //Monster is weak for that Magic's element
        modifier *= 2;

    //Check Monsters Strength
    mQ.prepare("SELECT * FROM monster AS m JOIN monster_element AS me ON m.monster_id = me.monster_id JOIN element_strength AS es ON me.element_id = es.element_id WHERE m.monster_id = :monsterID AND es.strength_id = :elementID");
    mQ.bindValue(":monsterID", monster.getID());
    mQ.bindValue(":elementID", magic.getElement());
    mQ.exec();
    if(mQ.next()) //Monster is strong against that Magic's element
        modifier *= 0.25;

    //Check Monsters Resistance
    mQ.prepare("SELECT * FROM monster AS m JOIN monster_element AS me ON m.monster_id = me.monster_id JOIN element_resistance AS er ON me.element_id = er.element_id WHERE m.monster_id = :monsterID AND er.resistance_id = :elementID");
    mQ.bindValue(":monsterID", monster.getID());
    mQ.bindValue(":elementID", magic.getElement());
    mQ.exec();
    if(mQ.next()) //Monster is resistant to that Magic's element
        modifier  *= 0.50;

    return modifier;
}
