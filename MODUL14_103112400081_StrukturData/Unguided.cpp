#include <iostream>
using namespace std;

typedef char charInfo;

struct Vertex;
struct Edge;

typedef Vertex* ptrVertex;
typedef Edge* ptrEdge;

struct Edge {
    ptrVertex destVertex;
    ptrEdge nextEdge;
};

struct Vertex {
    charInfo id;
    int status;
    ptrEdge firstIncidentEdge;
    ptrVertex nextVertex;
};

struct Graph {
    ptrVertex firstVertex;
};

struct NodeQ {
    ptrVertex val;
    NodeQ* next;
};

struct QueueList {
    NodeQ* head;
    NodeQ* tail;
};

void createQ(QueueList &Q) {
    Q.head = NULL;
    Q.tail = NULL;
}

bool emptyQ(QueueList Q) {
    return (Q.head == NULL);
}

void enq(QueueList &Q, ptrVertex v) {
    NodeQ* baru = new NodeQ;
    baru->val = v;
    baru->next = NULL;

    if (emptyQ(Q)) {
        Q.head = baru;
        Q.tail = baru;
    } else {
        Q.tail->next = baru;
        Q.tail = baru;
    }
}

ptrVertex deq(QueueList &Q) {
    if (emptyQ(Q)) return NULL;

    NodeQ* del = Q.head;
    ptrVertex out = del->val;

    Q.head = Q.head->next;
    if (Q.head == NULL) Q.tail = NULL;

    delete del;
    return out;
}

void initGraph(Graph &G) {
    G.firstVertex = NULL;
}

ptrVertex alokasiVertex(charInfo data) {
    ptrVertex V = new Vertex;
    V->id = data;
    V->status = 0;
    V->firstIncidentEdge = NULL;
    V->nextVertex = NULL;
    return V;
}

ptrEdge alokasiEdge(ptrVertex tujuan) {
    ptrEdge E = new Edge;
    E->destVertex = tujuan;
    E->nextEdge = NULL;
    return E;
}

void addVertex(Graph &G, charInfo data) {
    ptrVertex V = alokasiVertex(data);

    if (G.firstVertex == NULL) {
        G.firstVertex = V;
    } else {
        ptrVertex P = G.firstVertex;
        while (P->nextVertex != NULL) {
            P = P->nextVertex;
        }
        P->nextVertex = V;
    }
}

ptrVertex searchVertex(Graph G, charInfo data) {
    ptrVertex P = G.firstVertex;
    while (P != NULL) {
        if (P->id == data) return P;
        P = P->nextVertex;
    }
    return NULL;
}

void addEdge(ptrVertex v1, ptrVertex v2) {
    if (v1 == NULL || v2 == NULL) return;

    ptrEdge e1 = alokasiEdge(v2);
    e1->nextEdge = v1->firstIncidentEdge;
    v1->firstIncidentEdge = e1;

    ptrEdge e2 = alokasiEdge(v1);
    e2->nextEdge = v2->firstIncidentEdge;
    v2->firstIncidentEdge = e2;
}

void showGraphData(Graph G) {
    ptrVertex v = G.firstVertex;
    while (v != NULL) {
        cout << "[" << v->id << "] terhubung ke -> ";

        ptrEdge e = v->firstIncidentEdge;
        if (e == NULL) cout << "(tidak ada)";

        while (e != NULL) {
            cout << e->destVertex->id << " ";
            e = e->nextEdge;
        }
        cout << endl;
        v = v->nextVertex;
    }
}

void resetStatus(Graph G) {
    ptrVertex p = G.firstVertex;
    while (p != NULL) {
        p->status = 0;
        p = p->nextVertex;
    }
}

void runDFS(ptrVertex V) {
    if (V->status == 1) return;

    V->status = 1;
    cout << V->id << " ";

    ptrEdge e = V->firstIncidentEdge;
    while (e != NULL) {
        if (e->destVertex->status == 0) {
            runDFS(e->destVertex);
        }
        e = e->nextEdge;
    }
}

void executeDFS(Graph G, ptrVertex startV) {
    if (startV == NULL) return;

    resetStatus(G);
    cout << "DFS Traversal: ";
    runDFS(startV);
    cout << endl;
}

void executeBFS(Graph G, ptrVertex startV) {
    if (startV == NULL) return;

    resetStatus(G);
    cout << "BFS Traversal: ";

    QueueList Q;
    createQ(Q);

    startV->status = 1;
    enq(Q, startV);

    while (!emptyQ(Q)) {
        ptrVertex cur = deq(Q);
        cout << cur->id << " ";

        ptrEdge e = cur->firstIncidentEdge;
        while (e != NULL) {
            if (e->destVertex->status == 0) {
                e->destVertex->status = 1;
                enq(Q, e->destVertex);
            }
            e = e->nextEdge;
        }
    }
    cout << endl;
}

int main() {
    Graph G;
    initGraph(G);

    char listV[] = {'A','B','C','D','E','F','G','H'};
    for (int i = 0; i < 8; i++) {
        addVertex(G, listV[i]);
    }

    ptrVertex A = searchVertex(G,'A');
    ptrVertex B = searchVertex(G,'B');
    ptrVertex C = searchVertex(G,'C');
    ptrVertex D = searchVertex(G,'D');
    ptrVertex E = searchVertex(G,'E');
    ptrVertex F = searchVertex(G,'F');
    ptrVertex Gv = searchVertex(G,'G');
    ptrVertex H = searchVertex(G,'H');

    addEdge(A,B); addEdge(A,C);
    addEdge(B,D); addEdge(B,E);
    addEdge(C,F); addEdge(C,Gv);
    addEdge(D,H); addEdge(E,H);
    addEdge(F,H); addEdge(Gv,H);

    cout << "=== STRUKTUR GRAPH ===" << endl;
    showGraphData(G);
    cout << endl;

    executeDFS(G, A);
    executeBFS(G, A);

    return 0;
}
