//
//  2409П5.cpp
//  practice1
//
//  Created by Соня Артеменко on 15.10.2021.
//

#include <stdio.h>
#include <cmath>
#include <iostream>

using namespace std;

void speedTime() {
    float v, t;
    cin>>v>>t;
    float s1=v*t;
    float a=-v/t;
    float s2=a*t*t/2;
    cout<<s1<<" "<<s2<<" "<<(s1+s2)<<endl;
}
