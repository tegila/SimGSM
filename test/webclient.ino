/*
  Web client

 This sketch connects to a website (http://www.google.com)
 using an Arduino SIM908 shield. 

 Circuit:
 * SIM908 shield attached to Serial2 (Arduino Mega), power pin = 5

 Adapted 05 Mar 2013
 by Anderson Santos
 Original by David A. Mellis

 */

#include <SPI.h>
#include <GPRSClient.h>
#include <SimGSM.h>

// Initialize the GSM client library
// with the IP address and port of the server 
// that you want to connect to (port 80 is default for HTTP):
SimGSM gsm(Serial2);
GPRSClient client(gsm);

void setup() {
  Serial.println("Setting up...");
  //Open serial communications:
  Serial.begin(9600);

  // start the Ethernet connection:
  gsm.begin(2400);
  gsm.powerToggle();
  //Change with your settings APN, USER, PASS
  client.setParams("zap.vivo.com.br","vivo","vivo");
  delay(5000);
/*
  Serial.println("connecting...");
  // if you get a connection, report back via serial:
  if (client.connect("www.google.com", 80)) {
    Serial.println("connected");
    // Make a HTTP request:
    client.println("GET /search?q=arduino HTTP/1.0");
    client.println();
  } 
  else {
    // kf you didn't get a connection to the server:
    Serial.println("connection failed");
  }
*/
}

void loop()
{
  gsm.powerToggle();

  // if there are incoming bytes available 
  // from the server, read them and print them:
  if (client.available()) {
    Serial.println("client avalilabe");
    char c = client.read();
    Serial.print(c);
  } else {
    Serial.println("client NOT avalilabe");
  }

  // if the server's disconnected, stop the client:
  if (!client.connected()) {
    Serial.println();
    Serial.println("disconnecting...");
    client.stop();
  } else {
    Serial.println("client connected...");
  }
}
