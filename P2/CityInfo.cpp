#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class CityInfo {

    public:
    string name;
    double longitude;
    double latitude;
    int population;
    double costOfLiving;
    double avgSalary;
    CityInfo(string _name, double _longitude, double _latitude, int _population, double _costOfLiving, double _avgSalary) {
        name = _name;
        longitude = _longitude;
        latitude = _latitude;
        population = _population;
        costOfLiving = _costOfLiving;
        avgSalary = _avgSalary;
    }
};