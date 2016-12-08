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
#include <map>

using namespace std;

class hashing
{
	private:
		map<hashval_t,int> hashedValues;

	public:
    //constructor
    hashing();
		//reads in the lines of a file
		void readLines(string filename);
    //returns the vector of values
    hashval_t hashFunction(string jstring);
		//accesor for the map
		map<hashval_t,int> getMap();
};
#endif
