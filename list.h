#ifndef LIST_H
#define LIST_H
#include "itemtype.h"
#include <string>
#include <cassert>
#include <cstdlib>
#include <iostream>

using namespace std;

struct NodeList
{
public:

    NodeList(File* d, NodeList* l=NULL, NodeList* p=NULL)
    {
        data_f = d;
        next_f = l;
        prev_f = p;
    }

    //modifiers

    void set_data(File* d) {data_f = d;}
    void set_next(NodeList* l) {next_f = l;}
    void set_prev(NodeList* p) {prev_f = p;}

    // observers
    File* data() const {return data_f;}

    // forward links
    NodeList* next() {return next_f;}
    const NodeList* next() const {return next_f;}

    // backward links
    NodeList* prev() {return prev_f;}
    const NodeList* prev() const {return prev_f;}

private:
    File* data_f;
    // forward pointer
    NodeList* next_f;
    // backward pointer
    NodeList* prev_f;
};

class list
{
public:
    list();
    void appendFile(const string &fname);
    NodeList* head(){return head_f;}
    NodeList* tail(){return tail_f;}
    ~list();
private:
    NodeList* head_f;
    NodeList* tail_f;
};
#endif

