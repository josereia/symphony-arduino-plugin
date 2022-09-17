#include <Arduino.h>
#include <IRremote.hpp>

//ir codes
#define IR_BPLUS 0xF700FF //
#define IR_BMINUS 0xF7807F //
#define IR_OFF 0xF740BF //
#define IR_ON 0xF7C03F //
#define IR_R 0xF720DF //
#define IR_G 0xF7A05F //
#define IR_B 0xF7609F //
#define IR_W 0xF7E01F //
#define IR_B1 0xF710EF //
#define IR_B2 0xF7906F //
#define IR_B3 0xF750AF //
#define IR_FLASH 0xF7D02F //
#define IR_B4 0xF730CF //
#define IR_B5 0xF7B04F //
#define IR_B6 0xF7708F //
#define IR_STROBE 0xF7F00F //
#define IR_B7 0xF708F7 //
#define IR_B8 0xF78877 //
#define IR_B9 0xF748B7 //
#define IR_FADE 0xF7C837 //
#define IR_B10 0xF728D7 //
#define IR_B11 0xF7A857 //
#define IR_B12 0xF76897 //
#define IR_SMOOTH 0xF7E817 //

#define IR_SENDER_PIN 3
#define COLORS_QTD 17

IRsend irsend;
int colors[COLORS_QTD][3] = {
  {255, 0, 0}, //vermelho
  {255, 130, 0}, //vermelho1
  {255, 200, 0}, //vermelho2
  {255, 230, 0}, //vermelho3
  {255, 255, 0}, //vermelho4
  {0, 255, 0}, //verde
  {0, 255, 200}, //verde1
  {0, 255, 230}, //verde2
  {0, 239, 255}, //verde3
  {0, 200, 255}, //verde4
  {0, 0, 255}, //azul
  {120, 0, 255}, //azul1
  {200, 0, 255}, //azul2
  {240, 0, 255}, //azul3
  {255, 0, 180}, //azul4
  {255, 255, 255}, //branco
  {240, 176, 200}
};


void sendIRCode(String color) {
  Serial.println(color);
  if (color == "255,0,0") { //vermelho
    irsend.sendNEC(IR_R, 32);
  } else if (color == "255,130,0") { //vermelho1
    irsend.sendNEC(IR_B1, 32);
  } else if (color == "255,200,0") { //vermelho2
    irsend.sendNEC(IR_B4, 32);
  } else if (color == "255,230,0") { //vermelho3
    irsend.sendNEC(IR_B7, 32);
  } else if (color == "255,255,0") { //vermelho4
    irsend.sendNEC(IR_B10, 32);
  } else if (color == "0,255,0") { //verde
    irsend.sendNEC(IR_G, 32);
  } else if (color == "0,255,200") { //verde1
    irsend.sendNEC(IR_B2, 32);
  } else if (color == "0,255,230") { //verde2
    irsend.sendNEC(IR_B5, 32);
  } else if (color == "0,239,255") { //verde3
    irsend.sendNEC(IR_B8, 32);
  } else if (color == "0,200,255") { //verde4
    irsend.sendNEC(IR_B11, 32);
  } else if (color == "0,0,255") { //azul
    irsend.sendNEC(IR_B, 32);
  } else if (color == "120,0,255") { //azul1
    irsend.sendNEC(IR_B3, 32);
  } else if (color == "200,0,255") { //azul2
    irsend.sendNEC(IR_B6, 32);
  } else if (color == "240,0,255") { //azul3
    irsend.sendNEC(IR_B9, 32);
  } else if (color == "255,0,180") { //azul4
    irsend.sendNEC(IR_B12, 32);
  } else if (color == "255,255,255") { //branco
    irsend.sendNEC(IR_W, 32);
  } else if (color == "240,176,200") {
    irsend.sendNEC(IR_B12, 32);
  } else {
    irsend.sendNEC(IR_W, 32);
  }
}

String toString(int arr[3]) {
  String color = "";
  for (int i = 0; i < 3; i++) {
    String str = String(arr[i]);
    color += str;

    if (i < 2) {
      color += ",";
    }
  };

  return color;
}

int *toArray(char delimiter[], String test) {
  int i;
  char *p;
  char string[128];
  static int array[3];

  test.toCharArray(string, sizeof(string));
  i = 0;
  p = strtok(string, delimiter);
  while (p && i < 3)
  {
    array[i] = atoi(p);
    p = strtok(NULL, delimiter);
    ++i;
  }

  return array;
}

void calculateRgbDistance(int colorToAnalyze[3]) {
  int color[3] = {0, 0, 0};
  double a = 0;
  double b = 0;

  for (int i = 0; i < COLORS_QTD; i++) {
    a = sqrt(pow((colorToAnalyze[0] - colors[i][0]), 2) + pow((colorToAnalyze[1] - colors[i][1]), 2) + pow((colorToAnalyze[2] - colors[i][2]), 2));
    b = sqrt(pow((colorToAnalyze[0] - colors[i + 1][0]), 2) + pow((colorToAnalyze[1] - colors[i + 1][1]), 2) + pow((colorToAnalyze[2] - colors[i + 1][2]), 2));


    if ((b-a) < -1) {
      Serial.println(toString(colors[i]));
      color[0] = colors[i][0];
      color[1] = colors[i][1];
      color[2] = colors[i][2];
    }


  };
  //sendIRCode(toString(color));
}

void setup()
{
  Serial.begin(9600);
  irsend.begin(IR_SENDER_PIN, true);
}

void loop()
{
  if (Serial.available()) {
    String serialRead = Serial.readString();
    calculateRgbDistance(toArray(",", serialRead));
  }
}
