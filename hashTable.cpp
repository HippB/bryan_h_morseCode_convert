#include "hashTable.h"
#include "function.h"
#include <iostream>
#include <string>

//create hash code with compression. From textbook
int hashCode(char letter){
    int h = 0;
    letter = tolower(letter);
    h = 31 * h + letter;
    int h_compressed = h % 31;    // remainder operation being amount of characters for MorseCode
    if (h_compressed < 0) { h_compressed = -h_compressed; }
    return h_compressed;    //returns hash code
}

// creates the hash table size
HashTable::HashTable(){
	for(int i = 0; i < 31; i++){
        buckets[i] = nullptr;
    }
	current_size=0;
}

// takes the letter and its morse code equivalent and puts them in the hash table
void HashTable::insert(char c, std::string morse) {
    int h = hashCode(c); 
    
    Node* current = buckets[h]; 
    while (current != nullptr) {
        if (current-> dataChar == c) { return; } // Already in the set
        current = current->next; 
    }
    
    // this creates the new node, contains both character and Morse code 
    // then connects it to the bucket
    Node* new_node = new Node; 
    new_node->dataChar = c;
    new_node->dataMorse = morse;
    new_node->next = buckets[h]; 
    buckets[h] = new_node; 
    current_size++;
}

int HashTable::size() const {
    return current_size;    //gets the size of list
}

// it will empty the bucket to clear the memory usage
// goes through each bucket and deletes its nodes
void HashTable::clearTable(){
	for(int i = 0; i < 31; i++){
		Node* temp = buckets[i];
		Node* temp2 = nullptr;
		while(temp != nullptr){
			temp2 = temp -> next;
			delete temp;
			temp = temp2;
		}
	}
}

// uses the character's hash code to search through the hash table 
// to look for the desired character in its parameter
// After finding the character, prints the Morse code for that character 
void HashTable::find(char c) {
	int h = hashCode(c);
	c = toupper(c);
	Node* current = buckets[h];
	while (current != nullptr) {
        if (current-> dataChar == c) { 
			std::cout << current -> dataMorse;
		}
        current = current->next; 
    } 

}
