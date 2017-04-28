#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;
#define scanf scanf_s

int main(int argc, char * argv[]) {
	int T;
	scanf("%d", &T);
	for (int j = 1; j <= T; ++j) {
		int N;
		scanf("%d", &N);
		int * seq = new int[N + 1]();
		int * ff = new int[N + 1]();
		int index = 0, a, sum0 = 0;
		for (int i = 0; i < N; ++i) {
			scanf("%d", seq + i);
			if (!seq[i]) {
				sum0++;
			}
			else {
				seq[i] -= sum0;
				int orz = (lower_bound(ff, ff + index, seq[i]) - ff);
				if (orz == index) {
					ff[index++] = seq[i];
				}
				else {
					ff[orz] = seq[i];
				}
			}
		}
		printf("Case #%d: %d\n", j, index + sum0);
		delete[] seq; delete[] ff;
	}
	return 0;
}