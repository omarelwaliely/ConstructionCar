#define DEBOUNCE_TIME 50 // Adjust debounce time as needed

#define FORWARD_BUTTON 9
#define BACKWARD_BUTTON 10
#define RIGHT_BUTTON 11
#define LEFT_BUTTON 12
#define UP_BUTTON A0
#define DOWN_BUTTON A1
#define OPEN_BUTTON A2
#define CLOSE_BUTTON A3

volatile unsigned long lastDebounceTime = 0;
volatile unsigned long debounceDelay = DEBOUNCE_TIME;

volatile bool forwardPressed = false;
volatile bool backwardPressed = false;
volatile bool rightPressed = false;
volatile bool leftPressed = false;
volatile bool upPressed = false;
volatile bool downPressed = false;
volatile bool openPressed = false;
volatile bool closePressed = false;

void setup() {
  Serial.begin(9600);
  while (!Serial);
  Serial1.begin(9600);

  pinMode(FORWARD_BUTTON, INPUT_PULLUP);
  pinMode(BACKWARD_BUTTON, INPUT_PULLUP);
  pinMode(RIGHT_BUTTON, INPUT_PULLUP);
  pinMode(LEFT_BUTTON, INPUT_PULLUP);
  pinMode(UP_BUTTON, INPUT_PULLUP);
  pinMode(DOWN_BUTTON, INPUT_PULLUP);
  pinMode(OPEN_BUTTON, INPUT_PULLUP);
  pinMode(CLOSE_BUTTON, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(FORWARD_BUTTON), forwardButtonISR, CHANGE);
  attachInterrupt(digitalPinToInterrupt(BACKWARD_BUTTON), backwardButtonISR, CHANGE);
  attachInterrupt(digitalPinToInterrupt(RIGHT_BUTTON), rightButtonISR, CHANGE);
  attachInterrupt(digitalPinToInterrupt(LEFT_BUTTON), leftButtonISR, CHANGE);
  attachInterrupt(digitalPinToInterrupt(UP_BUTTON), upButtonISR, CHANGE);
  attachInterrupt(digitalPinToInterrupt(DOWN_BUTTON), downButtonISR, CHANGE);
  attachInterrupt(digitalPinToInterrupt(OPEN_BUTTON), openButtonISR, CHANGE);
  attachInterrupt(digitalPinToInterrupt(CLOSE_BUTTON), closeButtonISR, CHANGE);
}

void loop() {


  while (Serial1.available()) {
    char c = Serial1.read();
    Serial.print(c); 
  }
  while(Serial.available()){
    char c = Serial.read();
    Serial1.print(c); 
  }

  if (forwardPressed) {
    if (digitalRead(FORWARD_BUTTON) == LOW) {
      Serial.println("Forward button pressed.");
      Serial1.println("f");
    } else {
      Serial1.println("s");
      Serial.println("Forward button released.");
    }
    forwardPressed = false;
  }

  if (backwardPressed) {
    if (digitalRead(BACKWARD_BUTTON) == LOW) {
      Serial.println("Backward button pressed.");
      Serial1.println("b");
    } else {
      Serial.println("Backward button released.");
      Serial1.println("s");

    }
    backwardPressed = false;
  }

  if (rightPressed) {
    if (digitalRead(RIGHT_BUTTON) == LOW) {
      Serial.println("Right button pressed.");
      Serial1.println("r");

    } else {
      Serial.println("Right button released.");
      Serial1.println("s");

    }
    rightPressed = false;
  }

  if (leftPressed) {
    if (digitalRead(LEFT_BUTTON) == LOW) {
      Serial.println("Left button pressed.");
      Serial1.println("l");

    } else {
      Serial.println("Left button released.");
      Serial1.println("s");

    }
    leftPressed = false;
  }

  if (upPressed) {
    if (digitalRead(UP_BUTTON) == LOW) {
      Serial.println("Up button pressed.");
    } else {
      Serial.println("Up button released.");
    }
    upPressed = false;
  }

  if (downPressed) {
    if (digitalRead(DOWN_BUTTON) == LOW) {
      Serial.println("Down button pressed.");
    } else {
      Serial.println("Down button released.");
    }
    downPressed = false;
  }

  if (openPressed) {
    if (digitalRead(OPEN_BUTTON) == LOW) {
      Serial.println("Open button pressed.");
    } else {
      Serial.println("Open button released.");
    }
    openPressed = false;
  }

  if (closePressed) {
    if (digitalRead(CLOSE_BUTTON) == LOW) {
      Serial.println("Close button pressed.");
    } else {
      Serial.println("Close button released.");
    }
    closePressed = false;
  }
}

void forwardButtonISR() {
  if (millis() - lastDebounceTime > debounceDelay) {
    lastDebounceTime = millis();
    forwardPressed = !forwardPressed;
  }
}

void backwardButtonISR() {
  if (millis() - lastDebounceTime > debounceDelay) {
    lastDebounceTime = millis();
    backwardPressed = !backwardPressed;
  }
}

void rightButtonISR() {
  if (millis() - lastDebounceTime > debounceDelay) {
    lastDebounceTime = millis();
    rightPressed = !rightPressed;
  }
}

void leftButtonISR() {
  if (millis() - lastDebounceTime > debounceDelay) {
    lastDebounceTime = millis();
    leftPressed = !leftPressed;
  }
}

void upButtonISR() {
  if (millis() - lastDebounceTime > debounceDelay) {
    lastDebounceTime = millis();
    upPressed = !upPressed;
  }
}

void downButtonISR() {
  if (millis() - lastDebounceTime > debounceDelay) {
    lastDebounceTime = millis();
    downPressed = !downPressed;
  }
}

void openButtonISR() {
  if (millis() - lastDebounceTime > debounceDelay) {
    lastDebounceTime = millis();
    openPressed = !openPressed;
  }
}

void closeButtonISR() {
  if (millis() - lastDebounceTime > debounceDelay) {
    lastDebounceTime = millis();
    closePressed = !closePressed;
  }
}
