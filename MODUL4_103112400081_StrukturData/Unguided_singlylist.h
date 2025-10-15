#ifndef SINGLYLIST_H
#define SINGLYLIST_H

#include <iostream>

typedef int infotype;

struct ElmList;

typedef ElmList* address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address First;
};

void CreateList(List& L);

address alokasi(infotype x);

void dealokasi(address& P);

void printInfo(List L);

void insertFirst(List& L, address P);

#endif