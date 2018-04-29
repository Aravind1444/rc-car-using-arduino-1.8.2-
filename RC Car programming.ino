int M1a = 2;
int M1b = 3;
int M2a = 4;
int M2b = 5;
int en1 = 6;
int buzzer = 7;
long duration,cm,inches;
#define trigPin 13
#define echoPin 12
#define led1 11
#define led2 10
#define led3 9
#define led4 8
 
 String cmd ="";

void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(M1a, OUTPUT);
  pinMode(M1b, OUTPUT);
  pinMode(M2a, OUTPUT);
  pinMode(M2b, OUTPUT);
  pinMode(en1, OUTPUT);
 

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  
  pinMode(buzzer, OUTPUT);
 
 
}

void loop() 
{

   while (Serial.available()){  //Check if there is an available byte to read
  delay(10); //Delay added to make thing stable
  char c = Serial.read(); //Conduct a serial read
  if (c == '#') {break;} //Exit the loop when the # is detected after the word
  cmd += c; //Shorthand for cmd = cmd + c
  }    
  
  if(cmd.length()>0)
   { 
     Serial.println(cmd);
    if((cmd=="FFFF") || (cmd=="FF") || (cmd=="FFF") || (cmd=="F") )
    {
      digitalWrite(M1a, HIGH);
      digitalWrite(M1b, LOW);
      digitalWrite(M2a, HIGH);
      digitalWrite(M2b, LOW);
      Serial.println("Going Forward");
      }
    else if((cmd=="BBBB")||(cmd=="BBB")||(cmd=="BB")||(cmd=="B"))
    {
      digitalWrite(M1a, LOW);
      digitalWrite(M1b, HIGH);
      digitalWrite(M2a, LOW);
      digitalWrite(M2b, HIGH);
      Serial.println("Going Backward");
    }
if((cmd=="LLLL")||(cmd=="LLL")||(cmd=="LL")||(cmd=="L"))
    {
      digitalWrite(M1a, HIGH);
      digitalWrite(M1b, LOW);
      digitalWrite(M2a, LOW);
      digitalWrite(M2b, HIGH);
      Serial.println("Going Left");
      }
     else if((cmd=="RRRR")||(cmd=="RRR")||(cmd=="RR")||(cmd=="R"))
    {
      digitalWrite(M1a, LOW);
      digitalWrite(M1b, HIGH);
      digitalWrite(M2a, HIGH);
      digitalWrite(M2b, LOW);
      Serial.println("Going right");
      } 
     else if((cmd=="SSSS")||(cmd=="SSS")||(cmd=="SS")||(cmd=="S"))
    {
      digitalWrite(M1a, LOW);
      digitalWrite(M1b, LOW);
      digitalWrite(M2a, LOW);
      digitalWrite(M2b, LOW);
      Serial.println("Going stopping");
      } 
digitalWrite(trigPin, LOW);
  delayMicroseconds(50);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(5000);
  digitalWrite(trigPin, LOW);
  
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
   
  cm = (duration/2) / 29.1;
  inches = (duration/2) / 74; 
  
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  
  delay(250);
}
if((cmd=="BBBB") || (cmd=="BB") || (cmd=="BBB") || (cmd=="B") )
{
tone(buzzer, 1000); // Send 1KHz sound signal...
  delay(1500);        // ...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(100);          

      }
     
     if((cmd=="FFFF") || (cmd=="FF") || (cmd=="FFF") || (cmd=="F") )
    {
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      digitalWrite(led4, HIGH);
      
      } 
     else if((cmd=="BBBB") || (cmd=="BB") || (cmd=="BBB") || (cmd=="B") )
    {
      digitalWrite(led1, LOW);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      digitalWrite(led4, LOW);
      
      } 
      else if((cmd=="SSSS") || (cmd=="SS") || (cmd=="SSS") || (cmd=="S") )
    {
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      digitalWrite(led4, LOW);
      }
      else if((cmd=="RRRR") || (cmd=="RR") || (cmd=="RRR") || (cmd=="R") )
    {
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      digitalWrite(led4, HIGH);
      }
       else if((cmd=="LLLL") || (cmd=="LL") || (cmd=="LLL") || (cmd=="L") )
    {
      digitalWrite(led1, HIGH);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      digitalWrite(led4, LOW);
      }
   cmd="";
   Serial.flush();
    } 




