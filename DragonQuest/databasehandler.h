#ifndef DATABASEHANDLER_H
#define DATABASEHANDLER_H

#include <QCoreApplication>
#include <QtSql>
#include <QSqlDatabase>
#include <iostream>
#include <string>
#include <vector>
#include <hero.h>
#include <monster.h>
#include <cave.h>

class DatabaseHandler
{
public:
    DatabaseHandler(const QString &username, const QString &password);
    ~DatabaseHandler();

    //hero
    std::vector<Hero> getHeroes();
    unsigned int addHero(const Hero& hero);
    void saveHero(const Hero& hero);
    //monster
    std::vector<Monster> getMonsters();
    //cave
    std::vector<Cave> getCaves();
    void saveCave(const Cave& cave);
    void generateNewCaves(unsigned int heroLevel);
    std::vector<Monster> getCaveMonsters(const Cave& cave);


private:
    QSqlDatabase mDB;
    QSqlQuery mQ;
};

#endif // DATABASEHANDLER_H
