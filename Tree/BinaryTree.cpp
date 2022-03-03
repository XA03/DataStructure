#include <bits/stdc++.h>

using namespace std;

// reference http://alrightchiu.github.io/SecondRound/binary-tree-introjian-jie.html

class BinaryTree;

class Node{
    public:
        int value;
        Node* parent;
        Node* left;
        Node* right;
        Node():value(0),parent(NULL),left(NULL),right(NULL){};
        Node(int input):value(input),parent(NULL),left(NULL),right(NULL){};
    friend class BinaryTree;
};

class BinaryTree{
    public:
        Node* root;
        BinaryTree():root(NULL){};
        BinaryTree(vector<int>arr);

        void buildTree(vector<int>arr);
        void insertbyorder(int input);
        void Preorder(Node* current);
        void Inorder(Node* current);
        void Postorder(Node* current);
        void Levelorder(Node* current);
        void Inorder_by_parent(Node* current);
        void Inorder_Reverse(Node* current);

        Node* leftmost(Node* current);
        Node* rightmost(Node* current);
        Node* inorderpredecessor(Node* root);    //inorder 的 前一個node
        Node* inordersuccessor(Node* root);      //inorder 的 下一個node
};

BinaryTree::BinaryTree(vector<int>arr){
    Node* new_node=new Node(arr[0]);
    root=new_node;
    buildTree(arr);
}

void BinaryTree::buildTree(vector<int>arr){
    queue<Node*>q;
    Node* current=root;
    root->value=arr[0];

    for(int i=1;i<arr.size();i++){

        if(arr[i]==-1)continue;

        Node* new_node=new Node(arr[i]);
        if(i%2==1){
            new_node->parent=current;
            current->left=new_node;
            q.push(new_node);
        }
        else{
            new_node->parent=current;
            current->right=new_node;
            q.push(new_node);
            current=q.front();
            q.pop();
        }
    }

}

void BinaryTree::insertbyorder(int input){
    queue<Node*>q;
    Node* current=root;

    while(current){
        if(current->left!=NULL)q.push(current->left);
        else{
            Node* new_node=new Node(input);
            new_node->parent=current;
            current->left=new_node;
            break;
        }

        if(current->right!=NULL)q.push(current->right);
        else{
            Node* new_node=new Node(input);
            new_node->parent=current;
            current->right=new_node;
            break;
        }
        current=q.front();
        q.pop();
    }

}

void BinaryTree::Preorder(Node* current){
    if(current){
        cout<<current->value<<endl;
        Preorder(current->left);
        Preorder(current->right);
    }
}

void BinaryTree::Inorder(Node* current){
    if(current){
        Inorder(current->left);
        cout<<current->value<<endl;
        Inorder(current->right);
    }    
}

void BinaryTree::Postorder(Node* current){
    if(current){
        Postorder(current->left);
        Postorder(current->right);
        cout<<current->value<<endl;
    }
}

void BinaryTree::Levelorder(Node* current){
    queue<Node*>q;
    q.push(root);

    while(!q.empty()){
        Node* cur=q.front();
        q.pop();
        cout<<cur->value<<endl;
        if(cur->left!=NULL)q.push(cur->left);
        if(cur->right!=NULL)q.push(cur->right);
    }


}

Node* BinaryTree::leftmost(Node* current){
    while(current->left!=NULL)current=current->left;
    return current;
}

Node* BinaryTree::rightmost(Node* current){
    while(current->right!=NULL)current=current->right;
    return current;
}

Node* BinaryTree::inordersuccessor(Node* current){
    if(current->right!=NULL)return leftmost(current->right);
    Node* Successor=current->parent;
    while(Successor!=NULL&&current==Successor->right){
        current=Successor;
        Successor=Successor->parent;
    }
    return Successor;
}

void BinaryTree::Inorder_by_parent(Node* root){
    Node* current=new Node;
    current=leftmost(root);

    while(current){
        cout<<current->value<<endl;
        current=inordersuccessor(current);
    }
}

Node* BinaryTree::inorderpredecessor(Node* current){
    if(current->left!=NULL)return rightmost(current->left);
    Node* Predeccessor=current->parent;
    while(Predeccessor!=NULL&&current==Predeccessor->left){
        current=Predeccessor;
        Predeccessor=Predeccessor->parent;
    }
    return Predeccessor;
}

void BinaryTree::Inorder_Reverse(Node* root){
    Node* current=new Node;
    current=rightmost(root);
    while(current){
        cout<<current->value<<endl;
        current=inorderpredecessor(current);
    }
}


int main(){

    vector<int>x={1,22,2,3,4,5};
    BinaryTree T(x);
    T.Inorder_by_parent(T.root);
    T.Inorder_Reverse(T.root);

    return 0;
}