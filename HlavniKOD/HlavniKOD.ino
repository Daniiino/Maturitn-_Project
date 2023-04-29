//Noty
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
//////////////////////////////////////////

//Písnička
int melody[] = {
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
int tempo = 120;
int notes = sizeof(melody) / sizeof(melody[0]) / 2;
int wholenote = (60000 * 4) / tempo;
int divider = 0, noteDuration = 0;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Knihovny
#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
/////////////////////////////////////////


//Definované Piny
#define VIBRATION_PIN 14
int PinPoplach = 0;
int buzzer = 17;
/////////////////////////////////////////

//Promněné 
int PoDea = 0;
int D = 0;
int P = 0;
int Song = 1;
int ZaplyVyber = 0;
int Start = 0;
String q = "0";
int s = 0;
int c = 1;
int Radek = 0;
int PrvniStart = 0;
int zaply = 0;
int alarm = 0;
///////////////////////////////////////////



//Klávesnice
const int ROW_NUM    = 4; // four rows
const int COLUMN_NUM = 3; // four columns
String PIN [4] = {"1","2","0","4"};
String KOD [4] ={"0","0","0","0"};
char keys[ROW_NUM][COLUMN_NUM] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
char Cislo[4]{'1','2','3','4'};

byte pin_rows[ROW_NUM] = {9, 8, 7, 6};      // connect to the row pinouts of the keypad
byte pin_column[COLUMN_NUM] = {5, 4, 3}; // connect to the column pinouts of the keypad

 

Keypad keypad = Keypad(makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM );
LiquidCrystal_I2C lcd(0x27, 20, 4); // I2C address 0x27, 16 column and 2 rows

 

int cursorColumn = 0;
///////////////////////////////////////////////////////////////////////////////////////////










 
//Setup
void setup(){
  lcd.begin(); // initialize the lcd
  lcd.backlight();

  //KOD
  lcd.setCursor(2,0);
  lcd.print("Zabezpecovaci"); 
  lcd.setCursor(2,1);
  lcd.print("---System---"); 
  delay(2500);
  lcd.clear();
}
//////////////////////////////////////////////
 
//Loop
void loop(){
  if(PrvniStart == 0){
  NovyPin();
  VSongu();
  }
  if(P==1){
  char zadejC = keypad.getKey();
  if (zadejC) {
   lcd.print(s);
   if(s < 1){
    q = zadejC;
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


if(cursorColumn == 1) {
   if(q == "1"){
      Song = 1;
      lcd.clear();
      lcd.setCursor(0,0); 
      lcd.print("Znelka je Vybrana"); 
      lcd.setCursor(0,1); 
      lcd.print("Pirati z Karibiku"); 
      zaply = 1;
      P++;
      clearKod();
     
      }else{
    if(q == "2"){
      Song = 2;
      lcd.setCursor(0,0);
      lcd.print("Znelka je Vybrana"); 
      lcd.setCursor(0,1); 
      lcd.print("The Lion Sleeps Tonight"); 
      zaply = 1;
      P++;
      clearKod();
     
      }else{
        SpatnaPisen();
        }
      }
  }
  }
  if(zaply == 1){
  Menu();
  ZadaniPinu();
  }
  if (zaply == 2){
  if(Start == 1){
  lcd.print("---Uspesnee---");
  lcd.setCursor(0,1);
  lcd.print("---spusteno---");
  delay(1500);
  lcd.clear();
  Start++;
  }
  //Infra();
  Vibrace();
  //PIR();
  }
}
///////////////////////////////////////////////////////////////









//Metody
//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
void NovyPin(){
  char NP = keypad.getKey();
  if (NP) {
   if(s < 4){
    q = NP;
    PIN[s] = q;
    lcd.setCursor(c, 1);
    //lcd.print(KOD[s]);
    s++;
    c++;
     }
    lcd.setCursor(cursorColumn, Radek); // move cursor to   (cursorColumn, 0)
    lcd.print("+"); 
    
    cursorColumn++;                 // move cursor to next position
                                    // if reaching limit, clear LCD
  }
  if(cursorColumn == 4) { 
    lcd.clear();
    lcd.print("Pin byl ulozen");
    delay(1000);
     clearKod();
     PrvniStart++;
     ZaplyVyber = 1;
    }                            
  }
//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::


//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
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
            //alarm++;
            delay(2000);
            lcd.clear();
            cursorColumn = 10;
            clearKod();
            zaply = 2;
            if(PoDea == 1){
              delay(1500);
              lcd.setCursor(0,0);
              lcd.print("Zadej PIN:"); 
              cursorColumn = 10;
              PoDea++;
              }
            if(Radek==1){
             // tone(buzzer,261,250);
              //tone(buzzer,349,250);
              }
            if(D == 1){  
            Deaktivace();
            }
            //lcd.print(zaply);
            }else{
              lcd.clear();
              cursorColumn = 0;
              lcd.print("Pin neni spravny");
               //tone(buzzer,349,250);
               //tone(buzzer,523,250);
              delay(2000);
              lcd.clear();
              cursorColumn = 10;
              if(Radek==1){
                lcd.print("Pro deaktivaci");
                lcd.setCursor(0,1);
                lcd.print("Zadej PIN:"); 
                cursorColumn = 10;
                }else{
              lcd.print("Zadej PIN:");
              cursorColumn = 10;
                } 
              clearKod();
              cursorColumn = 10;
              }
             // lcd.print(PinPoplach);
  }
 
  }
//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::  
void VSongu(){
  if(ZaplyVyber == 1){
    if( P == 0){
  delay(1000); 
  lcd.clear();
  lcd.print("Vyber alarmni");
  lcd.setCursor(0,1);
  lcd.print("znelku");
  lcd.setCursor(0,1);
  delay(2500);
  lcd.clear();
  lcd.print("Stisknutim cisla");
  lcd.setCursor(0,1);
  lcd.print("jedna nebo dva:");
  delay(2500);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("1.Pirati z Karibiku"); 
  lcd.setCursor(0,1);
  lcd.print("2.The Lion Sleeps Tonight"); 
  delay(2000);
  lcd.clear();
  P++;
  clearKod();
    }
  }
}
//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
void Vibrace(){
  if (!digitalRead(VIBRATION_PIN)) {
 //Serial.println(digitalRead(VIBRATION_PIN));
 Detekce();
 Poplach();
 }
  }
//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::  

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::  
void Poplach(){
  clearAlarm();
// Zapnout Ledky
  
  lcd.print("Pro deaktivaci");
  lcd.setCursor(0,1);
  lcd.print("Zadej PIN:"); 
  cursorColumn = 10;
  Radek++;
  D = 1;
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
//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::  
/////////////////////////////////////////////////////////////////////////////


  
//pomocné Metody
//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
  void Menu(){
 if(Start == 0){
 delay(1000);
 lcd.clear();
 lcd.print("Zadej PIN:"); 
 Start++; 
 cursorColumn = 10;
 }
}
//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
void clearKod(){
  KOD[0] = "0";
  KOD[1] = "0";
  KOD[2] = "0";
  KOD[3] = "0";
  s = 0;
  c = 0;
  cursorColumn = 0; 
  q = "0";
}
//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
void Detekce() {
  lcd.print("Zaznamenan Pohyb");
  delay(2000);
  lcd.clear();
}
//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
void clearAlarm(){
  alarm = 0;
}
//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
void SpatnaPisen(){
  if(q != "2" && q != "1"){
    q = "0";
    lcd.setCursor(0,0); 
    lcd.print("Znelka je");
    lcd.setCursor(0,1); 
    lcd.print("Vybrana Nahodne");
    delay(2000); 
    Song = 1;
    zaply = 1;
    P++;
    
    clearKod();
    }
}
//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
void Deaktivace(){
  lcd.print("----System----");
  lcd.setCursor(0,1);
  lcd.print("--Deaktivovan--");
  delay(1500);
  lcd.clear();
  D = 0;
  Song = 1;
  ZaplyVyber = 0;
  Start = 0;
  q = "0";
  s = 0;
  c = 1;
  Radek = 0;
  zaply = 1;
  alarm = 0;
  PoDea = 1;
  loop();
}
//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

////////////////////////////////////////////////////