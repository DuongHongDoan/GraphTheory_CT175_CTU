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
int num[max_n], min_num[max_n], k, on_stack[max_n], count = 0, maxV=0;
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
		//count la dem so BPLT manh
		count++; 
		int w;
		int count_v=0;
		do {
			w = getTop(&S); 
			//count_v la tim BPLT manh co nhieu dinh nhat
			count_v++;
			pop(&S);
			on_stack[x] = 0;
		}while (w!=x);
		if (count_v > maxV)
			maxV = count_v;
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
/*in gia tri num va min_num*/
//	for (u=1; u<=n; u++)
//		printf ("%d %d\n",num[u], min_num[u]);

/*Kiem tra DT lien thong manh*/
	if (count == 1)
		printf ("STRONG CONNECTED");
	else
		printf ("DISCONNECTED");

/*Dem so BPLT manh*/
//	printf ("\n%d", count);

/*BPLT co dinh nhieu nhat*/
//	printf ("%d", maxV);
	return 0;
}

/*Thuat toan Tarjan khong dung cau truc List*/
//#include <stdio.h>
//#define max_n 50
//
//typedef struct {
//	int n, m;
//	int a[max_n][max_n];
//}Graph;
//
//void init_graph(Graph *pG, int n) {
//	pG->n = n;
//	pG->m = 0;
//	int u, v;
//	for (u=1; u<=n; u++){
//		for (v=1; v<=n; v++) {
//			pG->a[u][v] = 0;
//		}
//	}
//}
//
//void add_edge(Graph *pG, int u, int v) {
//	pG->a[u][v] += 1;
//	pG->m++;
//}
//
//int adjacent(Graph *pG, int u, int v) {
//	return pG->a[u][v] != 0;	
//}
//
//typedef struct {
//	int size;
//	int data[max_n];
//}Stack;
//
//void makenullStack(Stack *pS) {
//	pS->size = 0;
//}
//
//int empty(Stack *pS) {
//	return pS->size == 0;
//}
//
//int getTop(Stack *pS) {
//	return pS->data[pS->size];
//}
//
//void push(Stack *pS, int x) {
//	pS->size++;
//	pS->data[pS->size] = x;
//}
//
//void pop(Stack *pS) {
//	pS->size--;
//}
//
//int min(int a, int b) {
//	return a>b ? b : a;
//}
//
//int num[max_n], min_num[max_n], k, on_stack[max_n];
//Stack S;
//void SCC (Graph *pG, int u) {
//	num[u] = min_num[u] = k;
//	k++;
//	on_stack[u] = 1;
//	push(&S, u);
//	
//	int v;
//	for (v=1; v<=pG->n; v++) {
//		if (adjacent(pG, u, v)) {
//			if(num[v] < 0) {
//				SCC(pG, v);
//				min_num[u] = min(min_num[u], min_num[v]);
//			}
//			else if (on_stack[v])
//				min_num[u] = min(min_num[u], num[v]);
//		}
//	}
//	
//	if (num[u] == min_num[u]) {
//		int w;
//		do {
//			w = getTop(&S);
//			pop(&S);
//			on_stack[w] = 0;
//		}while(w!=u);
//	}
//}
//
//int main () {
//	Graph G;
//	int n, m, e, u, v;
//	freopen("dothi.txt", "r", stdin);
//	scanf ("%d%d", &n, &m);
//	init_graph(&G, n);
//	
//	for (e=1; e<=m; e++) {
//		scanf ("%d%d", &u, &v);
//		add_edge(&G, u, v);
//	}
//	
//	for (u=1; u<=n; u++) {
//		num[u] = -1;
//	}
//	k=1;
//	makenullStack(&S);
//	
//	int count=0;
//	for (u=1; u<=n; u++) 
//		if(num[u]<0){
//			count++;
//			SCC(&G, u);	
//		}
//		
//			
//	if(count==1)
//		printf ("STRONG CONNECTED");
//	else
//		printf ("DISCONNECTED");
//	return 0;	
//}
