//
//  nearlyPi.cpp
//  crispy
//
//  Created by Соня Артеменко on 07.10.2021.
//


#include <stdio.h>
#include <iostream>
#include<cmath>
using namespace std;

void nearlyPi() {
    int K; double a = 0, b = 0;
    cin>>K;
    int n;
    if (K % 22 != 0) {
        n = K / 22 + 1;
    } else {
        n= K / 22;
    }
    a = 22 * n;
    b = 7 * n;
    cout<<a<<"/"<<b<<endl;
}
