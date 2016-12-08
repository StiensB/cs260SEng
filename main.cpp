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

#include "hashtab.h"
#include "hashing.h"

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <cstddef>

using namespace std;

int main(int argc, char* argv[])
{
  string filename = argv[0];
  string filename2 = argv[1];

  //objects
  hashing theHashing;
  hashing theSecond;
  //maps of objects
  map<hashval_t, int> firstMap = theHashing.getMap();
  map<hashval_t, int> secondMap = theSecond.getMap();

  theHashing.readLines(filename);
  theSecond.readLines(filename2);

    for (map<hashval_t,int>::iterator it=firstMap.begin(); it!=firstMap.end(); ++it)
    {
      for (map<hashval_t,int>::iterator it2=secondMap.begin(); it2!=secondMap.end(); ++it)
      {
        if(it->first == it2 -> first)
        {
          cout<<"Similar Elements Found At" << it->second;
        }
      }
    }


  return 0;
};
