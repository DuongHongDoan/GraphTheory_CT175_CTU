/*Bai 1: voi do thi co huong sau
8 12
1 2 7
1 3 9
1 5 14
2 3 10
2 4 15
3 4 11
3 5 2
4 6 6 
5 6 9
6 7 6 
6 8 8 
7 8 1
*/
#define oo 999999
#define NO_EDGE 0
typedef struct {
    int A[MAX_N][MAX_N];
    int m, n;
} Graph;

int pi[MAX_N];//chieu dai duong di ngan nhat
int p[MAX_N];//luu cha cua dinh dang xet
int mark[MAX_N];

void Dijkstra(Graph *pG, int s=1) {
    for (int u = 1; u <= pG->n=8; u++) {
		mark[u] = 0;
        pi[u] = oo;
	}
         
    pi[s=1] = 0;
    p[s=1] = -1;
    
    
    for (int i = 1; i <= pG->n - 1; i++) {//Lap tu 1 den 8-1 = 7 lan
    //Lan lap 1
        int min_pi = oo;
        for (int j = 1; j <= pG->n; j++){
        	if (mark[j]==0 && pi[j] < min_pi) {
                min_pi = pi[j];//min_pi = pi[1] = 0
                u = j;// u = 1
            }
		}
            
        mark[u] = 1;//mark[1] = 1

		List L = neighbors(pG, u);// L = (2, 3, 5)
        for (int k = 1; k <= L.size; k++){
        	int v = getElement(&L, k);// v = 2
        	if (mark[v]==0) {//dung
            	if (pi[u] + pG->A[u][v] < pi[v]) {//7<oo  => dung
        			pi[v] = pi[u] + pG->A[u][v]; //pi[2] = 7
            		p[v] = u;	//p[2] = 1
				}
            }
            int v = getElement(&L, k);// v = 3
        	if (mark[v]==0) {//dung
            	if (pi[u] + pG->A[u][v] < pi[v]) {//9<oo => dung
        			pi[v] = pi[u] + pG->A[u][v]; //pi[3] = 9
            		p[v] = u;	//p[3] = 1
				}
            }
            int v = getElement(&L, k);// v = 5
        	if (pG->A[u][v] != NO_EDGE && mark[v]==0) {//dung
            	if (pi[u] + pG->A[u][v] < pi[v]) {//14<oo => dung
        			pi[v] = pi[u] + pG->A[u][v]; //pi[5] = 14
            		p[v] = u;	//p[5] = 1
				}
            }
		} 
	//Lan lap 2
        int min_pi = oo;
        for (int j = 1; j <= pG->n; j++){
        	if (mark[j]==0 && pi[j] < min_pi) {
                min_pi = pi[j];//min_pi = pi[2] = 7
                u = j;// u = 2
            }
		}
            
        mark[u] = 1;//mark[2] = 1

		List L = neighbors(pG, u);// L = (3, 4)
        for (int k = 1; k <= L.size; k++){
        	int v = getElement(&L, k);// v = 3
        	if (mark[v]==0) {//dung
            	if (pi[u] + pG->A[u][v] < pi[v]) {//17<9 => sai
				}
            }
            int v = getElement(&L, k);// v = 4
        	if (mark[v]==0) {//dung
            	if (pi[u] + pG->A[u][v] < pi[v]) {//22<oo => dung
        			pi[v] = pi[u] + pG->A[u][v]; //pi[4] = 22
            		p[v] = u;	//p[4] = 2
				}
            }
		} 
	//Lan lap 3
        int min_pi = oo;
        for (int j = 1; j <= pG->n; j++){
        	if (mark[j]==0 && pi[j] < min_pi) {
                min_pi = pi[j];//min_pi = pi[3] = 9
                u = j;// u = 3
            }
		}
            
        mark[u] = 1;//mark[3] = 1

		List L = neighbors(pG, u);// L = (4, 5)
        for (int k = 1; k <= L.size; k++){
            int v = getElement(&L, k);// v = 4
        	if (mark[v]==0) {//dung
            	if (pi[u] + pG->A[u][v] < pi[v]) {//20<22 => dung
        			pi[v] = pi[u] + pG->A[u][v]; //pi[4] = 20
            		p[v] = u;	//p[4] = 3
				}
            }
        	int v = getElement(&L, k);// v = 5
        	if (mark[v]==0) {//dung
            	if (pi[u] + pG->A[u][v] < pi[v]) {//11<14 => dung
            		pi[v] = pi[u] + pG->A[u][v]; //pi[5] = 11
            		p[v] = u;//p[5] = 3
				}
            }
		} 
	//Lan lap 4
        int min_pi = oo;
        for (int j = 1; j <= pG->n; j++){
        	if (mark[j]==0 && pi[j] < min_pi) {
                min_pi = pi[j];//min_pi = pi[5] = 11
                u = j;// u = 5
            }
		}
            
        mark[u] = 1;//mark[5] = 1

		List L = neighbors(pG, u);// L = (6)
        for (int k = 1; k <= L.size; k++){
            int v = getElement(&L, k);// v = 6
        	if (mark[v]==0) {//dung
            	if (pi[u] + pG->A[u][v] < pi[v]) {//20<oo => dung
        			pi[v] = pi[u] + pG->A[u][v]; //pi[6] = 20
            		p[v] = u;	//p[6] = 5
				}
            }
		} 
	//Lan lap 5
        int min_pi = oo;
        for (int j = 1; j <= pG->n; j++){
        	if (mark[j]==0 && pi[j] < min_pi) {
                min_pi = pi[j];//min_pi = pi[4] = 20
                u = j;// u = 4
            }
		}
            
        mark[u] = 1;//mark[4] = 1

		List L = neighbors(pG, u);// L = (6)
        for (int k = 1; k <= L.size; k++){
            int v = getElement(&L, k);// v = 6
        	if (mark[v]==0) {//dung
            	if (pi[u] + pG->A[u][v] < pi[v]) {//26<20 => sai
//        			pi[v] = pi[u] + pG->A[u][v]; //pi[6] = 20
//            		p[v] = u;	//p[6] = 5
				}
            }
		} 
	//Lan lap 6
        int min_pi = oo;
        for (int j = 1; j <= pG->n; j++){
        	if (mark[j]==0 && pi[j] < min_pi) {
                min_pi = pi[j];//min_pi = pi[6] = 20
                u = j;// u = 6
            }
		}
            
        mark[u] = 1;//mark[6] = 1

		List L = neighbors(pG, u);// L = (7, 8)
        for (int k = 1; k <= L.size; k++){
            int v = getElement(&L, k);// v = 7
        	if (mark[v]==0) {//dung
            	if (pi[u] + pG->A[u][v] < pi[v]) {//26<oo => dung
        			pi[v] = pi[u] + pG->A[u][v]; //pi[7] = 26
            		p[v] = u;	//p[7] = 6
				}
            }
            int v = getElement(&L, k);// v = 8
        	if (mark[v]==0) {//dung
            	if (pi[u] + pG->A[u][v] < pi[v]) {//28<oo => dung
        			pi[v] = pi[u] + pG->A[u][v]; //pi[8] = 28
            		p[v] = u;	//p[8] = 6
				}
            }
		}
	//Lan lap 7
        int min_pi = oo;
        for (int j = 1; j <= pG->n; j++){
        	if (mark[j]==0 && pi[j] < min_pi) {
                min_pi = pi[j];//min_pi = pi[7] = 26
                u = j;// u = 7
            }
		}
            
        mark[u] = 1;//mark[7] = 1

		List L = neighbors(pG, u);// L = (8)
        for (int k = 1; k <= L.size; k++){
            int v = getElement(&L, k);// v = 8
        	if (mark[v]==0) {//dung
            	if (pi[u] + pG->A[u][v] < pi[v]) {//27<28 => dung
        			pi[v] = pi[u] + pG->A[u][v]; //pi[8] = 27
            		p[v] = u;	//p[8] = 7

				}
            }
		}
    }
}

/*Bai 2: voi do thi vo huong sau
8 12
1 2 6
1 3 10
2 3 3
2 5 4
3 4 11
3 5 2
4 6 6
5 6 9
5 7 2
6 7 6
6 8 4
7 8 1
*/
#define oo 999999
#define NO_EDGE 0
typedef struct {
    int A[MAX_N][MAX_N];
    int m, n;
} Graph;

int pi[MAX_N];//chieu dai duong di ngan nhat
int p[MAX_N];//luu cha cua dinh dang xet
int mark[MAX_N];

void Dijkstra(Graph *pG, int s=1) {
    for (int u = 1; u <= pG->n=8; u++){
        mark[u] = 0;
        pi[u] = oo; 
    }
    pi[s=1] = 0;
    p[s=1] = -1;
    
    
    for (int i = 1; i <= pG->n - 1; i++) {//Lap tu 1 den 8-1 = 7 lan
    //Lan lap 1
        int min_pi = oo;
        for (int j = 1; j <= pG->n; j++){
        	if (mark[j]==0 && pi[j] < min_pi) {
                min_pi = pi[j];//min_pi = pi[1] = 0
                u = j;// u = 1
            }
		}
            
        mark[u] = 1;//mark[1] = 1

		List L = neighbors(pG, u);// L = (2, 3)
        for (int k = 1; k <= L.size; k++){
        	int v = getElement(&L, k);// v = 2
        	if (mark[v]==0) {//dung
            	if (pi[u] + pG->A[u][v] < pi[v]) {// 6<oo => dung
        			pi[v] = pi[u] + pG->A[u][v]; //pi[2] = 6
            		p[v] = u;	//p[2] = 1
				}
            }
            int v = getElement(&L, k);// v = 3
        	if (mark[v]==0) {//dung
            	if (pi[u] + pG->A[u][v] < pi[v]) {//10<oo => dung
        			pi[v] = pi[u] + pG->A[u][v]; //pi[3] = 10
            		p[v] = u;	//p[3] = 1
				}
            }
		} 
	//Lan lap 2
        int min_pi = oo;
        for (int j = 1; j <= pG->n; j++){
        	if (mark[j]==0 && pi[j] < min_pi) {
                min_pi = pi[j];//min_pi = pi[2] = 6
                u = j;// u = 2
            }
		}
            
        mark[u] = 1;//mark[2] = 1

		List L = neighbors(pG, u);// L = (1, 3, 4)
        for (int k = 1; k <= L.size; k++){
        	int v = getElement(&L, k);// v = 1
        	if (mark[v]==0) {//sai
//            	if (pi[u] + pG->A[u][v] < pi[v]) {//17<9 => sai
//				}
            }
            int v = getElement(&L, k);// v = 3
        	if (mark[v]==0) {//dung
            	if (pi[u] + pG->A[u][v] < pi[v]) {//9<10 => dung
            		pi[v] = pi[u] + pG->A[u][v]; //pi[3] = 9
            		p[v] = u;	//p[3] = 2
				}
            }
            int v = getElement(&L, k);// v = 4
        	if (mark[v]==0) {//dung
            	if (pi[u] + pG->A[u][v] < pi[v]) {//11<oo => dung
        			pi[v] = pi[u] + pG->A[u][v]; //pi[4] = 11
            		p[v] = u;	//p[4] = 2
				}
            }
		} 
	//Lan lap 3
        int min_pi = oo;
        for (int j = 1; j <= pG->n; j++){
        	if (mark[j]==0 && pi[j] < min_pi) {
                min_pi = pi[j];//min_pi = pi[3] = 9
                u = j;// u = 3
            }
		}
            
        mark[u] = 1;//mark[3] = 1

		List L = neighbors(pG, u);// L = (1, 2, 4, 5)
        for (int k = 1; k <= L.size; k++){
            int v = getElement(&L, k);// v = 1
        	if (mark[v]==0) {//sai
//            	if (pi[u] + pG->A[u][v] < pi[v]) {//20<22 => dung
//        			pi[v] = pi[u] + pG->A[u][v]; //pi[4] = 20
//            		p[v] = u;	//p[4] = 3
//				}
            }
        	int v = getElement(&L, k);// v = 2
        	if (mark[v]==0) {//sai
//            	if (pi[u] + pG->A[u][v] < pi[v]) {//11<14 => dung
//            		pi[v] = pi[u] + pG->A[u][v]; //pi[5] = 11
//            		p[v] = u;//p[5] = 3
//				}
            }
            int v = getElement(&L, k);// v = 4
        	if (mark[v]==0) {//dung
            	if (pi[u] + pG->A[u][v] < pi[v]) {//20<11 => sai
//        			pi[v] = pi[u] + pG->A[u][v]; //pi[4] = 20
//            		p[v] = u;	//p[4] = 3
				}
            }
        	int v = getElement(&L, k);// v = 5
        	if (mark[v]==0) {//dung
            	if (pi[u] + pG->A[u][v] < pi[v]) {//11<oo => dung
            		pi[v] = pi[u] + pG->A[u][v]; //pi[5] = 11
            		p[v] = u;//p[5] = 3
				}
            }
		} 
	//Lan lap 4
        int min_pi = oo;
        for (int j = 1; j <= pG->n; j++){
        	if (mark[j]==0 && pi[j] < min_pi) {
                min_pi = pi[j];//min_pi = pi[4] = 11
                u = j;// u = 4
            }
		}
            
        mark[u] = 1;//mark[4] = 1

		List L = neighbors(pG, u);// L = (2, 3, 6)
        for (int k = 1; k <= L.size; k++){
        	int v = getElement(&L, k);// v = 2
        	if (mark[v]==0) {//sai
//            	if (pi[u] + pG->A[u][v] < pi[v]) {//11<14 => dung
//            		pi[v] = pi[u] + pG->A[u][v]; //pi[5] = 11
//            		p[v] = u;//p[5] = 3
//				}
            }
            int v = getElement(&L, k);// v = 3
        	if (mark[v]==0) {//sai
//            	if (pi[u] + pG->A[u][v] < pi[v]) {//20<11 => sai
//        			pi[v] = pi[u] + pG->A[u][v]; //pi[4] = 20
//            		p[v] = u;	//p[4] = 3
//				}
            }
            int v = getElement(&L, k);// v = 6
        	if (mark[v]==0) {//dung
            	if (pi[u] + pG->A[u][v] < pi[v]) {//17<oo => dung
        			pi[v] = pi[u] + pG->A[u][v]; //pi[6] = 17
            		p[v] = u;	//p[6] = 4
				}
            }
		} 
	//Lan lap 5
        int min_pi = oo;
        for (int j = 1; j <= pG->n; j++){
        	if (mark[j]==0 && pi[j] < min_pi) {
                min_pi = pi[j];//min_pi = pi[5] = 11
                u = j;// u = 5
            }
		}
            
        mark[u] = 1;//mark[5] = 1

		List L = neighbors(pG, u);// L = (3, 6, 7)
        for (int k = 1; k <= L.size; k++){
        	int v = getElement(&L, k);// v = 3
        	if (mark[v]==0) {//sai
//            	if (pi[u] + pG->A[u][v] < pi[v]) {//11<14 => dung
//            		pi[v] = pi[u] + pG->A[u][v]; //pi[5] = 11
//            		p[v] = u;//p[5] = 3
//				}
            }
            int v = getElement(&L, k);// v = 6
        	if (mark[v]==0) {//dung
            	if (pi[u] + pG->A[u][v] < pi[v]) {//20<17 => sai
//        			pi[v] = pi[u] + pG->A[u][v]; //pi[6] = 20
//            		p[v] = u;	//p[6] = 5
				}
            }
            int v = getElement(&L, k);// v = 7
        	if (mark[v]==0) {//dung
            	if (pi[u] + pG->A[u][v] < pi[v]) {//13<oo => dung
        			pi[v] = pi[u] + pG->A[u][v]; //pi[7] = 13
            		p[v] = u;	//p[7] = 5
				}
            }
		} 
	//Lan lap 6
        int min_pi = oo;
        for (int j = 1; j <= pG->n; j++){
        	if (mark[j]==0 && pi[j] < min_pi) {
                min_pi = pi[j];//min_pi = pi[7] = 13
                u = j;// u = 7
            }
		}
            
        mark[u] = 1;//mark[7] = 1

		List L = neighbors(pG, u);// L = (5, 6, 8)
        for (int k = 1; k <= L.size; k++){
            int v = getElement(&L, k);// v = 5
        	if (mark[v]==0) {//sai
//            	if (pi[u] + pG->A[u][v] < pi[v]) {//27<28 => dung
//        			pi[v] = pi[u] + pG->A[u][v]; //pi[8] = 27
//            		p[v] = u;	//p[8] = 7o
//
//				}
            }
            int v = getElement(&L, k);// v = 6
        	if (mark[v]==0) {//dung
            	if (pi[u] + pG->A[u][v] < pi[v]) {//19<17 => sai
//        			pi[v] = pi[u] + pG->A[u][v]; //pi[8] = 27
//            		p[v] = u;	//p[8] = 7o

				}
            }
            int v = getElement(&L, k);// v = 8
        	if (mark[v]==0) {//dung
            	if (pi[u] + pG->A[u][v] < pi[v]) {//14<oo => dung
        			pi[v] = pi[u] + pG->A[u][v]; //pi[8] = 14
            		p[v] = u;	//p[8] = 7

				}
            }
		}
	//Lan lap 7
        int min_pi = oo;
        for (int j = 1; j <= pG->n; j++){
        	if (mark[j]==0 && pi[j] < min_pi) {
                min_pi = pi[j];//min_pi = pi[8] = 14
                u = j;// u = 8
            }
		}
            
        mark[u] = 1;//mark[8] = 1

		List L = neighbors(pG, u);// L = (6, 7)
        for (int k = 1; k <= L.size; k++){
            int v = getElement(&L, k);// v = 6
        	if (mark[v]==0) {//dung
            	if (pi[u] + pG->A[u][v] < pi[v]) {//18<17 => sai
//        			pi[v] = pi[u] + pG->A[u][v]; //pi[8] = 28
//            		p[v] = u;	//p[8] = 6
				}
            }
            int v = getElement(&L, k);// v = 7
        	if (mark[v]==0) {//sai
//            	if (pi[u] + pG->A[u][v] < pi[v]) {//26<oo => dung
//        			pi[v] = pi[u] + pG->A[u][v]; //pi[7] = 26
//            		p[v] = u;	//p[7] = 6
//				}
            }
		}
    }
}
