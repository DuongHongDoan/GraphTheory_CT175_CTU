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
			pG->a[u][v] = 0;
		}
	}
}

void add_edge(Graph *pG, int u, int v, int w) {
	pG->a[u][v] = w;
}

int pi[max_n][max_n];
int next[max_n][max_n];
int negative_cycle = 0;
void FloydWarshall (Graph *pG) {
	int u, v, k;
	for (u=1; u<=pG->n; u++) {
		for (v=1; v<=pG->n; v++) {
			pi[u][v] = oo;
			next[u][v] = -1;
		}
	}
	
	for (u=1; u<=pG->n; u++) {
		pi[u][u] = 0;
	}
	
	for (u=1; u<=pG->n; u++) {
		for (v=1; v<=pG->n; v++) {
			if(pG->a[u][v] != 0) {
				pi[u][v] = pG->a[u][v];
				next[u][v] = v;
			}
		}
	}
	
	for (k=1; k<=pG->n; k++) {
		for (u=1; u<=pG->n; u++) {
			if (pi[u][k] == oo)    
			    continue;
			for (v=1; v<=pG->n; v++) {
				if (pi[k][v] == oo)   
			   		continue;
				if(pi[u][k] + pi[k][v] < pi[u][v]) {
					pi[u][v] = pi[u][k] + pi[k][v];
					next[u][v] = next[u][k];
				}
			}
		}
	}
	
	/*Kiem tra chu trinh am*/
	for(u=1; u<=pG->n; u++) {
		if(pi[u][u] < 0) {
			negative_cycle = 1;
			break;
		}
	}
}

int main () {
	Graph G;
	int n, m, e, u, v, w;
	freopen("dothi.txt", "r", stdin);
	scanf ("%d%d", &n, &m);
	init_graph(&G, n);
	
	for (e=1; e<=m; e++) {
		scanf ("%d%d%d", &u, &v, &w);
		add_edge(&G, u, v, w);
	}
	
	FloydWarshall(&G);
	
/*In chieu dai ngan nhat giua cac cap dinh*/
	for (u=1; u<=n; u++) {
		for (v=1; v<=n; v++) {
			if (pi[u][v] == oo)
				printf("%d -> %d: NO PATH\n", u, v);
			else 
				printf("%d -> %d: %d\n", u, v, pi[u][v]);
		}
	}

/*In duong di ngan nhat giua cac cap dinh*/
//	for (u=1; u<=n; u++) {
//		for (v=1; v<=n; v++) {
//			if (pi[u][v] < oo){
//				printf("path(%d, %d): %d", u, v, u);
//				int current = u;
//				while(current!=v) {
//					current = next[current][v];
//					printf (" -> %d", current);
//				}
//				printf ("\n");
//			}
//			else 
//				printf("path(%d, %d): NO PATH\n", u, v);
//		}
//	}

/*Kiem tra chu trinh am*/
//	if(negative_cycle == 1)
//		printf("YES");
//	else 
//		printf("NO");
//	return 0;
}
