
#ifndef WORD_H
#define WORD_H
#include "itemtype.h"
#include "list.h"
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>



class Word
{
public:
	Word();
	Word(const string word);
	string get_word();
	list* get_files();
	void insert(const string word, string* fname);
private:
	string word;
	list* data;
};
struct NodeWord
{
public:
	NodeWord(const Word& d, NodeWord* l=NULL, NodeWord* p=NULL)
    {
        data_f = d;
        next_f = l;
        prev_f = p;
    }

    //modifiers

    void set_data(const Word& d) {data_f = d;}
    void set_next(NodeWord* l) {next_f = l;}
    void set_prev(NodeWord* p) {prev_f = p;}

    // observers
    Word data() const {return data_f;}

    // forward links
    NodeWord* next() {return next_f;}
    const NodeWord* next() const {return next_f;}

    // backward links
    NodeWord* prev() {return prev_f;}
    const NodeWord* prev() const {return prev_f;}

private:
    Word data_f;
    // forward pointer
    NodeWord* next_f;
    // backward pointer
    NodeWord* prev_f;
};

class wordLink
{
public:
	wordLink();
	void appendWord(const Word* data_f);
	NodeWord* head(){return head_f;}
	NodeWord* tail(){return tail_f;}
private:
	NodeWord* head_f;
	NodeWord* tail_f;
};

#endif
