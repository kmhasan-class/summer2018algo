#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

const int INF = 1000000;
const int NIL = -1;

class Vertex {
public:
    int v; // label/number/index
    int d; // distance
    int p; // parent

    Vertex() {
        v = NIL;
        d = INF;
        p = NIL;
    }

    Vertex(int label, int distance, int parent) {
        v = label;
        d = distance;
        p = parent;
    }

    void print() {
        if (v == NIL)
            cout << "NIL";
        else cout << v + 1;

        cout << ": ";

        if (d == INF)
            cout << "INF";
        else cout << d;

        cout << ", ";

        if (p == NIL)
            cout << "NIL";
        else cout << p + 1;

        cout << endl;
    }
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

int compare(Vertex v1, Vertex v2) {
    return v1.d - v2.d;
}

// Home Work: implement a MinHeap
// implement extractMin
class MinHeap {
public:
    Vertex *A;
    int length;
    int heapSize;

    MinHeap(Vertex *data, int n) {
        // major change from how it was implemented in class
        A = data;
        length = n;
        buildMinHeap();
    }

    MinHeap(int n) {
        A = new Vertex[n];
        length = 0;
    }

    bool isEmpty() {
        if (heapSize == 0)
            return true;
        else return false;

        //return heapSize == 0;
    }

    void addData(Vertex data) {
        A[length] = data;
        length++;
    }

    // page 157
    void buildMinHeap() {
        // line 1
        heapSize = length;
        for (int i = length / 2; i >= 0; i--)
            minHeapify(i);
    }

    int parent(int i) {
        return i / 2;
    }

    int left(int i) {
        return 2 * i;
    }

    int right(int i) {
        return 2 * i + 1;
    }

    void minHeapify(int i) {
        int l = left(i);
        int r = right(i);

        int smallest;

        // write a compare function
        // that compares two vertices
        // and use it in the following line
        //if (l < heapSize && A[l] < A[i])
        if (l < heapSize && compare(A[l], A[i]) < 0)
            smallest = l;
        else smallest = i;

        //if (r < heapSize && A[r] < A[smallest])
        if (r < heapSize && compare(A[r], A[smallest]) < 0)
            smallest = r;

        if (smallest != i) {
            Vertex temp = A[i];
            A[i] = A[smallest];
            A[smallest] = temp;
            minHeapify(smallest);
        }

    }

    Vertex extractMin() {
        if (heapSize < 1) {
            cerr << "Heap underflow" << endl;
            return Vertex();
        }

        Vertex min = A[0];
        A[0] = A[heapSize - 1];

        heapSize--;

        minHeapify(0);

        return min;
    }

    void print() {
        cout << "Heap contents:" << endl;
        for (int i = 0; i < heapSize; i++)
            A[i].print();
    }
};

class Graph {
public:
    int V; // number of vertices
    int E; // number of edges
    Vertex *vertices;
    Edge *edges;
    int edgeCounter;

    Graph(int V, int E) {
        this->V = V;
        this->E = E;
        edgeCounter = 0;
        edges = new Edge[E];
        vertices = new Vertex[V];
        for (int v = 0; v < V; v++)
            vertices[v].v = v;
    }

    ~Graph() {
        delete edges;
        delete vertices;
    }

    void addEdge(int u, int v, int w) {
        Edge e(u - 1, v - 1, w);
        edges[edgeCounter] = e;
        edgeCounter++;
    }

    void print() {
        cout << "Vertices " << V << endl;

        for (int i = 0; i < V; i++) {
            cout << i + 1 << ": ";
            vertices[i].print();
        }

        cout << "Edges " << E << endl;

        for (int i = 0; i < edgeCounter; i++) {
            cout << i + 1 << ": ";
            edges[i].print();
        }
    }

    // page 648
    void initializeSingleSource(int s) {
        for (int v = 0; v < V; v++) {
            vertices[v].d = INF;
            vertices[v].p = NIL;
        }
        vertices[s - 1].d = 0;
    }

    // page 658
    void dijkstra(int s) {
        // line 1
        initializeSingleSource(s);

        // line 2
        bool *S = new bool[V];
        for (int v = 0; v < V; v++)
            S[v] = false;

        // line 3
        MinHeap Q(vertices, V);

        Q.print();

        // line 4
        while (!Q.isEmpty()) {
            // line 5
            Vertex u = Q.extractMin();
            // line 6
            S[u.v] = true;

            // horrible implementation follows
            // refer to page 590 for a better
            // representation

            for (int e = 0; e < E; e++) {
                int adjU = NIL;
                if (edges[e].u == u.v) {
                    adjU = edges[e].v;
                } else if (edges[e].v == u.v) {
                    adjU = edges[e].u;
                }

                if (adjU != NIL) {
                    // call Relax (page 649)
                    // also call heapDecreaseKey (page 164)
                }
            }

        }

        delete S;
    }

};

int main() {
    int V, E;
    
    ifstream fin("graph.in");

    fin >> V >> E;

    Graph g(V, E);

    for (int e = 0; e < E; e++) {
        int u, v, w;
        fin >> u >> v >> w;
        g.addEdge(u, v, w);
    }

    g.dijkstra(5);
    
    g.print();

    fin.close();

    return 0;
}

