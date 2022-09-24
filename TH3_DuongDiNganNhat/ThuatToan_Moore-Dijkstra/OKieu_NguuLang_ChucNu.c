#include <stdio.h>
#define max_n 50
#define oo 999999

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
			pG->a[u][v] = -1;
		}
	}
}

void add_edge(Graph *pG, int u, int v, int w) {
	pG->a[u][v] = w;
//	if (u!=v)
//		pG->a[v][u] = w;
//	pG->m++;
}

int pi[max_n], p[max_n], mark[max_n];
void Moore_Dijkstra(Graph *pG, int s) {
	int u;
	for (u=1; u<=pG->n; u++) {
		mark[u] = 0;
		pi[u] = oo;
		p[u] = 0;
	}
	
	pi[s] = 0;
	p[s] = -1;
	
	int i;
	for (i=1; i<pG->n; i++) {
		int j, min_pi = oo;
		for (j=1; j<=pG->n; j++) {
			if (mark[j] == 0 && pi[j] < min_pi) {
				min_pi = pi[j];
				u = j;
			}
		}
		
		mark[u] = 1;
		
		int v;
		for (v=1; v<=pG->n; v++) {
			if (pG->a[u][v] != -1 && mark[v] == 0) {
				if (pi[u] + pG->a[u][v] < pi[v]) {
					pi[v] = pi[u] + pG->a[u][v];
					p[v] = u;
				}
			}
		}
	}
}

int main () {
	Graph G ;
	int n, m, e, u, v, w;
	freopen("dothi.txt", "r", stdin);
	scanf ("%d%d", &n, &m);
	init_graph(&G, n);
	
	for (e=1; e<=m; e++) {
		scanf ("%d%d%d", &u, &v, &w);
		add_edge(&G, u, v, w);
	}
	
	Moore_Dijkstra(&G, 1);
	
	if (pi[n] != oo)
		printf ("%d\n", pi[n]);
	else printf ("-1");
		
	return 0;
}
