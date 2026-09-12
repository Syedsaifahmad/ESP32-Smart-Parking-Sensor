const int TRIG_PIN = 5;       // HC-SR04 TRIG → D5
const int ECHO_PIN = 18;      // HC-SR04 ECHO → D18 through resistor divider
const int BUZZER_PIN = 13;    // Buzzer S → D13
const int LED_PIN = 2;        // LED positive → D2 through 220Ω

const float PARKING_LIMIT = 60.0;  // Detection distance in cm

void setup() {
  Serial.begin(115200);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);

  digitalWrite(TRIG_PIN, LOW);
  digitalWrite(LED_PIN, LOW);
  noTone(BUZZER_PIN);

  Serial.println("Smart Parking Sensor Started");
}

float readDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH, 30000);

  if (duration == 0) {
    return -1;
  }
  float distance = duration * 0.0343 / 2;
  return distance;
}
void loop() {
  float distance = readDistance();

  if (distance < 0) {
    Serial.println("No echo received");

    digitalWrite(LED_PIN, LOW);
    noTone(BUZZER_PIN);
  }
  else {
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    if (distance <= PARKING_LIMIT) {
      // Parking occupied
      digitalWrite(LED_PIN, HIGH);

      tone(BUZZER_PIN, 2000);  // 2 kHz buzzer sound

      Serial.println("STATUS: PARKING OCCUPIED");
    }
    else {
      // Parking available
      digitalWrite(LED_PIN, LOW);

      noTone(BUZZER_PIN);

      Serial.println("STATUS: PARKING AVAILABLE");
    }
  }
  delay(500);
}
