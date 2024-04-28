#ifndef DATABASEHANDLER_H
#define DATABASEHANDLER_H

#include <QCoreApplication>
#include <QtSql>
#include <QSqlDatabase>
#include <iostream>
#include <string>
#include <vector>
#include <hero.h>

class DatabaseHandler
{
public:
    DatabaseHandler(const QString &username, const QString &password);
    ~DatabaseHandler();

    std::vector<Hero> getHeroes();

private:
    QSqlDatabase mDB;
    QSqlQuery mQ;
};

#endif // DATABASEHANDLER_H
