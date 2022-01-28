#include <iostream>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

struct fr {
    char name[21];
    int rank;
    int length;
};

int main() {
    int n, k;
    char nameArr[21] = {0};
    queue<fr> Q;

    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%s", nameArr);
    }

    return 0;
}