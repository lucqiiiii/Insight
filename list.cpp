#include "list.h"
#include "word.h"
#include "itemtype.h"
#include <cassert>
#include <cstdlib>
#include <iostream>

using namespace std;

list::list(){
	head_f = NULL;
	tail_f = NULL;
}
void list::appendFile(const string &fname){
	NodeList* temp = head_f;
	while(temp!=NULL){
		if(temp->data()->fileName() == fname){
			temp->data()->incrCount();
			return;
		}
		temp = temp->next();
		//cout<<"WE R IN LIST"<<endl;
	}
	File* file = new File(fname);
	NodeList* fileNode = new NodeList(file, NULL, NULL);
	if(head_f == NULL && tail_f == NULL){
		head_f=tail_f=fileNode;
	}

	temp = head_f;
	if(file->count() > temp->data()->count()){
		fileNode->set_next(temp);
		temp->set_prev(fileNode);
		head_f = fileNode;
	}
	while(temp->data()->count() < file->count() && temp->next() != NULL){
		temp = temp->next();
	}
	if(temp->next() != NULL){
		temp->set_prev(fileNode);
		temp->prev()->set_next(fileNode);
		fileNode->set_next(temp);
		fileNode->set_prev(temp->prev());
	}else if(temp->next() == NULL && temp->data()->count() > file->count()){
		temp->set_prev(fileNode);
		temp->prev()->set_next(fileNode);
		fileNode->set_next(temp);
		fileNode->set_prev(temp->prev());
	}else if(temp->next() == NULL && temp->data()->count() < file->count()){
		temp->set_next(fileNode);
		fileNode->set_prev(temp);
		tail_f = fileNode;
	}
	// NodeList* print = head_f;
	// cout<< "*******"<<endl;
	// while(print != NULL){
	// 	cout<< print->data()->fileName()<<endl;
	// 	cout<< print->data()->count()<<endl;
	// 	print = print->next();
	// }

}
list::~list(){
	NodeList* temp;
	while(head_f != NULL){
		temp = head_f;
		head_f = head_f->next();
		temp->set_data(new File());
		temp->set_next(NULL);
		delete temp;
	}
	tail_f = NULL;
}
