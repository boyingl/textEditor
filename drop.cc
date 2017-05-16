#include "textprocess.h"
#include "decorator.h"
#include "drop.h"
#include <iostream>
#include <string>
using namespace std;

drop::drop(TextProcessor* component, int dropn):decorator{component}, dropn{dropn}{}

string drop::getWord(){
  string word = component->getWord();
  int len = word.length();
  if(dropn >= len) return "";
  word = word.substr(dropn);
  return word;
}

