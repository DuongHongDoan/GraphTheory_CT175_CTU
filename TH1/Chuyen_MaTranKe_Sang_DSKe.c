#include <stdio.h>
#define max_n 50

typedef struct {
	int n, m;
	int a[max_n][max_n];
}Graph;

void init_G(Graph *pG, int n) {
	pG->n = n;
	pG->m = 0;
	int u, v;
	for (u=1; u<=n; u++) 
		for (v=1; v<=n; v++)
			pG->a[u][v] = 0;
}

void add_edge(Graph *pG, int u, int v) {
	pG->a[u][v] += 1;
	if (u != v)
		pG->a[v][u] += 1;
	pG->m++;
}

void neighbors(Graph *pG, int u) {
/*Don cung*/
//	int v;
//	for (v=1; v<=pG->n; v++) {
//		if (adjacent(pG, u, v) == 1)
//			printf ("%d ", v);
//	}
//	printf ("\n");
/*Da cung*/
	int v, i;
	for (v=1; v<=pG->n; v++) {
		for (i=1; i<=pG->a[u][v]; i++)
			printf ("%d ", v);
	}
	printf ("0\n");
}

int main () {
	Graph G;
	int n;
	scanf ("%d", &n);
	init_G(&G, n);
	int i, j;
	for (i=1; i<=n; i++) {
		for (j=1; j<=n; j++)
			scanf ("%d", &G.a[i][j]);
	}
	
	int u;
	
	for (u=1; u<=n; u++) {
		neighbors(&G, u);
	}
	return 0;
}
