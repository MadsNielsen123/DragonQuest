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
        hero.heal();
        heroes.push_back(hero);
    }

    return heroes;
}

unsigned int DatabaseHandler::addHero(const Hero &hero)
{
    mQ.prepare("INSERT INTO hero (name, level, xp, hp, ap, gold) VALUES (:name, :level, :xp, :hp, :ap, :gold)");
    mQ.bindValue(":name", QString::fromStdString(hero.getName()));
    mQ.bindValue(":level", hero.getLevel());
    mQ.bindValue(":xp", hero.getXP());
    mQ.bindValue(":hp", hero.getHP());
    mQ.bindValue(":ap", hero.getAP());
    mQ.bindValue(":gold", hero.getGold());
    mQ.exec();

    mQ.exec("SELECT MAX(hero_id) FROM hero");
    mQ.next();
    return mQ.value(0).toUInt();
}

void DatabaseHandler::saveHero(const Hero &hero)
{
    mQ.prepare("UPDATE hero SET level = :level, xp = :xp, hp = :hp, ap = :ap, gold = :gold WHERE hero_id = :heroId");
    mQ.bindValue(":level", hero.getLevel());
    mQ.bindValue(":xp", hero.getXP());
    mQ.bindValue(":hp", hero.getHP());
    mQ.bindValue(":ap", hero.getAP());
    mQ.bindValue(":heroId", hero.getID());
    mQ.bindValue(":gold", hero.getGold());
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

    return monsters;
}

std::vector<Cave> DatabaseHandler::getCaves()
{
    std::vector<Cave> caves;
    Cave cave;

    mQ.exec("SELECT * FROM cave ORDER BY cave_id DESC LIMIT 5"); //only load last 5 caves
    while(mQ.next())
    {
        cave.setID(mQ.value(0).toInt());
        cave.setName(mQ.value(1).toString().toStdString());
        cave.setWinGold(mQ.value(2).toInt());
        cave.setWinXP(mQ.value(3).toInt());
        cave.setLevel(mQ.value(4).toInt());
        cave.setConqueredStatus(mQ.value(5).toBool());
        caves.push_back(cave);
    }

    return caves;
}

void DatabaseHandler::generateNewCaves(unsigned int heroLevel)
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
        level = heroLevel + (rand()%7 - 3); //random number between -3 and 3
        if(level < 1)
            level = 1;
        gold = 10*level;
        xp = 125*level;

        //Add cave to database
        mQ.prepare("INSERT INTO cave (name, gold, xp, level) VALUES (:name, :gold, :xp, :level)");
        mQ.bindValue(":name", QString::fromStdString(name));
        mQ.bindValue(":gold", gold);
        mQ.bindValue(":xp", xp);
        mQ.bindValue(":level", level);
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

    return monsters;
}
