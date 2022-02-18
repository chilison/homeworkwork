//
//  triangleHeight.cpp
//  crispy
//
//  Created by Соня Артеменко on 07.10.2021.
//

#include <iostream>
#include <stdio.h>
using namespace std;
void triangleHeight() {
    int n;
    cin>>n;
    for (int i = 0; i < n; i++) {
        double a, S;
        cin>>a>>S;
        double h = 2 * S / a;
        cout<<h<<endl;
    }
}
