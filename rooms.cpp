#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
#include "json.hpp"
#include <fstream>
using json = nlohmann::json;

class rooms {
public:
    string id;
    string desc;
    unordered_map<string, string> exits;


    static void describeRoom(const json& roomJson);
};

void rooms::describeRoom(const json& roomJson) {

    cout << "Room Description: " << roomJson["desc"].get<string>() << endl;
    // at the start print the description according to initial room (which is in objects)
    // then print accordibf to where the player is (a variable for this needs to be added)
};
