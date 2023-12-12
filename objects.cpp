#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Object {
public:


    // function to describe the objects in the currentRoom* 
    static void describeObjects(const json& mapData, const string& command);
};
void Object::describeObjects(const json& mapData,const string& command ) {
    
     // Check if the command is "objectlook" or "look object"
    if (command == "objectlook" || command == "look object") {
        string currentRoom = mapData["player"]["initialroom"].get<string>();
        // Find the room in the "rooms" array based on the current room
        auto roomIt = find_if(mapData["rooms"].begin(), mapData["rooms"].end(),
                              [currentRoom](const json& room) {
                                  return room["id"] == currentRoom;
                              });

        // Check if the room with the given ID was found
        if (roomIt != mapData["rooms"].end()) {
            // Print objects in the room
            cout << "Objects in the Room:" << endl;
            for (const auto& objectId : (*roomIt)["objectsInRoom"]) {
                auto objIt = find_if(mapData["objects"].begin(), mapData["objects"].end(),
                                     [objectId](const json& obj) {
                                         return obj["id"] == objectId;
                                     });
                if (objIt != mapData["objects"].end()) {
                    cout << "  - " << (*objIt)["desc"].get<string>() << endl;
                }
            }
        } else {
            cout << "Room not found." << endl;
        }
    } else {
        cout << "Unknown command." << endl;
    }
}