#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* 判断某点是否在给定三角形之内
author: zhanghao
email: zhangh2548@outlook.com
date:2020/09/23 11:14:54
*/
typedef struct {
    double x, y;
}Point;
double getDis(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
double getArea(Point A, Point B, Point C) {
    double len1 = getDis(A, B), len2 = getDis(A, C), len3 = getDis(B, C);
    double p = (len1 + len2 + len3) / 2;
    return sqrt((p - len1) * (p - len2) * (p - len3) * p);//海伦公式
}
int judge1(Point A, Point B, Point C, Point D) {
    return (getArea(A, B, D) + getArea(B, C, D) + getArea(C, A, D)) <= getArea(A, B, C);
}


//向量叉积
double product(Point A, Point B, Point C) {
    return (B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x);
}
int judge2(Point A, Point B, Point C, Point D) {
    return (product(A, B, D) >= 0 && product(B, C, D) >= 0 && product(C, A, D) >= 0);
}


int main()
{
    Point A, B, C, D;
    scanf("%lf %lf %f %lf %lf %lf %f %lf", &A.x, &A.y, &B.x, &B.y, &C.x, &C.y, &D.x, &D.y);
    printf("res1 = %d\n", judge1(A, B, C, D));
    printf("res2 = %d\n", judge2(A, B, C, D));
    return 0;
}