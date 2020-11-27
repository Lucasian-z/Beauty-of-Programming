#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    while (1) {
        for (int i = 0; i < 19600000; ++i);
        _sleep(10);
    }
    return 0;
}