#include <stdio.h>
#define Max_Vertices 20  //cap phat o nho cho mang 2 chieu cua Graph
#define Max_Length 20 	 // cap phat o nho cho mang 1 chieu cua List


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


//--------------------Ham main------------------

int main () {
	Graph G;
//	FILE* file = fopen("dothi.txt", "r");
	freopen("dothi.txt", "r", stdin);

	int n, m; // n la so dinh, m la so cung
//	fscanf (file, "%d%d", &n, &m);
	scanf ("%d%d", &n, &m);

	init_G(&G, n);
	int u, v, e;
	for (e=1; e<=m; e++) {
		scanf ("%d%d", &u, &v);
		add_edge(&G, u, v);
	}
	
	
	int i, j;
	for (i=1; i<=G.n; i++) {
		printf ("%d\n", degree(&G, i));
	}
	
	//can tim 1 lang gieng
	for (i=1; i<=G.n; i++) {
		List list = neighbors(&G, i);
		printf ("Neighbors of %d = [", i);
		for (j=1; j<=list.size; j++) {
			printf ("%d ", element_at(&list, j));
		}
		printf ("]\n");
	}
	return 0;
}
