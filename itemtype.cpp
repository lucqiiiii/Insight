//Kelly Wang 5351010
#include <iostream>
#include <string>
#include "itemtype.h"

using namespace std;

//implement the constructor
File::File(const string& fname, const int& num){
    file_name=fname; 
    wordOccur=num;
}
    
// implement modifiers
void File::incrCount(){
    wordOccur++;
}

void File::set_fname(string fname){
	file_name = fname;
}

// implement observers
string File::fileName() const{
	return file_name;
} 

int File:: count() const{
	return wordOccur;
}
