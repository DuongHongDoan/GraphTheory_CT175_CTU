#include <stdio.h>
#define Max_N 100
#define Max_M 50

typedef struct {
	int n, m;
	int a[Max_N][Max_M];
}Graph;

void init_G(Graph *pG, int n, int m) {
	int u, e;
	pG->n = n;
	pG->m = m;
	for (u=1; u<=n; u++) {
		for (e=1; e<=m; e++) {
			pG->a[u][e] = 0;
		}
	}
}

void add_edge(Graph *pG, int e, int u, int v) {
/*Da DT vo huong - Gia DT*/
//	pG->a[u][e] = 1;
//	pG->a[v][e] += 1;
/*Don DT vo huong*/
//	pG->a[u][e] = 1;
//	pG->a[v][e] = 1;
/*Da DT co huong*/
//	pG->a[u][e] = 1;
//	pG->a[v][e] = -1;
/*Don DT co huong*/
	pG->a[u][e] = 1;
	pG->a[v][e] = -1;
} 

int adjacent(Graph *pG, int u, int v) {
	int e;
	for (e=1; e<=pG->m; e++) {
		if (pG->a[u][e] == 1 || pG->a[v][e] == 1)
			return 1;
	}
	return 0;
}

int degree(Graph *pG, int u) {
/*Vo huong*/
//	int e, deg = 0;
//	for (e=1; e<=pG->m; e++) {
//		if (adjacent(pG, u, e))
//			deg += pG->a[u][e];
//	}
//	return deg;
/*Co huong*/
	int e, deg = 0;
	for (e=1; e<=pG->m; e++) {
		if (pG->a[u][e] == 1 || pG->a[u][e] == -1)
			deg++;
	}
	return deg;
}

void neighbors(Graph *pG, int u) {
	int v, e;
	for (v=1; v<=pG->n; v++) {
		if (u == v) {
			for (e=1; e<=pG->m; e++) {
				if (pG->a[u][e] > 0 && pG->a[v][e] > 0) {
					printf ("%d ", v);
				}
			}
		}
		
	}
		
	printf ("\n");
}

int main () {
	Graph G;
	int n, m;
	freopen("dothi.txt", "r", stdin);
	scanf ("%d%d", &n, &m);
	init_G(&G, n, m);
	
	int e, u, v;
	for (e=1; e<=m; e++) {
		scanf ("%d%d", &u, &v);
		add_edge(&G, e, u, v);
	}
	
	
	for (u=1; u<=G.n; u++) {
		for (e=1; e<=G.m; e++) {
			printf ("%d ", G.a[u][e]);
		}
		printf ("\n");
	}
	
	for (e=1; e<=G.n; e++) {
		printf ("deg[%d] = %d\n", e, degree(&G, e));
	}
	
	for (e=1; e<=G.n; e++) {
		printf ("neighbours(%d) = ", e);
		neighbors(&G, e);
	}
	return 0;
}
