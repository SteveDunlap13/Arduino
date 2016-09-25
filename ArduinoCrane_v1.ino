// Steve Dunlap
// Sept 24, 2016
// Arduino code for crane
// 3 Nema 17 motors with 3 A4988 drivers and 2 joysticks
//////////////////////////////////////////////////////////////////

// Counters
int counter = 0;
const int m1_x_low = 475;
const int m1_x_high = 555;
int m1_x_position = 0;

const int m2_x_low = 475;
const int m2_x_high = 555;
int m2_x_position = 0;

const int m3_y_low = 475;
const int m3_y_high = 555;
int m3_y_position = 0;


// Base motor
#define m1_dir_pin     2
#define m1_step_pin    3
#define m1_enable_pin  4

// Trolley motor
#define m2_dir_pin     5
#define m2_step_pin    6
#define m2_enable_pin  7

// Lift motor
#define m3_dir_pin     8
#define m3_step_pin    9
#define m3_enable_pin  10

#define m2_limit_switch 12
#define m3_limit_switch 13

// Joystick controls
#define m1_x_pin       A0   // moves the base left/right
#define m2_x_pin       A1   // moves the trolley left/right
#define m3_y_pin       A2   // moves the lift up/down



void setup() {

  pinMode(m1_enable_pin, OUTPUT);
  digitalWrite(m1_enable_pin, LOW);
  pinMode(m1_step_pin, OUTPUT);
  pinMode(m1_dir_pin, OUTPUT);
  
  pinMode(m2_enable_pin, OUTPUT);
  digitalWrite(m2_enable_pin, LOW);
  pinMode(m2_step_pin, OUTPUT);
  pinMode(m2_dir_pin, OUTPUT);

  pinMode(m3_enable_pin, OUTPUT);
  digitalWrite(m3_enable_pin, LOW);
  pinMode(m3_step_pin, OUTPUT);
  pinMode(m3_dir_pin, OUTPUT);

  pinMode(m1_x_pin, INPUT);
  pinMode(m2_x_pin, INPUT);
  pinMode(m3_y_pin, INPUT);

  pinMode(m2_limit_switch, INPUT);
  pinMode(m3_limit_switch, INPUT);
}

void loop() {
  
  m1_x_position = analogRead(m1_x_pin);
  m2_x_position = analogRead(m2_x_pin);
  m3_y_position = analogRead(m3_y_pin);

  //digitalRead(m2_limit_switch)
  
  // base motor control
  if(m1_x_position < m1_x_low) {

    digitalWrite(m1_dir_pin, HIGH); // anti-clockwise
    digitalWrite(m1_step_pin, HIGH);
    delay(10);
    digitalWrite(m1_step_pin, LOW);
    delay(10);
  }
  if(m1_x_position > m1_x_high) {

    digitalWrite(m1_dir_pin, LOW); // clockwise
    digitalWrite(m1_step_pin, HIGH);
    delay(10);
    digitalWrite(m1_step_pin, LOW);
    delay(10);
  }
  

  // trolley motor control
  if(m2_x_position < m2_x_low) {

    digitalWrite(m2_dir_pin, HIGH); // anti-clockwise
    digitalWrite(m2_step_pin, HIGH);
    delay(1);
    digitalWrite(m2_step_pin, LOW);
    delay(1);
  }
  if(m2_x_position > m2_x_high && digitalRead(m2_limit_switch) == LOW) {

    digitalWrite(m2_dir_pin, LOW); // clockwise
    digitalWrite(m2_step_pin, HIGH);
    delay(1);
    digitalWrite(m2_step_pin, LOW);
    delay(1);
  }

  
  // lift motor control
  if(m3_y_position < m3_y_low) {

    digitalWrite(m3_dir_pin, HIGH); // anti-clockwise
    digitalWrite(m3_step_pin, HIGH);
    delay(1);
    digitalWrite(m3_step_pin, LOW);
    delay(1);
  }
  if(m3_y_position > m3_y_high && digitalRead(m3_limit_switch) == LOW) {

    digitalWrite(m3_dir_pin, LOW); // clockwise
    digitalWrite(m3_step_pin, HIGH);
    delay(1);
    digitalWrite(m3_step_pin, LOW);
    delay(1);
  }
  

/*
  digitalWrite(m1_dir_pin, HIGH);
  digitalWrite(m2_dir_pin, HIGH);
  digitalWrite(m3_dir_pin, HIGH);
  
  for(counter = 0; counter < 500; counter++)
  {
    //digitalWrite(m1_step_pin, HIGH);
    digitalWrite(m2_step_pin, HIGH);
    digitalWrite(m3_step_pin, HIGH);

    delay(5);
    
    //digitalWrite(m1_step_pin, LOW);
    digitalWrite(m2_step_pin, LOW);
    digitalWrite(m3_step_pin, LOW);

    delay(10);
  }
*/
}


//end
