#include "sculptor.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>

/**
 * @brief Construtor da classe
 * @param _nx A dimensão da largura da matriz
 * @param _ny A dimensão da altura da matriz
 * @param _nz A dimensão do profundidade da matriz
 */
Sculptor::Sculptor(int _nx, int _ny, int _nz)
{
    nx = _nx;
    ny = _ny;
    nz = _nz;
    if(nx <= 0 || ny<=0 || nz<=0){
        nx=0;
        ny=0;
        nz=0;
    }

    v = new Voxel**[nx];

    v[0] = new Voxel*[nx*ny];

    v[0][0] = new Voxel[nx*ny*nz];

}
/**
 * @brief A função setColor define a cor atual do desenho
 * @param r cor vermelha
 * @param g cor verde
 * @param b cor azul
 * @param alpha define a transparência da estrutura
 */

void Sculptor::setColor(float r, float g, float b, float alpha)
{
    _r = r;
    _g = g;
    _b = b;
    _a = alpha;
}
/**
 * @brief A função putVoxel ativa o voxel na posição (x,y,z) (fazendo ison = true) e atribui ao mesmo a cor atual de desenho
 * @param x
 * @param y
 * @param z
 */
void Sculptor::putVoxel(int x, int y, int z)
{
    v[x][y][z].ison = true;
    v[x][y][z].r = _r;
    v[x][y][z].g = _g;
    v[x][y][z].b = _b;
    v[x][y][z].a = _a;

}
/**
 * @brief A função cutVoxel desativa o voxel na posição (x,y,z) (fazendo ison = false)
 * @param x
 * @param y
 * @param z
 */
void Sculptor::cutVoxel(int x, int y, int z)
{
    v[x][y][z].ison = false;

}
/**
 * @brief A função putBox ativa os voxels no intervalo [x0-x1],[y0-y1] e [z0-z1]e atribui aos voxels a cor atual do desenho
 * @param x0
 * @param x1
 * @param y0
 * @param y1
 * @param z0
 * @param z1
 */
void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1)
{
    int i,j,k;
    for (i = x0; i<x1+1; i++){
            for ( j = y0; j<y1+1; j++){
                for ( k = z0; k<z1+1; k++){

                }
            }
    }

}
/**
 * @brief A função cutBox desativa todos os voxels no intervalo [x0-x1] , [y0-y1] e [z0-z1] atribuindo aos voxels a cor atual do desenho
 * @param x0
 * @param x1
 * @param y0
 * @param y1
 * @param z0
 * @param z1
 */
void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1)
{
    int i,j,k;
    for (i = x0; i<x1+1; i++){
        for ( j = y0; j<y1+1; j++){
            for (k = z0; i<z1+1; k++){
                v[i][j][k].r = _r;
                v[i][j][k].g = _g;
                v[i][j][k].b = _b;
                v[i][j][k].a = _a;
                v[i][j][k].ison = false;

            }
        }
    }
}
/**
 * @brief A função putSphere ativa todos os voxels que satisfaz a equação da esfera e atribui aos voxels a cor atual do desenho
 * @param xcenter  variável x do centro da esfera
 * @param ycenter  variável y do centro da esfera
 * @param zcenter  variável z do centro da esfera
 * @param radius  raio da esfera
 */
void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius)
{
    int i,j,k;
    for(i=0;i<xcenter;i++){
        for(j=0;j<ycenter;j++){
            for(k=0;k<zcenter;k++){
                if((pow((i-xcenter),2)+pow((j-ycenter),2)+pow((k-zcenter),2))<=pow(radius,2)){
                    v[i][j][k].ison = true;
                    v[i][j][k].r = _r;
                    v[i][j][k].g = _g;
                    v[i][j][k].b = _b;
                    v[i][j][k].a = _a;
                }
            }
        }
    }
}
/**
 * @brief A função cutSphere desativa todos os voxels que satisfaz a equação da esfera
 * @param xcenter variável x do centro da esfera
 * @param ycenter variável y do centro da esfera
 * @param zcenter variável z do centro da esfera
 * @param radius raio da esfera
 */
void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius)
{
    int i,j,k;
    for(i=0;i<xcenter;i++){
        for(j=0;j<ycenter;j++){
            for(k=0;k<zcenter;k++){
                if((pow((i-xcenter),2)+pow((j-ycenter),2)+pow((k-zcenter),2))<=pow(radius,2)){
                    v[i][j][k].r = _r;
                    v[i][j][k].g = _g;
                    v[i][j][k].b = _b;
                    v[i][j][k].a = _a;
                    v[i][j][k].ison = false;
                }
            }
        }
    }
}
/**
 * @brief A função putEllipsoid Ativa todos os voxels que satisfazem à equação do elipsóide e atribui aos mesmos a cor atual de desenho
 * @param xcenter
 * @param ycenter
 * @param zcenter
 * @param rx
 * @param ry
 * @param rz
 */
void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz)
{
    int i,j,k;
    for(i=0;i<rx;i++){
        for(j=0;j<ry;j++){
            for(k=0;k<rz;k++){
                if((pow((i-xcenter),2)/pow(xcenter,2))+(pow((j-ycenter),2)/pow(ycenter,2))+(pow((k-zcenter),2)/pow(zcenter,2))<=1){
                    v[i][j][k].ison = true;
                    v[i][j][k].r = _r;
                    v[i][j][k].g = _g;
                    v[i][j][k].b = _b;
                    v[i][j][k].a = _a;
                }
            }
        }
    }
}
/**
 * @brief A função cutEllipsoid ativa os voxels que satisfaz a equação do elipsoide e atribui aos voxels a cor atual do desenho
 * @param xcenter
 * @param ycenter
 * @param zcenter
 * @param rx
 * @param ry
 * @param rz
 */
void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz)
{
    int i,j,k;
    for(i=0;i<rx;i++){
        for(j=0;j<ry;j++){
            for(k=0;k<rz;k++){
                if((((pow((i-xcenter),2))/(pow(xcenter,2)))+((pow((j-ycenter),2))/(pow(ycenter,2)))+((pow((k-zcenter),2))/(pow(zcenter,2))))<=1){
                    v[i][j][k].r = _r;
                    v[i][j][k].g = _g;
                    v[i][j][k].b = _b;
                    v[i][j][k].a = _a;
                    v[i][j][k].ison = false;
                }
            }
        }
    }

}
/**
 * @brief Destrutor da classe Sculptor
 */
Sculptor::~Sculptor()
{
   delete [] v[0][0];
   delete [] v[0];
   delete [] v;
}
