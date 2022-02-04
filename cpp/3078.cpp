#include <iostream>
#include <list>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

struct fr {
    int rank, length;
};

int main() {
    int n, k, rnk, len;
    long long cnt = 0;
    char nameArr[21] = {0};
    queue<fr> Q;
    list<fr> L;
    list<fr>::iterator iter;

    scanf("%d %d", &n, &k);
    //학생 순서랑 이름 길이 저장
    for (int i = 0; i < n; i++) {
        scanf("%s", nameArr);
        L.push_back({i + 1, (int)strlen(nameArr)});
    }

    // iter = L.begin();

    while (!L.empty()) {
        //탐색 주기의 시작
        iter = L.begin();
        rnk = L.front().rank;
        len = L.front().length;

        while (iter != L.end()) {
            //조건에 부합하면 Q에 밀어넣고 리스트에서 삭제
            //그렇지 않으면 그냥 포인터만 넘김.
            if ((*iter).length == len) {
                while ((*iter).rank - rnk > k) {
                    Q.pop();
                    cnt += Q.size();
                    // Q가 비어있다면 Q.front()에서 segmentation fault가
                    //나올 수 있으므로, 비어있는지 확인하고 넣어줘야함.
                    rnk = Q.empty() ? (*iter).rank : Q.front().rank;
                }
                Q.push(*iter);
                iter = L.erase(iter);
            } else {
                iter++;
            }
        }

        //포인터가 리스트의 끝에 도달했을때
        //리스트가 비어있지 않다면, 다시 처음으로 돌아가 시작
        while (!Q.empty()) {
            Q.pop();
            cnt += Q.size();
        }
    }

    printf("%lld", cnt);

    return 0;
}