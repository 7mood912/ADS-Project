#include<iostream>
using namespace std;
class node{
public:
node* left;
node* right;
int data;};
class BST{
node* root;
public:
BST(){root = NULL;}
bool isEmpty() const { return root==NULL; }
void print_inorder();
void inorder(node*);
void print_preorder();
void preorder(node*);
void print_postorder();
void postorder(node*);
void insert(int);
void remove(int);
};
void BST::insert(int d){
node* t = new node;
node* parent;
t->data = d;
t->left = NULL;
t->right = NULL;
parent = NULL;
// is this a new tree?
if(isEmpty()) root = t;
else {
//Note: ALL insertions are as leaf nodes
node* curr;
curr = root;
// Find the Node's parent
while(curr){
parent = curr;
if(t->data > curr->data) curr = curr->right;
else curr = curr->left;}
if(t->data < parent->data)
parent->left = t;
else
parent->right = t;}
}
void BST::remove(int d){
bool found = false;
if(isEmpty()){
cout<<" This Tree is empty! "<<endl;
return;}
node* curr;
node* parent;
curr = root;
while(curr != NULL){
if(curr->data == d){
found = true;
break;}
else{
parent = curr;
if(d>curr->data) curr = curr->right;
else curr = curr->left;}}
if(!found){
cout<<" Data not found! "<<endl;
return;}
// 3 cases :
// 1. We're removing a leaf node
// 2. We're removing a node with a single child
// 3. we're removing a node with 2 children
// Node with single child
if((curr->left == NULL && curr->right != NULL)|| (curr->left != NULL && curr->right == NULL)){
if(curr->left == NULL && curr->right != NULL) {
if(parent->left == curr){
parent->left = curr->right;
delete curr; }
else{
parent->right = curr->right;
delete curr;}}
else{ // left child present, no right child
if(parent->left == curr){
parent->left = curr->left;
delete curr;}
else {
parent->right = curr->left;
delete curr;}}
return;}
//We're looking at a leaf node
if( curr->left == NULL && curr->right == NULL){
if(parent->left == curr) parent->left = NULL;
else parent->right = NULL;
delete curr;
return;}
//Node with 2 children
// replace node with smallest value in right subtree
if (curr->left != NULL && curr->right != NULL) {
node* chkr;
chkr = curr->right;
if((chkr->left == NULL) && (chkr->right == NULL)){
curr = chkr;
delete chkr;
curr->right = NULL;}
else{
// right child has children
//if the node's right child has a left child
// Move all the way down left to locate smallest element
if((curr->right)->left != NULL){
node* lcurr;
node* lcurrp;
lcurrp = curr->right;
lcurr = (curr->right)->left;
while(lcurr->left != NULL){
lcurrp = lcurr;
lcurr = lcurr->left;}
curr->data = lcurr->data;
delete lcurr;
lcurrp->left = NULL; }
else{
node* tmp;
tmp = curr->right;
curr->data = tmp->data;
curr->right = tmp->right;
delete tmp;}}
return;
}}
void BST::print_inorder(){
inorder(root);}
void BST::inorder(node* p){
if(p != NULL){
if(p->left) inorder(p->left);
cout<<" "<<p->data<<" ";
if(p->right) inorder(p->right);}
else return;}
void BST::print_preorder(){
preorder(root);}
void BST::preorder(node* p){
if(p != NULL){
cout<<" "<<p->data<<" ";
if(p->left) preorder(p->left);
if(p->right) preorder(p->right);}
else return;}
void BST::print_postorder(){
postorder(root);}
void BST::postorder(node* p){
if(p != NULL){
if(p->left) postorder(p->left);
cout<<" "<<p->data<<" "; }
else return;}
