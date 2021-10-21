//
//  1510П4.cpp
//  practice-2
//
//  Created by Соня Артеменко on 21.10.2021.
//


#include <stdio.h>
#include <iostream>
#include<cmath>
#include <ctime>

using namespace std;

void p151021z4() {
    int n;
    cin>>n;
    int *a=new int[n];
    for (int i=0; i<n; i++) {
        a[n]=i;
    }
    for (int i=0; i<n; i++) {
        cout<<"ячейка "<<i<<" где-то здесь "<<&a[i]<<endl;
    }
    
    
    
}
