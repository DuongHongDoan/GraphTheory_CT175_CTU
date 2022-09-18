#include <stdio.h> 
#define max_n 50
#define max_e 50
typedef struct {
	int n, m;
	int a[max_n][max_n];
}Graph;

void init_graph (Graph *pG, int n) 
void add_edge (Graph *pG, int u, int v) 
List neightbors(Graph *pG, int u)

typedef struct {
	int data[max_S];
	int top;
}Stack;

void makenullStack(Stack *pS) 

int getTop (Stack *pS) 

void push (Stack *pS, int x)

void pop (Stack *pS) 

typedef int ElementType;
typedef struct {
	ElementType data[max_e];
	int size;
}List;

void makenullList (List *pL)
ElementType getElement(List *pL,int i)

 
void SCC (Graph *pG, int x=1) {
	num[x=1] = min_num[x=1] = 1;
	k++;// k=2
	push(&S, 1);// S = {1}
	on_stack[x=1] = 1;
	
	List L = neightbors(pG, x=1);// L = {2, 6}
	int j;
	for (j=1; j<=L.size; j++) {
    //y=2
		int y = getElement(&L, j);// y=2
		if (num[y=2] < 0) {//dung
//De Quy x=2
			SCC(pG, y=2);
            num[x=2] = min_num[x=2] = 2;
            k++;//k=3
            push(&S, 2);//S = {1, 2}
            on_stack[2] = 1;
            
            List L = neightbors(pG, 2); //L={3}
            int j;
            for (j=1; j<=L.size; j++) {
            //y=3
                int y = getElement(&L, j);// y= 3
                if (num[y] < 0) {//dung
//De quy x=3
                    SCC(pG, y=3);
                    num[x=3] = min_num[x=3] = 3;
                    k++;// k=4
                    push(&S, x=3);//S={1, 2, 3}
                    on_stack[x=3] = 1;
                    
                    List L = neightbors(pG, x=3);//L={2, 4}
                    int j;
                    for (j=1; j<=L.size; j++) {
                    //y=2
                        int y = getElement(&L, j);// y=2
                        if (num[y] < 0) {//sai
                        }
                        else if (on_stack[y=2])
                            min_num[x=3] = min(min_num[x=3], num[y=2]);//min-num[3] = min(3, 2) = 2
                    //y=4
                        int y = getElement(&L, j);//y=4
                        if (num[y] < 0) {//dung
//De quy x=4
                            SCC(pG, y=4);
                            num[x=4] = min_num[x=4] = 4;
                            k++;//k=5
                            push(&S, x=4);// S={1, 2, 3, 4}
                            on_stack[x=4] = 1;
                            
                            List L = neightbors(pG, x=4);//L={8}
                            int j;
                            for (j=1; j<=L.size; j++) {
                            //y=8
                                int y = getElement(&L, j);//y=8
                                if (num[y] < 0) {//dung
//De quy x=8
                                    SCC(pG, y=8);
                                    num[x=8] = min_num[x=8] = 5;
                                    k++;//k=6
                                    push(&S, x=8);//S={1,2,3,4,8}
                                    on_stack[x=8] = 1;
                                    
                                    List L = neightbors(pG, x=8);//L={4,7}
                                    int j;
                                    for (j=1; j<=L.size; j++) {
                                    //y=4
                                        int y = getElement(&L, j);//y=4
                                        if (num[y] < 0) {//sai
                                        }
                                        else if (on_stack[y=4])
                                            min_num[x=8] = min(min_num[x=8], num[y=4]);//min_num[8]=min(5,4)=4
                                    //y=7
                                        int y = getElement(&L, j);//y=7
                                        if (num[y] < 0) {//dung
//De quy x=7
                                            SCC(pG, y=7);
                                            num[x=7] = min_num[x=7] = 6;
                                            k++;//k=7
                                            push(&S, x=7);//S={1,2,3,4,8,7}
                                            on_stack[x=7] = 1;
                                            
                                            List L = neightbors(pG, x=7);//L={3,8}
                                            int j;
                                            for (j=1; j<=L.size; j++) {
                                            //y=3
                                                int y = getElement(&L, j);//y=3
                                                if (num[y] < 0) {//sai
                                                }
                                                else if (on_stack[y=3])
                                                    min_num[x=7] = min(min_num[x=7], num[y=3]);//min_num[7]=min(7,3)=3
                                            //y=8
                                                int y = getElement(&L, j);
                                                if (num[y] < 0) {//sai
                                                }
                                                else if (on_stack[y=8])
                                                    min_num[x=7] = min(min_num[x=7], num[y=8]);//min_num[7]=min(3,5)=3
                                            }
                                            printf ("min_num[%d] = %d\n", x=7, min_num[x=7]);//min_num[7] = 3
                                            
                                            if (num[x=7] == min_num[x=7]) {//sai
                                            }
                                            min_num[x=8] = min(min_num[x=8], min_num[y=7]);//min_num[8]=min(4,3)=3
                                        }
                                    }
                                    printf ("min_num[%d] = %d\n", x=8, min_num[x=8]);//min_num[8]=3
                                    
                                    if (num[x=8] == min_num[x=8]) {//sai
                                    }
                                    min_num[x=4] = min(min_num[x=4], min_num[y=8]);//min_num[4]=min(4,3)=3
                                }
                            }
                            printf ("min_num[%d] = %d\n", x=4, min_num[x=4]);//min_num[4]=3
                            
                            if (num[x=4] == min_num[x=4]) {//sai
                            }
                            min_num[x=3] = min(min_num[x=3], min_num[y=4]);//min_num[3]=min(2,3)=2
                        }
                    }
                    printf ("min_num[%d] = %d\n", x=3, min_num[x=3]);//min_num[3]=2
                    
                    if (num[x=3] == min_num[x=3]) {//sai
                    }
                    min_num[x=2] = min(min_num[x=2], min_num[y=3]);//min_num[2]=min(2,2)=2
                }
            }
            printf ("min_num[%d] = %d\n", x=2, min_num[x=2]);//min_num[2]=2
            
            if (num[x=2] == min_num[x=2]) {//dung
                printf ("%d la dinh khop.\n", x=2);//2 la dinh khop.
                int w;
                do {
                    w = getTop(&S);// w=7
                    pop(&S);//S={1,2,3,4,8}
                    on_stack(w=7) = 0;
                }while(7 != x=2);
                do {
                    w = getTop(&S);// w=8
                    pop(&S);//S={1,2,3,4}
                    on_stack(w=8) = 0;
                }while(8 != x=2);
                do {
                    w = getTop(&S);// w=4
                    pop(&S);//S={1,2,3}
                    on_stack(w=4) = 0;
                }while(4 != x=2);
                do {
                    w = getTop(&S);// w=3
                    pop(&S);//S={1,2}
                    on_stack(w=3) = 0;
                }while(3 != x=2);
                do {
                    w = getTop(&S);// w=2
                    pop(&S);//S={1}
                    on_stack(w=2) = 0;
                }while(2 != x=2);//sai->dung vong lap
            }
			min_num[x=1] = min(min_num[x=1], min_num[y=2]);//min_num[1]=min(1,2)=1
		}

    //y=6
        int y = getElement(&L, j);// y=6
		if (num[y=6] < 0) {//dung
//De quy x=6
			SCC(pG, y=6);
            num[x=6] = min_num[x=6] = 7;
            k++;//k=8
            push(&S, x=6);//S={1,6}
            on_stack[x=6] = 1;
            
            List L = neightbors(pG, x=6);//l={2,5,7}
            int j;
            for (j=1; j<=L.size; j++) {
            //y=2
                int y = getElement(&L, j);//y=2
                else{//dung
                }
            //y=5
                int y = getElement(&L, j);//y=5
                if (num[y=5] < 0) {//dung
//De quy x=5
                    SCC(pG, y=5);
                    num[x=5] = min_num[x=5] = 8;
                    k++;//k=9
                    push(&S, x=5);//S={1,6,5}
                    on_stack[x=5] = 1;
                    
                    List L = neightbors(pG, x=5);//L={1}
                    int j;
                    for (j=1; j<=L.size; j++) {
                    //y=1
                        int y = getElement(&L, j);//y=1
                        if (num[y] < 0) {//sai
                        }
                        else if (on_stack[y=1])
                            min_num[x=5] = min(min_num[x=5], num[y=1]);//min_num[5]=min(8,1)=1
                    }
                    printf ("min_num[%d] = %d\n", x=5, min_num[x=5]);//min_num[5]=1
                    
                    if (num[x=5] == min_num[x=5]) {//sai
                    }
                    min_num[x=6] = min(min_num[x=6], min_num[y=5]);//min_num[6]=min(7,1)=1
                }
            //y=7
                int y = getElement(&L, j);//y=7
                else{//dung
                }
            }
            printf ("min_num[%d] = %d\n", x, min_num[x]);//min_num[6]=1
            
            if (num[x] == min_num[x]) {//sai
            }
			min_num[x=1] = min(min_num[x=1], min_num[y=6]);//min_num[1]=min(1,1)=1
		}
	}
	printf ("min_num[%d] = %d\n", x=1, min_num[x=1]);//min_num[1]=1
	
	if (num[x=1] == min_num[x=1]) {//dung
		printf ("%d la dinh khop.\n", x);//1 la dinh khop.
		int w;
		do {
			w = getTop(&S);//w=5
			pop(&S);//S={1,6}
			on_stack(w=5) = 0;
		}while(5 != 1);
        do {
			w = getTop(&S);//w=6
			pop(&S);//S={1}
			on_stack(w=6) = 0;
		}while(6 != 1);
        do {
			w = getTop(&S);//w=1
			pop(&S);//S={}
			on_stack(w=1) = 0;
		}while(1 == 1);//dung->thoat vong lap
	}
}

int main () {
	Graph G;
	freopen("dothi.txt", "r", stdin);
	int n, m;
	scanf ("%d%d", &n, &m);
	init_G(&G, n);
	int u, v, e;
	for (e=1; e<=m; e++) {
		scanf ("%d%d", &u, &v);
		add_edge(&G, u, v);
	}
	
	SCC(&G, 1);
	return 0;
/*Kq hien thi:
	
*/
	
}
