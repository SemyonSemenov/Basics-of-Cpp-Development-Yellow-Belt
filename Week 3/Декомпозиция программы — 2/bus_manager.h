#pragma once
#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>
using namespace std;

#include "responses.h"

class BusManager {
private:
    map<string, vector<string>> buses_to_stops, stops_to_buses;
public:
    void AddBus(const string& bus, const vector<string>& stops);

    BusesForStopResponse GetBusesForStop(const string& stop) const;
    StopsForBusResponse GetStopsForBus(const string& bus) const;
    AllBusesResponse GetAllBuses() const;
};