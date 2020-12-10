#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>

enum carMove {
  straight, 
  backward, 
  turnLeft, 
  turnRight
} carBehave;

const int m1a = D0;
const int m1b = D1;
const int m2a = D2;
const int m2b = D3;

const int max_speed = 1024; // 1024

const char *SSID = "HUAWEI-7193";
const char *PWD = "58200115";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(m1a, OUTPUT);
  pinMode(m1b, OUTPUT);
  pinMode(m2a, OUTPUT);
  pinMode(m2b, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);

  digitalWrite(m1a, LOW);
  digitalWrite(m1b, LOW);
  digitalWrite(m2a, LOW);
  digitalWrite(m2b, LOW);

  digitalWrite(LED_BUILTIN, LOW);

  WiFi.begin(SSID,PWD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.println();
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  digitalWrite(LED_BUILTIN, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  int testloop = 512;
  while(testloop<max_speed) {
    analogWrite(m1a,testloop);
    analogWrite(m2a,testloop);
    analogWrite(LED_BUILTIN,testloop);
    delay(5);
    testloop++;
  }
analogWrite(m1a,0);
analogWrite(m2a,0);

delay(5000);

  testloop = 512;
  while(testloop<max_speed) {
    analogWrite(m1b,testloop);
    analogWrite(m2b,testloop);
    analogWrite(LED_BUILTIN,testloop);
    delay(5);
    testloop++;
  }
analogWrite(m1b,0);
analogWrite(m2b,0);

delay(5000);
}


void car_behave(int cars) {
  // Straight fwd
  if (cars == straight) {
    analogWrite(m1b, max_speed);
    analogWrite(m2b, max_speed);
  }
  if (cars == backward) {
    analogWrite(m1a, max_speed);
    analogWrite(m1b, max_speed);
  }
}

void backward(int car_bwd) {

}
