#include "header.h"

int main(void) {

	char maze[MAZE_MAX][MAZE_MAX] = {
	{ '1', '1', '1', '1', '1', '1', '1', '1', '1', '1' },
	{ '0', '0', '0', '0', '1', '1', '0', '0', '0', '1' },
	{ '1', '0', '1', '0', '1', '0', '0', '1', '0', '1' },
	{ '1', '0', '1', '1', '0', '0', '1', '1', '0', '1' },
	{ '1', '0', '0', '0', '0', '1', '1', '1', '0', '1' },
	{ '1', '0', '1', '1', '0', '0', '1', '1', '0', '1' },
	{ '1', '0', '0', '1', '1', '0', '1', '1', '0', '1' },
	{ '1', '1', '0', '0', '1', '0', '0', '0', '0', '1' },
	{ '1', '1', '1', '0', '0', '0', '1', '1', '0', '0' },
	{ '1', '1', '1', '1', '1', '1', '1', '1', '1', '1' },
	};

	int countZero;
	int i, j;
	graph* g = create_graph();
	vertex* tmp;	
	//Dtable *dtable[NUM_VERTEX];
	//maze[j][i]; i = x, j = y;
	for (i = 0; i < MAZE_MAX; i++) {
		for (j = 0; j < MAZE_MAX; j++) {
			if (i == 0 || j == 0) {
				if (maze[j][i] == '0') 
					insert_vertex(g, i, j);
			}
			//start point, end point
			else {
				if (maze[j][i] == '0') {
					countZero = 0;
					if (maze[j - 1][i] == '0')
						countZero++;
					if (maze[j][i - 1] == '0')
						countZero++;
					if (maze[j + 1][i] == '0')
						countZero++;
					if (maze[j][i + 1] == '0')
						countZero++;

					if (countZero > 2 || countZero == 1) {
						insert_vertex(g, i, j);
					}
				}
			}
			//check 4-direction
		}
	}
	//ó�� vertex���� �׷����� �߰���

	tmp = g->start;

	add_edge(tmp, maze);
	while (tmp->next != NULL) {
		//printf("%d, %d\n",tmp->p.x, tmp->p.y);
		tmp = tmp->next;
		add_edge(tmp, maze);
	}
	//printf("%d, %d\n",tmp->p.x, tmp->p.y);
	
	//�� vertex�� ���鼭 ����� arcNode���� �߰���
	//printf("!!");
	initDTable(g->start,8);
	doDijkstra(g->start);//0������ ���� ��� �ִܰŸ� ã��(��ȣ ���� ���� 1,2,..����������� �޶���)
	//printf("~~");

	print_graph(g);

	system("pause");
	return 0;
}