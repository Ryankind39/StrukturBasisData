#include <iostream>
using namespace std;

const int MAX = 20;

struct Stack {
    int info[MAX];
    int top;
};

void createStack(Stack &S) {
    S.top = -1;
}

bool isEmpty(Stack S) {
    return S.top == -1;
}

bool isFull(Stack S) {
    return S.top == MAX - 1;
}

void push(Stack &S, int x) {
    if (isFull(S)) {
        cout << "Stack penuh, tidak bisa push!" << endl;
        return;
    }
    S.top++;
    S.info[S.top] = x;
}

int pop(Stack &S) {
    if (isEmpty(S)) {
        cout << "Stack kosong, tidak bisa pop!" << endl;
        return -1;
    }
    int x = S.info[S.top];
    S.top--;
    return x;
}

void printInfo(Stack S) {
    if (isEmpty(S)) {
        cout << "Stack kosong." << endl;
        return;
    }
    cout << "TOP -> ";
    for (int i = S.top; i >= 0; i--) {
        cout << S.info[i] << " ";
    }
    cout << endl;
}

void balikStack(Stack &S) {
    Stack temp;
    createStack(temp);

    while (!isEmpty(S)) {
        push(temp, pop(S));
    }

    S = temp;
}

void pushAscending(Stack &S, int x) {
    if (isFull(S)) {
        cout << "Stack penuh!" << endl;
        return;
    }

    Stack temp;
    createStack(temp);

    while (!isEmpty(S) && S.info[S.top] < x) {
        push(temp, pop(S));
    }

    push(S, x);

    while (!isEmpty(temp)) {
        push(S, pop(temp));
    }
}

void getInputStream(Stack &S) {
    cout << "Masukkan karakter (ENTER untuk selesai): ";

    createStack(S);
    char c;

    cin.ignore();

    while (true) {
        c = cin.get();
        if (c == '\n') break;
        push(S, c);
    }
}

int main() {
    cout << "Hello world!" << endl;

    Stack S;

    createStack(S);
    push(S, 3);
    push(S, 4);
    push(S, 8);
    pop(S);
    push(S, 2);
    push(S, 3);
    pop(S);
    push(S, 9);

    printInfo(S);

    cout << "balik stack:" << endl;
    balikStack(S);
    printInfo(S);


    cout << "\n=== PUSH ASCENDING ===" << endl;
    createStack(S);

    pushAscending(S, 3);
    pushAscending(S, 4);
    pushAscending(S, 8);
    pushAscending(S, 2);
    pushAscending(S, 3);
    pushAscending(S, 9);

    printInfo(S);

    cout << "balik stack:" << endl;
    balikStack(S);
    printInfo(S);

    cout << "\n=== GET INPUT STREAM ===" << endl;
    createStack(S);
    getInputStream(S);

    printInfo(S);

    cout << "balik stack:" << endl;
    balikStack(S);
    printInfo(S);

    return 0;
}
