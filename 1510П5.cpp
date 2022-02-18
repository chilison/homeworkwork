//
//  1510П5.cpp
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
        a[i]=i;
    }
    int *ptr = &a[n-1];
    for (int i=0; i<n; i++) {
        cout<<*ptr<<endl;
        ptr--;
    }
}
