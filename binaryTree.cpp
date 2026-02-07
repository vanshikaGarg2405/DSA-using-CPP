#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node* left;
    struct node* right;
};

node* createNode(int val) {
    struct node* temp;
    temp = new node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
node* buildTree(vector<string>& arr) {
    if(arr.empty() || arr[0] == "N") return NULL;
    node* root = createNode(stoi(arr[0]));
    queue<node*> q;
    q.push(root);
    int i = 1;
    while(!q.empty() && i < arr.size()) {
        node* curr = q.front();
        q.pop();
        //Left Child
        if(i < arr.size() && arr[i] != "N") {
            curr->left = createNode(stoi(arr[i]));
            q.push(curr->left);
        }
        i++;
        if(i < arr.size() && arr[i] != "N") {
            curr->right = createNode(stoi(arr[i]));
            q.push(curr->right);  
        } 
        i++;
    }
    return root;
}

void preOrder(struct node* root) {
    if(root == NULL) return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

int main() {
    string st;
    getline(cin, st);
    stringstream ss(st);
    vector<string> arr;
    string val;
    while(ss >> val) arr.push_back(val);
    struct node* root = buildTree(arr);
    preOrder(root);
    return 0;
}