//
//  2409Д2.cpp
//  homework-3
//
//  Created by Соня Артеменко on 27.10.2021.
//

#include <stdio.h>
#include <iostream>
#include<cmath>


void multiplicBit(int a, int b) {
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
    std::cout<<c<<std::endl;
}
 
void multiplicBitMain() {
    int a, b;
    std::cout<<"Ваши числа:"<<std::endl;
    std::cin>>a>>b;
    multiplicBit(a, b);
}
