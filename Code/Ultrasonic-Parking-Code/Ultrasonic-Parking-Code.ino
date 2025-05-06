#include <NewPing.h>

#define TRIG_PIN  9
#define ECHO_PIN  10
#define RED_PIN   6
#define GREEN_PIN 5
#define BUZZER_PIN 7
#define MAX_DISTANCE 200

NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() {
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  Serial.begin(9600);
}

int getDistance() {
  delay(30);
  return sonar.ping_cm();
}

void setAlerts(int distance) {
  if (distance > 50) {
    // Safe (Green + Buzzer Off)
    digitalWrite(GREEN_PIN, HIGH);
    digitalWrite(RED_PIN, LOW);
    digitalWrite(BUZZER_PIN, LOW);
  } 
  else if (distance <= 50 && distance > 20) {
    // Caution (Yellow + Slow Beeps)
    digitalWrite(GREEN_PIN, HIGH);
    digitalWrite(RED_PIN, HIGH);
    digitalWrite(BUZZER_PIN, HIGH); // Buzzer ON
    delay(200);                     // Beep duration
    digitalWrite(BUZZER_PIN, LOW);  // Buzzer OFF
    delay(300);                     // Pause between beeps
  } 
  else {
    // Danger (Red + Fast Beeps)
    digitalWrite(GREEN_PIN, LOW);
    digitalWrite(RED_PIN, HIGH);
    digitalWrite(BUZZER_PIN, HIGH); // Buzzer ON
    delay(100);                     // Shorter beep
    digitalWrite(BUZZER_PIN, LOW);  // Buzzer OFF
    delay(100);                     // Shorter pause
  }
}

void loop() {
  int distance = getDistance();
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  setAlerts(distance);
}