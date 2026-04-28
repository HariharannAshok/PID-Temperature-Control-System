const int sensorPin = 34;
const int ena = 25;
const int in1 = 26;
const int in2 = 27;

// PID gains (tuned for thermal stability)
float Kp = 15.0;
float Ki = 0.3;
float Kd = 60.0;

float setpoint = 25.0;
float previousError = 0;
float integral = 0;
unsigned long previousTime = 0;

const int minPWM = 30; // Reduced from 60 to avoid over-cooling

void setup() {
  Serial.begin(115200);
  pinMode(ena, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
}

void loop() {
  unsigned long currentTime = millis();
  float dt = (currentTime - previousTime) / 1000.0;
  if (dt <= 0) dt = 0.01;

  int adcValue = analogRead(sensorPin);
  float voltage = adcValue * (3.3 / 4095.0);
  float temperature = voltage * 100;

  float error = setpoint - temperature;

 
  integral += error * dt;
  integral = constrain(integral, -30, 30);

  float derivative = (error - previousError) / dt;
  float output = (Kp * error) + (Ki * integral) + (Kd * derivative);

  // Convert to positive cooling effort
  output = -output;

  int pwmValue;


  if (abs(error) < 0.3) {
    pwmValue = 0; // Deadband: no jitter near setpoint
  } else {
    pwmValue = constrain((int)output, 0, 255);
  }

  analogWrite(ena, pwmValue);

  Serial.print("Temp: ");
  Serial.print(temperature);
  Serial.print(" | PWM: ");
  Serial.print(pwmValue);
  Serial.print(" | Error: ");
  Serial.print(error);
  Serial.print(" | Integral: ");
  Serial.println(integral);

  previousError = error;
  previousTime = currentTime;
  delay(500);
}
