#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 10
/* 计算字符串之间的距离
author: zhanghao
email: zhangh2548@outlook.com
date:2020/09/22 13:34:26
*/

char str1[N], str2[N];
int dp[N][N];//记忆数组，dp[i][j]表示str1[i~end1]和str2[j~end2]的距离
int calculateStrDistance(char *str1, int begin1, int end1, char *str2, int begin2, int end2) {
    if (begin1 > end1) {
        if (begin2 > end2) {
            return 0;
        }else {
            return end2  - begin2 + 1;
        }
    }
    if (begin2 > end2) {
        if (begin1 > end1) {
            return 0;
        }else {
            return end1 - begin1 + 1;
        }
    }
    if (str1[begin1] == str2[begin2]) {
        if (dp[begin1][begin2] != -1)
            return dp[begin1][begin2];
        return dp[begin1][begin2] = calculateStrDistance(str1, begin1 + 1, end1, str2, begin2 + 1, end2);
    }else {
        int t1 = calculateStrDistance(str1, begin1 + 1, end1, str2, begin2, end2);
        int t2 = calculateStrDistance(str1, begin1, end1, str2, begin2 + 1, end2);
        int t3 = calculateStrDistance(str1, begin1 + 1, end1, str2, begin2 + 1, end2);
        return dp[begin1][begin2] = (t1 > (t2 > t3 ? t3 : t2) ?  (t2 > t3 ? t3 : t2) : t1) + 1;
    }
}

int main()
{
    
    scanf("%s", str1);
    scanf("%s", str2);
    memset(dp, -1, sizeof(dp));
    printf("len1 = %d, len2 = %d\n", strlen(str1), strlen(str2));
    int dis = calculateStrDistance(str1, 0, strlen(str1) - 1, str2, 0, strlen(str2) - 1);
    printf("The distance is %d\n", dis);
    return 0;
}