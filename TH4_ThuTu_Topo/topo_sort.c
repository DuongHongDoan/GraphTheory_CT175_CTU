#include <stdio.h>
#define max_n 50
#define max_e 100
#define max_q 50

typedef struct {
	int n, m;
	int a[max_n][max_n];
}Graph;

void init_graph(Graph *pG, int n) {
	pG->n = n;
	pG->m = 0;
	int u, v;
	for (u=1; u<=n; u++) {
		for (v=1; v<=n; v++) {
			pG->a[u][v] = 0;
		}
	}
}

void add_edge(Graph *pG, int u, int v) {
	pG->a[u][v] = 1;
	pG->m++;
}

typedef int ElementType;
typedef struct {
	ElementType data[max_e];
	int size;
}List;

void makenullList(List *pL) {
	pL->size = 0;
}

void addList (List *pL, ElementType x) {
	pL->data[pL->size] = x;
	pL->size++;
}

int getElement(List *pL, int i) {
	return pL->data[i-1];
}

typedef struct {
	int front, rear;
	int data[max_q];
}Queue;

void makenullQueue(Queue *pQ) {
	pQ->front = 0;
	pQ->rear = -1;
}

int empty (Queue *pQ) {
	return pQ->front > pQ->rear;
}

int full (Queue *pQ) {
	return pQ->rear - pQ->front + 1 == max_q;
}

int getTop (Queue *pQ) {
	return pQ->data[pQ->front];
}

void enQueue(Queue *pQ, int x) {
	if (!full(pQ)) {
		if (empty(pQ)) {
			pQ->front = 0;
		}
		pQ->rear = pQ->rear + 1;
		pQ->data[pQ->rear] = x;
	}
}

void deQueue(Queue *pQ) {
	if(!empty(pQ)) {
		pQ->front = pQ->front + 1;
		if(pQ->front > pQ->rear)
			makenullQueue(pQ);
	}
}

void topo_sort(Graph *pG, List *pL) {
	// 1. Tinh bac vao cua u
	int u, x, d[max_n];
	for (u=1; u<=pG->n; u++){
		d[u] = 0;
		for (x=1; x<=pG->n; x++) {
			if (pG->a[x][u] != 0)
				d[u]++;
		}
	}
	
	// 2. Khoi tao hang doi va dua cac dinh co d[u] = 0 vao hang doi
	Queue Q;
	makenullQueue(&Q);
	for (u=1; u<=pG->n; u++) {
		if (d[u] == 0)	
			enQueue(&Q, u);
	}
	
	// 3. Tao danh sach rong va lap den khi hang doi rong thi dung
	makenullList (pL);
	
	while (!empty(&Q)) {
		// 3.1. Lay phan tu trong hang doi ra va them no vao danh sach pL
		u = getTop(&Q);
		deQueue(&Q);
		addList(pL, u);
		
		// 3.2. Xoa dinh u <=> giam bac vao cua cac dinh ke v cua u va neu d[u]=0 thi dua vao Queue
		int v;
		for(v=1; v<=pG->n; v++) {
			if (pG->a[u][v] != 0) {
				d[v]--;
				if (d[v] == 0)
					enQueue(&Q, v);
			}
		}
	}
}

int main () {
	Graph G;
	int n, m, e, u, v;
	freopen("dothi.txt", "r", stdin);
	scanf ("%d%d", &n, &m);
	init_graph(&G, n);
	for (e=1; e<=m; e++) {
		scanf ("%d%d", &u, &v);
		add_edge(&G, u, v);
	}
	List L;
	makenullList(&L);
	
	topo_sort(&G, &L);
	int i;
	for (i=1; i<=L.size; i++) {
		printf ("%d ", getElement(&L, i));
	}
	
	return 0;
}
