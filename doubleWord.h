#ifndef __DOUBLEWORD_H__
#define __DOUBLEWORD_H__
#include "textprocess.h"
#include "decorator.h"
#include <iostream>
#include <string>


class doubleWord : public decorator{
  private:
    std::string buffer;
    bool bufferFilled;
  public:
    doubleWord(TextProcessor* component);
    std::string getWord() override;
};

#endif

