#include <iostream>
#include <math.h>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main() {
    int n = 0;
    long long *ptr;
    long long height = 0, topW = 0, f = 0, tmp = 0, M = 0;
    stack<long long *> stk;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%lld", &height);
        ptr = new long long[2]{i + 1, height};
        if (stk.empty()) {
            stk.push(ptr);
            continue;
        }

        if (stk.top()[1] <= height) {
            ptr = new long long[2]{i + 1, height};
            stk.push(ptr);
        } else {
            topW = stk.top()[0];
            while (!stk.empty() && stk.top()[1] > height) {
                tmp = stk.top()[1];
                stk.pop();
                f = stk.empty() ? 0 : stk.top()[0];
                M = max((topW - f) * tmp, M);
            }
            ptr = new long long[2]{i + 1, height};
            stk.push(ptr);
        }
    }

    topW = stk.top()[0];
    while (!stk.empty()) {
        tmp = stk.top()[1];
        stk.pop();
        f = stk.empty() ? 0 : stk.top()[0];
        M = max((topW - f) * tmp, M);
    }

    printf("%lld", M);

    return 0;
}