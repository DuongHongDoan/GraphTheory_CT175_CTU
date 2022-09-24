#include <stdio.h>
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

int pi[max_n], p[max_n];
int negative_cycle = 0;
//void bellman_Ford(Graph *pG,int s) {
//	int u, v, w,i, k;
//	for (u=1; u<=pG->n; u++) {
//		pi[u] = oo;
//		p[u] = 0;
//	}
//	
//	pi[s] = 0;
//	p[s] = -1;
//	
//	
//	for (i=1; i<pG->n; i++) {
//		for (k=0; k<pG->m; k++) {
//			u = pG->edges[k].u;
//			v = pG->edges[k].v;
//			w = pG->edges[k].w;
//			if (pi[u] == oo)
//				continue;
//			if (pi[u] + w < pi[v]) {
//				pi[v] = pi[u] + w;
//				p[v] = u;
//			}
//		}
//	}
//	
//	//Kiem tra chu trinh am
//	for (k=0; k<pG->m; k++) {
//		u = pG->edges[k].u;
//		v = pG->edges[k].v;
//		w = pG->edges[k].w;
//		int t = pi[u] + w;
//		if ((t<=oo && t>=900000)) {
//			t = oo;
//			if (t < pi[v]) {
//				negative_cycle = 1;
//				break;
//			}
//		}
//		else if(t<oo) {
//			if (t < pi[v]) {
//				negative_cycle = 1;
//				break;
//			}
//		}	
//	}
//}

int BellmanFord(Graph *pG, int s) {
	int u, v, w, it, k;
	for (u = 1; u <= pG->n; u++) {
		pi[u] = oo;
	}
	pi[s] = 0;
	p[s] = -1; //tru?c d?nh s không có d?nh nào c?

	// l?p n-1 l?n
	for (it = 1; it < pG->n; it++) {
		// Duy?t qua các cung và c?p nh?t (n?u tho?)
		for (k = 0; k < pG->m; k++) {
			u = pG->edges[k].u;
			v = pG->edges[k].v;
			w = pG->edges[k].w;
			
			if (pi[u] == oo)    //chua có du?ng di t? s -> u, b? qua cung này
			    continue;
			    
			if (pi[u] + w < pi[v]) {
				pi[v] = pi[u] + w;
				p[v] = u;
			}
		}
	}
	//Làm thêm 1 l?n n?a d? ki?m tra chu trình âm (n?u c?n thi?t)
	for (k = 0; k < pG->m; k++) {
		u = pG->edges[k].u;
		v = pG->edges[k].v;
		w = pG->edges[k].w;
		
		if (pi[u] == oo)    //chua có du?ng di t? s -> u, b? qua cung này
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
	
	for (e=1; e<=m; e++) {
		scanf ("%d%d%d", &u, &v, &w);
		add_edge(&G, u, v, w);
	}
	
	scanf ("%d%d", &s, &t);
//	bellman_Ford(&G, s);
/*kiem tra chu trinh am*/
//	if (negative_cycle)
//		printf ("YES");
//	else 
//		printf ("NO");
		
//	if (BellmanFord(&G, s)==1)
//		printf ("YES");
//	else 
//		printf ("NO");

	
	int path[]
	return 0;
}
