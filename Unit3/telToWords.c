#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define N 20
/* 打印电话号码对应的所有单词
author: zhanghao
email: zhangh2548@outlook.com
date:2020/09/21 13:21:33
*/

char c[10][N] = {" ", " ", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};
int tel[N];//电话号码
int len[N] = {0};//每一轮各位号码对应的字母位置
int telLen;

void solve(int idx) {
    if (telLen == idx) {
        for (int i = 0; i < telLen; ++i) {
            printf("%c", c[tel[i]][len[i]]);
        }
        printf("\n");
        return;
    }
    for (len[idx] = 0; len[idx] < strlen(c[tel[idx]]); ++len[idx]) {
        solve(idx + 1);
    }
}

int main()
{
    scanf("%d", &telLen);
    for (int i = 0; i < telLen; ++i) {
        scanf("%d", &tel[i]);
    }
    solve(0);
    
    
    return 0;
}