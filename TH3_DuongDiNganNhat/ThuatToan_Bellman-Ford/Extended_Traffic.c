#include <stdio.h>
#include <math.h>
#define max_n 50
#define oo 999999

typedef struct {
	int u,v, w;
}Edge;

typedef struct {
	int n, m;
	Edge edges[max_n];
}Graph;

void init_graph (Graph *pG, int n) {
	pG->n = n;
	pG->m = 0;
}

void add_edge(Graph *pG, int u, int v, int w) {
	pG->edges[pG->m].u = u;
	pG->edges[pG->m].v = v;
	pG->edges[pG->m].w = w;
	pG->m++;
}

int pi[max_n], p[max_n], b[max_n];
int negative_cycle = 0;
int BellmanFord(Graph *pG, int s) {
	int u, v, w, it, k;
	for (u = 1; u <= pG->n; u++) {
		pi[u] = oo;
	}
	pi[s] = 0;
	p[s] = -1; //truoc dinh s khong co dinh nao

	// lap n-1 lan
	for (it = 1; it < pG->n; it++) {
		// Duyet qua cac cung va cap nhat (neu thoa)
		for (k = 0; k < pG->m; k++) {
			u = pG->edges[k].u;
			v = pG->edges[k].v;
			w = pG->edges[k].w;
			
			if (pi[u] == oo)    //chua co duong di tu s -> u, bo qua cung nay
			    continue;
			    
			if (pi[u] + w < pi[v]) {
				pi[v] = pi[u] + w;
				p[v] = u;
			}
		}
	}
	//Lam them 1 lan nua de kiem tra chu trinh am (neu can thiet)
	for (k = 0; k < pG->m; k++) {
		u = pG->edges[k].u;
		v = pG->edges[k].v;
		w = pG->edges[k].w;
		
		if (pi[u] == oo)    //chua co duong di tu s -> u, bo qua cung nay
		    continue;
		    
		if (pi[u] + w < pi[v]) {
			return 1;
		}
	}
	return 0;
}

int main () {
	Graph G;
	int n, m, e, u, v, w, s, t;
	freopen("dothi.txt", "r", stdin);
	scanf ("%d%d", &n, &m);
	init_graph(&G, n);
	
	for (u=1; u<=n;u++) {
		scanf ("%d", &b[u]);
	}
	
	for (e=1; e<=m; e++) {
		scanf ("%d%d", &u, &v);
		w = pow(b[v]-b[u], 3);
		add_edge(&G, u, v, w);
	}
	
	scanf ("%d%d", &s, &t);
	BellmanFord(&G, s);
	
/*In ra chieu dai DDNN tu dinh s den dinh t*/
	if (pi[t] != oo)
		printf ("%d", pi[t]);
	else printf ("-1");

	return 0;
}
