LSD-Display Tres Funciones

Autores: Jeronimo Sanchez, Luis Miguel Garcia y Julio Jaller

El codigo cumple las siguientes funciones:
1. Aplicación que solicite los valores de dos puntos en un plano cartesiano y retorne la pendiente y el
intercepto con el eje y de la recta que pasa por esos dos puntos (realice un control de las
indeterminaciones matemáticas).
2. Aplicación para calcular el promedio y la desviación estándar de un conjunto de N temperaturas
introducidos por consola. Para esto es necesario solicitar al usuario el número N de temperaturas y
paso siguiente, cada uno de los valores.
3. Aplicación que permita generar colores en un LED RGB con base en el código de color RGB.

Se selecciona la funcion mediante el teclado siendo el uno la primera funcion, el dos la segunda y el tres la tercera
Para poder seleccionar por el teclado se tiene una funcion que se compone de un ciclo While y dos ciclos For anidados de forma que se recorre la matriz 
del teclado, las filas son DigitalInts (Correspondientes a las entradas D2,D3,D4 y D5) por lo que envian una señal, en el primer ciclo For se enciende 
un y solo un DigitalInt por cada ciclo; en siguiente For lo que se hace es mirar cual DigitlaOut correspondiente a las columnas (entradas D6,D7 y D8) 
cierran el circuito, verifcacion realizada con un If dentro de dicho For que si entra a este cambia los valores de dos variables xFuncion y yFuncion que 
indican que posicion del teclado se esta presionando y en base a esta posición seleccionar la funcion luego de que se sale del ciclo, para salir del ciclo a 
la vez que se cambian las variables xFuncion y yFuncion se cambia por false una variable booleana validadorPrincipal para que no vuelva a recorrer el 
y entre a la funcion seleccionada.

```cpp
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
```

Para poder entrar a la función seleccionada se hace una serie de comparaciones con unos Else If que comparan las variables xFuncion y yFuncion anteriormente 
mencionados, si no cumplen con los valores esperados se vuelve a entrar a la funcion anteriormente mencionada para seleccionar por teclado.

            if(xFuncion == 0 && yFuncion == 0){
                
            }else if(xFuncion == 1 && yFuncion ==0){
                
            }else if (xFuncion == 2 && yFuncion == 0){

            }

Para la primera funcion utilizamos la funcion anteriomente mencionada para solicitar valores por teclado solo que en esta dentro del If las 
se le suma a una variable x1, y1, x2 y y2, para cada variable hacemos la funcion una vez, en esta funcion tenemos un counter que corresponder al exponente
del 10 para ir agregando decenas, centenas, etc; el problema es que como lo implementamos hay que meter los numeros alrevez de como estamos acostumbrados;
luego de ingresar todos los valores hacemos las operaciones correspondientes para poder imprimir en la consola lo que nos piden, la pendiente y el 
intercepto con el eje y.

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

Para la seunda funcion solicitamos un valor para N (la cantidad de temperaturas) mediante el mismo metodo anteriormente mencionado seguido a esto entramos 
a un ciclo For para pedir las N temperaturas, que se piden mediante el mismo metodo pero se guardan en una misma varible temp; como nos piden el promedio y 
la desviacion estadar antes de salir del cilco For se suma la variable obtenida a dos sumatorias una para el promedio y otra para la deviacion estandar, 
luego de salir del ciclo se hacen los calculos y se imprimen por consola el promedio y la desviación estandar.

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

Para la tercera funcion se usa exactamente el mismo metodo que se uso en las anteriores funciones para pedir por teclado los datos, hacemos la funcion 
tres veces una por cada color Rojo, Verde y Azul, luego de obtener los valores se divide entre 255 para obtener un valor entre cero y uno y el valor 
obtenido se le resta a uno, valor correspondiente a la frecuencia de los LEDS, luego de esto se llama a los LEDs para cambiar su frecuencia, y por ultimo 
se pregunta al usuario si desea mostrar otro color, si pressiona el 1 del teclado puede meter otro color y si presiona el cero del teclado sale de la 
función y puede seleccionar otra.

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

Para poder ingresar a otra función sin tener que reiniciar el codigo, despues de cada función tenemos que reiniciar las variables xFuncion y yFuncion.

```cpp
                xFuncion = -1;
                yFuncion = -1;
```

Nota:
En todas las tres funciones se tiene que ingresar los numeros al revez primero unidades, luego decenas, centenas y así sucesivamente
