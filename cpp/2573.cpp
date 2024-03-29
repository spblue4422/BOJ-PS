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

// bfsλ₯? ?¬?©?΄? ?.
// μ½λ κ°μ ? ?¬μ§?κ°? ??Ή? λ§μκ²? κ°μ???°
int main() {
    int N, M, dx, dy, tmp = 0, year = 0;
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &ocean[i][j]);
        }
    }

    // μ΅μ΄ ?Έ?. λΉνλ₯? ?? μ§μ΄?£?.
    while (true) {
        for (int i = 1; i < N - 1; i++) {
            for (int j = 1; j < M - 1; j++) {
                if (ocean[i][j] && !visited[i][j]) {
                    // μ΅μ΄ ?Έ?¬?κ³? λ°©λ¬Έ?¬λΆ? λ°κΎΈκΈ?
                    que.push({ocean[i][j], i, j});
                    visited[i][j] = 1;
                    // ?κ°? λΉλκΉμ?? ??.
                    while (!que.empty()) {
                        dx = que.front().x;
                        dy = que.front().y;
                        que.pop();
                        calcIce(dx, dy);
                    }
                    // ?κ°? λΉμ΄? ???΄ ??¬??, tmp μ¦κ??
                    //  tmp? ?­? ??? λΉμ°?΄ ?κ°λ¬?μ§?λ₯? ??¨
                    //  tmpκ°? 1λ³΄λ€ ?¬?€λ©? ?κ°λ? ?κ°? ?λ²? ???€? ?»
                    //  tmpκ°? 0?΄?Όλ©? ?Ό??΄ λͺ¨λ ?Ή??€? ?»
                    tmp++;
                }
                // tmpκ°? 1?΄ ???Όλ©? ?λ‘κ·Έ?¨? κ³μ?  ?΄? κ°? ??Όλ―?λ‘? break
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
            // tmpκ°? 0?Ό??, μΆλ ₯? 0?Όλ‘?
            year = 0;
            break;
        }
        year++;

        // λ°©λ¬Έ? ?Ό? λ°°μ΄ μ΄κΈ°?
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

// ocean λ°°μ΄ μ‘°μ  ?¨?
void calcIce(int x, int y) {
    int cnt = 0;
    // λ°©λ¬Έ ?¬λΆ?λ₯? λ¨Όμ?? ??¨.
    // λ°©λ¬Έ?μ§? ???€λ©? λ°λ€?Έμ§? λΉμ°?Έμ§? ??¨? cnt μ‘°μ 
    // λ°©λ¬Έ?¬λΆ?? κΈ°μ????? ?? ?Έ?¬ ?¬λΆ?
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