#ifndef MAIN_H
#define MAIN_H


#include "json.hpp"
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
using json = nlohmann::json;

class Room {
public:
    string id;
    string desc;
    unordered_map<string, string> exits;

    // Member function to initialize from JSON
    static Room fromJson(const json& j);
    
    // function to describe the room
    void describeRoom() const;
};

class Object {
public:
    string id;
    string desc;
    string initialRoom;

    // Member function to initialize from JSON
    static Object fromJson(const json& j);
};

class Enemy {
public:
    string id;
    string desc;
    int aggressiveness;
    string initialRoom;
    vector<string> killedBy;

    // Member function to initialize from JSON
    static Enemy fromJson(const json& j);
};

class Player {
public:
    string initialRoom;
    string currentRoom;
    // Member function to initialize from JSON
    static Player fromJson(const json& j);
};

class Objective {
public:
    string type;
    vector<string> what;

    // Member function to initialize from JSON
    static Objective fromJson(const json& j);
};

class GameData {
public:
    vector<Room> rooms;
    vector<Object> objects;
    vector<Enemy> enemies;
    Player player;
    Objective objective;

    // Member function to initialize from JSON
    static GameData fromJson(const json& j);
};

#endif // MAIN_H
