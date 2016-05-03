#include <iostream>
#include <string>
using namespace std;

class Date {
    int day, year;
    string month;
    int monthArray[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string monthNameArray[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    
    public:
    bool error = false;
    Date() {
        day = 1;
        month = monthNameArray[0];
        year = 1900;
    }
    void setDate(int m, int d, int y) {
        if(y > 0 && m > 0 && m < 13 && d > 0 && d < monthArray[m - 1]) {
            year = y;
            month = monthNameArray[m - 1];
            day = d;
        }
        else {
            error = true;
            cout << "Error. Date not valid" << endl;
        }
    }
    void getDate() {
        cout << month << " " << day << ", " << year;
    }
};

class Student : public Date {
    string fName, lName, facName;
    int ID, bDay, bMonth, bYear;
    
    public:
    Student(string f, string l, string a, int id) {
        fName = f;
        lName = l;
        facName = a;
        ID = id;
    }
    void setName(string f, string l) {
        fName = f;
        lName = l;
    }
    void setFacName(string a) {
        facName = a;
    }
    void setID(int id) {
        ID = id;
    }
    void setBirthDate(int m, int d, int y) {
        if(error == false) {
            setDate(m, d, y);
        }
    }
    void getInfo() {
        cout << fName << " " << lName << " " << facName << endl;
    }
    void getID() {
        cout << ID << endl;
    }
    void getBirthDate() {
        getDate();
        cout << endl;
    }
};

int main() {
    Student s("Gagik", "Papikyan", "CS", 1111);
    int d1, m1, y1;
    cin >> m1 >> d1 >> y1;
    s.setBirthDate(m1, d1, y1);
    s.getInfo();
    s.getID();
    s.getBirthDate();
    
    Student p(s);
    p.setName("Tigran", "Sedrakyan");
    p.setID(2222);
    int d2, m2, y2;
    cin >> m2 >> d2 >> y2;
    p.setBirthDate(m2, d2, y2);
    p.getInfo();
    p.getID();
    p.getBirthDate();
}
