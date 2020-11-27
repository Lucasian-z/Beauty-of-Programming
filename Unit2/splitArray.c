#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define N 4
/* 给定一个正整数数组，元素个数为2n，如何把该数组分割为元素个数为n的两个数组，且二者和最接近
author: zhanghao
email: zhangh2548@outlook.com
date:2020/09/19 11:10:43
*/
int MIN(int a, int b) {
    return a > b ? b : a;
}
int arr[2*N + 1];
int dp[1000][1000] = {0};
void solve() {
    int sum = 0;
    for (int i = 1; i <= 2 * N; ++i) {
        sum += arr[i];
    }
    printf("sum = %d\n", sum);
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 1; i <= 2 * N; ++i) {//dp[i][j]表示从前i个数中取任意个数能否使其和等于j
        for (int j = MIN(i, N); j >= 1; --j) {
            for (int v = 1; v <= sum / 2; ++v) {//类似背包问题
                if (v >= arr[i] && dp[j-1][v-arr[i]]) {
                    dp[j][v] = 1;
                }
            }
        }
    }
    int s = 0;
    for (s = sum / 2; s >= 1 && !dp[N][s]; --s);
    printf("The difference of two subarrays is %d\n", sum - s * 2);//两个子数组的最小差值
}

int main()
{
    srand((unsigned int)time(NULL));
    for (int i = 1; i <= 2 * N; ++i) {
        arr[i] = rand() % 50;
        printf("%d ", arr[i]);
    }
    printf("\n");
    solve();
    return 0;
}