
//бинарный поиск, вывести индекс, если нет - (-1)

#include <stdio.h>
#include <iostream>
#include<cmath>
#include <ctime>

using namespace std;
void search (int a[], int n, int x, int y) {
    if (x==y) {cout<<-1<<endl;}
    int mid = (x + y) / 2;

    if (a[mid] > n) {search(a, n, x, mid - 1);}
    else if (a[mid] == n) {cout<<mid<<endl; return;}
    else {search(a, n, mid+1, y);}
}

void binarySearch() {
    int k;
    cin>>k;
    int a[k];
    for (int i=0; i<k; i++) {
        cin>>a[i];
    }
    //cout<<a;
    int n;
    cin>>n;
    search(a, n, 0, k);
}

