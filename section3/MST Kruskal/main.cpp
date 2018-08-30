#include <iostream>
using namespace std;

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
        cout << "(" << u << ", " << v << ", " << w << ")" << endl;
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
        Edge e(u, v, w);
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

    mergeSort(g.edges, 0, g.E - 1);

    g.print();
/*
    double data[] = {32.33, 15, 68.12, 97.39, 12, 14, 35, 64, 12, 19, 24};

    cout << "Before sorting "; printArray(data, 0, 10);
    mergeSort(data, 0, 10);
    cout << "After sorting  ";printArray(data, 0, 10);
*/
    return 0;
}


