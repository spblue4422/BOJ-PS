#include <algorithm>
#include <cmath>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
using namespace std;

int disassemble(int i);

vector<int> broken;
vector<int> channel;

// 역대급으로 짜증났던 문제
int main() {
    int N, M, tmp, result = 9999999;

    scanf("%d", &N);
    scanf("%d", &M);

    //고장난 버튼 목록
    for (int i = 0; i < M; i++) {
        scanf("%d", &tmp);
        broken.push_back(tmp);
    }

    // 목표로 하는 채널 벡터에 집어넣기
    tmp = N;
    if (tmp == 0) {
        channel.push_back(tmp);
    } else {
        while (tmp) {
            channel.push_back(tmp % 10);
            tmp /= 10;
        }
    }

    // +, - 로만 움직일때
    result = min(result, abs(N - 100));

    // 범위 내 모든 값을 for문으로 돌면서 체크
    for (int i = 0; i < 999999; i++) {
        tmp = disassemble(i);
        if (!tmp) {
            continue;
        } else {
            result = min(result, abs(N - i) + tmp);
        }
    }

    printf("%d", result);

    return 0;
}

//
int disassemble(int i) {
    int flag = 1, ret;
    string str = to_string(i);

    for (int j = 0; j < broken.size(); j++) {
        if (str.find(to_string(broken[j])) < str.size()) {
            flag = 0;
        }
    }

    if (!flag) {
        ret = flag;
    } else {
        ret = str.size();
    }
    return ret;
}