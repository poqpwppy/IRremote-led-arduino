#include <IRremote.h>

const int remote = 10;
IRrecv recv(remote);
decode_results nhan;

const int a = 8;  //For displaying segment "a"
const int b = 9;  //For displaying segment "b"
const int c = 4;  //For displaying segment "c"
const int d = 5;  //For displaying segment "d"
const int e = 6;  //For displaying segment "e"
const int f = 2;  //For displaying segment "f"
const int g = 3;  //For displaying segment "g"

int dem = 0;

unsigned long key_value = 0;

void setup() {
  recv.enableIRIn();
  pinMode(a, OUTPUT);  //A
  pinMode(b, OUTPUT);  //B
  pinMode(c, OUTPUT);  //C
  pinMode(d, OUTPUT);  //D
  pinMode(e, OUTPUT);  //E
  pinMode(f, OUTPUT);  //F
  pinMode(g, OUTPUT);  //G
  
  Serial.begin(9600);
  
  displayDigit(dem);
  
}

void loop() {
  if(recv.decode(&nhan)) {
    if (nhan.value == 0XFFFFFFFF)
          nhan.value = key_value;

    switch(nhan.value) {
      case 0xFFE01F:
          dem--;
          if(dem<0) dem = 9;
          turnOff();
          displayDigit(dem);
          break ;
      case 0xFFA857:
          dem++;
          if(dem>9) dem = 0;
          turnOff();
          displayDigit(dem);
          break ;
      case 0xFF6897:
          dem = 0;
          turnOff();
          displayDigit(dem);
          break ;
      case 0xFF30CF:
          dem = 1;
          turnOff();
          displayDigit(dem);
          break ;
      case 0xFF18E7:
          dem = 2;
          turnOff();
          displayDigit(dem);
          break ;
      case 0xFF7A85:
          dem = 3;
          turnOff();
          displayDigit(dem);
          break ;
      case 0xFF10EF:
          dem = 4;
          turnOff();
          displayDigit(dem);
          break ;
      case 0xFF38C7:
          dem = 5;
          turnOff();
          displayDigit(dem);
          break ;
      case 0xFF5AA5:
          dem = 6;
          turnOff();
          displayDigit(dem);
          break ;
      case 0xFF42BD:
          dem = 7;
          turnOff();
          displayDigit(dem);
          break ;
      case 0xFF4AB5:
          dem = 8;
          turnOff();
          displayDigit(dem);
          break ;
      case 0xFF52AD:
          dem = 9;
          turnOff();
          displayDigit(dem);
          break ;
    }
    key_value = nhan.value;
    recv.resume();
  }
}

void displayDigit(int digit)
{
 //Conditions for displaying segment a
 if(digit!=1 && digit != 4)
 digitalWrite(a,HIGH);

 //Conditions for displaying segment b
 if(digit != 5 && digit != 6)
 digitalWrite(b,HIGH);

 //Conditions for displaying segment c
 if(digit !=2)
 digitalWrite(c,HIGH);

 //Conditions for displaying segment d
 if(digit != 1 && digit !=4 && digit !=7)
 digitalWrite(d,HIGH);

 //Conditions for displaying segment e 
 if(digit == 2 || digit ==6 || digit == 8 || digit==0)
 digitalWrite(e,HIGH);

 //Conditions for displaying segment f
 if(digit != 1 && digit !=2 && digit!=3 && digit !=7)
 digitalWrite(f,HIGH);
 if (digit!=0 && digit!=1 && digit !=7)
 digitalWrite(g,HIGH);

}
void turnOff()
{
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,LOW);
  digitalWrite(e,LOW);
  digitalWrite(f,LOW);
  digitalWrite(g,LOW);
}
