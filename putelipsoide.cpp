#include "putelipsoide.h"
#include <math.h>

PutElipsoide::PutElipsoide(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz, float r, float g, float b, float a){
    this->xcenter=xcenter; this->ycenter=ycenter; this->zcenter=zcenter;
    this->rx=rx; this->ry=ry; this->rz=rz; this->r=r; this->g=g; this->b=b; this->a=a;
}
void PutElipsoide::draw(Sculptor &s){

    for(int i = xcenter-rx; i < xcenter+rx; i++){
        for(int j = ycenter-ry; j < ycenter+ry; j++){
            for(int k = zcenter-rz; k < zcenter+rz; k++){
                if(xcenter < 0 || xcenter > i || ycenter < 0 || ycenter > j || zcenter < 0 || zcenter > k)
                {

                }else if((pow(i - xcenter,2)/pow(rx,2) + pow(j - ycenter,2)/pow(ry,2) + pow(k - zcenter,2)/pow(rz,2))<= 1)
                {
                    s.putVoxel(i, j, k);

                }
            }
        }
    }
}
