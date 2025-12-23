#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *kiri, *kanan;
};

Node *buatNode(int nilai)
{
    Node *baru = new Node;
    baru->data = nilai;
    baru->kiri = baru->kanan = NULL;
    return baru;
}

// 1. INSERT (menyisipkan data)
Node *insert(Node *root, int nilai) {
    if (root == NULL) {
        return buatNode(nilai);
    }

    if (nilai < root->data) {
        root->kiri = insert(root->kiri, nilai);
    } else {
        root->kanan = insert(root->kanan, nilai);
    }

    return root;
};

Node *search(Node *root, int nilai) {
    if (root == NULL || root-> data == nilai) {
        return root;
    }

    if (nilai < root->data) {
        return search(root->kiri, nilai);
    }

    return search(root->kanan, nilai);
}

// Helper: Cari nilai terkecil (untuk proses hapus)
Node *nilaiTerkecil(Node *node) {
    Node *current = node;
    while (current && current->kiri != NULL) {
        current = current->kiri;
    }
    return current;
}

// 3. DELETE (menghapus data - diperlukan untuk update)
Node *hapus(Node *root, int nilai) {
    if (root == NULL) {
        return root;
    }

    if (nilai < root->data) {
        root->kiri = hapus(root->kiri, nilai);
    } else if (nilai > root->data) {
        root->kanan = hapus(root->kanan, nilai);
    } else {
        // Jika data ketemu
        if (root->kiri == NULL) {
            Node *temp = root->kanan;
            delete root;
            return temp;
        }
        else if (root->kanan == NULL) {
            Node *temp = root->kiri;
            delete root;
            return temp;
        }
        // Jika punya 2 child: ambil terkecil dari kanan
        Node*temp = nilaiTerkecil(root->kanan);
        root->data = temp->data;
        root->kanan = hapus(root->kanan, temp->data);
    }
    return root;
}

// 4. UPDATE (ubah data)
Node *update(Node *root, int lama, int baru) {
    if (search(root, lama) != NULL) {
        root = hapus(root, lama);
        root = insert(root, baru);
        cout << "Data " << lama << " diupdate menjadi " << baru << endl;
    } else {
        cout << "Data " << lama << " tidak ditemukan!" << endl;
    }
    return root;
}

// 5. TRAVERSAL (menampilkan data)
void preOrder(Node *root) {
    // Akar -> kiri -> kanan
    if (root != NULL) {
        cout << root->data << " ";
        preOrder(root->kiri);
        preOrder(root->kanan);
    }
}

void inOrder(Node *root) {
    // kiri -> akar -> kanan
    if (root != NULL) {
        inOrder(root->kiri);
        cout << root->data << " ";
        inOrder(root->kanan);
    }
}

void postOrder(Node *root) {
    // kiri -> kanan -> akar
    if (root != NULL) {
        postOrder(root->kiri);
        postOrder(root->kanan);
        cout << root->data << " ";
    }
}

int main() {
    Node *root = NULL;

    cout << "=== 1. INSERT DATA ===" << endl;
    root = insert(root, 10);
    insert(root, 5);
    insert(root, 20);
    insert(root, 3);
    insert(root, 7);
    insert(root, 15);
    insert(root, 25);
    cout << "Data berhasil dimasukkan.\n" << endl;
    
    cout << "=== 2. TAMPILKAN TREE (TRAVERSAL) ===" << endl;
    cout << "PreOrder   : ";
    preOrder(root);
    cout << endl;
    cout << "InOrder    : ";
    inOrder(root);
    cout << endl;
    cout << "PostOrder  : ";
    postOrder(root);
    cout << endl << endl;

    cout << "=== 3. TEST SEARCH ===" << endl;
    int cari1 = 7, cari2 = 30;
    cout << "Cari " << cari1 << ": " << (search(root, cari1) ? "Ketemu" : "Tidak ada") << endl;
    cout << "Cari " << cari2 << ": " << (search(root, cari2) ? "Ketemu" : "Tidak ada") << endl;
    cout << endl;

    cout << "=== 4. TEST UPDATE ===" << endl;
    // mengubah angka 5 menjadi 8
    root = update(root, 5, 8);
    cout << "Hasil InOrder setelah update: ";
    cout << endl;
    cout << endl;
    
    cout << "PreOrder   : ";
    preOrder(root);
    cout << endl;
    cout << "InOrder    : ";
    inOrder(root);
    cout << endl;
    cout << "PostOrder  : ";
    postOrder(root);
    cout << endl << endl;

    cout << "=== 5. TEST DELETE ===" << endl;
    // menghapus angka 20 (Node yang punya child)
    cout << "Menghapus angka 20..." << endl;
    root = hapus(root, 20);
    
    cout << "PreOrder   : ";
    preOrder(root);
    cout << endl;
    cout << "InOrder    : ";
    inOrder(root);
    cout << endl;
    cout << "PostOrder  : ";
    postOrder(root);
    cout << endl << endl;
    
    return 0;
}