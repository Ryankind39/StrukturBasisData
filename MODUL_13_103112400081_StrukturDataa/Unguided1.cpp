#include <iostream>
using namespace std;

typedef int infotipeinduk;
typedef int infotipeanak;

struct elemen_list_anak;
struct elemen_list_induk;

typedef elemen_list_induk* address_induk;
typedef elemen_list_anak*  address_anak;

struct listanak {
    address_anak first;
    address_anak last;
};

struct elemen_list_anak {
    infotipeanak info;
    address_anak next;
    address_anak prev;
};

struct listinduk {
    address_induk first;
    address_induk last;
};

struct elemen_list_induk {
    infotipeinduk info;
    listanak anak;
    address_induk next;
    address_induk prev;
};

void CreateListInduk(listinduk &L) {
    L.first = NULL;
    L.last = NULL;
}

void CreateListAnak(listanak &L) {
    L.first = NULL;
    L.last = NULL;
}

address_induk alokasiInduk(infotipeinduk X) {
    address_induk P = new elemen_list_induk;
    P->info = X;
    CreateListAnak(P->anak);
    P->next = NULL;
    P->prev = NULL;
    return P;
}

void dealokasiInduk(address_induk P) {
    delete P;
}

address_anak alokasiAnak(infotipeanak X) {
    address_anak P = new elemen_list_anak;
    P->info = X;
    P->next = NULL;
    P->prev = NULL;
    return P;
}

void dealokasiAnak(address_anak P) {
    delete P;
}

address_induk findElmInduk(listinduk L, infotipeinduk X) {
    address_induk P = L.first;
    while (P != NULL) {
        if (P->info == X) return P;
        P = P->next;
    }
    return NULL;
}

address_anak findElmAnak(listanak L, infotipeanak X) {
    address_anak P = L.first;
    while (P != NULL) {
        if (P->info == X) return P;
        P = P->next;
    }
    return NULL;
}

void insertFirstInduk(listinduk &L, address_induk P) {
    if (L.first == NULL) {
        L.first = L.last = P;
    } else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}

void insertLastInduk(listinduk &L, address_induk P) {
    if (L.first == NULL) {
        insertFirstInduk(L, P);
    } else {
        L.last->next = P;
        P->prev = L.last;
        L.last = P;
    }
}

void insertAfterInduk(listinduk &L, address_induk Prec, address_induk P) {
    if (Prec->next == NULL) {
        insertLastInduk(L, P);
    } else {
        P->next = Prec->next;
        Prec->next->prev = P;
        Prec->next = P;
        P->prev = Prec;
    }
}

void insertFirstAnak(listanak &L, address_anak P) {
    if (L.first == NULL) {
        L.first = L.last = P;
    } else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}

void insertLastAnak(listanak &L, address_anak P) {
    if (L.first == NULL) {
        insertFirstAnak(L, P);
    } else {
        L.last->next = P;
        P->prev = L.last;
        L.last = P;
    }
}

void insertAfterAnak(listanak &L, address_anak Prec, address_anak P) {
    if (Prec->next == NULL) {
        insertLastAnak(L, P);
    } else {
        P->next = Prec->next;
        Prec->next->prev = P;
        Prec->next = P;
        P->prev = Prec;
    }
}

void deleteFirstInduk(listinduk &L, address_induk &P) {
    if (L.first == NULL) {
        P = NULL;
    } else if (L.first == L.last) {
        P = L.first;
        L.first = L.last = NULL;
    } else {
        P = L.first;
        L.first = P->next;
        L.first->prev = NULL;
    }
}

void deleteFirstAnak(listanak &L, address_anak &P) {
    if (L.first == NULL) {
        P = NULL;
    } else if (L.first == L.last) {
        P = L.first;
        L.first = L.last = NULL;
    } else {
        P = L.first;
        L.first = P->next;
        L.first->prev = NULL;
    }
}

int nBelas(listinduk L) {
    int count = 0;
    address_induk P = L.first;
    while (P != NULL) {
        count++;
        P = P->next;
    }
    return count;
}

int nBilas(listanak L) {
    int count = 0;
    address_anak P = L.first;
    while (P != NULL) {
        count++;
        P = P->next;
    }
    return count;
}

void printInfoAnak(listanak L) {
    address_anak P = L.first;
    while (P != NULL) {
        cout << P->info << " ";
        P = P->next;
    }
}

void printInfoInduk(listinduk L) {
    address_induk P = L.first;
    while (P != NULL) {
        cout << P->info << " : ";
        printInfoAnak(P->anak);
        cout << endl;
        P = P->next;
    }
}

int main() {
    listinduk LI;
    CreateListInduk(LI);

    insertFirstInduk(LI, alokasiInduk(10));
    insertLastInduk(LI, alokasiInduk(20));
    insertLastInduk(LI, alokasiInduk(30));

    address_induk parent = findElmInduk(LI, 20);
    if (parent != NULL) {
        insertLastAnak(parent->anak, alokasiAnak(101));
        insertLastAnak(parent->anak, alokasiAnak(102));
        insertLastAnak(parent->anak, alokasiAnak(103));
    }

    parent = findElmInduk(LI, 10);
    if (parent != NULL) {
        insertLastAnak(parent->anak, alokasiAnak(999));
    }

    cout << "=== DATA MULTI LINKED LIST ===" << endl;
    printInfoInduk(LI);

    cout << "\nJumlah Induk : " << nBelas(LI) << endl;
    if (findElmInduk(LI, 20) != NULL) {
        cout << "Jumlah Anak Induk 20 : "
             << nBilas(findElmInduk(LI, 20)->anak) << endl;
    }

    return 0;
}
