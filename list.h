//Luis Valdivia
//December 4, 2018
//list.h

#ifndef LIST_H
#define LIST_H
#include "itemtype.h"
#include <string>
#include <cassert>
#include <cstdlib>
#include <iostream>

using namespace std;

struct node
{
public:

    node(File* d, node* l=NULL, node* p=NULL)
    {
        data_f = d;
        next_f = l;
        prev_f = p;
    }

    //modifiers

    void set_data(File* d) {data_f = d;}
    void set_next(node* l) {next_f = l;}
    void set_prev(node* p) {prev_f = p;}

    // observers
    File* data() const {return data_f;}

    // forward links
    node* next() {return next_f;}
    const node* next() const {return next_f;}

    // backward links
    node* prev() {return prev_f;}
    const node* prev() const {return prev_f;}

private:
    File* data_f;
    // forward pointer
    node* next_f;
    // backward pointer
    node* prev_f;
};

class list
{
public: 
    //constructors 
    list();

    //modifier 
    void append_File(string* fname);
    void appendFile(string* fname);
    
    //sorting functions
    static node* splitFile(node* head);
    static node* mergeFile(node* first, node* second);
    node* mergeSortFile(node* head);

    //observer
    node* head(){return head_f;}
    node* tail(){return tail_f;}

    //deconstructor 
    ~list();

private: 
	node* head_f;
	node* tail_f;
};

bool not_in_list(string filename, node* head);

void print_list(node* head);

#endif 