#include <iostream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;

int main() {
    long long len = 0;
    int cnt = 0, temp = 0;
    stack<int> stk;
    char arr[100];

    scanf("%s", arr);
    string str = arr;

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ')') {
            while (stk.top() != '(') {
                if (stk.top() < 0) {
                    cnt += (stk.top() * -1);
                    stk.pop();
                } else {
                    cnt++;
                    stk.pop();
                }
            }
            stk.pop();
            if (!stk.empty()) {
                temp = stk.top() - 48;
                stk.pop();
                if (temp * cnt * -1 != 0) {
                    stk.push(temp * cnt * -1);
                }
            }
            cnt = 0;
        } else {
            stk.push(str[i]);
        }
    }

    while (!stk.empty()) {
        if (stk.top() < 0) {
            len += (stk.top() * -1);
        } else {
            len++;
        }
        stk.pop();
    }

    printf("%lld", len);

    return 0;
}

// struct zip {
//     int letter;
//     //플래그가 0이면 일반 글자, 1이면 반복된 문자열의 길이
//     int flag;
// };

// int main() {
//     long long len = 0;
//     int cnt = 0, repeat;
//     stack<zip> stk;
//     char arr[100];

//     scanf("%s", arr);
//     string str = arr;

//     for (int i = 0; i < str.length(); i++) {
//         if (str[i] == ')') {
//             //)일때는 (가 나오기전까지 스택에서 팝
//             while (stk.top().letter != '(') {
//                 //팝할때, 플래그 값이 1이면 압축을 푼 문자열의 길이 이므로,
//                 // cnt에 더해줘야함. 아니면 그냥 1을 더함.
//                 cnt = stk.top().flag ? cnt + stk.top().letter : cnt + 1;
//                 stk.pop();
//             }
//             //( 팝
//             stk.pop();
//             //문자열을 반복할 횟수
//             if (!stk.empty() && stk.top().letter != '(') {
//                 repeat = stk.top().letter - 48;
//                 stk.pop();
//             } else {
//                 repeat = 0;
//             }
//             // 반복횟수 * 반복할 문자열길이, 플래그는 1로 푸시
//             stk.push({repeat * cnt, 1});
//             cnt = 0;
//         } else { //)가 아니면 스택에 모두 푸시
//             stk.push({str[i], 0});
//         }
//     }

//     while (!stk.empty()) {
//         len = stk.top().flag ? len + stk.top().letter : len + 1;
//         stk.pop();
//     }

//     printf("%lld", len);

//     return 0;
// }

// struct zip {
//     int repeat;
//     int dest;
// };

// string으로 풀려했으나 메모리초과 발생
// int main() {
//     int len = 0;
//     string str, temp;
//     stack<zip> stk;
//     char arr[100];

//     scanf("%s", arr);
//     str = arr;

//     for (int i = 0; i < str.length(); i++) {
//         if (str[i] == '(') {
//             stk.push({(int)str[i - 1] - 48, i - 1});
//         } else if (str[i] == ')') {
//             //반복할 문자열 추출
//             temp = str.substr(stk.top().dest + 2, i - (stk.top().dest + 2));
//             //압축된 부분 삭제 -> 3글자 + 임시문자열 길이
//             str.erase(stk.top().dest, 3 + temp.length());
//             //반복문자열 삽입
//             for (int i = 0; i < stk.top().repeat; i++) {
//                 str.insert(stk.top().dest, temp);
//             }
//             i = stk.top().dest + temp.length() * stk.top().repeat - 1;
//             stk.pop();
//         }
//     }

//     printf("%d", str.length());

//     return 0;
// }