#ifndef __COUNT_H__
#define __COUNT_H__
#include "textprocess.h"
#include "decorator.h"
#include <iostream>
#include <string>

class count : public decorator{
    char theChar;
    unsigned int counter;

  public:
    count(TextProcessor* component, char c);
    std::string getWord() override;
};

#endif

