#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100
typedef char element;

typedef struct stack{
	element stack[MAX_STACK_SIZE];
	int top;
}StackType;

void init(StackType*s){
	s->top=-1;
}

int is_empty(StackType*s){
	return(s->top==-1);
}

int is_full(StackType*s){
	return(s->top==MAX_STACK_SIZE-1);
}

void push(StackType*s,element data){

	if(is_full(s)){
		printf("���� ��ȭ ����");
		exit(1);
	}
	else s->stack[++(s->top)]=data;
}

int pop(StackType*s){
	if(is_empty(s)){
		printf("������ �������");
		exit(1);
	}
	else return(s->stack[(s->top)--]);
}

element peek(StackType*s){
	if(is_empty(s)){
		printf("���� ���� ����");
		exit(1);
	}
	else return s->stack[s->top];
}

int prec(char op){ //�������� �켱����
	switch(op){
		case '(': case ')' : return 0;
		case '+': case '-' : return 1;
		case '*': case '/' : return 2;
	}
	return -1;
}

void infix_to_postfix(char exp[]){
	int i=0;
	char ch, top_op;
	int len=strlen(exp);
	StackType s;

	init(&s);
	for(i=0;i<len;i++){
		ch=exp[i];
		switch(ch){
		case '+' : case '-' : case '*' : case '/' : //������
			while(!is_empty(&s) && (prec(ch) <= prec(peek(&s)))) //stack�� �ִ� �������� �켱������ �� ũ�ų� ������ ���
				printf("%c",pop(&s));
			push(&s,ch);
			break;
		case '(': 
			push(&s,ch);
			break;
		case ')'://������ ��ȣ
			top_op=pop(&s);
			while(top_op!='('){ //���� ��ȣ�� ������ ����
				printf("%c",top_op);
				top_op=pop(&s);
			}
			break;
		default:
			printf("%c",ch);//�ǿ�����
			break;
		}
	}
	while(!is_empty(&s))
		printf("%c",pop(&s));
}
			
int main(void){
	infix_to_postfix("(2+3)*4+9");
	return 0;
}