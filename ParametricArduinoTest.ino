#include<Keyboard.h>
//#include <string>

int retardof11 = 10000;
int retardoms = 10;
String datoRecibido = "";

void tab(int cantidadtabs, int cantidadtabs2 = 0){
  for(int j = 0; j<cantidadtabs; j++){
    Keyboard.press(KEY_TAB);
    Keyboard.release(KEY_TAB);
    delay(retardoms);
  }
  Keyboard.print(" ");
  delay(retardoms);
  if(cantidadtabs2 != 0){
    for(int j = 0; j<cantidadtabs2; j++){
      Keyboard.press(KEY_TAB);
      Keyboard.release(KEY_TAB);
      delay(retardoms);
    }
    Keyboard.print(" ");
    delay(retardoms);

    Keyboard.press(KEY_F11);
    Keyboard.release(KEY_F11);
    delay(retardof11);
  

    reverseTabs(cantidadtabs2);
    reverseTabs(cantidadtabs);
  }else
  {
    Keyboard.press(KEY_F11);
    Keyboard.release(KEY_F11);
    delay(retardof11);
  
    reverseTabs(cantidadtabs);
  }
  
    
};




void reverseTabs(int cantidadtabs){
  Keyboard.print(" ");
  Keyboard.press(KEY_LEFT_SHIFT);
  for(int j = 0; j<cantidadtabs; j++){
      Keyboard.press(KEY_TAB);
      Keyboard.release(KEY_TAB);
      delay(retardoms);
    };
  Keyboard.release(KEY_LEFT_SHIFT);
  }


void singleTest(int imagen){
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.release(KEY_LEFT_ALT);
  delay(retardoms);
  Keyboard.press(KEY_DOWN_ARROW);
  Keyboard.release(KEY_DOWN_ARROW);
  delay(retardoms);
  Keyboard.print("e");
  for(int i = 0; i<imagen; i++){
    Keyboard.print("e");
  }
  delay(retardoms);
  Keyboard.press(KEY_RETURN);
  Keyboard.release(KEY_RETURN);
};

void testPlan(){
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.release(KEY_LEFT_ALT);
  delay(retardoms);
  Keyboard.press(KEY_DOWN_ARROW);
  Keyboard.release(KEY_DOWN_ARROW);
  delay(retardoms);
  Keyboard.print("s");
};


void setup() {
 Serial1.begin(9600);
}

void loop(){

  if(Serial1.available()){                                          

    int singleTestImg;

    datoRecibido = Serial1.readString();
    datoRecibido.trim();

    Serial1.flush();

    if(datoRecibido == "0001" || datoRecibido == "0010" || datoRecibido == "0100" || datoRecibido == "1000"){
      singleTestImg = datoRecibido.indexOf("1") + 1;
      singleTest(singleTestImg);
      
    }
    if(datoRecibido == "0011"){
      tab(15, 2);
    }
    
    if(datoRecibido == "0110"){
      tab(5, 12);
    }

    if(datoRecibido == "1100"){
      tab(5, 2);
    }

    if(datoRecibido == "1001"){
      tab(10, 2);
    }

    if(datoRecibido == "1010"){
      tab(5, 7);
    }

    if(datoRecibido == "0101"){
      tab(10, 7);
    }

    if(datoRecibido == "0111"){
      tab(20);
    }
    
    if(datoRecibido == "1110"){
      tab(5);
    }

    if(datoRecibido == "1101"){
      tab(10);
    }

    if(datoRecibido == "1011"){
      tab(15);
    }

    if(datoRecibido == "1111"){
        Keyboard.press(KEY_F11);
        Keyboard.release(KEY_F11);
    }

    if(datoRecibido == "OK"){
      Keyboard.press(KEY_RETURN);
      Keyboard.release(KEY_RETURN);
      
    }

    if(datoRecibido == "TESTPLAN"){
      testPlan();
    }

    if(datoRecibido == "DOWN"){
      Keyboard.press(KEY_DOWN_ARROW);
      Keyboard.release(KEY_DOWN_ARROW);
    }

    if(datoRecibido == "UP"){
      Keyboard.press(KEY_UP_ARROW);
      Keyboard.release(KEY_UP_ARROW);
    }

    if(datoRecibido == "LEFT"){
      Keyboard.press(KEY_LEFT_ARROW);
      Keyboard.release(KEY_LEFT_ARROW);
    }

    if(datoRecibido == "RIGHT"){
      Keyboard.press(KEY_RIGHT_ARROW);
      Keyboard.release(KEY_RIGHT_ARROW);
    }

    if(datoRecibido == "CERRAR"){
      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.press(KEY_F4);
      delay(retardoms);

      Keyboard.release(KEY_F4);
      Keyboard.release(KEY_LEFT_ALT);
    }

    if(datoRecibido == "TAB"){
      Keyboard.press(KEY_TAB);
      Keyboard.release(KEY_TAB);
    }

    if(datoRecibido == "ESPACIO"){
      Keyboard.print(" ");
    }
  }

};
                                 
