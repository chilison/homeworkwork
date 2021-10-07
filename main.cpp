//
//  main.cpp
//  crispy
//
//  Created by Соня Артеменко on 16.09.2021.
//

#include <iostream>
#include<cmath>
#include <ctime>

using namespace std;
void sineDerivative1stPractice() {
    int n;
    cin>>n;
    if (n % 4 == 1) {
        cout<<"cos(x)"<<endl;
    } else if (n % 4 == 2) {
        cout<<"-sin(x)"<<endl;
    } else if (n % 4 == 3) {
        cout<<"-cos(x)"<<endl;
    } else {
        cout<<"sin(x)"<<endl;
    }
}
void iPositionReplacement11stPractice() {
    int x, i;
    cin>>x>>i;
    int xx=x>>(i-1);
    if (xx%2==0) {xx++;}
    xx=xx<<(i-1);
    xx=xx|x;
    cout<<xx;
}
void iPositionReplacement01stPractice() {
    int x, i;
    cin>>x>>i;
    int xx=x>>(i-1);
    if (xx%2==1) {x=x-pow(2,i-1);}
    cout<<x;
}
void task3in11stPractice() {
    int x, y;
    cin>>x;
    int xx=x;
    x=(x>>1)<<1;
    cout<<xx<<" "<<x<< endl;
    if (xx==x) {cout<<"EVEN"<<endl;} else {cout<<"ODD"<<endl;}
    cin>>y;
    // как это делат????
    x=xx<<3;
    cout<<x<<endl;
}
void speedTime() {
    float v, t;
    cin>>v>>t;
    float s1=v*t;
    float a=-v/t;
    float s2=a*t*t/2;
    cout<<s1<<" "<<s2<<" "<<(s1+s2)<<endl;
}
void xToY() {
    int x, y;
    cin>>x>>y;
    cout<<x<<" "<<y<<endl;
    x = x ^ y;
    y = y ^ x;
    x = x ^ y;
    cout<<x<<" "<<y<<endl;
}
void handshakeCount() {
    long p;
    cin>>p;
    long h=0;
    h=p*(p-1)/2;
    cout<<h<<endl;
}
void triangleHeight() {
    double a, S;
    cin>>a>>S;
    double h=2*S/a;
    cout<<h<<endl;
}
void dotsInCircle() {
    int r, t, k=0;
    cin>>r>>t;
    for (int i=0; i<t; i++) {
        int x, y;
        cin>>x>>y;
        double s=sqrt(x*x+y*y);
        if (s<=r) {k++;}
    }
    cout<<k<<endl;
}
void lifeDuration() {
    //time_t now = time(0);
    //tm *ltm = localtime(&now);
    int bday, bmonth, byear;
    cin>>bday>>bmonth>>byear;
    cout<<bday<<" "<<bmonth<<" "<<byear<<endl;
    //int currday=ltm->tm_mday, currmonth=1 + ltm->tm_mon, year=1970 + ltm->tm_year;
    //cout<<currday<<" "<<currmonth<<" "<<year<<endl;
    int currday=7, currmonth=10, year=2021;
    int k=0;
    int dim[]={0, 31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    while (bday!=currday || bmonth!=currmonth || byear!=year) {
        int feb, currdim;
        if (byear%400==0 || (byear%4==0 && byear%100!=0)) {
            feb=29;
        } else {feb=28;}
        if (bmonth==2) {
            currdim=feb;
        } else {
            currdim=dim[bmonth];
        }
        if (bday==31 && bmonth==12) {
            bday=1; bmonth=1; byear++;
        } else if (bday==currdim) {
            bday=1; bmonth++;
        } else {
            bday++;
        }
        k++;
        cout<<k<<" "<<bday<<" "<<bmonth<<" "<<byear<<endl;
    }
    cout<<k<<endl;
}
void nearlyPi() {
    int K; double a=0, b=0;
    cin>>K;
    int n;
    if (K%22!=0) {n=K/22+1;} else {n=K/22;}//n=23456/22+1=1066+1=1067; 1067*22>23456
    a=22*n;
    b=7*n;
    cout<<a<<"/"<<b<<endl;
}
int main() {
    //sineDerivative1stPractice();
    //iPositionReplacement11stPractice();
    //iPositionReplacement01stPractice();
    //task3in11stPractice();
    //xToY();
    int n;
    cin>>n;
    for (int i=0; i<n; i++) {
        //handshakeCount();
        //triangleHeight();
        //dotsInCircle();
    }
    //lifeDuration();
    nearlyPi();
    return 0;
}
