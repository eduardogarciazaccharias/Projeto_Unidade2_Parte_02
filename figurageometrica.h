#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H
#include "sculptor.h"
class Figurageometrica{
protected:
    float r,g,b,a;
public:
    virtual ~Figurageometrica(){};
    virtual void draw(Sculptor &s)=0;
};
#endif // FIGURAGEOMETRICA_H
