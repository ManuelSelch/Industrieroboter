unsigned long lastTimeMorse = 0;
unsigned long timerDelayMorse = 1000; // timer 

void handleGetMorse(){
  if ((millis() - lastTimeMorse) > timerDelayMorse) {
    if(receivingData){
      receiveData();
    }else{
      checkForStartSignal();
    }
    lastTimeMorse = millis();
  }
}

void checkForStartSignal(){
  int val = digitalRead(inputPin);
  if(val == 0){
    startStatus ++;
    Serial.println("0");
  }else{
    startStatus = 0;
  }

  if(startStatus == 2){
    Serial.println("start to receive data");
    receivingData = true;
    currentClock = 0;
  }
}

void receiveData(){
  int val = digitalRead(inputPin);
  Serial.print(currentClock);
  Serial.print(":");
  Serial.println(val);
  code[currentClock] = val;

  if(currentClock == maxClock){
    receivingData = false;
    handleData();
  }
  currentClock ++;
}

void handleData(){
  for(int i=0; i<=maxClock; i++){
    Serial.print(code[i]);
  }
  Serial.println("");
  if(validateData()){
    Serial.println("do stuff");
  }
}

bool validateData(){
  if(code[maxClock] == 0 and code[maxClock-1] == 0){
    Serial.println("code true");
  }else{
    Serial.println("code false");
  }
}
