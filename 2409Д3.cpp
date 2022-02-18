//
//  2409Д3.cpp
//  homework-3
//
//  Created by Соня Артеменко on 28.10.2021.
//

#include <stdio.h>
#include <iostream>
#include<cmath>

using namespace std;

void multiplicBitGeneral(long long a, long long b) {
    if (a<0 && b<0) {
        a=-a;
        b=-b;
    } else if (b<0) {
        a=-a;
        b=-b;
    }
    int c=0;
    while (b>0) {
        if (b%2==1) {
            c+=a;
        }
        b=b>>1;
        a=a<<1;
    }
    cout<<c;
}

long long exponenBit(long long a, long long b) {
    a=abs(a);
    long long c=0;
    while (b>0) {
        if (b%2==1) {
            c+=a;
        }
        b=b>>1;
        a=a<<1;
    }
    return c;
}

void dataIn() {
    long long a, b;
    cout<<"Ваши числа:"<<endl;
    cin>>a>>b;
    char z;
    cout<<"Вашa операция:"<<endl;
    cin>>z;
    void multiplicBit(long long a, long long b);
    long long exponenBit(long long a, long long b);
    if (z=='*') {
        multiplicBitGeneral(a, b);
    } else if (z=='+') {
        cout<<a+b<<endl;
    } else if (z=='-') {
        cout<<a-b<<endl;
    } else if (z=='%') {
        if (b!=0) {
        cout<<a%b<<endl;
        } else {cout<<"hell no pls no"<<endl;}
    } else if (z=='/') {
        if (b!=0) {
        cout<<a/b<<endl;
        } else {cout<<"hell no pls no"<<endl;}
    } else if (z=='^') {
        if (b==2 || b==4 || b==16 || b==32) {
            a=exponenBit(a, a);
            if (b==2) {
                cout<<a<<endl;
            } else if (b==4 || b==16 || b==32) {
                a=exponenBit(a, a);
                if (b==4) {
                    cout<<a<<endl;
                } else if (b==16 || b==32) {
                    a=exponenBit(a, a);
                    a=exponenBit(a, a);
                    if (b==16) {
                        cout<<a<<endl;
                    } else if (b==32) {
                            a=exponenBit(a, a);
                            cout<<a<<endl;
                        }
        } else {
            cout<<"not provided";
        }
    }

    }
    
}
}
