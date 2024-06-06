#include <iostream>
using namespace std;

// Definisi struktur pohon
struct Node {
    char data;
    Node* left;
    Node* right;
};

// Fungsi untuk membuat simpul baru
Node* createNode(char data) {
    Node* newNode_RatihAmbara_2311110037 = new Node;
    newNode_RatihAmbara_2311110037->data = data;
    newNode_RatihAmbara_2311110037->left = nullptr;
    newNode_RatihAmbara_2311110037->right = nullptr;
    return newNode_RatihAmbara_2311110037;
}

// Fungsi untuk menambah simpul ke pohon
Node* insertNode(Node* root, char data) {
    if (root == nullptr) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }
    return root;
}

// Tampilan pre-order
void preOrder(Node* root) {
    if (root != nullptr) {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Tampilan in-order
void inOrder(Node* root) {
    if (root != nullptr) {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

// Tampilan post-order
void postOrder(Node* root) {
    if (root != nullptr) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}

int main() {
    Node* root = nullptr;
    char data;
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Tambah simpul\n";
        cout << "2. Pre-order traversal\n";
        cout << "3. In-order traversal\n";
        cout << "4. Post-order traversal\n";
        cout << "0. Keluar\n";
        cout << "Pilihan Anda: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Masukkan data: ";
                cin >> data;
                root = insertNode(root, data);
                break;
            case 2:
                cout << "Pre-order traversal: ";
                preOrder(root);
                cout << endl;
                break;
            case 3:
                cout << "In-order traversal: ";
                inOrder(root);
                cout << endl;
                break;
            case 4:
                cout << "Post-order traversal: ";
                postOrder(root);
                cout << endl;
                break;
            case 0:
                cout << "Terima kasih!\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (choice != 0);

    return 0;
}
