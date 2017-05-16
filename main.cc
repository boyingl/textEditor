#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "textprocess.h"
#include "echo.h"
#include "decorator.h"
#include "allcaps.h"
#include "count.h"
#include "doubleWord.h"
#include "drop.h"

using namespace std;


int main () {
  cin.exceptions(ios::failbit|ios::eofbit);
  string s;

  try {
    while(1) {
      getline(cin,s);
      istringstream iss{s};
      iss.exceptions(ios::failbit);
      string fname;
      iss >> fname;
      istream *in = (fname == "stdin") ? &cin : new ifstream(fname.c_str());
      in->exceptions(ios::failbit|ios::eofbit);
  
      TextProcessor *tp = new Echo;
      string dec;
      try {
        while (true) {
          iss >> dec;
          if (dec == "dropfirst") {
            int n;
            iss >> n;
            tp = new drop(tp, n);
          }
          else if (dec == "doublewords") {
            tp = new doubleWord(tp);
          }
          else if (dec == "allcaps") {
            tp = new cap(tp);
          }
          else if (dec == "count") {
            char c;
            iss >> c;
            tp = new count(tp, c);
          }
       } 
      }
      catch (ios::failure) {}

      tp->setSource(in);

      string word;

      try {
        int lineNum = 1;
        while (true) {
          word = tp->getWord();
          if(word.size()!= 0) cout << lineNum++ << ' ' << word << endl;
        }
      }
      catch (ios::failure) {}
  
      if (in != &cin) delete in;
      delete tp;
    }
  }
  catch (ios::failure) {}
}


