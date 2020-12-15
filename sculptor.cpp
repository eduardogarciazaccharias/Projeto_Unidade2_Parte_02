#include "sculptor.h"
#include "voxel.h"
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;
Voxel ***v;
int nx, ny, nz;
float r, g, b, a;

Sculptor::Sculptor(int _nx, int _ny, int _nz)
{
    nx = _nx;
    ny = _ny;
    nz = _nz;
   // r = g = b = a = 1;
    alocaRecurso();
}
Sculptor::~Sculptor()
{
    for(int i =0; i < nx; i++){
        for(int j = 0; j < ny; j++){
            delete[] v[i][j];
        }
    }
    for(int x = 0; x < nx; x++){
        delete [] v[x];
    }
    delete [] v;
    nx = ny = nz = 0;
}
void Sculptor::alocaRecurso()
{
    v= new Voxel**[nx];
    for(int i =0; i < nx; i++){
        v[i] = new Voxel*[ny];
    }
    for(int i =0; i < nx; i++){
        for(int j = 0; j < ny; j++){
            v[i][j] = new Voxel[nz];
        }
    }
    for(int i = 0; i < nx; i++){
        for(int j = 0; j < ny; j++){
            for(int k = 0; k < nz; k++){
                v[i][j][k].isOn = false;
                v[i][j][k].r = r;
                v[i][j][k].g = g;
                v[i][j][k].b = b;
            }
        }
    }
}
void Sculptor::setColor(float _r, float _g, float _b, float _a)
{
    r = _r;
    g = _g;
    b = _b;
    a = _a;
}

void Sculptor::putVoxel(int x, int y, int z)
{
    v[x][y][z].isOn = true;
    v[x][y][z].r = r;
    v[x][y][z].g = g;
    v[x][y][z].b = b;
    v[x][y][z].a = a;
}
void Sculptor::cutVoxel(int x, int y, int z)
{
    v[x][y][z].isOn = false;
}


void Sculptor::writeOFF(char* filename )
{

    ofstream saida;

    saida.open(filename);

    saida << "OFF" << endl;
    int cont = 0;
    for(int i = 0; i < nx; i++){
        for(int j = 0; j < ny; j++){
            for(int k = 0; k < nz; k++){
                if(v[i][j][k].isOn == true){
                    cont++;
                }
            }
        }
    }
    saida << 8*cont << " " << 6*cont << " 0\n";
    for(int i = 0; i < nx; i++){
        for(int j = 0; j < ny; j++){
            for(int k = 0; k < nz; k++){
                if(v[i][j][k].isOn == true){
                    saida << i - 0.5 << " " << j + 0.5 << " " << k - 0.5 << " " <<endl;
                    saida << i - 0.5 << " " << j - 0.5 << " " << k - 0.5 << " " <<endl;
                    saida << i + 0.5 << " " << j - 0.5 << " " << k - 0.5 << " " <<endl;
                    saida << i + 0.5 << " " << j + 0.5 << " " << k - 0.5 << " " <<endl;
                    saida << i - 0.5 << " " << j + 0.5 << " " << k + 0.5 << " " <<endl;
                    saida << i - 0.5 << " " << j - 0.5 << " " << k + 0.5 << " " <<endl;
                    saida << i + 0.5 << " " << j - 0.5 << " " << k + 0.5 << " " <<endl;
                    saida << i + 0.5 << " " << j + 0.5 << " " << k + 0.5 << " " <<endl;

                }
            }
        }
    }
    int aux = 0;
    for(int i = 0; i < nx; i++){
        for(int j = 0; j < ny; j++){
            for(int k = 0; k < nz; k++){
                if(v[i][j][k].isOn == true){
                    saida << fixed;
                    saida << 4 << " " << 0+aux << " " << 3+aux << " " << 2+aux << " " << 1+aux << " " << setprecision(2) << v[i][j][k].r << " " << setprecision(2) << v[i][j][k].g << " " << setprecision(2) << v[i][j][k].b << " " << setprecision(2) << v[i][j][k].a <<endl;
                    saida << 4 << " " << 4+aux << " " << 5+aux << " " << 6+aux << " " << 7+aux << " " << setprecision(2) << v[i][j][k].r << " " << setprecision(2) << v[i][j][k].g << " " << setprecision(2) << v[i][j][k].b << " " << setprecision(2) << v[i][j][k].a <<endl;;
                    saida << 4 << " " << 0+aux << " " << 1+aux << " " << 5+aux << " " << 4+aux << " " << setprecision(2) << v[i][j][k].r << " " << setprecision(2) << v[i][j][k].g << " " << setprecision(2) << v[i][j][k].b << " " << setprecision(2) << v[i][j][k].a <<endl;;
                    saida << 4 << " " << 0+aux << " " << 4+aux << " " << 7+aux << " " << 3+aux << " " << setprecision(2) << v[i][j][k].r << " " << setprecision(2) << v[i][j][k].g << " " << setprecision(2) << v[i][j][k].b << " " << setprecision(2) << v[i][j][k].a <<endl;;
                    saida << 4 << " " << 3+aux << " " << 7+aux << " " << 6+aux << " " << 2+aux << " " << setprecision(2) << v[i][j][k].r << " " << setprecision(2) << v[i][j][k].g << " " << setprecision(2) << v[i][j][k].b << " " << setprecision(2) << v[i][j][k].a <<endl;;
                    saida << 4 << " " << 1+aux << " " << 2+aux << " " << 6+aux << " " << 5+aux << " " << setprecision(2) << v[i][j][k].r << " " << setprecision(2) << v[i][j][k].g << " " << setprecision(2) << v[i][j][k].b << " " << setprecision(2) << v[i][j][k].a <<endl;;
                    aux = aux+8;
                }
            }
        }
    }
    saida.close();
}
