#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
	int cou = 0;
	while (fgets(imm, 250, fp)) {
		long v = strtol(imm, NULL, 10);
		for (int i = 0; i < rangeSize; i++) {
			if (v >= ranges[i][0] && v <= ranges[i][1]) {
				cou++;
				break;
			}	
		}
	}
	printf("%d", cou);
	return 0;
}

