#include <stdio.h>
#define Max_N 50
#define Max_E 100

/*--------Khai bao cau truc List------*/
typedef int ElementType;
typedef struct {
	ElementType data[Max_E];
	int size;
}List;

void makenullList(List *pL) {
	pL->size = 0;
}

void push_back(List *pL, ElementType x) {
	pL->data[pL->size] = x;
	pL->size++;
}

ElementType getElement(List *pL, int i) {
	return pL->data[i-1];
}

int count_list(List *pL) {
	return pL->size;
}


/*--------Khai bao cau truc Graph------*/
typedef struct {
	int n;
	List adj[Max_N];
}Graph;

void init_G(Graph *pG, int n) {
	int u;
	pG->n = n;
	for (u=1; u<=n; u++) {
		makenullList(&pG->adj[u]);
	}
}

void add_edge (Graph *pG, int u, int v) {
	push_back(&pG->adj[u], v);
	push_back(&pG->adj[v], u);
}

int adjacent(Graph *pG, int u, int v) {
	int i;
	for (i=1; i<=pG->adj[u].size; i++)
		if (getElement(&pG->adj[u], i) == v)
			return 1;
	return 0;
}

int degree(Graph *pG, int u) {
	return pG->adj[u].size;
}

void neighbors(Graph *pG, int u) {
	int i;
	for (i=1; i<=pG->adj[u].size; i++) {
		if (adjacent(pG, u, i))
			printf ("%d ", getElement(&pG->adj[u], i));
	}
	printf ("\n");
}

int main () {
	Graph G;
	int n, m;
	freopen("dothi.txt", "r", stdin);
	scanf ("%d%d", &n, &m);
	init_G(&G, n);
	
	int e, u, v;
	for (e=1; e<=m; e++) {
		scanf ("%d%d",&u, &v);
		add_edge(&G, u, v);
	}
	
	for (e=1; e<=n; e++) {
		printf ("adj(%d) = ", e);
		neighbors(&G, e);
	}
	
	for (e=1; e<=n; e++) {
		printf ("deg(%d) = %d\n", e, degree(&G, e));
	}
	
	return 0;
}
