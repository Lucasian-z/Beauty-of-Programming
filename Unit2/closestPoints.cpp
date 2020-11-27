#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <algorithm>
using namespace std;

/*利用分治法求二维平面上最近的点对，时间复杂度为O(N*log(N))
author: zhanghao
email: zhangh2548@outlook.com
date: 2020/09/18 20:16:43
*/
class Point {
public:
    int m_x, m_y;
};

bool cmp_x(Point &x, Point &y) {
    if (x.m_x != y.m_x) {
        return x.m_x < y.m_x;
    }
    return x.m_y < y.m_y;
}
bool cmp_y(Point &x, Point &y) {
    return x.m_y < y.m_y;
}
#define N 20
vector<Point> pt(N);
Point A, B;

double getDis(Point &a, Point &b) {
    return sqrt((a.m_x - b.m_x) * (a.m_x - b.m_x) + (a.m_y - b.m_y) * (a.m_y - b.m_y));
}


vector<Point> tmp(N);
double cal(int left, int right) {
    double d = 1000000;
    if (left == right) {
        return d;
    }
    if (left + 1 == right) {
        A = pt[left], B = pt[right];
        return getDis(pt[left], pt[right]);
    }
    int mid = (left + right) >> 1;
    double minDisL = cal(left, mid);//前半段的最小距离
    Point A1 = A, B1 = B;//距离最近的两个点
    double minDisR = cal(mid + 1, right);//后半段的最小距离，此时A，B已被更新为后半段中的两点
    if (minDisL < minDisR) {//若前半段最小距离小于后半段最小距离，更新A，B，d
        A = A1;
        B = B1;
        d = minDisL;
    }else {//否则仅更新d
        d = minDisR;
    }
    int k = 0;
    for (int i = left; i <= right; ++i) {//将离选定点的水平距离小于d加入临时数组
        if (fabs(pt[i].m_x - pt[mid].m_x) <= d) {
            tmp[k++] = pt[i];
        }
    }
    sort(tmp.begin(), tmp.begin() + k, cmp_y);
    for (int i = 0; i < k; ++i) {//求出tmp中相距最近的两点
        for (int j = i + 1; j < k && tmp[j].m_y - tmp[i].m_y < d; ++j) {
            double d1 = getDis(tmp[i], tmp[j]);
            if (d > d1) {
                d = d1;
                A = tmp[i];
                B = tmp[j];
            }
        }
    }
    return d;
}

int main()
{
    srand((unsigned int)time(NULL));
    for (int i = 0; i < N; ++i) {
        pt[i].m_x = rand() % 100 - 5;
        pt[i].m_y = rand() % 100 - 5;
    }
    sort(pt.begin(), pt.end(), cmp_x);
    for (auto &it : pt) {
        printf("(%d, %d) ", it.m_x, it.m_y);
    }
    printf("\n");
    double miniDis = cal(0, N - 1);
    printf("The mini distance is %.4lf of (%d, %d) and (%d, %d)\n", miniDis, A.m_x, A.m_y, B.m_x, B.m_y);
    return 0;
}