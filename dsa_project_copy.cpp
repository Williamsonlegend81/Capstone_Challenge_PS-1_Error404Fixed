#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
using namespace std;

struct Room {
    string room;
    int capacity;
};

vector<Room> readCSV(const string& f) {
    vector<Room> v;

    ifstream file(f);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file " << f << endl;
        return v;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        vector<string> row;
        string cell;

        while (getline(ss, cell, ',')) {
            row.push_back(cell);
        }

        if (row.empty()) {
            continue;
        }

        Room temp;
        temp.room = row[0];
        temp.capacity = stoi(row[1]);

        v.push_back(temp);
    }

    file.close();

    return v;
}

int main() {
    string f = "test2.csv";

    vector<Room> r = readCSV(f);

    // for (auto& it : r) {
    //     cout << "Room : " << it.room << "\n";
    //     cout << "Capacity : " << it.capacity << "\n";
    //     cout << endl;
    // }

    map<pair<string,int>,bool> mpp;

    for(auto it : r) {
        mpp[make_pair(it.room, it.capacity)] = false;
    }

    int s1 = 150;

    for(auto& it : mpp) {
        if(it.first.second >= s1 && !it.second) {
            cout << "Room : " << it.first.first << " Allocated.\n";
            it.second = true;
            break;
        }
    }
    
    return 0;
}