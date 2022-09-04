#include <stdio.h>
#define Max_Vertices 20  //cap phat o nho cho mang 2 chieu cua Graph
#define Max_Length 20 	 // cap phat o nho cho mang 1 chieu cua List
#define Max_Element 40   // cap phat o nho cho mang 1 chieu cua Queue

//--------------------khai bao cau truc Graph------------------
typedef struct {
	int a[Max_Vertices][Max_Vertices]; //ma tran dinh - dinh
	int n;                            //so luong dinh
}Graph;

void init_G (Graph *G, int n) { // khoi tao Graph
	int i, j;
	G->n = n;
	for (i=1; i<=n; i++) {
		for (j=1; j<=n; j++) {
			G->a[i][j] = 0;
		}
	}
}

void add_edge (Graph *G, int x, int y) { // them cung vao Graph
	G->a[x][y] = 1;
	G->a[y][x] = 1;
}

int adjacent (Graph *G, int x, int y) { // kiem tra dinh x, y co la lang gieng cua nhau khong ?
	return G->a[x][y] != 0;
}

int degree (Graph *G, int x) { // tinh bac cua cac dinh trong Graph
	int deg = 0, i;
	for (i=1; i<=G->n; i++) {
		if (adjacent(G, i, x))
			deg++;
	}
	return deg;
}


//--------------------khai bao cau truc List------------------
typedef struct {
	int data[Max_Length]; // mang chua ds phan tu lang gieng
	int size;            // so luong phan tu lang gieng
}List;

void makenullList(List *L) { // khoi tao List rong
	L->size = 0;
}

void addList(List *L, int x) { // them 1 dinh vao cuoi List
	L->data[L->size] = x;
	L->size++;
}

int element_at (List *L, int i) { // lay ra 1 dinh trong List tai vi tri i
	return L->data[i-1]; 
}

List neighbors (Graph *G, int x) { //tim lang gieng cua 1 dinh
	List L;
	int i;
	makenullList(&L);
	for (i=1; i<=G->n; i++) {
		if (adjacent(G, i, x)) {
			addList(&L, i);
		}
	}
	return L;
}

//--------------------khai bao cau truc Queue------------------
typedef struct {
	int data[Max_Element];
	int front;
	int rear;
}Queue;

void makenullQueue(Queue *Q) {
	Q->front = 0;
	Q->rear = -1;
}

int empty (Queue *Q) {
	return Q->front > Q->rear;
}

int getFront(Queue *Q) {
	return Q->data[Q->front];
}
void enQueue (Queue *Q, int x) { // them 1 phan tu vao Queue
	Q->rear++;
	Q->data[Q->rear] = x;
}

void deQueue (Queue *Q) {
	Q->front++;
}
//--------------------Duyet theo chieu rong BFS------------------

List bfs(Graph *G, int x, int parent[]) {
	List L_bfs;
	makenullList(&L_bfs);
	Queue Q;
	makenullQueue(&Q);
	int mark[Max_Vertices];
	int i;
	for (i=1; i<=G->n; i++) {
		mark[i] = 0;
	}
	enQueue(&Q, x);
/**/parent[x] = -1;   
	
	while (!empty(&Q)) {
		int u = getFront(&Q);
		deQueue(&Q);
		if (mark[u] == 1)
			continue;
		addList(&L_bfs, u);
		mark[u] = 1;
		List L;
//		makenullList(&L);
		L = neighbors(G, u);
		for (i=1; i<=L.size; i++) {
			int v = element_at(&L, i);
			if (mark[v] == 0)
				enQueue(&Q, v);
			/**/if (parent[v] == -1)
					parent[v] = u;
		}
	}
	return L_bfs;
}

//--------------------Ham main------------------

int main () {
	Graph G;
	freopen ("dothi.txt", "r", stdin);
	int n, m;
	scanf ("%d%d", &n, &m);
	init_G(&G, n);
	int e, u, v;
	for (e=1; e<=m; e++) {
		scanf ("%d%d", &u, &v);
		add_edge(&G, u, v);
	} 
	
	int mark_bfs[Max_Vertices];
	int parent[Max_Vertices];
	int i, j;
	for (j=1; j<=G.n; j++) {
		mark_bfs[j] = 0;
		parent[j] = -1;
	}
	for (j=1; j<=G.n; j++) {
		if (mark_bfs[j] == 0) {
			List L = bfs(&G, j, parent);
			for (i=1; i<=L.size; i++) {
				printf ("%d\n", element_at(&L, i));
				mark_bfs[element_at(&L, i)] = 1;
			}
		}
	}
	
	for (j=1; j<=G.n; j++) {
		printf ("%d %d\n", j, parent[j]);
	}

	return 0;
}
