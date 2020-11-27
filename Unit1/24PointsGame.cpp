#include <iostream>
#include <string>
#include <cmath>
using namespace std;

/* 24点游戏解法
author: zhanghao
email: zhangh2548@outlook.com
date: 2020/09/16 13:26:26
*/

const int N = 4;
const int resultValue = 24;
double number[N];
string result[N];
const double threshold = 1E-6;

bool PointGame(int n) {
    if (n == 1) {
        if (fabs(number[0] - resultValue) < threshold) {
            cout << result[0] << endl;
            return true;
        }else {
            return false;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            double a, b;
            string expa, expb;
            a = number[i];
            b = number[j];
            number[j] = number[n - 1];

            expa = result[i];
            expb = result[j];
            result[j] = result[n - 1];

            result[i] = '(' + expa + '+' + expb + ')';
            number[i] = a + b;
            if (PointGame(n - 1)) {
                return true;
            }

            result[i] = '(' + expa + '-' + expb + ')';
            number[i] = a - b;
            if (PointGame(n - 1)) {
                return true;
            }

            result[i] = '(' + expb + '-' + expa + ')';
            number[i] = b - a;
            if (PointGame(n - 1)) {
                return true;
            }

            result[i] = '(' + expa + '*' + expb + ')';
            number[i] = a * b;
            if (PointGame(n - 1)) {
                return true;
            }

            if (b != 0) {
                result[i] = '(' + expa + '/' + expb + ')';
                number[i] = a / b;
                if (PointGame(n - 1)) {
                    return true;
                }
            }

            if (a != 0) {
                result[i] = '(' + expb + '/' + expa + ')';
                number[i] = b / a;
                if (PointGame(n - 1)) {
                    return true;
                }
            }

            number[i] = a;
            number[j] = b;
            result[i] = expa;
            result[j] = expb;
            
        }
    }
    return false;
}


int main()
{
    for (int i = 0; i < N; ++i) {
        cin >> number[i];
        result[i] = to_string(int(number[i]));
    }
    
    if (PointGame(N)) {
        cout << "Success!" << endl;
    }else {
        cout << "Failed!" << endl;
    }
    return 0;
}