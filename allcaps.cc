#include "textprocess.h"
#include "decorator.h"
#include <iostream>
#include <string>
#include "allcaps.h"
using namespace std;

cap::cap(TextProcessor* component):decorator{component}{}

string cap::getWord(){
  string word = component->getWord();
  for(auto &n : word){
    if (n>=lowA && n<=lowZ) n = n - difference;
  }
  return word;
}

