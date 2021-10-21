//
//  1510П3.cpp
//  practice-2
//
//  Created by Соня Артеменко on 16.10.2021.
//

#include <stdio.h>
#include <iostream>
#include<cmath>
#include <ctime>

using namespace std;

void p151021z3() {
    int n, m;
    cin>>n>>m;
    int **a = new int*[n];
    for (int i = 0; i < n; i++) {
        a[i]=new int[m];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int b= 0+rand() % 101;
            a[i][j]=b;
        }
    }
    for (int i = 0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    for (int i=0; i<n; i++) {
        delete[] a[i];
    }
    delete [] a;
}
