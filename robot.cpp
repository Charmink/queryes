#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
using namespace std;

void Make_Something(map<string, vector<string>>& buses, map<string, vector<string>>& stops, const string& command){
    if (command == "NEW_BUS"){
        int stops_count;
        string stop, bus;
        cin >> bus >> stops_count;
        for (int i = 0; i < stops_count; i ++){
            cin >> stop;
            buses[bus].push_back(stop);
            stops[stop].push_back(bus);
        }
    }
    else if (command == "BUSES_FOR_STOP"){
        string stop;
        cin >> stop;
        if (stops.count(stop)){
            for (const string& bus: stops[stop])
                cout  << bus << " ";
        }
        else
            cout << "No stop";
        cout << endl;
    }
    else if (command == "STOPS_FOR_BUS"){
        string bus;
        cin >> bus;
        if (buses.count(bus)){
            for (const string& stop: buses[bus]) {
                cout << "Stop " << stop << ": ";
                if (stops.count(stop) && stops[stop].size() > 1){
                    for (const string& b: stops[stop]) {
                        if (b == bus)
                            continue;
                        cout << b << " ";
                    }
                }
                else
                    cout << "no interchange";
                cout << endl;
            }
        }
        else
            cout << "No bus" << endl;

    }
    else if (command == "ALL_BUSES"){
        if (buses.empty()){
            cout << "No buses" << endl;
            return;
        }
        for (const auto& items: buses){
            cout << "Bus " << items.first << ": ";
            for (const string& stop: items.second)
                cout << stop << " ";
            cout << endl;
        }
        cout << endl;
    }

}
int main (){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    string command;
    int n, k;
    cin >> n;
    map<string, vector<string>> buses;
    map<string, vector<string>> stops;
    for (int i = 0; i < n; i ++) {
        cin >> command;
        Make_Something(buses, stops, command);
    }
    return 0;

}