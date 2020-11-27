#include <iostream>
#include <vector>
using namespace std;
const int N = 10;

/* 电梯调度问题
author: zhanghao
email: zhangh2548@outlook.com
date: 2020/09/12 22:00:42
*/

int arr[N + 1] = {0, 2, 3, 3, 5, 21, 32, 3, 32, 7, 56};//arr[i]表示到第i层的乘客数目

//暴力解法
int solve1() {
    int targetFloor = -1;//电梯最终停的楼层
    int minFloor = INT_MAX;
    for (int i = 1; i <= N; ++i) {
        int nFloor = 0;
        for (int j = 1; j < i; ++j) {
            nFloor += arr[j] * (i - j);
        }
        for (int j = i + 1; j <= N; ++j) {
            nFloor += arr[j] * (j - i);
        }
        if (targetFloor == -1 || minFloor > nFloor) {
            targetFloor = i;
            minFloor = nFloor;
        }
    }
    return targetFloor;
}

//优化解法
int solve2() {
    int N1, N2, N3, i;
    int minFloor = 0, targetFloor = -1;
    for (N1 = 0, N2 = arr[1], N3 = 0, i = 2; i <= N; ++i) {
        N3 += arr[i];
        minFloor += arr[i] * (i - 1);
    }
    for (i = 2; i <= N; ++i) {
        if (N1 + N2 < N3) {
            minFloor += N1 + N2 - N3;
            targetFloor = i;
            N2 = arr[i];
            N1 += arr[i-1];
            N3 -= arr[i];
        }
        else {
            break;
        }

    }
    return targetFloor;
}


int main()
{
    int ans1 = solve1();
    int ans2 = solve2();
    printf("ans = %d, ans2 = %d\n", ans1, ans2);
    return 0;
}