//
//  main.cpp
//  practice-9
//
//  Created by Соня Артеменко on 19.11.2021.
//

#include <iostream>

using namespace std;

struct Obj {
    Obj *prev;
    Obj *next;
    double val;
    Obj(double value): prev(nullptr), val(value), next(nullptr) {}
};

struct Sp {
    Obj *first;
    Obj *last;
    Sp(): first(nullptr), last(nullptr) {}
    bool empty() {
        if (first==nullptr) {return true;} else {return false;}
    }
    void add(int value) {
        Obj *p = new Obj(value);
            if (empty()) {
            first = p;
            last = p;
            return;
        }
        p->next=nullptr;
        p->val=value;
        if (empty()==false) {
            p->prev=last;
            last->next=p;
            last=p;
        } else {
            p->prev = nullptr;
            first=p;
            last=p;
        }
        
    }
    void print() {
        if (empty()==true) {
            return;
        }
        Obj *p=first;
        while (p) {
            cout<<(p->val)<<endl;
            p=p->next;
        }
    }
    void printPositions() {
        if (empty()==true) {
            return;
        }
        Obj *p=first;
        while (p) {
            cout<<(p->prev)<<" "<<" "<<p<<" "<<(p->next)<<endl;
            p=p->next;
        }
    }
    void position(double value) {
        Obj *p=first;
        while(p && p->val!=value) {
            p=p->next;
        }
        if (p->val ==value) {cout<<p<<endl;} else {cout<<"there is no such value"<<endl;}
    }
    void deleteLast() {
        if (empty()==true) {return;}
        Obj *p=first;
        if (first==last) {
            first=p->next;
            delete p;
            return;
        }
        while (p->next!=last) {
            p=p->next;
        }
        p->next=nullptr;
        delete last;
        last=p;
    }
    void deleteFirst() {
        if (empty()==true) {return;}
        Obj *p=first;
        (p->next)->prev=nullptr;
        first=p->next;
        delete p;
    }
    void deleteGiven(double value) {
        if (empty()==true) {return;}
        if (first->val==value) {deleteFirst(); return;}
        if (last->val==value) {deleteLast(); return;}
        Obj *p=first;
        Obj *curr=p->next;
        
        while (curr && curr->val!=value) {
            p=p->next;
            curr=curr->next;
        }
        if (curr!=nullptr) {
        ((p->next)->next)->prev=p;
        p->next=curr->next;
        curr->prev=p->prev;
        delete curr;
        } else {cout<<"there is no such element"<<endl; return;}
    }
    void changeValue(int value) {
        if (empty()==true) {
            return;
        }
        if (value%2==0) {
            Obj *p=first;
            while (p) {
                p->val=p->val/2;
                p=p->next;
            }
        } else {
            Obj *p=first;
            while (p) {
                p->val=3*(p->val)-1;
                p=p->next;
            }
        }
    }
    void reverse() { //попарно меняем соседние, пока не получится нужное
        if (empty()==true) {return;}
        Obj *prev=first;
        Obj *p=first;
        Obj *curr=prev->next;
        int a=0;
        while (p->next!=last) {
            p=p->next;
            a++;
        }
        a+=2;
        cout<<a<<endl;
        int aa=a;
        for (int j=0; j<a; j++) {
            prev=first;
            curr=prev->next;
            for (int i=0; i<aa-1; i++) {
                double rem=curr->val;
                curr->val=prev->val;
                prev->val=rem;
                curr=curr->next;
                prev=prev->next;
            }
            aa--;
        }
    }
    int size() {
        Obj *p=first;
        int a=0;
        while (p->next!=last) {
            p=p->next;
            a++;
        }
        a+=2;
        return a;
    }
    void get (int k) {
        if (k>size()-1) {cout<<"there is no such element"<<endl; return;}
        Obj *p=first;
        int i=0;
        while(i!=k) {
            p=p->next;
            i++;
        }
        cout<<(p->val)<<endl;
    }
    void getAsStack () {
        get(size()-1);
        deleteLast();
    }
    void orderCheck() {
        if (empty()==true) {return;}
        Obj *p=first;
        int a=size();
        int r=0;
        for (int i=0; i<a; i++) { //убывающая
            for (int j=0; j<a; j++) {
                for (int k=0; k<a-1; k++) {
                    if (k!=i && k!=j && i!=j) {
                        if (k==i || k==j) {
                            if (k+1!=a) {
                                if ( p->val<(((p->next)->next)->val)) {
                                    r=1; break;
                                }
                            }
                        } else {
                            if ( p->val<((p->next)->val)) {
                                r=1; break;
                            }
                        }
                    } else {r=1;}
                    p=p->next;
                }
                if (r==0) {
                    cout<<"could be in the decreasing order without "<< i<<", "<<j<<" elements"<<endl;
                    return;
                }
                r=0;
                p=first;
            }
        }
        
        for (int i=0; i<a; i++) { //возрастающая
            for (int j=0; j<a; j++) {
                for (int k=0; k<a-1; k++) {
                    if (k!=i && k!=j && i!=j) {
                        if (k==i || k==j) {
                            if (k+1!=a) {
                                if ( p->val>(((p->next)->next)->val)) {
                                    r=1; break;
                                }
                            }
                        } else {
                            if ( p->val>((p->next)->val)) {
                                r=1; break;
                            }
                        }
                    } else {r=1;}
                    p=p->next;
                }
                if (r==0) {
                    cout<<"could be in the increasing order without "<< i<<", "<<j<<" elements"<<endl;
                    return;
                }
                r=0;
                p=first;
            }
        }
        cout<<"could not be in the right order"<<endl;
        
    }
    void symmetric() {
        Obj *start=first;
        Obj *finish=last;
        int r=0;
        for (int i=0; i<size()/2; i++) {
            if ((start->val)!=(finish->val)) {
                r=1; break;
            }
            start=start->next;
            finish=finish->prev;
        }
        if (r==0) {cout<<"it is symmetric"<<endl;} else {cout<<"it is not symmetric"<<endl;}
    }

};


int main(int argc, const char * argv[]) {
    Sp spisok;
    /*for (int i=0; i<10; i++) {
        spisok.add(i); //задача 1 и 7
    }*/
    spisok.add(84);
    spisok.add(516);
    spisok.add(-11);
    spisok.add(267);
    spisok.add(24);
    spisok.add(-98236);
    //spisok.deleteFirst(); //задача 1 и 7
    //spisok.deleteLast(); //задача 1 и 7
    
    
    //int n;
    //cin>>n;
    //spisok.position(n);//задача 1
    //spisok.deleteGiven(516); //задача 1 и 7
    
    
    //int data;
    //cin>>data;
    //spisok.changeValue(data); //задача 2
   
    //spisok.reverse(); //задача 3
    //spisok.orderCheck(); //задача 4
    //spisok.get(10); //просто так
    //spisok.getAsStack(); //задача 5 удаление последнего уже реализовано, добавление в конец тоже, поэтому только get с удалением
    
    //spisok.symmetric(); //задача 8
    //spisok.print(); //задача 1
    return 0;
}
