//
//  main.cpp
//  homework-6
//
//  Created by Соня Артеменко on 27.10.2021.
//

#include <iostream>

using namespace std;

void arrayFilling(int **a, int n, int m) {
     for (int  i=0; i<n; i++) {
         for (int j=0; j<m; j++) {
             a[i][j]=10+rand()%50;
         }
     }
 }

void print(int **a, int n, int m) {
     for (int  i=0; i<n; i++) {
         for (int j=0; j<m; j++) {
             cout<<a[i][j]<<" ";
         }
         cout<<endl;
     }
 }

int main() {
    
    int n, m;
    cin>>n>>m;
    int **a = new int*[n];
    for (int i = 0; i < n; i++) {
        a[i]=new int[m];
    }
    arrayFilling(a, n, m);
    print(a, n, m);
    for (int i=0; i<n; i++) {
        delete[] a[i];
    }
    delete [] a;
}

