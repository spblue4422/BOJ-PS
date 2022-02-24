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

// bfs를 사용해서 품.
// 코드 개선의 여지가 상당히 많을것 같은데
int main() {
    int N, M, dx, dy, tmp = 0, year = 0;
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &ocean[i][j]);
        }
    }

    //최초 세팅. 빙하를 큐에 집어넣음.
    while (true) {
        for (int i = 1; i < N - 1; i++) {
            for (int j = 1; j < M - 1; j++) {
                if (ocean[i][j] && !visited[i][j]) {
                    //최초 푸쉬하고 방문여부 바꾸기
                    que.push({ocean[i][j], i, j});
                    visited[i][j] = 1;
                    //큐가 빌때까지 탐색.
                    while (!que.empty()) {
                        dx = que.front().x;
                        dy = que.front().y;
                        que.pop();
                        calcIce(dx, dy);
                    }
                    //큐가 비어서 탐색이 끝났을때, tmp 증가
                    // tmp의 역할은 빙산이 동강났는지를 판단
                    // tmp가 1보다 크다면 동강나서 큐가 두번 돌았다는 뜻
                    // tmp가 0이라면 얼음이 모두 녹았다는 뜻
                    tmp++;
                }
                // tmp가 1이 아니라면 프로그램을 계속할 이유가 없으므로 break
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
            // tmp가 0일때는, 출력을 0으로
            year = 0;
            break;
        }
        year++;

        //방문한 얼음 배열 초기화
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

// ocean 배열 조정 함수
void calcIce(int x, int y) {
    int cnt = 0;
    //방문 여부를 먼저 판단.
    //방문하지 않았다면 바다인지 빙산인지 판단후 cnt 조정
    //방문여부의 기준은 큐의 푸쉬 여부
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