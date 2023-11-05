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

//TB, not sure if this is right
    HashTable(int initTableSize)
    {
	    tableSize = initTableSize;

	    dataTable = new LinkedList<DataType, KeyType>;
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

//TB
    void insert(const DataType& newDataItem, const KeyType& key)
    {
	    dataTable->insert(newDataItem, key);
    }

    //TB
    bool remove(const KeyType& deleteKey)
    {
	    return dataTable->remove(deleteKey);
    }

    //TB
    bool retrieve(const KeyType& searchKey, DataType& returnItem) const
    {
	    return dataTable->retrieve(searchKey, returnItem);
    }
    
    void clear()
    {
	    dataTable->clear();
    }

    bool isEmpty() const
    {
	    return dataTable->isEmpty();
    }
//TB
    void showStructure() const 
    {
	    dataTable->showStructure();
    }

private:
    //TB
    void copyTable(const HashTable& source)
    {
	    //clear source incase it isn't empty
	    source.clear();

	    Node<DataType, KeyType>* tracker = dataTable->getHead();
	    while(tracker != nullptr)
	    {
		    source.insert(tracker->data, tracker->key);
		    tracker = tracker->next;
	    }
    }

    int tableSize;
    LinkedList<DataType, KeyType>* dataTable;
};

#endif // ifndef HASHTABLE_H
