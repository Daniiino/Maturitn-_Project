/*
* Created by ArduinoGetStarted.com
*
* This example code is in the public domain
*
* Tutorial page: https://arduinogetstarted.com/tutorials/arduino-keypad-lcd
*/
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
#define REST      0
// change this to make the song slower or faster
int tempo = 120;
// notes of the moledy followed by the duration.
// a 4 means a quarter note, 8 an eighteenth , 16 sixteenth, so on
// !!negative numbers are used to represent dotted notes,
// so -4 means a dotted quarter note, that is, a quarter plus an eighteenth!!
int melody[] = {
  
  // Dart Vader theme (Imperial March) - Star wars 
  // Score available at https://musescore.com/user/202909/scores/1141521
  // The tenor saxophone part was used
  
 NOTE_A4,-4, NOTE_A4,-4, NOTE_A4,16, NOTE_A4,16, NOTE_A4,16, NOTE_A4,16, NOTE_F4,8, REST,8,
  NOTE_A4,-4, NOTE_A4,-4, NOTE_A4,16, NOTE_A4,16, NOTE_A4,16, NOTE_A4,16, NOTE_F4,8, REST,8,
  NOTE_A4,4, NOTE_A4,4, NOTE_A4,4, NOTE_F4,-8, NOTE_C5,16,

  NOTE_A4,4, NOTE_F4,-8, NOTE_C5,16, NOTE_A4,2,//4
  NOTE_E5,4, NOTE_E5,4, NOTE_E5,4, NOTE_F5,-8, NOTE_C5,16,
  NOTE_A4,4, NOTE_F4,-8, NOTE_C5,16, NOTE_A4,2,
  
  NOTE_A5,4, NOTE_A4,-8, NOTE_A4,16, NOTE_A5,4, NOTE_GS5,-8, NOTE_G5,16, //7 
  NOTE_DS5,16, NOTE_D5,16, NOTE_DS5,8, REST,8, NOTE_A4,8, NOTE_DS5,4, NOTE_D5,-8, NOTE_CS5,16,

  NOTE_C5,16, NOTE_B4,16, NOTE_C5,16, REST,8, NOTE_F4,8, NOTE_GS4,4, NOTE_F4,-8, NOTE_A4,-16,//9
  NOTE_C5,4, NOTE_A4,-8, NOTE_C5,16, NOTE_E5,2,

  NOTE_A5,4, NOTE_A4,-8, NOTE_A4,16, NOTE_A5,4, NOTE_GS5,-8, NOTE_G5,16, //7 
  NOTE_DS5,16, NOTE_D5,16, NOTE_DS5,8, REST,8, NOTE_A4,8, NOTE_DS5,4, NOTE_D5,-8, NOTE_CS5,16,

  NOTE_C5,16, NOTE_B4,16, NOTE_C5,16, REST,8, NOTE_F4,8, NOTE_GS4,4, NOTE_F4,-8, NOTE_A4,-16,//9
  NOTE_A4,4, NOTE_F4,-8, NOTE_C5,16, NOTE_A4,2,
  
};

// sizeof gives the number of bytes, each int value is composed of two bytes (16 bits)
// there are two values per note (pitch and duration), so for each note there are four bytes
int notes = sizeof(melody) / sizeof(melody[0]) / 2;
// this calculates the duration of a whole note in ms
int wholenote = (60000 * 4) / tempo;
int divider = 0, noteDuration = 0;
int buzzer = 17;
#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
bool stav = 0;
#define VIBRATION_PIN 14
int inputPin = 15;               // choose the input pin (for PIR sensor)
int pirState = LOW;             // we start, assuming no motion detected
int val = 0;                    // variable for reading the pin status
const int cidloPin = 2;
int InfraPin=22;
int pinOut = 3;
int PinPoplach = 0;
int zaply = 0;
const int ROW_NUM    = 4; // four rows
const int COLUMN_NUM = 3; // four columns
String q = "0";
int s = 0;
int c = 1;
int alarm = 0;
int Radek = 0;
int Start = 0;
String PIN [4] = {"1","2","3","4"};
String KOD [4] ={"0","0","0","0"};
char keys[ROW_NUM][COLUMN_NUM] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
char Cislo[4]{'1','2','3','4'};
byte pin_rows[ROW_NUM] = {3, 4, 5, 6};      // connect to the row pinouts of the keypad
byte pin_column[COLUMN_NUM] = {7, 8, 9}; // connect to the column pinouts of the keypad
Keypad keypad = Keypad(makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM );
LiquidCrystal_I2C lcd(0x27, 20, 4); // I2C address 0x27, 16 column and 2 rows
int cursorColumn = 10;

 



void setup(){
  Serial.begin(9600);  
  pinMode(cidloPin, INPUT);
  pinMode(inputPin, INPUT);     // declare sensor as input
  // nastavení přerušení na pin 2 (int0) 
  // při rostoucí hraně (logO->log1) se vykoná program prerus 
  attachInterrupt(0, Detekce, RISING);
  pinMode(pinOut, INPUT);
  pinMode(VIBRATION_PIN, INPUT);
  lcd.begin(); // initialize the lcd
  lcd.backlight();

}

 







void loop(){
  Menu();
 if(zaply == 0){
   pinMode(cidloPin, INPUT);
  // nastavení přerušení na pin 2 (int0) 
  // při rostoucí hraně (logO->log1) se vykoná program prerus 

  attachInterrupt(0, Detekce, RISING);
  if(stav == 0){
  stav = !(digitalRead(pinOut));
    if(stav == 1){
      //sysout na stránky
      stav = 0;
      }
  }
 }
ZadaniPinu();
if (zaply == 1){
  if(Start == 1){
  lcd.print("---Uspesnee---");
  lcd.setCursor(0,1);
  lcd.print("---spusteno---");
  delay(1500);
  lcd.clear();
  Start++;
  }
  Infra();
  Vibrace();
  PIR();
  }
}















// Metody 
void Infra(){
   // načtení informací ze všech vstupních pinů
  // Serial.print("Stav vstupnich pinu: ");
    // jednobitová proměnná pro uložení stavu
    bool stav;
    // načtení stavu aktuálního pinu, nutná
    // negace, protože modul vrací 0 při detekci
    stav = !(digitalRead(InfraPin));
     //lcd.print(stav);
     if(stav == 1){
      Detekce();
      Poplach();
    //Serial.print("  ");
  // ukončení řádku na sériové lince
   //Serial.println();
} 
  }
void Vibrace(){
  if (!digitalRead(VIBRATION_PIN)) {
 //Serial.println(digitalRead(VIBRATION_PIN));
 Detekce();
 Poplach();
 }
  }
void Detekce() {
  // pokud je aktivován digitální vstup,
  // vypiš informaci po sériové lince
  lcd.print("Zaznamenan Pohyb");
  delay(2000);
  lcd.clear();
}
void clearKod(){
  KOD[0] = "0";
  KOD[1] = "0";
  KOD[2] = "0";
  KOD[3] = "0";
  s = 0;
  c = 0;
  Radek = 0;
}

void clearAlarm(){
  alarm = 0;
}

void Poplach(){
  clearAlarm();
// Zapnout Ledky
  
  lcd.print("Pro deaktivaci");
  lcd.setCursor(0,1);
  lcd.print("Zadej PIN:"); 
  Radek++;
       for(int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {
  ZadaniPinu();
    // calculates the duration of each note
    divider = melody[thisNote + 1];
    if (divider > 0) {
      // regular note, just proceed
      noteDuration = (wholenote) / divider;
    } else if (divider < 0) {
      // dotted notes are represented with negative durations!!
      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5; // increases the duration in half for dotted notes
    }

    if(alarm == 1){
      break;
    }else{
    // we only play the note for 90% of the duration, leaving 10% as a pause
    tone(buzzer, melody[thisNote], noteDuration*0.9);

    // Wait for the specief duration before playing the next note.
    delay(noteDuration);
    // stop the waveform generation before the next note.
    noTone(buzzer);
       }
  }
  clearAlarm();
 
  
}
void Menu(){
 if(Start == 0){
 lcd.setCursor(2,0);
 lcd.print("Zabezpecovaci"); 
 lcd.setCursor(2,1);
 lcd.print("---System---"); 
 delay(2500);
 lcd.clear();
 lcd.print("Zadej PIN:"); 
 Start++; 
 }
}
void PIR(){
  val = digitalRead(inputPin);  // read input value
  if (val == HIGH){   // check if the input is HIGH      
    if (pirState == LOW){
      pirState = HIGH;
      Detekce();
      Poplach();
    }
  } 
  else {
    if (pirState == HIGH){
     // Serial.println("Motion ended!");  // print on output change
      pirState = LOW;
    }
  }
}
void ZadaniPinu(){
  char pismeno = keypad.getKey();
  if (pismeno) {
   if(s < 4){
    q = pismeno;
    KOD[s] = q;
    lcd.setCursor(c, 1);
    //lcd.print(KOD[s]);
    s++;
    c++;
     }
    lcd.setCursor(cursorColumn, Radek); // move cursor to   (cursorColumn, 0)
    lcd.print("*"); 
    
    cursorColumn++;                 // move cursor to next position
                                    // if reaching limit, clear LCD
  }

    if(cursorColumn == 14) {       
    if(KOD[0]==PIN[0] && KOD[1] == PIN[1] && KOD[2] == PIN[2] && KOD[3] == PIN[3]){
            lcd.clear();
            cursorColumn = 0;
            lcd.print("Pin je spravny");
            alarm++;
            delay(2000);
            lcd.clear();
            cursorColumn = 10;
            clearKod();
            zaply = 1;
            if(Radek==1){
              tone(buzzer,261,250);
              tone(buzzer,349,250);
              }
            //lcd.print(zaply);
            }else{
              lcd.clear();
              cursorColumn = 0;
              lcd.print("Pin neni spravny");
               tone(buzzer,349,250);
               tone(buzzer,523,250);
              delay(2000);
              lcd.clear();
              cursorColumn = 10;
              if(Radek==1){
                lcd.print("Pro deaktivaci");
                lcd.setCursor(0,1);
                lcd.print("Zadej PIN:"); 
                }else{
              lcd.print("Zadej PIN:");
                } 
              clearKod();
              }
             // lcd.print(PinPoplach);
  }
 
  }