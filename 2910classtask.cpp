//
//  homework-1.cpp
//  crispy
//
//  Created by Соня Артеменко on 07.10.2021.
//

#include "homework-1.hpp"
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

void ticket() {
    string s;                             //считываем как строку, чтобы после не запутаться с вычислениями
    cin >> s;
    int a = 0, z = 0;
    for (int i = 0; i < 3; i++) {         //сумма первых трех
        int b = s[i] - '0';               //переводим символ в число
        a += b;
    }
    for (int i = 3; i < 6; i++) {
        int b = s[i] - '0';               //то же самое
        z += b;
    }
    if (a == z) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
}

void maxInArray() {
    long long n, max = LONG_LONG_MIN, r = 0;         //ограничения не были прописаны, поэтомy long long
    cin >> n;
    long long a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {            //нет смысла сравнивать с предыдущими, т.к. такие пары уже были проверены
            if (a[i] == a[j] && a[i] > max) {
                max = a[i];
                r = 1;                               //переключатель, чтобы точно знать, нужное значение было равно минимальному
            }                                        //long long или max не менялся
        }
    }
    if (r != 0) {
        cout << max << endl;
    } else {
        cout << "there is no answer" << endl;
    }
    
}


int main() {
    void ticket();
    void maxInArray();
    //maxInArray();
    //ticket();
    return 0;
}
