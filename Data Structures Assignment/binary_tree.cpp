/*
Print all nodes of a perfect binary tree in a specific order.
Given a perfect binary tree, print the values of alternating left and right nodes for each level in a top-
down and bottom-up manner.
For example, there are two ways to print the following tree:
Variation 1: Print Top-Down
(1, 2, 3, 4, 7, 5, 6, 8, 15, 9, 14, 10, 13, 11, 12)

Variation 2: Print Bottom-Up
(8, 15, 9, 14, 10, 13, 11, 12, 4, 7, 5, 6, 2, 3, 1)
*/

#include<iostream>
#include<queue>
#include<vector>
#include<unordered_map>
using namespace std;

struct Node
{
    int data;
    Node *l,*r;
    Node(int data)
    {
        this->data = data;
        this->l = NULL;
        this->r = NULL;
    }
};

void printNode_top_down(Node* root)
{
    if(root==NULL){
    return;
    }
    
    cout<<root->data<<" "; //print the root Node
    
    queue<Node*>q1,q2; //create two empty queues and enqueue root's left and right child, respectively
    
    if(root->l && root->r)
    {
        q1.push(root->l);
        q2.push(root->r);
    }
    while(!q1.empty()) //loop till queue is empty
    {
        int n = q1.size(); //process every node of the current level
        
        while(n--) //process every node of the current level
        {
            Node* x = q1.front();//dequeue front node from the first queue and print it
            q1.pop();
            cout<<x->data<<" ";
            
            if(x->l)//enqueue left and right child of 'x' to the first queue
            {
                q1.push(x->l);
            }
            
            if(x->r)
            {
                q1.push(x->r);
            }
            
            Node* y = q2.front(); //dequeue front node from the second queue and print it
            q2.pop();
            cout<<y->data<<" ";
            
            if(y->r) //enqueue left and right child of 'x' to the first queue
            {
                q2.push(y->r);
            }
            
            if(y->l)
            {
                q2.push(y->l);
            }
            
        }
    }
}

void printNodes_bottom_up(Node* root)
{
  if(root ==NULL) //return if the tree is empty
  {
   return ;
   }

  int level = 1;

  unordered_map<int, vector<int>> map; //create an empty multimap of int associated with multiple values

  map[level].push_back(root->data); //insert the root node at the first level
  queue<Node*>q1,q2;
  
  if(root->l && root->r)
  {
    q1.push(root->l);
    q2.push(root->r);
   }

    while(!q1.empty()) //loop till queue is empty
    {
      level++;
      int n = q1.size();

       while(n--)
        {
            Node* x = q1.front(); //dequeue front node from the first queue and print it
            q1.pop();
       
            map[level].push_back(x->data);
             if(x->l) { q1.push(x->l); } //enqueue left and right child of 'x' to the first queue
            
            if(x->r) { q1.push(x->r); }
            Node* y = q2.front(); //dequeue front node from the first queue and print it
            q2.pop();
            map[level].push_back(y->data);
            if(y->r) { q2.push(y->r); } //enqueue left and right child of 'x' to the first queue
            
            if(y->l) { q2.push(y->l); }
         }
     }
        for(int i=map.size();i>0; i--)        //print all nodes present at every level
        {
           for(int j: map[i]){
             cout<<j<<" ";
        }
     }
 }           
int main()
{
    Node* root = new Node(1);
    
    root->l = new Node(2);
    root->r = new Node(3);
    root->l->l = new Node(4);
    root->l->r = new Node(5);
    root->r->l = new Node(6);
    root->r->r = new Node(7);
    root->l->l->l = new Node(8);
    root->l->l->r = new Node(9);
    root->l->r->l = new Node(10);
    root->l->r->r = new Node(11);
    root->r->l->l = new Node(12);
    root->r->l->r = new Node(13);
    root->r->r->l = new Node(14);
    root->r->r->r = new Node(15);
    
    cout<<"Print Top-Down"<<endl;
    printNode_top_down(root);
    
    cout<<"\nPrint Bottom-Up"<<endl;
    printNodes_bottom_up(root);
    cout << endl;
    
    return 0;
}
