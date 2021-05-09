String zona;
const int BT1 = 2;
int value1 = 0;
int value3 = 0;
int conta = 0; 
int led1=13;
int led2=12;
int led3=11;
boolean anterior=false; 
void setup() {
  Serial.begin(9600);
  pinMode(BT1, INPUT);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT); 
}

void loop() {
 delay(20);
 while (Serial.available()==0){
  Contador();
 }

 zona=Serial.readString();
 Serial.println(zona);
 if(zona == "zona1"){
  Zona1();
 }
 if(zona == "zona2"){
  Zona2();
 }
 if(zona == "zona3"){
  Zona3();
 }

}


void Contador(){
  value1 = digitalRead(BT1);  //lectura digital de pin
  if (value1 == HIGH && anterior == false) {
    conta++; //Incrementa el contador
    anterior=true;  
  Serial.println(conta);
  }
  if (value1 == LOW && anterior == true) {
    anterior=false;
  } }
void Zona1(){
  for (value3 = 0; value3 < conta ; value3 += 1) { 
    digitalWrite(led1,HIGH);             
    delay(1000);
    digitalWrite(led1,LOW);
    delay(1000);                      
     }
     value3=0;
     }

void Zona2(){
  for (value3 = 0; value3 < conta ; value3 += 1) { 
    digitalWrite(led2,HIGH);             
    delay(1000);
    digitalWrite(led2,LOW);
    delay(1000);                      
     }
     value3=0;
     }
     
void Zona3(){
  for (value3 = 0; value3 < conta ; value3 += 1) { 
    digitalWrite(led3,HIGH);             
    delay(1000);
    digitalWrite(led3,LOW);
    delay(1000);                      
     }
     value3=0;
     }     
