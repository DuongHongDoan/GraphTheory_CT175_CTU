#include <stdio.h>
#define Max_E 50
//-------------Khai bao struct Edge--------------
typedef struct {
	int u, v;
}Edge;
//-------------Khai bao struct Graph--------------
typedef struct {
	int n, m;
	Edge edges[Max_E];
}Graph;

void init_G(Graph *pG, int n) {
	pG->n = n;
	pG->m = 0;
}

void add_edge(Graph *pG, int u, int v) {
/*Basic*/
//	pG->edges[pG->m].u = u;
//	pG->edges[pG->m].v = v;
//	pG->m++;
/*Nang cao 1*/
//	pG->edges[pG->m].u = u;
//	pG->edges[pG->m].v = v;
//	if (u >= 1 || u <= pG->n || v <= pG->n || v >= 1) {
//		pG->m++;
//	}
/*Nang cao 2 - Xem Else => Da hieu*/	
	int i;
	for (i=0; i<pG->m; i++) 
		if (u == pG->edges[i].u && v == pG->edges[i].v) {
			return;
		}
	pG->edges[pG->m].u = u;
	pG->edges[pG->m].v = v;		
	pG->m++;
/*Nang cao 3 - Xem Else => Da hieu*/
//	int i;
//	for (i=0; i<pG->m; i++) 
//		if ((u == pG->edges[i].u && v == pG->edges[i].v) ||
//		     (v == pG->edges[i].u && u == pG->edges[i].v)) {
//			return;
//		}
//	pG->edges[pG->m].u = u;
//	pG->edges[pG->m].v = v;		
//	pG->m++;
}

int adjacent(Graph *pG, int u, int v) {
/*Vo huong*/
//	int e;
//	for (e=0; e<pG->m; e++)
//		if ((pG->edges[e].u == u && pG->edges[e].v == v) ||
//		    (pG->edges[e].u == v && pG->edges[e].v == u))
//		    return 1;
//	return 0;
/*Co huong*/
	int e;
	for (e=0; e<pG->m; e++)
		if ((pG->edges[e].u == u && pG->edges[e].v == v))
		    return 1;
	return 0;
}

int degree (Graph *pG, int u) {
	int e, deg = 0;
	for (e=0; e<pG->m; e++) {
		if (pG->edges[e].u == u)
			deg++;
		if (pG->edges[e].v == u)
			deg++;
	}
	return deg;
}

void neighbors(Graph *pG, int u) {
/*Vo huong, co huong deu nhu nhau*/
	int v;
	for (v = 1; v <= pG->n; v++)
	        if (adjacent(pG, u, v))
	            printf("%d ", v);
	printf("\n");
}

int main () {
	Graph G;
	
/*Function Test*/
	init_G(&G, 4);
add_edge(&G, 1, 1);
add_edge(&G, 1, 3);
add_edge(&G, 4, 2);
add_edge(&G, 2, 4);
add_edge(&G, 3, 1);
add_edge(&G, 5, 4);
add_edge(&G, 2, 4);
add_edge(&G, 3, 1);
 	
	if (adjacent(&G, 1, 2) == 1)
 		printf ("dinh ke\n");
 	else printf ("Khong ke\n");
 	
 	int u;
 	for (u=1; u<=G.n; u++) {
 		printf ("deg[%d] = %d\n", u, degree(&G, u));	
	}
	
	int e;
	for (e=0; e<G.m; e++) {
		printf ("%d %d\n", G.edges[e].u, G.edges[e].v);
	}
/*Nhap data tu ban phim*/
//	int n, m;
//	scanf ("%d%d", &n, &m);
//	init_G(&G, n);
//	
//	int e, u, v;
//	for (e=0; e<m; e++) {
//		scanf ("%d%d", &u, &v);
//		add_edge(&G, u, v);
//	}
//	
//	printf ("Danh sach cung dc nhap tu ban phim:\n");
//	for (e=0; e<G.m; e++) {
//		printf ("%d %d\n", G.edges[e].u, G.edges[e].v);
//	}
//	
//	printf ("Bac cua tat ca cac dinh:\n");
//	for (u=1; u<=G.n; u++) {
// 		printf ("deg[%d] = %d\n", u, degree(&G, u));	
//	}
/*Nhap data tu file*/
//	int n, m;
//	freopen("dothi.txt", "r", stdin);
//	scanf ("%d%d", &n, &m);
//	init_G(&G, n);
//	
//	int e, u, v;
//	for (e=0; e<m; e++) {
//		scanf ("%d%d", &u, &v);
//		add_edge(&G, u, v);
//	}
	
//	printf ("Danh sach cung dc nhap tu ban phim:\n");
//	for (e=0; e<G.m; e++) {
//		printf ("%d %d\n", G.edges[e].u, G.edges[e].v);
//	}
//	
//	printf ("Bac cua tat ca cac dinh:\n");
//	for (u=1; u<=G.n; u++) {
// 		printf ("deg[%d] = %d\n", u, degree(&G, u));	
//	}
	
//	for (u=1; u<=G.n; u++) {
// 		printf ("neighbours(%d) = ", u);
//		neighbors(&G, u);	
//	}
	return 0;
}
