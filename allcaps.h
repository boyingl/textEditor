#ifndef __CAP_H__
#define __CAP_H__
#include "textprocess.h"
#include "decorator.h"
#include <iostream>
#include <string>


class cap : public decorator{
    const int difference = 32;
    const int lowA = 97;
    const int lowZ = 122; 

  public:
    cap(TextProcessor* component);
    std::string getWord() override;
};

#endif

