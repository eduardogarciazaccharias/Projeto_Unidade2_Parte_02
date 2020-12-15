#ifndef CUTSPHERE_H
#define CUTSPHERE_H
#include "figurageometrica.h"
#include "sculptor.h"
class CutSphere : public Figurageometrica{
    int xcenter, ycenter, zcenter, radius;
public:
    CutSphere(int xcenter, int ycenter, int zcenter, int radius);
    ~CutSphere(){};
    void draw(Sculptor &s);
};
#endif // CUTSPHERE_H
