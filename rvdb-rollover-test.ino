void setup() {
  Serial.begin(115200);
//  Serial.println("\n.. and then it begins ...\r\n");˜
  Serial.printf("StartTime[%02d:%02d:%03d]\r\n" , ((millis() / (60 * 1000)) % 60)
                                                , ((millis() / 1000) % 60)
                                                , (millis() % 1000));


}

// put your main code here, to run repeatedly:
String DecimalToBinaryStringalToBin(uint16_t b)
{
    String binary {};
    uint16_t mask = 0x8000;
    
    while (mask)
    {
        binary += ((b & mask) ?  '1':'0' );     
        mask >>= 1;
    }
    return binary;
}


void loop() {

  int32_t t=0;
  uint16_t timer = 65000;
  uint16_t timer_interval = 53;
  uint16_t timer_tick = 3;
  uint16_t timer_due = 0;

  timer_due = timer + timer_interval;
  while (t<400) {
    timer += timer_tick;
    Serial.printf("[%5d] [%5d] [%5d] [%5d] [%5d] [%5d]", t, timer, timer_due, timer_interval, (int16_t)(timer - timer_due), (uint16_t)(timer - timer_due));
    if ((int16_t)(timer - timer_due) >= 0) 
    {
      Serial.printf(" timer due - timer [%5d] timer_due [5%d] timer_interval [%5d]", timer, timer_due, timer_interval);
      timer_due += timer_interval;
      Serial.printf(" next: timer_due [%5d]", timer_due);
// niet echt nodig volgens mij, maar je zou het verschil kunnen skippen...
//      while ((int16_t)(timer - timer_due) >= 0)  {
//        Serial.printf(" /r/ntimer skip - timer [%5d] timer_due [5%d] timer_interval [%5d]", timer, timer_due, timer_interval);
//        timer_last += timer_interval;      
//      }
    }
//    if ((timer_due - timer) & 0x8000) Serial.print(" MSB = 1 -- timer - overflow");
    t++;
//    Serial.printf(" [%5d]", i);
//    Serial.printf(" [%s]", DecimalToBinaryStringalToBin(i).c_str());
    Serial.println();
    delay(1000/30); 
  }

  while(true){
    yield();
  }
}
