#include "header.h"

void random(int arr[]){
	int i=0;
	srand(time(NULL));
	for(i=0;i<MAX;i++)
		arr[i]=(rand()%100000)+1; //1���� 100000���̷� ��������
}

void BubbleSort(int * arr, int n){ //�������� ����Sort
	int i, j, temp;

	for(i=0; i<n-1; i++){
		for(j=0; j<(n-i)-1; j++){
			if(arr[j]>arr[j+1]){
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}

void merge(int arr[],int left, int mid, int right){ //�� �迭 ��ġ��
	int front=left;
	int back=mid+1;
	int i;

	int*sorted=(int*)malloc(sizeof(int)*(right+1));
	int tmp=left;

	while(front<=mid && back<=right){//�� ���� �迭���� �����ͺ��� ������ ��������
		if(arr[front]<=arr[back]) 
			sorted[tmp]=arr[front++];
		else
			sorted[tmp]=arr[back++];
		tmp++;
	}

	if(front>mid){
		for(i=back;i<=right;i++){
			sorted[tmp]=arr[i];
			tmp++;
		}
	}
	else{
		for(i=front;i<=mid;i++){
			sorted[tmp]=arr[i];
			tmp++;
		}
	}
	for(i=left;i<=right;i++)
		arr[i]=sorted[i];

	free(sorted);
}

void MergeSort(int arr[], int left, int right){
	int mid;

	if(left<right){
		mid=(left+right)/2; //�߰� ���� ���

		MergeSort(arr,left,mid);
		MergeSort(arr,mid+1,right);

		merge(arr,left,mid,right);
	}
}

void RadixSort(int*arr, int n){
	int i=0,j=0,max=0,exp=1,idx=0,k=0,tmp=0;
	int bucket[10][MAX]={0};
	int count[10]={0};

	for(i=0;i<n;i++){//�ִ� ã��
		if(arr[i]>max)
			max=arr[i];
	}

	while(max/exp>=1){
		for(i=0;i<10;i++) //��Ŷ���� ���� ���� �ʱ�ȭ
			count[i]=0;

		for(j=0;j<n;j++){//��Ŷ�� ���
			idx=(arr[j]/exp)%10; //�ڸ��� �´� ���ڻ̱�
			bucket[idx][count[idx]]=arr[j]; //������ ���ڸ� ��Ŷ�� ����
			count[idx]=count[idx]+1; //���� ��Ŷ�� ���� ���� ����
		}
		
		for(i=0;i<10;i++){ //��Ŷ�� �ִ� ���� ���� �迭�� �ٽ� ����
			for(k=0;k<count[i];k++){
				arr[tmp]=bucket[i][k];
				tmp++;
			}
		}
		tmp=0;
		exp*=10;
	}
}

void sorted(int arr[]){
	int i=0;
	for(i=0;i<MAX;i++)
		printf("%d ",arr[i]);
}