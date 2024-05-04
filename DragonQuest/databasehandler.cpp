#include "databasehandler.h"

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
        hero.heal();
        heroes.push_back(hero);
    }

    return heroes;
}

unsigned int DatabaseHandler::addHero(const Hero &hero)
{
    mQ.prepare("INSERT INTO hero (name, level, xp, hp, ap) VALUES (:name, :level, :xp, :hp, :ap)");
    mQ.bindValue(":name", QString::fromStdString(hero.getName()));
    mQ.bindValue(":level", hero.getLevel());
    mQ.bindValue(":xp", hero.getXP());
    mQ.bindValue(":hp", hero.getHP());
    mQ.bindValue(":ap", hero.getAP());
    mQ.exec();

    mQ.exec("SELECT MAX(hero_id) FROM hero");
    mQ.next();
    return mQ.value(0).toUInt();
}

void DatabaseHandler::saveHero(const Hero &hero)
{
    mQ.prepare("UPDATE hero SET level = :level, xp = :xp, hp = :hp, ap = :ap WHERE hero_id = :heroId");
    mQ.bindValue(":level", hero.getLevel());
    mQ.bindValue(":xp", hero.getXP());
    mQ.bindValue(":hp", hero.getHP());
    mQ.bindValue(":ap", hero.getAP());
    mQ.bindValue(":heroId", hero.getID());
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
