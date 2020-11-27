#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* 寻找数组的最小值和最大值
author: zhanghao
email: zhangh2548@outlook.com
date:2020/09/18 16:04:53
*/

int Min = INT_MAX, Max = INT_MIN;
//法1：按顺序将数组中相邻的两个数分为同一组，接着比较同一组中奇数位和偶数位,将较大的数放在偶数位，较小的数放在奇数位
#define N 10
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) > (y)) ? (y) : (x))
int arr[N];
void solve1() {
    srand((unsigned int)time(NULL));
    for (int i = 0; i < N; ++i) {
        arr[i] = rand() % 100;
        printf("%d ", arr[i]);
    }
    printf("\n");
    for (int i = 0; i < N; i += 2) {
        int m, n;
        if (i + 1 < N) {
            m = MAX(arr[i], arr[i + 1]);
            n = MIN(arr[i], arr[i + 1]);
            Max = MAX(Max, m);
            Min = MIN(Min, n);
        }else {
            Max = MAX(Max, arr[i]);
            Min = MIN(Min, arr[i]);
        }
    }
}

//法2：分治法求最大值
int solve2(int left, int right) {
    if (left == right) {
        Max = Min = arr[left];
        return Max;
    }
    int MaxL = solve2(left, left + (right - left) / 2);
    int MaxR = solve2(left + (right - left) / 2 + 1, right);
    int M = (MaxL > MaxR) ? MaxL : MaxR;
    return M;
}

int main()
{
    solve1();
    printf("Max = %d, Min = %d\n", Max, Min);
    int Max1 = solve2(0, N - 1);
    printf("Max1 = %d\n", Max1);
    return 0;
}