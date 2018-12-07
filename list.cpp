//Luis Valdivia
//December 4, 2018
//list.cpp

#include "list.h"
#include "itemtype.h"
#include "word.h"
#include <string>
#include <cassert>
#include <iostream>
#include <cstdlib>

using namespace std;


list::list(){
	head_f = NULL;
	tail_f = NULL;
}

void list::append_File(string* fname){  
    File* new_file = new File(*fname, 1);
    node* new_node = new node(new_file, NULL, NULL);
    if(head_f == NULL && tail_f == NULL){
        tail_f = head_f = new_node;
        return;
    }
    tail_f -> set_next(new_node);
    new_node -> set_prev(tail_f);
    tail_f = new_node;  
    return;
}

void list::appendFile(string* fname){	
	node* temp = head_f;
	while(temp){
		if(temp -> data() -> fileName() == *fname){
			temp -> data() -> incrCount();
            head_f = mergeSortFile(head_f);
            temp = head_f;
            while(temp -> next()){
                temp = temp -> next();
            }
            tail_f = temp;
			return;
		}
        temp = temp -> next();
	}
	File* new_file = new File(*fname, 1);
	node* new_node = new node(new_file, NULL, NULL);
	if(head_f == NULL){
		tail_f = new_node;
        head_f = new_node;
	}
    else if(head_f -> data() -> count() >= new_node -> data() -> count()){
        new_node -> set_next(head_f); 
        new_node -> next() -> set_prev(new_node); 
        head_f = new_node;
    }
    else{
        temp = head_f;
        while (temp -> next() && temp -> next() -> data() -> count() < new_node -> data() -> count()) 
            temp = temp -> next();
        new_node -> set_next(temp -> next());
        if (temp -> next()) 
            new_node -> next() -> set_prev(new_node); 
        else{
            tail_f = new_node;
        }
        temp -> set_next(new_node); 
        new_node -> set_prev(temp);
    }
	return;
}


// Function to merge DLL 
node* list::mergeFile(node* first, node* second){ 
    // If first linked list is empty 
    if (!first) 
        return second; 
  
    // If second linked list is empty 
    if (!second) 
        return first; 
  
    // Pick the smaller value 
    if ((first -> data() -> count()) < (second -> data() -> count())){ 
        first -> set_next(mergeFile(first -> next(),second)); 
        first -> next() -> set_prev(first); 
        first -> set_prev(NULL); 
        return first; 
    } 
    else{ 
        second -> set_next(mergeFile(first,second -> next())); 
        second -> next() -> set_prev(second); 
        second -> set_prev(NULL); 
        return second; 
    } 
} 

// Split a DLL into 2 DLLs of half sizes 
node* list::splitFile(node* head){ 
    node* fast = head;
    node* slow = head; 
    while (fast -> next() && fast -> next() -> next()){ 
        fast = fast -> next() -> next(); 
        slow = slow -> next(); 
    } 
    node* temp = slow -> next(); 
    slow -> set_next(NULL); 
    return temp; 
} 

// Function to do merge sort,
// afterwards, set head_f equal to this
node* list::mergeSortFile(node* head){ 
    if (!head || !head -> next()) 
        return head; 
    node* second = splitFile(head); 
  
    // Recur for left and right halves 
    head = mergeSortFile(head); 
    second = mergeSortFile(second); 
  
    // Merge the two sorted halves 
    return mergeFile(head, second); 
} 

list::~list(){
	node* temp;
	while(head_f != NULL){
		temp = head_f;
		head_f = head_f->next();
		temp->set_data(NULL);
		temp->set_next(NULL);
		delete temp;
	}
	tail_f = NULL;
}

void print_list(node* head){
    node* current = head;
    while(current){
        cout << current -> data() -> fileName() << endl;
        current = current -> next();
    }
    return;
}

bool not_in_list(string filename, node* head){
    node* current = head;
    while(current){
        if (current -> data() -> fileName() == filename){
            return false;
        }
        current = current -> next();
    }
    return true;
}

