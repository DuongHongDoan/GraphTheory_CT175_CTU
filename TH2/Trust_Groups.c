#include <stdio.h>
#define max_n 50
#define max_e 50
#define max_s 50

/*---------------------Cau truc dothi--------------------------*/
typedef struct {
	int n, m;
	int a[max_n][max_n];
}Graph;

void init_graph(Graph *pG, int n) {
	int u, v;
	pG->n = n;
	pG->m = 0;
	for (u=1; u<=n; u++)
		for (v=1; v<=n; v++)
			pG->a[u][v] = 0;
}

void add_edge(Graph *pG, int u, int v) {
	pG->a[u][v] += 1;
}

/*---------------------Cau truc nganxep--------------------------*/
typedef struct {
	int top;
	int data[max_s];
}Stack;

void makenullStack (Stack *pS) {
	pS->top = max_s;
}

int getTop(Stack *pS) {
	return pS->data[pS->top];
}

void push (Stack *pS, int x) {
	pS->top--;
	pS->data[pS->top] = x;
}

void pop(Stack *pS) {
	pS->top++;
}
/*---------------------Cau truc danhsach--------------------------*/
typedef int ElementType;
typedef struct {
	ElementType data[max_e];
	int size;
}List;

void makenullList (List *pL) {
	pL->size = 0;
}

ElementType getElement(List *pL, int i) {
	return pL->data[i-1];
}

void push_back (List *pL, ElementType x) {
	pL->data[pL->size] = x;
	pL->size++;
}

List neighbors(Graph *pG, int u) {
	List L;
	makenullList(&L);
	int v;
	for (v=1; v<=pG->n; v++) {
		if (pG->a[u][v] > 0 ){
			push_back(&L, v);
		}
	}
	return L;
}
/*---------------------Ham kiem tra BPLT--------------------------*/
int min(int a,int b) {
	if (a < b)
		return a;
	return b;
}
Stack S;
int num[max_n], min_num[max_n], k, on_stack[max_n], count = 0;
void SCC (Graph *pG, int x) {
	num[x] = min_num[x] = k;
	k++;
	push(&S, x);
	on_stack[x] = 1;
	List L = neighbors(pG, x);
	int v;
	for (v=1; v<=L.size; v++) {
		int y = getElement(&L, v);
		if (num[y] < 0) {
			SCC(pG, y);
			min_num[x] = min(min_num[x], min_num[y]);
		}
		else if (on_stack[y])
			min_num[x] = min(min_num[x], num[y]);
	}
	
	if (num[x] == min_num[x]) {
		count++; 
		int w;
		do {
			w = getTop(&S); 
			pop(&S);
			on_stack[x] = 0;
		}while (w!=x);
	}
}

int main () {
	Graph G;
	int n, m;
	freopen("dothi.txt", "r", stdin);
	scanf ("%d%d", &n, &m);
	init_graph(&G, n);
	
	int e, u, v;
	for (e=1; e<=m; e++) {
		scanf ("%d%d",&u, &v);
		add_edge(&G, u, v);
	}
	
	for (u=1; u<=n; u++)
		num[u] = -1;
	
	makenullStack(&S);
	k=1;
	
	for (u=1; u<=n; u++) {
		if (num[u] < 0)
			SCC(&G, u);
	}
	printf ("%d", count);
	return 0;
}

