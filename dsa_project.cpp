#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <utility>

using namespace std;

struct mySort {
    bool operator() (const pair<string,int>& a, const pair<string,int>& b) const {
        return a.second <= b.second;
        }
};

struct Course {
    string courseCode;
    string instructorName;
    string lectureHours;
};

struct Room {
    string room;
    int capacity;
};

vector<Course> readCSV1(const string& f) {
    vector<Course> courses;

    ifstream file(f);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file " << f << endl;
        return courses;
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

        Course course;
        course.courseCode = row[0];
        course.instructorName = row[1];
        course.lectureHours = row[2];

        courses.push_back(course);
    }

    file.close();

    return courses;
}

vector<Room> readCSV2(const string& f) {
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
    string f = "Book 3(Sheet1).csv";

    vector<Course> courses = readCSV1(f);
   pair<string,string> m1;
   pair<string,int> m2;
    // for (auto& it : courses) {
        
    //     m1.first=it.courseCode;
    //     m1.second=it.instructorName;

    //     m2.first=it.courseCode;
    //     m2.second=0;
    //     // int count=it.lectureHours;
    //     cout << "Course Code: " << it.courseCode << "\n";
    //     cout << "Instructor Name: " << it.instructorName << "\n";
    //     cout << "Lecture Hours: " << it.lectureHours << "\n";
    //     cout << endl;
    // }

    string f1 = "test2.csv";

    vector<Room> r = readCSV2(f1);

    // for (auto& it : r) {
    //     cout << "Room : " << it.room << "\n";
    //     cout << "Capacity : " << it.capacity << "\n";
    //     cout << endl;
    // }

    map<pair<string,int>,bool, mySort> mpp;

    for(auto it : r) {
        mpp[make_pair(it.room, it.capacity)] = false;
    }

    int s1 = 100;

    for(auto& it : mpp) {
        if(it.first.second >= s1) {
            cout << "Room : " << it.first.first << " Allocated.\n";
            break;
        }
    }

    // for (auto it : mpp) {
    //     cout << it.first.first << " : " << it.first.second << '\n';
    // }

    return 0;
}