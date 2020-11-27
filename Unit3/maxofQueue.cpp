#include <iostream>
#include <stack>
#include <ctime>
#include <algorithm>
using namespace std;

/* 双栈实现队列，并能以O(1)的复杂度返回最大值
author: zhanghao
email: zhangh2548@outlook.com
date: 2020/09/22 14:56:01
*/

template <typename T>
class Queue {
private:
    stack<T> sta1, sta2;
    stack<T> sta1Max, sta2Max;
public:
    void push(T value) {
        sta1.push(value);
        if (sta1Max.empty() || sta1Max.top() < value) {
            sta1Max.push(value);
        }
    }
    void pop() {
        if (sta2.empty()) {            
            while (!sta1.empty()) {
                sta2.push(sta1.top());
                if (sta2Max.empty() || sta1.top() > sta2Max.top()) {
                    sta2Max.push(sta1.top());
                }
                sta1.pop();
            }
            while (!sta1Max.empty()) {
                sta1Max.pop();
            }
        }
        if (sta2.top() == sta2Max.top()) {
            sta2Max.pop();
        } 
        sta2.pop();
    }
    T getMax() {
        T tmp1 = sta1Max.empty() ? INT_MIN : sta1Max.top();
        T tmp2 = sta2Max.empty() ? INT_MIN : sta2Max.top();
        return max(tmp1, tmp2);
    }
};

int main()
{
    srand((unsigned int)time(NULL));
    Queue<int> que;
    int N, num;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        num = rand() % 100;
        que.push(num);
        cout << num << " " << endl;
        
    }
    
    for (int i = 0; i < N; ++i) {        
        cout << "maxValue = " << que.getMax() << endl;que.pop();
    }
    return 0;
}