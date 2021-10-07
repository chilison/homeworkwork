//
//  dotsInCircle.cpp
//  crispy
//
//  Created by Соня Артеменко on 07.10.2021.
//
#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

void dotsInCircle() {
    int n;
    cin>>n;
    for (int i=0; i<n; i++) {
        int r, t, k=0;
        cin>>r>>t;
        for (int i=0; i<t; i++) {
            int x, y;
            cin>>x>>y;
            double s=sqrt(x*x+y*y);
            if (s<=r) {k++;}
        }
        cout<<k<<endl;
    }
}
