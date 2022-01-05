#include <algorithm>
#include <iostream>
#include <stdio.h>
using namespace std;

int dp[10000] = {0};

int main() {
    int n = 0;
    int arr[1001];
    int M = 0;

    scanf("%d", &n);

    for (int i = 0; i < 1000; i++) {
        scanf("%d", &arr[i]);
    }
    dp[1] = arr[0];
    for (int i = 1; i < n; i++) {
        dp[i + 1] = dp[1] + arr[i];
        
    }
}