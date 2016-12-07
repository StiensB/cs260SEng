/**
* Suppose you had two files and wanted to know if parts of one were contained in another.
* Maybe you have a file holding some email messages and you have another email message and would like to
* know if that email is similar to one you've seen before. In addition, maybe somebody is keeping those
* messages private because information is classified... so you'd like to be able to compare the files, possibly
* without seeing the original to which you are comparing. This same technique can be used to determine plagiarism.
*
*
* @bray stiens
**/

#ifndef HASHING_H
#define HASHING_H
#include "hashtab.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class hashing
{
	private:
    string jstring;

	public:
    //constructor
    hashing();
    //returns the vector of values
    hashval_t hashFunction(string jstring);

};
#endif
