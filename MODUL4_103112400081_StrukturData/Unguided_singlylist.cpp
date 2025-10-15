#include <iostream>
#include "Unguided_singlylist.h"
using namespace std;

void CreateList(List& L) {
    L.First = nullptr;
}

address alokasi(infotype x) {
    address P = new ElmList;
    if (P != nullptr) {
        P->info = x;
        P->next = nullptr;
    }
    return P;
}

void dealokasi(address& P) {
    delete P;
    P = nullptr;
}

void printInfo(List L) {
    address P = L.First;
    if (P == nullptr) {
        std::cout << "List kosong\n";
        return;
    }
    std::cout << "Isi List: ";
    while (P != nullptr) {
        std::cout << P->info << " ";
        P = P->next;
    }
    std::cout << std::endl;
}

void insertFirst(List& L, address P) {
    P->next = L.First;
    L.First = P;
}