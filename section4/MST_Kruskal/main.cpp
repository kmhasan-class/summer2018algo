#include <iostream>
using namespace std;

class Set {
public:
    int p;
    int rank;
};

class Edge {
public:
    int u;
    int v;
    int w;

    Edge() {
        u = 0;
        v = 0;
        w = 0;
    }

    Edge(int u, int v, int w) {
        this->u = u - 1;
        this->v = v - 1;
        this->w = w - 1;
    }

    void print() {
        cout << "(" << u + 1 << ", " << v + 1 << ", " << w + 1 << ")" << endl;
    }
};

class Graph {
private:
    int counter;
public:
    int V; // number of vertices
    int E; // number of edges
    Edge *edges;

    Graph(int V, int E) {
        this->V = V;
        this->E = E;
        edges = new Edge[E];
        counter = 0;
    }

    void addEdge(int u, int v, int w) {
        Edge edge(u, v, w);
        edges[counter++] = edge;
    }

    void print() {
        cout << "Vertices " << V << endl;
        cout << "Edges " << E << endl;

        for (int i = 0; i < counter; i++)
            edges[i].print();
    }
};

const int INF = 100000;

int compare(Edge e1, Edge e2) {
    // return -ve if e1.w < e2.w
    // return 0 if e1.w == e2.w
    // return +ve if e1.w > e2.w
    return e1.w - e2.w;
}

void merge(Edge A[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;

    // static declaration
    Edge L[n1 + 1];
    Edge R[n2 + 1];

    for (int i = 0; i < n1; i++)
        L[i] = A[p + i];

    for (int j = 0; j < n2; j++)
        R[j] = A[q + j + 1];

    L[n1] = Edge(0, 0, INF);
    R[n2] = Edge(0, 0, INF);

    int i = 0;
    int j = 0;

    for (int k = p; k <= r; k++)
        if (compare(L[i], R[j]) <= 0) {
//        if (L[i] <= R[j]) {
            A[k] = L[i];
            i = i + 1;
        } else {
            A[k] = R[j];
            j = j + 1;
        }
}

void mergeSort(Edge A[], int p, int r) {
    if (p < r) {
        //printArray(A, p, r);
        int q = (p + r) / 2;
        mergeSort(A, p, q);
        mergeSort(A, q + 1, r);
        merge(A, p, q, r);
    }
}

// page 571
void makeSet(Set sets[], int x) {
    sets[x].p = x;
    sets[x].rank = 0;
}

// page 571
int findSet(Set sets[], int x) {
    if (x != sets[x].p)
        sets[x].p = findSet(sets, sets[x].p);
    return sets[x].p;
}

// page 571
void link(Set sets[], int x, int y) {
    if (sets[x].rank > sets[y].rank)
        sets[y].p = x;
    else {
        sets[x].p = y;
        if (sets[x].rank == sets[y].rank)
            sets[y].rank = sets[y].rank + 1;
    }
}

// page 571
void setUnion(Set sets[], int x, int y) {
    link(sets, findSet(sets, x), findSet(sets, y));
}

// page 631
Edge* MST_Kruskal(Graph g) {
    Edge *A = new Edge[g.V - 1];
    int edgeCounter = 0;

    Set *sets = new Set[g.V];

    // line 2-3
    for (int v = 0; v < g.V; v++)
        makeSet(sets, v);

    // line 4
    mergeSort(g.edges, 0, g.E - 1);

    for (int e = 0; e < g.E; e++) {
        int u = findSet(sets, g.edges[e].u);
        int v = findSet(sets, g.edges[e].v);
        if (u != v) {
            A[edgeCounter++] = g.edges[e];
            setUnion(sets, g.edges[e].u, g.edges[e].v);
        }
    }

    delete sets;

    return A;
}

int main() {
    Graph g(7, 10);

    g.addEdge(4, 5, 9);
    g.addEdge(1, 7, 8);
    g.addEdge(2, 4, 1);
    g.addEdge(6, 7, 4);
    g.addEdge(1, 2, 2);
    g.addEdge(3, 7, 2);
    g.addEdge(2, 3, 3);
    g.addEdge(3, 5, 3);
    g.addEdge(5, 6, 6);
    g.addEdge(3, 6, 5);

    Edge *mstEdges = MST_Kruskal(g);

    int mstCost = 0;

    for (int e = 0; e < g.V - 1; e++) {
        mstEdges[e].print();
//        cout << mstEdges[e].w << endl;
        mstCost += mstEdges[e].w;
//        cout << mstCost << endl;
//        cout << endl;
    }

    // Got to fix this one
    cout << "MST Cost " << mstCost << endl;

    return 0;
}
