/**
* Suppose you had two files and wanted to know if parts of one were contained in another.
* Maybe you have a file holding some email messages and you have another email message and would like to
* know if that email is similar to one you've seen before. In addition, maybe somebody is keeping those
* messages private because information is classified... so you'd like to be able to compare the files,
* possibly without seeing the original to which you are comparing.
* This same technique can be used to determine plagiarism.
*
*
* @bray stiens
**/

#include "hashing.h"
#include "hashtab.h"
#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <vector>
#include <cstddef>

using namespace std;

  hashing::hashing()
  {
    map<hashval_t,int> hashedValues;

  }

  void hashing::readLines(string filename)
  {
    //empty string to be filled with unhashed values
    string toBeAdded = "";
    //reads in file
    ifstream infile;
    infile.open(filename.c_str());

    //while stuff is in there
    while(infile.peek() && !infile.eof())
    {
      //string for each line to be added for hashing
      string temp;
      //line number
      int x = 1;
      x++;
      //reads in 3 lines then adds them to be hashed
      for (int n = 0; n <3; n++)
      {
        getline(infile,temp);
        toBeAdded += temp;
      }
      std::pair<hashval_t,int>paired;
      paired = make_pair(hashFunction(toBeAdded), x);
      hashedValues.insert(paired);
    }
  }

  hashval_t hashing::hashFunction(string toBeAdded)
  {


    hashval_t hashed;
    hashed = 0;
    //actual hashing
    for (int i = 0; i < toBeAdded.size(); i++)
    {
      hashed = hashed^magicbits[toBeAdded[i]][i];
    }

    return hashed;
  }

  map<hashval_t,int> hashing::getMap()
  {
    return hashedValues;
  }
