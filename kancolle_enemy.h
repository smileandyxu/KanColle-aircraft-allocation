#ifndef KANCOLLE_ENEMY_H
#define KANCOLLE_ENEMY_H

#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

class enemy {
public:
    enemy(): Name(""), Fire(0.0), Armor(0.0), Health(0.0), Torpedo(0.0), Anti-air(0.0) {}

private:
    std::string Name;
    double Fire; //firepower
    double Armor; //armor
    double Health; //health
    double Torpedo; //torpedo-attack
    double Anti_air; //anti-air-attack
};

//health firepower torpedo-attack anti-air armor

#endif // KANCOLLE_ENEMY_H
