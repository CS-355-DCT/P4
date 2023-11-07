// HashTable.h
// Origin: Dr. Etheridge
// Group Project #4
// Thomas Bendall, Drew Clark, Christelle Mbemba
// 11/7/2023

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "LinkedList.h"
#include <stdexcept>
#include <string>
#include <iostream>

using namespace std;

template <typename DataType, typename KeyType>
class HashTable {
public:

    //TB
    //Initializes table size, and dataTable
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
	    for(int i = 0; i < other.tableSize; i++)
		    dataTable[i] = other.dataTable[i];

	    return *this;
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
	    dataTable[findHash(key)].insert(newDataItem, key);
    }

    //TB
    bool remove(const KeyType& deleteKey)
    {
	    return dataTable[findHash(deleteKey)].remove(deleteKey);
    }

    //TB
    bool retrieve(const KeyType& searchKey, DataType& returnItem) const
    {
	    return dataTable[findHash(searchKey)].retrieve(searchKey, returnItem);
    }

    void clear()
    {
	    for(int i = 0; i < tableSize; i++)
		    dataTable[i].clear();
    }

    bool isEmpty() const
    {
	    for(int i = 0; i < tableSize; i++)
	    {
		    if(!dataTable[i].isEmpty())
			    return false;
	    }
	    return true;
    }

    //TB
    void showStructure() const 
    {
	    for(int i = 0; i < tableSize; i++)
	    {
		    cout << "Table " << i << ":";
		    dataTable[i].showStructure();
	    }
    }

private:
    //TB
    void copyTable(const HashTable& source)
    {
	    //clear source incase it isn't empty
	    source.clear();
	    for(int i = 0; i < tableSize; i++)
	    {
	   	 Node<DataType, KeyType>* tracker = dataTable[i].getHead();
	   	 while(tracker != nullptr)
	   	 {
			 source.dataTable[i](tracker->data, tracker->key);
		   	 tracker = tracker->next;
	   	 }
	    }
    }

    //Doesn;t work yet/ not finished
    int findHash(const KeyType& key) const
    {
	    return 0;
    }

    int tableSize;
    LinkedList<DataType, KeyType>* dataTable;
};

#endif // ifndef HASHTABLE_H
