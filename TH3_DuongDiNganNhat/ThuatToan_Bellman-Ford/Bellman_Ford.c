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
void BellmanFord(Graph *pG,int s) {
	int u, v, w,i, k;
	for (u=1; u<=pG->n; u++) {
		pi[u] = oo;
		p[u] = 0;
	}
	
	pi[s] = 0;
	p[s] = -1;
	
	
	for (i=1; i<pG->n; i++) {
		for (k=0; k<pG->m; k++) {
			u = pG->edges[k].u;
			v = pG->edges[k].v;
			w = pG->edges[k].w;
			if (pi[u] == oo)
				continue;
			if (pi[u] + w < pi[v]) {
				pi[v] = pi[u] + w;
				p[v] = u;
			}
		}
	}
	
	//Kiem tra chu trinh am
	for (k=0; k<pG->m; k++) {
		u = pG->edges[k].u;
		v = pG->edges[k].v;
		w = pG->edges[k].w;
		int t = pi[u] + w;
		if ((t<=oo && t>=900000)) {
			t = oo;
			if (t < pi[v]) {
				negative_cycle = 1;
				break;
			}
		}
		else if(t<oo) {
			if (t < pi[v]) {
				negative_cycle = 1;
				break;
			}
		}	
	}
}

//int BellmanFord(Graph *pG, int s) {
//	int u, v, w, it, k;
//	for (u = 1; u <= pG->n; u++) {
//		pi[u] = oo;
//	}
//	pi[s] = 0;
//	p[s] = -1; //truoc dinh s khong co dinh nao
//
//	// lap n-1 lan
//	for (it = 1; it < pG->n; it++) {
//		// Duyet qua các cung và cap nhat (neu thoa)
//		for (k = 0; k < pG->m; k++) {
//			u = pG->edges[k].u;
//			v = pG->edges[k].v;
//			w = pG->edges[k].w;
//			
//			if (pi[u] == oo)    //chua có duong di tu s -> u, bo qua cung này
//			    continue;
//			    
//			if (pi[u] + w < pi[v]) {
//				pi[v] = pi[u] + w;
//				p[v] = u;
//			}
//		}
//	}
//	//Làm thêm 1 lan nua de kiem tra chu trình âm (neu can thiet)
//	for (k = 0; k < pG->m; k++) {
//		u = pG->edges[k].u;
//		v = pG->edges[k].v;
//		w = pG->edges[k].w;
//		
//		if (pi[u] == oo)    //chua có duong di tu s -> u, bo qua cung này
//		    continue;
//		    
//		if (pi[u] + w < pi[v]) {
//			return 1;
//		}
//	}
//	return 0;
//}

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
	
//	scanf ("%d%d", &s, &t);
	BellmanFord(&G, 1);
/*kiem tra chu trinh am*/	
//	if (BellmanFord(&G, s)==1)
//		printf ("YES\n");
//	else 
//		printf ("NO\n");
	if (negative_cycle==1)
		printf ("YES\n");
	else 
		printf ("NO\n");
/*in ra chieu dai duong di ngan nhat va dinh truoc no*/	
	for (u=1; u<=n; u++) {
		printf ("pi[%d] = %d, p[%d] = %d\n", u, pi[u], u, p[u]);
	}
	
	return 0;
}
