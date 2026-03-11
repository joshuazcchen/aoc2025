#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare_long(const void *a, const void *b) {
	const long *row_a = (const long *)a;
	const long *row_b = (const long *)b;

	if (row_a[0] < row_b[0]) return -1;
	if (row_a[0] > row_b[0]) return 1;
	return 0;
}

int main() {
	FILE *fp = fopen("input.txt", "r");
	long ranges[500][2];
	int rangeSize = 0;
	char imm[250];
	while (fgets(imm, 250, fp)){
		if (strcmp(imm, "") == 0 || strcmp(imm, "BREAK") == 0) {
			break;
		} else {
			char *endp;
			long lo = strtol(imm, &endp, 10);

			if (!lo) {
				break;
			}
			if (imm == endp) {
				break;
			}
			long hi = strtol(endp+sizeof(char), NULL, 10);
			ranges[rangeSize][0] = lo;
			ranges[rangeSize][1] = hi;
			rangeSize++;
		}
	}
	qsort(ranges, rangeSize, sizeof(ranges[0]), compare_long);

	if (rangeSize == 0) return 0;

	int resultingLen = 0;
	long long currentStart = ranges[0][0];
	long long currentEnd = ranges[0][1];
	long long resultingRange[500][2];

	for (int i = 1; i < rangeSize; i++) {
		long long nextStart = ranges[i][0];
		long long nextEnd = ranges[i][1];
		if (nextStart <= currentEnd) {
			if (nextEnd > currentEnd) currentEnd = nextEnd;
		} else {
			resultingRange[resultingLen][0] = currentStart;
			resultingRange[resultingLen][1] = currentEnd;
			resultingLen++;

			currentStart = nextStart;
			currentEnd = nextEnd;
		}
	}

	resultingRange[resultingLen][0] = currentStart;
	resultingRange[resultingLen][1] = currentEnd;
	resultingLen++;
	long long cou = 0;
	for (int i = 0; i < resultingLen; i++) {
		cou += (1 + resultingRange[i][1] - resultingRange[i][0]);
	}
	printf("%lld", cou);

	return 0;
}

