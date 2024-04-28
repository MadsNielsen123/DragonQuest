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
