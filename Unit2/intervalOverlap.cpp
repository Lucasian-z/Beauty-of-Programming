#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* 区间重合判断
author: zhanghao
email: zhangh2548@outlook.com
date: 2020/09/19 15:32:44
*/
struct Interval {//区间类
    int left, right;
    Interval() {}
    Interval(int a, int b): left(a), right(b) {}
};

bool cmp(Interval &a, Interval &b) {//按左端点进行排序
    return a.left < b.left || (a.left == b.left && a.right < b.right);
}

const int N = 5;
vector<Interval> ivec(N);

bool judge(Interval &A) {
    sort(ivec.begin(), ivec.end(), cmp);
    vector<Interval> ivecComb;//合并后的区间
    ivecComb.push_back(ivec[0]);
    for (int i = 1; i < ivec.size(); ++i) {
        if (ivec[i].left <= ivecComb.back().right) {
            if (ivec[i].right > ivecComb.back().right) {
                ivecComb.back().right = ivec[i].right;
            }
        }else {
            ivecComb.push_back(ivec[i]);
        }
    }
    for (auto &it : ivecComb) {
        printf("(%d, %d) ", it.left, it.right);
    }
    printf("\n");
    int left = 0, right = ivecComb.size(), mid;
    while (left < right) {//二分查找第一个>=目标区间左端点的区间
        mid = (left + right) >> 1;
        if (ivecComb[mid].left >= A.left) {
            right = mid;
        }else {
            left = mid + 1;
        }
    }
    if (left == ivecComb.size()) {
        return false;
    }else if (ivecComb[left].left == A.left) {
        return ivecComb[left].right >= A.right;
    }else if (left > 0 && ivecComb[left].left > A.left) {
        return A.left >= ivecComb[left - 1].left && A.right <= ivecComb[left - 1].right;
    }
    return false;
}

int main()
{
    for (int i = 0; i < N; ++i) {
        cin >> ivec[i].left >> ivec[i].right;
    }
    int a, b;
    cin >> a >> b;
    Interval A = Interval(a, b);
    bool res = judge(A);
    cout << boolalpha << res << endl;
    return 0;
}