//
//  changeBytes.cpp
//  practice-5
//
//  Created by Соня Артеменко on 12.11.2021.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;


void change(int *&x) {
    string s = "";
    int m=0;
    string str;
    while (*x>=2) {
        str = to_string((*x)%2);
        s=str+s;
        int k=(*x)/2;
        *x=k;
    }
    str = to_string((*x)%2);
    s=str+s;

    while (s.length()!=32) {
        s='0'+s;
    }
    cout<<s.substr(0,8)+" "+s.substr(8,8)+" "+s.substr(16,8)+" "+s.substr(24,8)<<endl;
    s=s.substr(8, 24)+s.substr(0, 8);
    cout<<s.substr(0,8)+" "+s.substr(8,8)+" "+s.substr(16,8)+" "+s.substr(24,8)<<endl;
    for (int i=1; i<32; i++) {
        int k=pow(2, 31-i);
        if (s[i]=='1') {
            m+=k;
        }
        //cout<<m<<" "<<s[i]<<" "<<" "<<(31-i)<<" "<<k<<endl<<endl;
    }
    if (s[0]=='1') {m=-m;}
    cout<<m<<endl<<endl;
}


void changeX(int *&xx) {
    unsigned char *b = (unsigned char*)xx, t, t1, t2, t3;
    t = *(b+3);
    t1 = *(b+2);
    *(b+3)=t1;
    t2 = *(b+1);
    *(b+2)=t2;
    t3 = *(b);
    *(b+1)=t3;
    *b = t;
}
    
    
void z3() {
    int a;
    cin>>a;
    int b=a;
    int *x=&a;
    int *xx=&b;
    
    change(x);
    changeX(xx);
    cout<<*xx<<endl;
}
