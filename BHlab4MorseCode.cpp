/* Bryan Hui 11-19-2021
CS124Fall2021 - Lab4MorseCode
This program will translate Morse Code into its alphabetic equavalent and from the alphabet to Morse 
Code in the given text file.
*/
#include <iostream>
#include <fstream>
#include <string>
#include "function.h"
#include "hashTable.h"
#include "binaryTree.h"

int main(){
    int userInput;
    do{
        intro();
        std::cin >> userInput;
        switch(userInput){
            case 1:{
                HashTable t;
                binaryTree b;
                makeTableTree(t, b);
                readAlphaMorse(t, b);
                break;
            }
            //input 2, exit program
            case 2:
                std::cout << "Exiting Program." << std::endl;
                return 0;
                break;
			
			//if entered a value other than 1 or 2
            default:
                std::cout << "You have entered an invalid response. Please try again." << std::endl;
                break;
        }
	
	// condition to exit the program, otherwise repeat
    }while(userInput != 2);
}
