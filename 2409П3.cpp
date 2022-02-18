//
//  2409П3.cpp
//  practice1
//
//  Created by Соня Артеменко on 15.10.2021.
//

#include <stdio.h>
#include <cmath>
#include <iostream>

using namespace std;


void iPositionReplacement01stPractice() {
    int x, i;
    cin>>x>>i;
    int xx=x>>(i-1);
    if (xx%2==1) {x=x-pow(2,i-1);}
    cout<<x;
}
