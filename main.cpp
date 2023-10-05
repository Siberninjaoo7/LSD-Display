#include "mbed.h"
#include "mbed.h"
#include <algorithm>
#include <cmath>
#include <cmath>
#include <ostream>
#include "iostream"
#include "TextLCD.h"
using namespace std;
#define BLINKING_RATE 100ms ;
DigitalOut arregloCol [3] ={D8,D9,D10};
DigitalIn arregloFil [4] = {D11,D12,D13,D14};
int teclado [4][3] ={{1,2,3},{4,5,6},{7,8,9},{0,0,0}};
PwmOut ledR(LED1);
PwmOut ledG(LED2);
PwmOut ledB(LED3);
TextLCD display(D2, D3, D4, D5, D6, D7, TextLCD::LCD16x2);
// main() runs in its own thread in the OS
int main()
{
     int xFuncion = -1, yFuncion = -1;
    while (true) {
         display.cls();
    ThisThread::sleep_for(1ms);
    display.printf("Como, habria que probarlo. -G ronimo Sanchez");
    display.locate(0,1);
    display.printf("Arq Hard");
     bool validadorPrincipal = true;
            display.printf("Selecione la funcion deseada con 1, 2 o 3");
            while(validadorPrincipal){
                for(int i =0; i<3; i++){
                    arregloCol[i] =0;
                    for(int j = 0; j<4;j++){
                        if(!arregloFil[j]){
                            xFuncion = i;
                            yFuncion = j;
                            validadorPrincipal=false;
                            while(!arregloFil[j]);
                            break;
                        }
                    }
                    arregloCol[i] =1;
                }
            }
            if(xFuncion == 0 && yFuncion == 0){
                display.printf("Primer funcion");
                double x1 =0,y1=0,x2=0,y2=0;
                int counter =0;

                display.printf("Ingrese la coordenada X del primer punto ");
                bool validador= true;
                while(validador){
                    for(int i =0; i<3; i++){
                    arregloCol[i] =0;
                        for(int j = 0; j<4;j++){
                            if(!arregloFil[j]){
                                x1 += teclado[j][i]*(pow(10,counter));
                                counter++;
                                while(!arregloFil[j]){

                                }
                                if(i == 2 && j == 3){
                                    validador  = false;
                                    break;
                                }   
                            }
                        }
                        arregloCol[i] =1;
                    }
                }
                counter=0;
                validador = true;
                display.printf("La coordenada X1 ingresada es ");
                string cord1 = (string)x1;
                display.printf(cord1);
                printf("Ingrese la coordenada Y del primer punto ");
                while(validador){
                    for(int i =0; i<3; i++){
                        arregloCol[i] =0;
                        for(int j = 0; j<4;j++){
                            if(!arregloFil[j]){
                                y1 += teclado[j][i]*(pow(10,counter));
                                counter++;
                                while(!arregloFil[j]){

                                }
                                if(i == 2 && j == 3){
                                    validador = false;
                                    break;  
                                }
                            }
                        }
                        arregloCol[i] =1;
                    }
                }
                validador=true;
                counter = 0;
                string cord2 = (string)y1;
                printf("La coordenada de Y1 ingresada es ");
                printf(y1);
                printf("Ingrese la coordenada X del segundo punto ");
                while(validador){
                    for(int i =0; i<3; i++){
                        arregloCol[i] =0;
                        for(int j = 0; j<4;j++){
                            if(!arregloFil[j]){
                                x2 += teclado[j][i]*(pow(10,counter));
                                counter++;
                                while(!arregloFil[j]){

                                }
                                if(i == 2 && j == 3){
                                    validador  = false;
                                    break;
                                } 
                            }
                        }
                        arregloCol[i] =1;   
                    }
                }
                validador = true;
                counter =0;
                printf("La coordenada de X2 ingresada es ");
                string coord3 = (string)x2;
                printf(x2);
                printf("Ingrese la coordenada Y del segundo punto ");
                while(validador){
                    for(int i =0; i<3; i++){
                        arregloCol[i] =0;
                        for(int j = 0; j<4;j++){
                            if(!arregloFil[j]){
                                y2 += teclado[j][i]*(pow(10,counter));
                                counter++;
                                while(!arregloFil[j]){

                                }
                                if(i == 2 && j == 3){
                                    validador = false;
                                    break;  
                                }
                            }
                        }
                        arregloCol[i] =1;
                    }
                }
                printf("La coordenada de Y2 ingresada es ");
                string coord4 = (string)y2;
                printf(y2);
                if(x1 ==x2 && y1 ==y2){
                    printf("Los puntos son iguales la pendiente es indefinida");
                }else if(x2-x1 == 0){
                    printf("La pendiente es indefinida por division entre cero");
                }else{
                    double pendiente = (y2-y1)/(x2-x1);
                    double interceptoY = y1-pendiente*x1;
                    printf("La pendiente es ");
                    string pend = (string)pendiente;
                    printf(pend);
                    printf("El intercepto con el eje Y es ");
                    string inter = (string)interceptoY;
                    printf(inter);
                }
                xFuncion = -1;
                yFuncion = -1;
            }else if(xFuncion == 1 && yFuncion ==0){
                printf("Segunda funcion");
                double n =0;
                double temp =0;
                double suma =0.0;
                double sumaCuadrados = 0.0;
                bool validador = true;
                int counter =0;
                printf("Ingrese la cantidad de temperaturas");
                while(validador){
                    for(int i =0; i<3; i++){
                        arregloCol[i] =0;
                        for(int j = 0; j<4;j++){
                            if(!arregloFil[j]){
                                n = n + teclado[j][i]*(pow(10,counter));
                                counter++;
                                while(!arregloFil[j]){

                                }
                                if(i == 2 && j == 3){
                                    validador = false;
                                    break;  
                                }
                            }
                        }
                        arregloCol[i] =1;
                    }
                }
                cout<<n<<endl;
                validador=true;
                counter=0;
                for(int u = 0; u<n;u++){
                    string un = (string)u; 
                    temp=0;
                    printf("Ingrese la temperatura ");
                    printf(un);
                    printf(" :");
                    while(validador){
                        for(int i =0; i<3; i++){
                            arregloCol[i] =0;
                            for(int j = 0; j<4;j++){
                                if(!arregloFil[j]){
                                    temp += teclado[j][i]*(pow(10,counter));
                                    counter++;
                                    while(!arregloFil[j]){

                                    }
                                    if(i == 2 && j == 3){
                                        validador = false;
                                        break;  
                                    }
                                }
                            }
                            arregloCol[i] =1;
                        }
                    }
                    printf("La temperatura ingresada es ");
                    string tempo = (string)temp;
                    printf(tempo);
                    validador=true;
                    counter=0;
                    suma += temp;
                    sumaCuadrados += temp*temp;
                }
                double promedio = suma/n;
                double desviacionStandar = sqrt((sumaCuadrados/n)-promedio*promedio);
                printf("El promedio de las temperaturas es ");
                string prom = (string)promedio;
                printf("La desviacion estandar es ");
                string desvi = (string)desviacionStandar;
                pritnf(desvi);
                xFuncion = -1;
                yFuncion = -1;
            }else if (xFuncion == 2 && yFuncion == 0){
                printf("Tercera funcion");
                int validador = 1;
                while (validador == 1) {
                    int frecuenciaR;
                    int frecuenciaG;
                    int frecuenciaB;
                    int counter = 0;
                    int R = 0;
                    int G = 0;
                    int B = 0;
                    bool validadorRGB = true;
                    printf("Ingrese el valor (entre 0 y 255) para el rojo");
                    while(validadorRGB){
                        for(int i =0; i<3; i++){
                            arregloCol[i] =0;
                            for(int j = 0; j<4;j++){
                                if(!arregloFil[j]){
                                    R += teclado[j][i]*(pow(10,counter));
                                    counter++;
                                    while(!arregloFil[j]){

                                    }
                                    if(i == 2 && j == 3){
                                        validadorRGB = false;
                                        break;  
                                    }
                                }
                            }
                            arregloCol[i] =1;
                        }
                    }
                    printf("Valor ingresado para el rojo: ");
                    string lojo = (string)R;
                    printf(lojo);
                    counter = 0;
                    validadorRGB = true;
                    printf("Ingrese el valor (entre 0 y 255) para el verde");
                    while(validadorRGB){
                        for(int i =0; i<3; i++){
                            arregloCol[i] =0;
                            for(int j = 0; j<4;j++){
                                if(!arregloFil[j]){
                                    G += teclado[j][i]*(pow(10,counter));
                                    counter++;
                                    while(!arregloFil[j]){

                                    }
                                    if(i == 2 && j == 3){
                                        validadorRGB = false;
                                        break;  
                                    }
                                }
                            }
                            arregloCol[i] =1;
                        }
                    }
                    printf("Valor ingresado para E")
                    string velde = (string)G;
                    printf(velde);
                    counter = 0;
                    validadorRGB = true;
                    printf("Ingrese el valor (entre 0 y 255) para el azul");
                    while(validadorRGB){
                        for(int i =0; i<3; i++){
                            arregloCol[i] =0;
                            for(int j = 0; j<4;j++){
                                if(!arregloFil[j]){
                                    B += teclado[j][i]*(pow(10,counter));
                                    counter++;
                                    while(!arregloFil[j]){

                                    }
                                    if(i == 2 && j == 3){
                                        validadorRGB = false;
                                        break;  
                                    }
                                }
                            }
                            arregloCol[i] =1;
                        }
                    }
                    printf("Valor ingresado para el azul: ")
                    string blu = (string)B;
                    printf(blu);
                    validadorRGB = true;
                    frecuenciaR = 1-R/255;
                    frecuenciaG = 1-G/255;
                    frecuenciaB = 1-B/255;
                    ledR.write(frecuenciaR);
                    ledG.write(frecuenciaG);
                    ledB.write(frecuenciaB);
                    ThisThread::sleep_for(BLINKING_RATE);
                    display.printf("Desea otro color (0 para salir, 1 para continuar)");
                    while(validadorRGB){
                        for(int i =0; i<3; i++){
                            arregloCol[i] =0;
                            for(int j = 0; j<4;j++){
                                if(!arregloFil[j]){
                                    if(i == 0 && j == 0){
                                        validador = 1;
                                        validadorRGB = false;
                                        break;  
                                    }else if(i == 1 && j == 3){
                                        validador = 0;
                                        validadorRGB = false;
                                        break;
                                    }
                                }
                            }
                            arregloCol[i] =1;
                        }
                    }
                }
                xFuncion = -1;
                yFuncion = -1;
            }
        }
    }


