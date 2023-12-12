#pragma once

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Room {
public:
    string id;
    string desc;
    unordered_map<string, string> exits;
};

class Object {
public:
    string id;
    string desc;
    string initialRoom;
};

class Enemy {
public:
    string id;
    string desc;
    int aggressiveness;
    string initialRoom;
    vector<string> killedBy;
};

class Player {
public:
    string initialRoom;
    string currentRoom = initialRoom;
};

class Objective {
public:
    string type;
    vector<string> what;
};

class GameData {
public:
    vector<Room> rooms;
    vector<Object> objects;
    vector<Enemy> enemies;
    Player player;
    Objective objective;
};

// Utility functions or additional declarations
