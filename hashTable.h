#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <string>

int hashCode(char letter);

class Node{
private:
    char dataChar;
    std::string dataMorse;
    Node* next;
friend class HashTable;
};

//hash table for separate chaining
class HashTable{
public:
	HashTable(); // constructs hashtable with num of buckets
    void insert(char c, std::string morse); // adds elements x to table
    int size() const; //returns num of elements in the hash table
    void find(char c);
    void clearTable();	//clears memory of hash table

private:
    Node* buckets[31];
    int current_size;

};

#endif
