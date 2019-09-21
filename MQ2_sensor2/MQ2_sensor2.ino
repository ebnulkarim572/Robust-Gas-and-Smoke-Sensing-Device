int sensorValue;
int GasSensorPin =A0; //Gas Sensor Connection
int buzzerPin=3;
void setup()
{
pinMode(buzzerPin,OUTPUT);
pinMode(GasSensorPin,INPUT);
Serial.begin(9600); // sets the serial port to 9600
}
void sms() {
Serial.begin(9600); //Baud rate of the GSM/GPRS Module
Serial.print("\r");
delay(1000);
Serial.print("AT+CMGF=1\r");
delay(1000);
Serial.print("AT+CMGS=\"+8801------\"\r"); //Number to which you want to send the sms
delay(1000);
Serial.print("Gas detected\r"); //The text of the message to be sent
delay(1000);
Serial.write(0x1A);
delay(1000);
}
void loop()
{
sensorValue = analogRead(GasSensorPin); // read analog input pin 0
Serial.println(sensorValue,DEC); // prints the value read
if(sensorValue<300)
{
Serial.println("No gas");
digitalWrite(buzzerPin,LOW);
}
else
{
//Serial.println("Gas detected");
digitalWrite(buzzerPin,HIGH);
sms();
}
delay(100); // wait 100ms for next reading
}
