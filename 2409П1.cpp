//
//  24.09.П.cpp
//  practice1
//
//  Created by Соня Артеменко on 15.10.2021.
//

#include <stdio.h>
#include <cmath>
#include <iostream>

using namespace std;

void sineDerivative1stPractice() {
    int n;
    cin>>n;
    if (n % 4 == 1) {
        cout<<"cos(x)"<<endl;
    } else if (n % 4 == 2) {
        cout<<"-sin(x)"<<endl;
    } else if (n % 4 == 3) {
        cout<<"-cos(x)"<<endl;
    } else {
        cout<<"sin(x)"<<endl;
    }
}

