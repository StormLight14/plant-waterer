int water_time = 5; // in seconds
int water_delay =  1; // in minutes

int reset_button_pin = 2;
int water_button_pin = 3;
int water_pump_control = 9;

unsigned long time;
unsigned long start_time = 0;

void setup() {
  pinMode(reset_button_pin, INPUT);
  pinMode(water_button_pin, INPUT);
  pinMode(water_pump_control, OUTPUT);
  Serial.begin(9600);

  water_time *= 1000; // turn into seconds
  water_delay *= 60000; // turn into minutes
}

void loop() {
  time = millis();
  if (time >= water_delay + start_time) {
    digitalWrite(water_pump_control, HIGH);
    if (time >= water_delay + start_time + water_time) {
      start_time = time;
      digitalWrite(water_pump_control, LOW);
    }
  }
 
  if (digitalRead(water_button_pin)) {
    Serial.println("Pumping water (button press).");
    digitalWrite(water_pump_control, HIGH);
    delay(water_time);
    digitalWrite(water_pump_control, LOW);
  }

  if (digitalRead(reset_button_pin)) {
    Serial.println("Resetting water timer (button press).");
    digitalWrite(water_pump_control, LOW);
    start_time = millis();
  }
}

void debug() {
  Serial.println("Millis: ");
  Serial.print(millis());
  Serial.print(", Start time: ");
  Serial.print(start_time);
  Serial.print(", ");
  Serial.print(water_delay - start_time);
}
