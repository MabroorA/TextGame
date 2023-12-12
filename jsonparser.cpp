#include <iostream>
#include <fstream>
#include "json.hpp"



using json = nlohmann::json;
using namespace std;

json readJsonFile(const string& filename) {
    ifstream file(filename);
    json jsonData;

    if (file.is_open()) {
        try {
            file >> jsonData;
        } catch (const json::exception& e) {
            cerr << "Error reading JSON file: " << e.what() << endl;
            // Handle the error as needed
        }

        file.close();
    } else {
        cerr << "Unable to open file: " << filename << endl;
        // Handle the error as needed
    }

    return jsonData;
}
