#include <iostream>
#include <math.h>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;

int sixLevel(int idx);

struct ints {
    int idx, lev;
};

vector<int> vec[101];
int N;

int main() {
    int M, tmp1, tmp2, m = 1000000, t;
    // int arr[101] = {0};

    scanf("%d %d", &N, &M);

    for (int i = 0; i < M; i++) {
        scanf("%d %d", &tmp1, &tmp2);
        vec[tmp1].push_back(tmp2);
        vec[tmp2].push_back(tmp1);
    }

    for (int i = 1; i <= N; i++) {
        // arr[i] = sixLevel(i);
        if (m > sixLevel(i)) {
            m = sixLevel(i);
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
            if (!visited[vec[k][i]]) { //주석 작성하장
                que.push({vec[k][i], l + 1});
                visited[vec[k][i]] = 1;
            }
        }
    }

    return sum;
}