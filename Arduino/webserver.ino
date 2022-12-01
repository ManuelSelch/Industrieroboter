unsigned long lastTimeWebserver = 0;
unsigned long timerDelayWebserver = 3000; // timer 

// server to store data
String serverName = "http://www.manuelmarco.xyz/industrieroboter_2022/";

void webserverGetCode(){
  if ((millis() - lastTimeWebserver) > timerDelayWebserver) {
    //Check WiFi connection status
    if(WiFi.status()== WL_CONNECTED){
      WiFiClient client;
      HTTPClient http;
      http.addHeader("Content-Type", "application/x-www-form-urlencoded");
      
      String serverPath = serverName + "?robot";
      
      // Your Domain name with URL path or IP address with path
      http.begin(client, serverPath.c_str());

      
      // Send HTTP GET request
      int httpResponseCode = http.GET();
      
      if (httpResponseCode>0) {
        Serial.print("HTTP Response code: ");
        Serial.println(httpResponseCode);
        String payload = http.getString();
        Serial.println(payload);
      }
      else {
        Serial.print("Error code: ");
        Serial.println(httpResponseCode);
      }
      // Free resources
      http.end();
    }
    else {
      Serial.println("WiFi Disconnected");
    }
    lastTimeWebserver = millis();
  }
}


void connectWifi(){
  // connect to wifi
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("conecting ...");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  // enable DNS name
  if (MDNS.begin("morse")) {
    Serial.println("MDNS responder started");
  }
}
