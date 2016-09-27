int delay_value = 1000;
int led_pin = 13;
int button_pin = 2;
void setup() { 
  pinMode(led_pin, OUTPUT); pinMode(button_pin, INPUT); 
}
void loop() { 
  digitalWrite(led_pin, HIGH);
  delay(delay_value);
  digitalWrite(led_pin, LOW);
  delay(delay_value);
  int button_state = digitalRead(button_pin);
  if (button_state == HIGH) { 
    delay_value = 100; 
  } else { 
    delay_value = 1000; 
  } 
}
