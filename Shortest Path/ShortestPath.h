#ifndef SHORTEST_PATH_H
#define	SHORTEST_PATH_H

typedef struct {
	// head edge index, cost
	int h, cost;
} Node;

typedef struct {
	int nxt, w, to;  // weight, to which node
} Edge;

typedef struct {
	Node* N;
	Edge* E;
	int n, m;  // |N| and |E|
} Graph;

void Dijkstra(Graph* G, int s);

#endif // SHORTEST_PATH_H