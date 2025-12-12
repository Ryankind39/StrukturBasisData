#include <iostream>
using namespace std;

const int MAX = 5;

struct Queue {
    int info[MAX];
    int head;
    int tail;
};

void createQueue1(Queue &Q) {
    Q.head = 0;
    Q.tail = -1;
}

bool isEmptyQueue1(Queue Q) {
    return Q.tail < Q.head;
}

bool isFullQueue1(Queue Q) {
    return Q.tail == MAX - 1;
}

void enqueue1(Queue &Q, int x) {
    if (isFullQueue1(Q)) {
        cout << "Queue penuh!" << endl;
        return;
    }
    Q.tail++;
    Q.info[Q.tail] = x;
}

int dequeue1(Queue &Q) {
    if (isEmptyQueue1(Q)) {
        cout << "Queue kosong!" << endl;
        return -1;
    }
    int x = Q.info[Q.head];
    Q.head++;
    return x;
}

void printInfo1(Queue Q) {
    cout << "H=" << Q.head << " T=" << Q.tail << " | ";
    if (isEmptyQueue1(Q)) {
        cout << "Queue kosong." << endl;
        return;
    }
    for (int i = Q.head; i <= Q.tail; i++) {
        cout << Q.info[i] << " ";
    }
    cout << endl;
}

void createQueue2(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue2(Queue Q) {
    return Q.head == -1;
}

bool isFullQueue2(Queue Q) {
    return Q.tail == MAX - 1;
}

void enqueue2(Queue &Q, int x) {
    if (isFullQueue2(Q)) {
        cout << "Queue penuh!" << endl;
        return;
    }
    if (isEmptyQueue2(Q)) {
        Q.head = 0;
        Q.tail = 0;
    } else {
        Q.tail++;
    }
    Q.info[Q.tail] = x;
}

int dequeue2(Queue &Q) {
    if (isEmptyQueue2(Q)) {
        cout << "Queue kosong!" << endl;
        return -1;
    }
    int x = Q.info[Q.head];

    for (int i = Q.head; i < Q.tail; i++) {
        Q.info[i] = Q.info[i + 1];
    }
    Q.tail--;

    if (Q.tail < 0) {
        Q.head = -1;
        Q.tail = -1;
    }

    return x;
}

void printInfo2(Queue Q) {
    cout << "H=" << Q.head << " T=" << Q.tail << " | ";
    if (isEmptyQueue2(Q)) {
        cout << "Queue kosong." << endl;
        return;
    }
    for (int i = Q.head; i <= Q.tail; i++) {
        cout << Q.info[i] << " ";
    }
    cout << endl;
}

void createQueue3(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue3(Queue Q) {
    return Q.head == -1;
}

bool isFullQueue3(Queue Q) {
    return (Q.tail + 1) % MAX == Q.head;
}

void enqueue3(Queue &Q, int x) {
    if (isFullQueue3(Q)) {
        cout << "Queue penuh!" << endl;
        return;
    }

    if (isEmptyQueue3(Q)) {
        Q.head = 0;
        Q.tail = 0;
    } else {
        Q.tail = (Q.tail + 1) % MAX;
    }

    Q.info[Q.tail] = x;
}

int dequeue3(Queue &Q) {
    if (isEmptyQueue3(Q)) {
        cout << "Queue kosong!" << endl;
        return -1;
    }

    int x = Q.info[Q.head];
    
    if (Q.head == Q.tail) {
        Q.head = -1;
        Q.tail = -1;
    } else {
        Q.head = (Q.head + 1) % MAX;
    }

    return x;
}

void printInfo3(Queue Q) {
    cout << "H=" << Q.head << " T=" << Q.tail << " | ";

    if (isEmptyQueue3(Q)) {
        cout << "Queue kosong." << endl;
        return;
    }

    int i = Q.head;
    while (true) {
        cout << Q.info[i] << " ";
        if (i == Q.tail) break;
        i = (i + 1) % MAX;
    }
    cout << endl;
}

int main() {

    cout << "\n===== QUEUE ALTERNATIF 1 (HEAD DIAM, TAIL BERGERAK) =====" << endl;
    Queue Q1;
    createQueue1(Q1);

    printInfo1(Q1);
    enqueue1(Q1, 5); printInfo1(Q1);
    enqueue1(Q1, 2); printInfo1(Q1);
    enqueue1(Q1, 7); printInfo1(Q1);
    dequeue1(Q1);    printInfo1(Q1);
    enqueue1(Q1, 4); printInfo1(Q1);
    dequeue1(Q1);    printInfo1(Q1);
    dequeue1(Q1);    printInfo1(Q1);


    cout << "\n===== QUEUE ALTERNATIF 2 (HEAD & TAIL BERGERAK / SHIFTING) =====" << endl;
    Queue Q2;
    createQueue2(Q2);

    enqueue2(Q2, 5); printInfo2(Q2);
    enqueue2(Q2, 2); printInfo2(Q2);
    enqueue2(Q2, 7); printInfo2(Q2);
    dequeue2(Q2);    printInfo2(Q2);
    enqueue2(Q2, 4); printInfo2(Q2);
    dequeue2(Q2);    printInfo2(Q2);
    dequeue2(Q2);    printInfo2(Q2);


    cout << "\n===== QUEUE ALTERNATIF 3 (CIRCULAR QUEUE) =====" << endl;
    Queue Q3;
    createQueue3(Q3);

    enqueue3(Q3, 5); printInfo3(Q3);
    enqueue3(Q3, 2); printInfo3(Q3);
    enqueue3(Q3, 7); printInfo3(Q3);
    dequeue3(Q3);    printInfo3(Q3);
    enqueue3(Q3, 4); printInfo3(Q3);
    dequeue3(Q3);    printInfo3(Q3);
    dequeue3(Q3);    printInfo3(Q3);

    return 0;
}
