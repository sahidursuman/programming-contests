#include <stdio.h>
#include <stdlib.h>

int main(){

	int M[100][100];
	int i = 0, j = 0, k = 0, n = 0, read = 0;
	
	scanf("%d", &n);

	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			M[i][j] = 0;

	for(k = 0; k < 2; k++){
	
		for(i = 0; i < n; i++)
			for(j = 0; j < n; j++){
				scanf("%d", &read);
				M[i][j] += read;
			}
	
	}
	
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++)
			printf("%d ", M[i][j]);
		printf("\n");
	}

	return 0;
}
