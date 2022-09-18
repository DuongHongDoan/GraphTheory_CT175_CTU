#include <stdio.h>
#define max_n 50
#define White 0
#define Gray 1
#define Black 2

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
	pG->a[u][v] += 1;
	pG->m++;
}

int adjacent(Graph *pG, int u, int v) {
	return pG->a[u][v] != 0;
}

int color[max_n];
int has_circle;

void DFS_DQ(Graph *pG, int u) {
	color[u] = Gray;
	
	int v;
	for (v=1; v<=pG->n; v++) {
		if (adjacent(pG, u, v)) {
			if (color[v] == White)
				DFS_DQ(pG, v);
			else if (color[v] == Gray)
				has_circle = 1;
		}
	}
	
	color[u] = Black;
}

int main () {
	Graph G;
	int n, m, u, v, e;
	freopen("dothi.txt", "r", stdin);
	scanf ("%d%d", &n, &m);
	init_graph (&G, n);
	for (e=1; e<=m; e++) {
		scanf ("%d%d", &u, &v);
		add_edge(&G, u, v);
	}
	
	for (e=1; e<=n; e++)
		color[e] = White;
		
	has_circle = 0;
	
	for (u=1; u<=n; u++) {
		if (color[u] == White)
			DFS_DQ(&G, u);
	}
	
	if (has_circle)
		printf ("CIRCULAR REFERENCE");
	else 
		printf ("OK");
	
	return 0;
}
