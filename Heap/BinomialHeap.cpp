#include<bits/stdc++.h>
using namespace std;

//現階段的我實力不夠，只能看懂Code但實作仍欠火侯 Copy by https://www.codingninjas.com/codestudio/library/binomial-heap-317

// A Binomial Tree node.
struct Node
{
    int data, degree;
    Node *child, *sibling, *parent;
};
  
Node* newNode(int key)
{
    Node *temp = new Node;
    temp->data = key;
    temp->degree = 0;
    temp->child = temp->parent = temp->sibling = NULL;
    return temp;
}
  
// This function merges two Binomial Trees.
Node* mergeBinomialTrees(Node *bTree1, Node *bTree2)
{

    // Make sure b1 is smaller
    if (bTree1->data > bTree2->data)
        swap(bTree1, bTree2);
  
  /* 
        We make the larger valued tree
        a child of smaller valued tree
  */
    bTree2->parent = bTree1;
    bTree2->sibling = bTree1->child;
    bTree1->child = bTree2;
    bTree1->degree++;
  
    return bTree1;
}
  
/*
    This function performs union operation on two.
    binomial heap i.e. l1 & l2
*/
list<Node*> unionBionomialHeap(list<Node*> bHeap1, list<Node*> bHeap2)
{

    /* _new to another binomial heap which contain
      new heap after merging l1 & l2
    */
    list<Node*> newNode;
    list<Node*>::iterator it = bHeap1.begin();
    list<Node*>::iterator ot = bHeap2.begin();
    while (it!=bHeap1.end() && ot!=bHeap2.end())
    {

        // If D(bHeap1) <= D(bHeap2)
        if((*it)->degree <= (*ot)->degree)
        {
            newNode.push_back(*it);
            it++;
        }

        // if D(bHeap1) > D(bHeap2)
        else
        {
            newNode.push_back(*ot);
            ot++;
        }
    }
  
    /* 
        If there remain some elements in bHeap1
        binomial heap
    */
    while (it != bHeap1.end())
    {
        newNode.push_back(*it);
        it++;
    }
  
    /*
        If there remain some elements in bHeap2
        binomial heap
    */
    while (ot!=bHeap2.end())
    {
        newNode.push_back(*ot);
        ot++;
    }
    return newNode;
}
  
/* 
    Adjust function helps in rearranging the heap so that
    the heap is in increasing order of degree and
    no two binomial trees have a similar degree in this heap
*/
list<Node*> adjust(list<Node*> _heap)
{
    if (_heap.size() <= 1)
        return _heap;
    list<Node*> new_heap;
    list<Node*>::iterator it1,it2,it3;
    it1 = it2 = it3 = _heap.begin();
  
    if (_heap.size() == 2)
    {
        it2 = it1;
        it2++;
        it3 = _heap.end();
    }
    else
    {
        it2++;
        it3=it2;
        it3++;
    }
    while (it1 != _heap.end())
    {

        // if only one element remains to be processed
        if (it2 == _heap.end())
            it1++;
  
        /* If D(it1) < D(it2) i.e. merging of the Binomial
          Tree pointed by it1 & it2 is not possible
          then move next in heap
        */
        else if ((*it1)->degree < (*it2)->degree)
        {
            it1++;
            it2++;
            if(it3!=_heap.end())
                it3++;
        }
  
        /* 
            If D(it1),D(it2) & D(it3) are the same i.e. the
            degree of the three consecutive Binomial 

            trees are the same in heap
        */
        else if (it3!=_heap.end() &&
                (*it1)->degree == (*it2)->degree &&
                (*it1)->degree == (*it3)->degree)
        {
            it1++;
            it2++;
            it3++;
        }
  
        // If degree of two Binomial Tree are same in heap
        else if ((*it1)->degree == (*it2)->degree)
        {
            Node *temp;
            *it1 = mergeBinomialTrees(*it1,*it2);
            it2 = _heap.erase(it2);
            if(it3 != _heap.end())
                it3++;
        }
    }
    return _heap;
}
  
// Inserting a Binomial Tree into binomial heap
list<Node*> insertATreeInHeap(list<Node*> _heap,
                              Node *tree)
{

    // Creating a new heap i.e temp
    list<Node*> temp;
  
    // Inserting Binomial Tree into heap
    temp.push_back(tree);
  
    /* 
        Perform union operation to insert finally
        Binomial tree in the original heap
    */
    temp = unionBionomialHeap(_heap,temp);
  
    return adjust(temp);
}
  
/* 
    Removing a minimum key element from the binomial heap
    this function takes Binomial Tree as input and return
    binomial heap after
    removing the head of the tree, i.e., the minimum element
*/
list<Node*> removeMinFromTreeReturnBHeap(Node *tree)
{
    list<Node*> heap;
    Node *temp = tree->child;
    Node *lo;
  
    // Making the binomial heap from the Binomial Tree
    while (temp)
    {
        lo = temp;
        temp = temp->sibling;
        lo->sibling = NULL;
        heap.push_front(lo);
    }
    return heap;
}
  
// A key is inserted into the binomial heap
list<Node*> insert(list<Node*> _head, int key)
{
    Node *temp = newNode(key);
    return insertATreeInHeap(_head,temp);
}
  
/* Returning the pointer of the minimum value Node
    present in the binomial heap
*/
Node* getMin(list<Node*> _heap)
{
    list<Node*>::iterator it = _heap.begin();
    Node *temp = *it;
    while (it != _heap.end())
    {
        if ((*it)->data < temp->data)
            temp = *it;
        it++;
    }
    return temp;
}
  
list<Node*> extractMin(list<Node*> _heap)
{
    list<Node*> new_heap,lo;
    Node *temp;
  
    /* temp contains the pointer of minimum value
      element in heap
    */
    temp = getMin(_heap);
    list<Node*>::iterator it;
    it = _heap.begin();
    while (it != _heap.end())
    {
        if (*it != temp)
        {

            /* Inserting all Binomial Tree into new
              binomial heap except the Binomial Tree
              contains minimum element
            */
            new_heap.push_back(*it);
        }
        it++;
    }
    lo = removeMinFromTreeReturnBHeap(temp);
    new_heap = unionBionomialHeap(new_heap,lo);
    new_heap = adjust(new_heap);
    return new_heap;
}
  
// Print function for Binomial Tree
void printTree(Node *h)
{
    while (h)
    {
        cout << h->data << " ";
        printTree(h->child);
        h = h->sibling;
    }
}
  
// Print function for binomial heap
void printHeap(list<Node*> _heap)
{
    list<Node*> ::iterator it;
    it = _heap.begin();
    while (it != _heap.end())
    {
        printTree(*it);
        it++;
    }
}
  
  
// Driver program to test above functions
int main()
{
    int ch,key;
    list<Node*> _heap;
  
    // Insert data in the heap
    cout << "Enter the number of elements to add\n";
    int n;
    
    cin >> n;
    
    cout << "Enter the elements\n";
    
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        _heap = insert(_heap,x);
    }
  
    cout << "Heap elements after inserting all elements:\n";
    printTree(*_heap.begin());
  
    return 0;
}
