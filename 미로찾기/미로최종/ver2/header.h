#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define NUM_VERTEX 8
#define MAZE_MAX 10

//===================stack data structure======================
typedef struct node__ {
	int x;
	int y;
	struct node__* next;
}node;

typedef struct stack__ {
	node* top;
}stack;


//===================stack data structure end===================

typedef struct point{
	int x;
	int y;
}Point;

typedef struct vertex_{
	int x, y;
	//Point p;//vertex ��ȣ -> �̷ο��� (x,y)��ǥ�� ��ȯ
	struct vertex_*next;//������ ��� vertex�� ����
	struct arcNode_*degree; //arc ����� ������(�ϳ��� ������� ����Ǿ� �ִ� ���� ���� ����)
}vertex;

typedef struct arcNode_{
	//Point p;//��ǥ
	int x,y;
	int arc;//arc ����ġ(������ �������� �Ÿ�)
	struct arcNode_*nextArc;//��� vertex�� ����Ǿ� �ִ� ������ ���� ����
}arcNode;

typedef struct graph_ {
   struct vertex_* start; //��� graph�ϳ��� �� ����� �׷���
}graph;

typedef struct dijkstra{ //���ͽ�Ʈ�� ���̺� ����ü
	int found;//(k)�ִܰŸ��� ã�Ҵ°�? 1=yes, 0=no
	int distance;//�ִܰŸ�(�̷��� �� �����濡�� ���� ����������� �Ÿ�)
	Point prev_vertex;//�ٷ� ������ ��� vertex�� ���ƴ°�(x,y��ǥ)
}Dijkstra;

typedef struct _dtable{
	Point p;//x,y��ǥ
	Dijkstra dij;//���ͽ�Ʈ�� ����ü
}Dtable;

Dtable dtable[NUM_VERTEX];

node* new_node(int x, int y);
void push(stack* s, int x, int y);
void pop(stack* s, int* x, int* y);
stack* create_stack();
int print_arcNode(vertex *v);
void add_edge(vertex* v, char maze[MAZE_MAX][MAZE_MAX]);
void print_graph(graph *g);
vertex* new_vertex(int x, int y);
arcNode* new_arcNode(int arc, int x, int y);
graph* create_graph();
void insert_vertex(graph* g, int x, int y);
void insert_edge(vertex* v, int arc, int x, int y);
void print_graph(graph *g);
void addEdge(Point p, int arc);
void initDTable(vertex*start,int n);
Point findDijkstraNextVertex(int n); // n : vertex ����
void showDTable(int n);
Dtable*d_table(vertex*v);
void updateDTable(vertex*v,int n);//vertex�� ���� �����ν� 
void doDijkstra(vertex*start);