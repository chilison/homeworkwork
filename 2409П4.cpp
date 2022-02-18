//
//  2409П4.cpp
//  practice1
//
//  Created by Соня Артеменко on 15.10.2021.
//

#include <stdio.h>
#include <cmath>
#include <iostream>

using namespace std;

void task3in11stPractice() {
    int x, y;
    cin>>x;
    int xx=x, xxx=x;
    x=(x>>1)<<1;
    cout<<xx<<" "<<x<< endl;
    if (xx==x) {cout<<"EVEN"<<endl;} else {cout<<"ODD"<<endl;}
    cin>>y;
    x=xx<<3;
    cout<<x<<endl;
    xxx = xxx ^ y;
    y = y ^ xxx;
    xxx = xxx ^ y;
    cout<<xxx<<" "<<y<<endl;
}
