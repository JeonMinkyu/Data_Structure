#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct node{
	int coef;
	int degree;
	struct node*pre; //���� ��带 ����Ŵ
	struct node*next; //���� ��带 ����Ŵ
}Node;

typedef struct list{
	Node*head;
	Node*tail;
	int num;//list���� ���� ����
}List;

void new_List(List*plist){
	plist->head=NULL;
	plist->tail=NULL;
	plist->num=0;
}

void insert(List*plist,int coef, int degree){
	Node*newNode=(Node*)malloc(sizeof(Node));//������ ���
	if(newNode==NULL){
		printf("����!\n");
		exit(1);
	}

	newNode->coef=coef;
	newNode->degree=degree;
	newNode->next=NULL;

	if(plist->head==NULL){ //ó�� �Է�(����) 
		plist->head=newNode; 
		plist->tail=newNode; //ó�� ��忡 head�� tail�� ���ÿ� ����
	}
	else{
		plist->tail->next=newNode; //newNode�� tail�ڿ� ���̰�
		plist->tail=newNode; //newNode�� tail�� �缳��
	}
	plist->num++; //����Ʈ ���� ���� �ϳ� �߰�
}

void Poly_Add(List*plist1, List*plist2, List*plist3){
	Node*newNode1;
	Node*newNode2;
	int sum=0;

	newNode1=plist1->head; 
	newNode2=plist2->head; //���� ó������ search�ϱ� ����
	
	//���� ������ ��� �����ְ�
	//�ٸ� ������ ��� ������ ū�� ������, ������ ������ �ڷ� ������ �����ϸ� ����

	while(newNode1 && newNode2){ //newNode1, newNode2�߿��� ��� �� ���� NULL�� ����������(����������)
		if(newNode1->degree==newNode2->degree){ // �� �Ŀ��� ������ ���ٸ�
			sum=newNode1->coef+newNode2->coef; //�� ����� ���Ͽ� sum�̶�� ������ �־��ֱ�
			if(sum!=0){ //�� sum�� 0�� �ƴ϶��
				insert(plist3,sum,newNode1->degree); //plist3�̶�� ����Ʈ ������ ����� ���� ����Ʈ�� sum��(���)�� �� ����� degree(����)�� ����
				newNode1=newNode1->next; //���� ������ �Ѿ��
				newNode2=newNode2->next; //���� ������ �Ѿ��
			}
		}
		else if(newNode1->degree>newNode2->degree){ //������ �ٸ� ���¿��� ù��° ���� ������ �� Ŭ ���
			insert(plist3,newNode1->coef,newNode1->degree); //�״�� ����� ����Ʈ�� �� ū ������ ����� �־��ش�
			newNode1=newNode1->next; // ������ ���� ���� ���� ���� ������ �Ѿ����
		}
		else{ //�ι�° ���� ������ �� Ŭ ���
			insert(plist3,newNode2->coef,newNode2->degree); //���� ���������� �ι�° ���� ������ �� Ŭ ��� �� ū ������ ����� �־���
			newNode2=newNode2->next; //���� ������ �Ѿ����
		}
	}
	//���� �ϳ��� ���� ������ ���� �׵��� �״�� �ڿ� ���̱⸸ �ϸ� ��
	while(newNode1!=NULL){ //newNode1�� �Լ��� ������ ������ �ʾҴٸ� ����������
		insert(plist3,newNode1->coef,newNode1->degree); //�������� ����� ������ �״�� �������ֱ�
		newNode1=newNode1->next; //newNode1�� �ݺ����� ���� ��� �������� ����ų �� �ֵ���
	}
	while(newNode2!=NULL){ //newNode2�� �Լ��� ������ ������ �ʾҴٸ� ����������
		insert(plist3,newNode2->coef,newNode2->degree); //�������� ����� ������ �״�� ����
		newNode2=newNode2->next; //newNode2�� �ݺ����� ���� ��� �������� ����ų �� �ֵ���
	}
}

void Poly_Print(List*plist){ //������ֱ�
	Node*p=plist->head; //ó������ ����ϱ����� head�� �־���
	while(p!=NULL){
		printf("%d * %d ",p->coef,p->degree);
		p=p->next;
	}
}

