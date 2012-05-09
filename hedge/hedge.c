/**
breno@breno-laptop ~/Documentos/UFSCar/icpc2011/hedge $ time gcc hedge.c -o hedge

	real	0m7.956s
	user	0m7.240s
	sys		0m0.612s
breno@breno-laptop ~/Documentos/UFSCar/icpc2011/hedge $ time ./hedge < hedge.in > hedge.out

	real	0m0.611s
	user	0m0.452s
	sys		0m0.116s
**/

#include <stdio.h>
#include <stdlib.h>
#define M 10001

int low[M], prt[M], vis[M], visH[M], R = 0, order = 0, G[M][M], H[M][M], sccN = 0;

inline int min(a, b){
	return a < b ? a : b;
}

inline void arc(int v, int w){
	int p = G[v][0] + 1, i = 0;
	
	for(i = 1; i < p; i++)
		if(G[v][i] == w)
			return;
	
	G[v][0] = p;
	G[v][p] = w;
}

inline void arcH(int v, int w){
	int p = H[v][0] + 1, i = 0;
	
	for(i = 1; i < p; i++)
		if(H[v][i] == w)
			return;
	
	H[v][0] = p;
	H[v][p] = w;	
}

inline void edge(int v, int w){
	arc(v, w);
	arc(w, v);
}

inline void edgeH(int v, int w){
	arcH(v, w);
	arcH(w, v);
}

void bridges(int v){
	int w = 0, i = 0;
	
	vis[v] = order;
	low[v] = order++;
	
	for(i = 1; i <= G[v][0]; i++){
		w = G[v][i];
	
		if(vis[w] < 0){
	
			prt[w] = v;
			bridges(w);
		
			low[v] = min(low[w], low[v]);
			
			if(low[w] == vis[w])
				edgeH(v, w);
			
		}else if(prt[v] != w)
			low[v] = min(low[v], vis[w]);
	}
}

void dfs(int v){
	int w = 0, i = 0;

	visH[v] = sccN;

	for(i = 1; i <= H[v][0]; i++){
		w = H[v][i];
		
		if(visH[w] < 0)
			dfs(w);
	}
}

int main(){

	int i = 0, j = 0, c = 0, q = 0, v = 0, w = 0;
	
	
	while(1){
		scanf("%d %d %d", &R, &c, &q);
		
		if(!R && !c && !q)
			break;
		
		for(i = 0; i < R; i++){
			G[i][0] = 0;
			H[i][0] = 0;
			
			low[i] = -1;
			prt[i] = -1;
			vis[i] = -1;
			visH[i] = -1;
		}		
		
		order = 0;		
		sccN = 0;
		
		for(i = 0; i < c; i++){
			scanf("%d %d", &v, &w);
			edge(v - 1, w - 1);
		}

		
		for(i = 0; i < R; i++){
			if(vis[i] < 0){
				prt[i] = i;
				bridges(i);
			}
		}
		
		for(i = 0; i < R; i++){
			if(visH[i] < 0){
				sccN++;
				dfs(i);
			}
		}
		
		for(i = 0; i < q; i++){
			scanf("%d %d", &v, &w);
				
			if(visH[v - 1] == visH[w - 1])
				printf("Y\n");
			else
				printf("N\n");
		}
		
		printf("-\n");
		
	}

	return 0;
}
