//
//  2210П1.cpp
//  practice-4
//
//  Created by Соня Артеменко on 22.10.2021.
//

#include <stdio.h>
#include <iostream>
#include<cmath>

using namespace std;

void fib(long long n, long long a, long long b, long long curr) {
    if (curr!=n) {
        long c=b;
        b=b+a;
        a=c;
        fib(n, a, b, curr+1);
    } else {cout<<b<<" ";}
}

void p221021z1() {
    long long n, b=1, a=1, k=1, s=0, p=0;
    cin>>n;
    fib(n, a, b, 2);
    //или
    n=n-1;
    for (int l=0; n>l; l++ ) {
        p=k;  k=s+k; s=p;
    }
    cout<<k;
}
