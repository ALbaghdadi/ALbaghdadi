#include <SoftwareSerial.h> // serial software library for interfacing gsm module


SoftwareSerial Serial1(10, 11); // RX, TX // connect gsm Tx at D2 and Rx at D3


String url = "";
String ip = "109.224.39.221"; // sparkfun server ip or url
int port = 1239; // sparkfun server port
String SendCmd = "AT+CIPSEND="; // sending number of byte command
String Start = "AT+CIPSTART=\"TCP\""; // TCPIP start command

String instr = "";
String str_sms = "";
String str1 = "";
int i = 0, temp = 0;

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
int x = 0;
int y = 0;
int n = 0;
int minValue = 0;
int maxValue = 0;
char keyPress = 0;
int keyPressTime = 100;
String msg = "";

int IDlocation=5;


float voltageAC=5;
float currentAC=5;
float voltageDC=5;
float currentDC=5;

String alpha = "1!@_$%?ABC2DEF3GHI4JKL5MNO6PQRS7TUV8WXYZ9* 0#";

void setup()
{
  Serial1.begin(9600); // init serial for GSM

Serial.begin(9600);
  Serial.print("Initializing GSM");
  initGSM(); // init GSM module

  Serial.print("Initializing GPRS");
  initGPRS(); // init GPRS in GSM Module
  
  Serial.print("System Ready");
  delay(2000);
}
void loop()
{
  int n = 0;
  
      msg[n] = ' ';

      Serial.print("Data Sending");
      Serial.print("To Server");
      url = "GET /testcode/dht4.php?ID_location=";
      url += IDlocation;
      url += "&voltageAC=";
      url += voltageAC;
      url += "&currentAC=";
      url += currentAC;
      url += "&voltageDC=";
      url += voltageDC;
      url += "&currentDC=";
      url += currentDC;
      url += " HTTP/1.1";
      String svr = Start + "," + ip + "," + port;
      delay(1000);
      connectGSM(svr, "CONNECT");
      Serial.println("Try to connect to servor");
      delay(1000);
      int len = url.length();
      String str = "";
      str = SendCmd + len;
      sendToServer(str);
      Serial1.print(url);
      delay(1000);
      Serial1.write(0x1A);
      delay(1000);
      
      n = 0;
      i = 0;
      x = 0;
      y = 0;
      msg = "";
    }
  



void sendToServer(String str)
{
  Serial1.println(str);
  delay(1000);
}
void initGSM()
{
  connectGSM("AT", "OK");
  connectGSM("ATE1", "OK");
  connectGSM("AT+CPIN?", "READY");
}
void initGPRS()
{
  connectGSM("AT+CIPSHUT", "OK");
  connectGSM("AT+CGATT=1", "OK");
  connectGSM("AT+CSTT=\"net.asiacell.com\",\"\",\"\"", "OK");
  connectGSM("AT+CIICR", "OK");
  delay(1000);
  Serial1.println("AT+CIFSR");
  delay(1000);
}
void connectGSM (String cmd, char *res)
{
  while (1)
  {
    Serial.println(cmd);
    Serial1.println(cmd);
    delay(500);
    while (Serial1.available() > 0)
    {
      if (Serial1.find(res))
      {
        delay(1000);
        return;
      }
    }
    delay(1000);
  }
}



/*
  Public URL
  http://data.sparkfun.com/streams/w5nXxM6rp0tww5YVYg3G
  Public Key
  w5nXxM6rp0tww5YVYg3G
  Private Key
  wY9DPG5vzpH99KNrNkx2
  Keep this key secret, and in a safe place. You will not be able to retrieve it.
  Delete Key
  xxxxxxxxxxxxx
  This key can only be used once. Keep this key secret, and in a safe place. You will not be able to retrieve it.
  Logging using query string parameters
  Format:
  http://data.sparkfun.com/input/[publicKey]?private_key=[privateKey]&log=[value]
  Example:
  http://data.sparkfun.com/input/w5nXxM6rp0tww5YVYg3G?private_key=wY9DPG5vzpH99KNrNkx2&log=22.21
*/
