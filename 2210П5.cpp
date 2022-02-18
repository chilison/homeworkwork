//
//  2210П5.cpp
//  practice-4
//
//  Created by Соня Артеменко on 28.10.2021.
//

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

void p221021z5() {
    string s;
    getline(cin,s);
    int pos=-1;
    do{
        pos=s.find("password:", pos+1);
        if(pos!=-1)
        {

            for(int i=pos+9;i<=pos+16 && i<s.length();i++)
                s[i]='*';
        }
    } while(pos!=-1);

    cout<<s<<endl;
    
}
