//Kelly Wang 5351010
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "itemtype.h"
#include "list.h"
#include "word.h"
#include "wordsearchunion.h"

using namespace std;

/*function... might want it in some class?*/
int wordsearch::getdir (string dir, vector<string> &files)
{
  DIR *dp;
  struct dirent *dirp;
  if((dp  = opendir(dir.c_str())) == NULL) {
    cout << "Error(" << errno << ") opening " << dir << endl;
    return errno;
  }

  while ((dirp = readdir(dp)) != NULL) {
    files.push_back(string(dirp->d_name));
  }
  closedir(dp);
  return 0;
}


int main(int argc, char* argv[])
{
  string dir; //
  vector<string> files = vector<string>();

  if (argc < 2)
    {
      cout << "No Directory specified; Exiting ..." << endl;
      return(-1);
    }
  dir = string(argv[1]);
  if (wordsearch::getdir(dir,files)!=0)
    {
      cout << "Error opening " << dir << "; Exiting ..." << endl;
      return(-2);
    }

  wordLink* wordList = new wordLink();
  // reading into the files v/putting it in the array 
  string slash("/");
  for (unsigned int i = 0;i < files.size();i++) {
    if(files[i][0]=='.')continue;
 //skip hidden files
    ifstream fin((string(argv[1])+slash+files[i]).c_str()); //open using absolute path
    // ...read the file...
    string word;
    while(true){
      fin >> word;
      if(fin.eof()){//cout << "EOF " << files[i] << endl; 
        break;
      }
      else {
        //cout << word;
        NodeWord* cursor = wordList->head();
        //cout<<"5"<<endl;
        while(cursor){
          if(cursor->data().get_word() == word){
            //cout<<"6"<<endl;
            cursor->data().get_files()->appendFile(&files[i]);
            //cout<<"7"<<endl;
            break;
          }
          cursor = cursor->next();
        }
        
        if(cursor == NULL){
          Word* addWord = new Word(word);
          addWord->get_files()->appendFile(&files[i]);
          wordList->appendWord(addWord);
        }
  // Now the string "word" holds the keyword, and the string "files[i]" holds the document name.
  // Use these two strings to search/insert in your array/list of words.
      }
    }
    fin.close();
  }

    //handeling getting the actual files ^
    string inputWord1;
    string inputWord2;
    int count = 0;

    cout << "Enter two words to find union or 'exit' to quit." << endl;
    cin >> inputWord1;
    cin >> inputWord2;
    if(inputWord1 == "exit"){
      return 0;
    }

    NodeWord* wordCursor = wordList->head();
    while(wordCursor != NULL){
      if(wordCursor->data().get_word() == inputWord1 || wordCursor->data().get_word() == inputWord2){
        node* getFileList = wordCursor->data().get_files()->head();
        while(getFileList!=NULL){
          count++;
          cout<<"File: "<<getFileList->data()->fileName()<<endl; 
          getFileList = getFileList ->next();
        }
      }
      wordCursor = wordCursor->next();
    }
    if(count == 0)
      cout<<"Word: "<<inputWord1<<" and "<< inputWord2 <<" does not have union" <<endl;
    return 0;
}



