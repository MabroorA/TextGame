#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;



class rooms {
public:
    string id;
    string desc;
    unordered_map<string, string> exits;


    void describeroom() const;
};

void rooms::describeroom() const{
    
};