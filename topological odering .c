#include <stdio.h>

#define MAX 10

int graph[MAX][MAX];
int visited[MAX];
int stack[MAX];
int top = -1;
int n;

// DFS function
void dfs(int v) {

    visited[v] = 1;

    for(int i = 0; i < n; i++) {

        if(graph[v][i] == 1 && !visited[i]) {

            dfs(i);
        }
    }

    // Push vertex into stack
    stack[++top] = v;
}

// Topological Sort Function
void topologicalSort() {

    for(int i = 0; i < n; i++) {

        if(!visited[i]) {

            dfs(i);
        }
    }

    printf("\nTopological Ordering:\n");

    while(top != -1) {

        printf("%d ", stack[top--]);
    }
}

int main() {

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for(int i = 0; i < n; i++) {

        for(int j = 0; j < n; j++) {

            scanf("%d", &graph[i][j]);
        }
    }

    topologicalSort();

    return 0;
}