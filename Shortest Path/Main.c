#include <stdio.h>
#include <stdlib.h>
#include "ShortestPath.h"

#define scanf scanf_s

int main()
{
	int s, u;
	Graph G;
	scanf("%d%d%d", &G.n, &G.m, &s);
	G.N = (Node*)malloc(G.n * sizeof(Node));
	for (int i = 0; i < G.n; i++) {
		G.N[i].h = -1;
		G.N[i].cost = 0x7fffffff;
	}
	G.E = (Edge*)malloc(G.m * sizeof(Edge));
	for (int i = 0; i < G.m; i++) {
		scanf("%d%d%d", &u, &G.E[i].to, &G.E[i].w);
		G.E[i].to--;
		G.E[i].nxt = G.N[u - 1].h, G.N[u - 1].h = i;
	}
	Dijkstra(&G, s - 1);
	for (int i = 0; i < G.n; i++) {
		printf("%d ", G.N[i].cost);
	}
	free(G.N);
	free(G.E);

	return 0;
}