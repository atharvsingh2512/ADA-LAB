#include <stdio.h>
#include <stdlib.h>

#define MAX 30

// Structure for edge
struct Edge {
    int src, dest, weight;
};

// Structure for subset
struct Subset {
    int parent;
};

// Find function
int find(struct Subset subsets[], int i) {

    while(subsets[i].parent != i)
        i = subsets[i].parent;

    return i;
}

// Union function
void Union(struct Subset subsets[], int x, int y) {

    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    subsets[xroot].parent = yroot;
}

// Compare function for sorting
int compare(const void *a, const void *b) {

    return ((struct Edge*)a)->weight -
           ((struct Edge*)b)->weight;
}

void kruskal(struct Edge edges[], int V, int E) {

    struct Edge result[MAX];

    struct Subset subsets[MAX];

    int e = 0;
    int i = 0;

    // Sort edges by weight
    qsort(edges, E, sizeof(edges[0]), compare);

    // Initialize subsets
    for(int v = 0; v < V; v++)
        subsets[v].parent = v;

    while(e < V - 1 && i < E) {

        struct Edge next = edges[i++];

        int x = find(subsets, next.src);
        int y = find(subsets, next.dest);

        // If no cycle
        if(x != y) {

            result[e++] = next;
            Union(subsets, x, y);
        }
    }

    printf("Edges in Minimum Spanning Tree:\n");

    int total = 0;

    for(i = 0; i < e; i++) {

        printf("%d -- %d == %d\n",
               result[i].src,
               result[i].dest,
               result[i].weight);

        total += result[i].weight;
    }

    printf("Total Cost = %d\n", total);
}

int main() {

    int V = 4; // vertices
    int E = 5; // edges

    struct Edge edges[] = {

        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    kruskal(edges, V, E);

    return 0;
}