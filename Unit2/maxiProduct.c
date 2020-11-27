#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) > (b) ? (b) : (a))

/*给定一个数组，长度为N，计算任意(N-1)个数的最大乘积
author: zhanghao
email: zhangh2548@outlook.com
date:2020/09/18 21:48:17
*/

int arr[N];

int solve() {
    srand((unsigned int)time(NULL));
    int res = 1;
    for (int i = 0; i < N; ++i) {
        arr[i] = rand() % 10;
    }
    int negaCnt = 0, posiCnt = 0, zeroCnt = 0, negaMax = INT_MIN, posiMin = INT_MAX;
    for (int i = 0; i < N; ++i) {
        if (arr[i] > 0) {
            ++posiCnt;
            posiMin = min(posiMin, arr[i]);
        }else if (arr[i] < 0) {
            ++negaCnt;
            negaMax = max(negaMax, arr[i]);
        }else {
            ++zeroCnt;
        }
    }
    int flag = 0;
    if (zeroCnt > 0) {
        if (zeroCnt > 1 || (negaCnt & 1)) {
            res = 0;
        }else {
            for (int i = 0; i < N; ++i) {
                if (arr[i]) {
                    res *= arr[i];
                }
            }
        }
    }else if (negaCnt & 1) {
        for (int i = 0; i < N; ++i) {
            if (arr[i] == negaMax && !flag) {
                flag = 1;
                continue;
            }
            res *= arr[i];
        }
    }else {
        for (int i = 0; i < N; ++i) {
            if (arr[i] == posiMin && !flag) {
                flag = 1;
                continue;
            }
            res *= arr[i];
        }
    }
    return res;
}

int main()
{
    int maxProduct = solve();
    for (int i = 0; i < N; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("The maxValue is %d\n", maxProduct);
    return 0;
}