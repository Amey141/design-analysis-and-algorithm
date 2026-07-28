#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int parent[100];

int find(int i)
{
	while(parent[i] != i)
		i = parent[i];
	return i;
}

void Union(int i, int j)
{
	parent[find(i)] = find(j);
}

void kruskalMST(int **cost, int V)
{
	int minCost = 0;
	int edge = 0;

	for(int i = 0; i < V; i++)
		parent[i] = i;

	while(edge < V - 1)
	{
		int min = INT_MAX;
		int a = -1, b = -1;

		// Find minimum edge
		for(int i = 0; i < V; i++)
		{
			for(int j = i + 1; j < V; j++)
			{
				if(cost[i][j] < min)
				{
					min = cost[i][j];
					a = i;
					b = j;
				}
			}
		}

		if(find(a) != find(b))
		{
			printf("Edge %d:(%d, %d) cost:%d\n", edge, a, b, min);
			minCost += min;
			Union(a, b);
			edge++;
		}

		// Remove the edge so it isn't selected again
		cost[a][b] = cost[b][a] = INT_MAX;
	}

	printf("Minimum cost= %d\n", minCost);
}
int main() {
    int V;
    printf("No of vertices: ");
    scanf("%d", &V);

    int **cost = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++)
        cost[i] = (int *)malloc(V * sizeof(int));

    printf("Adjacency matrix:\n");
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &cost[i][j]);

    kruskalMST(cost, V);

    for (int i = 0; i < V; i++)
        free(cost[i]);
    free(cost);

    return 0;
}
