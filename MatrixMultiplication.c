#include <stdio.h>

int main() {
	
	int m, n, r, p;

	// Read dimensions of Matrix A
	scanf("%d %d", &m, &n);

	int A[m][n];

	// Read Matrix A
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &A[i][j]);
		}
	}

    // Read dimensions of Matrix B
	scanf("%d %d", &r, &p);

    // Check if multiplication is possible
	if (n != r) {
		printf("Invalid input");
		return 0;
	}

	int B[r][p];

	// Read Matrix B
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < p; j++) {
			scanf("%d", &B[i][j]);
		}
	}

	int C[m][p];

    // Matrix multiplication
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < p; j++) {
			C[i][j] = 0;
			for (int k = 0; k < n; k++) {
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}

    // Print result matrix
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < p; j++) {
			printf("%d ", C[i][j]);
			if (j < p - 1)
				printf("");
		}
		printf("\n");
	}

	return 0;
}
