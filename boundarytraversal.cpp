#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node*left;
    Node*right;
    Node(int data){ 
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
}; 
bool isLeaf(Node*root){ 
    return !root->left&&!root->right;
}

void addleft(vector<int>&res,Node*root){ 
    Node*curr=root->left;
    while(curr){ 
        if(!isLeaf(curr)){res.push_back(curr->data);}
        if(curr->left!=NULL){curr=curr->left;}
        else{curr=curr->right;}
    }
}

void addright(vector<int>&res,Node*root){ 
    Node*curr=root->right;
    vector<int>temp;
    while(curr){ 
        if(!isLeaf(curr)){temp.push_back(curr->data);}
        if(curr->right!=NULL){curr=curr->right;}
        else{curr=curr->left;}
    }
    for(int i=temp.size()-1;i>=0;--i){
        res.push_back(temp[i]);
    }
    
}
void addleaves(vector<int>&res,Node*root){ 
    if(isLeaf(root)){ 
        res.push_back(root->data);
        return;
    }
    if(root->left!=NULL){addleaves(res,root->left);}
    if(root->right!=NULL){addleaves(res,root->right);}
}

void printResult(vector<int>& result) {
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
}
class Solution{
    public:
    vector<int>printBoundary(Node*root){ 
        vector<int>res;
        
        if(!root){return res;}
        
        if(!isLeaf(root)){res.push_back(root->data);}
        addleft(res,root);
        addleaves(res,root);
        addright(res,root);
        return res;
    }
};

int main() {
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution solution;

    // Get the boundary traversal
    vector<int> result = solution.printBoundary(root);

    // Print the result
    cout << "Boundary Traversal: ";
    printResult(result);

    return 0;}
