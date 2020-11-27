#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* 蚂蚁爬杆问题
author: zhanghao
email: zhangh2548@outlook.com
date: 2020/09/24 10:56:43
*/

#define N 10

int arr[N];
int len = 0;//杆长
void solve() {
    int minTime = INT_MAX, maxTime = 0;
    for (int i = 0; i < N; ++i) {
        minTime = min(minTime, min(arr[i], len - arr[i]));
        maxTime = max(maxTime, max(arr[i], len - arr[i]));
    }
    printf("minTime = %d, maxTime = %d\n", minTime, maxTime);
}

int main()
{
    scanf("%d", &len);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &arr[i]);
    }
    solve();
    return 0;
}