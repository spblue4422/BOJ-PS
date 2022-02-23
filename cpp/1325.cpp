#include <iostream>
#include <math.h>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;

vector<int> graph[10001];
vector<int> hacked;
vector<int> visited;
queue<int> que;

int main() {
    int N, M, A, B, cnt, Ma = 0;
    scanf("%d %d", &N, &M);

    hacked = vector<int>(N + 1, 0);

    for (int i = 0; i < M; i++) {
        scanf("%d %d", &A, &B);
        graph[B].push_back(A);
    }

    for (int i = 1; i <= N; i++) {
        visited = vector<int>(N + 1, 0);
        que.push(i);
        visited[i] = 1;

        while (!que.empty()) {
            int tmp = que.front();
            que.pop();
            cnt++;
            for (int j = 0; j < graph[tmp].size(); j++) {
                int k = graph[tmp][j];
                if (visited[k] != 0) {
                    continue;
                }
                que.push(k);
                visited[graph[tmp][j]] = 1;
            }
        }
        hacked[i] = cnt;
        Ma = max(Ma, cnt);
        cnt = 0;
    }

    for (int i = 1; i <= N; i++) {
        if (Ma == hacked[i]) {
            printf("%d ", i);
        }
    }

    return 0;
}