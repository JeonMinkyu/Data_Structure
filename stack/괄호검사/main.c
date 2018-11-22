#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack{
	char stack[100];
	int top;
}StackType;

void init(StackType*s){
	s->top=-1;
}

int is_empty(StackType*s){
	return (s->top==-1);
}

int is_full(StackType*s){
	return(s->top == 99);
}

void push(StackType*s, char item){
	if(is_full(s)){
		printf("���� ��ȭ ����\n");
		exit(1);
	}
	else
		s->stack[++(s->top)]=item;
}

char pop(StackType*s){
	if(is_empty(s)){
		printf("������ ������ϴ�\n");
		exit(1);
	}
	else
		return s->stack[(s->top)--];
}

int check(char*input){
	StackType s;
	char a, b;
	int i=0,n=strlen(input);
	init(&s);
	for(i=0;i<n;i++){//���ڿ� ���̸�ŭ �ݺ��� ���鼭
		a=input[i];
		switch(a){
		case '(':
		case '{':
		case '[':
			push(&s,a);
			break;
		case ')':
		case '}':
		case ']':
			if(is_empty(&s)){ //stack�� ����־��ٸ�
				return -1;
			}
			else{
				b=pop(&s);
				if(b=='(' && a!=')' || b=='{' && a!='}' || b == '[' && a!=']'){//�ݴ°�ȣ�� ������ȣ�� ¦�� �´���!(�ȸ����� ����)
					return -1;
				}
				else
					break;
			}
		}
	}
	
	if(is_empty(&s))
		return 0;
	else
		return -1;
}

int main(void){
	int i=0;
	char input[100]={'0'};

	printf("���ڿ� �Է� : ");
	fgets(input,100,stdin);
	
	if(check(input)==0) printf("��ȣ�� ������");
	else printf("��ȣ�� �������� ����");

	return 0;
}
