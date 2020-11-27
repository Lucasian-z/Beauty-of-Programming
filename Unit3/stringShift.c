#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100
/*字符串循环移位
author: zhanghao
email: zhangh2548@outlook.com
date:2020/09/21 12:42:38
*/
char str1[N];
char str2[N];
char str3[N];

//将str1复制两份
int judge1() {
    printf("str1 = %s\n", str1);
    printf("str2 = %s\n", str2);
    strcpy(str3, str1);
    strcpy(str3 + strlen(str1), str1);
    printf("%s\n", str3);
    return strstr(str3, str2) != NULL;
}

//虚拟拼接
int judge2() {
    int len1 = strlen(str1), len2 = strlen(str2);
    for (int i = 0; i < len1; ++i) {
        if (str1[i] == str2[0]) {
            int flag = 1;
            for (int j = 1; j < len2; ++j) {
                if (str2[j] != str1[(i+j) % len1]) {//(i+j)%len代表在str1循环游走
                    flag = 0;
                    break;
                }
            }
            if (flag) {
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    scanf("%s", str1);
    scanf("%s", str2);
    if (judge1()) {
        printf("Yes\n");
    }else {
        printf("No\n");
    }
    if (judge2()) {
        printf("Yes\n");
    }else {
        printf("No\n");
    }
    return 0;
}