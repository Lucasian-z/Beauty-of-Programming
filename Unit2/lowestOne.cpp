#include <iostream>

using namespace std;

/* 求N!二进制中最低位1的位置
author: zhanghao
email: zhangh2548@outlook.com
date: 2020/09/16 16:27:28
*/

//N!质因子2的个数+1
int lowestOne1(int N) {
    int ans = 0;
    while (N) {
        N >>= 1;
        ans += N;
    }
    return ans + 1;
}

//N!质因子2的个数等与N-N的二进制中1的数目
int lowestOne2(int N) {
    int ans = 0;
    int M = N;
    while (N) {
        N &= (N - 1);
        ++ans;
    }
    return M - ans + 1;
}

int main()
{
    int n;
    while (cin >> n) {
        printf("#ans1 = %d, #ans2 = %d\n", lowestOne1(n), lowestOne2(n));
    }
    return 0;
}