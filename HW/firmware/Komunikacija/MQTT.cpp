#include "MQTT.h"
    #include "PubSubClient.h"
    #include <ESP8266WiFi.h>
    WiFiClient wifiClient;
    PubSubClient client(wifiClient); 
/*
 * WiFi connect
 */
int MQTT::WiFi_Connect(char *ssid, char *pass){
  Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);
    WiFi.begin(ssid, pass);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("");
    Serial.print("WiFi connected.");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
    return(WIFI_CONNECTED);
}

int MQTT::MQTT_Broker_Set(char *brokerAdd, int port){
  client.setServer(brokerAdd, port);
  return(MQTT_BROKER_OK);
}


int MQTT::MQTT_Topic_Connect(char *clientName){
    if (client.connect(clientName)) {
       return(MQTT_TOPIC_CONNECT_OK);
//        Serial.print("Connected to MQTT broker at ");
//        Serial.print(server);
//        Serial.print(" as ");
//        Serial.println(clientName);
//        Serial.print("Main Topic is: ");
//        Serial.println(main_topic);
    }
    else {
      return(MQTT_TOPIC_CONNECT_NOK);
//        Serial.println("MQTT connect failed");
//        Serial.println("Will reset and try again...");
        abort();
    }
}


  /*
 * ******void mqttReConnect()
 * function for reconnect mqtt connection on server * 
 */
int MQTT::MQTT_Topic_Reconnect(char *clientName, char *main_topic){
  while (!client.connected()) {
        Serial.print("Attempting MQTT connection...");
        // Attempt to connect
        if (client.connect(clientName)) {
            Serial.println("connected");
            client.subscribe(main_topic);
            return(MQTT_TOPIC_CONNECT_OK);
        } else {
            return(MQTT_TOPIC_CONNECT_NOK);
//            Serial.print("failed, rc=");
//            Serial.print(client.state());
//            Serial.println(" try again in 5 seconds");
//            delay(5000);
        }
    }
}

int MQTT::MQTTPublish(char * topic, char *payload, char *clientName, char *main_topic){
  if (client.connected()) {
        if (client.publish(topic, (char*) payload/*.c_str()*/)) {
          return(MQTT_TOPIC_PUBLISH_OK);
//            Serial.print("Publish Co2 ppm ok (");
//            Serial.print(payload);
//            Serial.println(")");
        } else {
//            Serial.println("Publish on Co2 ppm topic failed");
          return(MQTT_TOPIC_PUBLISH_NOK);
        }
     } else {
        MQTT_Topic_Reconnect(clientName, main_topic);
    }  

}
