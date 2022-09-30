#include <Arduino.h>
#include <IRremote.hpp>

//ir codes
#define IR_BPLUS 0xF700FF   //
#define IR_BMINUS 0xF7807F  //
#define IR_OFF 0xF740BF     //
#define IR_ON 0xF7C03F      //
#define IR_R 0xF720DF       //
#define IR_G 0xF7A05F       //
#define IR_B 0xF7609F       //
#define IR_W 0xF7E01F       //
#define IR_B1 0xF710EF      //
#define IR_B2 0xF7906F      //
#define IR_B3 0xF750AF      //
#define IR_FLASH 0xF7D02F   //
#define IR_B4 0xF730CF      //
#define IR_B5 0xF7B04F      //
#define IR_B6 0xF7708F      //
#define IR_STROBE 0xF7F00F  //
#define IR_B7 0xF708F7      //
#define IR_B8 0xF78877      //
#define IR_B9 0xF748B7      //
#define IR_FADE 0xF7C837    //
#define IR_B10 0xF728D7     //
#define IR_B11 0xF7A857     //
#define IR_B12 0xF76897     //
#define IR_SMOOTH 0xF7E817  //

#define IR_SENDER_PIN 3
#define COLORS_QTD 17

IRsend irsend;

void sendIRCode(String color) {
  Serial.println(color);
  if (color == "255,0,0") {  //vermelho
    irsend.sendNEC(IR_R, 32);
  } else if (color == "255,130,0") {  //vermelho1
    irsend.sendNEC(IR_B1, 32);
  } else if (color == "255,200,0") {  //vermelho2
    irsend.sendNEC(IR_B4, 32);
  } else if (color == "255,230,0") {  //vermelho3
    irsend.sendNEC(IR_B7, 32);
  } else if (color == "255,255,0") {  //vermelho4
    irsend.sendNEC(IR_B10, 32);
  } else if (color == "0,255,0") {  //verde
    irsend.sendNEC(IR_G, 32);
  } else if (color == "0,255,200") {  //verde1
    irsend.sendNEC(IR_B2, 32);
  } else if (color == "0,255,230") {  //verde2
    irsend.sendNEC(IR_B5, 32);
  } else if (color == "0,239,255") {  //verde3
    irsend.sendNEC(IR_B8, 32);
  } else if (color == "0,200,255") {  //verde4
    irsend.sendNEC(IR_B11, 32);
  } else if (color == "0,0,255") {  //azul
    irsend.sendNEC(IR_B, 32);
  } else if (color == "120,0,255") {  //azul1
    irsend.sendNEC(IR_B3, 32);
  } else if (color == "200,0,255") {  //azul2
    irsend.sendNEC(IR_B6, 32);
  } else if (color == "240,0,255") {  //azul3
    irsend.sendNEC(IR_B9, 32);
  } else if (color == "255,0,180") {  //azul4
    irsend.sendNEC(IR_B12, 32);
  } else if (color == "255,255,255") { //branco
    irsend.sendNEC(IR_W, 32);
  }
}

void setup() {
  Serial.begin(9600);
  irsend.begin(IR_SENDER_PIN, true);
}

void loop() {
  if (Serial.available()) {
    String serialRead = Serial.readString();
    sendIRCode(serialRead);
  }
}