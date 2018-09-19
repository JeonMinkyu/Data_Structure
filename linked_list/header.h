typedef struct Node{
	int data;
	struct Node*next;
}Node;

int show_menu(); //�޴� ���
Node*new_node(); //��� ����
int ListLength(Node*head); //����Ʈ ���� ���
void insert_front(Node**head, int data); //list �տ� ����
void insert_back(Node**tail,int data); //list �ڿ� ����
void insert_middle(Node*head,int data); //list �߰��� ����
int search(Node*head,int data); //���ϴ� ���� index���
void Delete(Node**head, Node**tail, int data); //����
void show(Node*head); //���� ���� ���
int isEmpty(Node*head); //����ִ� ���� ���