#include <limits.h> 

		visited[nextnode] = 1;

		for (i = 1; i <= n; i++) {
			if (!visited[i] && G[nextnode][i] != 0 && i != nextnode) {
				if (mindistance + G[nextnode][i] < distance[i]) {
					distance[i] = mindistance + G[nextnode][i];
					pred[i] = nextnode;
				}
			}
		}
		count++;
	}

	printf("Node\tDistance\tPath\n");

	for (i = 1; i <= n; i++) {
		if (i != startnode) {
			if (distance[i] == INFINITY) {
				printf("%4d\t%8s\tNO PATH\n", i, "INF");
			} else {
				printf("%4d\t%8d\t%d", i, distance[i], i);
				j = i;
				do {
					j = pred[j];
					printf("<-%d", j);
				} while (j != startnode);
				printf("\n");
			}
		}
	}
	
	
}
int main() { 
	int s, d, w, i, j;
	printf("Enter the number of vertices : ");
	scanf("%d", &V);
	printf("Enter the number of edges : ");
	scanf("%d", &E);
	for(i = 1 ; i <= V; i++) {
		for(j = 1; j <= V; j++) {
			graph[i][i] = 0;
		}
	}
	for(i = 1; i <= E; i++) {
		printf("Enter source : ");
		scanf("%d", &s);
		printf("Enter destination : ");
		scanf("%d", &d);
		printf("Enter weight : ");
		scanf("%d", &w);
		if(s > V || d > V || s <= 0 || d <= 0) {
			printf("Invalid index. Try again.\n");
			i--;
			continue;
		} else {
			graph[s][d] = w;
		}
	}
	printf("Enter the source :");
	scanf("%d", &s);
	dijkstra(graph, V, s); 
	return 0; 
} 
