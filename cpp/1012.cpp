#include <algorithm>
#include <iostream>
#include <queue>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct xy {
    int x;
    int y;
};

int field[50][50] = {0};
xy direction[4] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int main() {
    int t, m, n, k, x, y, cnt = 0;
    xy tmp, dir;
    queue<xy> que;

    scanf("%d", &t);
    for (int tc = 0; tc < t; tc++) {
        cnt = 0;
        scanf("%d %d %d", &m, &n, &k);

        for (int i = 0; i < k; i++) {
            scanf("%d %d", &x, &y);
            field[x][y] = 1;
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (field[i][j] == 1) {
                    que.push({i, j});
                    field[i][j] = 0;
                    while (!que.empty()) {
                        tmp = que.front();
                        que.pop();
                        for (int v = 0; v < 4; v++) {
                            dir = direction[v];
                            if (tmp.x + dir.x >= 0 && tmp.x + dir.x < m && tmp.y + dir.y >= 0 && tmp.y + dir.y < n) {
                                if (field[tmp.x + dir.x][tmp.y + dir.y] == 1) {
                                    que.push({tmp.x + dir.x, tmp.y + dir.y});
                                    // pop할때 방문여부를 바꿔주면 큐에 동일한 정점이 매우 많이 들어갈 수 있기 때문에
                                    // push할 때 바꿔줘야한다.
                                    field[tmp.x + dir.x][tmp.y + dir.y] = 0;
                                }
                            }
                        }
                    }
                    cnt++;
                }
            }
        }
        printf("%d\n", cnt);
    }

    return 0;
}