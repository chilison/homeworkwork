//
//  main.cpp
//  wtf
//
//  Created by Соня Артеменко on 17.12.2021.
//

#include <iostream>
#include <vector>

using namespace std;


struct Leaf {
      vector<Leaf*> leaves;
      int val;
};

struct Tree {
    Leaf *root;
    Tree(): root(nullptr) {}
    bool empty() {
        if (root == nullptr) {return true;} else {return false;}
    }
    void addFirst(int value) {
        cout<<"ворнинг! лучше все рисовать, потому что программа рассчитана на слишком сообразительного пользователя... имеется в виду, что пользователь не пойдет дальше, если веток еще не создал, при желании создать бинарное дерево поиска сначала нужно добавлять меньшее значение, если такое имеется"<<endl;
        Leaf *p = new Leaf;
        root = p;
        p->val = value;
        cout<<"добавлен корень "<<value<<endl;
        return;
    }
    void addNext(int value, Leaf *p) {
        cout<<"создать новую ветку? жмяк 1"<<endl;
        cout<<"идем дальше? жмяк 2"<<endl;
        int r;
        cin>>r;
        if (r==1) {
            Leaf *newLeaf = new Leaf;
            newLeaf->val = value;
            (p->leaves).push_back(newLeaf);
            cout<<"значение "<<value<<" добавлено"<<endl;
            return;
        } else if (r==2) {
            cout<<"сейчас здесь "<<(p->leaves).size()<<" ветка/ветки/веток"<<endl;
            for (auto i=p->leaves.begin(); i!=p->leaves.end(); i++) {
                cout<<(*i)->val<<" ";
            }
            cout<<endl;
            cout<<"номер ветки, по которой пойдем, пожалуйста"<<endl;
            int k;
            cin>>k;
            return (addNext(value, (p->leaves)[k-1]));
         } else {
            cout<<"1 или 2, пожалуйста"<<endl;
            return addNext(value, p);
        }
    }
    void add(int value) {
        if (empty()) {
            addFirst(value);
        } else {
            Leaf *r = root;
            addNext(value, r);
        }
    }
    void rebuildTree(Leaf *p) { //перестраиваю дерево так, чтобы при обходе получить верный вектор
        if ((p->leaves).size() == 1) {
            if ((p->leaves)[0]->val > p->val) {
                (p->leaves).push_back((p->leaves)[0]);
                Leaf *bimbo = new Leaf;
                bimbo->val=INT_MIN; //любое целочисленное может быть в дереве, поэтому хотя бы так
                (p->leaves)[0] = bimbo;
               
            }
        }
        if ((p->leaves).size()!=0) {rebuildTree((p->leaves)[0]);}
        if ((p->leaves).size()==2) {rebuildTree((p->leaves)[1]);}
        
    }
    void check () {
        int r = 1;
        checkBinary(root, r);
        if (r==1) {
            rebuildTree(root);
            vector<int> a;
            checkBST(root, a);
            /*for (int i=0; i<a.size(); i++) {
                cout<<a[i]<<" ";
            }
            cout<<endl;*/
            for (int i=0; i<a.size()-1; i++) {
                if (a[i] != INT_MIN && a[i+1] != INT_MIN && a[i]>=a[i+1]) {r=0; break;}
            }
        }
        cout<<"answer "<<r<<endl;
    }
    void checkBinary(Leaf *p, int& r) {
        if (p) {
            if ((p->leaves).size()>2) {r=-1; return;}
            if ((p->leaves).size()!=0) {checkBinary((p->leaves)[0], r);}
            if ((p->leaves).size()==2) {checkBinary((p->leaves)[1], r);}
        }
    }
    void checkBST(Leaf *p, vector<int>& a) {
        if (p) {
            if ((p->leaves).size()!=0) {checkBST((p->leaves)[0], a);}
            a.push_back(p->val);
            if ((p->leaves).size()==2) {checkBST((p->leaves)[1], a);}
        }
    }
    
    
    
};

int main() {
    Tree tree;
    /*tree.add(13);
    tree.add(15);
    tree.add(67);
    tree.add(6);
    tree.add(890);
    tree.add(893);
    // команды 1 1 2 2 1 2 2 1 2 2 1 итоговое дерево прикреплю картинкой    ! не бинарное -1 !*/
    /*tree.add(13);
    tree.add(15);
    tree.add(67);
    tree.add(6);
    tree.add(890);
    // команды 1 1 2 2 1 2 2 1  итоговое дерево прикреплю картинкой    ! бинарное 0 ! */
    /*tree.add(8);
    tree.add(3);
    tree.add(10);
    tree.add(1);
    tree.add(6);
    tree.add(4);
    tree.add(7);
    tree.add(14);
    tree.add(13);
    // 1  1  2 1 1  2 1 1  2 1 2 2 1  2 1 2 2 1  2 2 1  2 2 2 1 1  итоговое дерево прикреплю картинкой    ! бинарное дерево поиска 1 ! */
    tree.check();
}
