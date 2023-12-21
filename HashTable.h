#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "ArrayList.h"
#include "LinkedList.h"

template <class T> 
struct HashTable{

    ArrayList<LinkedList<T> > storage;
    int K;

    HashTable(){
        K = 10;
        for(int i = 0; i < K; i++){
            storage.append(LinkedList<int>());
        }
    }

    HashTable(int K){
        this->K = K;
        for(int i = 0; i < K; i++){
            storage.append(LinkedList<int>());
        }
    }

    int f (int x){
        int ans = x % K;
        if (ans < 0){
            ans += K;
        }
        return ans;
    }

    void add(int value){
        int pos = f(value);
        
        storage[pos].append(value);
    }


    bool search(int value){
        int pos = f(value);
        return storage[pos].search(value);
    }


};

template <class T>
std::ostream& operator<<(std::ostream& os, const HashTable<T>& container){
    for (int i = 0; i < container.K; i++){
        os << i << ": " << container.storage.get(i) << std::endl;
    }

    return os;
}

#endif