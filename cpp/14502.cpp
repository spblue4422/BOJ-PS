#include <algorithm>
#include <iostream>
#include <math.h>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

int bfs(int n, int m);

struct pnt {
    int x;
    int y;
};

vector<pnt> vec;
queue<pnt> que;
vector<pnt> backupQue;
int px[4] = {0, 0, -1, 1};
int py[4] = {-1, 1, 0, 0};
int board[10][10];
int backup[10][10];

int main() {
    int n = 0, m = 0, Max = 0;

    scanf("%d %d", &n, &m);

    fill(&board[0][0], &board[0][0] + 100, 9);
    fill(&backup[0][0], &backup[0][0] + 100, 9);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            //맵 원본
            scanf("%d", &board[i][j]);
            //맵 백업
            backup[i][j] = board[i][j];

            if (board[i][j] == 0) {
                // 0의 좌표 위치를 넣어둔 벡터
                vec.push_back({i, j});
            } else if (board[i][j] == 2) {
                // 바이러스 좌표 위치를 넣어둔 큐
                que.push({i, j});
                backupQue.push_back({i, j});
            }
        }
    }

    for (int i = 0; i < vec.size(); i++) {
        for (int j = i + 1; j < vec.size(); j++) {
            for (int k = j + 1; k < vec.size(); k++) {
                board[vec[i].x][vec[i].y] = 1;
                board[vec[j].x][vec[j].y] = 1;
                board[vec[k].x][vec[k].y] = 1;
                Max = max(Max, bfs(n, m));

                //원본 맵이 망가졌기 때문에 복구 해줘야함
                copy(&backup[0][0], &backup[0][0] + 100, &board[0][0]);
                for (int i = 0; i < backupQue.size(); i++) {

                    que.push(backupQue[i]);
                }
            }
        }
    }

    printf("%d", Max);

    return 0;
}

int bfs(int n, int m) {
    int qx = 0, qy = 0, count = 0;
    while (!que.empty()) {
        qx = que.front().x;
        qy = que.front().y;
        que.pop();

        //  바이러스의 상하좌우를 탐색해서 전염될수 있는 공간일 경우 푸쉬
        for (int i = 0; i < 4; i++) {
            if (qx + px[i] < 0 || qy + py[i] < 0 || qx + px[i] > 7 ||
                qy + py[i] > 7) {
                continue;
            } else if (board[qx + px[i]][qy + py[i]] == 0) {
                //방문 여부를 확인해줘야함
                que.push({qx + px[i], qy + py[i]});
                board[qx + px[i]][qy + py[i]] = 2;
                count++;
            }
        }
    }
    //바이러스 전염 끝
    // 안전공간 개수 리턴(0의 개수 - 새로 푸시된 2의 개수)
    return vec.size() - (count + 3);
}