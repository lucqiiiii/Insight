#include "word.h"
#include "list.h"
#include "itemtype.h"
#include <iostream>
#include <string>

using namespace std;
Word::Word(){
	word = "";
	data = new list();
}

Word::Word(const string word){
	this->word = word;
	data = new list();
}

string Word::get_word(){
	return word;
}

list* Word::get_files(){
	return data;
}

void Word::insert(const string word, const string fname){
	this->word = word;
	data->appendFile(fname);
}

wordLink::wordLink(){
	head_f = NULL;
	tail_f = NULL;
}

void wordLink::appendWord(const Word* data_f){
	NodeWord* temp = head_f;
	NodeWord* wordNode = new NodeWord(*data_f, NULL, NULL);

	if(head_f == NULL && tail_f == NULL){
		head_f = tail_f = wordNode;
		return;
	}
	//head insert
	if(wordNode->data().get_word() < temp->data().get_word()){
		wordNode->set_next(temp);
		temp->set_prev(wordNode);
		head_f = wordNode;
		return;
	}
	//cout<<"WE R IN WORD"<<endl;
	while(temp->data().get_word() < wordNode->data().get_word() && temp->next() !=NULL){
		temp = temp->next();
	}
	if(temp->next() != NULL){
		//inserting somewhere in the linkedlist
		temp->prev()->set_next(wordNode);
		wordNode->set_next(temp);
		wordNode->set_prev(temp->prev());
		temp->set_prev(wordNode);
	}else if(temp->next()==NULL && temp->data().get_word() > wordNode->data().get_word()){
		temp->set_prev(wordNode);
		temp->prev()->set_next(wordNode);
		wordNode->set_next(temp);
		wordNode->set_prev(temp->prev());
	}else if(temp->next() == NULL && temp->data().get_word()<wordNode->data().get_word()){
		temp->set_next(wordNode);
		wordNode->set_prev(temp);
		tail_f = wordNode;
	}

}


