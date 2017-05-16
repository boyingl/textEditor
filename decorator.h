#ifndef __DECORATOR_H__
#define __DECORATOR_H__
#include "textprocess.h"
#include <iostream>

class decorator : public TextProcessor{

  protected:
    TextProcessor* component;    
    std::istream *source;

  public:
    decorator(TextProcessor* component);
    void setSource(std::istream *inp) override;
    virtual ~decorator() = 0;
};
#endif


