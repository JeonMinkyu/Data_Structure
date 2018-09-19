#include <stdio.h>
#include <malloc.h>

typedef struct matrix{
	int row;
	int col;
	int data;
}mat;

void input(mat*p, int n){
	int i=0;
	for(i=0;i<n;i++){
			printf("�� : ");
			scanf_s("%d",&(p[i].row));
			printf("�� : ");
			scanf_s("%d",&(p[i].col));
			printf("�� : ");
			scanf_s("%d",&(p[i].data));
			printf("\n");
	}
}

void add(mat*a,mat*b,mat*result){
	int i=0,j=0,tmp=0;
	while(i<3 && j<3){
		if(a[i].row == b[j].row && a[i].col == b[j].col){
			result[tmp].data=a[i].data+b[j].data;
			result[tmp].col=a[i].col;
			result[tmp].row=a[i].row;
			tmp++;
		}
		else{
			result[tmp].data=a[i].data;
			result[tmp].row=a[i].row;
			result[tmp].col=a[i].col;
			tmp++;

			result[tmp].data=b[j].data;
			result[tmp].row=b[j].row;
			result[tmp].col=b[j].col;
			tmp++;
		}
		i++;
		j++;
	}
}

void output(mat*result, int n){
	int i=0,j=0;

	for(i=0;i<n;i++){
		printf("�� : %d, �� : %d, �� : %d \n",result[i].row,result[i].col,result[i].data);
	}
}
int main(void){
	int i=0,j=0;
	mat*a=NULL;
	mat*b=NULL;
	mat*result=NULL;

	printf("��� a �� �Է� : \n");
	a=(mat*)malloc(sizeof(mat)*3); //0�� �ƴ� data 3�� {{1,0,0},{0,1,0},{0,0,3}} ����
	input(a,3);
	printf("��� b �� �Է� : \n");
	b=(mat*)malloc(sizeof(mat)*3); //0�� �ƴ� data 3�� {{0,0,0}.{0,0,3},{4,0,1}} ����
	input(b,3);

	result=(mat*)malloc(sizeof(mat)*5);
	add(a,b,result);
	output(result,5); //{{1,0,0},{0,1,3},{4,0,4}}�� ��� ����

	free(a);
	free(b);
	free(result);
	return 0;
}