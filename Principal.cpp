#include <iostream>
using namespace std;
#include "Vector3D.h"
#include "Esfera.h"
#include "ViewPlane.h"
#include "Rayo.h"

#include "Utilitarios.h"

int main()
{
    
    // ESFERA
    Punto3D centro(-20.0, 0.0, 100.0);
    double radio = 50;
    Esfera esfera(centro, radio);

    // ESFERA 2
    Punto3D centro1(20.0, 0.0, 80.0);
    double radio1 = 50;
    Esfera esfera1(centro1, radio1);   

    // VIEWPLANE
    int hres = 400;
    int vres = 300;
    double s = 1.0;
    ViewPlane vp(hres, vres, s);

    // UTILITARIO PARA GUARDAR IMAGEN -------------------------------------------------------------------
    int dpi = 72;
    int width = vp.hres;
    int height = vp.vres;
    int n = width * height;
    ColorRGB* pixeles = new ColorRGB[n];
    // --------------------------------------------------------------------------------------------------
    for(int fil = 0; fil < vp.vres; fil++)
    {
        for ( int col = 0; col < vp.hres; col++) 
        {
            // Disparar un rayo
            Vector3D direccion(0.0, 0.0, -1.0);
            double x_o = vp.s * ( col - vp.hres/2 + 0.5 );
            double y_o = vp.s * ( fil - vp.vres/2 + 0.5 );
            double z_o = 100;
            Punto3D origen(x_o, y_o, z_o);
          
            /*Rayo rayo(origen, direccion);
            if (esfera.hayImpacto(rayo) || esfera1.hayImpacto(rayo))
            {
                // PINTAR
                esfera.setColor(0.0,1.0,0);
                pixeles[fil*width+col].r = esfera.obtenerColor().r;
                pixeles[fil*width+col].g = esfera.obtenerColor().g;
                pixeles[fil*width+col].b = esfera.obtenerColor().b;
                   
                esfera1.setColor(1,0.0,0);
                pixeles[fil*width+col].r = esfera1.obtenerColor().r;
                pixeles[fil*width+col].g = esfera1.obtenerColor().g;
                pixeles[fil*width+col].b = esfera1.obtenerColor().b;
            }
            else
            {
                // PINTAR DE NEGRO
                pixeles[fil*width+col].r = 0.0;
                pixeles[fil*width+col].g = 0.0;
                pixeles[fil*width+col].b = 0.0;
            }*/

            Rayo rayo(origen, direccion);
            if (esfera.hayImpacto(rayo))
            {
                // PINTAR
                esfera.setColor(0.0,1.0,0);
                pixeles[fil*width+col].r = esfera.obtenerColor().r;
                pixeles[fil*width+col].g = esfera.obtenerColor().g;
                pixeles[fil*width+col].b = esfera.obtenerColor().b;
                   

            }

            //esfera1.hayImpacto(rayo)
            else
            {
                if (esfera1.hayImpacto(rayo))
                {
                    // PINTAR
                    esfera1.setColor(1.0,0.0,0);
                    pixeles[fil*width+col].r = esfera1.obtenerColor().r;
                    pixeles[fil*width+col].g = esfera1.obtenerColor().g;
                    pixeles[fil*width+col].b = esfera1.obtenerColor().b;
                }
                else{
                     // PINTAR DE NEGRO
                pixeles[fil*width+col].r = 0.0;
                pixeles[fil*width+col].g = 0.0;
                pixeles[fil*width+col].b = 0.0;
                }
               
            }

        }
    }

    savebmp("img1.bmp", width, height, dpi, pixeles);
    return 0;
}