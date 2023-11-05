// HashTable.h

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "LinkedList.h"
#include <stdexcept>
#include <iostream>

using namespace std;

template <typename DataType, typename KeyType>
class HashTable {
public:

//TB, idk if this works yet
    HashTable(int initTableSize)
    {
	    tableSize = initTableSize;

	    dataTable = new LinkedList<DataType, KeyType>[tableSize];
    }
    //TB
    //copy constructor: input HashTable to be copied
    HashTable(const HashTable& other)
    {
	    copyTable(other);
    }
    //TB
    //input HashTable to copy, output the HashTable
    HashTable& operator=(const HashTable& other)
    {
	    copyTable(other);
	    return other;
    }

    //TB
    //destructor: clears the list
    ~HashTable()
    {
	    clear();
    }

    void insert(const DataType& newDataItem, const KeyType& key) {}
    bool remove(const KeyType& deleteKey) { return true; }
    bool retrieve(const KeyType& searchKey, DataType& returnItem) const {return true;}
    void clear() {}

    bool isEmpty() const {return true;}

    void showStructure() const {}

private:
    void copyTable(const HashTable& source) {}

    int tableSize;
    LinkedList<DataType, KeyType>* dataTable;
};

#endif // ifndef HASHTABLE_H
