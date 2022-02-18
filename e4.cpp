//
//  lifeDuration.cpp
//  crispy
//
//  Created by Соня Артеменко on 07.10.2021.
//

#include <iostream>
#include<cmath>
#include <ctime>

using namespace std;

void lifeDuration() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int bday, bmonth, byear;
    cin>>bday>>bmonth>>byear;
    int currday=ltm->tm_mday, currmonth=1 + ltm->tm_mon, year=1900 + ltm->tm_year;
    int k=0;
    int dim[]={0, 31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    while (bday != currday || bmonth != currmonth || byear != year) {
        int feb, currdim;
        if (byear % 400 == 0 || (byear % 4 == 0 && byear %100 != 0)) {
            feb = 29;
        } else {feb = 28;}
        if (bmonth == 2) {
            currdim = feb;
        } else {
            currdim = dim[bmonth];
        }
        if (bday == 31 && bmonth == 12) {
            bday = 1;
            bmonth = 1;
            byear++;
        } else if (bday == currdim) {
            bday = 1;
            bmonth++;
        } else {
            bday++;
        }
        k++;
    }
    cout<<k<<endl;
}
