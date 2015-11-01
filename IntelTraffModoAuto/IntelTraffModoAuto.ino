
  //DEFINO TODOS LOS SUICHES Y LEDS QUE VOY A USAR
  #define suiche PINC,0             
  #define Verde1 PORTA,0             
  #define Amarillo1 PORTA,1             
  #define Rojo1 PORTA,2      
  #define Verde2 PORTA,3             
  #define Amarillo2 PORTA,4            
  #define Rojo2 PORTA,5  
  
  void setup()
    {
      
      //DEFINO LAS ENTRADAS Y SALIDAS 
      DDRA=B00111111;               
      DDRC=B00000000;                
      Serial.begin(9600);
    }
    
  void loop()                    
    {
      //SI suiche ESTA APAGADO HACE LO SIGUIENTE
    if(bitRead(PINC,suiche)==LOW)    
      {
        
        bitSet(PORTA,Verde1);          
        bitSet(PORTA,Rojo2);   
        delay(5000);
        
        bitClear(PORTA,Verde1);         
        bitClear(PORTA,Rojo2);        
        
        
      
    
  
                 
      
                
        bitSet(PORTA,Amarillo1);  
        bitSet (PORTA,Rojo2);
        delay(2000);                  
        bitClear(PORTA,Amarillo1); 
        bitClear(PORTA,Rojo2);   
  
   
   
        bitSet(PORTA,Rojo1); 
        bitSet(PORTA,Verde2);
        delay(5000);                  
        bitClear(PORTA,Rojo1); 
        bitClear (PORTA,Verde2);   
      
      
       bitSet(PORTA,Amarillo2);  
        bitSet (PORTA,Rojo1);
        delay(2000);                  
        bitClear(PORTA,Amarillo2); 
        bitClear(PORTA,Rojo1);   
        
        
      }
      
      else
      {  
        bitSet(PORTA,Amarillo1);   
        bitSet (PORTA,Amarillo2);
        
        delay(250);                  
        bitClear(PORTA,Amarillo1);          
                          
        bitClear(PORTA,Amarillo2);          
      }
    }

