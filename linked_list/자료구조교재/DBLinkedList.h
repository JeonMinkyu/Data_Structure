#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct _node{
	int data;
	struct _node *next; //������ ��带 ����Ű�� ������ ����
	struct _node *pre; //���� ��带 ����Ű�� ������ ����
}Node;
