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

class DatabaseHandler
{
public:
    DatabaseHandler(const QString &username, const QString &password);
    ~DatabaseHandler();

    std::vector<Hero> getHeroes();
    unsigned int addHero(const Hero& hero);
    void saveHero(const Hero& hero);

    std::vector<Monster> getMonsters();

private:
    QSqlDatabase mDB;
    QSqlQuery mQ;
};

#endif // DATABASEHANDLER_H
