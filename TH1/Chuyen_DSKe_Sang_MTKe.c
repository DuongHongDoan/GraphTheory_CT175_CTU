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
	for (u=1; u<=n; u++)
		for (v=1; v<=n; v++) 
			pG->a[u][v] = 0;
}

void add_edge(Graph *pG, int u, int v) {
	pG->a[u][v] += 1;
}

int main () {
	Graph G;
	int n;
	scanf ("%d", &n);
	init_g(&G, n);
	
	int u;
	for (u=1; u<=n; u++) {
		int v;
		while (1) {
			scanf ("%d", &v);
			if (v==0)
				break;
			add_edge(&G, u, v);
		}
	}
	
	int v;
	for (u=1; u<=n; u++){
		for (v=1; v<=n; v++) 
			printf ("%d ", G.a[u][v]);
		printf ("\n");
	}
		
	return 0;
}
