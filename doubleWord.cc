#include "textprocess.h"
#include "decorator.h"
#include <iostream>
#include <string>
#include "doubleWord.h"
using namespace std;

doubleWord::doubleWord(TextProcessor* component):decorator{component}, bufferFilled{false}{}


string doubleWord::getWord(){
  string word;
  if(bufferFilled){
    word = buffer;
    bufferFilled = false;
  }
  else {
    word = component->getWord();
    buffer = word;
    bufferFilled = true;
  }

  return word;
}

