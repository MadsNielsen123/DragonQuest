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
#include <magic.h>

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
    std::vector<Cave> getCaves(const Hero& hero);
    void saveCave(const Cave& cave);
    void generateNewCaves(const Hero& hero);
    std::vector<Monster> getCaveMonsters(const Cave& cave);

    //Magic
    std::vector<Magic> getBuyableMagics(const Hero& hero);
    void giveHeroMagic(const Hero& hero, unsigned int magicID);
    std::vector<Magic> getHeroMagics(const Hero& hero);
    double getDamageModifier(const Magic& magic, Monster& ch);

private:
    QSqlDatabase mDB;
    QSqlQuery mQ;
};

#endif // DATABASEHANDLER_H
