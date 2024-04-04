#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <utility>
#include <algorithm>
#include <list>

using namespace std;

struct Room {
    string room;
    int capacity;
};

//sort rooms in descending order as per the capacity
// struct mySort {
//     bool operator() (const pair<string,int>& a, const pair<string,int>& b) const {
//         return a.second <= b.second;
//     }
// };
class Course;

class Day {
public:
    string name, code, rm;
    int semester;
    Day() {}
    Day(string name, string code, string rm, int semester) : name(name), code(code), rm(rm), semester(semester) {}
    friend void timeTable(Course& deg, map<pair<string,int>,bool>& room);
};

class Course : public Day {
public:
    string courseCode;
    string instructorName;
    int lectureHours;
    int students;
    int semester;
    bool isRepeated;

    vector<Course> year1, year2, year3, year4, MnCy1, MnCy2, MnCy3, MnCy4;
    vector<vector<Day>> mon,tue,wed,thu,fri, freeSlot;

    Course() {
        isRepeated = false;
    }
    friend void timeTable(Course& deg, map<pair<string,int>,bool>& room);
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
        try {
            course.courseCode = row[0];
            course.instructorName = row[1];
            course.lectureHours = stoi(row[2]);
            course.students = stoi(row[3]);
            course.semester = stoi(row[4]);
        } catch (const invalid_argument& e) {
            cerr << "Error in reading programme!\n";
            continue;
        }

        courses.push_back(course);
    }

    file.close();

    return courses;
}

// struct customSort {
//     bool operator() (const Course& a, const Course& b) const {
//         return a.lectureHours >= b.lectureHours;
//     }
// };

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

void timeTable(Course& deg, map<pair<string,int>,bool>& room, int day, int time) {
    vector<Day> m;
    vector<string> instructor;

    int flag = 0;
    for(auto& i : deg.year1) {
        if(i.lectureHours != 0) {
            for(auto& j : room) {
                if(i.students <= j.first.second && !j.second && !i.isRepeated) {
                    Day temp(i.instructorName,i.courseCode,j.first.first, i.semester);

                    if(find(instructor.begin(), instructor.end(),i.instructorName) == instructor.end()) {
                        m.push_back(temp);
                        instructor.push_back(i.instructorName);
                        i.lectureHours--;
                        j.second = true; 
                        flag++;
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
        if(flag >= 1) break;
    }

    flag = 0;
    for(auto& i : deg.MnCy1) {
        if(i.lectureHours != 0) {
            for(auto& j : room) {
                if(i.students <= j.first.second && !j.second && !i.isRepeated) {
                    Day temp(i.instructorName,i.courseCode,j.first.first, i.semester);
                    if(find(instructor.begin(), instructor.end(),i.instructorName) == instructor.end()) {
                        m.push_back(temp);
                        instructor.push_back(i.instructorName);
                        i.lectureHours--;
                        j.second = true; 
                        flag++;
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
        if(flag >= 1) break;
    }

    flag = 0;
    for(auto& i : deg.year2) {
        if(i.lectureHours != 0) {
            for(auto& j : room) {
                if(i.students <= j.first.second && !j.second && !i.isRepeated) {
                    Day temp(i.instructorName,i.courseCode,j.first.first, i.semester);
                    if(find(instructor.begin(), instructor.end(),i.instructorName) == instructor.end()) {
                        m.push_back(temp);
                        instructor.push_back(i.instructorName);
                        i.lectureHours--;
                        j.second = true; 
                        flag++;
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
        if(flag >= 1) break;
    }

    flag = 0;
    for(auto& i : deg.MnCy2) {
        if(i.lectureHours != 0) {
            for(auto& j : room) {
                if(i.students <= j.first.second && !j.second && !i.isRepeated) {
                    Day temp(i.instructorName,i.courseCode,j.first.first, i.semester);
                    if(find(instructor.begin(), instructor.end(),i.instructorName) == instructor.end()) {
                        m.push_back(temp);
                        instructor.push_back(i.instructorName);
                        i.lectureHours--;
                        j.second = true; 
                        flag++;
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
        if(flag >= 1) break;
    }


    int cnt = 0;

    for(auto& i : deg.year3) {
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

    flag = 0;
    for(auto& i : deg.MnCy3) {
        if(i.lectureHours != 0) {
            for(auto& j : room) {
                if(i.students <= j.first.second && !j.second && !i.isRepeated) {
                    Day temp(i.instructorName,i.courseCode,j.first.first, i.semester);
                    if(find(instructor.begin(), instructor.end(),i.instructorName) == instructor.end()) {
                        m.push_back(temp);
                        instructor.push_back(i.instructorName);
                        i.lectureHours--;
                        j.second = true; 
                        flag++;
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
        if(flag >= 1) break;
    }

    cnt = 0;
    for(auto& i : deg.year4) {
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
        if(cnt >= 4 && (day == 3 || day == 4)) break;
        if(cnt >= 4 && (day == 0 || day == 1 || day == 2)) break;
    }

    if(day == 0) deg.mon.push_back(m);
    else if(day == 1) deg.tue.push_back(m);
    else if(day == 2) deg.wed.push_back(m);
    else if(day == 3) deg.thu.push_back(m);
    else if(day == 4) deg.fri.push_back(m);
}

void makeFalse(map<pair<string,int>,bool>& room) {
    for(auto& it : room) {
        it.second = false;
    }
}

void makeSlotFalse(Course& deg) {
    for(auto& it : deg.year1) it.isRepeated = false;
    for(auto& it : deg.year2) it.isRepeated = false;
    for(auto& it : deg.year3) it.isRepeated = false;
    for(auto& it : deg.year4) it.isRepeated = false;
    for(auto& it : deg.MnCy1) it.isRepeated = false;
    for(auto& it : deg.MnCy2) it.isRepeated = false;
    for(auto& it : deg.MnCy3) it.isRepeated = false;
    for(auto& it : deg.MnCy4) it.isRepeated = false;
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

void printFreeSlot(list<Day>& extra, string day) {
    if(extra.empty()) {
        cerr << "List is empty\n";
        return;
    }

    // cout << day << '\n'; 
    // cout << "---------------------------------------------------------------\n\n";

    cout << "Slot M6 : 14 to 14:50\n\n";
    cout << extra.back().code << " | " << extra.back().name << " | " << extra.back().rm << " | " << "Sem : " << extra.back().semester << endl;
    extra.pop_back();

    cout << "---------------------------------------------------------------\n\n";
    cout << "Slot M7 : 15 to 15:50\n\n";
    cout << extra.back().code << " | " << extra.back().name << " | " << extra.back().rm << " | " << "Sem : " << extra.back().semester << endl;
    extra.pop_back();

    cout << "---------------------------------------------------------------\n\n";
    cout << "Slot M8 : 16 to 16:50\n\n";
    cout << extra.back().code << " | " << extra.back().name << " | " << extra.back().rm << " | " << "Sem : " << extra.back().semester << endl;
    extra.pop_back();
    cout << "---------------------------------------------------------------\n\n";
}


int main() {

    string courseString = "coursesWithProgramme.csv";
    vector<Course> c = readCourse(courseString);

    Course btech, mtech;

    for(auto& it : c) {
        if(it.semester == 1) btech.year1.push_back(it);
        else if(it.semester == 3) btech.year2.push_back(it);
        else if(it.semester == 5) btech.year3.push_back(it);
        else if(it.semester == 7) btech.year4.push_back(it);
    }
    c = readCourse("MnC.csv");

    for(auto& it : c) {
        if(it.semester == 1) btech.MnCy1.push_back(it);
        else if(it.semester == 3) btech.MnCy2.push_back(it);
        else if(it.semester == 5) btech.MnCy3.push_back(it);
        else if(it.semester == 7) btech.MnCy4.push_back(it);
    }
    
/* ------------------------------------------------------------------------------------------------------------------------------- */

    string roomString = "areas.csv";
    vector<Room> r = readRoom(roomString);
    map<pair<string,int>,bool> room;

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

    //lectures that doesn't fit in the Morning shift
    list<Day> extra;

    for(auto& i : btech.year4) {
        if(i.lectureHours != 0) {
            for(auto& j : room) {
                if(i.students <= j.first.second && !j.second && !i.isRepeated) {
                    Day temp(i.instructorName,i.courseCode,j.first.first, i.semester);
                    extra.push_back(temp);
                    j.second = true;
                    i.isRepeated = true;
                    i.lectureHours--;
                    break;
                }
            }
        }
    }    
    
    for(auto& it : btech.MnCy2) {
        if(it.lectureHours != 0) {
            for(auto& jt : room) {
                if(it.students <= jt.first.second) {
                    Day temp(it.instructorName,it.courseCode,jt.first.first, it.semester);
                    extra.push_back(temp);
                    it.lectureHours--;
                    break;
                }
            }
        }
    }    

    printTimeTable(btech.mon, "Monday");
    printFreeSlot(extra, "Monday");
    printTimeTable(btech.tue, "Tuesday");
    printFreeSlot(extra, "Tuesday");
    printTimeTable(btech.wed, "Wednesday");
    printFreeSlot(extra, "Wednesday");
    printTimeTable(btech.thu, "Thursday");
    printFreeSlot(extra, "Thursday");
    printTimeTable(btech.fri, "Friday");
    printFreeSlot(extra, "Friday");

    cout << (extra.empty() ? "YES\n" : "NO\n");
    int cnt = 0;
    for(auto& it : btech.year1) cnt += (it.lectureHours != 0);
    for(auto& it : btech.year2) cnt += (it.lectureHours != 0);
    for(auto& it : btech.year3) cnt += (it.lectureHours != 0);
    for(auto& it : btech.year4) cnt += (it.lectureHours != 0);
    for(auto& it : btech.MnCy1) cnt += (it.lectureHours != 0);
    for(auto& it : btech.MnCy2) cnt += (it.lectureHours != 0);
    for(auto& it : btech.MnCy3) cnt += (it.lectureHours != 0);
    cout << cnt << endl;

    return 0;
}
