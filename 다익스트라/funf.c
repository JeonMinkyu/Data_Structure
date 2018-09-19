#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define NUM_VERTEX 5
#define NUM_EDGES 8

typedef struct point{
	int x;
	int y;
}Point;

typedef struct vertex{
	Point p;//vertex ��ȣ -> �̷ο��� (x,y)��ǥ�� ��ȯ
	struct vertex*next;//������ ��� vertex�� ����
	struct arcnode*degree; //arc ����� ������(�ϳ��� ������� ����Ǿ� �ִ� ���� ���� ����)
}Vertex;

typedef struct arcnode{
	Point p;//��ǥ
	int arc;//arc ����ġ(������  �������� �Ÿ�)
	struct arcnode*next_arc;//��� vertex�� ����Ǿ� �ִ� ������ ���� ����
}ArcNode;

typedef struct dijkstra{ //���ͽ�Ʈ�� ���̺� ����ü
	int found;//(k)�ִܰŸ��� ã�Ҵ°�? 1=yes, 0=no
	int distance;//�ִܰŸ�(�̷��� �� �����濡�� ���� ����������� �Ÿ�)
	int prev_vertex;//�ٷ� ������ ��� vertex�� ���ƴ°�(x,y��ǥ)
}Dijkstra;

typedef struct _dtable{
	Point p;//x,y��ǥ
	Dijkstra dij;//���ͽ�Ʈ�� ����ü
}Dtable;

Dtable dtable[NUM_VERTEX]; //ǥ�� vertex ������ŭ �־����

//Vertex* new_vertex(Point p);
//ArcNode* new_arcNode(int arc, Point p);
//void insert_vertex(graph* g, Point p);
//void insert_edge(vertex* v, int arc, Point p);
//void print_vertex(graph* g);
void addEdge(Point p1, Point p2, int arc); //p1 : ��� vertex, p2 : ���� vertex, arc : ����ġ, ����
void initDTable();
Point findDijkstraNextVertex();
void showDTable();
void updateDTable(Point p);
void doDijkstra(Point p);