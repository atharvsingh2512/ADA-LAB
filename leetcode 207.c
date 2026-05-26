#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {

    int* indegree = (int*)calloc(numCourses, sizeof(int));
    int** graph = (int**)malloc(numCourses * sizeof(int*));
    int* queue = (int*)malloc(numCourses * sizeof(int));

    for(int i = 0; i < numCourses; i++) {
        graph[i] = (int*)calloc(numCourses, sizeof(int));
    }

    // Build graph + indegree
    for(int i = 0; i < prerequisitesSize; i++) {
        int u = prerequisites[i][1];
        int v = prerequisites[i][0];

        if(graph[u][v] == 0) {
            graph[u][v] = 1;
            indegree[v]++;
        }
    }

    int front = 0, rear = 0;

    // push all 0 indegree nodes
    for(int i = 0; i < numCourses; i++) {
        if(indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    int count = 0;

    while(front < rear) {

        int node = queue[front++];
        count++;

        for(int i = 0; i < numCourses; i++) {

            if(graph[node][i]) {
                indegree[i]--;

                if(indegree[i] == 0) {
                    queue[rear++] = i;
                }
            }
        }
    }

    return count == numCourses;
}