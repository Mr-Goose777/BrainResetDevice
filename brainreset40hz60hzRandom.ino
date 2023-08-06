#include <elapsedMillis.h>

int ontime60hz = 500;     // LED ON-Cycle in 60 Hz mode Microseconds (low value makes the flicker more visible (good), but reduces apparent brigtness)
int ontime40hz = 1000;    // LED ON-Cycle in 60 Hz mode Microseconds (low value makes the flicker more visible (good), but reduces apparent brigtness)
int floatingpin = 0;      // "True" random number generator stuff, too lazy to comment
const int emptypin = A5;  // floating pin for "true" RNG.
void setup() {
  // put your setup code here, to run once:
  pinMode(3, OUTPUT);   // LED outer right
  pinMode(5, OUTPUT);   // LED mittle right
  pinMode(6, OUTPUT);   // LED outer left
  pinMode(9, OUTPUT);   // LED mittle left
  pinMode(A0, OUTPUT);  // Capacitive speaker  right
  pinMode(A1, OUTPUT);  // Capacitive speaker left
  randomSeed(23);       // "True" random number generator stuff, too lazy to comment
}


void loop() {

  elapsedMillis timeElapsed;
  unsigned int interval = 5000;  //one minute in ms, You could have different intervals by uncommenting the lines below and adjusting the intervals manually.


  while (timeElapsed < 3000) {  // do this much random Flash mode in ms
    randomflash();
  }
  timeElapsed = 0;
  while (timeElapsed < interval * 2) {  // do this 40Hz Flash mode in ms
    fortyhertz();
  }
  timeElapsed = 0;
  while (timeElapsed < interval * 3) {  // do this much 60Hz flash in MS
    sixtyhz();
  }
  timeElapsed = 0;
}

void sixtyhz() {
  int compensation = 2000 + 333 - ontime60hz;  // the cycle is supposed to be 16,666666667 ms, and it is, too lazy to comment, use a guitar tuner or something, IT IS 60 HZ ok?
  // put your main code here, to run repeatedly:
  digitalWrite(3, HIGH); // turning stuff on one side on
  digitalWrite(9, HIGH); // same
  digitalWrite(A0, HIGH); // same
  delayMicroseconds(ontime60hz); 
  digitalWrite(3, LOW); // turning stuff off
  digitalWrite(9, LOW); 
  digitalWrite(A0, LOW);
  delayMicroseconds(compensation);
  delay(6);  
  digitalWrite(5, HIGH); // turning suff on and off on the other side 180 degrees out of sync
  digitalWrite(6, HIGH);
  digitalWrite(A1, HIGH);
  delayMicroseconds(ontime60hz);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(A1, LOW);
  delayMicroseconds(compensation);
  delay(6);  //LED off for 14 ms
}

void fortyhertz() {
  int compensation = 2000 - ontime40hz;
  // put your main code here, to run repeatedly:
  digitalWrite(3, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(A0, HIGH);
  delayMicroseconds(ontime40hz);  //LED on for 2 ms
  digitalWrite(3, LOW);
  digitalWrite(9, LOW);
  digitalWrite(A0, LOW);
  delayMicroseconds(compensation);
  delay(10);  //LED off for 14 ms
  delayMicroseconds(500);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(A1, HIGH);
  delayMicroseconds(ontime40hz);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(A1, LOW);
  delayMicroseconds(compensation);
  delay(10);  //LED off for 14 ms
  delayMicroseconds(500);
}

void randomflash() {
  // "true" random number generator (it's definitely much more random than the built in one)
  int intensity = 10; // LED intensity for the random flashing, too bright would be truely utterly annoying.
  floatingpin = analogRead(emptypin);
  int randNum = random(16, 125);  //random number between 16 and 125. represents milliseconds. 16 milliseconds is the whole cycle of 62.5 Hz, 125 is the cycle of a frequency of 8 Hz. So you get flickering between 8 and 62 Hz. If you want to change it, the calculaton is 1000 / frequency-you want = the lenght of cycle. like 1000 / 2 Hz = 500 (ms)

  randomSeed(randNum / (randNum * (randNum * floatingpin)));  //random seed generator thing
  int half = randNum / 2;                                     //divide whole cycle by 2 for very obvious reasons.
  analogWrite(3, intensity);
  analogWrite(5, intensity);
  analogWrite(6, intensity);
  analogWrite(9, intensity);
  digitalWrite(A0, HIGH);
  digitalWrite(A1, HIGH);//Led goes whee for half of the cycle lenght.
  delay(half);
  analogWrite(3, 0);
  analogWrite(5, 0);
  analogWrite(6, 0);
  analogWrite(9, 0);
  digitalWrite(A0, LOW);
  digitalWrite(A1, LOW);
  delay(half);
}
