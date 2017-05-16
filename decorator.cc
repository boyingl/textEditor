#include "textprocess.h"
#include "decorator.h"
#include <iostream>
using namespace std;

decorator::decorator(TextProcessor* component):component{component}{}

void decorator::setSource(istream *in) { 
  component->setSource(in);
  source = in; 
}

decorator::~decorator(){
  if(component) delete component;
}

