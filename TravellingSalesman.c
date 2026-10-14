#include <stdio.h>
#include <stdlib.h>

#define INF 1e9


int min(int a, int b) {
    return (a < b) ? a : b;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

   
    int **dist = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        dist[i] = (int *)malloc(n * sizeof(int ));
        for (int j = 0; j < n; j++) {
            scanf("%d", &dist[i][j]);
        }
    }

    int num_states = 1 << n;
    
    
    int **dp = (int **)malloc(num_states * sizeof(int *));
    for (int i = 0; i < num_states; i++) {
        dp[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            dp[i][j] = INF;
        }
    }

    
    dp[1][0] = 0;

    
    for (int mask = 1; mask < num_states; mask++) {
        for (int u = 0; u < n; u++) {
            if (dp[mask][u] == INF) continue;

            
            for (int v = 0; v < n; v++) {
               
                if (!(mask & (1 << v)) && dist[u][v] != -1) {
                    int next_mask = mask | (1 << v);
                    dp[next_mask][v] = min(dp[next_mask][v], dp[mask][u] + dist[u][v]);
                }
            }
        }
    }

    
    int min_total_cost = INF;
    int all_visited_mask = num_states - 1;

    for (int u = 1; u < n; u++) {
        if (dp[all_visited_mask][u] != INF && dist[u][0] != -1) {
            min_total_cost = min(min_total_cost, dp[all_visited_mask][u] + dist[u][0]);
        }
    }

    
    if (min_total_cost == INF) {
        printf("-1\n"); 
    } else {
        printf("%d\n", min_total_cost);
    }

    
    for (int i = 0; i < num_states; i++) free(dp[i]);
    free(dp);
    for (int i = 0; i < n; i++) free(dist[i]);
    free(dist);

    return 0;
}

