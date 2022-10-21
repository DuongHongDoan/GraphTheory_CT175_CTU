#include <stdio.h>
#define max_n 50
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

void copyList(List *L1, List *L2) {
	makenullList(L1);
	int i;
	for (i=1; i<=L2->size; i++)
		addList(L1, getElement(L2, i));
}

int rank[max_n];
void ChiaKeo(Graph *pG) {
	int u, v, d[max_n];
	for (u=1; u<=pG->n; u++) {
		d[u] = 0;
		for (v=1; v<=pG->n; v++) 
			if (pG->a[v][u] != 0)
				d[u]++;
	}
	
	List L1, L2;
	makenullList(&L1);
	
	for (u=1; u<=pG->n; u++) 
		if (d[u] == 0)
			addList(&L1, u);
			
	int k=0;
	while (L1.size > 0) {
		makenullList(&L2);
		int i;
		for (i=1; i<=L1.size; i++) {
			u = getElement(&L1, i);
			rank[u] = k;
			for (v=1; v<=pG->n; v++) {
				if(pG->a[u][v] != 0) {
					d[v]--;
					if(d[v] == 0)
						addList(&L2, v);
				}
			}
		}
		copyList(&L1, &L2);
		k++;
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
		add_edge(&G, v, u);
	}
	
	ChiaKeo(&G);
	int tongKeo=0;
	for (u=1; u<=n; u++){
		printf("%d\n",rank[u]+1);
		tongKeo = (tongKeo + rank[u] + 1);
	}
	
	printf("%d", tongKeo);
	
	return 0;
}
