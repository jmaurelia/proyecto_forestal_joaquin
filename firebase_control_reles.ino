#include <ESP8266WiFi.h>
#include "FirebaseESP8266.h"

#define FIREBASE_HOST "bioforest-smart.firebaseio.com"
#define FIREBASE_AUTH "BmwJOOX3uN6AFvEYvoyoHgDY61V4tvaqkqYJxEXU"
#define WIFI_SSID "Maurelia 417"
#define WIFI_PASSWORD "Wab1687417"

#define Relay1 16 //D0
#define Relay2 5  //D1
#define Relay3 4  //D2
#define Relay4 0  //D3
#define Relay5 2  //D4
#define Relay6 14 //D5
#define Relay7 12 //D6

int rel1, rel2, rel3, rel4, rel5, rel6, rel7;
int valorAnterior1 = 1;
int valorAnterior2 = 1;
int valorAnterior3 = 1;
int valorAnterior4 = 1;
int valorAnterior5 = 1;
int valorAnterior6 = 1;
int valorAnterior7 = 1;

FirebaseData firebaseData;
FirebaseJson json;

void setup()
{
  Serial.begin(9600); // Select the same baud rate if you want to see the datas on Serial Monitor
  pinMode(Relay1, OUTPUT);
  pinMode(Relay2, OUTPUT);
  pinMode(Relay3, OUTPUT);
  pinMode(Relay4, OUTPUT);
  pinMode(Relay5, OUTPUT);
  pinMode(Relay6, OUTPUT);
  pinMode(Relay7, OUTPUT);
  digitalWrite(Relay1, HIGH);
  digitalWrite(Relay2, HIGH);
  digitalWrite(Relay3, HIGH);
  digitalWrite(Relay4, HIGH);
  digitalWrite(Relay5, HIGH);
  digitalWrite(Relay6, HIGH);
  digitalWrite(Relay7, HIGH);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected:");
  Serial.println(WiFi.localIP());

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.setInt(firebaseData, "/Sala1/programs/p1", l);
  Firebase.setInt(firebaseData, "/Sala1/programs/p2", l);
  Firebase.setInt(firebaseData, "/Sala1/programs/p3", l);
  Firebase.setInt(firebaseData, "/Sala1/programs/p4", l);
  Firebase.setInt(firebaseData, "/Sala1/programs/p5", l);
  Firebase.setInt(firebaseData, "/Sala1/programs/p6", l);
}

void loop()
{
  rel1 = Firebase.getInt(firebaseData, "/Sala1/programs/p1"); // Estado actual desde BD
  rel2 = Firebase.getInt(firebaseData, "/Sala1/programs/p2"); // Estado actual desde BD
  rel3 = Firebase.getInt(firebaseData, "/Sala1/programs/p3"); // Estado actual desde BD
  rel4 = Firebase.getInt(firebaseData, "/Sala1/programs/p4"); // Estado actual desde BD
  rel5 = Firebase.getInt(firebaseData, "/Sala1/programs/p5"); // Estado actual desde BD
  rel6 = Firebase.getInt(firebaseData, "/Sala1/programs/p6"); // Estado actual desde BD

  if (rel1 == 0 && valorAnterior1 == 1)
  {
    digitalWrite(Relay7, LOW);
    delay(100);
    digitalWrite(Relay7, HIGH);
    delay(500);
    digitalWrite(Relay1, LOW);
    delay(100);
    digitalWrite(Relay1, HIGH);
    Serial.println("Encender Programa 1");
  }
  valorAnterior1 = rel1;

  // Programa 2
  if (rel2 == 0 && valorAnterior2 == 1)
  {
    digitalWrite(Relay7, LOW);
    delay(100);
    digitalWrite(Relay7, HIGH);
    delay(500);
    digitalWrite(Relay2, LOW);
    delay(100);
    digitalWrite(Relay2, HIGH);
    Serial.println("Encender Programa 2");
  }
  valorAnterior2 = rel2;

  // Programa 3
  if (rel3 == 0 && valorAnterior3 == 1)
  {
    digitalWrite(Relay7, LOW);
    delay(100);
    digitalWrite(Relay7, HIGH);
    delay(500);
    digitalWrite(Relay3, LOW);
    delay(100);
    digitalWrite(Relay3, HIGH);
    Serial.println("Encender Programa 3");
  }
  valorAnterior3 = rel3;

  // Programa 4
  if (rel4 == 0 && valorAnterior4 == 1)
  {
    digitalWrite(Relay7, LOW);
    delay(100);
    digitalWrite(Relay7, HIGH);
    delay(500);
    digitalWrite(Relay4, LOW);
    delay(100);
    digitalWrite(Relay4, HIGH);
    Serial.println("Encender Programa 4");
  }
  valorAnterior4 = rel4;

  // Programa 5
  if (rel5 == 0 && valorAnterior5 == 1)
  {
    digitalWrite(Relay7, LOW);
    delay(100);
    digitalWrite(Relay7, HIGH);
    delay(500);
    digitalWrite(Relay5, LOW);
    delay(100);
    digitalWrite(Relay5, HIGH);
    Serial.println("Encender Programa 5");
  }
  valorAnterior5 = rel5;

  // Programa 6
  if (rel6 == 0 && valorAnterior6 == 1)
  {
    digitalWrite(Relay7, LOW);
    delay(100);
    digitalWrite(Relay7, HIGH);
    delay(500);
    digitalWrite(Relay6, LOW);
    delay(100);
    digitalWrite(Relay6, HIGH);
    Serial.println("Encender Programa 6");
  }
  valorAnterior6 = rel6;
}