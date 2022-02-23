#include <iostream>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int visited[1000001] = {0};

int main() {
    int F, S, G, U, D;
    queue<int> que;
    scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);

    que.push(S);
    visited[S] = 1;

    while (!que.empty()) {
        int tmp = que.front();
        que.pop();

        if (tmp + U <= F && !visited[tmp + U]) {
            que.push(tmp + U);
            visited[tmp + U] = visited[tmp] + 1;
        }
        if (tmp - D > 0 && !visited[tmp - D]) {
            que.push(tmp - D);
            visited[tmp - D] = visited[tmp] + 1;
        }
    }

    if (!visited[G]) {
        printf("use the stairs");
    } else {
        printf("%d", visited[G] - 1);
    }

    return 0;
}