
#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;


void gaussianMain() {
    int n, m;
    cin>>n>>m;
    double a[n][m];
    //вставляем в матрицу значения
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            double b;
            cin>>b;
            a[i][j]=b;
        }
    }
    //идем до n, тк двигаемся по диагонали
    for ( int k = 0; k < n; k++ ) {
        int irem=k, jrem=k; double elrem=0;
        //находим максимальное значение, чтобы поставить на место k*k
        for (int i=k; i<n; i++) {
            for (int j=k; j<n; j++) {
                if (abs(a[i][j])>abs(elrem)) {
                    irem=i;
                    jrem=j;
                    elrem=a[i][j];
                }
            }
        }
        //ставим найденное значение в текущий левый верхний угол k*k
        //столбцы меняем местами
        for (int i=0; i<n; i++) {
            double b = a[i] [k];
            a[i] [k] = a[i] [jrem];
            a[i] [jrem] = b;
        }
        //и строки
        for (int i=k; i<n+1; i++) {
            double b = a[k] [i];
            a[k] [i] = a[irem] [i];
            a[irem] [i] = b;
        }
        //подгоняем верхние значения, чтобы после получить 1 слева
        double z=a[k][k]; //чтобы после не делить на 1
        for (int i=k; i<n; i++) {
            a[k][i]= a[k][i]/z;
        }
        //вычитаем
        for ( int i = k + 1; i < n; i++ ) {
            for ( int j = k; j <= n; j++ ) {
                a[i] [j] -= a[k] [j] * a[i] [k];
            }
        
     }
    
    
    for (int i=0; i<n; i++) {
        for (int j=0; j<m ; j++) {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

}






