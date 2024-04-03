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
    int semester;
    Day() {}
    Day(string name, string code, string rm, int semester) : name(name), code(code), rm(rm), semester(semester) {}
    friend void timeTable(Course& deg, map<pair<string,int>,bool,mySort>& room);
};

class Course : public Day {
public:
    string courseCode;
    string instructorName;
    int lectureHours;
    int students;
    int semester;
    bool isRepeated;

    vector<Course> sem1, sem3, sem5, sem7;
    vector<vector<Day>> mon,tue,wed,thu,fri;

    Course() {
        isRepeated = false;
    }
    friend void timeTable(Course& deg, map<pair<string,int>,bool,mySort>& room);
    friend void printTimeTable(vector<vector<Day>>& v, string day);
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
        course.semester = stoi(row[4]);

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

struct instrutorTable {
    string time, rm, crse, day;
};

map<string,vector<instrutorTable>> instTable;

void timeTable(Course& deg, map<pair<string,int>,bool,mySort>& room, int day, int time) {
    vector<Day> m;
    vector<string> instructor;

    for(auto& i : deg.sem1) {
        bool flag = false;
        if(i.lectureHours != 0) {
            for(auto& j : room) {
                if(i.students <= j.first.second && !j.second && !i.isRepeated) {
                    Day temp(i.instructorName,i.courseCode,j.first.first, i.semester);

                    if(find(instructor.begin(), instructor.end(),i.instructorName) == instructor.end()) {
                        m.push_back(temp);
                        instructor.push_back(i.instructorName);
                        i.lectureHours--;
                        j.second = true; 
                        flag = true;
                        i.isRepeated = true;
                        if(day ==  0) {
                            if(time == 0) instTable[i.instructorName].push_back({"8 to 8:50",j.first.first,i.courseCode, "Monday"});
                            else if(time == 1) instTable[i.instructorName].push_back({"9 to 9:50",j.first.first,i.courseCode, "Monday"});
                            else if(time == 2) instTable[i.instructorName].push_back({"10 to 10:50",j.first.first,i.courseCode, "Monday"});
                            else if(time == 3) instTable[i.instructorName].push_back({"11 to 11:50",j.first.first,i.courseCode, "Monday"});
                            else if(time == 4) instTable[i.instructorName].push_back({"12 to 12:50",j.first.first,i.courseCode, "Monday"});
                        }
                        else if(day ==  1) {
                            if(time == 0) instTable[i.instructorName].push_back({"8 to 8:50",j.first.first,i.courseCode, "Tuesday"});
                            else if(time == 1) instTable[i.instructorName].push_back({"9 to 9:50",j.first.first,i.courseCode, "Tuesday"});
                            else if(time == 2) instTable[i.instructorName].push_back({"10 to 10:50",j.first.first,i.courseCode, "Tuesday"});
                            else if(time == 3) instTable[i.instructorName].push_back({"11 to 11:50",j.first.first,i.courseCode, "Tuesday"});
                            else if(time == 4) instTable[i.instructorName].push_back({"12 to 12:50",j.first.first,i.courseCode, "Tuesday"});
                        }
                        else if(day ==  2) {
                            if(time == 0) instTable[i.instructorName].push_back({"8 to 8:50",j.first.first,i.courseCode, "Wednesday"});
                            else if(time == 1) instTable[i.instructorName].push_back({"9 to 9:50",j.first.first,i.courseCode, "Wednesday"});
                            else if(time == 2) instTable[i.instructorName].push_back({"10 to 10:50",j.first.first,i.courseCode, "Wednesday"});
                            else if(time == 3) instTable[i.instructorName].push_back({"11 to 11:50",j.first.first,i.courseCode, "Wednesday"});
                            else if(time == 4) instTable[i.instructorName].push_back({"12 to 12:50",j.first.first,i.courseCode, "Wednesday"});
                        }
                        else if(day ==  3) {
                            if(time == 0) instTable[i.instructorName].push_back({"8 to 8:50",j.first.first,i.courseCode, "Thursday"});
                            else if(time == 1) instTable[i.instructorName].push_back({"9 to 9:50",j.first.first,i.courseCode, "Thursday"});
                            else if(time == 2) instTable[i.instructorName].push_back({"10 to 10:50",j.first.first,i.courseCode, "Thursday"});
                            else if(time == 3) instTable[i.instructorName].push_back({"11 to 11:50",j.first.first,i.courseCode, "Thursday"});
                            else if(time == 4) instTable[i.instructorName].push_back({"12 to 12:50",j.first.first,i.courseCode, "Thursday"});
                        }
                        else if(day ==  4) {
                            if(time == 0) instTable[i.instructorName].push_back({"8 to 8:50",j.first.first,i.courseCode, "Friday"});
                            else if(time == 1) instTable[i.instructorName].push_back({"9 to 9:50",j.first.first,i.courseCode, "Friday"});
                            else if(time == 2) instTable[i.instructorName].push_back({"10 to 10:50",j.first.first,i.courseCode, "Friday"});
                            else if(time == 3) instTable[i.instructorName].push_back({"11 to 11:50",j.first.first,i.courseCode, "Friday"});
                            else if(time == 4) instTable[i.instructorName].push_back({"12 to 12:50",j.first.first,i.courseCode, "Friday"});
                        }
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
                    Day temp(i.instructorName,i.courseCode,j.first.first, i.semester);
                    if(find(instructor.begin(), instructor.end(),i.instructorName) == instructor.end()) {
                        m.push_back(temp);
                        instructor.push_back(i.instructorName);
                        i.lectureHours--;
                        j.second = true; 
                        flag = true;
                        i.isRepeated = true;
                        if(day ==  0) {
                            if(time == 0) instTable[i.instructorName].push_back({"8 to 8:50",j.first.first,i.courseCode, "Monday"});
                            else if(time == 1) instTable[i.instructorName].push_back({"9 to 9:50",j.first.first,i.courseCode, "Monday"});
                            else if(time == 2) instTable[i.instructorName].push_back({"10 to 10:50",j.first.first,i.courseCode, "Monday"});
                            else if(time == 3) instTable[i.instructorName].push_back({"11 to 11:50",j.first.first,i.courseCode, "Monday"});
                            else if(time == 4) instTable[i.instructorName].push_back({"12 to 12:50",j.first.first,i.courseCode, "Monday"});
                        }
                        else if(day ==  1) {
                            if(time == 0) instTable[i.instructorName].push_back({"8 to 8:50",j.first.first,i.courseCode, "Tuesday"});
                            else if(time == 1) instTable[i.instructorName].push_back({"9 to 9:50",j.first.first,i.courseCode, "Tuesday"});
                            else if(time == 2) instTable[i.instructorName].push_back({"10 to 10:50",j.first.first,i.courseCode, "Tuesday"});
                            else if(time == 3) instTable[i.instructorName].push_back({"11 to 11:50",j.first.first,i.courseCode, "Tuesday"});
                            else if(time == 4) instTable[i.instructorName].push_back({"12 to 12:50",j.first.first,i.courseCode, "Tuesday"});
                        }
                        else if(day ==  2) {
                            if(time == 0) instTable[i.instructorName].push_back({"8 to 8:50",j.first.first,i.courseCode, "Wednesday"});
                            else if(time == 1) instTable[i.instructorName].push_back({"9 to 9:50",j.first.first,i.courseCode, "Wednesday"});
                            else if(time == 2) instTable[i.instructorName].push_back({"10 to 10:50",j.first.first,i.courseCode, "Wednesday"});
                            else if(time == 3) instTable[i.instructorName].push_back({"11 to 11:50",j.first.first,i.courseCode, "Wednesday"});
                            else if(time == 4) instTable[i.instructorName].push_back({"12 to 12:50",j.first.first,i.courseCode, "Wednesday"});
                        }
                        else if(day ==  3) {
                            if(time == 0) instTable[i.instructorName].push_back({"8 to 8:50",j.first.first,i.courseCode, "Thursday"});
                            else if(time == 1) instTable[i.instructorName].push_back({"9 to 9:50",j.first.first,i.courseCode, "Thursday"});
                            else if(time == 2) instTable[i.instructorName].push_back({"10 to 10:50",j.first.first,i.courseCode, "Thursday"});
                            else if(time == 3) instTable[i.instructorName].push_back({"11 to 11:50",j.first.first,i.courseCode, "Thursday"});
                            else if(time == 4) instTable[i.instructorName].push_back({"12 to 12:50",j.first.first,i.courseCode, "Thursday"});
                        }
                        else if(day ==  4) {
                            if(time == 0) instTable[i.instructorName].push_back({"8 to 8:50",j.first.first,i.courseCode, "Friday"});
                            else if(time == 1) instTable[i.instructorName].push_back({"9 to 9:50",j.first.first,i.courseCode, "Friday"});
                            else if(time == 2) instTable[i.instructorName].push_back({"10 to 10:50",j.first.first,i.courseCode, "Friday"});
                            else if(time == 3) instTable[i.instructorName].push_back({"11 to 11:50",j.first.first,i.courseCode, "Friday"});
                            else if(time == 4) instTable[i.instructorName].push_back({"12 to 12:50",j.first.first,i.courseCode, "Friday"});
                        }
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
                    Day temp(i.instructorName,i.courseCode,j.first.first, i.semester);
                    if(find(instructor.begin(),instructor.end(),i.instructorName) == instructor.end()) {
                        m.push_back(temp);
                        instructor.push_back(i.instructorName);
                        i.lectureHours--;
                        j.second = true; 
                        i.isRepeated = true;
                        cnt++;
                        if(day ==  0) {
                            if(time == 0) instTable[i.instructorName].push_back({"8 to 8:50",j.first.first,i.courseCode, "Monday"});
                            else if(time == 1) instTable[i.instructorName].push_back({"9 to 9:50",j.first.first,i.courseCode, "Monday"});
                            else if(time == 2) instTable[i.instructorName].push_back({"10 to 10:50",j.first.first,i.courseCode, "Monday"});
                            else if(time == 3) instTable[i.instructorName].push_back({"11 to 11:50",j.first.first,i.courseCode, "Monday"});
                            else if(time == 4) instTable[i.instructorName].push_back({"12 to 12:50",j.first.first,i.courseCode, "Monday"});
                        }
                        else if(day ==  1) {
                            if(time == 0) instTable[i.instructorName].push_back({"8 to 8:50",j.first.first,i.courseCode, "Tuesday"});
                            else if(time == 1) instTable[i.instructorName].push_back({"9 to 9:50",j.first.first,i.courseCode, "Tuesday"});
                            else if(time == 2) instTable[i.instructorName].push_back({"10 to 10:50",j.first.first,i.courseCode, "Tuesday"});
                            else if(time == 3) instTable[i.instructorName].push_back({"11 to 11:50",j.first.first,i.courseCode, "Tuesday"});
                            else if(time == 4) instTable[i.instructorName].push_back({"12 to 12:50",j.first.first,i.courseCode, "Tuesday"});
                        }
                        else if(day ==  2) {
                            if(time == 0) instTable[i.instructorName].push_back({"8 to 8:50",j.first.first,i.courseCode, "Wednesday"});
                            else if(time == 1) instTable[i.instructorName].push_back({"9 to 9:50",j.first.first,i.courseCode, "Wednesday"});
                            else if(time == 2) instTable[i.instructorName].push_back({"10 to 10:50",j.first.first,i.courseCode, "Wednesday"});
                            else if(time == 3) instTable[i.instructorName].push_back({"11 to 11:50",j.first.first,i.courseCode, "Wednesday"});
                            else if(time == 4) instTable[i.instructorName].push_back({"12 to 12:50",j.first.first,i.courseCode, "Wednesday"});
                        }
                        else if(day ==  3) {
                            if(time == 0) instTable[i.instructorName].push_back({"8 to 8:50",j.first.first,i.courseCode, "Thursday"});
                            else if(time == 1) instTable[i.instructorName].push_back({"9 to 9:50",j.first.first,i.courseCode, "Thursday"});
                            else if(time == 2) instTable[i.instructorName].push_back({"10 to 10:50",j.first.first,i.courseCode, "Thursday"});
                            else if(time == 3) instTable[i.instructorName].push_back({"11 to 11:50",j.first.first,i.courseCode, "Thursday"});
                            else if(time == 4) instTable[i.instructorName].push_back({"12 to 12:50",j.first.first,i.courseCode, "Thursday"});
                        }
                        else if(day ==  4) {
                            if(time == 0) instTable[i.instructorName].push_back({"8 to 8:50",j.first.first,i.courseCode, "Friday"});
                            else if(time == 1) instTable[i.instructorName].push_back({"9 to 9:50",j.first.first,i.courseCode, "Friday"});
                            else if(time == 2) instTable[i.instructorName].push_back({"10 to 10:50",j.first.first,i.courseCode, "Friday"});
                            else if(time == 3) instTable[i.instructorName].push_back({"11 to 11:50",j.first.first,i.courseCode, "Friday"});
                            else if(time == 4) instTable[i.instructorName].push_back({"12 to 12:50",j.first.first,i.courseCode, "Friday"});
                        }
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
                    Day temp(i.instructorName,i.courseCode,j.first.first, i.semester);
                    if(find(instructor.begin(),instructor.end(),i.instructorName) == instructor.end()) {
                        m.push_back(temp);
                        instructor.push_back(i.instructorName);
                        i.lectureHours--;
                        j.second = true; 
                        i.isRepeated = true;
                        cnt++;
                        if(day ==  0) {
                            if(time == 0) instTable[i.instructorName].push_back({"8 to 8:50",j.first.first,i.courseCode, "Monday"});
                            else if(time == 1) instTable[i.instructorName].push_back({"9 to 9:50",j.first.first,i.courseCode, "Monday"});
                            else if(time == 2) instTable[i.instructorName].push_back({"10 to 10:50",j.first.first,i.courseCode, "Monday"});
                            else if(time == 3) instTable[i.instructorName].push_back({"11 to 11:50",j.first.first,i.courseCode, "Monday"});
                            else if(time == 4) instTable[i.instructorName].push_back({"12 to 12:50",j.first.first,i.courseCode, "Monday"});
                        }
                        else if(day ==  1) {
                            if(time == 0) instTable[i.instructorName].push_back({"8 to 8:50",j.first.first,i.courseCode, "Tuesday"});
                            else if(time == 1) instTable[i.instructorName].push_back({"9 to 9:50",j.first.first,i.courseCode, "Tuesday"});
                            else if(time == 2) instTable[i.instructorName].push_back({"10 to 10:50",j.first.first,i.courseCode, "Tuesday"});
                            else if(time == 3) instTable[i.instructorName].push_back({"11 to 11:50",j.first.first,i.courseCode, "Tuesday"});
                            else if(time == 4) instTable[i.instructorName].push_back({"12 to 12:50",j.first.first,i.courseCode, "Tuesday"});
                        }
                        else if(day ==  2) {
                            if(time == 0) instTable[i.instructorName].push_back({"8 to 8:50",j.first.first,i.courseCode, "Wednesday"});
                            else if(time == 1) instTable[i.instructorName].push_back({"9 to 9:50",j.first.first,i.courseCode, "Wednesday"});
                            else if(time == 2) instTable[i.instructorName].push_back({"10 to 10:50",j.first.first,i.courseCode, "Wednesday"});
                            else if(time == 3) instTable[i.instructorName].push_back({"11 to 11:50",j.first.first,i.courseCode, "Wednesday"});
                            else if(time == 4) instTable[i.instructorName].push_back({"12 to 12:50",j.first.first,i.courseCode, "Wednesday"});
                        }
                        else if(day ==  3) {
                            if(time == 0) instTable[i.instructorName].push_back({"8 to 8:50",j.first.first,i.courseCode, "Thursday"});
                            else if(time == 1) instTable[i.instructorName].push_back({"9 to 9:50",j.first.first,i.courseCode, "Thursday"});
                            else if(time == 2) instTable[i.instructorName].push_back({"10 to 10:50",j.first.first,i.courseCode, "Thursday"});
                            else if(time == 3) instTable[i.instructorName].push_back({"11 to 11:50",j.first.first,i.courseCode, "Thursday"});
                            else if(time == 4) instTable[i.instructorName].push_back({"12 to 12:50",j.first.first,i.courseCode, "Thursday"});
                        }
                        else if(day ==  4) {
                            if(time == 0) instTable[i.instructorName].push_back({"8 to 8:50",j.first.first,i.courseCode, "Friday"});
                            else if(time == 1) instTable[i.instructorName].push_back({"9 to 9:50",j.first.first,i.courseCode, "Friday"});
                            else if(time == 2) instTable[i.instructorName].push_back({"10 to 10:50",j.first.first,i.courseCode, "Friday"});
                            else if(time == 3) instTable[i.instructorName].push_back({"11 to 11:50",j.first.first,i.courseCode, "Friday"});
                            else if(time == 4) instTable[i.instructorName].push_back({"12 to 12:50",j.first.first,i.courseCode, "Friday"});
                        }
                        break;
                    }
                }
            }
        }
        if(cnt >= 5 && (day == 3 || day == 4) && (time == 3 || time == 4)) break;
        if(cnt >= 4) break;
    }

    if(day == 0) deg.mon.push_back(m);
    else if(day == 1) deg.tue.push_back(m);
    else if(day == 2) deg.wed.push_back(m);
    else if(day == 3) deg.thu.push_back(m);
    else if(day == 4) deg.fri.push_back(m);
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

void printTimeTable(vector<vector<Day>>& v, string day) {
    cout << day << '\n'; 
    cout << "---------------------------------------------------------------\n\n";
    int slot = 0;
    for(auto& i : v) {
        if(slot == 0) cout << "Slot M1 : 8 to 8:50\n\n";
        else if(slot == 1) cout << "Slot M2 : 9 to 9:50\n\n";
        else if(slot == 2) cout << "Slot M3 : 10 to 10:50\n\n";
        else if(slot == 3) cout << "Slot M4 : 11 to 11:50\n\n";
        else if(slot == 4) cout << "Slot M5 : 12 to 12:50\n\n";

        for(auto& j : i) {
            cout << j.code << " | " << j.name << " | " << j.rm << " | Sem : " << j.semester << '\n'; 
        } cout << "---------------------------------------------------------------\n\n";
        slot++;
    }
}

int main() {

    string courseString = "coursesCombined.csv";
    vector<Course> c = readCourse(courseString);

    Course btech;

    for(auto& it : c) {
        if(it.semester == 1) btech.sem1.push_back(it);
        else if(it.semester == 3) btech.sem3.push_back(it);
        else if(it.semester == 5) btech.sem5.push_back(it);
        else if(it.semester == 7) btech.sem7.push_back(it);
    }

    sort(btech.sem1.begin(), btech.sem1.end(),customSort());
    sort(btech.sem3.begin(), btech.sem3.end(),customSort());
    
/* ------------------------------------------------------------------------------------------------------------------------------- */

    string roomString = "areas.csv";
    vector<Room> r = readRoom(roomString);
    map<pair<string,int>,bool, mySort> room;

    for(auto& it : r) {
        room[make_pair(it.room, it.capacity)] = false;
    }

    for(int day = 0; day < 5; ++day) {
        for(int time = 0; time < 5; ++time) {
            timeTable(btech,room,day,time);
            makeFalse(room);
        }
        makeSlotFalse(btech);
    }

    printTimeTable(btech.mon, "Monday");
    printTimeTable(btech.tue, "Tuesday");
    printTimeTable(btech.wed, "Wednesday");
    printTimeTable(btech.thu, "Thursday");
    printTimeTable(btech.fri, "Friday");

    //lectures that doesn't fit in the time Table
    vector<Course> extra;
    for(auto& it : btech.sem7) {
        if(it.lectureHours != 0) {
            extra.push_back(it);
        }
    }

    // for(auto& it : instTable) {
    //     cout << it.first << '\n';
    //     for(auto& i : it.second) {
    //         cout << i.time << " " << i.rm << " " << i.day << " " << i.crse << '\n';
    //     }
    // }

    return 0;
}