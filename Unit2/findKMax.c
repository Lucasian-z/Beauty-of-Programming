#include <stdio.h>
#include <stdlib.h>


/*
author: zhanghao
email: zhangh2548@outlook.com
date:2020/09/18 10:32:07
*/


//利用快速排序partition将数组划分为两段，前段比选定值大，后段比选定值小
int partition(int arr[], int st, int ed) {//前部分比选定值大，后部分比选定值小
    int tmp = arr[st];
    while (st < ed) {
        while (st < ed && arr[ed] < tmp) {
            --ed;
        } 
        if (st < ed) {
            arr[st] = arr[ed];
            ++st;
        }
        while (st < ed && arr[st] >= tmp) {
            ++st;
        }
        if (st < ed) {
            arr[ed] = arr[st];
            --ed;
        }
    }
    arr[st] = tmp;
    return st;
}

int findKMax(int arr[], int left, int right, int k) {    
    int res = -1;//满足条件的最大下标
    if (left <= right) {
        int parti = partition(arr, left, right);
        int len = parti - left + 1;
        if (len == k) {//正好满足条件
            res = parti;
        }else if (len > k) {//前部分个数大于k
            res = findKMax(arr, left, parti - 1, k);
        }else {//后部分个数小于k
            res = findKMax(arr, parti + 1, right, k - len);
        }
    }
    return res;
}

//二分法
int countGreater(int arr[], int n, int value) {
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] >= value) {
            ++cnt;
        }
    }
    return cnt;
}
int solve(int arr[], int n, int Min, int Max, int k) {
    int mid, cnt;
    while (Min < Max) {
        mid = (Min + Max) / 2;
        cnt = countGreater(arr, n, mid);
        if (cnt > k) {
            Min = mid + 1;
        }else {
            Max = mid;
        }
    }
    return Min;
}

//最大堆
void downAdjust(int arr[], int low, int high) {
    int i = low, j = 2 * i + 1;
    while (j <= high) {
        if (j < high && arr[j] < arr[j + 1]) ++j;
        if (arr[j] > arr[i]) {
            int tmp = arr[j];
            arr[j] = arr[i];
            arr[i] = tmp;
            i = j;
            j = 2 * i + 1;
        }else {
            break;
        }
    }
}
void heapSort(int arr[], int n, int k) {
    for (int i = n / 2 - 1; i >= 0; --i) {
        downAdjust(arr, i, n - 1);
    }
    for (int i = 0; i < k; ++i) {
        int tmp = arr[0];
        arr[0] = arr[n - 1];
        arr[--n] = tmp;
        printf("%d ", arr[n]);
        downAdjust(arr, 0, n - 1);
    }
}

int main()
{
    int arr[] = {2,3,5,7653,23,2,4,34,2,3,4,5999,6,8,8,7};
    // int idx = findKMax(arr, 0, 15, 3);
    // for (int i = 0; i <= idx; ++i) {
    //     printf("%d ", arr[i]);
    // }
    // int ans = solve(arr, 16, 2, 7653, 3);
    // printf("ans = %d\n", ans);
    heapSort(arr, 16, 3);
    return 0;
}