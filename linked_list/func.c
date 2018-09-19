#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "header.h"

int show_menu(){
   int menu = 0;
   printf("##############################################\n");
   printf("1. insert��  2. delete\n");
   printf("3. search��  4. length\n");
   printf("5. show      6. ����\n");
   printf("##############################################\n");

   scanf("%d",&menu);
   return menu;
}

//��� ����
Node*new_node(){
	Node*newNode=(Node*)malloc(sizeof(Node));
	newNode->data=0;
	newNode->next=NULL;

	return newNode;
}

int ListLength(Node*head){
	Node*cur=head;
	int count=0;
	while(cur!=NULL){
		count++;
		cur=cur->next;
	}
	return count-1;//�� �� ���̺���(0) ����
}

void insert_front(Node**head, int data){//head���� ���� ���� �������� head�� �պκп� �����ϴ� �Լ�.
	//head��ü�� ������ �ʿ��ϹǷ� �ּ��� ������ �ʿ��ϴ�.
	//���� ���� Node*head�� main���� ���������Ƿ� �ּҸ� �ѱ�� ���� Node**head�� �Ѱ��ش�.
	Node*newNode=new_node();//��� ����

	newNode->data=data;//������ �ʱ�ȭ
	newNode->next=*head;//���� head�� ���� �� ����� next�� ��
	*head=newNode;//head�� ���� ������
}

void insert_back(Node**tail,int data){//tail���� ū ���� �������� tail�� �޺κп� �����ϴ� �Լ�.
	//���� ���������� ������ Node**tail�� �Լ� ���ڷ� �Ѱ��ش�.
	Node*newNode=new_node();
	newNode->data=data;//������ ����
	
	(*tail)->next=newNode;//���� tail�� next������ ���ο� ��尡 ��
	(*tail)=(*tail)->next;//���� �� ��尡 tail�̵�
}

void insert_middle(Node*head,int data){//�� �ΰ��� ��찡 ��� �ƴ� �߰��� �����ϴ� �Լ�
	//middle�� �ִ� �Լ��� head�� tail�� ���� �ٲ��� ���� ����
	//���� �ּҸ� �ѱ��� �ʾƵ� �ǰ� ������ �� ��ġ�� ã�� ���� ó�� head���� �Ѱ��־� ã�����Ѵ�.
	Node*p=head;//�ݺ����� ���鼭 ������ ��带 ����ų ����ü ������ p
	Node*newNode=new_node(); //���� ����Ʈ�� �߰��� ���

	while(p->next->data<=data)//insert�� ��ġ�� ã������
		p=p->next;
	if(data==p->next->data){//�ߺ��� ������
		printf("�̹� ����\n");
		return;
	}
	newNode->data=data;
	newNode->next=p->next;//newNode�� next�� ��ġ�� ã������ next�� ����
	p->next=newNode;//�ᱹ 'p'�� ��ġ�� �յڷ� ����
}

int search(Node*head,int data){
	Node*find=head;
	int idx=0;

	while(1){
		if(find->data==data){
			return idx;
			break;
		}
		else{
			find=find->next;
			idx++;
		}
	}
	return -1;
}

void Delete(Node**head, Node**tail, int data){
	Node*remove=*head;//�� ��(head)���� ã������(���� ��尪�� ���̳��(0))
	Node*pre=NULL;//�����ϱ� ���� ���� ������ ������ �� �������� �����������

	while(remove!=NULL){//������ Ž��
		if(remove->data==data){//���ﰪ�� ã����
			pre->next=remove->next;//�� ���� ��ġ�� next���� ���� ��ġ�� ���� ���� ����(������ ����)
			break;
		}
		else{
			pre=remove;//���� ���� ��� Ž���� ����
			remove=remove->next;
		}
	}
	free(remove);
}

void show(Node*head){
	Node*p=head;

	if(isEmpty(head)==0)
		printf("��� �ֽ��ϴ�.\n");
	else{
		while(p!=NULL){
			printf("%d ",p->data);
			p=p->next;
		}
	}
	printf("\n");
}

int isEmpty(Node*head){
	if(head->next==NULL)
		return 0;
	else
		return 1;
}


