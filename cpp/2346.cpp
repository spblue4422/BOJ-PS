#include <iostream>
#include <list>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main() {
    int n = 0;
    int tmp = 0;
    list<int *> balloons;

    scanf("%d", &n);
    int total = n;

    for (int i = 1; i <= n; i++) {
        scanf("%d", &tmp);
        if (tmp > 0) {
            tmp -= 1;
        }
        int *arr = new int[2]{i, tmp};
        balloons.push_back(arr);
    }

    list<int *>::iterator iter = balloons.begin();
    tmp = 0;

    for (int i = 0; i < n; i++) {
        if (tmp > 0) {
            for (int j = 0; j < tmp; j++) {
                iter++;
                if (iter == balloons.end()) {
                    iter = balloons.begin();
                }
            }
        } else if (tmp < 0) {
            tmp = (tmp % total) + total;
            for (int j = 0; j < tmp; j++) {
                iter++;
                if (iter == balloons.end()) {
                    iter = balloons.begin();
                }
            }
        }
        printf("%d ", (*iter)[0]);
        tmp = (*iter)[1];
        iter = balloons.erase(iter);
        total--;
        if (iter == balloons.end()) {
            iter = balloons.begin();
        }
    }
    return 0;
}