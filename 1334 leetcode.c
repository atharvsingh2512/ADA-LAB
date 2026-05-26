#include <stdio.h>
#include <stdlib.h>

#define INF 99999

int findTheCity(int n, int** edges, int edgesSize, int* edgesColSize, int distanceThreshold) {

    int dist[n][n];

    // Initialize distance matrix
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }

    // Fill edges (undirected graph)
    for(int i = 0; i < edgesSize; i++) {

        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        dist[u][v] = w;
        dist[v][u] = w;
    }

    // Floyd Warshall
    for(int k = 0; k < n; k++) {

        for(int i = 0; i < n; i++) {

            for(int j = 0; j < n; j++) {

                if(dist[i][k] != INF &&
                   dist[k][j] != INF &&
                   dist[i][k] + dist[k][j] < dist[i][j]) {

                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    int bestCity = -1;
    int minCount = INF;

    // Count reachable cities
    for(int i = 0; i < n; i++) {

        int count = 0;

        for(int j = 0; j < n; j++) {

            if(i != j && dist[i][j] <= distanceThreshold)
                count++;
        }

        // choose best city (tie → larger index)
        if(count <= minCount) {
            minCount = count;
            bestCity = i;
        }
    }

    return bestCity;
}