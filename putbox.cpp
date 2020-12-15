#include "putbox.h"
#include <math.h>

PutBox::PutBox(int x0, int x1, int y0, int y1, int z0, int z1, float r, float g, float b, float a){
    this->x0=x0; this->x1=x1; this->y0=y0; this->y1=y1; this->z0=z0; this->z1=z1;
    this->r=r; this->g=g; this->b=b; this->a=a;
}

void PutBox::draw(Sculptor &s){
    if(x0 > x1){
        int tmp = x0;
        x1 = x0;         // implementar uma função troca;
        x0 = tmp;
    }
    if(y0 > y1){
        int tmp = y0;
        y1 = y0;         // implementar uma função troca;
        y0 = tmp;
    }
    if(z0 > z1){
        int tmp = z0;
        z1 = z0;         // implementar uma função troca;
        z0 = tmp;
    }
    for(int i = x0; i < x1; i++){
        for(int j = y0; j < y1; j++){
            for(int k = z0; k < z1; k++){
                s.putVoxel(1, j, k);
            }
        }
    }
}
