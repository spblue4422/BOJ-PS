#include <iostream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int hArr[500000] = {0};

int main() {
    int n = 0;
    long long height = 0;
    long long *ptr;
    stack<long long *> stk;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%lld", &height);
        ptr = new long long[2]{i + 1, height};

        if (stk.empty()) {
            stk.push(ptr);
            continue;
        }

        //새로 받는 노드가 더 작거나 같으면 푸쉬
        if (stk.top()[1] >= height) {
            stk.push(ptr);
        } else { // 더 크면 작거나 같을때까지 팝하고 푸쉬
            while (!stk.empty() && stk.top()[1] < height) {
                int k = stk.top()[0];
                stk.pop();
                if (stk.empty()) {
                    hArr[k - 1] = 0;
                } else {
                    hArr[k - 1] = stk.top()[0];
                }
            }
            stk.push(ptr);
        }
    }
    while (!stk.empty()) {
        int k = stk.top()[0];
        stk.pop();
        if (stk.empty()) {
            hArr[k - 1] = 0;
        } else {
            hArr[k - 1] = stk.top()[0];
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%lld ", hArr[i]);
    }

    return 0;
}