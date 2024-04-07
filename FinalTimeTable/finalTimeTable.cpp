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
#include <cstdlib>

using namespace std;

ofstream myFile("output.csv");

struct Room {
    string room;
    int capacity;
};

class Course;

class Day {
public:
    string name, courseCode, rm, courseName, programme;
    string section;
    int semester;
    Day() {}
    Day(string name,string code,string rm,int semester,string courseName,string section,string programme) : name(name), courseCode(code), rm(rm), semester(semester), courseName(courseName), section(section), programme(programme) {}
    friend void generateTimeTable(Course& deg, map<pair<string,int>,bool>& room, int day, int time);
};

class Course : public Day {
public:
    string instructorName;
    int lectureHours;
    int students;
    bool isRepeated;

    vector<Course> year1, year2, year3, year4, MnCy1, MnCy2, MnCy3, MnCy4;
    vector<Course> MScDSy1,MScDSy2,MTechICTy1,MTechICTy2,MScITy1,MScITy2,MScAAy1,MScAAy2,MDesCDy1,MDesCDy2;
    vector<vector<Day>> mon,tue,wed,thu,fri;

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
            course.courseName = row[5];
            course.section = row[6];
        } catch (const invalid_argument& e) {
            cerr << "Error in reading programme!\n";
            continue;
        }

        courses.push_back(course);
    }

    file.close();

    return courses;
}

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
    string time, rm, courseCode, day, section, courseName;
    int semester;
};

map<string,vector<instrutorTable>> instTable;

void generateInstructorTimeTable(string instructorName, string courseCode, string roomm, int day, int time, string section, int semester, string courseName) {
    if(day ==  0) {
            if(time == 0) instTable[instructorName].push_back({"8 to 8:50",roomm,courseCode,"Monday",section,courseName,semester});
            else if(time == 1) instTable[instructorName].push_back({"9 to 9:50",roomm,courseCode, "Monday",section,courseName,semester});
            else if(time == 2) instTable[instructorName].push_back({"10 to 10:50",roomm,courseCode, "Monday",section,courseName,semester});
            else if(time == 3) instTable[instructorName].push_back({"11 to 11:50",roomm,courseCode, "Monday",section,courseName,semester});
            else if(time == 4) instTable[instructorName].push_back({"12 to 12:50",roomm,courseCode, "Monday",section,courseName,semester});
            else if(time == 5) instTable[instructorName].push_back({"14 to 14:50",roomm,courseCode, "Monday",section,courseName,semester});
            else if(time == 6) instTable[instructorName].push_back({"15 to 15:50",roomm,courseCode, "Monday",section,courseName,semester});
    }
    else if(day ==  1) {
        if(time == 0) instTable[instructorName].push_back({"8 to 8:50",roomm,courseCode, "Tuesday",section,courseName,semester});
        else if(time == 1) instTable[instructorName].push_back({"9 to 9:50",roomm,courseCode,"Tuesday",section,courseName,semester});
        else if(time == 2) instTable[instructorName].push_back({"10 to 10:50",roomm,courseCode,"Tuesday",section,courseName,semester});
        else if(time == 3) instTable[instructorName].push_back({"11 to 11:50",roomm,courseCode,"Tuesday",section,courseName,semester});
        else if(time == 4) instTable[instructorName].push_back({"12 to 12:50",roomm,courseCode,"Tuesday",section,courseName,semester});
        else if(time == 5) instTable[instructorName].push_back({"14 to 14:50",roomm,courseCode,"Tuesday",section,courseName,semester});
        else if(time == 6) instTable[instructorName].push_back({"15 to 15:50",roomm,courseCode,"Tuesday",section,courseName,semester});
    }
    else if(day ==  2) {
        if(time == 0) instTable[instructorName].push_back({"8 to 8:50",roomm,courseCode, "Wednesday",section,courseName,semester});
        else if(time == 1) instTable[instructorName].push_back({"9 to 9:50",roomm,courseCode, "Wednesday",section,courseName,semester});
        else if(time == 2) instTable[instructorName].push_back({"10 to 10:50",roomm,courseCode, "Wednesday",section,courseName,semester});
        else if(time == 3) instTable[instructorName].push_back({"11 to 11:50",roomm,courseCode, "Wednesday",section,courseName,semester});
        else if(time == 4) instTable[instructorName].push_back({"12 to 12:50",roomm,courseCode, "Wednesday",section,courseName,semester});
        else if(time == 5) instTable[instructorName].push_back({"14 to 14:50",roomm,courseCode, "Wednesday",section,courseName,semester});
        else if(time == 6) instTable[instructorName].push_back({"15 to 15:50",roomm,courseCode, "Wednesday",section,courseName,semester});
    }
    else if(day ==  3) {
        if(time == 0) instTable[instructorName].push_back({"8 to 8:50",roomm,courseCode, "Thursday",section,courseName,semester});
        else if(time == 1) instTable[instructorName].push_back({"9 to 9:50",roomm,courseCode, "Thursday",section,courseName,semester});
        else if(time == 2) instTable[instructorName].push_back({"10 to 10:50",roomm,courseCode, "Thursday",section,courseName,semester});
        else if(time == 3) instTable[instructorName].push_back({"11 to 11:50",roomm,courseCode, "Thursday",section,courseName,semester});
        else if(time == 4) instTable[instructorName].push_back({"12 to 12:50",roomm,courseCode, "Thursday",section,courseName,semester});
        else if(time == 5) instTable[instructorName].push_back({"14 to 14:50",roomm,courseCode, "Thursday",section,courseName,semester});
        else if(time == 6) instTable[instructorName].push_back({"15 to 15:50",roomm,courseCode, "Thursday",section,courseName,semester});
    }
    else if(day ==  4) {
        if(time == 0) instTable[instructorName].push_back({"8 to 8:50",roomm,courseCode, "Friday",section,courseName,semester});
        else if(time == 1) instTable[instructorName].push_back({"9 to 9:50",roomm,courseCode, "Friday",section,courseName,semester});
        else if(time == 2) instTable[instructorName].push_back({"10 to 10:50",roomm,courseCode, "Friday",section,courseName,semester});
        else if(time == 3) instTable[instructorName].push_back({"11 to 11:50",roomm,courseCode, "Friday",section,courseName,semester});
        else if(time == 4) instTable[instructorName].push_back({"12 to 12:50",roomm,courseCode, "Friday",section,courseName,semester});
        else if(time == 5) instTable[instructorName].push_back({"14 to 14:50",roomm,courseCode, "Friday",section,courseName,semester});
        else if(time == 6) instTable[instructorName].push_back({"15 to 15:50",roomm,courseCode, "Friday",section,courseName,semester});
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
                    Day temp(i.instructorName,i.courseCode,j.first.first, i.semester,i.courseName, i.section, "ICT&CS");
                    if(find(instructor.begin(), instructor.end(),i.instructorName) == instructor.end()) {
                        m.push_back(temp);
                        instructor.push_back(i.instructorName);
                        i.lectureHours--;
                        j.second = true; 
                        flag++;
                        i.isRepeated = true;
                       
                        if(i.section == "A" || i.section == "B") {
                            for(auto& k : deg.year1) {
                                if(k.lectureHours != 0) {
                                    bool t = false;
                                    if(i.section != k.section && i.instructorName != k.instructorName) {
                                        for(auto& d : room) {
                                            if(k.students <= d.first.second && !d.second && !k.isRepeated) {
                                                Day temp(k.instructorName,k.courseCode,d.first.first, k.semester,k.courseName, k.section, "ICT&CS");
                                                m.push_back(temp);
                                                instructor.push_back(k.instructorName);
                                                k.lectureHours--;
                                                d.second = true;
                                                k.isRepeated = true; t = true;
                                                generateInstructorTimeTable(k.instructorName,k.courseCode,d.first.first,day,time,k.section,k.semester,k.courseName);
                                                break;
                                            }
                                        }
                                    }
                                    if(t) break;
                                }
                            }
                        }
                        generateInstructorTimeTable(i.instructorName,i.courseCode,j.first.first,day,time,i.section,i.semester,i.courseName);
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
                    Day temp(i.instructorName,i.courseCode,j.first.first, i.semester, i.courseName, i.section, "MnC/EVD");
                    if(find(instructor.begin(), instructor.end(),i.instructorName) == instructor.end()) {
                        m.push_back(temp);
                        instructor.push_back(i.instructorName);
                        i.lectureHours--;
                        j.second = true; 
                        flag++;
                        i.isRepeated = true;
                        generateInstructorTimeTable(i.instructorName,i.courseCode,j.first.first,day,time,i.section,i.semester,i.courseName);
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
                    Day temp(i.instructorName,i.courseCode,j.first.first, i.semester,i.courseName, i.section, "ICT&CS");
                    if(find(instructor.begin(), instructor.end(),i.instructorName) == instructor.end()) {
                        m.push_back(temp);
                        instructor.push_back(i.instructorName);
                        i.lectureHours--;
                        j.second = true; 
                        flag++;
                        i.isRepeated = true;
                        
                        if(i.section == "A" || i.section == "B") {
                            for(auto& k : deg.year2) {
                                if(k.lectureHours != 0) {
                                    bool t = false;
                                    if(i.section != k.section && i.instructorName != k.instructorName) {
                                        for(auto& d : room) {
                                            if(k.students <= d.first.second && !d.second && !k.isRepeated) {
                                                Day temp(k.instructorName,k.courseCode,d.first.first, k.semester,k.courseName, k.section, "ICT&CS");
                                                m.push_back(temp);
                                                instructor.push_back(k.instructorName);
                                                k.lectureHours--;
                                                d.second = true;
                                                k.isRepeated = true; t = true;
                                                generateInstructorTimeTable(k.instructorName,k.courseCode,d.first.first,day,time,k.section,k.semester,k.courseName);
                                                break;
                                            }
                                        }
                                    }
                                    if(t) break;
                                }
                            }
                        }
                        generateInstructorTimeTable(i.instructorName,i.courseCode,j.first.first,day,time,i.section,i.semester,i.courseName);
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
                    Day temp(i.instructorName,i.courseCode,j.first.first, i.semester,i.courseName, i.section, "MnC/EVD");
                    if(find(instructor.begin(), instructor.end(),i.instructorName) == instructor.end()) {
                        m.push_back(temp);
                        instructor.push_back(i.instructorName);
                        i.lectureHours--;
                        j.second = true; 
                        flag++;
                        i.isRepeated = true;
                        generateInstructorTimeTable(i.instructorName,i.courseCode,j.first.first,day,time,i.section,i.semester,i.courseName);
                        break;
                    }
                }
            }
        }
        if(flag >= 1) break;
    }


    flag = 0;
    int flagyear3 = 0;
    for(auto& i : deg.year3) {
        if(i.lectureHours != 0) {
            for(auto& j : room) {
                if(i.students <= j.first.second && !j.second && !i.isRepeated) {
                    Day temp(i.instructorName,i.courseCode,j.first.first, i.semester,i.courseName, i.section, "ICT&CS");
                    if(find(instructor.begin(),instructor.end(),i.instructorName) == instructor.end()) {
                        m.push_back(temp);
                        instructor.push_back(i.instructorName);
                        i.lectureHours--;
                        j.second = true; 
                        i.isRepeated = true;
                        flag++;
                        if(i.section == "AB") flagyear3 = 1;

                        if((i.section == "A" || i.section == "B")) {
                            for(auto& k : deg.year3) {
                                if(k.lectureHours != 0) {
                                    bool t = false;
                                    if(i.section != k.section && i.instructorName != k.instructorName) {
                                        for(auto& d : room) {
                                            if(k.students <= d.first.second && !d.second && !k.isRepeated) {
                                                Day temp(k.instructorName,k.courseCode,d.first.first, k.semester,k.courseName, k.section,"ICT&CS");
                                                m.push_back(temp);
                                                instructor.push_back(k.instructorName);
                                                k.lectureHours--;
                                                d.second = true;
                                                k.isRepeated = true; t = true;
                                                generateInstructorTimeTable(k.instructorName,k.courseCode,d.first.first,day,time,k.section,k.semester,k.courseName);
                                                break;
                                            }
                                        }
                                    }
                                    if(t) break;
                                }
                            }
                        }
                        generateInstructorTimeTable(i.instructorName,i.courseCode,j.first.first,day,time,i.section,i.semester,i.courseName);
                        break;
                    }
                }
            }
        }
        if(flag >= 2 || flagyear3 == 1) break;
    }

    flag = 0;
    for(auto& i : deg.MnCy3) {
        if(i.lectureHours != 0) {
            for(auto& j : room) {
                if(i.students <= j.first.second && !j.second && !i.isRepeated) {
                    Day temp(i.instructorName,i.courseCode,j.first.first, i.semester,i.courseName, i.section, "MnC/EVD");
                    if(find(instructor.begin(), instructor.end(),i.instructorName) == instructor.end()) {
                        m.push_back(temp);
                        instructor.push_back(i.instructorName);
                        i.lectureHours--;
                        j.second = true; 
                        flag++;
                        i.isRepeated = true; 
                        generateInstructorTimeTable(i.instructorName,i.courseCode,j.first.first,day,time,i.section,i.semester,i.courseName);
                        break;
                    }
                }
            }
        }
        if(flag >= 1) break;
    }

    flag = 0;
    int flagyear4 = 0;
    for(auto& i : deg.year4) {
        if(i.lectureHours != 0) {
            for(auto& j : room) {
                if(i.students <= j.first.second && !j.second && !i.isRepeated) {
                    Day temp(i.instructorName,i.courseCode,j.first.first, i.semester,i.courseName, i.section, "ICT&CS");
                    if(find(instructor.begin(),instructor.end(),i.instructorName) == instructor.end()) {
                        m.push_back(temp);
                        instructor.push_back(i.instructorName);
                        i.lectureHours--;
                        j.second = true; 
                        i.isRepeated = true;
                        flag++;
                        if(i.section == "AB") flagyear4 = 1;

                        if(i.section == "A" || i.section == "B") {
                            for(auto& k : deg.year4) {
                                if(k.lectureHours != 0) {
                                    bool t = false;
                                    if(i.section != k.section && i.instructorName != k.instructorName) {
                                        for(auto& d : room) {
                                            if(k.students <= d.first.second && !d.second && !k.isRepeated) {
                                                Day temp(k.instructorName,k.courseCode,d.first.first, k.semester,k.courseName, k.section, "ICT&CS");
                                                m.push_back(temp);
                                                instructor.push_back(k.instructorName);
                                                k.lectureHours--;
                                                d.second = true;
                                                k.isRepeated = true; t = true;
                                                generateInstructorTimeTable(k.instructorName,k.courseCode,d.first.first,day,time,k.section,k.semester,k.courseName);
                                                break;
                                            }
                                        }
                                    }
                                    if(t) break;
                                }
                            }
                        }
                        generateInstructorTimeTable(i.instructorName,i.courseCode,j.first.first,day,time,i.section,i.semester,i.courseName);
                        break;
                    }
                }
            }
        }
        if(flag >= 3 || flagyear4) break;
    }

/* ----------------------------------------------------------------------------------------------------------------------------------------------------- */

    flag = 0;
    for(auto& i : deg.MTechICTy1) {
        if(i.lectureHours != 0) {
            for(auto& j : room) {
                if(i.students <= j.first.second && !j.second && !i.isRepeated) {
                    Day temp(i.instructorName,i.courseCode,j.first.first, i.semester, i.courseName, i.section, "Masters");
                    if(find(instructor.begin(), instructor.end(),i.instructorName) == instructor.end()) {
                        m.push_back(temp);
                        instructor.push_back(i.instructorName);
                        i.lectureHours--;
                        j.second = true; 
                        flag++;
                        i.isRepeated = true;
                        generateInstructorTimeTable(i.instructorName,i.courseCode,j.first.first,day,time,i.section,i.semester,i.courseName);
                        break;
                    }
                }
            }
        }
        if(flag >= 1) break;
    }

    flag = 0;
    for(auto& i : deg.MTechICTy2) {
        if(i.lectureHours != 0) {
            for(auto& j : room) {
                if(i.students <= j.first.second && !j.second && !i.isRepeated) {
                    Day temp(i.instructorName,i.courseCode,j.first.first, i.semester, i.courseName, i.section, "Masters");
                    if(find(instructor.begin(), instructor.end(),i.instructorName) == instructor.end()) {
                        m.push_back(temp);
                        instructor.push_back(i.instructorName);
                        i.lectureHours--;
                        j.second = true; 
                        flag++;
                        i.isRepeated = true;
                        generateInstructorTimeTable(i.instructorName,i.courseCode,j.first.first,day,time,i.section,i.semester,i.courseName);
                        break;
                    }
                }
            }
        }
        if(flag >= 1) break;
    }

    flag = 0;
    for(auto& i : deg.MScITy1) {
        if(i.lectureHours != 0) {
            for(auto& j : room) {
                if(i.students <= j.first.second && !j.second && !i.isRepeated) {
                    Day temp(i.instructorName,i.courseCode,j.first.first, i.semester, i.courseName, i.section, "Masters");
                    if(find(instructor.begin(), instructor.end(),i.instructorName) == instructor.end()) {
                        m.push_back(temp);
                        instructor.push_back(i.instructorName);
                        i.lectureHours--;
                        j.second = true; 
                        flag++;
                        i.isRepeated = true;
                        generateInstructorTimeTable(i.instructorName,i.courseCode,j.first.first,day,time,i.section,i.semester,i.courseName);
                        break;
                    }
                }
            }
        }
        if(flag >= 1) break;
    }

    flag = 0;
    for(auto& i : deg.MScITy2) {
        if(i.lectureHours != 0) {
            for(auto& j : room) {
                if(i.students <= j.first.second && !j.second && !i.isRepeated) {
                    Day temp(i.instructorName,i.courseCode,j.first.first, i.semester, i.courseName, i.section, "Masters");
                    if(find(instructor.begin(), instructor.end(),i.instructorName) == instructor.end()) {
                        m.push_back(temp);
                        instructor.push_back(i.instructorName);
                        i.lectureHours--;
                        j.second = true; 
                        flag++;
                        i.isRepeated = true;
                        generateInstructorTimeTable(i.instructorName,i.courseCode,j.first.first,day,time,i.section,i.semester,i.courseName);
                        break;
                    }
                }
            }
        }
        if(flag >= 1) break;
    }

    flag = 0;
    for(auto& i : deg.MScDSy1) {
        if(i.lectureHours != 0) {
            for(auto& j : room) {
                if(i.students <= j.first.second && !j.second && !i.isRepeated) {
                    Day temp(i.instructorName,i.courseCode,j.first.first, i.semester, i.courseName, i.section,"Masters");
                    if(find(instructor.begin(), instructor.end(),i.instructorName) == instructor.end()) {
                        m.push_back(temp);
                        instructor.push_back(i.instructorName);
                        i.lectureHours--;
                        j.second = true; 
                        flag++;
                        i.isRepeated = true;
                        generateInstructorTimeTable(i.instructorName,i.courseCode,j.first.first,day,time,i.section,i.semester,i.courseName);
                        break;
                    }
                }
            }
        }
        if(flag >= 1) break;
    }

    flag = 0;
    for(auto& i : deg.MScDSy2) {
        if(i.lectureHours != 0) {
            for(auto& j : room) {
                if(i.students <= j.first.second && !j.second && !i.isRepeated) {
                    Day temp(i.instructorName,i.courseCode,j.first.first, i.semester, i.courseName, i.section,"Masters");
                    if(find(instructor.begin(), instructor.end(),i.instructorName) == instructor.end()) {
                        m.push_back(temp);
                        instructor.push_back(i.instructorName);
                        i.lectureHours--;
                        j.second = true; 
                        flag++;
                        i.isRepeated = true;
                        generateInstructorTimeTable(i.instructorName,i.courseCode,j.first.first,day,time,i.section,i.semester,i.courseName);
                        break;
                    }
                }
            }
        }
        if(flag >= 1) break;
    }

    flag = 0;
    for(auto& i : deg.MDesCDy1) {
        if(i.lectureHours != 0) {
            for(auto& j : room) {
                if(i.students <= j.first.second && !j.second && !i.isRepeated) {
                    Day temp(i.instructorName,i.courseCode,j.first.first, i.semester, i.courseName, i.section,"Masters");
                    if(find(instructor.begin(), instructor.end(),i.instructorName) == instructor.end()) {
                        m.push_back(temp);
                        instructor.push_back(i.instructorName);
                        i.lectureHours--;
                        j.second = true; 
                        flag++;
                        i.isRepeated = true;
                        generateInstructorTimeTable(i.instructorName,i.courseCode,j.first.first,day,time,i.section,i.semester,i.courseName);
                        break;
                    }
                }
            }
        }
        if(flag >= 1) break;
    }

    flag = 0;
    for(auto& i : deg.MDesCDy2) {
        if(i.lectureHours != 0) {
            for(auto& j : room) {
                if(i.students <= j.first.second && !j.second && !i.isRepeated) {
                    Day temp(i.instructorName,i.courseCode,j.first.first, i.semester, i.courseName, i.section,"Masters");
                    if(find(instructor.begin(), instructor.end(),i.instructorName) == instructor.end()) {
                        m.push_back(temp);
                        instructor.push_back(i.instructorName);
                        i.lectureHours--;
                        j.second = true; 
                        flag++;
                        i.isRepeated = true;
                        generateInstructorTimeTable(i.instructorName,i.courseCode,j.first.first,day,time,i.section,i.semester,i.courseName);
                        break;
                    }
                }
            }
        }
        if(flag >= 1) break;
    }

    flag = 0;
    for(auto& i : deg.MScAAy1) {
        if(i.lectureHours != 0) {
            for(auto& j : room) {
                if(i.students <= j.first.second && !j.second && !i.isRepeated) {
                    Day temp(i.instructorName,i.courseCode,j.first.first, i.semester, i.courseName, i.section,"Masters");
                    if(find(instructor.begin(), instructor.end(),i.instructorName) == instructor.end()) {
                        m.push_back(temp);
                        instructor.push_back(i.instructorName);
                        i.lectureHours--;
                        j.second = true; 
                        flag++;
                        i.isRepeated = true;
                        generateInstructorTimeTable(i.instructorName,i.courseCode,j.first.first,day,time,i.section,i.semester,i.courseName);
                        break;
                    }
                }
            }
        }
        if(flag >= 1) break;
    }

    flag = 0;
    for(auto& i : deg.MScAAy2) {
        if(i.lectureHours != 0) {
            for(auto& j : room) {
                if(i.students <= j.first.second && !j.second && !i.isRepeated) {
                    Day temp(i.instructorName,i.courseCode,j.first.first, i.semester, i.courseName, i.section, "Masters");
                    if(find(instructor.begin(), instructor.end(),i.instructorName) == instructor.end()) {
                        m.push_back(temp);
                        instructor.push_back(i.instructorName);
                        i.lectureHours--;
                        j.second = true; 
                        flag++;
                        i.isRepeated = true;
                        generateInstructorTimeTable(i.instructorName,i.courseCode,j.first.first,day,time,i.section,i.semester,i.courseName);
                        break;
                    }
                }
            }
        }
        if(flag >= 1) break;
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
    for(auto& it : deg.MTechICTy1) it.isRepeated = false;
    for(auto& it : deg.MTechICTy2) it.isRepeated = false;
    for(auto& it : deg.MDesCDy1) it.isRepeated = false;
    for(auto& it : deg.MDesCDy2) it.isRepeated = false;
    for(auto& it : deg.MScAAy1) it.isRepeated = false;
    for(auto& it : deg.MScAAy2) it.isRepeated = false;
    for(auto& it : deg.MScITy1) it.isRepeated = false;
    for(auto& it : deg.MScITy2) it.isRepeated = false;
    for(auto& it : deg.MScDSy1) it.isRepeated = false;
    for(auto& it : deg.MScDSy2) it.isRepeated = false;
}

void printTimeTable(vector<vector<Day>>& v, string day) {
    myFile << day << '\n'; 
    int slot = 0;
    for(auto& i : v) {
        if(slot == 0) myFile << "Slot M1 : 8 to 8:50\n";
        else if(slot == 1) myFile << "Slot M2 : 9 to 9:50\n";
        else if(slot == 2) myFile << "Slot M3 : 10 to 10:50\n";
        else if(slot == 3) myFile << "Slot M4 : 11 to 11:50\n";
        else if(slot == 4) myFile << "Slot M5 : 12 to 12:50\n";
        else if(slot == 5) myFile << "Slot M6 : 14 to 14:50\n";
        else if(slot == 6) myFile << "Slot M7 : 15 to 15:50\n";

        for(auto& j : i) {
            myFile << j.courseCode << "," << j.name << "," << j.rm << ",Sem : " << j.semester << "," << j.courseName << "," << j.section << "," << j.programme << '\n'; 
        } myFile << '\n';
        slot++;
    }
}

void printFreeSlot(list<Day>& extra, string day) {
    if(extra.empty()) return;

    if(!extra.empty()) {
        myFile << "Slot M8 : 16 to 16:50\n";
        myFile << extra.back().courseCode << "," << extra.back().name << "," << extra.back().rm << "," << "Sem : " << extra.back().semester << "," << extra.back().courseName << "," << extra.back().section << "," << extra.back().programme << '\n';
        extra.pop_back();
    }

    if(!extra.empty()) {
        myFile << "Slot M9 : 17 to 17:50\n";
        myFile << extra.back().courseCode << "," << extra.back().name << "," << extra.back().rm << "," << "Sem : " << extra.back().semester << "," << extra.back().courseName << "," << extra.back().section << "," << extra.back().programme << '\n';
        extra.pop_back();
    }

    if(!extra.empty()) {
        myFile << "Slot M10 : 17 to 17:50\n";
        myFile << extra.back().courseCode << "," << extra.back().name << "," << extra.back().rm << "," << "Sem : " << extra.back().semester << "," << extra.back().courseName << "," << extra.back().section << "," << extra.back().programme << '\n';
        extra.pop_back();
    } myFile << '\n';
}

int main() {

    ios_base::sync_with_stdio(false);

    Course student;
    vector<Course> c;

    string season;
    cout << "Enter \"Autumn\" for autumn time table or \"Winter\" for winter time table : ";
    cin >> season;

    transform(season.begin(), season.end(), season.begin(), [](char c) {return tolower(c);});

    if(season == "winter") {
        c = readCourse("Winter.csv");
        for(auto& it : c) {
            if(it.semester == 2) student.year1.push_back(it);
            else if(it.semester == 4) student.year2.push_back(it);
            else if(it.semester == 6) student.year3.push_back(it);
            else if(it.semester == 8) student.year4.push_back(it);
        }

        c = readCourse("MnCEvDWinter.csv");
        for(auto& it : c) {
            if(it.semester == 2) student.MnCy1.push_back(it);
            else if(it.semester == 4) student.MnCy2.push_back(it);
            else if(it.semester == 6) student.MnCy3.push_back(it);
            else if(it.semester == 8) student.MnCy4.push_back(it);
        }

        c = readCourse("winterMasters.csv");
        for(auto& it : c) {
            if(it.semester == 2 && it.section == "MTechICT") student.MTechICTy1.push_back(it);
            else if(it.semester == 4 && it.section == "MTechICT") student.MTechICTy2.push_back(it);
            else if(it.semester == 2 && it.section == "MScIT") student.MScITy1.push_back(it);
            else if(it.semester == 4 && it.section == "MScIT") student.MScITy2.push_back(it);
            else if(it.semester == 2 && it.section == "MScDS") student.MScDSy1.push_back(it);
            else if(it.semester == 4 && it.section == "MScDS") student.MScDSy2.push_back(it);
            else if(it.semester == 2 && it.section == "MScAA") student.MScAAy1.push_back(it);
            else if(it.semester == 4 && it.section == "MScAA") student.MScAAy2.push_back(it);
            else if(it.semester == 2 && it.section == "MDesCD") student.MDesCDy1.push_back(it);
            else if(it.semester == 4 && it.section == "MDesCD") student.MDesCDy2.push_back(it);
        }
    }

    else if(season == "autumn") {
        c = readCourse("Autumn.csv");
        for(auto& it : c) {
            if(it.semester == 1) student.year1.push_back(it);
            else if(it.semester == 3) student.year2.push_back(it);
            else if(it.semester == 5) student.year3.push_back(it);
            else if(it.semester == 7) student.year4.push_back(it);
        }

        c = readCourse("MnCEvDAutumn.csv");
        for(auto& it : c) {
            if(it.semester == 1) student.MnCy1.push_back(it);
            else if(it.semester == 3) student.MnCy2.push_back(it);
            else if(it.semester == 5) student.MnCy3.push_back(it);
            else if(it.semester == 7) student.MnCy4.push_back(it);
        }

        c = readCourse("AutumnMasters.csv");
        for(auto& it : c) {
            if(it.semester == 1 && it.section == "MTechICT") student.MTechICTy1.push_back(it);
            else if(it.semester == 3 && it.section == "MTechICT") student.MTechICTy2.push_back(it);
            else if(it.semester == 1 && it.section == "MScIT") student.MScITy1.push_back(it);
            else if(it.semester == 3 && it.section == "MScIT") student.MScITy2.push_back(it);
            else if(it.semester == 1 && it.section == "MScDS") student.MScDSy1.push_back(it);
            else if(it.semester == 3 && it.section == "MScDS") student.MScDSy2.push_back(it);
            else if(it.semester == 1 && it.section == "MScAA") student.MScAAy1.push_back(it);
            else if(it.semester == 3 && it.section == "MScAA") student.MScAAy2.push_back(it);
            else if(it.semester == 1 && it.section == "MDesCD") student.MDesCDy1.push_back(it);
            else if(it.semester == 3 && it.section == "MDesCD") student.MDesCDy2.push_back(it);
        }
    }

    else {
        myFile << "Invalid input.\n";
        return 0;
    }

                    /* Reading Rooms */

    string roomString = "areas.csv";
    vector<Room> r = readRoom(roomString);
    map<pair<string,int>,bool> room;

    for(auto& it : r) room[make_pair(it.room, it.capacity)] = false;
    
    for(int day = 0; day < 5; ++day) {
        for(int time = 0; time < 7; ++time) {
            generateTimeTable(student,room,day,time);
            makeFalse(room);
        }
        makeSlotFalse(student);
    }

    //lectures that doesn't fit in the Morning shift
    list<Day> extra;     
    for(auto& i : student.year1) {
        if(i.lectureHours != 0) {
            for(auto& j : room) {
                if(i.students <= j.first.second && !j.second && !i.isRepeated) {
                    Day temp(i.instructorName,i.courseCode,j.first.first, i.semester,i.courseName, i.section,"ICT&CS");
                    extra.push_back(temp);
                    j.second = true;
                    i.isRepeated = true;
                    i.lectureHours--;
                    break;
                }
            }
        }
    }   
    for(auto& i : student.year2) {
        if(i.lectureHours != 0) {
            for(auto& j : room) {
                if(i.students <= j.first.second && !j.second && !i.isRepeated) {
                    Day temp(i.instructorName,i.courseCode,j.first.first, i.semester,i.courseName, i.section,"ICT&CS");
                    extra.push_back(temp);
                    j.second = true;
                    i.isRepeated = true;
                    i.lectureHours--;
                    break;
                }
            }
        }
    }   
    for(auto& i : student.year3) {
        if(i.lectureHours != 0) {
            for(auto& j : room) {
                if(i.students <= j.first.second && !j.second && !i.isRepeated) {
                    Day temp(i.instructorName,i.courseCode,j.first.first, i.semester,i.courseName, i.section,"ICT&CS");
                    extra.push_back(temp);
                    j.second = true;
                    i.isRepeated = true;
                    i.lectureHours--;
                    break;
                }
            }
        }
    }   
    for(auto& i : student.year4) {
        if(i.lectureHours != 0) {
            for(auto& j : room) {
                if(i.students <= j.first.second && !j.second && !i.isRepeated) {
                    Day temp(i.instructorName,i.courseCode,j.first.first, i.semester,i.courseName, i.section,"ICT&CS");
                    extra.push_back(temp);
                    j.second = true;
                    i.isRepeated = true;
                    i.lectureHours--;
                    break;
                }
            }
        }
    }   
    for(auto& i : student.MnCy1) {
        if(i.lectureHours != 0) {
            for(auto& j : room) {
                if(i.students <= j.first.second && !j.second && !i.isRepeated) {
                    Day temp(i.instructorName,i.courseCode,j.first.first, i.semester,i.courseName, i.section,"MnC/EVD");
                    extra.push_back(temp);
                    j.second = true;
                    i.isRepeated = true;
                    i.lectureHours--;
                    break;
                }
            }
        }
    }   
    for(auto& i : student.MnCy2) {
        if(i.lectureHours != 0) {
            for(auto& j : room) {
                if(i.students <= j.first.second && !j.second && !i.isRepeated) {
                    Day temp(i.instructorName,i.courseCode,j.first.first, i.semester,i.courseName, i.section,"MnC/EVD");
                    extra.push_back(temp);
                    j.second = true;
                    i.isRepeated = true;
                    i.lectureHours--;
                    break;
                }
            }
        }
    }   
    for(auto& i : student.MnCy3) {
        if(i.lectureHours != 0) {
            for(auto& j : room) {
                if(i.students <= j.first.second && !j.second && !i.isRepeated) {
                    Day temp(i.instructorName,i.courseCode,j.first.first, i.semester,i.courseName, i.section,"MnC/EVD");
                    extra.push_back(temp);
                    j.second = true;
                    i.isRepeated = true;
                    i.lectureHours--;
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
                myFile << i.first << '\n';
                for(auto& j : i.second) {
                    myFile << j.day << "," << j.time << "," << j.courseCode << "," << j.courseName << "," << "Sem : " << j.semester << "," << j.section << "," << j.rm << '\n';
                } myFile << '\n';
            }
        }

        else {
            for(auto& it : instTable[prof]) {
                myFile << it.day << "," << it.time << "," << it.courseCode << "," << it.courseName << "," << "Sem : " << it.semester << "," << it.section << "," << it.rm << '\n';
            } myFile << '\n';
        }
    }
        
    else if(userChoice == 1) {
        string userDay;
        cout << "Enter the day(Monday to Friday) of which you want to see the time table or type all to see whole time table : ";
        cin >> userDay;

        transform(userDay.begin(), userDay.end(), userDay.begin(), [](char c) {return toupper(c);});

        if(userDay == "ALL") {
            printTimeTable(student.mon,"Monday");
            printFreeSlot(extra,"Monday");
            printTimeTable(student.tue,"Tuesday");
            printFreeSlot(extra,"Tuesday");
            printTimeTable(student.wed,"Wednesday");
            printFreeSlot(extra,"Wednesday");
            printTimeTable(student.thu,"Thursday");
            printFreeSlot(extra,"Thursday");
            printTimeTable(student.fri,"Friday");
            printFreeSlot(extra,"Friday");
        }

        else if(userDay == "MONDAY") {
            printTimeTable(student.mon,"Monday");
            printFreeSlot(extra,"Monday");
        }
        else if(userDay == "TUESDAY") {
            printTimeTable(student.mon,"Tuesday");
            printFreeSlot(extra,"Tuesday");
        }
        else if(userDay == "WEDNESDAY") {
            printTimeTable(student.mon,"Wednesday");
            printFreeSlot(extra,"Wednesday");
        }
        else if(userDay == "THURSDAY") {
            printTimeTable(student.mon,"Thursday");
            printFreeSlot(extra,"Thursday");
        }
        else if(userDay == "FRIDAY") {
            printTimeTable(student.mon,"Friday");
            printFreeSlot(extra,"Friday");
        }
    }

    else cout << "Invalid Choice.\n";

    myFile.close();
    system("output.csv");

    return 0;
}