#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int MatrixChainOrder(int arr[], int size) {
	int m[size][size];
	int k=0;
	int q=0;
	for (int i=1; i<size; i++) {
		m[i][i] = 0;
	}

	for (int i=2; i<size; i++) {
		for (int j=1; j<size-i+1; j++) {
			k = i+j-1;
			m[j][k] = INT_MAX;
			for (int l=j; l<k; l++) {
				q = m[j][l] + m[l+1][k] + arr[j-1]*arr[l]*arr[k];
				if (q < m[j][k]) {
					m[j][k] = q;
				}
			}
		}
	}

	return m[1][size-1];
}

int main()
{
    int arr[] = {2, 3, 6, 4, 5};
    int size = sizeof(arr)/sizeof(arr[0]);
 
    printf("Minimum number of multiplications is %d \n", MatrixChainOrder(arr, size));
    return 0;
}