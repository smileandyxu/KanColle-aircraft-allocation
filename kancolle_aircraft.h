#ifndef KANCOLLE_AIRCRAFT_H
#define KANCOLLE_AIRCRAFT_H

#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

class aircraft {
    friend bool operator<(const aircraft&, const aircraft&); /**/
    friend bool operator>(const aircraft&, const aircraft&); /**/
    friend bool operator==(const aircraft&, const aircraft&);
    friend bool operator!=(const aircraft&, const aircraft&);
    friend std::istream& operator>>(std::istream &, aircraft &);
    friend std::ostream& operator<<(std::ostream &, const aircraft &);

public:
    aircraft(): Name(""), AA(0.0), EFG(0.0), Bombing(0.0), Torpedo(0.0) {}
    aircraft(const aircraft &x): Name(x.Name), AA(x.AA), EFG(x.EFG), Bombing(x.Bombing), Torpedo(x.Torpedo) {}
    aircraft(const std::string n, const int a, const int b, const int c, const int d): Name(n), AA(a), EFG(b), Bombing(c), Torpedo(d) {}
    ~aircraft() {}

    inline bool same(const aircraft &) const;

    inline char type() const;

    inline double aa() const;
    inline double efg() const;
    inline double bombing() const;
    inline double torpedo() const;

    inline std::string name() const;

    inline aircraft& operator=(const aircraft &);

private:
    double AA; //air to air
    double EFG; //antisubmarine warfare
    double Bombing; //bombing equipment
    double Torpedo; //torpedo equipment
    std::string Name;
};
inline bool aircraft::same(const aircraft &rhs) const
{
    return this->type() == rhs.type();
}
inline char aircraft::type() const
{
    if (Bombing > 0)
        return 'D'; //Carrier-based Dive Bomber
    else if (Torpedo > 0)
        return 'T'; //Carrier-based Torpedo Bomber
    else
        return 'F'; //Carrier-based Fighter Aircraft
}
inline double aircraft::aa() const
{
    return AA;
}
inline double aircraft::efg() const
{
    return EFG;
}
inline double aircraft::bombing() const
{
    return Bombing;
}
inline double aircraft::torpedo() const
{
    return Torpedo;
}
inline std::string aircraft::name() const
{
    return Name;
}
inline aircraft& aircraft::operator=(const aircraft &rhs)
{
    Name = rhs.Name;
    AA = rhs.AA;
    EFG = rhs.EFG;
    Bombing = rhs.Bombing;
    Torpedo = rhs.Torpedo;
    return *this;
}

inline bool operator<(const aircraft &lhs, const aircraft &rhs) /**/
{
    if (lhs.type() == 'D')
        return lhs.Bombing < rhs.Bombing || (lhs.Bombing == rhs.Bombing && lhs.EFG < rhs.EFG);
    else if (lhs.typ() == 'T')
        return lhs.Torpedo < rhs.Torpedo || (lhs.Torpedo == rhs.Torpedo && lhs.EFG < rhs.EFG);
    else
        return lhs.AA < lhs.AA || (lhs.AA == rhs.AA && lhs.EFG < rhs.EFG);
}
inline bool operator>(const aircraft &lhs, const aircraft &rhs) /**/
{
    if (lhs.type() == 'D')
        return lhs.Bombing > rhs.Bombing || (lhs.Bombing == rhs.Bombing && lhs.EFG > rhs.EFG);
    else if (lhs.typ() == 'T')
        return lhs.Torpedo > rhs.Torpedo || (lhs.Torpedo == rhs.Torpedo && lhs.EFG > rhs.EFG);
    else
        return lhs.AA > lhs.AA || (lhs.AA == rhs.AA && lhs.EFG > rhs.EFG);
}
inline bool operator==(const aircraft &lhs, const aircraft &rhs) //different name means the same aircraft
{
    return lhs.AA == rhs.AA && lhs.EFG == rhs.EFG && lhs.Bombing == rhs.Bombing && lhs.Torpedo == rhs.Torpedo;
}
inline bool operator!=(const aircraft &lhs, const aircraft &rhs)
{
    return !(lhs == rhs);
}

std::istream& operator>>(std::istream &is, aircraft &rhs)
{
    is >> rhs.Name >> rhs.AA >> rhs.EFG >> rhs.Bombing >> rhs.Torpedo;
    return is;
}
std::ostream& operator<<(std::ostream &os, const aircraft &rhs)
{
    os << rhs.Name << ' ' << rhs.AA << ' ' << rhs.EFG << ' ' << rhs.Bombing << ' ' << rhs.Torpedo;
    return os;
}

std::map<std::string, aircraft> AIRCRAFT_LIST;
std::vector<aircraft> CDB;
std::vector<aircraft> CTB;
std::vector<aircraft> CFA;

inline void init_aircraft_data()
{
    std::ifstream fin("aircraft_data.txt");
    std::ofstream fout("aircraft_data.txt");
    aircraft tmp;
    while (fin >> tmp) {
        AIRCRAFT_LIST[tmp.name] = tmp;
        if (tmp.type() == 'D')
            CDB.push_back(tmp);
        else if (tmp.type() == 'T')
            CTB.push_back(tmp);
        else
            CFA.push_back(tmp);
    }
}

#endif // KANCOLLE_AIRCRAFT_H
