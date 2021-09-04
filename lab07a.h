/*Este programa cria uma biblioteca que ira fazer a conversão de unidades de medida para diversas outras unidades
Para isso ele tera uma entrada em que poderá se colocar diversas medidas de uma so vez, e como comando de 'stop' será lido um Q.
Autor: Rafael Hajime Mori        RA: 21045116*/

#include <stdio.h>
#include <math.h>

/* para medidas de peso: */
#define P_KG 0
#define P_LB 1
#define P_OZ 2
/* para medidas de comprimento: */
#define C_KM  0
#define C_MI  1
#define C_FT  2
#define C_LEA 3
/* para medidas de temperatura: */
#define T_C 0
#define T_F 1
#define T_K 2
/* para medidas de volume: */
#define V_M3   0
#define V_L    1
#define V_GAL  2
#define V_BL   3
#define V_FLOZ 4
/* para medidas de velocidade: */
#define S_KMH 0
#define S_MS  1
#define S_MPH 2

void converte_peso(int tipo, double *kg, double *lb, double *oz){
    /*converte em kilograma*/
    if(tipo==0){
        (*lb) = (*kg) / 0.3732417216;
        (*oz) = (*kg) / 0.028;
    }
    /*converte para libras*/
    if(tipo==1){
        *kg = *lb * 0.3732417216;
        *oz = (0.028 * *lb) *  0.3732417216;
    }
    /*converte para onça*/
    if(tipo==2){
        *kg = 0.028 * *oz;
        *lb = (*oz * 0.028) /0.3732417216;
    }
}

void converte_comprimento(int tipo, double *km, double *mi, double *ft, double *lea){
    /*converte para kilometros*/
    if(tipo==0){
        *mi = *km / 1.609344 ;
        *ft = *km / 0.0003048 ;
        *lea = *km / 4.828;
    }
    /*converte para milhas*/
    if(tipo==1){
        *km = (*mi * 1.609344);
        *ft = (1.609344 * *mi) / 0.0003048;
        *lea = (1.609344 * *mi) / 4.828;
    }
    /*converte para pés*/
    if(tipo==2){
        *km = (*ft * 0.0003048);
        *mi = (0.0003048 * *ft) / 1.609344;
        *lea = (0.0003048 * *ft) / 4.828;
    }
    /*converte para legua*/
    if(tipo==3){
        *km = *lea * 4.828;
        *ft = (4.828 * *lea) / 0.0003048;
        *mi = (4.828 * *lea) / 1.609344;
    }
}

void converte_temperatura(int tipo, double *c, double *f, double *k){     /*AQUIIIIIIIIIIIIIII*/
    /*converte para Celcius*/
    if(tipo==0){
        *f = (*c * (9/5))+32;
        *k = *c+237.15;
    }
    /*converte para Fahrenheit*/
    if(tipo==1){
        *c = ( *f -32)*(5/9);
        *k = ( *f +459.67)* (5/9);
    }
    /*converte para kelvin*/
    if(tipo==2){
        *c = *k -237.15;
        *f = ( *k * (9/5))-459.67;
    }
}
void converte_volume(int tipo, double *m3, double *l, double *gal, double *bl, double *floz){
    /*em metros³*/
    if(tipo==0){
        *l = *m3 / (pow(10,-3));
        *gal = *m3 / (4.54609 * pow(10, -3));
        *bl = *m3 / 0.16365924;
        *floz = *m3 / (3 * pow(10, -5));
    }
    /*em litros*/
    if(tipo==1){
        *m3 = *l * (pow(10,-3));
        *gal = *l / 4.54609;
        *bl = (*l * (pow(10,-3))) / 0.16365924;
        *floz = (*l * (pow(10,-3))) / (3 * (pow(10, -5)));
    }
    /*em galões*/
    if(tipo==2){
        *m3 = *gal * (4.54609 * pow(10, -3));
        *l = *gal * (4.54609);
        *bl = *gal * (4.54609 * pow(10, -3)) / 0.16365924;
        *floz = *gal * (4.54609 * pow(10, -3)) / (3 * (pow(10, -5)));
    }
    /*em barril */
    if(tipo==3){
        *m3 = *bl * 0.16365924;
        *l = (*bl * 0.16365924) / (pow(10, -3));
        *gal =  (*bl * 0.16365924) / (4.54609 * (pow(10, -3)));
        *floz =  (*bl * 0.16365924) / (3 * (pow(10, -5)));
    }
    /*onça fluída*/
    if(tipo==4){
        *m3 = *floz * (3 * (pow(10, -5)));
        *l = (*floz * (3 * (pow(10, -5)))) / (pow(10, -3));
        *gal = (*floz * (3 * (pow(10, -5)))) / (4.54609 * (pow(10, -3)));
        *bl = (*floz * (3 * (pow(10, -5)))) / (3 * (pow(10, -5)));
    }
}
void converte_velocidade(int tipo, double *kmh, double *ms, double *mph){
    /*converte para kilometros por hora*/
    if(tipo==0){
        *ms = *kmh * (2.7 * (pow(10, -1)));
        *mph = *kmh * (2.7 * (pow(10, -1))) / (0.44704);
    }
    /*converte para metros por segundo*/
    if(tipo==1){
        *kmh = *ms / (2.7 * (pow(10, -1)));
        *mph = *ms / (0.44704);
    }
    /*converte para milhas por hora*/
    if(tipo==2){
        *kmh = *mph * (2.7 * (pow(10, -1))); /*AQUIIIIIIIIIIIIIII*/
        *ms = *mph * 0.44704;
    }

}
