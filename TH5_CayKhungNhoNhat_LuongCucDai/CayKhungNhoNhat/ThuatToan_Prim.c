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
	int u,v;
	for (u=1; u<=n; u++) {
		for (v=1; v<=n; v++) {
			pG->a[u][v] = 0;
		}
	}
}

void add_edge(Graph *pG, int u, int v, int w) {
	pG->a[u][v] = w;
	pG->a[v][u] = w;
}

int pi[max_n], p[max_n], mark[max_n];

int Prim(Graph *pG, Graph *pT, int s) {
	//1. Khoi tao
	int u;
	for (u=1; u<=pG->n; u++) {
		mark[u] = 0;
		pi[u] = oo;
		p[u] = 0;
	}
	pi[s] = 0;
	p[s] = -1;
	
	//2. Lap n-1 lan
	int i;
	for (i=1; i<pG->n; i++) {
		//2.1. Tim dinh u gan voi dinh s nhat
		int j, min_pi = oo;
		for (j=1; j<=pG->n; j++) {
			if (mark[j]==0 && pi[j]<min_pi) {
				min_pi = pi[j];
				u = j;
			}
		}
		
		//2.2. Danh dau u da duyet
		mark[u] = 1;
		
		//2.3. Cap nhat lai pi va p cua cac dinh ke v cua u
		int v;
		for (v=1; v<=pG->n; v++) {
			if (pG->a[u][v] != 0)
				if(mark[v]==0 && pG->a[u][v] < pi[v]) {
					pi[v] = pG->a[u][v];
					p[v] = u;
				}
		}
	}
	
	//3. Dung cay pT dua vao p[u]: them cung (p[u], u) vao cay pT
	init_graph(pT, pG->n);
	int sum_w=0;
	
	for (u=1; u<=pG->n; u++) {
		if (p[u] != -1) {
			int w = pG->a[p[u]][u];
			add_edge(pT, p[u], u, w);
			sum_w += w;
		}
	}
	
	return sum_w;
}

int main () {
	Graph G, T;
	int n, m, e, u, v, w;
	freopen("dothi_P.txt", "r", stdin);
	scanf ("%d%d", &n, &m);
	init_graph(&G, n);
	
	for (e=1; e<=m; e++) {
		scanf ("%d%d%d", &u, &v, &w);
		add_edge(&G, u, v, w);
	}
	
	int s;
	scanf ("%d", &s);
	int sum_w = Prim(&G, &T, s);
	printf("Tong trong so cua cay tai dinh 1 la: %d\n", sum_w);

	//In cay T
	for (u=T.n; u>=1; u--) {
		if(u!=s)
			printf("(%d, %d): %d\n", p[u], u, T.a[p[u]][u]);
	}
	
	return 0;
}
