#include <stdio.h>
#define max_n 50
#define max_q 100
#define max_l 100

typedef struct {
	int n;
	int a[max_n][max_n];
}Graph;

void init_graph (Graph *pG, int n) {
	pG->n = n;
	int u, v;
	for (u=1; u<=n; u++) {
		for (v=1; v<=n; v++) {
			pG->a[u][v] = 0;
		}
	}
}

void add_edge(Graph *pG, int u, int v) {
	pG->a[u][v] += 1;
}

typedef struct {
	int size;
	int data[max_l];
}List;

void makenullList(List *pL) {
	pL->size = 0;
}

int empty(List *pL) {
	return pL->size == 0;
}

int getElement(List *pL, int i) {
	return pL->data[i-1];
}

void addList(List *pL, int x) {
	pL->data[pL->size] = x;
	pL->size++;
}

typedef struct {
	int front, rear;
	int data[max_q];
}Queue;

void makenullQueue(Queue *pQ) {
	pQ->front = 0;
	pQ->rear = -1;
}

int emptyQueue(Queue *pQ) {
	return pQ->front > pQ->rear;
}

int full(Queue *pQ) {
	return pQ->rear - pQ->front + 1 == max_q;
}

int getTop(Queue *pQ) {
	return pQ->data[pQ->front];
}

void enQueue (Queue *pQ, int x) {
	if (!full(pQ)) {
		if (emptyQueue(pQ)) {
			pQ->front = 0;
		}
		pQ->rear = pQ->rear + 1;
		pQ->data[pQ->rear] = x;
	}
}

void deQueue(Queue *pQ) {
	if(!emptyQueue(pQ)) {
		pQ->front = pQ->front + 1;
		if(pQ->front > pQ->rear)
			makenullQueue(pQ);
	}
}

void XepDa(Graph *pG, List *pL) {
	int u, x, d[max_n];
	for (u=1; u<=pG->n; u++){
		d[u] = 0;
		for (x=1; x<=pG->n; x++) {
			if (pG->a[x][u] != 0)
				d[u]++;
		}
	}
	
	Queue Q;
	makenullQueue(&Q);
	
	for (u=1; u<=pG->n; u++) {
		if (d[u]==0)
			enQueue(&Q, u);
	}
	

	makenullList(pL);
	while (!emptyQueue(&Q)) {
		u = getTop(&Q);
		deQueue(&Q);
		addList(pL, u);
		
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
	freopen("dothi.txt", "r", stdin);
	int n,m, e, u, v;
	scanf ("%d%d", &n, &m);
	init_graph(&G, n);
	
	for (e=1; e<=m; e++) {
		scanf ("%d%d", &u, &v);
		add_edge(&G, u, v);
	}
	
	List L;
	makenullList(&L);
	XepDa(&G, &L);
	
	int i;
	for (i=1; i<=L.size; i++) {
		printf("%d ", getElement(&L, i));
	}
	
	return 0;
}
