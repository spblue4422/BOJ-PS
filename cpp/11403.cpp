#include <algorithm>
#include <iostream>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;

void bfs(int n);

// 입력받는 인접행렬
vector<int> adjlist[100];
// 출력할 인접행렬
vector<int> result[100];
// bfs용
queue<int> que;
// 순회여부 확인배열
int already[100] = {0};

int main() {
    int N = 0, ed;

    // 입력
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &ed);
            adjlist[i].push_back(ed);
        }
    }

    // bfs 순회
    for (int i = 0; i < N; i++) {
        bfs(i);

        for (int j = 0; j < N; j++) {
            result[i].push_back(already[j]);
        }

        fill(already, already + 100, 0);
    }

    // 출력
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}

// bfs
// 처음에는 pop 직전에 순회여부를 찍었지만, 자기 노드가 무조건 찍히는 문제 발생
// push 하면서 찍는걸로 변경
void bfs(int n) {
    que.push(n);
    while (!que.empty()) {
        int k = que.front();
        que.pop();
        for (int i = 0; i < adjlist[k].size(); i++) {
            if (adjlist[k][i] == 1 && already[i] != 1) {
                que.push(i);
                already[i] = 1;
            }
        }
    }

    return;
}