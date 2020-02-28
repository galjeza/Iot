#include "MQTT.h"

#define ServerAddress    "broker.hivemq.com"
#define MQTTClient       "cloudIoT"
#define MQTTTestTopic    "BQ/gal/test/"
#define MQTTMainTopic    "main"
#define WiFiSSID         "DSPLAB"
#define WiFiPass         "dsplab123!"
#define MQTTPort         1883

void setup() {
  Serial.begin(9600);  
  Serial.println("***************HELLOWORLD*****************");
  MQTT cloudMQTT;

  // put your setup code here, to run once:
  while((cloudMQTT.MQTT_Broker_Set(ServerAddress, MQTTPort)) != MQTT_BROKER_OK){
    Serial.println(".");
    delay(5);
  }
  while((cloudMQTT.WiFi_Connect(WiFiSSID, WiFiPass)) != WIFI_CONNECTED){
    Serial.println("*");
  }

  while((cloudMQTT.MQTT_Topic_Connect(MQTTClient)) != MQTT_TOPIC_CONNECT_OK){
    Serial.println("MQTT topic connect NOK");
  }
}

void loop() {
  MQTT cloudMQTT;

  // put your main code here, to run repeatedly:
  while((cloudMQTT.MQTTPublish(MQTTTestTopic, "testtesttesttest", MQTTClient, MQTTMainTopic)) != MQTT_TOPIC_PUBLISH_OK){
    Serial.println("MQTT topic publish NOK");
  }
  Serial.println("MQTT topic publish OK, again");
  delay(1000);
}
