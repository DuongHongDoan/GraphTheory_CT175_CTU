#include <stdio.h>
#define max_n 50
#define max_e 100

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

void add_edge(Graph *pG, int u, int v) {
	pG->a[u][v] = 1;
	pG->m++;
}

typedef int ElementType;
typedef struct {
	ElementType data[max_e];
	int size;
}List;

void makenullList(List *pL) {
	pL->size = 0;
}

void addList (List *pL, ElementType x) {
	pL->data[pL->size] = x;
	pL->size++;
}

int getElement(List *pL, int i) {
	return pL->data[i-1];
}

void copyList(List *pL1, List *pL2) {
	makenullList(pL1);
	int i;
	for (i=1; i<=pL2->size; i++) {
		addList(pL1, getElement(pL2, i));
	}
}

int r[max_n]; // Luu hang cua dinh
void topo_rank(Graph *pG) {
	// 1. Tinh bac vao cua cac dinh u
	int d[max_n];
	int u, x;
	for (u=1; u<=pG->n; u++) {
		d[u] = 0;
		for (x=1; x<=pG->n; x++) {
			if (pG->a[x][u] != 0)
				d[u]++;
		}
	}
	
	// 2. Khoi tao danh sach L1. Tim goc d[u]=0 dua vao danh sach L1
	List L1;
	makenullList(&L1);
	for (u=1; u<=pG->n; u++) {
		if (d[u] == 0)
			addList (&L1, u);
	}
	
	// 3. Lap den khi danh sach L1 rong thi dung
	int k = 0; // Khoi tao hang dau tien k=0
	while (L1.size > 0) {
		//3.1. Khoi tao danh sach L2 va lay cac phan tu trong L1 ra xep hang
		List L2;
		makenullList(&L2);
		int i;
		for (i=1; i<=L1.size; i++) {
			// 3.1.1. Xep hang cac phan tu trong L1
			u = getElement(&L1, i);
			r[u] =k;
			// 3.1.2. Xoa dinh u <=> giam bac vao cac dinh ke v cua u va neu d[v]=0 thi dua v vao L2
			int v;
			for (v=1; v<=pG->n; v++) {
				if(pG->a[u][v] != 0){
					d[v]--;
					if (d[v] == 0)
						addList(&L2, v);
				}
			}
		}
		// 3.2. Copy L2 vao L1
		copyList(&L1, &L2);
		k++;
	}
}

int main () {
	Graph G;
	int n, m, e, u, v;
	freopen("dothi.txt", "r", stdin);
	scanf ("%d%d", &n, &m);
	init_graph(&G, n);
	for (e=1; e<=m; e++) {
		scanf ("%d%d", &u, &v);
		add_edge(&G, u, v);
	}
	
	topo_rank(&G);
	int i;
	for (i=1; i<=n; i++) {
		printf ("r[%d] = %d\n", i, r[i]);
	}
	
	return 0;
}
