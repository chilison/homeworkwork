//
//  1510П2.cpp
//  practice-2
//
//  Created by Соня Артеменко on 16.10.2021.
//

#include <stdio.h>
#include <iostream>
#include<cmath>
#include <ctime>

using namespace std;

void p151021z2() {
    int a=2; int *aa=&a; cout<<"adress of variable "<<aa<<" size of variable "<<sizeof(*aa)<<endl;
    char b='b'; char *bb=&b; cout<<"adress of variable "<<bb<<" size of variable "<<sizeof(*bb)<<endl;
    bool c=false; bool *cc=&c; cout<<"adress of variable "<<cc<<" size of variable "<<sizeof(*cc)<<endl;
    short d=22; short *dd=&d; cout<<"adress of variable "<<dd<<" size of variable "<<sizeof(*dd)<<endl;
    long e=2222222; long *ee=&e; cout<<"adress of variable "<<ee<<" size of variable "<<sizeof(*ee)<<endl;
    float f=2.2; float *ff=&f; cout<<"adress of variable "<<ff<<" size of variable "<<sizeof(*ff)<<endl;
    double g=2.22; double *gg=&g; cout<<"adress of variable "<<gg<<" size of variable "<<sizeof(*gg)<<endl;
    long double h=22567.22212313; long double *hh=&h; cout<<"adress of variable "<<hh<<" size of variable "<<sizeof(*hh)<<endl;
    int i[2]; int *ii; ii=i; cout<<"adress of variable "<<ii<<" size of variable "<<sizeof(*ii)<<endl;
    
    
    
}
