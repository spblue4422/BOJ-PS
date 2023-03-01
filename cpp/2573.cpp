#include <iostream>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

void calcIce(int x, int y);

int ocean[300][300] = {0};
int visited[300][300] = {0};

struct glac {
    int height, x, y;
};

queue<glac> que;

// bfs�? ?��?��?��?�� ?��.
// 코드 개선?�� ?���?�? ?��?��?�� 많을�? 같�???��
int main() {
    int N, M, dx, dy, tmp = 0, year = 0;
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &ocean[i][j]);
        }
    }

    // 최초 ?��?��. 빙하�? ?��?�� 집어?��?��.
    while (true) {
        for (int i = 1; i < N - 1; i++) {
            for (int j = 1; j < M - 1; j++) {
                if (ocean[i][j] && !visited[i][j]) {
                    // 최초 ?��?��?���? 방문?���? 바꾸�?
                    que.push({ocean[i][j], i, j});
                    visited[i][j] = 1;
                    // ?���? 빌때까�?? ?��?��.
                    while (!que.empty()) {
                        dx = que.front().x;
                        dy = que.front().y;
                        que.pop();
                        calcIce(dx, dy);
                    }
                    // ?���? 비어?�� ?��?��?�� ?��?��?��?��, tmp 증�??
                    //  tmp?�� ?��?��??? 빙산?�� ?��강났?���?�? ?��?��
                    //  tmp�? 1보다 ?��?���? ?��강나?�� ?���? ?���? ?��?��?��?�� ?��
                    //  tmp�? 0?��?���? ?��?��?�� 모두 ?��?��?��?�� ?��
                    tmp++;
                }
                // tmp�? 1?�� ?��?��?���? ?��로그?��?�� 계속?�� ?��?���? ?��?���?�? break
                if (tmp != 1) {
                    break;
                }
            }
            if (tmp != 1) {
                break;
            }
        }
        if (tmp > 1) {
            break;
        } else if (tmp == 0) {
            // tmp�? 0?��?��?��, 출력?�� 0?���?
            year = 0;
            break;
        }
        year++;

        // 방문?�� ?��?�� 배열 초기?��
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                visited[i][j] = 0;
            }
        }
        tmp = 0;
    }

    printf("%d", year);

    return 0;
}

// ocean 배열 조정 ?��?��
void calcIce(int x, int y) {
    int cnt = 0;
    // 방문 ?���?�? 먼�?? ?��?��.
    // 방문?���? ?��?��?���? 바다?���? 빙산?���? ?��?��?�� cnt 조정
    // 방문?���??�� 기�????? ?��?�� ?��?�� ?���?
    if (!visited[x - 1][y]) {
        if (ocean[x - 1][y]) {
            que.push({ocean[x - 1][y], x - 1, y});
            visited[x - 1][y] = 1;
        } else {
            cnt++;
        }
    }
    if (!visited[x + 1][y]) {
        if (ocean[x + 1][y]) {
            que.push({ocean[x + 1][y], x + 1, y});
            visited[x + 1][y] = 1;
        } else {
            cnt++;
        }
    }
    if (!visited[x][y - 1]) {
        if (ocean[x][y - 1]) {
            que.push({ocean[x][y - 1], x, y - 1});
            visited[x][y - 1] = 1;
        } else {
            cnt++;
        }
    }
    if (!visited[x][y + 1]) {
        if (ocean[x][y + 1]) {
            que.push({ocean[x][y + 1], x, y + 1});
            visited[x][y + 1] = 1;
        } else {
            cnt++;
        }
    }

    ocean[x][y] = ocean[x][y] - cnt > 0 ? ocean[x][y] - cnt : 0;
}