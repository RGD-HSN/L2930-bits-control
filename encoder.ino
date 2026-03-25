// Define 74HC595 shift register pins
#define CLOCK_PIN 4  // SHCP (Clock)
#define LATCH_PIN 2  // STCP (Latch)
#define SERIAL_PIN 8 // DS (Serial Input)
#define ENABLE_PIN 7 // Enable direction control

// Define individual PWM speed control pins
#define M1_PWM 3  // Motor 1 Speed
#define M2_PWM 5  // Motor 2 Speed
#define M3_PWM 6  // Motor 3 Speed
#define M4_PWM 10 // Motor 4 Speed

// Variable to store the current state of the shift register
byte motorState = 0b00000000;

// Function to update shift register with new direction values
void updateShiftRegister() {
  digitalWrite(LATCH_PIN, LOW);
  shiftOut(SERIAL_PIN, CLOCK_PIN, MSBFIRST, motorState);
  digitalWrite(LATCH_PIN, HIGH);
}

// Function to set motor direction: 1 (Forward), -1 (Backward), 0 (Stop)
void setMotorSpeed(int motor, int speed) {



  switch (motor) {
    case 1: // Motor 1 (Bit 7 and Bit 1)
      analogWrite(M3_PWM, abs(speed));
      if (speed >0)
        motorState = (motorState & 0b01011111) | 0b10000000; // Bit 7 HIGH, Bit 1 LOW (Forward)
      else if (speed <0)
        motorState = (motorState & 0b01011111) | 0b00100000; // Bit 7 LOW, Bit 1 HIGH (Backward)
      else
        motorState &= (motorState & 0b01011111);  // Clear both bits (Stop)
      break;
      
    case 2: // Motor 2 (Bit 3 and Bit 6)
      analogWrite(M1_PWM, abs(speed));
      if (speed >0)
        motorState = (motorState & 0b11101101) | 0b00010000; // Bit 6 HIGH, Bit 3 LOW (Forward)
      else if (speed <0)
        motorState = (motorState & 0b11101101) | 0b00000010; // Bit 6 LOW, Bit 3 HIGH (Backward)
      else
        motorState &= (motorState & 0b11101101); // Clear both bits (Stop)
      break;
      
    case 3: // Motor 3 (Bit 5 and Bit 4)
      analogWrite(M4_PWM, abs(speed));
      if (speed >0)
        motorState = (motorState & 0b11110011) | 0b00000100; // Bit 5 HIGH, Bit 4 LOW (Forward)
      else if (speed <0)
        motorState = (motorState & 0b11110011) | 0b00001000; // Bit 5 LOW, Bit 4 HIGH (Backward)
      else
        motorState &= (motorState & 0b11110011) ; // Clear both bits (Stop)
      break;
      
    case 4: // Motor 4 (Bit 2 and Bit 0)
      analogWrite(M2_PWM, abs(speed));
      if (speed >0)
        motorState = (motorState & 0b10111110) | 0b00000001; // Bit 2 HIGH, Bit 0 LOW (Forward)
      else if (speed <0)
        motorState = (motorState & 0b10111110) | 0b01000000; // Bit 2 LOW, Bit 0 HIGH (Backward)
      else
        motorState &= (motorState & 0b10111110) ; // Clear both bits (Stop)
      break;
  }
  updateShiftRegister(); // Apply the updated motor directions
}

 

void setup() {
  // Set shift register pins as output
  pinMode(CLOCK_PIN, OUTPUT);
  pinMode(LATCH_PIN, OUTPUT);
  pinMode(SERIAL_PIN, OUTPUT);
  pinMode(ENABLE_PIN, OUTPUT);

  // Set PWM pins as output
  pinMode(M1_PWM, OUTPUT);
  pinMode(M2_PWM, OUTPUT);
  pinMode(M3_PWM, OUTPUT);
  pinMode(M4_PWM, OUTPUT);

  Serial.begin(9600);
}

void loop() {
    setMotorSpeed(4, 0); // M1
  setMotorSpeed(1, 250); // M1
  delay(3000);

  setMotorSpeed(1, 0); // M1
  setMotorSpeed(2, 250); // M1
  delay(3000);

  setMotorSpeed(2, 0); // M1
  setMotorSpeed(3, 250); // M1
  delay(3000);

  setMotorSpeed(3, 0); // M1
  setMotorSpeed(4, 250); // M1
  delay(3000);


  //ROTOTE 
 // setMotorSpeed(1, 250); // M1
  //setMotorSpeed(2, 250); // M2
  //setMotorSpeed(3, 250); // M3
  //setMotorSpeed(4, 250); // M4
  //delay(5000);

  // Stop
 // setMotorSpeed(1, 0);
 // setMotorSpeed(2, 0);
 // setMotorSpeed(3, 0);
  //setMotorSpeed(4, 0);
  //delay(1000);

    // -ROTATE
  //setMotorSpeed(1, -250);
  //setMotorSpeed(2, -250);
 // setMotorSpeed(3, -250);
 // setMotorSpeed(4, -250);
 // delay(3000);

  // Stop
 // setMotorSpeed(1, 0);
  //setMotorSpeed(2, 0);
  //setMotorSpeed(3, 0);
 // setMotorSpeed(4, 0);
 // delay(1000);

  // Move FORWARD
//  setMotorSpeed(1, -250);
 // setMotorSpeed(2, 250);
//  setMotorSpeed(3, 250);
  //setMotorSpeed(4, -250);
 // delay(3000);

  // Stop
 // setMotorSpeed(1, 0);
 /* setMotorSpeed(2, 0);
  setMotorSpeed(3, 0);
  setMotorSpeed(4, 0);
  delay(1000);

  // Move BACKWARD
  setMotorSpeed(1, 250);
  setMotorSpeed(2, -250);
  setMotorSpeed(3, -250);
  setMotorSpeed(4, 250);
  delay(3000);

  // Stop
  setMotorSpeed(1, 0);
  setMotorSpeed(2, 0);
  setMotorSpeed(3, 0);
  setMotorSpeed(4, 0);
  delay(2000);*/


}