//Qi Guo Project2
#include "list.h"
#include <iostream>
using namespace std;

//Constructor
list::list(){
    head = NULL;
}

//Destructor
list::~list(){
    ldnode *n = head;
    while(n){
        ldnode *garbage = n;
        n = n -> next;
        delete garbage;
    }
}

void list::add(const string& f){
    if(head == NULL){ //the list is empty
        head = new ldnode;
        (head -> file).set_filename(f);
        (head -> file).inc_count();
    }
    else{ //already a list for that word
        ldnode *n = head;
        while(n -> next){ //check not the last node
            if((n -> file).filename() == f){ //check have that fname
               (n -> file).inc_count();
               //Order
               ldnode *h = head;
               //count greater than the head
        /*       if((n -> file).count() >= (h -> file).count()){
                   n -> next = h;
                   h -> prev = n;
          */         
               return;
            }
            n = n -> next;
        }
        if((n -> file).filename() == f){ //check last node
            (n -> file).inc_count();
            return;
        }
        //does not have that fnmae
        ldnode *temp = new ldnode;
        (temp -> file).set_filename(f);
        (temp -> file).inc_count();
        // insert to the right spot
        ldnode *h = head;
        temp -> prev = n;
        n -> next = temp;
        
    }
}

void list::printl(){
    ldnode* temp = head;
    while(temp){
        cout << (temp -> file).filename() << " and " << (temp -> file).count() << endl;
        temp = temp -> next;
    }
    
}
