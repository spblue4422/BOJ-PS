#include <iostream>
#include <list>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

struct input {
    // flag가 1이면 right, 0이면 left
    int order, time, flag;
};

int main() {
    int m, t, n, tmp, time = 0, flag = 0, cnt = 0;
    int passenger[100001] = {0};
    char str[6];
    list<input> inputList;
    list<input>::iterator iter;
    queue<input> que;

    // 입력이 시간순서대로 주어질까...?
    scanf("%d %d %d", &m, &t, &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %s", &tmp, str);
        if (strcmp(str, "left") == 0) {
            inputList.push_back({i + 1, tmp, 0});
        } else {
            inputList.push_back({i + 1, tmp, 1});
        }
    }

    iter = inputList.begin();

    while (!inputList.empty() || !que.empty()) {
        //기다리는 승객이 없을때, 시간이 승객이 도착하는 시간보다 작을 때
        if (que.empty() && iter != inputList.end() && (*iter).time > time) {
            time = (*iter).time;
        }
        //현재 시간보다 일찍 도착한 승객들을 리스트에서 제거, 큐에 푸쉬
        while (iter != inputList.end() && (*iter).time <= time) {
            que.push(*iter);
            iter = inputList.erase(iter);
        }
        //큐에 푸쉬된 승객들 확인
        //같은 쪽에 있는 승객들 태우고
        //반대편의 승객들은 다시 큐에 푸쉬
        for (int i = 0, siz = que.size(); i < siz; i++) {
            //큐를 확인
            // 1. 같은쪽에 있는 승객인가
            // 2. 배에 탑승해 있는 승객의 수가 m보다 작은가
            if (que.front().flag == flag && cnt < m) {
                int tmp = que.front().order;
                passenger[tmp] = time + t;
                que.pop();
                cnt += 1;
            } else {
                que.push(que.front());
                que.pop();
            }
        }
        time += t;
        cnt = 0;
        flag = flag ? 0 : 1;
    }

    for (int i = 1; i <= n; i++) {
        printf("%d\n", passenger[i]);
    }

    return 0;
}