//
//  main.cpp
//  practice-11
//
//  Created by Соня Артеменко on 03.12.2021.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Behavior {
     string action;
     int points;
};
struct Chain {
    vector<Behavior> chain;
};

int hashCode(string str) {
    int k = 0;
    for (int i = 0; i < str.length(); i++) {
        k += str[i];
    }
    return k%1000;
}
void add(Chain *a, string str, int val) {
    int hash = hashCode(str);
    cout<<hash<<endl;
    a[hash].chain.push_back({str, val});
}
void get(Chain *a, string str) {
    int hash = hashCode(str);
    for (int i=0; i<a[hash].chain.size(); i++) {
        cout<<" action: "<<a[hash].chain.at(i).action<<"   points: "<<a[hash].chain.at(i).points<<endl;
    }
}
void remove(Chain *a, string str) {
    int hash = hashCode(str);
    for (int i=0; i<a[hash].chain.size(); i++) {
        if (a[hash].chain.at(i).action == str) {
            a[hash].chain.erase(a[hash].chain.begin() + i);
        }
    }
}
int size(Chain *a) {
    int k = 0;
    for (int i=0; i<1000; i++) {
        k+=a[i].chain.size();
    }
    return k;
}
int main() {
    Chain *a = new Chain[1000];
    int n;
    cin>>n;
    for (int i=0; i<n; i++) {
        string str;
        int val;
        cin>>str;
        cin>>val;
        add(a, str, val);
    }
    
    string str;
    cin>>str;
    get(a, str);
    
    cin>>str;
    remove(a, str);
    
    cin>>str;
    get(a, str);
    
    int k=size(a);
    cout<<k<<endl;
    
    return 0;
}




   

    
