//
//  main.cpp
//  homework-5
//
//  Created by Соня Артеменко on 21.10.2021.
//

#include <iostream>

using namespace std;

void arrayFilling(int b[], size_t n) {
    for (size_t i=0; i<n; i++) {
        for (size_t j=0; j<n; j++) {
            b[i*n+j]=(int)i*n+j+1;
        }
    }
}
void arrayDiagonalSwitchEven(int b[], size_t n) {
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            if (i >= j) {
                int a = b[i*n+j];
                b[i*n+j] = b[j*n+i];
                b[j*n+i] = a;
            }
        }
    }
}
void arrayDiagonalSwitchOdd(int b[], size_t n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i<n-j) {
                int a=b[i*n+j];
                b[i*n+j]=b[(n-j-1)*n+n-i-1];
                b[(n-j-1)*n+n-i-1]=a;
            }
        }
    }
}
void arrayTurn(int b[], size_t n) {
    //нечетные
    for (size_t i=0; i<n; i+=2) {
        int t=b[i*n];
        for (size_t j=0; j<n-1; j++) {
            b[i*n+j]=b[i*n+j+1];
        }
        b[i*n+n-1]=t;
    }
    //четные
    for (size_t i=1; i<n; i+=2) {
        int t=b[i*n+n-1];
        for (size_t j=n-1; j>0; j--) {
            b[i*n+j]=b[i*n+j-1];
        }
        b[i*n]=t;
    }
}

void arrayOrderEven(int b[], size_t n) {
    for (int r = 0; r < n - 1; r++) {
        for (int i = 0; i < n - 1; i++) {
            for (int j = i; j < n - 1; j++) {
                if (j + 1 + r < n) {
                    if (b[i*n +i + r] > b[(j + 1)*n+j + 1 + r]) {
                        int a = b[i*n +i + r];
                            b[i*n +i + r] = b[(j + 1)*n+j + 1 + r];
                            b[(j + 1)*n+j + 1 + r] = a;
                    }
                }
            }
        }
    }
    arrayDiagonalSwitchEven(reinterpret_cast<int *>( b ), n);
    for (int r = 0; r < n - 1; r++) {
        for (int i = 0; i < n - 1; i++) {
            for (int j = i; j < n - 1; j++) {
                if (j + 1 + r < n) {
                    if (b[i*n +i + r] > b[(j + 1)*n+j + 1 + r]) {
                        int a = b[i*n +i + r];
                            b[i*n +i + r] = b[(j + 1)*n+j + 1 + r];
                            b[(j + 1)*n+j + 1 + r] = a;
                    }
                }
            }
        }
    }
    arrayDiagonalSwitchEven(reinterpret_cast<int *>( b ), n);
}

void arrayOrderOdd(int b[], size_t n) {
    for (int r = 0; r < n - 1; r++) {
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n-r; j++) {
                if (b[i*n+n - 1 - i - r] < b[j*n+n - 1 - (j) - r]) {
                    int a = b[i*n+n - 1 - i - r];
                    b[i*n+n - 1 - i - r] = b[j*n+n - 1 - (j) - r];
                    b[j*n+n - 1 - (j) - r] = a;
                }
            }
        }
    }
    arrayDiagonalSwitchOdd(reinterpret_cast<int *>( b ), n);
    for (int r = 0; r < n - 1; r++) {
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n-r; j++) {
                if (b[i*n+n - 1 - i - r] < b[j*n+n - 1 - (j) - r]) {
                    int a = b[i*n+n - 1 - i - r];
                    b[i*n+n - 1 - i - r] = b[j*n+n - 1 - (j) - r];
                    b[j*n+n - 1 - (j) - r] = a;
                }
            }
        }
    }
    arrayDiagonalSwitchOdd(reinterpret_cast<int *>( b ), n);
}

int main() {
    int n, k=0;
    cin>>n;
    int b[n][n];
    arrayFilling(reinterpret_cast<int *>( b ), n);
    while (true) {
        int a;
        cin>>a;
        if (a==0) {
            arrayTurn(reinterpret_cast<int *>( b ), n);
            k++;
            for (int i=0; i<n; i++) {
                for (int j=0; j<n; j++) {
                    cout<<b[i][j]<<" ";;
                }
                cout<<endl;
            }
        } else if (a==1) {
            if (k%2==0) {
                arrayOrderEven(reinterpret_cast<int *>( b ), n);
            } else {
                arrayOrderOdd(reinterpret_cast<int *>( b ), n);
            }
            for (int i=0; i<n; i++) {
                for (int j=0; j<n; j++) {
                    cout<<b[i][j]<<" ";;
                }
                cout<<endl;
            }
        } else {
            return 0;
        }
    }
}
