#include <iostream>
#include <string>
#include <limits>

using namespace std;

struct Buku {
    string ISBN;
    string judul;
    string penulis;
    Buku* next;
};

Buku* head = nullptr;

void tambahBuku(string isbn, string judul, string penulis) {
    Buku* baru = new Buku();
    baru->ISBN = isbn;
    baru->judul = judul;
    baru->penulis = penulis;
    baru->next = nullptr;

    if (head == nullptr) {
        head = baru;
    } else {
        Buku* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = baru;
    }
    cout << "Buku berhasil ditambahkan." << endl;
}

void hapusBuku(string isbn) {
    if (head == nullptr) {
        cout << "Linked list kosong, tidak ada buku yang dihapus." << endl;
        return;
    }

    if (head->ISBN == isbn) {
        Buku* temp = head;
        head = head->next;
        delete temp;
        cout << "Buku dengan ISBN " << isbn << " berhasil dihapus." << endl;
        return;
    }

    Buku* current = head;
    while (current->next != nullptr) {
        if (current->next->ISBN == isbn) {
            Buku* temp = current->next;
            current->next = temp->next;
            delete temp;
            cout << "Buku dengan ISBN " << isbn << " berhasil dihapus." << endl;
            return;
        }
        current = current->next;
    }

    cout << "Buku dengan ISBN " << isbn << " tidak ditemukan." << endl;
}

void perbaruiBuku(string isbn, string newJudul, string newPenulis) {
    Buku* current = head;
    while (current != nullptr) {
        if (current->ISBN == isbn) {
            current->judul = newJudul;
            current->penulis = newPenulis;
            cout << "Buku dengan ISBN " << isbn << " berhasil diperbarui." << endl;
            return;
        }
        current = current->next;
    }

    cout << "Buku dengan ISBN " << isbn << " tidak ditemukan." << endl;
}

void lihatBuku() {
    if (head == nullptr) {
        cout << "Linked list kosong, tidak ada buku." << endl;
        return;
    }

    Buku* current = head;
    cout << "Daftar Buku:" << endl;
    while (current != nullptr) {
        cout << "ISBN: " << current->ISBN << ", Judul: " << current->judul << ", Penulis: " << current->penulis << endl;
        current = current->next;
    }
}

void cariBuku(int pilihan, string searchTerm) {
    if (head == nullptr) {
        cout << "Linked list kosong, tidak ada buku." << endl;
        return;
    }

    Buku* current = head;
    bool ditemukan = false;

    while (current != nullptr) {
        bool cocok = false;
        switch (pilihan) {
            case 1: // Cari berdasarkan Judul
                if (current->judul == searchTerm) cocok = true;
                break;
            case 2: // Cari berdasarkan Penulis
                if (current->penulis == searchTerm) cocok = true;
                break;
            case 3: // Cari berdasarkan ISBN
                if (current->ISBN == searchTerm) cocok = true;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
                return;
        }

        if (cocok) {
            cout << "Buku ditemukan:" << endl;
            cout << "ISBN: " << current->ISBN << ", Judul: " << current->judul << ", Penulis: " << current->penulis << endl;
            ditemukan = true;
        }

        current = current->next;
    }

    if (!ditemukan) {
        cout << "Buku dengan kriteria pencarian tidak ditemukan." << endl;
    }
}

int main() {
    int pilihan;
    string isbn, judul, penulis, searchTerm;

    do {
        cout << "\nMenu:" << endl;
        cout << "1. Tambah Buku" << endl;
        cout << "2. Hapus Buku" << endl;
        cout << "3. Perbarui Buku" << endl;
        cout << "4. Lihat Semua Buku" << endl;
        cout << "5. Cari Buku" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih: ";
        cin >> pilihan;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (pilihan) {
            case 1:
                cout << "Masukkan ISBN: ";
                getline(cin, isbn);
                cout << "Masukkan Judul: ";
                getline(cin, judul);
                cout << "Masukkan Penulis: ";
                getline(cin, penulis);
                tambahBuku(isbn, judul, penulis);
                break;
            case 2:
                cout << "Masukkan ISBN buku yang akan dihapus: ";
                getline(cin, isbn);
                hapusBuku(isbn);
                break;
            case 3:
                cout << "Masukkan ISBN buku yang akan diperbarui: ";
                getline(cin, isbn);
                cout << "Masukkan Judul baru: ";
                getline(cin, judul);
                cout << "Masukkan Penulis baru: ";
                getline(cin, penulis);
                perbaruiBuku(isbn, judul, penulis);
                break;
            case 4:
                lihatBuku();
                break;
            case 5:
                cout << "Cari berdasarkan:" << endl;
                cout << "1. Judul" << endl;
                cout << "2. Penulis" << endl;
                cout << "3. ISBN" << endl;
                cout << "Pilih: ";
                int pilihanCari;
                cin >> pilihanCari;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Masukkan kata kunci pencarian: ";
                getline(cin, searchTerm);
                cariBuku(pilihanCari, searchTerm);
                break;
            case 0:
                cout << "Terima kasih!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
        }
    } while (pilihan != 0);

    return 0;
}