int water_time = 5 * 1000; // in seconds
int water_delay =  15 * 1000; // in seconds | * 60000; // in hours

int reset_button_pin = 2;
int water_button_pin = 3;
int water_pump_pin = 4;

unsigned long time;
unsigned long start_time = 0;

void setup() {
  pinMode(reset_button_pin, INPUT);
  pinMode(water_button_pin, INPUT);
  pinMode(water_pump_pin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  time = millis();
  if (time >= water_delay + start_time) {
    digitalWrite(water_pump_pin, HIGH);
    if (time >= water_delay + start_time + water_time) {
      start_time = time;
      digitalWrite(water_pump_pin, LOW);
    }
  }
 
  //debug();

  if (digitalRead(water_button_pin)) {
    Serial.println("Pumping water (button press).");
    digitalWrite(water_pump_pin, HIGH);
    delay(water_time);
    digitalWrite(water_pump_pin, LOW);
  }

  if (digitalRead(reset_button_pin)) {
    Serial.println("Resetting water timer (button press).");
    digitalWrite(water_pump_pin, LOW);
    start_time = millis();
  }

  /* SIMPLE CODE, no input
  delay(water_delay); 
  digitalWrite(water_pump_pin, HIGH);
  delay(water_time);
  digitalWrite(water_pump_pin, LOW);
  */
}

void debug() {
  Serial.println("Millis: ");
  Serial.print(millis());
  Serial.print(", Start time: ");
  Serial.print(start_time);
  Serial.print(", ");
  Serial.print(water_delay - start_time);
}
