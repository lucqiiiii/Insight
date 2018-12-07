//Kelly Wang 5351010
#ifndef ITEMTYPE_H
#define ITEMTYPE_H
#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

class File
{
public:
    // constructor
    File(const string& fname = "", const int& num = 0 );

    // modifier
    void incrCount(); // increase file count
    void set_fname(string fname);

    // observers
    string fileName() const; // return file_name

    int count() const; // return wordOcur

private:
    string file_name;
    int wordOccur; //word occurences
};

#endif
