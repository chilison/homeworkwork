//
//  homework-1.cpp
//  crispy
//
//  Created by Соня Артеменко on 07.10.2021.
//

#include "homework-1.hpp"
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int sum(string s) {
    int c = 0;
    for (int j = 0; j < s.length(); j++) {
        int b = s[j] - '0';
        c += b;
    }
    return c;
}
void z1() {
    int a, b;
    cin >> a >> b;
    for (int i = a; i < b + 1; i++) {
        int r = 0;
        string s = to_string(i);
        int c = sum(s);
        for (int j = 2; j < 10; j++) {
            int ii = i * j;
            string ss = to_string(ii);
            int cc = sum(ss);
            if (c != cc) {r = 1;}
        }
        if (r == 0) {
            cout << i << endl;
        }
        
    }
}
void z2() {
    int n;
    cin >> n;
    int m = 0;
    while (n >= 3) {
        if (n % 3 == 0) {
            m++;
            n = n / 3;
        } else {
            m = 0;
            break;
        }
    }
    cout << m << endl;
}
void z3() {
    string surname, name, papaname;
    cin >> name >> papaname >> surname;
    cout << surname << " " << name[0] << "." << papaname[0] << "." <<endl;
}

int primeOrNot(int n) {
    int r = 0;
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {r = 1; break;}
    }
    return r;
}
void z5() {
    int a, b;
    cin >> a >> b;
    int rr = 0;
    for (int i = a; i < b + 1; i++) {
        string s = to_string(i);
        int r = 0;
        int p = i;
        for (int j = 0; j < s.length() - 1; j++) {
            r = primeOrNot(p);
            if (r == 1) {break;}
            p = p / 10;
        }
        if (r == 0) {cout << i << " "; rr = 1;}
    }
    if (rr == 0) {cout << 0 << endl;}
    
}

int main() {
    void z1();
    void z2();
    void z3();
    void z5();
    //z1();
    //z2();
    //z3();
    //z5();
    return 0;
}
