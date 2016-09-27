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
    enemy(const enemy &x): Name(x.Name), Fire(x.Fire), Armor(x.Armor), Health(x.Health), Torpedo(x.Torpedo), Anti_air(x.Anti_air) {}
    enemy(const std::string n, const int a, const int b, const int c, const int d, const int e): Name(n), Fire(a). Armor(b), Health(c), Torpedo(d), Anti_air(e) {}
    enemy(const std::string n, const double, const double b, const double c, const double d, const double e): Name(n), Fire(a). Armor(b), Health(c), Torpedo(d), Anti_air(e) {}
    ~enemy() {}

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
