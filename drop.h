//dropfirst n
#ifndef __DROP_H__
#define __DROP_H__
#include "textprocess.h"
#include "decorator.h"
#include <iostream>
#include <string>

class drop : public decorator{
    int dropn;

  public:
    drop(TextProcessor* component, int dropn);
    std::string getWord() override;
};

#endif

