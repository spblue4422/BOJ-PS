#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

void padoban();

long long array[101] = {0};

int main() {
    long long T;
    int N;

    padoban();

    scanf("%lld", &T);

    for (int i = 0; i < T; i++) {
        scanf("%d", &N);
        printf("%lld\n", array[N]);
    }

    return 0;
}

void padoban() {
    array[1] = 1;
    array[2] = 1;
    array[3] = 1;
    array[4] = 2;
    array[5] = 2;

    for (int i = 6; i < 101; i++) {
        array[i] = array[i - 5] + array[i - 1];
    }
}