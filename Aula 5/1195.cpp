#include <iostream>

using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int val) {
    if (root == nullptr) {
        return new Node(val);
    }
    
    if (val < root->val) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    
    return root;
}

void preOrder(Node* root) {
    if (root == nullptr) return;
    cout << " " << root->val;
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node* root) {
    if (root == nullptr) return;
    inOrder(root->left);
    cout << " " << root->val;
    inOrder(root->right);
}

void postOrder(Node* root) {
    if (root == nullptr) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << " " << root->val;
}

void freeTree(Node* root) {
    if (root == nullptr) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int C;
    if (!(cin >> C)) return 0;

    for (int i = 1; i <= C; ++i) {
        int N;
        cin >> N;

        Node* root = nullptr;

        for (int j = 0; j < N; ++j) {
            int val;
            cin >> val;
            root = insert(root, val);
        }

        cout << "Case " << i << ":\n";
        
        cout << "Pre.:";
        preOrder(root);
        cout << "\n";
        
        cout << "In..:";
        inOrder(root);
        cout << "\n";
        
        cout << "Post:";
        postOrder(root);
        cout << "\n\n";

        freeTree(root);
    }

    return 0;
}