
int AsciiCod= 0; // LO QUE SE ENVIA AL SERIAL
int ValPin=0; // VALOR DE EL PIN

//SE DEFINE CADA SUICHE Y LED
#define suiche PINC,0
#define V PORTA,0
#define A PORTA,1
#define R PORTA,2
#define v PORTA,3
#define a PORTA,4
#define r PORTA,5

void setup(){
  Serial.begin(9600);
  //SE DEFINE ENTRADAS Y SALIDAS 
  DDRA=B11111111;
  DDRC=B00000000;
  //SE IMPRIMEN ESTAS INSTRUCCIONES EN EL SERIAL
  Serial.println("(v)     Led verde 1");
  Serial.println("(a)     Led amarillo 1");
  Serial.println("(r)     Led  Rojo 1");
  Serial.println("(V)     Led  verde 2");
  Serial.println("(A)     Led  amarillo 2");
  Serial.println("(R)     Led  Rojo 2");
  Serial.println("(x) o (X)   apagar todo");
}

void loop(){
  //SI suiche ESTA APAGADO
 if(bitRead(PINC,suiche)==LOW) 
 {
   
  if (Serial.available()>0){
    //LEE LO QUE SE INGRESA AL SERIAL
    AsciiCod = Serial.read();
  }
  if(AsciiCod=='x'){
    //LLAMA EL MOTODO ApagarTodo()
    ApagarTodo();
  }
   if(AsciiCod=='X'){
     //LLAMA EL METODO ApagarTodo()
    ApagarTodo();
  }

  if(AsciiCod=='v' || AsciiCod=='a' || AsciiCod=='r' || AsciiCod=='V' || AsciiCod=='A' || AsciiCod=='R'){
    //LLAMA TestSalidas()
    TestSalidas();
  }
 }
 else //SI suiche ESTA ACTIVADO 
 {
   if (Serial.available()>0){
    AsciiCod = Serial.read();
  }
  if(AsciiCod=='x'){
    //LLAMA EL METODO ApagarTodo()
    ApagarTodo();
  }
   if(AsciiCod=='X'){
     //LLAMA EL METODO ApagarTodo()
    ApagarTodo();
  }
  
  
  if(AsciiCod=='v' || AsciiCod=='a' || AsciiCod=='r' || AsciiCod=='V' || AsciiCod=='A' || AsciiCod=='R'){
    //LLAMA EL METODO TestSalidas2()
    TestSalidas2();
  }  
 }
}

void ApagarTodo(){ //APAGA TODO
  bitClear(PORTA,V);
  bitClear(PORTA,A);
  bitClear(PORTA,R);
  bitClear(PORTA,v);
  bitClear(PORTA,a);
  bitClear(PORTA,r);
  Serial.println("Proceso detenido");
  AsciiCod=0;
}



void TestSalidas(){ //PRENDE INDEPENDIENTE MENTE CADA LED (SOLO DEJA PRENDER 1 POR SEMAFORO)
  if(AsciiCod=='v'){
    bitSet(PORTA,V);
    Serial.println("Verde Semaforo 1 ON");
    bitClear (PORTA,A);
    bitClear (PORTA,R);
   
  }

  if(AsciiCod=='a'){
    bitSet(PORTA,A);
    Serial.println("Amarillo Semaforo 1 ON");
    bitClear (PORTA,V);
    bitClear (PORTA,R);
  }

  if(AsciiCod=='r'){
    bitSet(PORTA,R);
    Serial.println("Rojo Semaforo 1 ON");
    bitClear (PORTA,A);
    bitClear (PORTA,V);
  }

  if(AsciiCod=='V'){
    bitSet(PORTA,v);
    Serial.println("Verde Semaforo 2 ON");
    bitClear (PORTA,a);
    bitClear (PORTA,r);
  }

  if(AsciiCod=='A'){
    bitSet(PORTA,a);
    Serial.println("Amarillo Semaforo 2 ON");
    bitClear (PORTA,v);
    bitClear (PORTA,r);
  }

  if(AsciiCod=='R'){ 
    bitSet(PORTA,r);
    Serial.println("Rojo Semaforo 2 ON");
    bitClear (PORTA,v);
    bitClear (PORTA,a);
  }
  
  AsciiCod=0;
}


void TestSalidas2(){ //PRENDE LOS LEDS DE MANERA SINCRONIZADA (PRENDE UN LED EN UN SEMAFORO Y SU CONTRARIO EN EL OTRO)
  if(AsciiCod=='v'){
    bitSet(PORTA,V);
    bitSet (PORTA,r);
    Serial.println("Verde Semaforo 1 ON");
    bitClear (PORTA,A);
    bitClear (PORTA,R);
    bitClear (PORTA,a);
    bitClear (PORTA,v);
   
  }

  if(AsciiCod=='a'){
    bitSet(PORTA,A);
    bitSet(PORTA,r);
    Serial.println("Amarillo Semaforo 1 ON");
    bitClear (PORTA,V);
    bitClear (PORTA,R);
    bitClear (PORTA,v);
    bitClear (PORTA,a);
  }

  if(AsciiCod=='r'){
    bitSet(PORTA,R);
    bitSet (PORTA,v);
    Serial.println("Rojo Semaforo 1 ON");
    bitClear (PORTA,A);
    bitClear (PORTA,V);
    bitClear (PORTA,r);
    bitClear (PORTA,a);
  }

  if(AsciiCod=='V'){
    bitSet(PORTA,v);
    bitSet (PORTA,R);
    Serial.println("Verde Semaforo 2 ON");
    bitClear (PORTA,a);
    bitClear (PORTA,r);
    bitClear (PORTA,V);
    bitClear (PORTA,A);
  }

  if(AsciiCod=='A'){
    bitSet(PORTA,a);
    bitSet(PORTA,R);
    Serial.println("Amarillo Semaforo 2 ON");
    bitClear (PORTA,v);
    bitClear (PORTA,r);
    bitClear (PORTA,R);
    bitClear (PORTA,V);
  }

  if(AsciiCod=='R'){
    bitSet(PORTA,r);
    bitSet (PORTA,V);
    Serial.println("Rojo Semaforo 2 ON");
    bitClear (PORTA,v);
    bitClear (PORTA,a);
    bitClear (PORTA,A);
    bitClear (PORTA,R);
  }
  
  AsciiCod=0;
}

