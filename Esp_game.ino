const int leds[] = {5, 4, 0, 2, 14};  // D1 to D5
const int numLEDs = 5;
int centerLED = 2;  // index of center LED

int currentLED = 0;
int direction = 1;
unsigned long lastStepTime = 0;
int speed = 200;  // lower = faster
int score = 0;

void setup() {
  for (int i = 0; i < numLEDs; i++) {
    pinMode(leds[i], OUTPUT);
  }

  Serial.begin(9600);
  Serial.println("Welcome to LED Reaction Game!");
  Serial.println("Controls:");
  Serial.println("r → Reverse direction");
  Serial.println("+ → Increase speed");
  Serial.println("- → Decrease speed");
  Serial.println("s → Show score");
  Serial.println("x → Reset score");
  Serial.println();
}

void loop() {
  // === LED Movement ===
  if (millis() - lastStepTime > speed) {
    lastStepTime = millis();

    for (int i = 0; i < numLEDs; i++) {
      digitalWrite(leds[i], LOW);
    }

    currentLED += direction;

    if (currentLED >= numLEDs) {
      currentLED = numLEDs - 2;
      direction = -1;
    } else if (currentLED < 0) {
      currentLED = 1;
      direction = 1;
    }

    digitalWrite(leds[currentLED], HIGH);
  }

  // === Serial Input Controls ===
  if (Serial.available()) {
    char input = Serial.read();

    if (input == 'r' || input == 'R') {
      if (currentLED == centerLED) {
        score++;
        Serial.println("🎯 Nice timing! +1 point.");
      } else {
        Serial.println("❌ Missed! Not center LED.");
      }

      direction *= -1;
      Serial.print("↔ Direction reversed! Score: ");
      Serial.println(score);
    }

    else if (input == '+') {
      speed = max(50, speed - 50);
      Serial.print("⚡ Speed increased. Delay = ");
      Serial.println(speed);
    }

    else if (input == '-') {
      speed += 50;
      Serial.print("🐢 Speed decreased. Delay = ");
      Serial.println(speed);
    }

    else if (input == 's' || input == 'S') {
      Serial.print("📊 Current Score: ");
      Serial.println(score);
    }

    else if (input == 'x' || input == 'X') {
      score = 0;
      Serial.println("🔄 Score reset!");
    }
  }
}
