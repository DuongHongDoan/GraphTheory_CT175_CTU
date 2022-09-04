#include <stdio.h> 
#define White 0
#define Gray 1
#define Black 2
#define max_n 50

typedef struct {
	int n, m;
	int a[max_n][max_n];
}Graph;

void init_graph (Graph *pG, int n) {
	int i, j;
	pG->n = n;
	pG->m = 0;
	for (i=1; i<=n; i++) 
		for (j=1; j<=n; j++)
			pG->a[i][j] = 0;
}

void add_edge (Graph *pG, int u, int v) {
/*Vo huong*/
//	pG->a[u][v] += 1;
//	if (u!=v)
//		pG->a[v][u] += 1;
//	pG->m++;
/*Co huong*/
	pG->a[u][v] += 1;
	pG->m++;
}

int adjacent(Graph *pG, int u, int v) {
	return pG->a[u][v] != 0;
}

int color[max_n];
int has_circle;
int parent[max_n];
int start, end;

void DFS_DQ(Graph *pG, int u, int p) {
	color[u] = Gray;
	parent[u] = p;
	
	int v;
	for (v=1; v<=pG->n; v++) {
		if (adjacent(pG, u, v)) {
			if (v == p)
				continue;
			if (color[v] == White)
				DFS_DQ(pG, v, u);
			else if (color[v] == Gray) {
				has_circle = 1;
				start = u;
				end = v;
			}
			
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
	
	for (e=1; e<=n; e++) {
		color[e] = White;
		parent[e] = -1;
	}
		
	
	has_circle = 0;
	
	for (e=1; e<=n; e++) 
		if (color[e] == White)
			DFS_DQ(&G, e, -1);
	
	if (has_circle) {
		int a[100], i=0, j;
		a[0] = start;
		int u = start;
		do {
			u = parent[u];
			i++;
			a[i] = u;
		}while (u!=v);
		
		for (j=i; j>=0; j--)
			printf ("%d ",a[j]);
		printf ("%d\n", a[i]);
	}
	else
		printf ("-1");
	
	return 0;
}
