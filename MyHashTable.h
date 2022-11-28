//
// Created by Turner on 11/27/22.
//

#ifndef HASHTABLEIMPLEMENTATION_MYHASHTABLE_H
#define HASHTABLEIMPLEMENTATION_MYHASHTABLE_H

#include <iostream>

using namespace std;

// create a data entry for hash table
class HashData{
public:
    string key;
    int value;

    HashData(string key, int value){
        this->key = key;
        this->value = value;
    }
};

class MyHashTable{
private:
    HashData** hashTable; // 2D array of HashData
    int hash(string key) const;
    int size = 50;
public:
    MyHashTable();
    explicit MyHashTable(int size);
    void set(string key, int value);
    int get(string key);
    void add(string key, int value);
    void removeAll(string key);
    void remove(string key, int value);
};





#endif //HASHTABLEIMPLEMENTATION_MYHASHTABLE_H
