#ifndef CUTELIPSOIDE_H
#define CUTELIPSOIDE_H
#include "figurageometrica.h"
#include "sculptor.h"

class CutElipsoide : public Figurageometrica{
     int xcenter, ycenter, zcenter, rx, ry, rz;
public:
     CutElipsoide(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
     ~CutElipsoide(){};
     void draw(Sculptor &s);
};
#endif // CUTELIPSOIDE_H
