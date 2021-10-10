// C++ code
//

// establishing variables, A-H correspond to the pins
const int A = 8;
const int B = 9;
const int C = 10;
const int D = 11;
const int E = 4;
const int F = 5;
const int G = 6;
const int H = 7;
int pval = 0;
int inputpin = (A0);
int pval2 = 0;
int i = 0;
int onesdigit = 0;
int tensdigit = 0;
  
void setup()
{ //establishing my pins as outputs, and the input pin for the potentiometer as an input
  
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(H, OUTPUT);
  pinMode(inputpin, INPUT);
  
}

void loop()
{ 
  Serial.begin(9600);
  
// pval represents the value for potentiometer, and reads the input from A0
// Serial.printlm(pval) prints the potentiometer value into the system monitor
  pval = analogRead(inputpin);
  Serial.println(pval);
  delay(1000);
//establishing pval2 as the pval(1023) divided by 10.23 to reach 100%
  pval2 = pval/10.23;
//restricting pval2 to 99 so that it does not return an input larger than 99
  if (pval2 > 99){
    pval2 = 99;
  }
//get the tens digit by dividing by 10 and modulus 10
  tensdigit = pval2/10 % 10;
//get the ones digit through modulus 10
  onesdigit = pval2 % 10;
// Checking to ensure the values are valid
  Serial.println(pval2);
  Serial.println(onesdigit);
  Serial.println(tensdigit);
  Serial.println();
 
  for (i=0; i<=1023; i++){
// getting the ones values to be diplayed through binary representation
    if (onesdigit == 0){
      digitalWrite(G, LOW);
      digitalWrite(H, LOW);
      digitalWrite(E, LOW);
      digitalWrite(F, LOW);
    }

    else if (onesdigit == 1){
      digitalWrite(G, HIGH);
      digitalWrite(H, LOW);
      digitalWrite(E, LOW);
      digitalWrite(F, LOW);
    }

    else if (onesdigit == 2){
      digitalWrite(G, LOW);
      digitalWrite(H, HIGH);
      digitalWrite(E, LOW);
      digitalWrite(F, LOW);
    }

    else if (onesdigit == 3){
      digitalWrite(G, HIGH);
      digitalWrite(H, HIGH);
      digitalWrite(E, LOW);
      digitalWrite(F, LOW);
    }

    else if (onesdigit == 4){
      digitalWrite(G, LOW);
      digitalWrite(H, LOW);
      digitalWrite(E, HIGH);
      digitalWrite(F, LOW);
    }

    else if (onesdigit == 5){
      digitalWrite(G, HIGH);
      digitalWrite(H, LOW);
      digitalWrite(E, HIGH);
      digitalWrite(F, LOW);
    }

    else if (onesdigit == 6){
      digitalWrite(G, LOW);
      digitalWrite(H, HIGH);
      digitalWrite(E, HIGH);
      digitalWrite(F, LOW);
    }

    else if (onesdigit == 7){
      digitalWrite(G, HIGH);
      digitalWrite(H, HIGH);
      digitalWrite(E, HIGH);
      digitalWrite(F, LOW);
    }

    else if (onesdigit == 8){
      digitalWrite(G, LOW);
      digitalWrite(H, LOW);
      digitalWrite(E, LOW);
      digitalWrite(F, HIGH);
    }

    else if (onesdigit == 9){
      digitalWrite(G, HIGH);
      digitalWrite(H, LOW);
      digitalWrite(E, LOW);
      digitalWrite(F, HIGH);
      }
    }
      
}

