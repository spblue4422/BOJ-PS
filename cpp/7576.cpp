#include <iostream>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct tmt {
    int x, y;
};

int bfs(queue<tmt> Q, int m, int n);

int arr[1000][1000];

int main() {

    int m, n, flag = 0, cnt = 0;
    queue<tmt> Q;

    scanf("%d %d", &m, &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &arr[i][j]);
            if (arr[i][j] == 1) {
                Q.push({i, j});
            } else if (arr[i][j] == 0) {
                flag = 1;
            }
        }
    }
    if (flag == 0) {
        printf("0");
        return 0;
    }

    cnt = bfs(Q, m, n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 0) {
                printf("-1");
                return 0;
            }
        }
    }

    printf("%d", cnt);

    return 0;
}

int bfs(queue<tmt> Q, int m, int n) {
    int days = 0, cnt = 0, x, y;

    while (!Q.empty()) {
        cnt = Q.size();
        for (int i = 0; i < cnt; i++) {
            x = Q.front().x;
            y = Q.front().y;
            Q.pop();
            if (x > 0 && arr[x - 1][y] == 0) {
                arr[x - 1][y] = 1;
                Q.push({x - 1, y});
            }
            if (x < n - 1 && arr[x + 1][y] == 0) {
                arr[x + 1][y] = 1;
                Q.push({x + 1, y});
            }
            if (y > 0 && arr[x][y - 1] == 0) {
                arr[x][y - 1] = 1;
                Q.push({x, y - 1});
            }
            if (y < m - 1 && arr[x][y + 1] == 0) {
                arr[x][y + 1] = 1;
                Q.push({x, y + 1});
            }
        }
        if (!Q.empty()) {
            days++;
        }
    }

    return days;

    return 0;
}