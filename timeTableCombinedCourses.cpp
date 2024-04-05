#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cctype>
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
    friend void generateTimeTable(Course& deg, map<pair<string,int>,bool>& room, int day, int time);
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
    friend void generateTimeTable(Course& deg, map<pair<string,int>,bool>& room, int day, int time);
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

void generateInstructorTimeTable(string instructorName, string courseCode, string roomm, int day, int time) {
    if(day ==  0) {
                            if(time == 0) instTable[instructorName].push_back({"8 to 8:50",roomm,courseCode, "Monday"});
                            else if(time == 1) instTable[instructorName].push_back({"9 to 9:50",roomm,courseCode, "Monday"});
                            else if(time == 2) instTable[instructorName].push_back({"10 to 10:50",roomm,courseCode, "Monday"});
                            else if(time == 3) instTable[instructorName].push_back({"11 to 11:50",roomm,courseCode, "Monday"});
                            else if(time == 4) instTable[instructorName].push_back({"12 to 12:50",roomm,courseCode, "Monday"});
                        }
                        else if(day ==  1) {
                            if(time == 0) instTable[instructorName].push_back({"8 to 8:50",roomm,courseCode, "Tuesday"});
                            else if(time == 1) instTable[instructorName].push_back({"9 to 9:50",roomm,courseCode, "Tuesday"});
                            else if(time == 2) instTable[instructorName].push_back({"10 to 10:50",roomm,courseCode, "Tuesday"});
                            else if(time == 3) instTable[instructorName].push_back({"11 to 11:50",roomm,courseCode, "Tuesday"});
                            else if(time == 4) instTable[instructorName].push_back({"12 to 12:50",roomm,courseCode, "Tuesday"});
                        }
                        else if(day ==  2) {
                            if(time == 0) instTable[instructorName].push_back({"8 to 8:50",roomm,courseCode, "Wednesday"});
                            else if(time == 1) instTable[instructorName].push_back({"9 to 9:50",roomm,courseCode, "Wednesday"});
                            else if(time == 2) instTable[instructorName].push_back({"10 to 10:50",roomm,courseCode, "Wednesday"});
                            else if(time == 3) instTable[instructorName].push_back({"11 to 11:50",roomm,courseCode, "Wednesday"});
                            else if(time == 4) instTable[instructorName].push_back({"12 to 12:50",roomm,courseCode, "Wednesday"});
                        }
                        else if(day ==  3) {
                            if(time == 0) instTable[instructorName].push_back({"8 to 8:50",roomm,courseCode, "Thursday"});
                            else if(time == 1) instTable[instructorName].push_back({"9 to 9:50",roomm,courseCode, "Thursday"});
                            else if(time == 2) instTable[instructorName].push_back({"10 to 10:50",roomm,courseCode, "Thursday"});
                            else if(time == 3) instTable[instructorName].push_back({"11 to 11:50",roomm,courseCode, "Thursday"});
                            else if(time == 4) instTable[instructorName].push_back({"12 to 12:50",roomm,courseCode, "Thursday"});
                        }
                        else if(day ==  4) {
                            if(time == 0) instTable[instructorName].push_back({"8 to 8:50",roomm,courseCode, "Friday"});
                            else if(time == 1) instTable[instructorName].push_back({"9 to 9:50",roomm,courseCode, "Friday"});
                            else if(time == 2) instTable[instructorName].push_back({"10 to 10:50",roomm,courseCode, "Friday"});
                            else if(time == 3) instTable[instructorName].push_back({"11 to 11:50",roomm,courseCode, "Friday"});
                            else if(time == 4) instTable[instructorName].push_back({"12 to 12:50",roomm,courseCode, "Friday"});
                        }
}

void generateTimeTable(Course& deg, map<pair<string,int>,bool>& room, int day, int time) {
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
                        generateInstructorTimeTable(i.instructorName,i.courseCode,j.first.first,day,time);
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
                        generateInstructorTimeTable(i.instructorName,i.courseCode,j.first.first,day,time);
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
                        generateInstructorTimeTable(i.instructorName,i.courseCode,j.first.first,day,time);
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
                        generateInstructorTimeTable(i.instructorName,i.courseCode,j.first.first,day,time);
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
                        generateInstructorTimeTable(i.instructorName,i.courseCode,j.first.first,day,time);
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
                        generateInstructorTimeTable(i.instructorName,i.courseCode,j.first.first,day,time);
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
                        generateInstructorTimeTable(i.instructorName,i.courseCode,j.first.first,day,time);
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
    if(extra.empty()) return;
    
    // cout << day << '\n'; 
    // cout << "---------------------------------------------------------------\n\n";

    if(!extra.empty()) {
        cout << "Slot M6 : 14 to 14:50\n\n";
        cout << extra.back().code << " | " << extra.back().name << " | " << extra.back().rm << " | " << "Sem : " << extra.back().semester << endl;
        extra.pop_back();
    }

    if(!extra.empty()) {
        cout << "---------------------------------------------------------------\n\n";
        cout << "Slot M7 : 15 to 15:50\n\n";
        cout << extra.back().code << " | " << extra.back().name << " | " << extra.back().rm << " | " << "Sem : " << extra.back().semester << endl;
        extra.pop_back();
    }

    if(!extra.empty()) {
        cout << "---------------------------------------------------------------\n\n";
        cout << "Slot M8 : 16 to 16:50\n\n";
        cout << extra.back().code << " | " << extra.back().name << " | " << extra.back().rm << " | " << "Sem : " << extra.back().semester << endl;
        extra.pop_back();
    }
    cout << "---------------------------------------------------------------\n\n";
}

int main() {

    ios_base::sync_with_stdio(false);

    Course btech;
    vector<Course> c;

    string season;
    cout << "Enter Autumn for autum time table or Winter for winter time table : ";
    cin >> season;

    transform(season.begin(), season.end(), season.begin(), [](char c) {return tolower(c);});

    if(season == "winter") {
        c = readCourse("Winter.csv");
        for(auto& it : c) {
            if(it.semester == 2) btech.year1.push_back(it);
            else if(it.semester == 4) btech.year2.push_back(it);
            else if(it.semester == 6) btech.year3.push_back(it);
            else if(it.semester == 8) btech.year4.push_back(it);
        }

        c = readCourse("MnCEvDWinter.csv");
        for(auto& it : c) {
            if(it.semester == 2) btech.MnCy1.push_back(it);
            else if(it.semester == 4) btech.MnCy2.push_back(it);
            else if(it.semester == 6) btech.MnCy3.push_back(it);
            else if(it.semester == 8) btech.MnCy4.push_back(it);
        }
    }

    else if(season == "autumn") {
        c = readCourse("Autumn.csv");
        for(auto& it : c) {
            if(it.semester == 1) btech.year1.push_back(it);
            else if(it.semester == 3) btech.year2.push_back(it);
            else if(it.semester == 5) btech.year3.push_back(it);
            else if(it.semester == 7) btech.year4.push_back(it);
        }

        c = readCourse("MnCEvDAutumn.csv");
        for(auto& it : c) {
            if(it.semester == 1) btech.MnCy1.push_back(it);
            else if(it.semester == 3) btech.MnCy2.push_back(it);
            else if(it.semester == 5) btech.MnCy3.push_back(it);
            else if(it.semester == 7) btech.MnCy4.push_back(it);
        }
    }

    else {
        cout << "Invalid input.\n";
        return 0;
    }

/* ------------------------------------------------------------------------------------------------------------------------------- */

    string roomString = "areas.csv";
    vector<Room> r = readRoom(roomString);
    map<pair<string,int>,bool> room;

    for(auto& it : r) room[make_pair(it.room, it.capacity)] = false;
    
    for(int day = 0; day < 5; ++day) {
        for(int time = 0; time < 5; ++time) {
            generateTimeTable(btech,room,day,time);
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

    for(auto& i : btech.year2) {
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

    int userChoice;
    cout << "Enter 0 to see Instructor's time table or 1 to see students' time table : ";
    cin >> userChoice;

    if(userChoice == 0) {
        string prof;
        cout << "Enter the name of prof in short form type all to see all instructor's time table : ";
        cin >> prof;

        transform(prof.begin(), prof.end(), prof.begin(), [](char c) {return toupper(c);});

        if(prof == "ALL") {
            for(auto& i : instTable) {
                cout << i.first << '\n';
                for(auto& j : i.second) {
                    cout << j.day << " | " << j.time << " | " << j.crse << " | " << j.rm << '\n';
                }
            }
        }

        else {
            for(auto& it : instTable[prof]) {
                cout << it.day << " | " << it.time << " | " << it.crse << " | " << it.rm << '\n';
            }
        }

    }
        
    else if(userChoice == 1) {
        string userDay;
        cout << "Enter the day(Monday to Friday) of which you want to see the time table or type all to see whole time table : ";
        cin >> userDay;

        transform(userDay.begin(), userDay.end(), userDay.begin(), [](char c) {return toupper(c);});

        if(userDay == "ALL") {
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
        }

        else if(userDay == "MONDAY") {
            printTimeTable(btech.mon, "Monday");
            printFreeSlot(extra, "Monday");
        }
        else if(userDay == "TUESDAY") {
            printTimeTable(btech.mon, "Tuesday");
            printFreeSlot(extra, "Tuesday");
        }
        else if(userDay == "WEDNESDAY") {
            printTimeTable(btech.mon, "Wednesday");
            printFreeSlot(extra, "Wednesday");
        }
        else if(userDay == "THURSDAY") {
            printTimeTable(btech.mon, "Thursday");
            printFreeSlot(extra, "Thursday");
        }
        else if(userDay == "FRIDAY") {
            printTimeTable(btech.mon, "Friday");
            printFreeSlot(extra, "Friday");
        }
    }

    else cout << "Invalid Choice.\n";

    // cout << (extra.empty() ? "YES\n" : "NO\n");
    // int cnt = 0;
    // for(auto& it : btech.year1) cnt += (it.lectureHours != 0); 
    // for(auto& it : btech.year2) cnt += (it.lectureHours != 0);
    // for(auto& it : btech.year3) cnt += (it.lectureHours != 0);
    // for(auto& it : btech.year4) cnt += (it.lectureHours != 0); 
    // for(auto& it : btech.MnCy1) cnt += (it.lectureHours != 0);
    // for(auto& it : btech.MnCy2) cnt += (it.lectureHours != 0);
    // for(auto& it : btech.MnCy3) cnt += (it.lectureHours != 0);
    // cout << cnt << endl;

    return 0;
}
