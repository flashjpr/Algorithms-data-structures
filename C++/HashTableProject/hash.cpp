//
//  hash.cpp
//  HashTableProject
//
//  Created by Mihai Alexandru Ionut Fleseriu on 19/01/2016.
//  Copyright © 2016 Mihai Alexandru Ionut Fleseriu. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>

#include "hash.h"

using namespace std;

//Define the constructor
hashType::hashType(){
    
    for(int i = 0; i < tableSize; i++){
        HashTable[i] = new item;
        HashTable[i] -> name = "empty";
        HashTable[i] -> drink = "empty";
        HashTable[i] -> next = NULL;
    }
}

void hashType::AddItem(string name, string drink){
    
    //figures the index for a new person
    int index = Hashing(name);
    
    //check if it's default information, if so override
    if(HashTable[index] -> name == "empty"){
        HashTable[index] -> name = name;
        HashTable[index] -> drink = drink;
    }else{
        //otherwise do not override, but link to the current index a new item
        item* pointer = HashTable[index]; //point to the begining of that index
        item* n = new item;
        
        n -> name = name;
        n -> drink = drink;
        n -> next = NULL;
        
        while (pointer-> next != NULL) {
            pointer = pointer -> next;
        }
        
        //link the last item to the newly created item
        pointer -> next = n;
    }
}

int hashType::NumberOfItemsInIndex(int index){
    int count = 0;
    
    if (HashTable[index] -> name == "empty") {
        return count;
    }else{
        count++;
        item* pointer = HashTable[index];
        while (pointer -> next != NULL) {
            count++;
            pointer = pointer -> next;
        }
    }
    return count;
}

void hashType::PrintTable(){
    //number of elements in each index
    int number;
    
    for (int i = 0; i< tableSize; i++) {
        number = NumberOfItemsInIndex(i);
        cout << "____________________\n";
        cout << "index = " << i << endl;
        cout << HashTable[i] -> name << endl;
        cout << HashTable[i] -> drink << endl;
        cout << "# of items = " << number << endl;
        cout << "____________________\n";
    }
}

void hashType::PrintItemsInIndex(int index){
    //point to the first item in index
    item* pointer = HashTable[index];
    
    if(pointer -> name == "empty") cout<< "The bucket #"<< index <<" is empty.";
    else{
        cout << "The bucket "<< index <<" has the items:\n ";
        
        while (pointer != NULL) {
            cout << "____________________\n";
            cout << pointer -> name << endl;
            cout << pointer -> drink << endl;
            cout << "____________________\n";
            
            pointer = pointer -> next;
        }
    }
}

int hashType::Hashing(string key)
{
    int hash = 0, index;
    
    //for each character of key, transform it to an integer and save in var hash
    for(int i = 0; i< key.length();i++){
        //tried some different ways of computing the hash function
        hash = (hash + (int)key[i]) * 17;
    }

    //deal with out of table size keys
    index = hash % tableSize;
    
    
    return index;
}

void hashType::SearchDrink(string name){
    //name is the key; pass the key and search its bucket
    int bucket = Hashing(name);
    
    bool foundName = false;
    string drink;
    
    item* pointer = HashTable[bucket];
    
    //as long as we point to something
    while (pointer != NULL) {
        if(pointer -> name == name){
            foundName = true;
            drink = pointer -> drink;
        }
        //keep moving the pointer forward untill go through all the list
        pointer = pointer -> next;
    }//while
    
    if (foundName == true)
        cout << "Favourite drink = " << drink << endl;
    else
        cout << name << " 's information was not found in the HashTable" << endl;
}

void hashType::RemoveItem(string name){
    //hash value of the name passing in the remove item function
    int bucket = Hashing(name);
    
    
    item* deletePointer;
    item* pointer1;//
    item* pointer2;//
    
    //Case 0: bucket is empty
    if (HashTable[bucket] -> name == "empty" && HashTable[bucket] -> drink == "empty") {
        cout << name << " was not found in the HashTable\n";
    }
    
    
    //Case 1: only 1 item contained in bucket
    //      : that item has matching name
    else if (HashTable[bucket] -> name == name && HashTable[bucket] -> next == NULL){
        
        //make it default value | same as deleting but we don t want to delete it here
        HashTable[bucket] -> name = "empty";
        HashTable[bucket] -> drink = "empty";
        
        cout << name << " was removed from the HashTable";
    }
    
    
    //Case 2: match in the first item(in bucket) but there are additional items in the bucket
    else if(HashTable[bucket] -> name == name){
        //point to the very first item
        deletePointer = HashTable[bucket];
        
        //point to the new item in the list
        HashTable[bucket] = HashTable[bucket]-> next;
        
        delete deletePointer;
        
        cout << name << " was removed from the HashTable";
    }
    
    //Case 3: bucket is not empty, but first item is not a match
    
    else {
        //"pointer1" is always 1 step ahead of "pointer2"
        //make p2 trail 1 item behind p1
        //stop when we find a match or reach the end
        pointer1 = HashTable[bucket] -> next;
        pointer2 = HashTable[bucket];
        
        while (pointer1 != NULL && pointer1 -> name != name) {
            //advance p1 and p2
            pointer2 = pointer1;
            pointer1 = pointer1 -> next;
        }
        //  Case 3.1: no match found
        if(pointer1 == NULL)    cout << name << " was not found in the HashTable\n";

        //  Case 3.2: found a match
        else{
            
            deletePointer = pointer1;
            pointer1 = pointer1 -> next;
            pointer2 -> next = pointer1;
            
            delete deletePointer;
            cout << name << " was removed from the HashTable";
        }//else
    }
}










