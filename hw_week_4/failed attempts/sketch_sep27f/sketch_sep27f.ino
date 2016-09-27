
const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin1 =  13; // the number of the LED pin
const int ledPin2 = 11;
int buttonState = 0; 


void setup() {
  // put your setup code here, to run once:
 pinMode(ledPin1, OUTPUT);
 pinMode(ledPin2, OUTPUT);
 pinMode(buttonPin, INPUT);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  
  int blinkRateMilliseconds = 500;
  // put your main code here, to run repeatedly:
  digitalWrite (ledPin1, HIGH);
  digitalWrite (ledPin2, HIGH);

  delay(blinkRateMilliseconds);

  digitalWrite (ledPin1, LOW);
  digitalWrite (ledPin2, LOW);

  delay(blinkRateMilliseconds);

   if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(ledPin1, LOW);
    } else {
    // turn LED off:
    digitalWrite(ledPin1, HIGH);
  }
  
}
