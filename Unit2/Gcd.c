#include <stdio.h>
#include <stdlib.h>

/*
author: zhanghao
email: zhangh2548@outlook.com
date:2020/09/18 11:27:26
*/

//辗转相除法
int gcd1(int x, int y) {
    return y == 0 ? x : gcd1(y, x % y);
}

//优化去除大整数的取模运算
int gcd2(int x, int y) {
    if (x < y) {
        return gcd2(y, x);
    }
    if (y == 0) {
        return x;
    }
    return gcd2(x - y, y);
}

//优化去除减法
int gcd3(int x, int y) {
    if (x < y) {
        return gcd3(y, x);
    }
    if (y == 0) {
        return x;
    }
    if (x & 1) {//x是奇数
        if (y & 1) {
            return gcd3(y, x - y);
        }else {
            return gcd3(x, y >> 1);
        }
    }else {
        if (y & 1) {
            return gcd3(x >> 1, y);
        }else {
            return gcd3(x >> 1, y >> 1) << 1;
        }
    }
}

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    int ans1 = gcd1(m, n);
    int ans2 = gcd2(m, n);
    int ans3 = gcd3(m, n);
    printf("ans1 = %d, ans2 = %d, ans3 = %d\n", ans1, ans2, ans3);
    return 0;
}