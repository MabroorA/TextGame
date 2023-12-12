#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm> // for std::find_if
#include "json.hpp"

using namespace std;
using json = nlohmann::json;

class Rooms {
public:
    // Function to describe the room, objects, and enemy
    static void describeRoom(const json& mapData, const string& command);
};

void Rooms::describeRoom(const json& mapData, const string& command) {
    // Check if the command is "look" or "look around"
    if (command == "look" || command == "look around") {
        string currentRoomId = mapData["player"]["initialroom"].get<string>();

        // Find the room in the "rooms" array based on the current room ID
        auto roomIt = find_if(mapData["rooms"].begin(), mapData["rooms"].end(),
                              [currentRoomId](const json& room) {
                                  return room["id"] == currentRoomId;
                              });

        // Check if the room with the given ID was found
        if (roomIt != mapData["rooms"].end()) {
            // Print the description of the found room
            cout << "Room Description: " << (*roomIt)["desc"].get<string>() << endl;

            // Check if there are exits in the current room
            if (roomIt->find("exits") != roomIt->end()) {
                // Print the exits
                cout << "Exits: ";
                for (auto& exit : (*roomIt)["exits"].items()) {
                    cout << exit.key() << " ";
                }
                cout << endl;
            }

            // Check if there are objects in the current room
            if (mapData.find("objects") != mapData.end()) {
                // Find objects in the current room
                auto objectsInRoom = find_if(mapData["objects"].begin(), mapData["objects"].end(),
                                             [currentRoomId](const json& obj) {
                                                 return obj["initialroom"] == currentRoomId;
                                             });

                // Print the objects in the current room
                if (objectsInRoom != mapData["objects"].end()) {
                    cout << "Objects in the Room: " << (*objectsInRoom)["id"].get<string>() << endl;
                }
            }

            // Check if there are enemies in the current room
            if (mapData.find("enemies") != mapData.end()) {
                // Find enemies in the current room
                auto enemiesInRoom = find_if(mapData["enemies"].begin(), mapData["enemies"].end(),
                                             [currentRoomId](const json& enemy) {
                                                 return enemy["initialroom"] == currentRoomId;
                                             });

                // Print the enemies in the current room
                if (enemiesInRoom != mapData["enemies"].end()) {
                    cout << "Enemy in the Room: " << (*enemiesInRoom)["id"].get<string>() << endl;
                }
            }
        } else {
            cout << "Room not found." << endl;
        }
    } else {
        cout << "Unknown command." << endl;
    }
}