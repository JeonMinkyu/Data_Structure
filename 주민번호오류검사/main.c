#include<stdio.h>

void check_ID(char id[14],char weight[13]);

int main(void){
	int i=0,j=0;
	char id[14]={0};
	char weight[13]={'2','3','4','5','6','7','8','9','2','3','4','5'}; // ����ġ
	int sum=0;

	printf("�ֹε�Ϲ�ȣ�� �Է��Ͻÿ� : ");
	scanf_s("%s",id,sizeof(id));

	check_ID(id,weight);


	return 0;
}

void check_ID(char id[14],char weight[13]){

	int i=0,j=0;
	int check=0;
	int sum=0;

	printf("�ֹι�ȣ�� ������ �˻��մϴ�. %s\n",id);

	for(i=0;i<12;i++){
		sum+=((id[i]-'0')*(weight[i]-'0'));
	}

	check=(11-(sum%11))%10;
	printf("�ֹι�ȣ ������ : %c\n",id[12]);
	printf("check : %d\n",check);
	if(check==(id[12]-'0'))
		printf("correct!!");
	else printf("False!!");
}