#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#define mod 1000000007

using namespace std;

#define scanf scanf_s

long long dp[1010][1010];

int main(int argc, char * argv[]) {
	int N, M;
	while (scanf("%d %d", &N, &M) != EOF) {
		memset(dp, 0, sizeof(dp));
		int *A = new int[N + 1], *B = new int[M + 1];
		for (int i = 1; i <= N; ++i) {
			scanf("%d", A + i);
		}
		for (int i = 1; i <= M; ++i) {
			scanf("%d", B + i);
		}
		for (int i = 1; i <= M; ++i) {
			for (int j = 1; j <= N; ++j) {
				if (A[j] != B[i]) {
					dp[i][j] = -dp[i - 1][j - 1] + dp[i][j - 1] + dp[i - 1][j];
				}
				else {
					dp[i][j] = dp[i - 1][j] + 1 + dp[i][j - 1];
				}
				dp[i][j] += mod;
				dp[i][j] %= mod;
			}
		}
		printf("%lld\n", dp[M][N]);
		delete[] A;
		delete[] B;
	}
	return 0;
}