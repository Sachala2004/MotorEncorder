//define pins
#define buz_pin 13
#define encA_pin 2
#define encB_pin 3
#define pwm_pin 5
#define IN1 6
#define IN2 7

//define variables
const int one_wheel_rev = 20*22; //ticks (encorder rounnds per wheel round)*(ticks per encorder round)
const float wheel_c = PI*62;       //mm 

//define globals 
volatile unsigned long enc_count = 0;

void setup() {
  //debug 
  Serial.begin(9600);

  //setup pins

  pinMode(buz_pin,OUTPUT);    

  pinMode(encA_pin, INPUT_PULLUP);
  pinMode(encB_pin, INPUT_PULLUP);
  pinMode(pwm_pin, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  //interrupt 
  attachInterrupt(digitalPinToInterrupt(encA_pin),countA,CHANGE);  

  drive_forward(wheel_c);  //give distance(mm) as a parameter  
  drive_backward(wheel_c);  
  // drive_forward(wheel_c/70);  //give distance(mm) as a parameter  
     

  
}

void loop() {
  // Serial.println(enc_count);
  // delay(100);

}
void countA(){
  enc_count++;      
}

void drive_forward(int dist){
  enc_count = 0;  
  int tot_ticks = (dist/wheel_c)*one_wheel_rev;
  analogWrite(pwm_pin,150);
  
  while(enc_count<tot_ticks){
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
  }
    
  delay(5);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
}

void drive_backward(int dist){
  tone(buz_pin,1500);
  enc_count = 0;  
  int tot_ticks = (dist/wheel_c)*one_wheel_rev;
  analogWrite(pwm_pin,150);
  
  while(enc_count<tot_ticks){
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
  }
    
  delay(5);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  noTone(buz_pin);  

}
