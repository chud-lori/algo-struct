#include <stdio.h>

int claimbsta(int n) {
    int dp[n+1];

    if (n == 1) {
        return 1;
    }

    for(int j=0; j<n+1; j++) {
        dp[j] = 0;
    }

    for(int i=2; i<=n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

int main(void) {

    int n=2;
    int r = claimbsta(n);

    printf("result: %d", r);
}
