//
//  sortNlink.cpp
//  practice-5
//
//  Created by Соня Артеменко on 12.11.2021.
//

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

void sortNlink(int *&x, int *&y, int *&z) {
    int a[3]={*x, *y, *z};
    for (int i=0; i<2; i++) {
            for (int j=i+1; j<3; j++) {
                if (a[i]<a[j]) {
                    int t=a[j];
                    a[j]=a[i];
                    a[i]=t;
                }
            }
        }
    *x=a[0]; *y=a[1]; *z=a[2];
    cout<<*x<<" "<<*y<<" "<<*z<< endl;
}

void z2() {
    int a, b, c;
    cin>>a>>b>>c;
    int *x=&a;
    int *y=&b;
    int *z=&c;
    sortNlink(x, y, z);
}
    
  
