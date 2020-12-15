#include "cutsphere.h"
#include<math.h>

CutSphere::CutSphere(int xcenter, int ycenter, int zcenter, int radius){
    this->xcenter=xcenter; this->ycenter=ycenter; this->zcenter=zcenter; this->radius=radius;
 }
void CutSphere::draw(Sculptor &s){

    for(int i = xcenter-radius; i < xcenter+radius; i++){
        for(int j = ycenter-radius; j < ycenter+radius; j++){
            for(int k = zcenter-radius; k < zcenter+radius; k++){
                float d = sqrt(pow(xcenter - i,2) + pow(ycenter - j,2) + pow(zcenter - k,2));
                if(xcenter < 0 || xcenter > i || ycenter < 0 || ycenter > j || zcenter < 0 || zcenter > k)
                {

                }else if(d <= radius)
                {
                   s.cutVoxel(i, j, k);

                }
            }
        }
    }
}
