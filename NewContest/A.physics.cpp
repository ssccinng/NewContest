#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <math.h>

using namespace std;

#define scanf scanf_s

int main(int argc, char * argv[]) {
	int T;
	scanf("%d", &T);
	for (int j = 1; j <= T; ++j) {
		long long N, C;
		scanf("%lld %lld", &N, &C);
		long long * seq = new long long[N + 1];
		long long a, b, c;
		for (int i = 1; i <= N; ++i) {
			scanf("%lld %lld %lld", &a, &b, &c);
			seq[i] = a;
		}
		sort(seq + 1, seq + N + 1);
		int q;
		scanf("%d", &q);
		long long d, e;
		while (q--) {
			scanf("%lld %lld", &d, &e);
			printf("%.3f\n", sqrt(seq[e] * seq[e] + 2.0 * C * d));
		}
		delete[] seq;
	}
	return 0;
}