#define BLYNK_TEMPLATE_ID   "TMPL2vugeEkLj"
#define BLYNK_TEMPLATE_NAME "Planta IoT"
#define BLYNK_AUTH_TOKEN    "ZlG1Cc4GN3pKv6u2Ntk67UmHxGfEkr1D"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char ssid[] = "Casa Lend";
char pass[] = "casabala";

#define SENSOR_PIN    A0    // Pino do sensor de umidade
#define LED_PIN       2     // Pino do LED 
#define VP_UMIDADE    V2    // Pino Virtual da umidade no App
#define VP_BOTAO_LED  V1    // Pino Virtual do botão no App

BlynkTimer timer;

// Função para ler o sensor
void lerSensor() {
  // Calibragem do seu sensor
  int valorMaximo = 1024; // Sensor no ar
  int valorMinimo = 560;  // Sensor na água

  int leitura = analogRead(SENSOR_PIN);
  int umidade = map(leitura, valorMaximo, valorMinimo, 0, 100);
  umidade = constrain(umidade, 0, 100);

  // Envia o valor da umidade para o App
  Blynk.virtualWrite(VP_UMIDADE, umidade);
}

// Função que roda quando o botão no App é apertado
BLYNK_WRITE(VP_BOTAO_LED) {
  int estado = param.asInt(); // Pega o valor do botao (0 ou 1)
  
  // Acende (LOW) ou apaga (HIGH) o LED
  digitalWrite(LED_PIN, estado == 1 ? LOW : HIGH);
}

// Roda quando conecta no Blynk para sincronizar o botão
BLYNK_CONNECTED() {
  Blynk.syncVirtual(VP_BOTAO_LED);
}

// Configurações iniciais (roda uma vez)
void setup() {
  // Configura o pino do LED como saída
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, HIGH); // Garante que o LED comece apagado

  // Conecta ao Wi-Fi e ao Blynk
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  // Agenda a função 'lerSensor' para rodar a cada 2 segundos
  timer.setInterval(2000L, lerSensor);
}

// Roda sem parar
void loop() {
  Blynk.run(); // Mantém o Blynk funcionando
  timer.run(); // Roda o timer
}