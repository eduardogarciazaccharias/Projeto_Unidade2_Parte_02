#ifndef PUTELIPSOIDE_H
#define PUTELIPSOIDE_H
#include "figurageometrica.h"
#include "sculptor.h"

class PutElipsoide : public Figurageometrica{
    int xcenter, ycenter, zcenter, rx, ry, rz;
public:
    PutElipsoide(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz, float r, float g, float b, float a);
    ~PutElipsoide(){}
    void draw(Sculptor &s);
};
#endif // PUTELIPSOIDE_H
