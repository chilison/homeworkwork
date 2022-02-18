//
//  2210П3.cpp
//  practice-4
//
//  Created by Соня Артеменко on 28.10.2021.
//

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

void p221021z3 () {
    string s, ans;
    cin>>s;
    int curr=0, currsum=0;
    for (int i=0; i<s.length(); i++) {
        if (s[i]=='+' && (i==0 || i==s.length()-1 || isdigit(s[i-1])==false || isdigit(s[i+1])==false)) {
            s[i]=' ';
        }
    }
    //cout<<s<<endl;
    for (int i=0; i<s.length(); i++) {
        
        if (isdigit(s[i])==false && s[i]!='+') {
            if (isdigit(s[i-1])==true) {
                currsum+=curr;
                ans+=to_string(currsum);
                currsum=0;
                curr=0;
            }
            ans+=s[i];
        } else if (s[i]=='+'){
            currsum+=curr;
            curr=0;
        } else if (isdigit(s[i])==true) {
            char ss=s[i];
            int b=ss-'0';
            curr=curr*10+b;
        }
        //cout<<i<<" "<<currsum<<" "<<curr<<endl;
    }
    
    currsum+=curr;
    if (currsum!=0) {
        ans+=to_string(currsum);
    }
    
    for (int i=0; i<ans.length(); i++) {
        if (ans[i]==' ') {
            cout<<'+';
        } else {
            cout<<ans[i];
            
        }
    }
    cout<<endl;
}
