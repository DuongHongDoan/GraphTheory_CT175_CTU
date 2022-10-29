#include <stdio.h>
#define max_n 50

typedef struct {
	int u, v, w;
}Edge;

typedef struct {
	int n, m;
	Edge edge[max_n];
}Graph;

void init_graph(Graph *pG, int n) {
	pG->n = n;
	pG->m = 0;
}

void add_edge(Graph *pG, int u, int v, int w) {
	pG->edge[pG->m].u = u;
	pG->edge[pG->m].v = v;
	pG->edge[pG->m].w = w;
	pG->m++;
}
 
//Bien ho tro
int parent[max_n];

//Tim goc cua dinh mot dinh
int findRoot(int u) {
	while(parent[u] != u)
		u = parent[u];
	return u;
}

int Kruskal(Graph *pG, Graph *pT) {
	//1. Sap xep cac cung theo trong so khong giam
	int i, j;
	for (i=0; i<pG->m; i++){
		for (j=i+1; j<pG->m; j++) {
			if(pG->edge[j].w < pG->edge[i].w) {
				Edge tmp = pG->edge[i];
				pG->edge[i] = pG->edge[j];
				pG->edge[j] = tmp;
			}
		}
	}
	
	//2. Khoi tao cay pT rong va khoi tao bo quan ly BPLT
	init_graph (pT, pG->n);
	int u, v, w;
	for (u=1; u<=pG->n; u++)
		parent[u] = u;
	int sum_w=0;
	
	//3. Duyet qua cac cung da sap xep
	int e;
	for (e=0; e<pG->m; e++) {
		u = pG->edge[e].u;
		v = pG->edge[e].v;
		w = pG->edge[e].w;
		
		//3.1. Tim cha cho dinh u va dinh v
		int root_u = findRoot(u);
		int root_v = findRoot(v);
		
		//3.2. u va v nam o 2 BPLT khac nhau
		if (root_u != root_v) {
			
			//3.2.1. Them cung u, v, w vao cay pT
			add_edge(pT, u, v, w);
			
			//3.2.2. Gop 2 BPLT lai
			parent[root_v] = root_u;
			
			//3.2.3. Tinh tong trong so cua cay pT
			sum_w += w;
		} 
	}
	
	return sum_w;
}

int main () {
	Graph G, T;
	int n, m, e, u, v, w;
	freopen("dothi_K.txt", "r", stdin);
	scanf ("%d%d", &n, &m);
	init_graph(&G, n);
	
	for (e=0; e<m; e++) {
		scanf ("%d%d%d", &u, &v, &w);
		add_edge(&G, u, v, w);
	}
	
	int sum_w = Kruskal(&G, &T);
	printf("Tong trong so cua cay T la: %d\n", sum_w);
	
	//In ra cay T
	for (e=0; e<T.m; e++) {
		printf("(%d, %d): %d\n", T.edge[e].u, T.edge[e].v, T.edge[e].w);
	}
	
	return 0;
}
