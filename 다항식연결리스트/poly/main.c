#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main(void){
	int n1=0,n2=0,i=0;
	Node*newNode1=new_Node(0,0);
	Node*newNode2=new_Node(0,0);
	Node*newNode3=new_Node(0,0);
	Node*poly1_head, *poly1_tail;
	Node*poly2_head, *poly2_tail;
	Node*result_head, *result_tail;

	poly1_head=poly1_tail=newNode1;
	poly2_head=poly2_tail=newNode2;
	result_head=result_tail=newNode3;

	printf("���׽� 1 �Է� : \n");
	printf("�� ���� �� ? ");
	scanf_s("%d",&n1);
	input(&poly1_head,&poly1_tail,0,0,n1);
	output_1(poly1_head);

	printf("���׽� 2 �Է� : \n");
	printf("�� ���� ��?");
	scanf_s("%d",&n2);
	input(&poly2_head,&poly2_tail,0,0,n2);
	output_1(poly2_head);

	printf("���� : ");
	Poly_Add(poly1_head,poly2_head,&result_head,&result_tail);
	output_1(result_head);
	output_2(result_tail);

	printf("���� : ");
	Poly_Sub(poly1_head,poly2_head,&result_head,&result_tail);
	output_1(result_head);
	output_2(result_tail);

	return 0;
}