#include <iostream>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

char arr[101][101] = {0};
long long visited[101][101] = {0};

struct dxdy {
    int x, y;
};

//최단거리 => bfs이용하자
int main() {
    int N, M, dx, dy;
    queue<dxdy> que;
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++) {
        scanf("%s", &arr[i]);
    }

    que.push({0, 0});
    visited[0][0] = 1;

    while (!que.empty()) {
        dx = que.front().x;
        dy = que.front().y;
        que.pop();

        if (dx + 1 < N && !visited[dx + 1][dy] && arr[dx + 1][dy] == '1') {
            que.push({dx + 1, dy});
            visited[dx + 1][dy] = visited[dx][dy] + 1;
        }
        if (dy + 1 < M && !visited[dx][dy + 1] && arr[dx][dy + 1] == '1') {
            que.push({dx, dy + 1});
            visited[dx][dy + 1] = visited[dx][dy] + 1;
        }
        if (dx - 1 < N && !visited[dx - 1][dy] && arr[dx - 1][dy] == '1') {
            que.push({dx - 1, dy});
            visited[dx - 1][dy] = visited[dx][dy] + 1;
        }
        if (dy - 1 < M && !visited[dx][dy - 1] && arr[dx][dy - 1] == '1') {
            que.push({dx, dy - 1});
            visited[dx][dy - 1] = visited[dx][dy] + 1;
        }

        if (visited[N - 1][M - 1]) {
            break;
        }
    }

    printf("%lld", visited[N - 1][M - 1]);

    return 0;
}