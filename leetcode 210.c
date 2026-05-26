#include <stdio.h>
#include <stdlib.h>

/**
 * returnSize is used by LeetCode to store output size
 */
int* findOrder(int numCourses,
               int** prerequisites,
               int prerequisitesSize,
               int* prerequisitesColSize,
               int* returnSize) {

    int* indegree = (int*)calloc(numCourses, sizeof(int));
    int** graph = (int**)malloc(numCourses * sizeof(int*));
    int* queue = (int*)malloc(numCourses * sizeof(int));
    int* result = (int*)malloc(numCourses * sizeof(int));

    for(int i = 0; i < numCourses; i++) {
        graph[i] = (int*)calloc(numCourses, sizeof(int));
    }

    // Build graph
    for(int i = 0; i < prerequisitesSize; i++) {

        int u = prerequisites[i][1];
        int v = prerequisites[i][0];

        if(graph[u][v] == 0) {
            graph[u][v] = 1;
            indegree[v]++;
        }
    }

    int front = 0, rear = 0;

    // push 0 indegree nodes
    for(int i = 0; i < numCourses; i++) {
        if(indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    int idx = 0;

    while(front < rear) {

        int node = queue[front++];
        result[idx++] = node;

        for(int i = 0; i < numCourses; i++) {

            if(graph[node][i]) {
                indegree[i]--;

                if(indegree[i] == 0) {
                    queue[rear++] = i;
                }
            }
        }
    }

    // If cycle exists
    if(idx != numCourses) {
        *returnSize = 0;
        return NULL;
    }

    *returnSize = numCourses;
    return result;
}