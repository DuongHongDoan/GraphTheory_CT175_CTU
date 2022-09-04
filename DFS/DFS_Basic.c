#include <stdio.h>
#define Max_Vertices 20  //cap phat o nho cho mang 2 chieu cua Graph
#define Max_Length 20 	 // cap phat o nho cho mang 1 chieu cua List
#define Max_Element 40   // cap phat o nho cho mang 1 chieu cua Stack

//--------------------khai bao cau truc Graph------------------
typedef struct {
	int a[Max_Vertices][Max_Vertices]; //ma tran dinh - dinh
	int n; //so luong dinh
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
	int size; // so luong phan tu lang gieng
}List;

void makenullList(List *L) { // khoi tao List rong
	L->size = 0;
}

void addList(List *L, int x) { // them 1 dinh vao cuoi List
	L->data[L->size] = x;
	L->size++;
}

int element_at (List *L, int i) { // lay ra 1 dinh trong List taij vi tri i
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


//--------------------khai bao cau truc Stack------------------
typedef struct {
	int data[Max_Element]; 
	int size;
}Stack;

void makenullStack (Stack *S) { //khoi tao stack rong
	S->size = 0;
}

int empty(Stack *S) {
	return S->size == 0;
}

void push_S(Stack *S, int x) { //them 1 phan tu vao Stack
	S->data[S->size] = x;
	S->size++;
}

int getTop(Stack *S) { // lay ra phan tu trong Stack
	return S->data[S->size-1];
}

void pop_S (Stack *S) { // xoa phan tu trong Stack
	S->size--;
}
//--------------------Duyet theo chieu sau DFS------------------
void dfs (Graph *G, int x) {
	Stack S;
	makenullStack(&S);
	push_S(&S, x);
	
	//khai bao mang de danh dau cac dinh da dc duyet
	int mark[Max_Vertices];
	int i, j;
	for (i=1; i<=G->n; i++) {
		mark[i]=0; //khoi tao mark all = 0 <=> chua duyet, =1 la da dc duyet
	}
	
	while (!empty(&S)) {
		int u = getTop(&S);
		pop_S(&S);
		if (mark[u] == 1)
			continue;
		printf ("Duyet: %d\n", u);
		mark[u] = 1;
		List list = neighbors(G, u);
		for (i=1; i<=list.size; i++) {
			int v = element_at(&list, i);
			if (mark[v] == 0) {
				push_S(&S, v);
			}
		}
	}
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
	
	dfs(&G, 1);
	return 0;
}
