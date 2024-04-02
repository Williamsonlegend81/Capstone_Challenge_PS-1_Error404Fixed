#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;

struct Room {
    string room;
    int capacity;
};

//sort rooms in descending order as per the capacity
struct mySort {
    bool operator() (const pair<string,int>& a, const pair<string,int>& b) const {
        return a.second <= b.second;
    }
};

class Course;

class Day {
public:
    string name, code, rm;
    //vector<Day> slot;
    Day() {}
    Day(string name, string code, string rm) : name(name), code(code), rm(rm) {}
    friend void timeTable(Course& deg, map<pair<string,int>,bool,mySort>& room);
};

class Course {
public:
    string courseCode;
    string instructorName;
    int lectureHours;
    int students;
    bool isRepeated;

    vector<Course> sem1, sem3, sem5, sem7;

    Course() {
        isRepeated = false;
    }
    friend void timeTable(Course& deg, map<pair<string,int>,bool,mySort>& room);
};

//to read instructors' information
vector<Course> readCourse(const string& f) {
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

        Course course;
        course.courseCode = row[0];
        course.instructorName = row[1];
        course.lectureHours = stoi(row[2]);
        course.students = stoi(row[3]);
        // try {
        //     course.lectureHours = stoi(row[2]);
        //     course.students = stoi(row[3]);
        // } catch (const invalid_argument& e) {
        //     cerr << "Error: Invalid integer format in file " << f << endl;
        //     continue;
        // }

        courses.push_back(course);
    }

    file.close();

    return courses;
}

struct customSort {
    bool operator() (const Course& a, const Course& b) const {
        return a.lectureHours >= b.lectureHours;
    }
};

//to read rooms' info
vector<Room> readRoom(const string& f) {
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

        Room temp;
        temp.room = row[0];
        temp.capacity = stoi(row[1]);

        v.push_back(temp);
    }

    file.close();
    return v;
}

void timeTable(Course& deg, map<pair<string,int>,bool,mySort>& room) {
    vector<Day> m;
    vector<string> instructor;

    for(auto& i : deg.sem1) {
        bool flag = false;
        if(i.lectureHours != 0) {
            for(auto& j : room) {
                if(i.students <= j.first.second && !j.second && !i.isRepeated) {
                    Day temp(i.instructorName,i.courseCode,j.first.first);

                    if(find(instructor.begin(), instructor.end(),i.instructorName) == instructor.end()) {
                        m.push_back(temp);
                        instructor.push_back(i.instructorName);
                        i.lectureHours--;
                        j.second = true; 
                        flag = true;
                        i.isRepeated = true;
                        break;
                    }
                }
            }
        }
        if(flag) break;
    }

    for(auto& i : deg.sem3) {
        bool flag = false;
        if(i.lectureHours != 0) {
            for(auto& j : room) {
                if(i.students <= j.first.second && !j.second && !i.isRepeated) {
                    Day temp(i.instructorName,i.courseCode,j.first.first);
                    if(find(instructor.begin(), instructor.end(),i.instructorName) == instructor.end()) {
                        m.push_back(temp);
                        instructor.push_back(i.instructorName);
                        i.lectureHours--;
                        j.second = true; 
                        flag = true;
                        i.isRepeated = true;
                        break;
                    }
                }
            }
        }
        if(flag) break;
    }

    int cnt = 0;

    for(auto& i : deg.sem5) {
        if(i.lectureHours != 0) {
            for(auto& j : room) {
                if(i.students <= j.first.second && !j.second && !i.isRepeated) {
                    Day temp(i.instructorName,i.courseCode,j.first.first);
                    if(find(instructor.begin(),instructor.end(),i.instructorName) == instructor.end()) {
                        m.push_back(temp);
                        instructor.push_back(i.instructorName);
                        i.lectureHours--;
                        j.second = true; 
                        i.isRepeated = true;
                        cnt++;
                        break;
                    }
                }
            }
        }
        if(cnt >= 3) break;
    }

    cnt = 0;
    for(auto& i : deg.sem7) {
        if(i.lectureHours != 0) {
            for(auto& j : room) {
                if(i.students <= j.first.second && !j.second && !i.isRepeated) {
                    Day temp(i.instructorName,i.courseCode,j.first.first);
                    if(find(instructor.begin(),instructor.end(),i.instructorName) == instructor.end()) {
                        m.push_back(temp);
                        instructor.push_back(i.instructorName);
                        i.lectureHours--;
                        j.second = true; 
                        i.isRepeated = true;
                        cnt++;
                        break;
                    }
                }
            }
        }
        if(cnt >= 4) break;
    }

    for(auto& it : m) {
        cout << it.code << " " << it.name << " " << it.rm << endl;
    }
}

void makeFalse(map<pair<string,int>,bool,mySort>& room) {
    for(auto& it : room) {
        it.second = false;
    }
}

void makeSlotFalse(Course& deg) {
    for(auto& it : deg.sem1) it.isRepeated = false;
    for(auto& it : deg.sem3) it.isRepeated = false;
    for(auto& it : deg.sem5) it.isRepeated = false;
    for(auto& it : deg.sem7) it.isRepeated = false;
}

int main() {

    string courseString = "semes1.csv";
    Course btech;
    btech.sem1 = readCourse(courseString);
    courseString = "semes3.csv";
    btech.sem3 = readCourse(courseString);
    courseString = "semes5.csv";
    btech.sem5 = readCourse(courseString);
    courseString = "semes7.csv";
    btech.sem7 = readCourse(courseString);

    sort(btech.sem1.begin(), btech.sem1.end(),customSort());
    sort(btech.sem3.begin(), btech.sem3.end(),customSort());
    
/* ------------------------------------------------------------------------------------------------------------------------------- */

    string roomString = "areas.csv";
    vector<Room> r = readRoom(roomString);
    map<pair<string,int>,bool, mySort> room;

    for(auto& it : r) {
        room[make_pair(it.room, it.capacity)] = false;
    }

    for(int j = 0; j < 5; ++j) {
        if(j == 0) cout << "Monday\n";
        else if(j == 1) cout << "Tuesday\n";
        else if(j == 2) cout << "Wednesday\n";
        else if(j == 3) cout << "Thursday\n";
        else if(j == 4) cout << "Friday\n";
        cout << "------------------------------------------\n\n";
        for(int i = 0; i < 5; ++i) {
            if(i == 0) cout << "Slot M1 : (8 to 8:50)\n";
            else if(i == 1) cout << "Slot M2 : (9 to 9:50)\n";
            else if(i == 2) cout << "Slot M3 : (10 to 10:50)\n";
            else if(i == 3) cout << "Slot M4 : (11 to 11:50)\n";
            else if(i == 4) cout << "Slot M5 : (12 to 12:50)\n";

            timeTable(btech,room);
            makeFalse(room);
            cout << "------------------------------------------\n\n";
        }
        makeSlotFalse(btech);
    }

    return 0;
}