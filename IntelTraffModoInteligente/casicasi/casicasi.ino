  //AQUI DEFINO CADA SUICHE Y LED DEL CIRCUITO 
  #define suiche0 PINC,0
  #define suiche1 PINC,1
  #define suiche2 PINC,2
  #define Verde1 PORTA,0      
  #define Amarillo1 PORTA,1             
  #define Rojo1 PORTA,2      
  #define Verde2 PORTA,3             
  #define Amarillo2 PORTA,4            
  #define Rojo2 PORTA,5  
  
//AQUI DEFINO LAS VARIABLES QUE VOY A USAR

const int fotoCeldaMin = 300;  //VALOR MINIMO DE LAS FOTO CELDAS
const int fotoCeldaMax = 900;  //VALOR MAXIMO DE LAS FOTO CELDAS

//VARIABLES DE LOS VALORES QUE REPORTA CADA SENSOR INICIADAS EN 0
int val0 = 0; 
int val1 = 0;
int val2 = 0;
int val3 = 0;
int valMulta1 = 0;
int val8 = 0;
int val9 = 0;
int val10 = 0;
int valMulta2 = 0;

//CONTADORES QUE VAN A MOSTRAR CUANTOS CARROS HAY EN CADA LINEA
int cont1 = 0;
int cont2 = 0;

void setup() {
  //DEFINO QUE ES ENTRADA Y QUE ES SALIDA
  DDRA = B00111111;
  DDRC = B00000000;
  Serial.begin(9600);  
}

void loop() {
  
  //LE ASIGNO A ESTAS VARIABLES LAS LECTURAS DE CADA SENSOR DE LA LINEA 1
  int lecturaFotoCelda0 = analogRead(A0);
  int lecturaFotoCelda1 = analogRead(A1);
  int lecturaFotoCelda2 = analogRead(A2);
  int lecturaFotoCeldaMulta1 = analogRead(A3);
  
  
  
  
  //LE ASIGNO A ESTAS VARIABLES LAS LECTURAS DE CADA SENSOR DE LA LINEA 2
  int lecturaFotoCelda8 = analogRead(A8);
  int lecturaFotoCelda9 = analogRead(A9);
  int lecturaFotoCelda10 = analogRead(A10);
  int lecturaFotoCeldaMulta2 = analogRead(A4);



  
  
  
  
  //"MAPEO" EL RANGO DE CADA UNO DE LOS SENSORES DE LA LINEA 1
  int rango0 = map(lecturaFotoCelda0, fotoCeldaMin, fotoCeldaMax, 0, 3);
  int rango1 = map(lecturaFotoCelda1, fotoCeldaMin, fotoCeldaMax, 0, 3);
  int rango2 = map(lecturaFotoCelda2, fotoCeldaMin, fotoCeldaMax, 0, 3);
  int rangoFotoMulta1 = map(lecturaFotoCeldaMulta1, fotoCeldaMin, fotoCeldaMax, 0, 3);
  
  
  //"MAPEO" EL RANGO DE CADA UNO DE LOS SENSORES DE LA LINEA 2
  int rango8 = map(lecturaFotoCelda8, fotoCeldaMin, fotoCeldaMax, 0, 3);
  int rango9 = map(lecturaFotoCelda9, fotoCeldaMin, fotoCeldaMax, 0, 3);
  int rango10 = map(lecturaFotoCelda10, fotoCeldaMin, fotoCeldaMax, 0, 3);
  int rangoFotoMulta2 = map(lecturaFotoCeldaMulta2, fotoCeldaMin, fotoCeldaMax, 0, 3);



//SI EL suiche0 ESTA ACTIVO IMPRIME SI HAY CARRO O NO Y CON QUE CERTEZA EN LA LINEA 1
 if(bitRead(PINC,suiche0)==HIGH)    
 {

//DEPENDIENDO DE EL CASO DETERMINADO POR EL MAPEO DE rango0 SE PUEDE IMPRIMIR EN EL SERIAL CADA UNO DE LOS SIGUIENTES CASOS
  switch (rango0) {
    
  case 0:    
    Serial.println("Definitivamente hay un carro en la primera posicion de el semaforo 1");
    break;
  case 1:    
    Serial.println("Posiblemente hay un carro en la primera posicion de el semaforo 1");
    break;
  case 2:    
    Serial.println("Seguramente no hay un carro en la primera posicion de el semaforo 1");
    break;
  case 3:    
    Serial.println("Definitivamente no hay un carro en la primera posicion de el semaforo 1");
    break;
  } 
  delay(10);
  

//DEPENDIENDO DE EL CASO DETERMINADO POR EL MAPEO DE rango1 SE PUEDE IMPRIMIR EN EL SERIAL CADA UNO DE LOS SIGUIENTES CASOS
 switch (rango1) {
    
  case 0:    
    Serial.println("Definitivamente hay un carro en la segunda posicion de el semaforo 1");
    break;
  case 1:    
    Serial.println("Posiblemente hay un carro en la segunda posicion de el semaforo 1");
    break;
  case 2:    
    Serial.println("Seguramente no hay un carro en la segunda posicion de el semaforo 1");
    break;
  case 3:    
    Serial.println("Definitivamente no hay un carro en la segunda posicion de el semaforo 1");
    break;
  } 
  delay(10);
  
  
  //DEPENDIENDO DE EL CASO DETERMINADO POR EL MAPEO DE rango2 SE PUEDE IMPRIMIR EN EL SERIAL CADA UNO DE LOS SIGUIENTES CASOS
   switch (rango2) {
    
  case 0:    
    Serial.println("Definitivamente hay un carro en la tercera posicion de el semaforo 1");
    break;
  case 1:    
    Serial.println("Posiblemente hay un carro en la tercera posicion de el semaforo 1");
    break;
  case 2:    
    Serial.println("Seguramente no hay un carro en la tercera posicion de el semaforo 1");
    break;
  case 3:    
    Serial.println("Definitivamente no hay un carro en la tercera posicion de el semaforo 1");
    break;
  } 
  delay(10);
  
  
  
  //DEPENDIENDO DE EL CASO DETERMINADO POR EL MAPEO DE rangoFotoMulta1 SE PUEDE IMPRIMIR EN EL SERIAL CADA UNO DE LOS SIGUIENTES CASOS
     switch (rangoFotoMulta1) {
    
  case 0:    
    Serial.println("Definitivamente un carro ha pasado  el semaforo 1");
    break;
  case 1:    
    Serial.println("Posiblemente un carro ha pasado el semaforo 1");
    break;
  case 2:    
    Serial.println("Seguramente un carro ha pasado el semaforo 1");
    break;
  case 3:    
    Serial.println("Definitivamente ningun carro ha pasado el semaforo 1");
    break;
  } 
  delay(10);
  
  
  
 }
 
  //SI EL suiche1 ESTA ACTIVO IMPRIME SI HAY CARRO O NO Y CON QUE CERTEZA EN LA LINEA 2
  if(bitRead(PINC,suiche1)==HIGH)   
 { 

  switch (rango8) {
    
  case 0:    
    Serial.println("Definitivamente hay un carro en la primera posicion de el semaforo 2");
    break;
  case 1:    
    Serial.println("Posiblemente hay un carro en la primera posicion de el semaforo 2");
    break;
  case 2:    
    Serial.println("Seguramente no hay un carro en la primera posicion de el semaforo 2");
    break;
  case 3:    
    Serial.println("Definitivamente no hay un carro en la primera posicion de el semaforo 2");
    break;
  } 
  delay(10);
  

  //DEPENDIENDO DE EL CASO DETERMINADO POR EL MAPEO DE rango9 SE PUEDE IMPRIMIR EN EL SERIAL CADA UNO DE LOS SIGUIENTES CASOS
 switch (rango9) {
    
  case 0:    
    Serial.println("Definitivamente hay un carro en la segunda posicion de el semaforo 2");
    break;
  case 1:    
    Serial.println("Posiblemente hay un carro en la segunda posicion de el semaforo 2");
    break;
  case 2:    
    Serial.println("Seguramente no hay un carro en la segunda posicion de el semaforo 2");
    break;
  case 3:    
    Serial.println("Definitivamente no hay un carro en la segunda posicion de el semaforo 2");
    break;
  } 
  delay(10);
  
  
  
    //DEPENDIENDO DE EL CASO DETERMINADO POR EL MAPEO DE rango10 SE PUEDE IMPRIMIR EN EL SERIAL CADA UNO DE LOS SIGUIENTES CASOS
   switch (rango10) {
    
  case 0:    
    Serial.println("Definitivamente hay un carro en la tercera posicion de el semaforo 2");
    break;
  case 1:    
    Serial.println("Posiblemente hay un carro en la tercera posicion de el semaforo 2");
    break;
  case 2:    
    Serial.println("Seguramente no hay un carro en la tercera posicion de el semaforo 2");
    break;
  case 3:    
    Serial.println("Definitivamente no hay un carro en la tercera posicion de el semaforo 2");
    break;
  } 
  delay(10);
  
  
  
    //DEPENDIENDO DE EL CASO DETERMINADO POR EL MAPEO DE rangoFotoMulta2 SE PUEDE IMPRIMIR EN EL SERIAL CADA UNO DE LOS SIGUIENTES CASOS
     switch (rangoFotoMulta2) {
    
  case 0:    
    Serial.println("Definitivamente un carro ha pasado  el semaforo 2");
    break;
  case 1:    
    Serial.println("Posiblemente un carro ha pasado el semaforo 2");
    break;
  case 2:    
    Serial.println("Seguramente un carro ha pasado el semaforo 2");
    break;
  case 3:    
    Serial.println("Definitivamente ningun carro ha pasado el semaforo 2");
    break;
  } 
  delay(10);
  
 }
 
 


  











  
//LE ASIGNO EL VALOR QUE DA LA LECTURA DE LOS SENSORES A LAS VARIABLES DE LA LINEA 1
val0 = analogRead(0);
val1= analogRead(1);
val2 = analogRead(2);
valMulta1 = analogRead(3);



//SI DETECTA QUE HAY 1 SOLO CARRO LE ASIGNA A cont1 EL VALOR DE 1
if (val0 <= 350 || val1 <= 350 || val2 <= 350)
{
cont1 = 1;
}

//SI ES EL VALOR QUE ARROJA EL SENSOR ES MAYOR A 350 ENTONCES NO HAY CARRO Y SE LE DA EL VALOR DE 0 A cont1
if (val0 > 350 || val1 > 350 || val2 > 350)
{
cont1 = 0;
}


//SI DETECTA QUE HAY 2  CARROS LE ASIGNA A cont1 EL VALOR DE 2
if (val0 && val1 <= 350 ||val1 && val2 <= 350 || val0 && val2 <= 350)
{
cont1 = 2;
}


//SI ES EL VALOR QUE ARROJA EL SENSOR ES MAYOR A 350 ENTONCES NO HAY CARRO Y SE LE DA EL VALOR DE 0 A cont1
if (val0 && val1 > 350 ||val1 && val2 > 350 || val0 && val2 > 350)
{
cont1 = 0;
}



//SI DETECTA QUE HAY 3  CARROS LE ASIGNA A cont1 EL VALOR DE 3
if (val0 && val1 && val2 <= 350)
{
cont1 = 3;
}


//SI ES EL VALOR QUE ARROJA EL SENSOR ES MAYOR A 350 ENTONCES NO HAY CARRO Y SE LE DA EL VALOR DE 0 A cont1
if (val0 && val1 && val2 > 350)
{
cont1 = 0;
}




//LE ASIGNO EL VALOR QUE DA LA LECTURA DE LOS SENSORES A LAS VARIABLES DE LA LINEA 1
val8 = analogRead(8);
val9= analogRead(9);
val10 = analogRead(10);
valMulta2 = analogRead(4);




  
//SI DETECTA QUE HAY 1 SOLO CARRO LE ASIGNA A cont2 EL VALOR DE 1  
if (val8 <= 350 || val9 <= 350 || val10 <= 350)
{
cont2 = 1;
}


//SI ES EL VALOR QUE ARROJA EL SENSOR ES MAYOR A 350 ENTONCES NO HAY CARRO Y SE LE DA EL VALOR DE 0 A cont2
if (val8 > 350 || val9 > 350 || val10 > 350)
{
cont2 = 0;
}


//SI DETECTA QUE HAY 2 CARROS LE ASIGNA A cont2 EL VALOR DE 2
if (val8 && val9 <= 350 ||val8 && val10 <= 350 || val9 && val10 <= 350)
{
cont2 = 2;
}


//SI ES EL VALOR QUE ARROJA EL SENSOR ES MAYOR A 350 ENTONCES NO HAY CARRO Y SE LE DA EL VALOR DE 0 A cont2
if (val8 && val9 > 350 ||val8 && val10 > 350 || val9 && val10 > 350)
{
cont2 = 0;
}



//SI DETECTA QUE HAY 3  CARROS LE ASIGNA A cont2 EL VALOR DE 3
if (val8 && val9 && val10 <= 350)
{
cont2 = 3;
}


//SI ES EL VALOR QUE ARROJA EL SENSOR ES MAYOR A 350 ENTONCES NO HAY CARRO Y SE LE DA EL VALOR DE 0 A cont2
if (val8 && val9 && val10 > 350)
{
cont2 = 0;
}




//ACTIVANDO EL suiche2 SE ACTIVA EL FUNCIONAMIENTO DE 
 if(bitRead(PINC,suiche2)==HIGH)   
{
  
  //DICE CUANTOS CARROS HAY EN CADA LINEA
    Serial.print ( "Carros en al linea 1 :  ");

  Serial.println ( cont1);
  

  
      Serial.print ( "Carros en la linea 2 ");

    Serial.println (cont2);
    


  //SI EL cont1 ES MAYOR AL DOS QUIERE DECIR QUE HAY MAS CARROS EN LA LINEA 1 POR TANTO DA MAS TIEMPO EN VERDE A EL SEMAFORO 1 Y MAS TIEMPO EN ROJO A EL SEMAFORO 2
if (cont1 > cont2)
{
  Serial.println ("Hay mas carros en la calle del semaforo 1");
  delay (10);
  
  bitSet(PORTA,Verde1);          
        bitSet(PORTA,Rojo2);   
        delay(6000);
        
        bitClear(PORTA,Verde1);         
        bitClear(PORTA,Rojo2);        
        
        
      
    
  
                 
      
                
        bitSet(PORTA,Amarillo1);  
        bitSet (PORTA,Rojo2);
        delay(2000);                  
        bitClear(PORTA,Amarillo1); 
        bitClear(PORTA,Rojo2);   
  
   
   
        bitSet(PORTA,Rojo1); 
        bitSet(PORTA,Verde2);
        delay(3000);                  
        bitClear(PORTA,Rojo1); 
        bitClear (PORTA,Verde2);   
      
      
       bitSet(PORTA,Amarillo2);  
        bitSet (PORTA,Rojo1);
        delay(2000);                  
        bitClear(PORTA,Amarillo2); 
        bitClear(PORTA,Rojo1);   
  
}


// SI EL cont2 ES MAYOR QUIERE DECIR QUE HAY MAS CARROS EN LA LINEA 2 POR TANTO DA MAS TIEMPO EN VERDE A EL SEMAFORO 2 Y MAS TIEMPO EN ROJO A EL SEMAFORO 1
else if (cont2 > cont1)
{
  Serial.println ("Hay mas carros en la calle del semaforo 2");
    delay (10);
    
    
    bitSet(PORTA,Verde1);          
        bitSet(PORTA,Rojo2);   
        delay(3000);
        
        bitClear(PORTA,Verde1);         
        bitClear(PORTA,Rojo2);        
        
        
      
    
  
                 
      
                
        bitSet(PORTA,Amarillo1);  
        bitSet (PORTA,Rojo2);
        delay(2000);                  
        bitClear(PORTA,Amarillo1); 
        bitClear(PORTA,Rojo2);   
  
   
   
        bitSet(PORTA,Rojo1); 
        bitSet(PORTA,Verde2);
        delay(6000);                  
        bitClear(PORTA,Rojo1); 
        bitClear (PORTA,Verde2);   
      
      
       bitSet(PORTA,Amarillo2);  
        bitSet (PORTA,Rojo1);
        delay(2000);                  
        bitClear(PORTA,Amarillo2); 
        bitClear(PORTA,Rojo1);

  
  
  

}

// SI LOS DOS CONTADORES SON IGUALES QUIERE DECIR QUE HAY EL MISMO NUMERO DE CARROS EN AMBAS FILAS Y POR TANTO DA EL MISMO TIEMPO EN VERDE Y ROJO A LOS DOS SEMAFOROS
else if (cont1 == cont2)
{
  Serial.println ("Hay los mismos carros en los dos lados");
    delay (10);
    
    
    bitSet(PORTA,Verde1);          
        bitSet(PORTA,Rojo2);   
        delay(6000);
        
        bitClear(PORTA,Verde1);         
        bitClear(PORTA,Rojo2);        
        
        
      
    
  
                 
      
                
        bitSet(PORTA,Amarillo1);  
        bitSet (PORTA,Rojo2);
        delay(2000);                  
        bitClear(PORTA,Amarillo1); 
        bitClear(PORTA,Rojo2);   
  
   
   
        bitSet(PORTA,Rojo1); 
        bitSet(PORTA,Verde2);
        delay(6000);                  
        bitClear(PORTA,Rojo1); 
        bitClear (PORTA,Verde2);   
      
      
       bitSet(PORTA,Amarillo2);  
        bitSet (PORTA,Rojo1);
        delay(2000);                  
        bitClear(PORTA,Amarillo2); 
        bitClear(PORTA,Rojo1);  


}





  
  
  



    
 
  










}







 

}
