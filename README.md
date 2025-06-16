# 🌱 Planta-IoT

## Sobre o Projeto

Este projeto é um **monitor inteligente de umidade de solo** para vasos de plantas, utilizando **MOD-WIFI-ESP8266** e sensor YL-69, com integração ao aplicativo Blynk.  
O sistema permite acompanhar a umidade em tempo real pelo celular, receber alertas de rega e tornar o cuidado com plantas mais fácil e prático.

---

## Como Funciona

- O sensor YL-69 mede a umidade do solo do vaso.
- O MOD-WIFI-ESP8266 lê esse valor e envia para o app Blynk via WiFi.
- No app, você pode visualizar o valor de umidade e receber alertas quando a planta precisa de água.

---

## Esquema de ligação

| Sensor YL-69 (Módulo) | MOD-WIFI-ESP8266 |
|:---------------------:|:----------------:|
| VCC                   | 3V3              |
| GND                   | GND              |
| AO                    | A0               |

---

## Passo a passo

1. Monte o circuito conforme o esquema acima.
2. Programe a placa MOD-WIFI-ESP8266 com o código fornecido (não esquecer de preencher o WiFi e o Auth Token do Blynk).
3. Abra o app Blynk, configure o widget (gauge, LED, etc.) no pino virtual correto.
4. Veja os valores em tempo real e receba alertas de rega quando a umidade estiver baixa!

---

## Recursos do Projeto

- Monitoramento remoto em tempo real pelo app Blynk
- Alerta de rega via notificação push (configurável)
- Fácil de montar e expandir

---

## Créditos

Desenvolvido por: Luiza de Martha e Nicholas Siécola

Disciplina: Conceitos e Tecnologias para Dispositivos Conectados (C115)

Professor: Samuel Baraldi Mafra

---

