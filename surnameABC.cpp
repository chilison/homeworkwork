//
//  surnameABC.cpp
//  practice-5
//
//  Created by Соня Артеменко on 12.11.2021.
//

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

void z1() {
    int n;
    cin>>n;
    string *a=new string[n];
    for (int i=0; i<n ; i++) {
        cin>>a[i];
    }
    for (int i=0; i<n-1; i++) {
        for (int j=i+1; j<n; j++)  {
            for (int k=0;k<min(a[i].length(), a[j].length()); k++) {
                if (k==min(a[i].length(), a[j].length())-1 && a[i].length()>a[j].length()) {
                    string b=a[i];
                    a[i]=a[j];
                    a[j]=b;
                }
                if (a[i][k]>a[j][k]) {
                    string b=a[i];
                    a[i]=a[j];
                    a[j]=b;
                    break;
                } else if (a[i][k]<a[j][k]) {
                    break;
                }
            }
        }
    }
    for (int i=0; i<n; i++) {
        cout<<a[i]<<endl;
    }
    delete [] a;
    
}
