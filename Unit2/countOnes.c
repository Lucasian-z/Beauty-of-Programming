#include <stdio.h>
#include <stdlib.h>

/* 给定数字N,计算从1到N的十进制数中1出现的个数
author: zhanghao
email: zhangh2548@outlook.com
date:2020/09/18 09:22:20
*/


int count1(int N) {
    int cnt = 0;
    int fac = 1;

    int up = 0, cur = 0, low = 0;
    while (N / fac) {
        up = N / (fac * 10);
        cur = N / fac % 10;
        low = N - (N / fac) * fac;

        switch (cur)
        {
        case 0://当前数字为0，则当前数字为1的个数由高位数字决定
            cnt += up * fac;
            break;//当前数字为1，则当前数字为1的个数由高位和低位数字共同影响
        case 1:
            cnt += up * fac + low + 1;
            break;
        default://当前数字大于1，则当前数字为1的个数由高位数字决定
            cnt += (up + 1) * fac;
            break;
        }
        fac *=  10;
    }
    return cnt;
}

int main()
{
    int N;
    scanf("%d", &N);
    int res = count1(N);
    printf("res = %d\n", res);
    return 0;
}