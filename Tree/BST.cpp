#include <bits/stdc++.h>

using namespace std;

class BST;

class Node{
    public:
        Node* left;
        Node* right;
        Node* parent;
        string word;
        int key;


        Node():left(NULL),right(NULL),parent(NULL),word(""),key(0){};
        Node(int input):left(NULL),right(NULL),parent(NULL),word(""),key(input){};
        Node(string str):left(NULL),right(NULL),parent(NULL),word(str),key(0){};
        Node(string str,int input):left(NULL),right(NULL),parent(NULL),word(str),key(input){};
        
        int Getkey(){return key;}
        string Getstr(){return word;}

    friend class BST;
};

class BST{
    public:
        Node* root;

        BST():root(NULL){};


        Node* leftmost(Node *current);
        Node* rightmost(Node* current);
        Node* Successor(Node *current);
        Node* Predecessor(Node* current);
        Node* Search(int key);
        void InsertBST(string str,int key);
        void Inorder(Node* root);
        void InorderReverse(Node* root);
        void LevelOrder(Node* root);
        void DeleteNode(int key);
};

Node* BST::leftmost(Node* current){
    while(current->left!=NULL)current=current->left;
    return current;
}

Node* BST::rightmost(Node* current){
    while(current->right!=NULL)current=current->right;
    return current;
}

Node* BST::Successor(Node* current){
    if(current->right!=NULL)return leftmost(current->right);
    Node* successor=current->parent;
    
    while(successor && current==successor->right){
        current=successor;
        successor=successor->parent;
    }

    return successor;
}

Node* BST::Predecessor(Node* current){
    if(current->left!=NULL)return rightmost(current->left);
    Node* predecessor=current->parent;
    while(predecessor && current==predecessor->left){
        current=predecessor;
        predecessor=predecessor->parent;
    }
    return predecessor;
}

Node* BST::Search(int key){
    Node* current=root;

    while(current!=NULL&&key!=current->key){
        if(key<current->key)current=current->left;
        else current=current->right;
    }
    
    return current;
}

void BST::InsertBST(string str,int key){
    Node* new_node=new Node(str,key);
    Node* parent=NULL;
    Node* current=NULL;

    current=root;

    while(current!=NULL){
        parent=current;
        if(new_node->key < current->key)current=current->left;
        else current=current->right;
    }

    new_node->parent=parent;

    if(parent==NULL)root=new_node;
    else if(new_node->key < parent->key)parent->left=new_node;
    else {
        parent->right=new_node;
    }
}

void BST::Inorder(Node* root){
    Node* current=leftmost(root);
    while(current!=NULL){
        cout<<current->word<<" "<<current->key<<endl;
        current=Successor(current);
    }
}

void BST::InorderReverse(Node* root){
    Node* current=rightmost(root);
    while(current!=NULL){
        cout<<current->word<<" "<<current->key<<endl;
        current=Predecessor(current);
    }
}

void BST::LevelOrder(Node* root){
    queue<Node*>q;
    q.push(root);
    
    while(!q.empty()){
        Node* current=q.front();
        q.pop();
        cout<<current->word<<" "<<current->key<<endl;
        if(current->left!=NULL)q.push(current->left);
        if(current->right!=NULL)q.push(current->right);
    }
}

void BST::DeleteNode(int key){
    Node* de_target=Search(key);
    if(de_target==NULL){
        cout<<"delete target doesn't exist.\n";
        return ;
    }

    Node* de_node;
    Node* de_node_child;

    if(de_target->left==NULL||de_target->right==NULL){
        de_node=de_target;
    }
    else{
        de_node=Successor(de_target);
    }

    if(de_node->left!=NULL)de_node_child=de_node->left;
    else de_node_child=de_node->right;

    if(de_node_child!=NULL)de_node_child->parent=de_node->parent;
    
    if(de_node->parent==NULL)root=de_node_child;
    else if(de_node==de_node->parent->left)de_node->parent->left=de_node_child;
    else de_node->parent->right=de_node_child;

    if(de_node!=de_target){
        de_target->key=de_node->key;
        de_target->word=de_node->word;
    }

    delete de_node;
    de_node=NULL;



}


int main(){

    return 0;
}