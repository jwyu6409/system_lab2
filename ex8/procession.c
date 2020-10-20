#include <stdio.h>
#include <stdlib.h>

void input(int **m, int line, int row);
void output(int **m, int line, int row);

int main(int args, int argv[]){
	int i, j;
	int line, row;

	printf("행을 입력하세요 : ");
	scanf(" %d", &line);

	printf("열을 입력하세요 : ");
	scanf(" %d", &row);

	int **d_Array=malloc(sizeof(int *) *line);
	int **c_Array=malloc(sizeof(int *) *line);
	int **out=malloc(sizeof(int *) *line);

	for(i=0; i<line; i++){
		d_Array[i]=malloc(sizeof(int *) *row);
		c_Array[i]=malloc(sizeof(int *) *row);
		out[i]=malloc(sizeof(int *) *row);
	}

	printf("첫번째 행렬 : \n");
	input(d_Array, line, row);
	output(d_Array, line, row);
	printf("\n\n");

	printf("두번째 행렬 : \n");
	input(c_Array, line, row);
	output(c_Array, line, row);
	printf("\n\n");

	printf("두 행렬의 합 : \n");

	for(i=0; i<line; i++){
		for(j=0; j<row; j++){
			out[i][j]=d_Array[i][j] + c_Array[i][j];
		}
	}

	for(i=0; i<line; i++){
		for(j=0; j<row; j++){
			printf("%d ", out[i][j]);
		}
		printf("\n");
	}

	for(i=0; i<row; i++){
		free(d_Array[i]);
		free(c_Array[i]);
		free(out);
	}

	free(d_Array);
	free(c_Array);
	free(out);

	return 0;
}

void input(int **m, int line, int row){
	int i, j;

	for(i=0; i<line; i++){
		for(j=0; j<row; j++){
			m[i][j]=i+j;
		}
	}
}

void output(int **m, int line, int row){
	int i, j;

	for(i=0; i<line; i++){
		for(j=0; j<row; j++){
			printf("%d ", m[i][j]);
		}
		printf("\n");
	}
}
