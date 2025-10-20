#include <iostream>
#include <string>

using namespace std;

// Struktur untuk menyimpan data pembeli
struct Pembeli {
    string nama;
    string pesanan;
};

// Struktur untuk Node dalam linked list
struct Node {
    Pembeli data;
    Node* next;
};

class AntrianLinkedList {
private:
    Node* head;

public:
    AntrianLinkedList() {
        head = nullptr;
    }

    // Menambah antrian
    void tambah_antrian(string nama, string pesanan) {
        Pembeli pembeli;
        pembeli.nama = nama;
        pembeli.pesanan = pesanan;

        Node* node_baru = new Node;
        node_baru->data = pembeli;
        node_baru->next = nullptr;

        if (head == nullptr) {
            head = node_baru;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = node_baru;
        }

        cout << "Antrian untuk " << nama << " dengan pesanan " << pesanan << " telah ditambahkan." << endl;
    }

    // Melayani antrian (hapus dari depan)
    void layani_antrian() {
        if (head == nullptr) {
            cout << "Antrian kosong." << endl;
            return;
        }

        Pembeli pembeli_dilayani = head->data;
        Node* temp = head;
        head = head->next;
        delete temp;

        cout << "Melayani antrian: " << pembeli_dilayani.nama << " dengan pesanan " << pembeli_dilayani.pesanan << endl;
    }

    // Menampilkan antrian
    void tampilkan_antrian() {
        if (head == nullptr) {
            cout << "Antrian kosong." << endl;
            return;
        }

        cout << "Antrian:" << endl;
        Node* current = head;
        while (current != nullptr) {
            cout << "Nama: " << current->data.nama << ", Pesanan: " << current->data.pesanan << endl;
            current = current->next;
        }
    }

    // Mencari nama pembeli
    void cari_pembeli(string nama_cari) {
        if (head == nullptr) {
            cout << "Antrian kosong." << endl;
            return;
        }

        Node* current = head;
        bool ditemukan = false;

        while (current != nullptr) {
            if (current->data.nama == nama_cari) {
                cout << "Pembeli ditemukan:" << endl;
                cout << "Nama: " << current->data.nama << ", Pesanan: " << current->data.pesanan << endl;
                ditemukan = true;
                break;
            }
            current = current->next;
        }

        if (!ditemukan) {
            cout << "Pembeli dengan nama " << nama_cari << " tidak ditemukan dalam antrian." << endl;
        }
    }
};

int main() {
    AntrianLinkedList antrian;
    int pilihan;
    string nama, pesanan, nama_cari;

    while (true) {
        cout << "\nMenu:" << endl;
        cout << "1. Tambah Antrian" << endl;
        cout << "2. Layani Antrian" << endl;
        cout << "3. Tampilkan Antrian" << endl;
        cout << "4. Cari Pembeli" << endl;
        cout << "5. Keluar" << endl;

        cout << "Masukkan pilihan Anda: ";
        cin >> pilihan;
        cin.ignore(); // Membersihkan newline dari buffer

        switch (pilihan) {
            case 1: {
                cout << "Masukkan nama pembeli: ";
                getline(cin, nama);
                cout << "Masukkan pesanan pembeli: ";
                getline(cin, pesanan);
                antrian.tambah_antrian(nama, pesanan);
                break;
            }
            case 2:
                antrian.layani_antrian();
                break;
            case 3:
                antrian.tampilkan_antrian();
                break;
            case 4:
                cout << "Masukkan nama pembeli yang ingin dicari: ";
                getline(cin, nama_cari);
                antrian.cari_pembeli(nama_cari);
                break;
            case 5:
                cout << "Terima kasih!" << endl;
                return 0;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    }

    return 0;
}