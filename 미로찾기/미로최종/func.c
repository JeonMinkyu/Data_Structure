#include "header.h"

void init_q(Queue *q) {

	q->front = q->rear = NULL;
}

int q_is_empty(Queue *q) {

	return (q->front == NULL);

}

void enqueue(Queue *q, int x, int y) {

	QueueNode *node = (QueueNode*)malloc(sizeof(Queue));
	if (node == NULL) printf("�޸� �Ҵ� ����\n");
	else {
		node->next = NULL;
		node->x = x;
		node->y = y;

		if (q_is_empty(q)) {
			q->front = node;
			q->rear = node;
		}
		else {
			q->rear->next = node;
			q->rear = node;
		}
	}
}

Point dequeue(Queue *q) {

	QueueNode *tmp = q->front;
	Point item;
	if (q_is_empty(q)) printf("ť�� ��� �ֽ��ϴ�.\n");
	else {

		item.x = tmp->x;
		item.y = tmp->y;

		q->front = q->front->next;
		if (q->front == NULL)
			q->rear = NULL;

		return item;
	}

}


node* new_node(int x, int y) {
	node* tmp = (node*)malloc(sizeof(node));
	tmp->x = x;
	tmp->y = y;
	tmp->next = NULL;

	return tmp;
}

void push(stack* s, int x, int y) {
	node* tmp = new_node(x, y);

	tmp->next = s->top;
	s->top = tmp;
}

void pop(stack* s, int* x, int* y) {
	node* tmp;
	if (s->top == NULL)
		printf("pop error");
	else {
		*x = s->top->x;
		*y = s->top->y;
		tmp = s->top;
		s->top = s->top->next;
		free(tmp);
	}
}

stack* create_stack() {
	stack *tmp = (stack*)malloc(sizeof(stack));
	tmp->top = NULL;

	return tmp;
}

vertex* new_vertex(int x, int y) {
	vertex* tmp = (vertex*)malloc(sizeof(vertex));
	tmp->degree = NULL;
	tmp->next = NULL;
	tmp->x = x;
	tmp->y = y;

	return tmp;
}

arcNode* new_arcNode(int arc, int x, int y) {
	arcNode* tmp = (arcNode*)malloc(sizeof(arcNode));
	tmp->nextArc = NULL;
	tmp->x = x;
	tmp->y = y;
	tmp->arc = arc;

	return tmp;
}

graph* create_graph() {
	graph* g = (graph*)malloc(sizeof(graph));
	g->start = NULL;
	return g;
}

void insert_vertex(graph* g, int x, int y) {
	vertex* tmp = new_vertex(x, y);
	vertex* check;

	if (g->start == NULL) {
		g->start = tmp;
	}
	else {
		check = g->start;
		while (check->next != NULL) {
			check = check->next;
		}
		check->next = tmp;
	}
}
//add vertex to graph

void insert_edge(vertex* v, int arc, int x, int y) {
	arcNode* tmp = new_arcNode(arc, x, y);
	arcNode* check;

	if (v->degree == NULL) {
		v->degree = tmp;
	}
	else {
		check = v->degree;
		while (check->nextArc != NULL) {
			check = check->nextArc;
		}
		check->nextArc = tmp;
	}
}
//add edge to vertex

int print_arcNode(vertex *v) {
	arcNode *tmp = v->degree;

	if (tmp == NULL) return -1;

	printf("(%d, %d)  %d  ", tmp->x, tmp->y, tmp->arc);
	while (tmp->nextArc != NULL) {

		tmp = tmp->nextArc;
		printf("(%d, %d)  %d  ", tmp->x, tmp->y, tmp->arc);

	}

	printf("\n");

	return 0;

}

void print_graph(graph *g) {
	vertex* tmp = g->start;

	printf("(%d, %d)     ", tmp->x, tmp->y);
	print_arcNode(tmp);
	while (tmp->next != NULL) {
		tmp = tmp->next;
		printf("(%d, %d)     ", tmp->x, tmp->y);

		if (print_arcNode(tmp) == -1) printf("\n");

	}

}

void add_edge(vertex* v, char maze[MAZE_MAX][MAZE_MAX]) {
	stack* s = create_stack();
	char copy[MAZE_MAX][MAZE_MAX];
	int x, y;
	int i, j, k;
	int count;	//�������� ������ �Ǻ��ϴ� ����
	int length; // vertex���� �Ÿ��� ��� ����

	for (i = 0; i < MAZE_MAX; i++) {
		for (j = 0; j < MAZE_MAX; j++) {
			copy[i][j] = maze[i][j];
		}
	}

	copy[v->y][v->x] = 'e';

	if (copy[v->y - 1][v->x] == '0')
		push(s, v->y - 1, v->x);
	if (copy[v->y + 1][v->x] == '0')
		push(s, v->y + 1, v->x);
	if (copy[v->y][v->x - 1] == '0')
		push(s, v->y, v->x - 1);
	if (copy[v->y][v->x + 1] == '0')
		push(s, v->y, v->x + 1);
	//v�� �������� ���������� ���ÿ� push

	while (s->top != NULL) {
		pop(s, &y, &x);	//�� �߿� �ϳ��� pop �ϰ�
		length = 0;

		while (1) {	//���� vertex������ ���� ã�ư���
			copy[y][x] = 'e';
			count = 0;

			if (y - 1 >= 0) {
				if (copy[y - 1][x] == '0') {
					push(s, y - 1, x);
					count++;
				}
			}
			if (y + 1 < MAZE_MAX) {
				if (copy[y + 1][x] == '0') {
					push(s, y + 1, x);
					count++;
				}
			}
			if (x - 1 >= 0) {
				if (copy[y][x - 1] == '0') {
					push(s, y, x - 1);
					count++;
				}
			}
			if (x + 1 < MAZE_MAX) {
				if (copy[y][x + 1] == '0') {
					push(s, y, x + 1);
					count++;
				}
			}
			length++;

			if (count > 1 || count == 0) {
				insert_edge(v, length, x, y);

				for (k = 0; k < count; k++) {
					pop(s, &y, &x);
				}

				break;
			}	//vertex�� ã������ �׷����� �߰��ϰ� ���� ������� ����
			else
				pop(s, &y, &x);

		}
	}
}


//============�̷� ���=============

void printMaze(char m[MAZE_MAX][MAZE_MAX])
{
	int i=0,j=0;
	for (i = 0; i < MAZE_MAX; i++) {
		for (j = 0; j < MAZE_MAX; j++) {
			switch (m[i][j]) {
			case '1':   //��
				printf("��");   break;
			case '0':   //��
				printf("  ");   break;
			default:
				printf(" %c", m[i][j]);
			}
		}
		printf("\n");
	}
}
//==========dfs==========
vertex *search_v(graph *g, int x, int y) {//vertex ��带 ã���ִ� �Լ�. vertex�� ����Ǿ� �ִ� arcNode�� ���󰡴� �ش� arcNode�� ���� x,y���� ������ �ִ� vertex���� ã�� �������ش�.
	vertex *v;
	v = g->start;
	while (v != NULL) {
		if (v->x == x && v->y == y) {//�Էµ� ��ǥ���� ���� vertex�� ������
			return v;//v ����
		}
		else {
			v = v->next;//���ö����� �� ���� vertex�� �ű�
		}
	}
	return NULL;
}

int check_exist(stack* s, int x, int y) {//���ÿ� �ش� ��尡 �����ϴ��� Ȯ���ϴ� �Լ�
	node* curr = s->top;
	while (curr != NULL) {
		if (curr->x == x && curr->y == y) {//�Էµ� ��ǥ���� ���� ���
			return 1;
		}
		curr = curr->next;//ã���� ���� ���� ��� Ȯ��
	}
	return 0;
}

void print_stack2(node *node) {//����Լ��� ���� ������ �� ���������� �ش� x,y���� ����ϰ� ���ش�
	if (node == NULL) {
		return;
	}
	print_stack2(node->next);
	printf("(%d %d)", node->x, node->y);
}

void print_stack(stack* s) {
	//node* node = s->top;
	//printf("print path\n");
	//while (node != NULL) {
	//   printf("(%d %d) ", node->x, node->y);
	//   node = node->next;
	//}
	print_stack2(s->top);
}

void DFS(graph *g) {
	int x, y;      //����
	stack* s;   //��带 ���� ���� ����
	vertex* init_node;
	node* current_node ;
	s = (stack*)malloc(sizeof(stack));   //���� �Ҵ�
	s->top = NULL;

	init_node = g->start;      //�׷����� ���۳��� init_node�� ���ٰ� ����
	push(s, init_node->x, init_node->y);      //ó�� ���� �̷��� �Ա��̹Ƿ� ������ ���ÿ� push
	current_node = s->top;   //������ ���� ��带 ����Ű�� current node


	while (current_node != NULL) {// ���� ��尡 0�� �ƴҶ�
		vertex* find_degree_from = search_v(g, current_node->x, current_node->y);   //search_v�� ���� ã�� current �� ���� ��ǥ�� ���� vertex�� ����
		arcNode* next_edge = find_degree_from->degree;   //find_degree_from�� ����� arcNode�� next_edge�� ����

		while (next_edge != NULL && check_exist(s, next_edge->x, next_edge->y)) {      //next_edge�� null�� �ƴϰ�, ���ÿ� �����Ѵٸ�
			next_edge = next_edge->nextArc;      //���� arcNode�� �Ѿ
		}

		if (next_edge == NULL) {      //arc Node��尡 ���̻� ���ٸ� (���� ��θ� ã�� �� ����)
			pop(s, &x, &y); //->??? x, y ���� ��� �˾ƿ�..?
			current_node = s->top;
		}
		else {      //arcNode ��尡 ���� ���(���� ��θ� ã�� �� �ִ�)
					//printf("push %d %d\n", next_edge->x, next_edge->y);
			find_degree_from->degree = next_edge->nextArc;   //������ ���� �Ѿ
			push(s, next_edge->x, next_edge->y);   //���ÿ� push
			current_node = s->top;
			if (next_edge->x == 9 && next_edge->y == 8) {   //�̷� Ż�⿡ �������� ���
				printf("DFS result : ");
				print_stack(s);   //��� ���
				break;
			}
		}
	}
}

//====bfs====
void bfs(graph *g) {//������� ��ǥ

	vertex* v, *check;
	arcNode *w;
	Point item;
	int x, y;

	Queue q;
	init_q(&q);

	v = g->start;
	x = v->x;
	y = v->y;

	visited[x][y] = 1;
	pre[x][y].x = -2;
	pre[x][y].y = -2;
	//printf("%d, %d\n", x, y);

	enqueue(&q, x, y);


	while (!q_is_empty(&q)) {

		item = dequeue(&q);
		x = item.x;
		y = item.y;

		for (v = g->start; v->x != x||v->y != y; v = v->next);

		for (w = v->degree; w != NULL; w = w->nextArc) {

			if (visited[w->x][w->y] == 0) {
				visited[w->x][w->y] = 1;
				//printf("%d, %d\n", w->x, w->y);
				enqueue(&q, w->x, w->y);
			}
			if(pre[x][y].x!=w->x&&pre[x][y].y != w->y)
				if (dis[w->x][w->y] == 0 || dis[w->x][w->y] > dis[x][y] + w->arc) {
					dis[w->x][w->y] = dis[x][y] + w->arc;
					pre[w->x][w->y].x = x;
					pre[w->x][w->y].y = y;
				}
		}
	}
}

//========dijkstra========
void initDTable(vertex*start,int n){ //���̺� �ʱ�ȭ(���̺� ������ ��������X, vertex ������ŭ ����� ��)->vertex������ n���� ������!
	int i=0;
	vertex*tmp=start;
	vertex*pre=start;
	dtable[i].p.x=tmp->x;
	dtable[i].p.x=tmp->x;
	dtable[i].p.y=tmp->y;
	dtable[i].dij.found=0;
	dtable[i].dij.distance=0;//�ּڰ����� �ٷ� ��ü�� �� �ֵ���
	dtable[i].dij.prev_vertex.x=-1;//������ ���Ŀ°� ����(�ʱ�ȭ�ϱ�),(x,y)��ǥ��!
	dtable[i].dij.prev_vertex.y=-1;
	
	while (tmp->next != NULL) {
		i++;
		tmp = tmp->next;
		dtable[i].p.x=tmp->x;
		dtable[i].p.y=tmp->y;
		dtable[i].dij.found=0;
		dtable[i].dij.distance=9999;//�ּڰ����� �ٷ� ��ü�� �� �ֵ���
		dtable[i].dij.prev_vertex.x=-1;
		dtable[i].dij.prev_vertex.y=-1;
	}
}

//���� �ִܰŸ��� �������� ���� vertex �� ���� ���� distance�� ���� vertex ��ȯ
//��� vertex�� �ִܰŸ��� �˷�������� return -1
Point findDijkstraNextVertex(int n){
	int i=0;
	int smallest_distance=9999;//���� ª������ �Ÿ�(�̷ο��� �������� �������� �ɸ� �Ÿ�)
	Point smallest_vertex={-1,-1};//���� ª������ vertex��ȣ(x,y��ǥ)
	
	for(i=0;i<n;i++){//table�� �� ������
		if((dtable[i].dij.found==0) && (dtable[i].dij.distance<smallest_distance)){//���� ���� ª�� ���� �������� �ʾҰ� �˷��� ���̺��� �� ���� ���̰� �ִٸ�
			smallest_vertex.x=dtable[i].p.x;//smallest_distance���� ���� �Ÿ��̹Ƿ� smallest_vertex, �̷ο� �����Ѵٸ�...dtable�� i��° ��ǥ���� �־��ֱ�
			smallest_vertex.y=dtable[i].p.y;
			smallest_distance=dtable[i].dij.distance;
		}
	}//���ǹ��� ������� ���ϸ�(�� �̹� �˷����ִٸ�) (-1,-1)��ȯ
	return smallest_vertex;
}

void showDTable(int n){
	int i=0;
	printf("dtable\n");
	printf(" ���� ��ǥ| ã�Ҵ°� �ִ� �Ÿ� �ٷ� �� ��ǥ \n");
	for(i=0;i<n;i++){
		printf(" (%d,  %d)  |  %4d    %6d     (%d %d) \n",dtable[i].p.x, dtable[i].p.y ,dtable[i].dij.found, dtable[i].dij.distance, dtable[i].dij.prev_vertex.x, dtable[i].dij.prev_vertex.y);
	}
}

//�ִܰŸ��� �˷��� vertex�� ���� �� ���ο� vertex�� �����ν� ���� �� �� �ִ� ���(vertex)�� ã��(v�� �پ��ִ� ���� �̿�)
void updateDTable(vertex*v,int n){//v�� update�� vertex, n�� vertex�� ����(���̺� ��) , vertex v�� ����� ��� arc�� �˻��ؾ���
	int i=0,t=0,p=0;
	vertex*cur_ver=v;
	arcNode*cur_arc=v->degree;//cur���� vertex�� �ش��ϴ� arc������ ��
	
	for(i=0;i<n;i++){//���� vertex v�� dtable�� ��ġ=t
		if((v->x==dtable[i].p.x) && (v->y==dtable[i].p.y))
			t=i;
	}
	//�ִܰŸ��� �˷����� �ʾҰ�,(found==0)
	//���� �˷��� �Ÿ����� t�� ���Ұ�찡 �� ������, dtable�� ������Ʈ
	while(cur_arc!=NULL){
		for(i=0;i<n;i++){
			if((dtable[i].p.x==cur_arc->x) && (dtable[i].p.y==cur_arc->y))//table���� �ش��ϴ� ��ġ�� ã�Ƽ�
				p=i;
		}
		if((dtable[p].dij.found==0) && (dtable[p].dij.distance > dtable[t].dij.distance+cur_arc->arc)){
			dtable[p].dij.distance=dtable[t].dij.distance+cur_arc->arc; //v�� ���ļ� ���� �Ÿ�
			dtable[p].dij.prev_vertex.x=v->x;//���� ��忡 p �ֱ�
			dtable[p].dij.prev_vertex.y=v->y;
		}
		cur_arc=cur_arc->nextArc; //�� vertex ������ arc�� ã�� ����
	}
}

void doDijkstra(vertex*start){ // start : ������ vertex
	int i=0,j=0,t=0;
	vertex*cur=start;
	Point next_vertex={start->x,start->y};
	
	while((next_vertex.x=findDijkstraNextVertex(8).x)!=-1 && (next_vertex.y=findDijkstraNextVertex(8).y)!=-1){//ã�����	
		for(j=0;j<8;j++){
			if((dtable[j].p.x==next_vertex.x) && (dtable[j].p.y==next_vertex.y))
				t=j;
		}//next_vertex�� �ش��ϴ� ���̺� ��ġ ã�Ƽ�
		dtable[t].dij.found=1;//ã�� ���� 1�� �ֱ�(ã�Ҵٴ°� ǥ��)
		while((cur->x!=next_vertex.x) || (cur->y!=next_vertex.y))//update�Լ��� �־��� vertex ã������(�ϳ��� �޶� �ٸ��Ŵϱ�)
			cur=cur->next;
		updateDTable(cur,8);//dtable ������Ʈ(���� ��κ��� ª�� ���� �߰ߵǸ� ��ü)
	}
	showDTable(8);
}
//========dijkstra-----------

void print_path(int x, int y) {//���� ��ǥ �Է�

	if (pre[x][y].x == -1 && pre[x][y].y == -1) {

		printf("������������ ��ΰ� �������� �ʽ��ϴ�.\n");
		return;
	}
	if (pre[x][y].x == -2 && pre[x][y].y == -2) {

		printf("BFS Ž�� �ִ� ��� : (%d, %d)", x, y);
		return;

	}
	print_path(pre[x][y].x, pre[x][y].y);
	printf("  (%d, %d)", x, y);

}