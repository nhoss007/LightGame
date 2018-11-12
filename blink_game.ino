/*
int led = 12;
int button = 2;
bool state = false;
bool ledState = false;

void setup() {
  // put your setup code here, to run once:
  //state = digitalRead();
  pinMode(led, OUTPUT);
  pinMode(button, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  ledState = digitalRead(led);
  state = digitalRead(button);
  if ( state == true) {
      ledState = !ledState;
  }
  digitalWrite( led, ledState);
}
*/
int led1 = 13;
int led2 = 12;
int led3 = 11;
int led4 = 10;

//int startButton = 1; 

//Player 1 Buttons
int player1Button1 = 8;
int player1Button2 = 7;
int player1Button3 = 6;
int player1Button4 = 5;

//Player 2 Buttons
int player2Button1 = 4; 
int player2Button2 = 3;
int player2Button3 = 2;
int player2Button4 = 9;

int randomNumber;
int gameLength; 

int scorePlayer1;
int scorePlayer2;


void setup() {
  randomSeed(analogRead(0));
  Serial.begin(9600);
  
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);

  
  pinMode(player1Button1, INPUT);
  pinMode(player1Button2, INPUT);
  pinMode(player1Button3, INPUT);
  pinMode(player1Button4, INPUT);

  pinMode(player2Button1, INPUT);
  pinMode(player2Button2, INPUT);
  pinMode(player2Button3, INPUT);
  pinMode(player2Button4, INPUT);
}
 

void loop() {

  if(digitalRead(player1Button1) == HIGH && digitalRead(player2Button1) == HIGH && digitalRead(player1Button2) == HIGH && digitalRead(player2Button2) == HIGH && digitalRead(player1Button3) == HIGH && digitalRead(player2Button3) == HIGH && digitalRead(player2Button4) == HIGH && digitalRead(player2Button4) == HIGH) {

      //reset
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      digitalWrite(led4, LOW);
      scorePlayer1 = 0;
      scorePlayer2 = 0;

    delay(200);
      
    digitalWrite(led1, HIGH);
    delay(550);
    digitalWrite(led1, LOW);
    
    digitalWrite(led2, HIGH);
    delay(550);
    digitalWrite(led2, LOW);
    
    digitalWrite(led3, HIGH);
    delay(550);
    digitalWrite(led3, LOW);
    
    digitalWrite(led4, HIGH);
    delay(550);
    digitalWrite(led4, LOW);
    delay(300);
    
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    delay(550);
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    
    delay(1500);

    gameLength = 20; // GAME LENGTH 
    while ( gameLength >= 0 ) {

         /*
        if(Serial.available() > 0) {
        input = Serial.read();
        }
         if(input == 'r'){
          // FIXME
        }
        */
        
        randomNumber = random(4);
        if(randomNumber == 3 ){
          digitalWrite(led1, HIGH);
          delay(250);
          
          if (digitalRead(player1Button1) == HIGH && digitalRead(led1) == HIGH && digitalRead(player1Button2) == LOW && digitalRead(player1Button3) == LOW && digitalRead(player1Button4) == LOW) {
            scorePlayer1 += 1;
          }
          
          if (digitalRead(player2Button1) == HIGH && digitalRead(led1) == HIGH && digitalRead(player2Button2) == LOW && digitalRead(player2Button3) == LOW && digitalRead(player2Button4) ==LOW ) {
            scorePlayer2 += 1;
          }
         
          
          digitalWrite(led1, LOW);
        }
        else if(randomNumber == 2) {
          digitalWrite(led2, HIGH);
          delay(250);
          
          if (digitalRead(player1Button2) == HIGH && digitalRead(led2) == HIGH && digitalRead(player1Button1) == LOW && digitalRead(player1Button3) == LOW && digitalRead(player1Button4) ==LOW) {
            scorePlayer1 += 1;
          }
         
          if (digitalRead(player2Button2) == HIGH && digitalRead(led2) == HIGH && digitalRead(player2Button1) == LOW && digitalRead(player2Button3) == LOW && digitalRead(player2Button4) ==LOW) {
            scorePlayer2 += 1;
          }
         
          
          digitalWrite(led2, LOW);
        }
        else if(randomNumber == 1) {
          digitalWrite(led3, HIGH);
          delay(250);

          if (digitalRead(player1Button3) == HIGH && digitalRead(led3) == HIGH && digitalRead(player1Button2) == LOW && digitalRead(player1Button1) == LOW && digitalRead(player1Button4) ==LOW) {
            scorePlayer1 += 1;
          }
         
          if (digitalRead(player2Button3) == HIGH && digitalRead(led3) == HIGH && digitalRead(player2Button2) == LOW && digitalRead(player2Button1) == LOW && digitalRead(player2Button4) ==LOW) {
            scorePlayer2 += 1;
          }
         
          
          digitalWrite(led3, LOW);
        }
        else {
          digitalWrite(led4, HIGH);
          delay(250);

          if (digitalRead(player1Button4) == HIGH && digitalRead(led4) == HIGH && digitalRead(player1Button2) == LOW && digitalRead(player1Button3) == LOW && digitalRead(player2Button1) ==LOW) {
            scorePlayer1 += 1;
          }
         
          if (digitalRead(player2Button4) == HIGH && digitalRead(led4) == HIGH && digitalRead(player2Button2) == LOW && digitalRead(player2Button3) == LOW && digitalRead(player2Button1) ==LOW) {
            scorePlayer2 += 1;
          }
        
          digitalWrite(led4, LOW);  
        }

    
    
      delay (350); // DIFFICULTY LEVEL HARD: 0-250   MEDIUM 250-500   EASY 500+
      gameLength--;
    }
    
    if (scorePlayer1 > scorePlayer2) {
      digitalWrite(led1, HIGH);
 
    }
    else if (scorePlayer2 > scorePlayer1) {
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
    }
    else {
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      digitalWrite(led4, HIGH);
    }
    
  }

    Serial.println(scorePlayer1);
    Serial.println(scorePlayer2);

  
}
