//
//  main.cpp
//  practice-10
//
//  Created by Соня Артеменко on 09.12.2021.
//

#include <iostream>
#include <string>
#include <new>
#include <assert.h>
using namespace std;
typedef unsigned int uint;
 

template<typename key, typename value>
class associativeArray {
    struct note {
        key keyk;
        value data;
    };
 
private:
    
    note* a;
    uint  k;
    uint  mem;
public:
    associativeArray(void):a(NULL), k(0), mem(16){}
    ~associativeArray(){
        this->clear();
    }
    associativeArray(const associativeArray&);
    associativeArray& operator = (const associativeArray&);
public:
        value* add(const key& keyk, const value& data){
        uint i = _bin_find(keyk);
        if(_heap_alloc_() == false) {
            return nullptr;
        }
        if (keyk == a[i].keyk) {
            return nullptr;
        }
        if(i < k){
            note *pb = a + k;
            note *pa = a + i;
            for(;pb > pa; --pb)
                *pb = *(pb - 1);
        }
        a[i].keyk = keyk;
        a[i].data = data;
        k++;
        return &a[i].data;
    }
    void remove(const key& keyk){
        uint i = _bfind_data(keyk);
        if (i != (uint)-1) {
            k--;
            note *pa = a + i;
            note *pb = a + k;
            for(;pa < pb; ++pa) {
                *pa = *(pa + 1);
            }
            if(!k) {
                this->clear();
            }
        }
    }
    value* find(const key& keyk){
        uint i = _bfind_data(keyk);
        return (i != (uint)-1) ? &a[i].data : NULL;
    }
    const value* find(const key& keyk) const {
        const uint i = _bfind_data(keyk);
        if (i != (uint)-1) {
            return &a[i].data;
        } else {
            return nullptr;
        }
    }
    bool empty(void) const {
        return (a == NULL);
    }
    void size(void) const {
         cout<< k << endl;
    }
    void clear(void){
        if(a != NULL)
        delete[] a;
        a = NULL;
        k = 0;
        mem = 0;
    }
    const key& keyAt(uint i) const {
        return a[i].key;
    }
 
    value& valueAt(uint i) const {
        return a[i].data;
    }
 
    const value& operator [] (const key& keyk) const {
        const uint i = _bfind_data(keyk);
        assert(i != (uint)-1);
        return a[i].data;
    }
 
    value& operator [] (const key& keyk){
        uint i = _bin_find(keyk);
        if((i < k) && (keyk == a[i].keyk)) {
            return a[i].data;
        }
        if(_heap_alloc_()){
            if(i < k){
                note* pb = a + k;
                note* pa = a + i;
                for(;pb > pa; --pb)
                    *pb = *(pb - 1);
            }
            a[i].keyk  = keyk;
            a[i].data = value();
            k++;
        } else {
            assert(false);
        }
        return a[i].data;
    }
 
private:
 
    bool _heap_alloc_(void){
        if(a == NULL){
            a = new (std::nothrow) note[mem];
            if(a == NULL)
                return false;
        } else if((k + 1) >= mem){
            uint  tmem = k + mem / 2;
            note* tmp  = new (std::nothrow) note[tmem];
            if(tmp == NULL)
                return false;
            
            const note* p = a;
            const note* e = a + k;
            note* d = tmp;
            while(p != e)
                *d++ = *p++;
 
            delete[] a;
            a = tmp;
            mem = tmem;
        }
        return true;
    }
    uint _bin_find(const key& keyk){
        if(! k || (keyk < a[0].keyk))
            return 0;
        else if(a[k - 1].keyk < keyk)
            return k;
 
        uint m = 0, f = 0, l = k;
 
        while(f < l){
            m = (f + l) >> 1;
            if(keyk < a[m].keyk)
                l = m;
            else {
                if(keyk == a[m].keyk)
                    return m;
                f = m + 1;
            }
        }
        return f;
    }
    uint _bfind_data(const key& keyk) const {
        if(! k || (keyk < a[0].keyk))
            return (uint)-1;
        else if(a[k - 1].keyk < keyk)
            return (uint)-1;
 
        uint m = 0, f = 0, l = k;
 
        while(f < l){
            m = (f + l) >> 1;
            if(keyk < a[m].keyk)
                l = m;
            else {
                if(keyk == a[m].keyk)
                    return m;
                f = m + 1;
            }
        }
        return (uint)-1;
    }
};
 
 
 
int main(){
    associativeArray<string, int> q;
    q.remove("bully-style joke"); //удаление по ключу
    q.add("smile", 3); //вставки
    q.add("compliment", 10);
    q.add("said hello first", 17);
    q.add("said some nice words", 7);
    q.add("helped with hw", 99);
    q.add("bully-style joke", -99);
    q.add("joined party", 50);
    q.add("organised party", 100);
    cout << q["compliment"] << endl; //вывод по ключу
    q.size(); //размер
    q.clear();
    return 0;
}
