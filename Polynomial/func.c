#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int coef;
	int degree;
	struct node*pre; //���� ��带 ����Ŵ
	struct node*next; //���� ��带 ����Ŵ
}Node;

Node*new_Node(int coef, int degree){
	Node*newNode=(Node*)malloc(sizeof(Node));
	newNode->coef=coef;
	newNode->degree=degree;
	newNode->pre=NULL;
	newNode->next=NULL;

	return newNode;
}

void insert_front(Node**head, int coef, int degree){ //�տ� �߰�
	Node*newNode=new_Node(coef, degree);

	newNode->next=(*head);
	(*head)->pre=newNode;
	(*head)=newNode;	
}

void insert_back(Node**tail, int coef, int degree){
	Node*newNode=new_Node(coef,degree);

	(*tail)->next=newNode;
	newNode->pre=(*tail);
	(*tail)=(*tail)->next;
}

void insert_middle(Node*head, int coef, int degree){
	Node*p=head;
	Node*newNode=new_Node(coef,degree);

	while(p->next->degree>=degree)
		p=p->next;
	if(degree==p->next->degree){
		printf("�̹� ���� \n");
		return;
	}
	
	newNode->coef=coef;
	newNode->degree=degree;

	//p ��ġ ������ ������ ��!
	//newNode�� �޺κ��� p�� next�� ����
	newNode->next=p->next; //���� newNode�� ����� ���� �����Ƿ� newNode�� next�� p�� next�� ����
	p->next->pre=newNode; //p�� next�� pre�� newNode�� ��������
	//newNode�� �պκ��� p�� ����
	newNode->pre=p; 
	p->next=newNode; 
}

void input(Node**head, Node**tail,int co, int de, int n){
	int coe=0,deg=0,i=0;
	Node*p=NULL;
	p=new_Node(coe,deg);
	*head=*tail=p;
	
	if(n>0){ //�Ϲ� ���׽Ŀ� �Է�
		for(i=0;i<n;i++){
			printf("��� : ");
			scanf_s("%d",&coe);
			printf("���� : ");
			scanf_s("%d",&deg);
			p=new_Node(coe,deg);

			//�Լ� ���ڷ� �̹� **�� �������� �ּҸ� �ֱ����� &head, &tail�� �ƴ� head tail�� �Ѱ���!
			if(deg>(*head)->degree) insert_front(head,coe,deg);//�տ� �߰�
			else if(deg<(*tail)->degree) insert_back(tail,coe,deg); //�ڿ� �߰�
			else insert_middle(*head,coe,deg); //�߰��� �߰�
		}
	}
	else{ //result ���׽Ŀ� �ֱ� ����
		printf("����!!!!!!!!!!!!!!!!!");
		if(de>(*head)->degree)
			insert_front(head,co,de);  //�տ� �߰�
		else if(de<(*tail)->degree)
			insert_back(tail,co,de); //�ڿ� �߰�
		else
			insert_middle(*head,co,de); //�߰��� �߰�
	}
}

void output_1(Node*head){ //���� ���� �׺������
	Node*p=NULL;
	p=head;

	printf("���� �������� ");
	printf("%dx^%d",p->coef, p->degree);
	p=p->next;
	while(p->next!=NULL){
		if(p->coef>0){
			printf("+");
			printf("%dx^%d",p->coef, p->degree);
		}
		else
			printf("%dx^%d",p->coef, p->degree);
		p=p->next;
	}
	printf("\n");
}

void output_2(Node*tail){ //���� ���� �׺��� ��� (output1���� next�� pre�� �ٲٸ��
	Node*p=NULL;
	p=tail;

	printf("���� �������� ");
	printf("%dx^%d",p->coef, p->degree);
	p=p->pre;
	while(p!=NULL){
		if(p->coef>0){
			printf("+");
			printf("%dx^%d",p->coef, p->degree);
		}
		else
			printf("%dx^%d",p->coef, p->degree);
		p=p->pre;
	}
	printf("\n");
}

void Poly_Add(Node*head1, Node*head2, Node**head3, Node**tail3){
	Node*newNode1=head1; //��1
	Node*newNode2=head2; //��2
	int sum=0;
	
	//���� ������ ��� �����ְ�
	//�ٸ� ������ ��� ������ ū�� ������, ������ ������ �ڷ� ������ �����ϸ� ����
	
	while(newNode1 && newNode2){ //newNode1, newNode2�߿��� ��� �� ���� NULL�� ����������(����������)
		if(newNode1->degree==newNode2->degree){ // �� �Ŀ��� ������ ���ٸ�
			sum=newNode1->coef+newNode2->coef; //�� ����� ���Ͽ� sum�̶�� ������ �־��ֱ�
			printf("sum : %d\n",sum);
			if(sum!=0){ //�� sum�� 0�� �ƴ϶��
				insert_back(tail3,sum,newNode1->degree);
			}
				newNode1=newNode1->next; //���� ������ �Ѿ��
				newNode2=newNode2->next; //���� ������ �Ѿ��
		}
		else if(newNode1->degree>newNode2->degree){ //������ �ٸ� ���¿��� ù��° ���� ������ �� Ŭ ���
			printf("coef2 : %d\n",newNode1->coef);
			insert_back(tail3,newNode1->coef,newNode1->degree);
			newNode1=newNode1->next; // ������ ���� ���� ���� ���� ������ �Ѿ����
		}
		else{ //�ι�° ���� ������ �� Ŭ ���
			printf("coef3 : %d\n",newNode2->coef);
			insert_back(tail3,newNode2->coef,newNode2->degree);
			newNode2=newNode2->next; //���� ������ �Ѿ����
		}
	}
	//���� �ϳ��� ���� ������ ���� �׵��� �״�� �ڿ� ���̱⸸ �ϸ� ��
	while(newNode1!=NULL){ //newNode1�� �Լ��� ������ ������ �ʾҴٸ� ����������
		input(head3,tail3,newNode1->coef,newNode1->degree,-1); //�������� ����� ������ �״�� �������ֱ�
		newNode1=newNode1->next; //newNode1�� �ݺ����� ���� ��� �������� ����ų �� �ֵ���
	}
	while(newNode2!=NULL){ //newNode2�� �Լ��� ������ ������ �ʾҴٸ� ����������
		input(head3,tail3,newNode2->coef,newNode2->degree,-1); //�������� ����� ������ �״�� ����
		newNode2=newNode2->next; //newNode2�� �ݺ����� ���� ��� �������� ����ų �� �ֵ���
	}
}

void Poly_Sub(Node*head1, Node*head2, Node**head3, Node**tail3){
	Node*newNode1; //��1
	Node*newNode2; //��2
	int sub=0;

	newNode1=head1;
	newNode2=head2; //���� ó������ search�ϱ� ����
	
	//���� ������ ��� �����ְ�
	//�ٸ� ������ ��� ������ ū�� ������, ������ ������ �ڷ� ������ �����ϸ� ����
	
	while(newNode1 && newNode2){ //newNode1, newNode2�߿��� ��� �� ���� NULL�� ����������(����������)
		if(newNode1->degree==newNode2->degree){ // �� �Ŀ��� ������ ���ٸ�
			sub=newNode1->coef-newNode2->coef; //�� ����� ���Ͽ� sum�̶�� ������ �־��ֱ�
			if(sub!=0){ //�� sub�� 0�� �ƴ϶��
				input(head3,tail3,sub,newNode1->degree,-1);
				newNode1=newNode1->next; //���� ������ �Ѿ��
				newNode2=newNode2->next; //���� ������ �Ѿ��
			}
		}
		else if(newNode1->degree>newNode2->degree){ //������ �ٸ� ���¿��� ù��° ���� ������ �� Ŭ ���
			input(head3,tail3,newNode1->coef,newNode1->degree,-1);//�״�� ����� ����Ʈ�� �� ū ������ ����� �־��ش�
			newNode1=newNode1->next; // ������ ���� ���� ���� ���� ������ �Ѿ����
		}
		else{ //�ι�° ���� ������ �� Ŭ ���(-���̰� �־��ֱ�)
			input(head3,tail3,(-newNode2->coef),newNode2->degree,-1); 
			newNode2=newNode2->next; //���� ������ �Ѿ����
		}
	}
	//���� �ϳ��� ���� ������ ���� �׵��� �״�� �ڿ� ���̱⸸ �ϸ� ��
	while(newNode1!=NULL){ //newNode1�� �Լ��� ������ ������ �ʾҴٸ� ����������
		input(head3,tail3,newNode1->coef,newNode1->degree,-1); //�������� ����� ������ �״�� �������ֱ�
		newNode1=newNode1->next; //newNode1�� �ݺ����� ���� ��� �������� ����ų �� �ֵ���
	}
	while(newNode2!=NULL){ //newNode2�� �Լ��� ������ ������ �ʾҴٸ� ����������
		input(head3,tail3,(-newNode2->coef),newNode2->degree,-1); //�������� ����� -�� ���̰� ������ �״�� ����
		newNode2=newNode2->next; //newNode2�� �ݺ����� ���� ��� �������� ����ų �� �ֵ���
	}
}
