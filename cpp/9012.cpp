#include <iostream>
#include <stack>
#include <stdio.h>

using namespace std;

int main() {
    stack<int> stk;
    int n = 0, tmp;

    scanf("%d", &n);

    char arr[n][52] = {0};

    for (int i = 0; i < n; i++) {
        tmp = 1;
        scanf("%s", arr[i]);
        for (int j = 0; arr[i][j]; j++) {
            if (arr[i][j] == '(') {
                stk.push(1);
            } else if (arr[i][j] == ')') {
                if (!stk.empty()) {
                    stk.pop();
                } else {
                    tmp = 0;
                    break;
                }
            }
        }
        if (!stk.empty() || tmp == 0) {
            printf("NO\n");
            while (stk.size()) {
                stk.pop();
            }
        } else {
            printf("YES\n");
        }
    }

    return 0;
}