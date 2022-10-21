#include <stdio.h>
#define max_n 50
#define max_S 50

/*-----------Cau truc Dt--------------*/
typedef struct {
	int n, m;
	int a[max_n][max_n];
}Graph;

void init_graph(Graph *pG, int n) {
	pG->n = n;
	pG->m = 0;
	int u, v;
	for (u=1; u<=n; u++)
		for (v=1; v<=n; v++)
			pG->a[u][v] = 0;
}

void add_edge(Graph *pG, int u, int v) {
/*Vo huong*/
	pG->a[u][v] += 1;
	if (u != v)
		pG->a[v][u] += 1;
	pG->m++;
/*Co huong*/
//	pG->a[u][v] += 1;
//	pG->m++;
}

int adjacent(Graph *pG, int u, int v) {
	return pG->a[u][v] != 0;
}

/*-----------Cau truc ngan xep--------------*/
typedef struct {
	int data[max_S];
	int top;
}Stack;

void makenullStack(Stack *pS) {
	pS->top = max_S;
}

int empty(Stack *pS) {
	return pS->top == max_S;
}

int getTop (Stack *pS) {
	return pS->data[pS->top];
}

void push (Stack *pS, int x) {
	pS->top--;
	pS->data[pS->top] = x;
}

void pop (Stack *pS) {
	pS->top++;
}

/*-----------Ham duyet do thi theo chieu sau--------------*/
int mark[max_n];
void DFS(Graph *pG, int s) {
	// 1. Tao ngan xep
	Stack S;
	makenullStack(&S);
	
	// 2. Dua phan tu dau tien can xet vao Ngan xep
	push(&S, s);
	
	//3. Lap cho den khi Ngan xep rong
	while (!empty(&S)) {
		//3.1. Lay phan tu dau ngan xep ra xet va xoa no di
		int u = getTop(&S);
		pop(&S);
		
		//3.2. Kiem tra u duyet roi thi bo qua
		if(mark[u] != 0)
			continue;
		//3.3. Neu chua duyet thi danh dau da duyet
		printf ("%d\n", u);
		mark[u] = 1;
		
		//3.4. Xet cac dinh ke v cua u va v chua duoc duyet
		int v;
		for (v=1; v<=pG->n; v++) {
			if (pG->a[u][v] != 0 && mark[v] == 0)
				push(&S, v);
		}
	}
}

/*-----------Ham main--------------*/
int main () {
	Graph G;
	int n, m, e, u, v;
	freopen("dothi.txt", "r", stdin);
	scanf ("%d%d", &n, &m);
	init_graph (&G, n);
	for (e=1; e<=m; e++) {
		scanf ("%d%d", &u, &v);
		add_edge(&G, u, v);
	}
	
	int i;
	for (i=1; i<=n; i++)
		mark[i] = 0;
		
/*Duyet dinh bat ky*/
//	int s;
//	scanf ("%d", &s);	
//	DFS(&G, s);
/*Duyet dinh cu the*/	
	DFS(&G, 1);
/*Duyet toan bo do thi*/
//	for (i=1; i<=n; i++) {
//		if (mark[i] == 0)
//			DFS(&G, i);
//	}
}
