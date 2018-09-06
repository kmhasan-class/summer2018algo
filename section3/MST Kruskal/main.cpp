#include <iostream>
using namespace std;

class Set {
public:
    int p;
    int rank;
};

class Edge {
public:
    int u; // starting vertex
    int v; // ending vertex
    int w; // weight

    Edge() {
        u = 0;
        v = 0;
        w = 0;
    }

    Edge(int u, int v, int w) {
        this->u = u;
        this->v = v;
        this->w = w;
    }

    void print() {
        cout << "(" << u + 1 << ", " << v + 1<< ", " << w << ")" << endl;
    }

    int compare(Edge *that) {
        return this->w - that->w;
    }
};
/*
Edge e1(1, 3, 5);
Edge e2(4, 2, 9);
e1.compare(e2);
compare(e1, e2);
*/
class Graph {
public:
    int V; // number of vertices
    int E; // number of edges
    Edge *edges;
    int counter;

    Graph(int V, int E) {
        this->V = V;
        this->E = E;
        counter = 0;
        edges = new Edge[E];
    }

    void addEdge(int u, int v, int w) {
        Edge e(u - 1, v - 1, w);
        edges[counter] = e;
        counter++;
    }

    void print() {
        cout << "Vertices " << V << endl;
        cout << "Edges " << E << endl;

        for (int i = 0; i < counter; i++)
            edges[i].print();
    }
};

int compare(Edge x, Edge y) {
    // if x < y, return -ve
    // if x > y, return +ve
    // if x == y, return 0
    return x.w - y.w;
}

const Edge INF(0, 0, 100000);
void merge(Edge A[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;

    Edge L[n1 + 1];
    Edge R[n2 + 1];

    for (int i = 0; i < n1; i++)
        L[i] = A[p + i];

    for (int j = 0; j < n2; j++)
        R[j] = A[q + j + 1];

    L[n1] = INF;
    R[n2] = INF;

    int i = 0;
    int j = 0;

    for (int k = p; k <= r; k++) {
        if (compare(L[i], R[j]) <= 0) {
        //if (L[i] <= R[j]) {
            A[k] = L[i];
            i = i + 1;
        } else {
            A[k] = R[j];
            j = j + 1;
        }
    }
}

// page 34
void mergeSort(Edge A[], int p, int r) {
    if (p < r) {
        //printArray(A, p, r);
        int q = (p + r) / 2;
        mergeSort(A, p, q);
        mergeSort(A, q + 1, r);
        merge(A, p, q, r);
    }
}

void makeSet(Set sets[], int x) {
    sets[x].p = x;
    sets[x].rank = 0;
}

int findSet(Set sets[], int x) {
    if (x != sets[x].p)
        sets[x].p = findSet(sets, sets[x].p);
    return sets[x].p;
}

void link(Set sets[], int x, int y) {
    if (sets[x].rank > sets[y].rank) {
        sets[y].p = x;
    } else {
        sets[x].p = y;
        if (sets[x].rank == sets[y].rank)
            sets[y].rank = sets[y].rank + 1;
    }
}

void setUnion(Set sets[], int x, int y) {
    link(sets, findSet(sets, x), findSet(sets, y));
}

// page 631
Edge* MST_Kruskal(Graph g) {
    Edge* A = new Edge[g.V - 1];
    int edgeCounter = 0;

    Set* sets = new Set[g.V];

    // line #2-3
    for (int v = 0; v < g.V; v++)
        makeSet(sets, v);

    // line #4
    mergeSort(g.edges, 0, g.E - 1);

    for (int e = 0; e < g.E; e++) {
        int u = findSet(sets, g.edges[e].u);
        int v = findSet(sets, g.edges[e].v);

        // line #6
        if (u != v) {
            // line #7
            A[edgeCounter++] = g.edges[e];
            setUnion(sets, g.edges[e].u, g.edges[e].v);
        }
    }

    delete sets;

    return A;
}

int main() {
    Graph g(7, 9);

    g.addEdge(1, 2, 2);
    g.addEdge(2, 5, 2);
    g.addEdge(3, 7, 9);
    g.addEdge(4, 5, 2);
    g.addEdge(5, 6, 3);
    g.addEdge(3, 6, 4);
    g.addEdge(2, 3, 3);
    g.addEdge(2, 6, 5);
    g.addEdge(1, 4, 4);

    Edge* mstEdges = MST_Kruskal(g);

    for (int e = 0; e < g.V - 1; e++)
        mstEdges[e].print();

    return 0;
}


