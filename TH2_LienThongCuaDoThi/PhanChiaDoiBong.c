#include <stdio.h>
#define max_n 50
#define NoColor 0
#define Blue 1
#define Red 2

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
int conflict;

void DFS_DQ(Graph *pG, int u, int c) {
	color[u] = c;
	
	int v;
	for (v=1; v<=pG->n; v++) {
		if (adjacent(pG, u, v)) {
			if (color[v] == NoColor)
				DFS_DQ(pG, v, 3-c);
			else if (color[v] == color[u])
				conflict = 1;
		}
	}
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
		color[e] = NoColor;
		
	conflict = 0;
	
	for (u=1; u<=n; u++) 
		if (color[u] == NoColor)
			DFS_DQ(&G, u, Blue);
			
	if (conflict)
		printf ("IMPOSSIBLE");
	else {
		for (u=1; u<=G.n; u++) {
			if (color[u] == Blue)
				printf ("%d ", u);
		}
		printf ("\n");
		for (u=1; u<=G.n; u++) {
			if (color[u] == Red)
				printf ("%d ", u);
		}
	}
	
	return 0;
}
