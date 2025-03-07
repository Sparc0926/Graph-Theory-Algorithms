#include <stdlib.h>
#include "ShortestPath.h"


static int* heap, cnt, * idx;  // heap and it's current size


static void heapify(Graph* G)
{
	heap = (int*)malloc((G->n + 1) * sizeof(int));
	idx = (int*)malloc(G->n * sizeof(int));
	for (int i = 0; i < G->n; i++)  heap[i + 1] = i, idx[i] = i + 1;
	cnt = G->n;
}


static void update(Graph* G, int i)  // move heap[i] to it's correct position
{
	for (; i != 1 && G->N[heap[i]].cost < G->N[heap[i >> 1]].cost; i >>= 1) {
		heap[0] = heap[i], heap[i] = heap[i >> 1], heap[i >> 1] = heap[0];
		idx[heap[i]] = i, idx[heap[i >> 1]] = i >> 1;
	}
}


static void pop(Graph* G)  // remove and return the top of the heap
{
	heap[0] = heap[1], heap[1] = heap[cnt], heap[cnt--] = heap[0];
	idx[heap[1]] = 1;
	for (int i = 1; i < (cnt >> 1) + 1;) {
		int m = i << 1;
		if ((m | 1) <= cnt && G->N[heap[m | 1]].cost < G->N[heap[m]].cost)  m |= 1;
		if (G->N[heap[i]].cost > G->N[heap[m]].cost) {
			heap[0] = heap[m], heap[m] = heap[i], heap[i] = heap[0];
			idx[heap[i]] = i, i = idx[heap[m]] = m;
		}
		else  break;
	}

}


void Dijkstra(Graph* G, int s)
{
	heapify(G);
	heap[s + 1] = 0, heap[1] = s;
	idx[0] = s + 1, idx[s] = 1;
	G->N[s].cost = 0;  // initial state
	// keep going whenever the heap isn't empty
	while (cnt) {
		pop(G);
		for (int i = G->N[heap[cnt + 1]].h; i != -1; i = G->E[i].nxt) {
			Edge* e = G->E + i;
			// update if new_cost < old_cost
			if (G->N[e->to].cost > G->N[heap[cnt + 1]].cost + e->w && G->N[heap[cnt + 1]].cost != 0x7fffffff) {
				G->N[e->to].cost = G->N[heap[cnt + 1]].cost + e->w;
				update(G, idx[e->to]);
			}
		}
	}
	free(heap), free(idx);
}