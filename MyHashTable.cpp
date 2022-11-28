//
// Created by Turner on 11/27/22.
//

#include "MyHashTable.h"

// hash the key
int MyHashTable::hash(string key) const { // O(k) where k is key length = O(1)
    int hashValue = 0;
    for (int i = 0; i < key.size(); i++) { // creates a unique hash based on character_size * position % size
        hashValue = (hashValue + key[i] * i) % this->size;
    }
    return hashValue;
}


// create an array of HashData of size 50
MyHashTable::MyHashTable() { // O(50) = O(1)
    hashTable = new HashData *[size];

    // initialize all the values in hashTable as nullptr
    for (int i = 0; i < size; i++) {
        hashTable[i] = nullptr;
    }
}


// create an array of HashData of a size based on user input
MyHashTable::MyHashTable(int size) { // O(s)
    hashTable = new HashData *[size];

    // initialize all the values in hashTable as nullptr
    for (int i = 0; i < size; i++) {
        hashTable[i] = nullptr;
    }
}

// set the value at a key in the hashtable
void MyHashTable::set(string key, int value) { // O(1) with no collisions, O(n) with collisions

    if(value < 0){
        cout << "Error: value cannot be negative - " << key << " was not added" << endl;
        return;
    }

    int hashValue = hash(key);  // hash the key

    // if the hashValue spot in hashTable is taken and
    // the key is not already present in hashTable
    // increase the hashValue by 1
    while (hashTable[hashValue] != nullptr && hashTable[hashValue]->key != key) {
        hashValue++;
    }

    // prevent memory leak if setting value at same key
    if (hashTable[hashValue] != nullptr) {
        delete hashTable[hashValue];
    }

    // insert HashData into table
    hashTable[hashValue] = new HashData(key, value);
}

// get the value at a key
int MyHashTable::get(string key) { // O(1) with no collisions, O(n) with collisions
    int hashValue = hash(key);  // hash the key

    // if the hashValue spot in hashTable is taken and
    // the key is not already present in hashTable
    // increase the hashValue by 1
    while (hashTable[hashValue] != nullptr && hashTable[hashValue]->key != key) {
        hashValue++;
    }

    // if the HashData at this hashValue is a nullptr return -1 to indicate not found
    if (hashTable[hashValue] == nullptr) {
        return -1;
    }

    // return the value found that matches key
    return hashTable[hashValue]->value;
}


// adds value at a key to existing value at the same key if possible
void MyHashTable::add(string key, int value) {  // O(1) with no collisions from add function
    // O(n) with collisions from add function
    int hashValue = hash(key);  // hash the key

    // if the hashValue spot in hashTable is taken and
    // the key is not already present in hashTable
    // increase the hashValue by 1
    while (hashTable[hashValue] != nullptr && hashTable[hashValue]->key != key) {
        hashValue++;
    }


    // add value to existing value instead of replacing
    if (hashTable[hashValue] != nullptr) {
        if ((hashTable[hashValue]->value + value) > -1) {
            hashTable[hashValue]->value += value;
        } else cout << "Error: value cannot be negative - value was not changed" << endl;
        return;
    }

    // insert HashData into table
    hashTable[hashValue] = new HashData(key, value);
}

// remove a value and output if successful
void MyHashTable::removeAll(string key) { // O(1) with no collisions, O(n) with collisions
    int hashValue = hash(key);  // hash the key

    if (get(key) == -1) {
        cout << key << " does not exist" << endl;
        return;
    }

    delete hashTable[hashValue];
    cout << "Successfully removed " << key << endl;

}

void MyHashTable::remove(string key, int value) { // O(1) with no collisions, O(n) with collisions
    if (get(key) == -1) {
        cout << "Value does not exist" << endl;
        return;
    }

    // invert the value and add
    value *= -1;
    add(key, value);
}
