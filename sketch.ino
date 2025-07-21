const int buttonPin = 3;       
const int sensorPin = 2;       
const int transistorPin = 4;   
const int ledPin2 = 9;         

bool isOn = false;             
bool lastButtonState = HIGH;   

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);  
  pinMode(sensorPin, INPUT);          
  pinMode(transistorPin, OUTPUT);    
  pinMode(ledPin2, OUTPUT);          

  digitalWrite(transistorPin, LOW);  
  digitalWrite(ledPin2, LOW);         
}

void loop() {
  bool currentButtonState = digitalRead(buttonPin);

  
  if (currentButtonState == LOW && lastButtonState == HIGH) {
    isOn = !isOn;        
    delay(200);         
  }
  lastButtonState = currentButtonState;

  if (isOn && digitalRead(sensorPin) == HIGH) {
    digitalWrite(transistorPin, HIGH);  
    digitalWrite(ledPin2, HIGH);          
  } else {
    digitalWrite(transistorPin, LOW);   
    digitalWrite(ledPin2, LOW);         
  }
}
