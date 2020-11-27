#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

/* 斐波那契数列
author: zhanghao
email: zhangh2548@outlook.com
date:2020/09/18 14:47:35
*/

//法1：递推式
int fibon[50];

int fib1(int n) {
    if (fibon[n] != -1) {
        return fibon[n];
    }
    return fibon[n] = fib1(n-1) + fib1(n-2);
}

int fib2(int n) {
    int a = 0, b = 1, c;
    for (int i = 2; i <= n; ++i) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

//法2：通项公式
double fib3(int n) {
    double c = sqrt(5.0);
    return c / 5 * (pow((1 + c) / 2, n) - pow((1 - c) / 2, n));
}

//法3：分治，矩阵乘法
class Matrix {
public:
    int matrix[2][2];
public:
    Matrix() {
        memset(matrix, 0, sizeof(matrix));
    }
    void Identity() {
        matrix[0][0] = matrix[1][1] = 1;
    }
    Matrix operator*(Matrix &A) {//矩阵乘法
        Matrix R;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                for (int k = 0; k < 2; ++k) {
                    R.matrix[i][j] += matrix[i][k] * A.matrix[k][j];
                }
            }
        }
        return R;
    }
};

Matrix matrixPow(const Matrix &m, int n) {//快速矩阵幂
    Matrix result;
    result.Identity();
    Matrix tmp = m;
    while (n) {
        if (n & 1) {
            result = result * tmp;
        }
        tmp = tmp * tmp;
        n >>= 1;
    }
    return result;
}

int fib4(int n) {
    Matrix A;
    A.matrix[0][0] = A.matrix[0][1] = A.matrix[1][0] = 1;
    Matrix ans = matrixPow(A, n - 1);
    return ans.matrix[0][0];
}

int main()
{
    int n;
    scanf("%d", &n);
    memset(fibon, -1, sizeof(fibon));
    fibon[0] = 0, fibon[1] = 1;
    int ans1 = fib1(n);
    printf("ans1 = %d\n", ans1);
    int ans2 = fib2(n);
    printf("ans2 = %d\n", ans2);
    int ans3 = fib3(n);
    printf("ans3 = %d\n", ans3);
    int ans4 = fib4(n);
    printf("ans4 = %d\n", ans4);
    return 0;
}