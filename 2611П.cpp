//
//  main.cpp
//  practice-10
//
//  Created by Соня Артеменко on 26.11.2021.
//

#include <iostream>

using namespace std;

struct Leaf {
     Leaf *right;
     Leaf *left;
     int val;
     
 };

 struct Tree {
     Leaf *root;
     Tree(): root(nullptr) {}
     bool empty() {
         if (root == nullptr) {return true;} else {return false;}
     }
     void addFirst(int value) {
         Leaf *p = new Leaf;
         root = p;
         p->val = value;
         p->left = nullptr;
         p->right = nullptr;
         return;
     }
     void addNext(int value, Leaf *p) {
         if (value < p->val) {
             if (p->left != nullptr) {
                 addNext(value, p->left);
             } else {
                 p->left = new Leaf;
                 (p->left)->val = value;
                 (p->left)->left = nullptr;
                 (p->left)->right = nullptr;
             }
         } else if (value > p->val) {
             if (p->right != nullptr) {
                 addNext(value, p->right);
             } else {
                 p->right = new Leaf;
                 (p->right)->val = value;
                 (p->right)->left = nullptr;
                 (p->right)->right = nullptr;
                
             }
         }
     }
     void add(int value) { //три эда, чтобы при вызове не передавать данные, которые имеют значение только для исполнителя
         if (empty()) {
             addFirst(value);
         } else {
             Leaf *r = root;
             addNext(value, r);
         }
     }
     void print() { //два принта, чтобы при вызове не передавать данные, которые имеют значение только для исполнителя
         printPro(root);
     }
     void printPro(Leaf *p) {
         if (empty()) {return;} else if (p!=nullptr) {
            printPro(p->left);
            cout << p->val << endl;
            printPro(p->right);
         }
     }
     Leaf* deleteGiven(int value) {
         return deleteGivenPro(root, value);
     }
     Leaf* deleteGivenPro(Leaf* p, int value){
         if (p == nullptr) {
             return p;
         }
         if (value == p->val){
             Leaf* temp;
             if (p->right == nullptr) {
                 temp = p->left;
             } else {
                 Leaf* ptr = p->right;
                 if(ptr->left == nullptr){
                     ptr->left = p->left;
                     temp = ptr;
                 } else {
                     Leaf* pmin = ptr->left;
                     while(pmin->left != NULL){
                         ptr  = pmin;
                         pmin = ptr->left;
                     }
                     ptr->left = pmin->right;
                     pmin->left = p->left;
                     pmin->right = p->right;
                     temp = pmin;
                 }
             }
             delete p;
             return temp;
         } else if (value < p->val) {
             p->left = deleteGivenPro(p->left, value);
         } else {
             p->right = deleteGivenPro(p->right, value);
         }
         return p;
     }
     void height() {
         if (empty()) {return;}
         int k = 0;
         Leaf *p = root;
         while (p!=nullptr) {
             k++;
             p = p->left;
         }
         cout<<k<<endl;
     }
     void directTraversal () {
         directTraversalPro(root);
     }
     
     void directTraversalPro(Leaf *p) {
         if (empty()) {return;}
         if (p) {
                cout<<p->val<<endl;
                directTraversalPro(p->left);
                directTraversalPro(p->right);
         }
     }
     void symmetricTraversal() {
         symmetricTraversalPro(root);
     }
     void symmetricTraversalPro(Leaf *p) {
         if (p) {
             symmetricTraversalPro(p->left);
             cout<<p->val<<endl;
             symmetricTraversalPro(p->right);
         }
     }
     void reverseTraversal() {
         reverseTraversalPro(root);
     }
     void reverseTraversalPro(Leaf *p) {
         if (p) {
             reverseTraversalPro(p->left);
             reverseTraversalPro(p->right);
             cout<<p->val<<endl;
         }
     }

 };



int main(int argc, const char * argv[]) {
    Tree tree;
    tree.add(78);
    tree.add(56);
    tree.add(14);
    tree.add(-11);
    tree.add(908);
    //tree.deleteGiven(56);
    //tree.print();
    //tree.height();
    //tree.directTraversal();
    //tree.symmetricTraversal();
    //tree.reverseTraversal();
}
