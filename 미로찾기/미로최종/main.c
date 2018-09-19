#include "header.h"

int main() {

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

	//print_vertex(g);

	tmp = g->start;

	add_edge(tmp, maze);
	while (tmp->next != NULL) {
		tmp = tmp->next;
		add_edge(tmp, maze);
	}
	//�� vertex�� ���鼭 ����� arcNode���� �߰���

	/*tmp = g->start;

	print_edge(tmp);
	while (tmp->next != NULL) {
	tmp = tmp->next;
	print_edge(tmp);
	}*/

	print_graph(g);

	//print�� vertex edge ���ļ� ����ϵ��� �ٲ� �� ����
	//�ٸ� ���� �÷��ּ���

	system("pause");

	printMaze(maze);

	bfs(g);
	print_path(9, 8);
	printf("\n");

	DFS(g);
	printf("\n");
	
	initDTable(g->start,8);
	doDijkstra(g->start);//0������ ���� ��� �ִܰŸ� ã��(��ȣ ���� ���� 1,2,..����������� �޶���)
	
	return 0;

}