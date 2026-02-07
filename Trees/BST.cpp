#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node * left, *right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
Node* insertNode(Node *node, int val) {
    if(!node) return new Node(val);
    if(val < node->data) node->left = insertNode(node->left, val);
    else if(val > node->data) node->right = insertNode(node->right, val);
    else return node;
    return node;
}
Node* findMin(Node *node) {
    while(node && node->left) node = node->left;
    return node;
}
Node* deleteNode(Node *node, int val) {
    if(!node) return NULL;
    if(val < node->data) node->left = deleteNode(node->left, val);
    else if(val > node->data) node->right = deleteNode(node->right, val);
    else {
        if(!node->left) {
            Node* temp = node->right;
            delete node;
            return temp;
        }
        if(!node->right) {
            Node* temp = node->left;
            delete node;
            return temp;
        }
        Node* temp = findMin(node->right);
        node->data = temp->data;
        node->right = deleteNode(node->right, temp->data);
    }
    return node;
}
bool searchNode(Node *node, int val) {
    if(!node) return false;
    if(node->data == val) return true;
    if(val < node->data) return searchNode(node->left, val);
    else return searchNode(node->right, val);
}
void inorder(Node *node, vector<int> &res) {
    if(!node) return;
    inorder(node->left, res);
    res.push_back(node->data);
    inorder(node->right, res);
}
void preorder(Node *node, vector<int> &res) {
    if(!node) return;
    res.push_back(node->data);
    preorder(node->left, res);
    preorder(node->right, res);
}
void postorder(Node * node, vector<int> &res) {
    if(!node) return;
    postorder(node->left, res);
    postorder(node->right, res);
    res.push_back(node->data);
}
int main() {
    int n, op;
    if(!(cin >> n)) return 0;
    vector<string> outputs;
    Node *root = NULL;
    while(n--) {
        cin >> op;
        if(op == 1) {
            int val;
            cin >> val;
            root = insertNode(root, val);
        }
        else if (op == 2) {
            int val;
            cin >> val;
            root = deleteNode(root, val);
        }
        else if (op == 3) {
            int val;
            cin >> val;
            if(searchNode(root, val)) outputs.push_back("found");
            else outputs.push_back("not found");
        }
        else if(op == 4) {
            vector<int> res;
            inorder(root, res);
            if(res.empty()) outputs.push_back("Empty");
            else {
                stringstream ss;
                for(int i = 0; i < res.size(); i++) {
                    ss << res[i];
                    if(i != res.size() - 1) ss << " ";
                }
                outputs.push_back(ss.str());
            }
        }
        else if(op == 5) {
            vector<int> res;
            preorder(root, res);
            if(res.empty()) outputs.push_back("Empty");
            else {
                stringstream ss;
                for(int i = 0; i < res.size(); i++) {
                    ss << res[i];
                    if(i != res.size() - 1) ss << " ";
                }
                outputs.push_back(ss.str());
            }
        }
        else if(op == 6) {
            vector<int> res;
            postorder(root, res);
            if(res.empty()) outputs.push_back("Empty");
            else {
                stringstream ss;
                for(int i = 0; i < res.size(); i++) {
                    ss << res[i];
                    if(i != res.size() - 1) ss << " ";
                }
                outputs.push_back(ss.str());
            }
        }
    }
    for(const string &s : outputs) cout << s << endl;
    return 0;
}