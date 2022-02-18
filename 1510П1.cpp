//
//  1510П1.cpp
//  practice-2
//
//  Created by Соня Артеменко on 15.10.2021.
//

#include <stdio.h>
#include <iostream>
#include<cmath>
#include <ctime>

using namespace std;

void p151021z1() {
    int s=0, k;
    cin>>k;
    int a[k];
    int *i=&s;
    while (*i!=k) {
        cin>>a[*i];
        *i=*i+1;
    }
}
