#include <iostream>
using namespace std;

const int INF = 1000000;
const int NIL = -1;

class Vertex {
public:
    int d; // distance
    int p; // parent

    Vertex() {
        d = INF;
        p = NIL;
    }

    Vertex(int distance, int parent) {
        d = distance;
        p = parent;
    }

    void print() {
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

// Home Work: implement a MinHeap
// implement extractMin
class MinHeap {
public:
    Vertex *A;
    int length;
    int heapSize;

    MinHeap(Vertex *data, int n) {
        A = new Vertex[n];
        length = n;
        for (int i = 0; i < n; i++)
            A[i] = data[i];
    }

    MinHeap(int n) {
        A = new Vertex[n];
        length = 0;
    }

    ~MinHeap() {
        delete A;
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
        if (l < heapSize && A[l] < A[i])
            smallest = l;
        else smallest = i;

        if (r < heapSize && A[r] < A[smallest])
            smallest = r;

        if (smallest != i) {
            int temp = A[i];
            A[i] = A[smallest];
            A[smallest] = temp;
            minHeapify(smallest);
        }

    }

    int extractMin() {
        if (heapSize < 1) {
            cerr << "Heap underflow" << endl;
            return -1;
        }

        int max = A[0];
        A[0] = A[heapSize - 1];

        heapSize--;

        minHeapify(0);

        return max;
    }

    void print() {
        for (int i = 0; i < heapSize; i++)
            cout << A[i] << " ";
        cout << endl;
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

        delete S;
    }

};

int main() {
    Graph g(7, 9);

    g.addEdge(1, 2, 2);
    g.addEdge(2, 5, 2);
    g.addEdge(4, 5, 2);
    g.addEdge(2, 3, 3);
    g.addEdge(5, 6, 3);
    g.addEdge(3, 6, 4);
    g.addEdge(1, 4, 4);
    g.addEdge(2, 6, 5);
    g.addEdge(3, 7, 9);

    g.dijkstra(7);
    g.print();

    int data[] = {53, 13, 20, 67, 99};
    int n = 5;
    MinHeap h(data, n);
    /*
    MinHeap h(5);
    h.addData(53);
    h.addData(13);
    h.addData(20);
    h.addData(67);
    h.addData(99);
    */
    h.buildMinHeap();
    h.print();
/*
    int data[] = {5, 2, 1, 6, 34, 7, 2, 6, 19};
    int n = 9;

    MinHeap h(data, n);
    h.print();
    h.buildMinHeap();
    h.print();

    cout << h.extractMin() << endl;

    h.print();

    cout << h.extractMin() << endl;

    h.print();
*/
    return 0;
}

