#include <stdio.h>
#include <time.h>

int factorial(int n){ //���ȣ���� �̿�-�˰����� ������

	if(n<=1) return(1);
	else return(n*factorial(n-1));
}

int fact(int n){ //�ݺ��� �̿�-�ӵ��� ������ �޸� ����� ����
	int i, f=1;
	if(n<=1) return(1);
	else{
		for(i=1;i<=n;i++)
			f=f*i;
		return f;
	}
}

int main(void){
	int n=0;
	clock_t start=0, end=0;

	scanf("%d",&n);
	start=clock();
	printf("factorial : %d\n",factorial(n));
	end=clock();
	printf("�ð�(���) : %lf\n",(double)end-start);

	start=clock();
	printf("fact : %d\n",fact(n));
	end=clock();
	printf("�ð�(�ݺ�) : %lf\n",(double)end-start);
	return 0;
}
