#include <iostream>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

int main() {
    int n, k;
    char cmd[10] = {0};
    queue<int> Q;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s", cmd);
        if (!(strcmp(cmd, "push"))) {
            scanf("%d", &k);
            Q.push(k);
        } else if (!strcmp(cmd, "pop")) {
            if (Q.empty()) {
                printf("-1\n");
            } else {
                printf("%d\n", Q.front());
                Q.pop();
            }
        } else if (!strcmp(cmd, "size")) {
            printf("%d\n", Q.size());
        } else if (!strcmp(cmd, "empty")) {
            printf("%d\n", Q.empty());
        } else if (!strcmp(cmd, "front")) {
            if (Q.empty()) {
                printf("-1\n");
            } else {
                printf("%d\n", Q.front());
            }
        } else if (!strcmp(cmd, "back")) {
            if (Q.empty()) {
                printf("-1\n");
            } else {
                printf("%d\n", Q.back());
            }
        }
    }

    return 0;
}