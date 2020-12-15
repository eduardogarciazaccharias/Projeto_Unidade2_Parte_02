#include "interpretador.h"
#include "putvoxel.h"
#include "putbox.h"
#include "putelipsoide.h"
#include "putsphere.h"
#include "cutbox.h"
#include "cutelipsoide.h"
#include "cutsphere.h"
#include "cutvoxel.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <ostream>


interpretador::interpretador(){

}

std::vector<Figurageometrica*> interpretador::parse(std::string filename){
    std::vector<Figurageometrica*> figs;
    std::ifstream fin;
    std::stringstream ss;
    std::string s, token;

    fin.open(filename.c_str());
    if(!fin.is_open()){
        std::cout << "nao abriu " << filename << std::endl;
        exit(0);
    }

    while(fin.good()){
        std::getline(fin, s);
        if(fin.good()){
            ss.clear();
            ss.str(s);
            ss >> token;
            if(ss.good()){
                if(token.compare("dim") == 0){
                    ss >> dimx >> dimy >> dimz;
                }
                else if(token.compare("putvoxel") == 0){
                    int x0, y0, z0;
                    ss >> x0 >> y0 >> z0 >> r >> g >> b >> a;
                    figs.push_back(new PutVoxel(x0, y0, z0, r, g, b, a));
                }
                else if(token.compare("cutvoxel") == 0){
                    int x0, y0, z0;
                    ss >> x0 >> y0 >> z0;
                    figs.push_back(new CutVoxel(x0, y0, z0));
                }
                else if(token.compare("putbox") == 0){
                    int x0, x1, y0, y1, z0, z1;
                    ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1 >> r >> g >> b >> a;
                    figs.push_back(new PutBox(x0, x1, y0, y1, z0, z1, r, g, b, a));
                }
                else if(token.compare("cutbox") == 0){
                    int x0, x1, y0, y1, z0, z1;
                    ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1;
                    figs.push_back(new CutBox(x0, x1, y0, y1, z0, z1));
                }
                else if(token.compare("putsphere") == 0){
                    int xcenter, ycenter, zcenter, radius;
                    ss >> xcenter >> ycenter >> zcenter >> radius >> r >> g >> b >> a;
                    figs.push_back(new PutSphere(xcenter, ycenter, zcenter, radius, r, g, b, a));
                }
                else if(token.compare("cutsphere") == 0){
                    int xcenter, ycenter, zcenter, radius;
                    ss >> xcenter >> ycenter >> zcenter >> radius;
                    figs.push_back(new CutSphere(xcenter, ycenter, zcenter, radius));
                }
                else if(token.compare("putelipsoide") == 0){
                    int xcenter, ycenter, zcenter, rx, ry, rz;
                    ss >> xcenter >> ycenter >> zcenter >> rx >> ry >> rz >> r >> g >> b >> a;
                    figs.push_back(new PutElipsoide(xcenter, ycenter, zcenter, rx, ry, rz, r, g, b, a));
                }
                else if(token.compare("cutelipsoide") == 0){
                    int xcenter, ycenter, zcenter, rx, ry, rz;
                    ss >> xcenter >> ycenter >> zcenter >> rx >> ry >> rz;
                    figs.push_back(new CutElipsoide(xcenter, ycenter, zcenter, rx, ry, rz));
                }

            }
        }
    }
    return (figs);
}

int interpretador::getDimx(){
    return dimx;
}
int interpretador::getDimy(){
    return dimy;
}
int interpretador::getDimz(){
    return dimz;
}
