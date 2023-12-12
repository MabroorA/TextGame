#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
#include "json.hpp"
#include <fstream>
using json = nlohmann::json;

class Rooms {
public:
    string id;
    string desc;
    unordered_map<string, string> exits;
    // reading json data 
    static Rooms fromJson(const json& j);
    
   // function to describe the room
    static void describeRoom(const json& mapData, const string& userInput);
};

Rooms Rooms::fromJson(const json& j) {
    Rooms room;
    room.id = j["id"].get<string>();
    room.desc = j["desc"].get<string>();
    room.exits = j["exits"].get<unordered_map<string, string>>();
    return room;
}


void Rooms::describeRoom(const json& mapData,const string& userInput ) {
    
    // Check if the user input is "look" or "look around"
    if (userInput == "look" || userInput == "look around") {
        string currentRoom = mapData["player"]["initialroom"].get<string>();
        // Find the room in the "rooms" array based on the current room 
        auto roomIt = find_if(mapData["rooms"].begin(), mapData["rooms"].end(),
                              [currentRoom](const json& room) {
                                  return room["id"] == currentRoom;
                              });

        // Check if the room with the given ID was found
        if (roomIt != mapData["rooms"].end()) {
            // Print the description of the found room
            cout << "Room Description: " << (*roomIt)["desc"].get<string>() << endl;
        } else {
            cout << "Room not found." << endl;
        }
    } else {
        cout << "Unknown command." << endl;
    }
}


// void Rooms::describeRoom(const json& mapData, const string& currentRoomId)  {
//     cout << "Room Description: " << roomJson["desc"].get<string>() << endl;
//     // cout << "Room Description: " << roomJson["desc"].get<string>() << endl;
//     // cout << "Player Room: " << roomJson["player"]["initialroom"].get<string>() << endl;
//     // at the start print the description according to initial room (which is in objects)
//     // then print accordibf to where the player is (a variable for this needs to be added)
// };
