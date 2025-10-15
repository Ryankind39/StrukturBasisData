#include <iostream>
#include "Unguided_singlylist.h"
using namespace std;

int main() {
    List myList;
    CreateList(myList);

    // Membuat elemen-elemen dengan data: 9, 12, 8, 0, 2
    address P1 = alokasi(9);
    address P2 = alokasi(12);
    address P3 = alokasi(8);
    address P4 = alokasi(0);
    address P5 = alokasi(2);

    // Memasukkan elemen-elemen ke dalam list (dari belakang ke depan)
    insertFirst(myList, P5); // 2
    insertFirst(myList, P4); // 0 -> 2
    insertFirst(myList, P3); // 8 -> 0 -> 2
    insertFirst(myList, P2); // 12 -> 8 -> 0 -> 2
    insertFirst(myList, P1); // 9 -> 12 -> 8 -> 0 -> 2

    // Menampilkan isi list
    printInfo(myList);

    return 0;
}