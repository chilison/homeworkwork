//
//  handshakeCount.cpp
//  crispy
//
//  Created by Соня Артеменко on 07.10.2021.
//
#include <iostream>
#include <stdio.h>
using namespace std;

void handshakeCount() {
    int n;
    cin>>n;
    for (int i = 0; i < n; i++) {
        long p;
        cin>>p;
        long h = 0;
        h = p * (p - 1) / 2;
        cout<<h<<endl;
    }
}
