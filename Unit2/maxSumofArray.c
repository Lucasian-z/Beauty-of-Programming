#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define M 5
#define N 5

/* 求二维数组子数组的最大值
author: zhanghao
email: zhangh2548@outlook.com
date:2020/09/19 09:42:54
*/

int arr[M+1][N+1];
int getMaxSum(int arr[][N+1]) {
    int maxS = INT_MIN;
    for (int i = 1; i <= M; ++i) {
        for (int j = 1; j <= N; ++j) {
            arr[i][j] += arr[i-1][j];//竖向前缀和
        }
    }
    int tmpS = 0, tmpMax = 0;
    for (int i = 1; i <= M; ++i) {
        for (int j = i; j < M; ++j) {
            tmpS = 0;tmpMax = 0;
            for (int k = 1; k <= N; ++k) {//将第k列的第i行到第j行看作一维数组，转化为一维数组的子数组最大和
                if (tmpS < 0) {
                    tmpS = 0;
                }
                tmpS += arr[j][k] - arr[i-1][k];
                
                if (tmpMax < tmpS) {
                    tmpMax = tmpS;
                }
            }
            if (tmpMax > maxS) {
                maxS = tmpMax;
            }
        }
    }
    return maxS;
}

int main()
{
    srand((unsigned int)time(NULL));
    memset(arr, 0, sizeof(arr));
    for (int i = 1; i <= M; ++i) {
        for (int j = 1; j <= N; ++j) {
            arr[i][j] = rand() % 100 - 50;
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
    int res = getMaxSum(arr);
    printf("res = %d\n", res);
    return 0;
}