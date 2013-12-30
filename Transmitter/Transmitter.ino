IntervalTimer timer0;
IntervalTimer timer1;

uint32_t sequence[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 0};
uint32_t i = 0;
uint32_t symbol = 1;
uint32_t flip = 0;

void timerCallback1() {
  symbol = sequence[i%10];
  i++;
}

void timerCallback0() {
  if(symbol) {
    digitalWrite(A9, flip);
    flip = ~flip;
  }
}

/* not working properly at the moment
float freqToMicro(float freq) {
  return (1.0 / 2.0*freq)*1000000.0;
}
*/

void setup() {
  //analogWriteResolution(11);
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
  pinMode(A9, OUTPUT);
  //tone(A9, 21000);
  //analogWriteFrequency(A9, 1000);
  //timer1.begin(timerCallback1, 500000);
  /*
  100 -> 5K
  50 -> 10K
  40 -> 12.5K
  30 -> 16.7K
  25 -> 20k
  24 -> 20.8K
  23 -> 21.7k
  22 -> 22.7k
  21 -> 23.8k
  20 -> 25K
  10 -> 50K
  //306
  20k -> 25
  //310
  20.4k -> 24.5
  //320
  20.8k -> 24
  //304
  21.2k -> 23.585
  //330
  21.6k -> 23.148
  */
  //timer0.begin(timerCallback0, freqToMicro(20000.0));     // microseconds
  //306
  //timer0.begin(timerCallback0, 25);
  //310
  //timer0.begin(timerCallback0, 24.5);
  //320
  //timer0.begin(timerCallback0, 24);
  //304
  //timer0.begin(timerCallback0, 23.585);
  //330
  //timer0.begin(timerCallback0, 23.148);
  //Not a room
  //timer0.begin(timerCallback0, 24);     // microseconds
}

void loop() {
  
}
