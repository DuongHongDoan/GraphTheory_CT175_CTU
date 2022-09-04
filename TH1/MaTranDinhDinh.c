#include <stdio.h>
#define Max_N 50

typedef struct {
	int n, m;
	int A[Max_N][Max_N];
}Graph;

void init_G(Graph *pG, int n) {
	pG->n = n;
	pG->m = 0;
	int i, j;
	for (i=1; i<=n; i++) {
		for (j=1; j<=n; j++)
			pG->A[i][j] = 0;
	}
}

void add_edge(Graph *pG, int u, int v) {
/*Co huong*/
    pG->A[u][v] += 1;
/*Vo huong*/
//	pG->A[u][v] += 1;
//    if (u != v)
//        pG->A[v][u] += 1;
}

int adjacent (Graph *pG, int u, int v) {
	return pG->A[u][v] != 0;
}

int degree (Graph *pG, int u) {
/*Vo huong*/
//	int e, deg = 0;
//	for (e=1; e<=pG->n; e++) {
//		deg += pG->A[u][e];
//	}
//	return deg; // return deg+pG->A[u][u] khi co khuyen
/*Co huong*/
	int e, deg = 0;
	for (e=1; e<=pG->n; e++) {
		deg += pG->A[u][e] + pG->A[e][u]; // deg(u) = deg_out(u) + deg_in(u)
	}
	return deg;
}

void neighbors(Graph *pG, int u) {
/*Don cung*/
	int v;
	for (v=1; v<=pG->n; v++) {
		if (adjacent(pG, u, v) == 1)
			printf ("%d ", v);
	}
	printf ("\n");
/*Da cung*/
//	int v, i;
//	for (v=1; v<=pG->n; v++) {
//		for (i=1; i<=pG->A[u][v]; i++)
//			printf ("%d ", v);
//	}
//	printf ("\n");
}

int main () {
	Graph G;
	int n, m;
	freopen("dothi.txt", "r", stdin);
	scanf ("%d%d", &n, &m);
	init_G(&G, n);
	
	int e, u, v;
	for (e=1; e<=m; e++) {
		scanf ("%d%d", &u, &v);
		add_edge(&G, u, v);
	}
	int i, j;
	for (i=1; i<=G.n; i++) {
		for (j=1; j<=G.n; j++)
			printf ("%d ", G.A[i][j]);
		printf ("\n");
	}
	
	for (e=1; e<=G.n; e++) {
		printf ("deg[%d] = %d\n", e, degree(&G, e));
	}
	
	for (e=1; e<=G.n; e++) {
		printf ("neighbours[%d] = ", e);
		neighbors(&G, e);
	}	
	return 0;
}
