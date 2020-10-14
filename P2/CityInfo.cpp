#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class CityInfo {
    string name;
    double longitude;
    double latitude;
    int population;
    int costOfLiving;
    int avgSalary;

    CityInfo(string _name, double _longitude, double _latitude, int _population, int _costOfLiving, int _avgSalary) {
        name = _name;
        longitude = _longitude;
        latitude = _latitude;
        population = _population;
        costOfLiving = _costOfLiving;
        avgSalary = _avgSalary;
    }
};