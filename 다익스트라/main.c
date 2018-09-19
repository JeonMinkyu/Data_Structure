#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define NUM_VERTEX 5
#define NUM_EDGES 8

typedef struct point{
	int x;
	int y;
}Point;

typedef struct node{
	int v;//vertex ��ȣ -> �̷ο��� (x,y)��ǥ�� ��ȯ
	int weight; //����ġ(������ �������� �Ÿ�)
	struct node*next;//up,down,left,right
}Node; //�׷������� ������

typedef struct dijkstra{ //���ͽ�Ʈ�� ���̺� ����ü
	int found;//(k)�ִܰŸ��� ã�Ҵ°�? 1=yes, 0=no
	int distance;//�ִܰŸ�(�̷��� �� �����濡�� ���� ����������� �Ÿ�)
	int prev_vertex;//�ٷ� ������ ��� vertex�� ���ƴ°�(x,y��ǥ)
}Dijkstra;

Dijkstra dtable[NUM_VERTEX]; //ǥ�� vertex ������ŭ �־����
Node*graph[NUM_VERTEX];

//vertex�湮���� ǥ�� �迭
//if visited[i]==1, visited
//				 0, otherwise
int visited[NUM_VERTEX]={0};

void addEdge(int v1, int v2, int w){//v1 : ���vertex , v2 : ����vertex , w : ����ġ
	Node*new_one=(Node*)malloc(sizeof(Node));
	Node*cur=graph[v1];//v1���� ����ϴ� ���� �̷���� graph

	new_one->v=v2;
	new_one->next=NULL;
	new_one->weight=w;

	if(cur==NULL)//v1�� �ƹ� vertex�� �پ����� ���� ����
		graph[v1]=new_one;
	else{//v1�� �̹� �ٸ� vertex�� �پ��ִ� ����
		while(cur->next!=NULL)//������ ������
			cur=cur->next;//��� �����ɷ� �Ѿ�鼭
		cur->next=new_one;//�� �Ѿ���� �� �������� ��� ����
	}
}//�ᱹ ���ο� ��带 �׷����� �������ִ� �Լ�

void initDTable(){ //���̺� �ʱ�ȭ
	int i=0;
	for(i=0;i<NUM_VERTEX;i++){//VERTEX ������ŭ �ʱ�ȭ
		dtable[i].found=0;//��ã�� ����
		dtable[i].distance=9999;//�ּڰ����� �ٷ� ��ü�� �� �ֵ���
		dtable[i].prev_vertex=-1;//������ ���Ŀ°� ����(�ʱ�ȭ�ϱ�),(x,y)��ǥ��!
	}
}

//���� �ִܰŸ��� �������� ���� vertex �� ���� ���� distance�� ���� vertex ��ȯ
//��� vertex�� �ִܰŸ��� �˷�������� return -1
int findDijkstraNextVertex(){
	int i=0;
	int smallest_distance=9999;//���� ª������ �Ÿ�(�̷ο��� �������� �������� �ɸ� �Ÿ�)
	int smallest_vertex=-1;//���� ª������ vertex��ȣ(x,y��ǥ)

	for(i=0;i<NUM_VERTEX;i++){//table�� �� ������
		if((dtable[i].found==0) && (dtable[i].distance<smallest_distance)){//���� ���� ª�� ���� �������� �ʾҰ� �˷��� ���̺��� �� ���� ���̰� �ִٸ�
			smallest_vertex=i;//smallest_distance���� ���� �Ÿ��̹Ƿ� smallest_vertex, �̷ο� �����Ѵٸ�...'���° �̷� ������'�̶�� ������ �����ұ�(����ü�� ���� �ϳ� �� �߰��ϰ� ���������� �����ϸ� �����Ҽ���?)
			smallest_distance=dtable[i].distance;
		}
	}//���ǹ��� ������� ���ϸ�(�� �̹� �˷����ִٸ�) -1��ȯ
	return smallest_vertex;
}

void showDTable(){
	int i;
	for(i=0;i<NUM_VERTEX;i++){
		printf("%d : %d %d %d \n",i,dtable[i].found, dtable[i].distance, dtable[i].prev_vertex);
	}
}

//�ִܰŸ��� �˷��� vertex�� ���� �� v�� �����ν� ���� �� �� �ִ� ���(vertex)�� ã��(v�� �پ��ִ� ���� �̿�)
void updateDTable(int v){//v�� �پ��ִ� ��带 �̿��ؼ�..! 
	Node*cur=graph[v]; //v�� ����� ��� ��� ã�Ƽ�
	
	while(cur!=0){
		//�ִܰŸ��� �˷����� �ʾҰ�,(found==0)
		//���� �˷��� �Ÿ����� v�� ���Ұ�찡 �� ������, dtable�� ������Ʈ
		if(dtable[cur->v].found==0 && (dtable[cur->v].distance>dtable[v].distance+cur->weight)){
			dtable[cur->v].distance=dtable[v].distance+cur->weight; //v�� ���ļ� ���� �Ÿ�
			dtable[cur->v].prev_vertex=v;//���� ��忡 v �ֱ�
		}
		cur=cur->next;
	}
}

void doDijkstra(int v){ // v : ��𼭺��� ã�� ��������
	int next_vertex=-1;//�ִܰŸ��� ������ vertexã��
	dtable[v].distance=0;//���� ���̺��� �ٷ�0(�����ϴ� vertex�� �ִܰŸ��� 0)

	while((next_vertex=findDijkstraNextVertex())!=-1){//ã�����
		dtable[next_vertex].found=1;//�ִܰŸ��� ã�Ҵٰ� ǥ��
		updateDTable(next_vertex);//dtable ������Ʈ(���� ��κ��� ª�� ���� �߰ߵǸ� ��ü)
	}
	showDTable();
}

int main(){

	addEdge(0,1,1); //������ 1 : reverse�����ϵ���(�����... but �̷δ� ����� ������ ����)
	addEdge(0,2,3);
	addEdge(0,4,5);
	addEdge(1,2,2);
	addEdge(1,4,4);
	addEdge(2,4,6);
	addEdge(2,3,7);
	addEdge(3,4,8);

	initDTable();

	doDijkstra(0);//0������ ���� ��� �ִܰŸ� ã��(��ȣ ���� ���� 1,2,..����������� �޶���)
}