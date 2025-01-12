#include <ESP8266WiFi.h>

String writeAPIKey = "7W6T2QOMYPF6RHFQ";
const char *ssid = "Xuong STEM";
const char *password = "@xuongstem";
const char* server = "api.thingspeak.com";
int dem,c1,c2,c3;
WiFiClient client;
String myString; // complete message from arduino, which consistors of snesors data
char rdata; // received charactors
int firstVal, secondVal,thirdVal; //sensorSt
String chuoi1,chuoi2,chuoi3;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(1000);

  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid,password);
  while (WiFi.status() !=WL_CONNECTED)  {
    delay(2000);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address");
  Serial.println(WiFi.localIP());

}

void loop() {
  // put your main code here, to run repeatedly:
    if (Serial.available()>0) {
    rdata = Serial.read(); 
    if(rdata=='*')
    {
 if (client.connect(server, 80)) {  // Kết nối đến server ThingSpeak
    // Tạo giá trị ngẫu nhiên để gửi đi
    int value1 = random(10, 100);

    // Tạo HTTP request
    String httpRequest = String("GET /update?api_key=") + writeAPIKey + "&field1=0 HTTP/1.1\r\n" +
                         "Host: " + server + "\r\n" +
                         "Connection: close\r\n\r\n";

    // Gửi HTTP request
    client.print(httpRequest);
    Serial.println("HTTP request sent");

    // Đọc phản hồi từ server
    while (client.connected() || client.available()) {
      if (client.available()) {
        String line = client.readStringUntil('\n');
        Serial.println(line);
      }
    }
    client.stop();
  } else {
    Serial.println("Connection failed");
  }

  
  // thingspeak needs minimum 15 sec delay between updates
  delay(20000);
  Serial.println("done send");
  }
    }
  //thinkspeak

}

String getValue(String data, char separator, int index)
{
    int found = 0;
    int strIndex[] = { 0, -1 };
    int maxIndex = data.length() - 1;
 
    for (int i = 0; i <= maxIndex && found <= index; i++) {
        if (data.charAt(i) == separator || i == maxIndex) {
            found++;
            strIndex[0] = strIndex[1] + 1;
            strIndex[1] = (i == maxIndex) ? i+1 : i;
        }
    }
    return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}
