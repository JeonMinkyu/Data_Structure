#include"head.h"

int main(void){
	int i=0,j=0,n=0,a=0;
	int search=0;
	int num[20]={0};
	while(1){
		printf("===========�޴�==========\n");
		printf("1. ���� 20�� �����ϱ�\n");
		printf("2. ���� �迭 ����ϱ�\n");
		printf("3. �����ϱ�\n");
		printf("4. Ž���ϱ�\n");
		printf("5. ����\n");
		printf("=========================\n\n");
		printf("�޴��� �Է��Ͻÿ� : ");
		scanf_s("%d",&n);
		if(n==5){
			printf("�����մϴ�.\n");
			break;
		}
	switch(n){
		case 1:
			srand((unsigned)time(NULL));
	
			for(i=0;i<20;i++){
				num[i]=rand()%100+1;
			}
			break;
			case 2:
			print(num);
			break;
		case 3:
			printf("1. ��������\n");
			printf("2. ��������\n");
			scanf_s("%d",&a,sizeof(a));
	
			if(a==1)
				selection_sort(num);
			else if(a==2)
				bubble_sort(num);
			break;
		case 4:
			printf("1. ����Ž��\n");
			printf("2. ����Ž��\n");
			scanf_s("%d",&a,sizeof(a));
			printf("Ž���� ���� �Է��Ͻÿ� : ");
			scanf_s("%d",&search,sizeof(search));
			if(a==1)
				seq(num,search);
			else if(a==2)
				bin(num,search);
			break;
		}
	}
}