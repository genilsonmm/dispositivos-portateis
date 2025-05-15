//Inclusão das bibliotecas
#include <ESP8266WiFi.h>
#include <HCSR04.h>

const char* ssid = "genilson";
const char* password = "genilson123";

WiFiServer server(80); //Porta 80

// Pinos do sensor ultrassônico
const int trigPin = 12; // D6
const int echoPin = 13; // D7
UltraSonicDistanceSensor distanceSensor(trigPin, echoPin); 


const int LED = 5;
int state = LOW;

void setup() {
  Serial.begin(115200);

  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);

  // Connect to Wi-Fi network with SSID and password
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  // Print local IP address and start web server
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();  // Starts the Server
  Serial.println("Server started");
  Serial.print("IP Address of network: "); // Prints IP address on Serial Monitor
  Serial.println(WiFi.localIP());
  Serial.print("Copy and paste the following URL: http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
}

void loop() {
  WiFiClient client = server.available();
  if (!client)
  {
    measureDistance();
    delay(1000);
    return;
  }
  Serial.println("Waiting for new client");
  while(!client.available())
  {
    delay(1);
  }

  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush(); //clean

  Serial.print("Request: ");
  Serial.println(request);
  Serial.print("/LEDON --------------------");
  Serial.println(request.indexOf("/LEDON"));
  Serial.print("/LEDOFF -------------------");
  Serial.println(request.indexOf("/LEDOFF"));
  
  if(request.indexOf("/LEDON") > 1)
  {
    digitalWrite(LED, HIGH); // Turn ON LED
    state = HIGH;
  }
  if(request.indexOf("/LEDOFF") > 1)
  {
    digitalWrite(LED, LOW); // Turn OFF LED
    state = LOW;
  }

  //showHtmlPage(client);
  showJsonData(client);

  
  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");
}

void measureDistance(){
  //Efetua a leitura da distancia em centimetros
    Serial.print("Distancia: ");
    Serial.print(distanceSensor.measureDistanceCm());
    Serial.println(" cm");
}

void showJsonData(WiFiClient client){
  client.println("HTTP/1.1 200 OK");
  client.println("Content-type: application/json"); // Retornando JSON
  client.println("Connection: close");
  client.println();
  client.print("{\"LED\":");
  client.print(state);
  client.print(",\"PIN\":");
  client.print(LED);
  client.println("}");
}

void showHtmlPage(WiFiClient client){
  /*------------------HTML Page Creation---------------------*/

  client.println("HTTP/1.1 200 OK"); 
  client.println("Content-Type: text/html");
  client.println("");
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");

  client.println("<head>");
  client.println("<meta charset=\"UTF-8\">");
  client.println("<title>LED TOGGLE</title>");
  client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
  client.println(".button { background-color: #195B6A; border: none; color: white; padding: 16px 40px;");
  client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
  client.println("</style></head>");
  client.print("<body>");
  client.println("<header id=\"main-header\">");
  client.println("<h1>LED TOGGLE</h1>");
  client.println("<h4>by Genilson Medeiros</h4>");
  client.println("</header>");

  if(state == HIGH)
  {
    client.println("ON");
  }
  else
  {
    client.println("OFF");
  }

  client.println("");
  client.print("<p>Distância: ");
  client.print(distanceSensor.measureDistanceCm());
  client.print("</p>");

  client.print("<br>");
  client.print("<br>");
  client.println("<a href=\"/LEDON\"\"><button class=\"button\">ON</button></a>");
  client.println("<a href=\"/LEDOFF\"\"><button class=\"button\">OFF</button></a>");
  client.print("</body>");
  client.println("</html>");
}
