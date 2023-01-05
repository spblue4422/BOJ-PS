#include <iostream>
#include <math.h>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;

int sixLevel(int idx);

struct ints {
    //번호, 도달 단계
    int idx, lev;
};

vector<int> vec[101];
int N;

int main() {
    int M, tmp1, tmp2, m = 1000000, t, sL;

    scanf("%d %d", &N, &M);

    //양방향 인접리스트 만들기
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &tmp1, &tmp2);
        vec[tmp1].push_back(tmp2);
        vec[tmp2].push_back(tmp1);
    }

    for (int i = 1; i <= N; i++) {
        sL = sixLevel(i);
        if (m > sL) {
            //최솟값
            m = sL;
            //최소 베이컨 수를 가지는 번호
            t = i;
        }
    }

    printf("%d", t);

    return 0;
}

int sixLevel(int idx) {
    int visited[101] = {0};
    int k, l, sum = 0;

    queue<ints> que;

    que.push({idx, 0});
    visited[idx] = 1;

    while (!que.empty()) {
        k = que.front().idx;
        l = que.front().lev;
        que.pop();
        sum += l;
        for (int i = 0; i < vec[k].size(); i++) {
            // vec[k][i]: 연결되어 있는 번호
            //해당 번호 방문 여부 체크
            if (!visited[vec[k][i]]) {
                //방문 안했다면 큐에 푸쉬
                que.push({vec[k][i], l + 1});
                visited[vec[k][i]] = 1;
            }
        }
    }

    return sum;
}