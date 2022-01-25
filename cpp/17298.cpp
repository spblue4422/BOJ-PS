#include <algorithm>
#include <iostream>
#include <stack>
#include <stdio.h>
using namespace std;

int input[1000000] = {0};
int output[1000000] = {0};

int main() {
    stack<int *> stk;
    int n = 0;
    int chk = 0;
    int *ptr;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &input[i]);
    }
    for (int i = 0; i < n; i++) {
        if (stk.empty()) {
            ptr = new int[2]{i, input[i]};
            stk.push(ptr);
        } else {
            if (stk.top()[1] >= input[i]) {
                ptr = new int[2]{i, input[i]};
                stk.push(ptr);
            } else {
                //스택이 비어있지 않으면서 스택의 top보다 큰수일 때,
                while (!stk.empty() && stk.top()[1] < input[i]) {
                    chk = stk.top()[0];
                    output[chk] = input[i];
                    stk.pop();
                }
                //다 뽑아낸 후,
                ptr = new int[2]{i, input[i]};
                stk.push(ptr);
            }
        }
    }
    while (!stk.empty()) {
        chk = stk.top()[0];
        output[chk] = -1;
        stk.pop();
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", output[i]);
    }

    return 0;
}