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

// bfsë¥? ?‚¬?š©?•´?„œ ?’ˆ.
// ì½”ë“œ ê°œì„ ?˜ ?—¬ì§?ê°? ?ƒ?‹¹?ˆ ë§ì„ê²? ê°™ì???°
int main() {
    int N, M, dx, dy, tmp = 0, year = 0;
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &ocean[i][j]);
        }
    }

    // ìµœì´ˆ ?„¸?Œ…. ë¹™í•˜ë¥? ??— ì§‘ì–´?„£?Œ.
    while (true) {
        for (int i = 1; i < N - 1; i++) {
            for (int j = 1; j < M - 1; j++) {
                if (ocean[i][j] && !visited[i][j]) {
                    // ìµœì´ˆ ?‘¸?‰¬?•˜ê³? ë°©ë¬¸?—¬ë¶? ë°”ê¾¸ê¸?
                    que.push({ocean[i][j], i, j});
                    visited[i][j] = 1;
                    // ?ê°? ë¹Œë•Œê¹Œì?? ?ƒ?ƒ‰.
                    while (!que.empty()) {
                        dx = que.front().x;
                        dy = que.front().y;
                        que.pop();
                        calcIce(dx, dy);
                    }
                    // ?ê°? ë¹„ì–´?„œ ?ƒ?ƒ‰?´ ??‚¬?„?•Œ, tmp ì¦ê??
                    //  tmp?˜ ?—­?• ??? ë¹™ì‚°?´ ?™ê°•ë‚¬?Š”ì§?ë¥? ?Œ?‹¨
                    //  tmpê°? 1ë³´ë‹¤ ?¬?‹¤ë©? ?™ê°•ë‚˜?„œ ?ê°? ?‘ë²? ?Œ?•˜?‹¤?Š” ?œ»
                    //  tmpê°? 0?´?¼ë©? ?–¼?Œ?´ ëª¨ë‘ ?…¹?•˜?‹¤?Š” ?œ»
                    tmp++;
                }
                // tmpê°? 1?´ ?•„?‹ˆ?¼ë©? ?”„ë¡œê·¸?¨?„ ê³„ì†?•  ?´?œ ê°? ?—†?œ¼ë¯?ë¡? break
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
            // tmpê°? 0?¼?•Œ?Š”, ì¶œë ¥?„ 0?œ¼ë¡?
            year = 0;
            break;
        }
        year++;

        // ë°©ë¬¸?•œ ?–¼?Œ ë°°ì—´ ì´ˆê¸°?™”
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

// ocean ë°°ì—´ ì¡°ì • ?•¨?ˆ˜
void calcIce(int x, int y) {
    int cnt = 0;
    // ë°©ë¬¸ ?—¬ë¶?ë¥? ë¨¼ì?? ?Œ?‹¨.
    // ë°©ë¬¸?•˜ì§? ?•Š?•˜?‹¤ë©? ë°”ë‹¤?¸ì§? ë¹™ì‚°?¸ì§? ?Œ?‹¨?›„ cnt ì¡°ì •
    // ë°©ë¬¸?—¬ë¶??˜ ê¸°ì????? ??˜ ?‘¸?‰¬ ?—¬ë¶?
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