#define encA 2
#define encB 3

void setup() {
  Serial.begin(9600);
  pinMode(encA,INPUT);
  pinMode(encB,INPUT);

}

void loop() {
 int a = digitalRead(encA);
 int b = digitalRead(encB);

 Serial.print(a*5);
 Serial.print("  ");
 Serial.print(b*5);
 Serial.println();
 

}
