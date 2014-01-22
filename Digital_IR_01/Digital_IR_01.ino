const int IR_SensorNum = 2;             //pin the receiver is connected to

volatile unsigned long microseconds;
volatile unsigned long oldMicroseconds;
volatile unsigned long pulseLength;

void setup()
{
  Serial.begin(9600);
  pinMode(IR_SensorNum, INPUT);
  attachInterrupt(0, measurePulse, CHANGE);  // encoder pin on interrupt 0 (pin 2)
}

void loop()
{
  Serial.println(pulseLength);
  delay(100);
}

void measurePulse()
{
  microseconds = micros();
  if (digitalRead(irReceiverPin) == HIGH)
  {
      pulseLength = microseconds - oldMicroseconds;
  }
  if (digitalRead(irReceiverPin) == LOW)
  {
       oldMicroseconds = microseconds;
  }
}
      
    
