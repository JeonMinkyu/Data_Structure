#include "DLinkedList.h"

void ListInit(List*plist){
	plist->head=(Node*)malloc(sizeof(Node));//���̳�� ����
	plist->head->next=NULL;
	plist->comp=NULL;
	plist->numOfData=0;
}

void FInsert(List*plist, LData data){ //comp�� NULL�϶� ȣ��
	Node*newNode=(Node*)malloc(sizeof(Node));
	newNode->data=data;

	newNode->next=plist->head->next;//���̳�� ������ �߰�
	plist->head->next=newNode; //���̳�尡 �� ��带 ����Ű�� ��
	(plist->numOfData)++;
}

void LInsert(List*plist, LData data){
	if(plist->comp==NULL)
		FInsert(plist,data);
	else
		SInsert(plist,data);
}

int LFirst(List*plist, LData *pdata){ //��ȸ�Լ�
	if(plist->head->next==NULL)
		return FALSE;
	plist->before=plist->head; //before�� ���̳�带 ����Ű����
	plist->cur=plist->head->next; //cur�� ù ��°(���̳�� ���� ù��°)��带 ����Ű�� ��

	*pdata=plist->cur->data;
	return TRUE;
}

int LNext(List*plist, LData*pdata){
	if(plist->cur->next==NULL)
		return FALSE;
	plist->before=plist->cur; //cur�� ����Ű�� ���� before�� ����Ŵ
	plist->cur=plist->cur->next; //cur�� �� ���� ��带 ����Ŵ

	*pdata=plist->cur->data;
	return TRUE;
}

//LFirst Ȥ�� LNext�Լ��� ��ȯ�� �����͸� �����Ѵ�
LData LRemove(List*plist){
	Node*rpos=plist->cur; //�Ҹ� ����� �ּҰ��� rpos�� ����
	LData rdata=rpos->data; //�Ҹ� ����� �����͸� rdata�� ����
	
	plist->before->next=plist->cur->next;//�Ҹ� ����� ����Ʈ���� ����
	plist->cur=plist->before; //cur�� ����Ű�� ��ġ ������

	free(rpos); //����Ʈ���� ���ŵ� ��� �Ҹ�
	(plist->numOfData)--; //����� ������ �� �ϳ� ����
	return rdata; //���ŵ� ����� ������ ��ȯ

}

int LCount(List*plist){
	return plist->numOfData;
}

void SetSortRule(List*plist, int(*comp)(LData d1, LData d2)){
	plist->comp=comp;
}

void SInsert(List*plist, LData data){
	Node*newNode=(Node*)malloc(sizeof(Node));
	Node*pred=plist->head; //pred�� ���� ��带 ����Ŵ
	newNode->data=data;

	while(pred->next!=NULL && plist->comp(data, pred->next->data)!=0){
//�� ��尡 �� ��ġ�� ã�� ���� �ݺ���(pred�� ������ ��带 ����Ű�� �͵� �ƴϰ�, �� �����Ͱ� �� �ڸ��� ���� ã�� ���ߴٸ� pred�� ���� ���� �̵���Ų��
		pred=pred->next; //���� ���� �̵�
	}
	newNode->next=pred->next; //�� ����� �������� ����
	pred->next=newNode;

	(plist->numOfData)++;
}
