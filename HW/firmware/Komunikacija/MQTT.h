#ifndef  MQTT_h
#define  MQTT_h

#define MQTT_TOPIC_CONNECT_OK   1
#define MQTT_TOPIC_CONNECT_NOK  0
#define MQTT_BROKER_OK          1
#define MQTT_TOPIC_PUBLISH_OK   1
#define MQTT_TOPIC_PUBLISH_NOK  0

#define WIFI_CONNECTED      1
 
class MQTT{
  public:
    int WiFi_Connect(char *ssid, char *pass);
    int MQTT_Broker_Set(char *brokerAdd, int port);
    int MQTT_Topic_Connect(char *clientName);
    int MQTT_Topic_Reconnect(char *clientName, char *main_topic);
    int MQTTPublish(char * topic, char *payload, char *clientName, char *main_topic);

};
#endif
