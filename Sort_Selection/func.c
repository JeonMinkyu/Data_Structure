#include"head.h"

int min_index(int num[20]){//�ּڰ� �ε��� ã��
	int i=0,j=0;
	int min=0;
	for(i=0;i<20;i++){
		if(num[min]>num[i]){
			min=i;
		}
	}
	return min;
}

void random_num(int arr[20]){//random ����
	int i=0;
	for(i=0;i<20;i++){
		arr[i]=rand()%100+1;
	}
}

void print(int num[20]){//���� �迭���� ���
	int i=0;
	for(i=0;i<20;i++){
		printf("%d ",num[i]);
	}
	printf("\n");
}


void selection_sort(int num[20]){//��������
	int i=0,j=0,min=0,temp=0, n=0,k=0;
	for(i=0;i<19;i++){//19��° �����ϸ� ������ ���� �ڵ� ����
		min=i;//�ּҰ� index����
		print(num);
		for(j=i+1;j<20;j++){
			if(num[j]<num[min]){
				min=j;
			}
		}
		temp=num[min];
		num[min]=num[i];
		num[i]=temp;
	}
}

void bubble_sort(int num[20]){//��������
	int i=0,j=0,temp=0;
	for(i = 0; i < 19; i++) { // ������ �� ȸ���� �����ϱ� ����
		for(j = 0; j < 19; j++){// ������ �� �� ��ȯ 
			if(num[j]>num[j+1]){//�տ� �ִ� ���ڰ� �ڿ� �ִ°ͺ��� Ŭ ���->�ڸ��ٲ�
				temp=num[j];
				num[j]=num[j+1];
				num[j+1]=temp; 
			} 
		}print(num);//��Ȳ ��� 
	}
}

void seq(int num[20],int search){
	int i=0;
	int a=0,n=0;
	for(i=0;i<20;i++){
		if(num[i]==search){
			a=num[i];
			n=i;
		}

		else if(search>num[i] && search<num[i+1]){
			if(search-num[i]>num[i+1]-search)
				a=num[i+1];
			else
				a=num[i];
			n=i;
		}
	}
	printf("Ž�� Ƚ�� : %d\n",n);
	printf("Ž�� ��� : %d\n",a);
}

void bin(int num[20],int search){
	int a=0,n=0,i=0;
	int low=0,middle=0;
	int high=19;

	while(low<=high){//���� ���� �������� �� ����
		middle=(low+high)/2;
		if(search==num[middle]){
			a=num[middle];
			n=i;
			break;
		}
		else if(search>num[middle])
			low=middle+1;
		else
			high=middle-1;
		i++;
	}
	printf("Ž�� Ƚ�� : %d\n",n);
	printf("Ž�� ��� : %d\n",a);
}	