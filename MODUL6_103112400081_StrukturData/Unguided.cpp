#include <iostream>
#include <string>
using namespace std;

struct Kendaraan {
    string nomorPolisi;
    string warna;
    int tahun;
};

typedef Kendaraan InfoKendaraan;

struct Node {
    InfoKendaraan data;
    Node* next;
    Node* prev;
};

typedef Node* Address;

struct List {
    Address first;
    Address last;
};

void buatListKosong(List &daftarKendaraan);
Address buatNodeBaru(InfoKendaraan kendaraanBaru);
void hapusNode(Address node);
void tambahKendaraanDiAkhir(List &daftarKendaraan, Address nodeBaru);
void tampilkanKendaraan(const List &daftarKendaraan);
Address cariKendaraan(const List &daftarKendaraan, const string &nomorPolisi);
void hapusKendaraanPertama(List &daftarKendaraan, Address &node);
void hapusKendaraanTerakhir(List &daftarKendaraan, Address &node);
void hapusKendaraanSetelah(Address sebelum, Address &node);
bool cekDuplikat(const List &daftarKendaraan, const string &nomorPolisi);

void buatListKosong(List &daftarKendaraan) {
    daftarKendaraan.first = nullptr;
    daftarKendaraan.last = nullptr;
}

Address buatNodeBaru(InfoKendaraan kendaraanBaru) {
    Address node = new Node;
    node->data = kendaraanBaru;
    node->next = nullptr;
    node->prev = nullptr;
    return node;
}

void hapusNode(Address node) {
    if (node != nullptr) {
        delete node;
    }
}

void tambahKendaraanDiAkhir(List &daftarKendaraan, Address nodeBaru) {
    if (daftarKendaraan.first == nullptr) {
        daftarKendaraan.first = nodeBaru;
        daftarKendaraan.last = nodeBaru;
    } else {
        daftarKendaraan.last->next = nodeBaru;
        nodeBaru->prev = daftarKendaraan.last;
        daftarKendaraan.last = nodeBaru;
    }
}

void tampilkanKendaraan(const List &daftarKendaraan) {
    Address node = daftarKendaraan.first;
    if (node == nullptr) {
        cout << "\nDATA LIST KOSONG\n";
        return;
    }
    cout << "\nDATA LIST\n";
    while (node != nullptr) {
        cout << "Nomor Polisi : " << node->data.nomorPolisi << endl;
        cout << "Warna        : " << node->data.warna << endl;
        cout << "Tahun        : " << node->data.tahun << endl << endl;
        node = node->next;
    }
}

Address cariKendaraan(const List &daftarKendaraan, const string &nomorPolisi) {
    Address node = daftarKendaraan.first;
    while (node != nullptr) {
        if (node->data.nomorPolisi == nomorPolisi) {
            return node;
        }
        node = node->next;
    }
    return nullptr;
}

void hapusKendaraanPertama(List &daftarKendaraan, Address &node) {
    node = nullptr;
    if (daftarKendaraan.first == nullptr) return;

    node = daftarKendaraan.first;
    if (daftarKendaraan.first == daftarKendaraan.last) {
        daftarKendaraan.first = nullptr;
        daftarKendaraan.last = nullptr;
    } else {
        daftarKendaraan.first = daftarKendaraan.first->next;
        daftarKendaraan.first->prev = nullptr;
    }
    node->next = nullptr;
    node->prev = nullptr;
}

void hapusKendaraanTerakhir(List &daftarKendaraan, Address &node) {
    node = nullptr;
    if (daftarKendaraan.last == nullptr) return;

    node = daftarKendaraan.last;
    if (daftarKendaraan.first == daftarKendaraan.last) {
        daftarKendaraan.first = nullptr;
        daftarKendaraan.last = nullptr;
    } else {
        daftarKendaraan.last = daftarKendaraan.last->prev;
        daftarKendaraan.last->next = nullptr;
    }
    node->next = nullptr;
    node->prev = nullptr;
}

void hapusKendaraanSetelah(Address sebelum, Address &node) {
    node = nullptr;
    if (sebelum == nullptr) return;
    if (sebelum->next == nullptr) return;

    node = sebelum->next;
    Address setelah = node->next;
    sebelum->next = setelah;
    if (setelah != nullptr) {
        setelah->prev = sebelum;
    }
    node->next = nullptr;
    node->prev = nullptr;
}

bool cekDuplikat(const List &daftarKendaraan, const string &nomorPolisi) {
    Address node = daftarKendaraan.first;
    while (node != nullptr) {
        if (node->data.nomorPolisi == nomorPolisi) {
            return true;
        }
        node = node->next;
    }
    return false;
}

int main() {
    List daftarKendaraan;
    buatListKosong(daftarKendaraan);

    int jumlah;
    cout << "Masukkan jumlah data kendaraan: ";
    if (!(cin >> jumlah) || jumlah < 0) {
        cout << "Input jumlah tidak valid.\n";
        return 0;
    }
    cout << endl;

    for (int i = 0; i < jumlah; i++) {
        InfoKendaraan kendaraanBaru;

        cout << "Masukkan nomor polisi: ";
        cin >> kendaraanBaru.nomorPolisi;

        if (cekDuplikat(daftarKendaraan, kendaraanBaru.nomorPolisi)) {
            cout << "Nomor polisi sudah terdaftar\n\n";
            i--;
            continue;
        }

        cout << "Masukkan warna kendaraan: ";
        cin >> kendaraanBaru.warna;
        cout << "Masukkan tahun kendaraan: ";
        cin >> kendaraanBaru.tahun;
        cout << endl;

        Address nodeBaru = buatNodeBaru(kendaraanBaru);
        tambahKendaraanDiAkhir(daftarKendaraan, nodeBaru);
    }

    tampilkanKendaraan(daftarKendaraan);

    string nomorDicari;
    cout << "Masukkan Nomor Polisi yang dicari : ";
    cin >> nomorDicari;

    Address ditemukan = cariKendaraan(daftarKendaraan, nomorDicari);
    if (ditemukan != nullptr) {
        cout << "\nNomor Polisi : " << ditemukan->data.nomorPolisi << endl;
        cout << "Warna        : " << ditemukan->data.warna << endl;
        cout << "Tahun        : " << ditemukan->data.tahun << endl;
    } else {
        cout << "Data tidak ditemukan.\n";
    }

    string nomorDihapus;
    cout << "\nMasukkan Nomor Polisi yang akan dihapus : ";
    cin >> nomorDihapus;

    Address nodeDihapus = cariKendaraan(daftarKendaraan, nomorDihapus);
    if (nodeDihapus != nullptr) {
        if (nodeDihapus == daftarKendaraan.first) {
            hapusKendaraanPertama(daftarKendaraan, nodeDihapus);
        } else if (nodeDihapus == daftarKendaraan.last) {
            hapusKendaraanTerakhir(daftarKendaraan, nodeDihapus);
        } else {
            Address prevNode = nodeDihapus->prev;
            hapusKendaraanSetelah(prevNode, nodeDihapus);
        }
        hapusNode(nodeDihapus);
        cout << "Data dengan nomor polisi " << nomorDihapus << " berhasil dihapus.\n";
    } else {
        cout << "Data tidak ditemukan.\n";
    }

    tampilkanKendaraan(daftarKendaraan);
    Address cur = daftarKendaraan.first;
    while (cur != nullptr) {
        Address next = cur->next;
        hapusNode(cur);
        cur = next;
    }
    daftarKendaraan.first = daftarKendaraan.last = nullptr;

    return 0;
}
