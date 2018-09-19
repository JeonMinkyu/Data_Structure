#include <stdio.h>

typedef struct heap{
	int key[10];
	int heap_size;
}HeapType;

void init(HeapType*heap){
	heap->heap_size=0;
}

void insert_heap(HeapType*heap, int data){ //�ִ� �� ����
	int i=0;
	i=++(heap->heap_size); //������ index �ڸ��� ���� �����ϱ� ���� ����
	
	while(i!=1 && data>heap->key[i/2]){ //root ��尡 �ƴҶ�����, �Էµ� data�� �θ��庸�� �۾��� ������ ��� �ö�
		heap->key[i]=heap->key[i/2];//�ڸ��� ã�ư�
		i/=2;
	}
	heap->key[i]=data;//ã�� index�ڸ��� data�ֱ�
}

int delete_heap(HeapType*heap){ //�ִ� �� ����
	int parent=1, child=2;
	int data=0, tmp=0;

	data=heap->key[parent]; //root����� data
	tmp=heap->key[(heap->heap_size)--];//������ ���

	while(child<=heap->heap_size){//child index�� ��ü �� ������� ũ�ų� ���� ����(�ܸ������� �� �������鼭 ���ؾ� �ϹǷ�)
		if((child<heap->heap_size) && (heap->key[child]) <heap->key[child+1])//���� ����� �ڽĳ�� �� �� ���� �ڽĳ�尡 �ִٸ�
			child++;
		if(tmp>=heap->key[child])//�ش� ��尡 �ڽ� ��庸�� ũ�ų� �������� ����
			break;
		heap->key[parent]=heap->key[child];
		parent=child;
		child*=2;//��� �ڽĳ��� ������
	}
	heap->key[parent]=tmp;//������ ���� �ڸ��� ã�Ƽ� tmp��� data�� ����
	return data;
}

void heap_sort(HeapType*heap,int*arr,int n){
	int i=0;

	for(i=0;i<n;i++)
		insert_heap(heap,arr[i]);

	for(i=heap->heap_size-1;i>=0;i--)
		arr[i]=delete_heap(heap);
}

int main(void){
	int arr[]={8,9,1,5,7,2,4,3,6,10};
	int i=0;
	HeapType heap;
	heap.heap_size=0;

	printf("before : ");
	for(i=0;i<10;i++)
		printf("%d ",arr[i]);
	printf("\n");
	
	heap_sort(&heap,arr,10);
	printf("after : ");
	for(i=0;i<10;i++)
		printf("%d ",arr[i]);
	printf("\n");

	return 0;
}
