#include <iostream>
#include <cstdlib>
using namespace std;

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

const int INF = 1000000;
const int NIL = -1;

class Vertex {
public:
    int v; // the vertex number/index
    int d; // distance
    int p; // parent

    Vertex() {
        v = NIL;
        d = INF;
        p = NIL;
    }

    Vertex(int index, int distance, int parent) {
        v = index;
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
        else cout << p;

        cout << endl;
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
        A = new Vertex[n];
        length = n;
        for (int i = 0; i < n; i++)
            A[i] = data[i];
        buildMinHeap();
    }

    ~MinHeap() {
        delete A;
    }

    // page 157
    void buildMinHeap() {
        // line 1
        heapSize = length;
        for (int i = length / 2; i >= 0; i--)
            minHeapify(i);
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

    int parent(int i) {
        return i / 2;
    }

    int left(int i) {
        return 2 * i;
    }

    int right(int i) {
        return 2 * i + 1;
    }

    bool isEmpty() {
        if (heapSize == 0)
            return true;
        else return false;

        //return heapSize == 0;
    }

    void minHeapify(int i) {
        int l = left(i);
        int r = right(i);

        int smallest;

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

    void print() {
        cout << "Heap contents:" << endl;
        for (int i = 0; i < heapSize; i++) {
            cout << i + 1 << ": ";
            A[i].print();
        }
    }
};

class Graph {
private:
    int counter;
public:
    int V; // number of vertices
    int E; // number of edges
    Edge *edges;
    Vertex *vertices;

    Graph(int V, int E) {
        this->V = V;
        this->E = E;
        edges = new Edge[E];
        vertices = new Vertex[V];
        for (int v = 0; v < V; v++)
            vertices[v].v = v;
        counter = 0;
    }

    ~Graph() {
        delete edges;
        delete vertices;
    }

    void addEdge(int u, int v, int w) {
        Edge edge(u, v, w);
        edges[counter++] = edge;
    }

    void print() {
        cout << "Vertices " << V << endl;

        for (int i = 0; i < V; i++) {
            vertices[i].print();
        }

        cout << "Edges " << E << endl;

        for (int i = 0; i < counter; i++) {
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
        vertices[s].d = 0;
    }

    // page 658
    void dijkstra(int s) {
        // line 1
        initializeSingleSource(s - 1);

        // line 2
        bool *S = new bool[V];
        for (int v = 0; v < V; v++)
            S[v] = false;

        MinHeap Q(vertices, V);

        //Q.print();

        // line 4
        while (!Q.isEmpty()) {
            // line 5
            Vertex u = Q.extractMin();

            // line 6
            S[u.v] = true;

            // highly inefficient
            for (int e = 0; e < E; e++) {
                int adjU = NIL;
                if (edges[e].u == u.v) {
                    adjU = edges[e].v;
                } else if (edges[e].v == u.v) {
                    adjU = edges[e].u;
                }

                if (adjU != NIL) {
                    cout << "Found adjacent!" << endl;
                    vertices[adjU].print();
                    exit(0);
                    // call relax (page 649)
                    // also implement one extra function
                    // heapDecreaseKey (page 164)
                }
            }
        }

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
/*
    int data[] = {5, 2, 1, 6, 34, 7, 2, 6, 19};
    int n = 9;

    MinHeap h(data, n);
    h.print();

    h.buildMinHeap();
    h.print();

    cout << h.extractMin() << endl;
    cout << h.extractMin() << endl;
    cout << h.extractMin() << endl;
    h.print();
*/
    return 0;
}

