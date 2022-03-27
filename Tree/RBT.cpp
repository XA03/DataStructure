#include <bits/stdc++.h>

using namespace std;

class RBT;

class node{
    public:
        node* left;
        node* right;
        node* parent;
        int element,key,color;

        node(){};
        node(int element,int key):element(element),key(key){};

        friend class RBT;
};

class RBT{
    public:
        node* root;
        node* sentinel;

        RBT(){
            sentinel=new node();
            sentinel->color=1;
            root=sentinel;
            root->parent=sentinel;
        };


        node* Search(int key);
        node* Successor(node* cur);
        node* leftmost(node* cur);


        void leftrotation(node* cur);
        void rightrotation(node* cur);
        void insert(int element,int key);
        void insertfix(node* cur);
        void deletion(int key);
        void deletionfix(node* cur);
};

node* RBT::Search(int key){
    node* cur=root;
    while(cur!=sentinel && key!=cur->key){
        if(key<cur->key)cur=cur->left;
        else cur=cur->right;
    }

    return cur;
}

node* RBT::Successor(node* cur){
    if(cur->right!=sentinel)return leftmost(cur->right);

    node* new_node=cur->parent;
    while(new_node!=sentinel && cur==new_node->right){
        cur=new_node;
        new_node=new_node->parent;
    }
    return new_node;
}

node* RBT::leftmost(node* cur){
    while(cur->left!=sentinel)cur=cur->left;
    return cur;
}

void RBT::leftrotation(node* cur){
    node* rc=cur->right;
    cur->right=rc->left;
    
    if(rc->left!=sentinel)rc->left->parent=cur;
    rc->parent=cur->parent;
    
    if(cur->parent==sentinel)root=rc;
    else if(cur==cur->parent->left)cur->parent->left=rc;
    else cur->parent->right=rc;

    rc->left=cur;
    cur->parent=rc;
}

void RBT::rightrotation(node* cur){
    node* lc=cur->left;
    cur->left=lc->right;
    
    if(lc->right!=sentinel)lc->right->parent=cur;
    lc->parent=cur->parent;

    if(cur->parent==sentinel)root=lc;
    else if(cur==cur->parent->left)cur->parent->left=lc;
    else cur->parent->right=lc;

    lc->right=cur;
    cur->parent=lc;
}

void RBT::insert(int element,int key){
    node* cur=root;
    node* parent=sentinel;
    node* new_node = new node(element,key);

    while(cur!=sentinel){
        parent=cur;
        if(new_node->key<cur->key)cur=cur->left;
        else cur=cur->right;
    }

    new_node->parent=parent;

    if(parent==sentinel)root=new_node;
    else if(new_node->key<parent->key)parent->left=new_node;
    else parent->right=new_node;

    new_node->left=sentinel;
    new_node->right=sentinel;
    new_node->color=0;

    insertfix(new_node);
}

void RBT::insertfix(node* cur){
    while(cur->parent->color==0){
        
        if(cur->parent==cur->parent->parent->left){
            node* uncle=cur->parent->right;
            
            if(uncle->color==0){
                cur->parent->color=1;
                uncle->color=1;
                cur->parent->parent->color=0;
                cur=cur->parent->parent;
            }

            else{
                if(cur==cur->parent->left){
                    cur->parent->color=1;
                    cur->parent->parent->color=0;
                    rightrotation(cur->parent->parent);
                }
                else{
                    cur=cur->parent;
                    leftrotation(cur);
                }
            }
        }
        else{
            node* uncle=cur->parent->left;

            if(uncle->color==0){
                cur->parent->color=1;
                uncle->color=1;
                cur->parent->parent->color=0;
                cur=cur->parent->parent;
            }

            else{
                if(cur==cur->parent->left){
                    cur=cur->parent;
                    rightrotation(cur);
                }
                else{
                    cur->parent->color=1;
                    cur->parent->parent->color=0;
                    leftrotation(cur->parent->parent);
                }
            }


        }




    }
    root->color=1;
}

void RBT::deletion(int key){
    node* de_node=Search(key);

    if(de_node==sentinel){
        cout<<"沒有這個node\n";
        return ;
    }

    node* release;
    node* release_child;
    if(de_node->left==sentinel || de_node->right==sentinel)release=de_node;
    else release=Successor(de_node);

    if(release->left!=sentinel)release_child=release->left;
    else release_child=release->right;

    release_child->parent=de_node->parent;//release_child may be sentinel. It's promising.

    if(de_node->parent==sentinel)root=release_child;
    else if(release==release->left)release->parent->left=release_child;
    else release->parent->right=release_child;

    if(release!=de_node){
        de_node->key=release->key;
        de_node->element=release->element;
    }

    if(release->color==1){
        deletionfix(release_child);
    }

    delete release;
}

void RBT::deletionfix(node* cur){
    while(cur!=root && cur->color==1){
        node* sibling; 
        if(cur==cur->parent->left){
            sibling=cur->parent->right;
            if(sibling->color==0){
                sibling->color=1;
                sibling->parent->color=0;
                leftrotation(cur->parent);
                sibling=cur->parent->right;
            }

            if(sibling->left->color==1 && sibling->right->color==1){
                sibling->color=0;
                cur=cur->parent;
            }

            else{
                if(sibling->right->color==1){
                    sibling->left->color=1;
                    sibling->color==0;
                    rightrotation(sibling);
                    sibling=cur->parent->right;
                }

                sibling->color=cur->parent->color;
                cur->parent->color=1;
                ibling->right->color=1;
                leftrotation(cur->parent);
                cur=root;
            }
        }
        else{
            sibling=cur->parent->left;

            if(sibling->color==0){
                cur->parent->color=0;
                sibling->color=1;
                rightrotation(cur->parent);
                sibling=cur->parent->left;
            }

            if(sibling->left->color=1= && sibling->right->color=1){
                sibling->color=0;
                cur=cur->parent;
            }

            else{
                if(sibling->left->color==1){
                    sibling->right->color=1;
                    sibling->color=0;
                    leftrotation(sibling);
                    sibling=cur->parent->left;
                }

                sibling->color=cur->parent->color;
                cur->parent->color=1;
                sibling->left->color=1;
                rightrotation(cur->parent);
                cur=root;
            }
        }
    }
    cur->color=1;
}

int main(){

    RBT test;

    test.insert(33,0);






    return 0;
}