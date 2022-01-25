#include <iostream>
#include <stack>
#include <stdio.h>

using namespace std;

int main() {
    stack<int> stk;
    int n = 0, tmp = 0;
    long long sum = 0;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &tmp);
        if (!tmp) {
            stk.pop();
        } else {
            stk.push(tmp);
        }
    }

    while (stk.size()) {
        sum += stk.top();
        stk.pop();
    }

    printf("%lld", sum);

    return 0;
}