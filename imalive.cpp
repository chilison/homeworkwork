//
//  imalive.cpp
//  practice-5
//
//  Created by Соня Артеменко on 18.11.2021.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

void iMAlive(int *&n) {
    static int r=0;
    if (r==0) {
        cout<<"Hello world! I was born!!!"<<endl;
    } else if (r<=*n) {
        cout<<"I'm alive"<<endl;
    } else {
        cout<<"Bye, bye, dear, I'm already asleep..."<<endl;
    }
    r++;
}

void z4() {
    int n;
    cin>>n;
    int *ptr=new int(n);
    int m;
    cin>>m;
    for (int i=0;i<m; i++) {
        iMAlive(ptr);
    }
}
