#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 判断三角形的类型
author: zhanghao
email: zhangh2548@outlook.com
date:2020/09/24 11:15:59
*/
// 7           6           5           4           3           2           1           0
// 标志位      \           \           直角        锐角        钝角         等边        等腰
char strs[8][10] = {"等腰", "等边", "钝角", "锐角", "直角", "", "", "三角形"};
void print(int typeN) {
    
    if (typeN == 0) {
        printf("非三角形");
        return;
    }
    for (int i = 0; i <= 7; ++i) {
        if ((typeN >> i) & 1) {
            printf("%s", strs[i]);
        }
    }
    printf("\n");
}

int judge(int a, int b, int c) {
    int res = 0;
    if (b > c) {//使a <= b <= c
        b = b ^ c;
        c = b ^ c;
        b = b ^ c;
    }
    if (a > c) {
        a ^= c;
        c ^= a;
        a ^= c;
    }
    if (a > b) {
        a ^= b;
        b ^= a;
        a ^= b;
    }
    printf("a = %d, b = %d, c = %d\n", a, b, c);
    if (a + b > c) {
        res |= 1 << 7;
        if (a*a + b*b == c*c) {
            res |= 1 << 4;
        }else if (a*a + b*b < c*c) {
            res |= 1 << 2;
        }else {
            res |= 1 << 3;
        }
        if (a == c) {
            res |= 1 << 1;
            res ^= 1 << 3;
        }else {
            if (a == b || b == c) {
                res |= 1;
            }
        }
    }
    return res;
}

int main()
{
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    int res = judge(a, b, c);
    print(res);
    return 0;
}