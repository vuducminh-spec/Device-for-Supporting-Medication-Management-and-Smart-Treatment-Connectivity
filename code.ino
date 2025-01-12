/*4X4     Arduin0
 * 2  -     A0
 * 3  -     A1
 * 4  -     A2
 * 5  -     A3
 * 6  -     7
 * 7  -     6
 * 8  -     5
 * 9  -     4
 * 
 * 
 * Nạp code mở Serial Monitor, chọn No line ending, baud 9600.

*/
#include <Keypad.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <Rtc_Pcf8563.h>
const int trigPin = 8;
const int echoPin = 9;
#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0; 
//init the real time clock
Rtc_Pcf8563 rtc;
LiquidCrystal_I2C lcd(0x27,20,4);  
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {7, 6, 5, 4}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {A0, A1, A2, A3}; //connect to the column pinouts of the keypad
int gio_ngan1,phut_ngan,gio_ngan2,phut_ngan2,gio_ngan3,phut_ngan3;
//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 
#include <SoftwareSerial.h>
#include <DFPlayer_Mini_Mp3.h>

SoftwareSerial mySerial(10, 11); // RX, TX
void setup(){
  Serial.begin(9600);
  mySerial.begin (9600);
  mp3_set_serial (mySerial);  //set softwareSerial for DFPlayer-mini mp3 module 
  mp3_set_volume (30);
  myservo.attach(13);
    lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
//  lcd.setCursor(3,0);
//  lcd.print("Hello, world!");
//  lcd.setCursor(2,1);
//  lcd.print("Ywrobot Arduino!");
//   lcd.setCursor(0,2);
//  lcd.print("Arduino LCM IIC 2004");
//   lcd.setCursor(2,3);
//  lcd.print(" ");
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.println("Date and Time function test.");
  //clear out the registers
  rtc.initClock();
  //set a time to start with.
  //day, weekday, month, century(1=1900, 0=2000), year(0-99)
//  rtc.setDate(18, 32, 5, 1, 10);
  //hr, min, sec
  rtc.setTime(17, 37, 0);
      lcd.setCursor(1,0);
    lcd.print("He thong nhac nho");
  //Serial.println("Date set to: Sunday(6) March(3) 14, 2010.  Time set to:  1:15:00 am.");
//  
//  Serial.println("Now reading back from chip.");
}
String chuoi_gioa,chuoi_phuta,chuoi_giob,chuoi_phutb,chuoi_gioc,chuoi_phutc; 
int kta,ktb,ktc;
int ha,pa,hb,pb,hc,pc;
void dieu_kien_A(char customKey)
{
     if(kta==2)
    {
    if(customKey=='D')
    {
      kta=0;
      pa = chuoi_phuta.toInt();
//      chuoi_phuta="";
      chuoi_phuta.remove(0);
      //Serial.println(pa);
            lcd.setCursor(2,0);
      lcd.print("Done:    ");
         myservo.write(130); 
            delay(500);
            myservo.write(90); 
      delay(1000);
      lcd.clear();
      }
      else
      {
    chuoi_phuta=chuoi_phuta+String(customKey);
    lcd.setCursor(2,0);
    lcd.print("phutA: ");
    lcd.print(chuoi_phuta);
      }
    }
    if(kta==1)
    {
    if(customKey=='#')
    {
      kta=2;
      ha=chuoi_gioa.toInt();
      chuoi_gioa.remove(0);
          lcd.setCursor(2,0);
    lcd.print("phutA:   ");
    //Serial.println(ha);
      }
      else
      {
    chuoi_gioa=chuoi_gioa+String(customKey);
    lcd.setCursor(2,0);
    lcd.print("GioA: ");
    lcd.print(chuoi_gioa);
      }
  }
    
    if(customKey=='A')
    {
      kta=1;
       myservo.write(30); 
            delay(500);
            myservo.write(90); 
      lcd.clear();
      lcd.setCursor(2,0);
    lcd.print("GioA:   ");
      }
  }
void dieu_kien_B(char customKey)
{
     if(ktb==2)
    {
    if(customKey=='D')
    {
      ktb=0;
      pb = chuoi_phutb.toInt();
       chuoi_phutb.remove(0);
      //Serial.println(pb);
      lcd.setCursor(2,0);
      lcd.print("Done:    ");
      delay(1000);
      lcd.clear();
      }
      else
      {
    chuoi_phutb=chuoi_phutb+String(customKey);
    lcd.setCursor(2,0);
    lcd.print("phutB: ");
    lcd.print(chuoi_phutb);
      }
    }
    if(ktb==1)
    {
    if(customKey=='#')
    {
      ktb=2;
      hb=chuoi_giob.toInt();
      chuoi_giob.remove(0);
          lcd.setCursor(2,0);
    lcd.print("phutB:   ");
    //Serial.println(hb);
      }
      else
      {
    chuoi_giob=chuoi_giob+String(customKey);
    lcd.setCursor(2,0);
    lcd.print("GioB: ");
    lcd.print(chuoi_giob);
      }
  }
    
    if(customKey=='B')
    {
      ktb=1;
      lcd.clear();
      lcd.setCursor(2,0);
    lcd.print("GioB:   ");
      }
  }
void dieu_kien_C(char customKey)
{
     if(ktc==2)
    {
    if(customKey=='D')
    {
      ktc=0;
            pc = chuoi_phutc.toInt();
            chuoi_phutc.remove(0);
      //Serial.println(pc);
      lcd.setCursor(2,0);
      lcd.print("Done: ");
      delay(1000);
      lcd.clear();
      }
      else
      {
    chuoi_phutc=chuoi_phutc+String(customKey);
    lcd.setCursor(2,0);
    lcd.print("phutC: ");
    lcd.print(chuoi_phutc);
      }
    }
    if(ktc==1)
    {
    if(customKey=='#')
    {
      ktc=2;
      hc=chuoi_gioc.toInt();
      chuoi_gioc.remove(0);
          lcd.setCursor(2,0);
    lcd.print("phutC:   ");
   // Serial.println(hc);
      }
      else
      {
    chuoi_gioc=chuoi_gioc+String(customKey);
    lcd.setCursor(2,0);
    lcd.print("GioC: ");
    lcd.print(chuoi_gioc);
      }
  }
    
    if(customKey=='C')
    {
      ktc=1;
      lcd.clear();
      lcd.setCursor(2,0);
    lcd.print("GioC:   ");
      }
  }
int readcm()
{
  long duration;
  int distance;
  
  // Phát xung siêu âm
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Đo thời gian sóng dội lại
  duration = pulseIn(echoPin, HIGH);
  
  // Tính toán khoảng cách (tốc độ âm thanh trong không khí khoảng 343m/s)
  distance = duration * 0.034 / 2;
  return distance;
  }
int tb;
void loop(){
    lcd.setCursor(0,1);
    lcd.print("Time: ");
    lcd.print(rtc.getHour());
    lcd.print(":");
    lcd.print(rtc.getMinute());
    lcd.print(":");
    lcd.print(rtc.getSecond());
    lcd.print(" ");
    lcd.setCursor(0,2);
    lcd.print("A: ");
    lcd.print(ha);
    lcd.print(":");
    lcd.print(pa);
      lcd.print(" ");
        lcd.print("B: ");
    lcd.print(hb);
    lcd.print(":");
    lcd.print(pb);
      lcd.print(" ");
      lcd.setCursor(0,3);
        lcd.print("C: ");
    lcd.print(hc);
    lcd.print(":");
    lcd.print(pc);
    lcd.print("  ");
    if(rtc.getMinute()==pa)
    {
    if(rtc.getHour()==ha&&rtc.getSecond()==0&&tb==0)
    {
   // Serial.println("uong_thuoc");
    mp3_next ();
    delay (1000);
//    myservo.write(130); 
//    delay(500);
//    myservo.write(90); 
    tb=1;
    }
    if(tb==1&&readcm()<15)
          {
            myservo.write(30); 
            delay(500);
            myservo.write(90); 
            Serial.println("*");
            delay(10000);
            myservo.write(130); 
            delay(500);
            myservo.write(90); 
            tb=0;
            }
      }
      else 
      {
        if(tb==1&&rtc.getSecond()==0)
        {
          //Serial.println("uong_thuoc");
          mp3_next ();
          delay (1000);
          }
          if(tb==1&&readcm()<15)
          {
            myservo.write(30); 
            delay(500);
            myservo.write(90); 
            Serial.println("*");
            delay(10000);
            myservo.write(130); 
            delay(500);
            myservo.write(90);  
            tb=0;
            }
        }
   if(kta==0&&ktb==0&&ktc==0)
   {
          lcd.setCursor(1,0);
    lcd.print("He thong nhac nho");
    }
  char customKey = customKeypad.getKey();
  if (customKey){
    dieu_kien_A(customKey);
    dieu_kien_B(customKey);
    dieu_kien_C(customKey);
//    Serial.println(customKey);
//    Serial.println("nhan");
  }
}
