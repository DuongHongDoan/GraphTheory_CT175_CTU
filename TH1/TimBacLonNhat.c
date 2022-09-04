#include <stdio.h>
#define max_n 50

typedef struct {
	int n, m;
	int a[max_n][max_n];
}Graph;

void init_g(Graph *pG, int n) {
	pG->n = n;
	pG->m = 0;
	int u, v;
	for (u=1; u<=n; u++) {
		for (v=1; v<=n; v++)
			pG->a[u][v] = 0;
	}
}

void add_edge(Graph *pG, int u, int v) {
	pG->a[u][v] = 1;
	pG->a[v][u] = 1;
	pG->m++;
}

int degree(Graph *pG, int u) {
	int v, deg=0;
	for (v=1; v<=pG->n; v++)
		deg += pG->a[u][v];
	return deg;
}
int main () {
	Graph G;
	freopen("dothi.txt", "r", stdin);
	int e, u, v, n, m;
	scanf ("%d%d", &n, &m);
	init_g(&G, n);
	
	for (e=1; e<=m; e++) {
		scanf ("%d%d", &u, &v);
		add_edge(&G, u, v);
	}
	
	int d, max = degree(&G, 1);
	for (u=2; u<=n; u++) {
		if (max < degree(&G, u))
			max = degree(&G, u);
		if (max == degree(&G, u))
			d = u;
	}
	printf ("%d %d", d, max);
	return 0;
}
