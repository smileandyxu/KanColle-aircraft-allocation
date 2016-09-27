#ifndef KANCOLLE_CARRIER_H
#define KANCOLLE_CARRIER_H

#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

#include "kancolle_aircraft.h"

#define MAX_CAP 4

class carrier {
public:
    carrier(): Name(""), Fire(0.0), Used(0) {}
    ~carrier() {}

private:
    aircraft Equipment[MAX_CAP]; //equiped aircrafts
    std::string Name;
    double Fire; //fire
    int Used; //number of used places
};

#endif // KANCOLLE_CARRIER_H
