#include "function.h"
#include "hashTable.h"
#include "binaryTree.h"
#include <iostream>
#include <fstream>
#include <string>

void intro(){
    std::cout << "In this program we will be converting Morse Code into text and vice versa" << std::endl;
    std::cout << "Type 1 to start the program! and 2 to exit!" << std::endl;
}

void makeTableTree(HashTable &t, binaryTree &b){
    std::ifstream astream;  // using ifstream to access the text file called astream
    std::string word;

    // "Yes!" begin the program by asking to write file name
    std::cout << "Using text file 'morse2021.txt' as cipher for the alphabet and Morse code equivalence" << std::endl;
                
    // opens the desired text file according to user's input
    astream.open("morse2021.txt");

    // checks if astream opened an actual file, maybe misspelling file name
    if(astream.is_open()){
    //to place all of the original text to the linked list
        while(std::getline(astream,word)){
			
			std::string morseString;
			int Length = word.length();
			// in the text file, word[0] is the alphabetic letter
			// starting on word[2] is the Morse code equivalent
			for(int i = 2; i < Length; i++){
				morseString += word[i];
			}
            t.insert(word[0], morseString);
            b.insertMorse(morseString, word[0]);
            
        }
         // closes the desired text file
        //std::cout<<"closed";
        astream.close();
        
    }
                // ends program if no file was opened
        else{
            std::cout << "There exists no such file." << std::endl;
            return;
        }
}

void readAlphaMorse(HashTable &t, binaryTree &b){
    std::string file_name;  // for user to enter text file name
    std::ifstream astream;  // using ifstream to access the text file called astream
    std::string word;

    // "Yes!" begin the program by asking to write file name
    std::cout << "Please enter the text file of your choice." << std::endl;
    std::cout << "Input file name: ";
    std::cin >> file_name;
                
    // opens the desired text file according to user's input
    astream.open(file_name);

    // checks if astream opened an actual file, maybe misspelling file name
    if(astream.is_open()){
    //to place all of the original text to the linked list
        while(std::getline(astream,word)){
			std::cout << word << std::endl;
			if(isalpha(word[0])){
				for(int i = 0; i < word.size(); i++){
					t.find(word[i]);
					std::cout << " ";
					if (word[i] == ' '){	//if there is a space in the 
						std::cout << " "; //sentence, make a double space for morse code
					}
				}
				std::cout << std::endl;
			}
			else{
				std::string w, res;
				for(int i = 0; i < word.size(); i++){
					if(word[i] == ' '){	// a double space means a new word
						res+=b.readM(w);
						w="";
					}
					w += word[i];
				}
				std::cout << res;	
			}
			std::cout << std::endl;
          // extracts the words from the text file and puts them in the vector
       }
         // closes the desired text file
        //std::cout<<"closed";
        t.clearTable();
        astream.close();
        
     }
                // ends program if no file was opened
      else{
           std::cout << "There exists no file: " << file_name << std::endl;
           return;
      }
}
