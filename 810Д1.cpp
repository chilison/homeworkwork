//
//  main.cpp
//  hw5
//
//  Created by Соня Артеменко on 21.10.2021.
//

#include <iostream>
using namespace std;

int main() {
    
            int n = rand(), k;
            cin>>k;
            char a[n][n];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    int a1=rand(), a2=rand();
                    if (a1>a2) {
                        a[i][j] = '.';} else {a[i][j] = '0';}
                }
            }
            for (int z = 0; z < k; z++) {
                char aa[n][n];
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        int p = 0;
                        if (i == 0) {
                            if (a[n - 1][j] == '.') {
                                p++;
                            }
                        } else {
                            if (a[i - 1][j] == '.') {
                                p++;
                            }
                        } //вверх
                        if (j == 0) {
                            if (a[i][n - 1] == '.') {
                                p++;
                            }
                        } else {
                            if (a[i][j - 1] == '.') {
                                p++;
                            }
                        } //влево
                        if (i == n - 1) {
                            if (a[0][j] == '.') {
                                p++;
                            }
                        } else {
                            if (a[i + 1][j] == '.') {
                                p++;
                            }
                        } //вниз
                        if (j == n - 1) {
                            if (a[i][0] == '.') {
                                p++;
                            }
                        } else {
                            if (a[i][j + 1] == '.') {
                                p++;
                            }
                        } //вправо
                        if (i == 0 || j == n - 1) {
                            if (i == 0 && j == n - 1) {
                                if (a[n - 1][0] == '.') {
                                    p++;
                                }
                            } else if (i==0 && a[n - 1][j + 1] == '.' || j==n-1 && a[i-1][0] == '.') {
                                p++;
                            }
                        } else {
                            if (a[i - 1][j + 1] == '.') {
                                p++;
                            }
                        } //вправо и вверх
                        if (i == 0 || j==0) {
                            if (j == 0 && i==0) {
                                if (a[n - 1][n - 1] == '.') {
                                    p++;
                                }
                            } else if (i==0 && a[n - 1][j-1] == '.' || j==0 && a[i-1][n-1]=='.') {
                                p++;
                            }
                        } else {
                            if (a[i - 1][j - 1] == '.') {
                                p++;
                            }
                        } //влево и вверх
                        if (i == n - 1 || j == 0) {
                            if (j == 0 && i==n-1) {
                                if (a[0][n - 1] == '.') {
                                    p++;
                                }
                            } else if (i==n-1 && a[0][j - 1] == '.' || j==0 && a[i+1][n-1]=='.')  {
                                p++;
                            }
                        } else {
                            if (a[i + 1][j- 1] == '.') {
                                p++;
                            }
                        } //вниз и влево
                        if (i == n - 1 || j==n-1) {
                            if (j == n - 1 && i==n-1) {
                                if (a[0][0] == '.') {
                                    p++;
                                }
                            } else if (i==n-1 && a[0][j + 1] == '.' || j==n-1 && a[i+1][0] == '.') {
                                p++;
                            }
                        } else {
                            if (a[i + 1][j + 1] == '.') {
                                p++;
                            }
                        } //вниз и вправо
                        if (a[i][j] == '0') {
                            if (p == 3) {
                                aa[i][j] = '.';
                            } else {
                                aa[i][j] = '0';
                            }
                        }
                        if (a[i][j] == '.') {
                            if (p == 3 || p == 2) {
                                aa[i][j] = '.';
                            } else {
                                aa[i][j] = '0';
                            }
                        }
                      
                    }
                   
                }
                for (int i = 0; i < n; i++) {
                    for (int j=0; j<n; j++) {
                        a[i][j]=aa[i][j];
                    }
                }
            }
            for (int i = 0; i < n; i++) {
                for (int j=0; j<n; j++) {
                    cout<<a[i][j];
                }
                cout<<endl;
            }
        }
    
