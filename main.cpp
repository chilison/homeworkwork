//
//  main.cpp
//  hwsem23
//
//  Created by Соня Артеменко on 18.03.2022.
//


#include <iostream>
#include <time.h>
#include <string>


using namespace std;

string DayOfTheWeek(string dateOfBirth) {
    string day;
    int d, m, y = stoi(dateOfBirth.substr(6));
    if (dateOfBirth.substr(3, 4)[0] == '0') {
        m = stoi(dateOfBirth.substr(4, 4));
    } else {
        m = stoi(dateOfBirth.substr(3, 4));
    }
    if (dateOfBirth.substr(0, 1)[0] == '0') {
        d = stoi(dateOfBirth.substr(1, 1));
    } else {
        d = stoi(dateOfBirth.substr(0, 2));
    }
    int temp1 = (y % 100) / 12, temp2 = (y % 100) % 12;
    int index = temp1 + temp2;
    if (temp1 != 0) {index += temp2 / temp1;}
    switch (m) {
        case 1:
            index += 6;
            break;
        case 2:
            index += 2;
            break;
        case 3:
            index += 2;
            break;
        case 4:
            index += 5;
            break;
        case 5:
            index += 0;
            break;
        case 6:
            index += 3;
            break;
        case 7:
            index += 5;
            break;
        case 8:
            index += 1;
            break;
        case 9:
            index += 4;
            break;
        case 10:
            index += 6;
            break;
        case 11:
            index += 2;
            break;
        case 12:
            index += 4;
            break;
    }
    index += d;
    if (y / 100 == 19) {
        index +=1;
    }
    index = index % 7;
    if (y % 4 == 0 && (m == 2 || m == 1)) {
        index -= 1;
    }
    switch (index) {
        case 7:
            day = "воскресенье";
            break;
        case 1:
            day = "понедельник";
            break;
        case 2:
            day = "вторник";
            break;
        case 3:
            day = "среда";
            break;
        case 4:
            day = "четверг";
            break;
        case 5:
            day = "пятница";
            break;
        case 6:
            day = "суббота";
            break;
    }
    return day;
}
int Age(string dateOfBirth) {
    int age;
    time_t now = time(0);
    string date = ctime(&now);
    int month, day, year;
    string t = date.substr(4, 3);
    if (t == "Jan") {
        month = 1;
    } else if (t == "Feb") {
        month = 2;
    } else if (t == "Mar") {
        month = 3;
    } else if (t == "Apr") {
        month = 4;
    } else if (t == "May") {
        month = 5;
    } else if (t == "Jun") {
        month = 6;
    } else if (t == "Jul") {
        month = 7;
    } else if (t == "Aug") {
        month = 8;
    } else if (t == "Sep") {
        month = 9;
    } else if (t== "Oct") {
        month = 10;
    } else if (t == "Nov") {
        month = 11;
    } else {
        month = 12;
    }
    if (dateOfBirth.substr(8, 9)[0] == '0' || dateOfBirth.substr(8, 9)[0] == ' ') {
        day = stoi(dateOfBirth.substr(9, 9));
    } else {
        day = stoi(dateOfBirth.substr(8, 9));
    }
    year = stoi(date.substr(20));
    int m, d;
    if (dateOfBirth.substr(3, 4)[0] == '0') {
        m = stoi(dateOfBirth.substr(4, 4));
    } else {
        m = stoi(dateOfBirth.substr(3, 4));
    }
    if (dateOfBirth.substr(0, 1)[0] == '0') {
        d = stoi(dateOfBirth.substr(1, 1));
    } else {
        d = stoi(dateOfBirth.substr(0, 1));
    }
    if (m < month || (m == month && d < day)) {
        return year - stoi(dateOfBirth.substr(6));
    } else {
        return year - stoi(dateOfBirth.substr(6)) - 1;
    }
    return age;
}
int Day(string dateOfBirth) {
    int age = 0;
    return age;
}
class Person {
    private:
        string surname, name, dateOfBirth;
    public :
        Person(string surname, string name, string dateOfBirth);
        ~Person();
        string GetFullName();
        string GetDateOfBirth();
        void PersonalInfoOut();
        void DateOfBirthDayOfTheWeek();
};
Person::Person(string surname, string name, string dateOfBirth) {
    this -> surname = surname;
    this -> name = name;
    this -> dateOfBirth = dateOfBirth;
}
Person::~Person() {}

string Person::GetFullName() {
    return surname + " " + name;
}
string Person::GetDateOfBirth() {
    return dateOfBirth;
}
void Person::PersonalInfoOut() {
    cout << surname <<  " " <<  name << ": " << Age(dateOfBirth) << " полных лет" << endl;
}
void Person::DateOfBirthDayOfTheWeek() {
    cout << dateOfBirth <<  ", " <<  DayOfTheWeek(dateOfBirth) << endl;
}
int main(int argc, const char * argv[]) {
    string surname, name, birth;
    cin >> surname;
    cin >> name;
    cin >> birth;
    Person person(surname, name, birth);
    person.PersonalInfoOut();
    person.DateOfBirthDayOfTheWeek();
    return 0;
}

