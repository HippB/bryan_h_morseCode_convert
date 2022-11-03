#ifndef FUNCTION_H
#define FUNCTION_H
#include <string>
#include <fstream>
#include "hashTable.h"
#include "binaryTree.h"

void intro();	//introduction

void makeTableTree(HashTable &t, binaryTree &b); //reads the inputted text file

void readAlphaMorse(HashTable &t, binaryTree &b); //reads the inputted text file

#endif
