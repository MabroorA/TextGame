#include <iostream>
#include <string>
#include <vector>

using namespace std;
class enemies {
public:
    string id;
    string desc;
    int aggressiveness;
    string initialRoom;
    vector<string> killedBy;
};