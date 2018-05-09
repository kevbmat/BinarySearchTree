//
//  main.cpp
//  BinarySearchTreeProject
//
//  Created by Kevin Mattappally on 3/19/18.
//  Copyright © 2018 Kevin Mattappally. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "BinarySearchTree.h"

using namespace std;

// Open the file to be read from in the main program
// pre: infile is not open to a file
// post: infile can be used to read from a file
// usage: openInputFile(infile);
void openInputFile(ifstream& infile);

// Open the file to be written in from in the main program
// pre: outfile is not open to a file
// post: outfile can be used to read from a file
// usage: openOutputFile(output);
void openOutputFile(ofstream& outfile);

// Makes the inital dictionary
// pre: infile has been opened for reading and
// mytree is an empty binary search tree
// usage: makeInitialTree(infile, mytree);
void makeInitialTree(ifstream& infile, BinarySearchTree& mytree);

// prints out the menu for the user to select from
// post: the entire menu of options for the users is printed
// usage: printMenu();
void printMenu();

// gets the option for the menu that the user wants
// pre: user has to input a letter from the menu
// post: user's letter choice is returned
// usage: getOption();
char getOption();

// does the option that the user wants out of the program
// pre: letterChoice has the user's letter and a choice is to be made
// post: the letterChoice is used to make the proper choice
// usage: doOption(letterChoice, mytree, outfile, infile)
void doOption(char letterChoice, BinarySearchTree& mytree, ofstream& outfile, ifstream& infile);

// checks whether the user wants to exit the program with e
// pre: letterChoice is passed in
// post: if the letterChoice is e, then the program exits
// usage: isNotExit(letterChoice)
bool isNotExit(char letterChoice);

// prints out the exception message
// pre: except is assigned to an exception
// post: an exception notice is printed out
// usage: PrintExceptionMessage(except);
void PrintExceptionMessage(const Exception& except);

// searches for a phone number in the dictionary
// pre: mytree exists, a targetNumber is a phone number to search
// post: the found item is assigned to anItem, otherwise an exception is thrown
// usage: findName(mytree, targetNumber, anItem);
void findName(BinarySearchTree& mytree, Key targetNumber, Item anItem);

// inserts an item into the dictionary
// pre: mytree exists, anItem is assigned to an item waiting to be inserted
// post: the found item is assigned to anItem, otherwise an exception is thrown
// usage: insertItem(mytree, anItem);
void insertItem(BinarySearchTree& mytree, Item anItem);

// lists out the current items in the dictionary onto the file
// pre: mytree exists, outfile is empty
// post: outfile contains the items in the tree
// usage: listItems(mytree, outfile)
void listItems(BinarySearchTree& mytree, ostream& outfile);

// prints out the tree in a pretty fashion
// pre: mytree exists
// post: the tree is printed out to the console
// usage: printTree(mytree);
void printTree(BinarySearchTree& mytree);

// rebalances the tree by saving it and then making it more optimal for searching
// pre: mytree exists, infile and outfile are to be opened for reading and outputing
// post: mytree is now optimized, and the outfile contains the items in order
// usage: rebalanceTree(mytree, infile, outfile);
void rebalanceTree(BinarySearchTree& mytree, ifstream& infile, ofstream& outfile);

// saves the dictionary to a file
// pre: mytree exists and outfile is to be opened
// post: mytree's contents is listed out in the outfile
// usage: saveDictionary(mytree, outfile);
void saveDictionary(BinarySearchTree& mytree, ofstream& outfile);

int main()
{
    char letter = '\0';
    ifstream infile;
    ofstream outfile;
    BinarySearchTree mytree;
    
    openInputFile(infile);
    makeInitialTree(infile, mytree);
    while (isNotExit(letter))
    {
        printMenu();
        letter = getOption();
        doOption(letter, mytree, outfile, infile);
    }
    saveDictionary(mytree, outfile);
}

// Open the file to be read from in the main program
// pre: infile is not open to a file
// post: infile can be used to read from a file
// usage: openInputFile(infile);
void openInputFile(ifstream& infile)
{
    infile.open("Dictionary.dat");
    if(infile.fail())
    {
        cout << "Sorry there was an error in opening the input Dicionary file";
        exit(1);
    }
}

// Open the file to be written in from in the main program
// pre: outfile is not open to a file
// post: outfile can be used to read from a file
// usage: openOutputFile(output);
void openOutputFile(ofstream& outfile)
{
    outfile.open("Dictionary.dat");
    if(outfile.fail())
    {
        cout << "Sorry there was an error in opening the output Dicionary file";
        exit(1);
    }
}

// Makes the inital dictionary
// pre: infile has been opened for reading and
// mytree is an empty binary search tree
// usage: makeInitialTree(infile, mytree);
void makeInitialTree(ifstream& infile, BinarySearchTree& mytree)
{
    char newLine;
    Item newItem;
    int numberOfItems;
    infile >> numberOfItems;
    infile.get(newLine);
    for (int i = 0; i < numberOfItems; i++)
    {
        infile >> newItem;
        mytree.insert(newItem);
    }
    infile.close();
}

// prints out the menu for the user to select from
// post: the entire menu of options for the users is printed
// usage: printMenu();
void printMenu()
{
    cout << "\nf  : find the name of the contact, given her/his phone number" << endl;
    cout << "i  : insert a new item (phone number and name ) into the dictionary" << endl;
    cout << "l  : list the items in the entire dictionary on the screen in inorder fashion" << endl;
    cout << "p  : print the tree in pretty fashion (showing only the phone numbers)" << endl;
    cout << "r  : rebalance the tree" << endl;
    cout << "s  : save the dictionary to the file in sorted order – inorder --  ready to be read" << endl;
    cout << "e  : exit the program which automatically does option s" << endl;
}

// gets the option for the menu that the user wants
// pre: user has to input a letter from the menu
// post: user's letter choice is returned
// usage: getOption();
char getOption()
{
    char letterChoice, newLine;
    cout << "\nEnter your option > ";
    cin.get(letterChoice);
    cin.get(newLine);
    return letterChoice;
}

// does the option that the user wants out of the program
// pre: letterChoice has the user's letter and a choice is to be made
// post: the letterChoice is used to make the proper choice
// usage: doOption(letterChoice, mytree, outfile, infile)
void doOption(char letterChoice, BinarySearchTree& mytree, ofstream& outfile, ifstream& infile)
{
    Key targetNumber;
    Item anItem;
    switch(letterChoice)
    {
        case 'f' :
            findName(mytree, targetNumber, anItem);
            break;
        case 'i' :
            insertItem(mytree, anItem);
            break;
        case 'l' :
            listItems(mytree, cout);
            break;
        case 'p' :
            printTree(mytree);
            break;
        case 'r' :
            rebalanceTree(mytree, infile, outfile);
            break;
        case 's' :
            saveDictionary(mytree, outfile);
            break;
        default :;
    }
}

// checks whether the user wants to exit the program with e
// pre: letterChoice is passed in
// post: if the letterChoice is e, then the program exits
// usage: isNotExit(letterChoice)
bool isNotExit(char letterChoice)
{
    return letterChoice != 'e';
}

// prints out the exception message
// pre: except is assigned to an exception
// post: an exception notice is printed out
// usage: PrintExceptionMessage(except);
void PrintExceptionMessage(const Exception& except)
{
    cout << endl << endl;
    cout << except.What();
    cout << endl << endl;
}

// searches for a phone number in the dictionary
// pre: mytree exists, a targetNumber is a phone number to search
// post: the found item is assigned to anItem, otherwise an exception is thrown
// usage: findName(mytree, targetNumber, anItem);
void findName(BinarySearchTree& mytree, Key targetNumber, Item anItem)
{
    cout << "Enter a phone number > ";
    cin >> targetNumber;
    try
    {
        mytree.search(targetNumber, anItem);
        cout << anItem;
    }
    catch (Exception except)
    {
        PrintExceptionMessage(except);
    }
}

// inserts an item into the dictionary
// pre: mytree exists, anItem is assigned to an item waiting to be inserted
// post: the found item is assigned to anItem, otherwise an exception is thrown
// usage: insertItem(mytree, anItem);
void insertItem(BinarySearchTree& mytree, Item anItem)
{
    cout << "Enter a phone number and name to insert into the dictionary > ";
    cin >> anItem;
    try
    {
        mytree.insert(anItem);
    }
    catch (Exception except)
    {
        PrintExceptionMessage(except);
    }
}

// lists out the current items in the dictionary onto the file
// pre: mytree exists, outfile is empty
// post: outfile contains the items in the tree
// usage: listItems(mytree, outfile)
void listItems(BinarySearchTree& mytree, ostream& outfile)
{
    mytree.BinaryTree::inorderTraverse(outfile);
}

// prints out the tree in a pretty fashion
// pre: mytree exists
// post: the tree is printed out to the console
// usage: printTree(mytree);
void printTree(BinarySearchTree& mytree)
{
    mytree.BinarySearchTree::prettyDisplay();
}

// rebalances the tree by saving it and then making it more optimal for searching
// pre: mytree exists, infile and outfile are to be opened for reading and outputing
// post: mytree is now optimized, and the outfile contains the items in order
// usage: rebalanceTree(mytree, infile, outfile);
void rebalanceTree(BinarySearchTree& mytree, ifstream& infile, ofstream& outfile)
{
    saveDictionary(mytree, outfile);
    mytree.rebalanceTree(outfile);
    infile.close();
}

// saves the dictionary to a file
// pre: mytree exists and outfile is to be opened
// post: mytree's contents is listed out in the outfile
// usage: saveDictionary(mytree, outfile);
void saveDictionary(BinarySearchTree& mytree, ofstream& outfile)
{
    openOutputFile(outfile);
    mytree.inorderTraverse(outfile);
    outfile.close();
}


