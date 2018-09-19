#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "header.h"

int main(void){
	Node*newNode=new_node();//�� �տ� ���̳�� �߰� -> ���� �� ���� �տ� �ִ� ��带 �����Ҷ��� pre���� ������ ����
	Node*head=NULL;
	Node*tail=NULL;
	int menu=0,i=0,data=0,idx=0;
	head=tail=newNode; //���̳��
	while(1){
		menu=show_menu();
		if(menu==6){
			printf("�����մϴ� .\n");
			break;
		}
		switch(menu){
		case 1:
			printf("������ �� �Է� (�ڿ����� ����): ");
			scanf_s("%d",&data);
			if(data==0){
				printf("�ڿ����� �Է� �����մϴ�\n");//����ó��
				break;
			}
			if(data<head->data) insert_front(&head,data); //head�� ����Ű�� ������ �۴ٸ� �տ� ����
			else if(data>tail->data) insert_back(&tail,data); //tail�� ����Ű�� ������ ũ�ٸ� �ڿ� ����
			else insert_middle(head,data); //�Ѵ� �ƴ϶�� �߰��� ����
			break;
		case 2:
			printf("������ �� �Է� : ");
			scanf_s("%d",&data);
			Delete(&head,&tail,data);
			break;
		case 3:
			printf("�˻��� �� �Է� : ");
			scanf_s("%d",&data);
			printf("data�� index : %d\n",search(head,data));
			break;
		case 4:
			printf("���� : %d\n",ListLength(head));
			break;
		case 5:
			show(head);
			break;
		}
	}
}