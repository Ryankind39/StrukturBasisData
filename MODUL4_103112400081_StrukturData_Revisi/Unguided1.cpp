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
};

int main() {
    AntrianLinkedList antrian;
    int pilihan;
    string nama, pesanan;

    while (true) {
        cout << "\nMenu:" << endl;
        cout << "1. Tambah Antrian" << endl;
        cout << "2. Layani Antrian" << endl;
        cout << "3. Tampilkan Antrian" << endl;
        cout << "4. Keluar" << endl;

        cout << "Masukkan pilihan Anda: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan nama pembeli: ";
                cin >> nama;
                cout << "Masukkan pesanan pembeli: ";
                cin >> pesanan;
                antrian.tambah_antrian(nama, pesanan);
                break;
            case 2:
                antrian.layani_antrian();
                break;
            case 3:
                antrian.tampilkan_antrian();
                break;
            case 4:
                cout << "Terima kasih!" << endl;
                return 0;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    }

    return 0;
}