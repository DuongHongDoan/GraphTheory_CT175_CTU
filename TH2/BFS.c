#include <stdio.h>
#define max_n 50
#define max_Q 50
/*--------------Cau truc do thi----------*/
typedef struct {
	int n, m;
	int a[max_n][max_n];
}Graph;

void init_graph(Graph *pG, int n) {
	pG->n = n;
	pG->m = 0;
	int u, v;
	for (u=1; u<=n; u++)
		for (v=1; v<=n; v++)
			pG->a[u][v] = 0;
}

void add_edge(Graph *pG, int u, int v) {
/*Vo huong*/
	pG->a[u][v] += 1;
	if (u!=v)
		pG->a[v][u] += 1;
	pG->m++;
/*Co huong*/
//	pG->a[u][v] += 1;
//	pG->m++;
}

int adjacent (Graph *pG, int u, int v) {
	return pG->a[u][v] != 0;
}
/*--------------Cau truc hang doi----------*/
typedef struct {
	int data[max_Q];
	int front, rear;
}Queue;

void makenullQueue(Queue *pQ) {
	pQ->front = 0;
	pQ->rear = -1;
}

int emptyQueue(Queue *pQ) {
	return pQ->front > pQ->rear;
}

int fullQueue(Queue *pQ) {
	return pQ->rear - pQ->front + 1 == max_Q;
}

int getTop(Queue *pQ) {
	return pQ->data[pQ->front];
}

void enQueue(Queue *pQ, int x) {
	if (!fullQueue(pQ)) {
		if (emptyQueue(pQ)) {
			pQ->front = 0;
		}
		pQ->rear = pQ->rear + 1;
		pQ->data[pQ->rear] = x;
	}
}

void deQueue (Queue *pQ) {
	if (!emptyQueue(pQ)) {
		pQ->front = pQ->front + 1;
		if (pQ->front > pQ->rear)
			makenullQueue(pQ);
	}
}

/*--------------Ham duyet Dt theo chieu rong----------*/
int mark[max_n];
void BFS (Graph *pG, int s) {
	Queue Q;
	makenullQueue(&Q);
	enQueue(&Q, s);
	
	while (!emptyQueue(&Q)) {
		int u = getTop(&Q);
		deQueue(&Q);
		if (mark[u] != 0)
			continue;
		printf ("%d\n", u);
		mark[u] = 1;
		int v;
		for (v=1; v<=pG->n; v++) {
			if (adjacent(pG, u, v))
				enQueue(&Q, v);
		}
	}
}

/*--------------Ham main----------*/
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
	
	int i;
	for (i=1; i<=n; i++) 
		mark[i] = 0;
		
/*Duyet dinh bat ky*/
//	int s;
//	scanf ("%d", &s);	
//	BFS(&G, s);
/*Duyet dinh cu the*/	
	BFS(&G, 1);
/*Duyet toan bo do thi*/
//	for (i=1; i<=n; i++) {
//		if (mark[i] == 0)
//			BFS(&G, i);
//	}
	
	return 0;
}
