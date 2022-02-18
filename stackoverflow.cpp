//
//  stackoverflow.cpp
//  practice-4
//
//  Created by Соня Артеменко on 22.10.2021.
//

#include <stdio.h>
#include <iostream>
#include<cmath>
#include <ctime>

using namespace std;

void overflowFib(long long n, long long a, long long b, long long curr) {
    if (curr!=n) {
        long c=b;
        b=b+a;
        a=c;
        overflowFib(n+2, a, b, curr+1);
    } else {cout<<b<<" ";}
}

void p221021z2() {
    long long n=10, b=1, a=1;
    overflowFib(n, a, b, 2);
}
