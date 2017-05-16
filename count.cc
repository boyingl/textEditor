#include "textprocess.h"
#include "decorator.h"
#include <iostream>
#include <string>
#include <sstream>
#include "count.h"
using namespace std;

count::count(TextProcessor* component, char theChar):decorator{component}, theChar{theChar}, counter{1}{}

string count::getWord(){
  string word = component->getWord();

  for(unsigned int i = 0; i < word.size(); i ++) {
    if (word[i] == theChar) {
      ostringstream countStream;
      countStream << counter;
      string countString = countStream.str();
      word = word.substr(0, i) + countString + word.substr(i+1);
      i = i + countString.size() -1;
      counter ++; 
    }  
  }
  return word;
}

