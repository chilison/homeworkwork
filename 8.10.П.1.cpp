
//сортировка пузырьком, минимум, максимум, размах, медиана и мода

#include <stdio.h>
#include <iostream>
#include<cmath>
#include <ctime>

using namespace std;

void sortingTask() {
    int n; double sum=0;
    cin>>n;
    double k=n;
    int a[n];
    
    for (int i=0; i<n; i++) {
        cin>>a[i];
        sum+=a[i];
    }
    for (int i=0; i<n-1; i++) {
        for (int j=i+1; j<n; j++) {
            if (a[i]>a[j]) {
                a[j]=a[i]+a[j];
                a[i]=a[j]-a[i];
                a[j]=a[j]-a[i];
            }
        }
    }
    /*for (int i=0; i<n; i++) {
        cout<<a[i]<<endl;
    }*/
    int modamax=1, curr=1, rem=0;
    for (int i=1; i<n; i++) {
        if (a[i]==a[i-1]) {
            curr++;
            if (curr>modamax) {
                modamax=curr;
                rem=a[i];
            }
        } else {
            if (curr>modamax) {
                modamax=curr;
                rem=a[i];
            }
            curr=1;
        }
    }
    
    cout<<"MAX = "<<a[n-1]<<endl;
    cout<<"min = "<<a[0]<<endl;
    cout<<"размах = "<<(a[n-1]-a[0]);
    cout<<"среднее = "<<sum/k<< endl;
    if (n%2==0) {
        cout<<"медиана = "<<a[(n-1)/2]<<endl;
    } else {
        cout<<"медиана = "<<a[n/2]<<endl;
    }
    cout<<modamax<<" times of "<<rem<<endl;
}
