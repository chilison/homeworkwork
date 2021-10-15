//
//  24.09.cpp
//  practice1
//
//  Created by Соня Артеменко on 15.10.2021.
//

#include <stdio.h>
#include <cmath>
#include <iostream>

using namespace std;

void iPositionReplacement11stPractice() {
    int x, i;
    cin>>x>>i;
    int xx=x>>(i-1);
    if (xx%2==0) {xx++;}
    xx=xx<<(i-1);
    xx=xx|x;
    cout<<xx;
}
