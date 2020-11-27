#include <stdio.h>
#include <stdlib.h>

/*找出给定元素中超过半数的元素
author: zhanghao
email: zhangh2548@outlook.com
date:2020/09/16/ 21:05:51
*/
#define N 10
int arr1[N] = {0, 1, 2, 3, 5, 5, 5, 5, 5, 5};

int mooreVote() {
    int candidate;
    for (int i = 0, cnt = 0; i < N; ++i) {
        if (cnt == 0) {
            candidate = arr1[i];
            cnt = 1;
        }else {
            if (candidate == arr1[i]) {
                ++cnt;
            }else {
                --cnt;
            }
        }        
    }
    return candidate;
}

//假设有3个元素的个数都超过总元素个数的1/4
int arr2[N] = {1,2,2,2,3,3,3,4,4,4};
int res[3] = {0}, cnt[3] = {0};
void solve() {
    
    for (int i = 0; i < N; ++i) {
        int flag = 0;
        for (int j = 0; j < 3; ++j) {
            if (cnt[j] == 0) {
                res[j] = arr2[i];
                cnt[j] = 1;
                flag = 1;
                break;
            }else if (res[j] == arr2[i]) {
                ++cnt[j];
                flag = 1;
                break;
            }else {
                if (j == 2 && arr2[i] != res[j]) {
                    flag = 0;
                    break;
                }
            }
            
        }
        if (flag == 0) {
            for (int j = 0; j < 3; ++j) {
                --cnt[j];
            }
        }
    }
}

//求出给定元素中最多的前k个元素
#define k 5
int arr3[20] = {4,2,2,2,3,3,4,4,5,35,35,35,36,3,3,67,5,5,5,5};
int ans[k], num[k];
void solve2() {
    for (int i = 0; i < 20; ++i) {
        int flag = 0;
        for (int j = 0; j < k; ++j) {
            if (num[j] == 0) {
                num[j] = 1;
                ans[j] = arr3[i];
                flag = 1;
                break;
            }else if (arr3[i] == ans[j]) {
                ++num[j];
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            for (int j = 0; j < k; ++j) {
                --num[j];
            }
        }
    }
}

int main()
{
    // int candidate = mooreVote();
    // printf("res = %d\n", candidate);
    // solve();
    // for (int i = 0; i < 3; ++i) {
    //     printf("%d\n", res[i]);
    // }
    solve2();
    for (int i = 0; i < k; ++i) {
        printf("%d\n", ans[i]);
    }
    return 0;
}