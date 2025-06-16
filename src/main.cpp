#define BLYNK_TEMPLATE_ID "TMPL2vugeEkLj"
#define BLYNK_TEMPLATE_NAME "Planta IoT"
#define BLYNK_AUTH_TOKEN "ZlG1Cc4GN3pKv6u2Ntk67UmHxGfEkr1D"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// WiFi
char ssid[] = "Casa Lend";
char pass[] = "casabala";

// Pino do sensor de umidade
#define PIN_SENSOR A0

void setup() {
  Serial.begin(9600);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop() {
  int seco = 1024;     // valor no ar (seco)
  int molhado = 560;   // valor na água (molhado)
  int leitura = analogRead(PIN_SENSOR);
  int percent = map(leitura, seco, molhado, 0, 100);
  if (percent < 0) percent = 0;
  if (percent > 100) percent = 100;
  Blynk.virtualWrite(V2, percent);

  static int percent2 = 0;
  percent2 = (percent2 + 1) % 101; // Conta até 100 e volta para 0
  Blynk.virtualWrite(V1, percent2); // Envia para o Virtual Pin V1
  
  Serial.print("Leitura: ");
  Serial.print(leitura);
  Serial.print(" | Umidade: ");
  Serial.println(percent);

  delay(2000);
  Blynk.run();
}
