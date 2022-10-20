int VB = A8;
void setup() {
 Serial.begin(9600);
 pinMode(VB, INPUT);
}
void loop() {
 if (digitalRead(VB)) {
 Serial.println("Vibrace prekonaly detekcni prah.");
 delay(500);
 }
}
