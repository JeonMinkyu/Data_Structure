typedef struct node{
	int coef;
	int degree;
	struct node*pre; //���� ��带 ����Ŵ
	struct node*next; //���� ��带 ����Ŵ
}Node;

Node*new_Node(int coef, int degree);
void insert_front(Node**head, int coef, int degree);
void insert_back(Node**tail, int coef, int degree);
void insert_middle(Node*head, int coef, int degree);
void input(Node**head, Node**tail,int co, int de, int n);
void output_1(Node*head);
void output_2(Node*tail);
void Poly_Add(Node*head1, Node*head2, Node**head3, Node**tail3);
void Poly_Sub(Node*head1, Node*head2, Node**head3, Node**tail3);

