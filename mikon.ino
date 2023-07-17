#include <ESP8266WiFi.h>        // Include the Wi-Fi library
#include <ESP8266HTTPClient.h>
//#include <WiFiClient.h>
#define HOST "192.168.137.1"          // Enter HOST URL without "http:// "  and "/" at the end of URL

const char* ssid     = "DESKTOP-4IP5KD8 0072";         // The SSID (name) of the Wi-Fi network you want to connect to
const char* password = "wifippicrusak";     // The password of the Wi-Fi network

const int infraredPin1 = D5;  // Pin sensor infrared FC-51 (input)
const int infraredPin2 = D6;  // Pin sensor infrared FC-51 (input)
const int ledPin = D4;  // Pin LED (output)

int sendlev1, sendlev2, sendlev3, sendlev4, sendlev5, sendlev6, sendlev7, sendlev8, sendlev9, sendlev10;
int sendlev11, sendlev12, sendlev13, sendlev14, sendlev15, sendlev16, sendlev17, sendlev18, sendlev19, sendlev20;
int sendlev21, sendlev22, sendlev23, sendlev24, sendlev25, sendlev26, sendlev27, sendlev28, sendlev29, sendlev30;
int sendlev31, sendlev32, sendlev33, sendlev34, sendlev35, sendlev36, sendlev37, sendlev38, sendlev39, sendlev40;
int sendlev41, sendlev42, sendlev43, sendlev44, 
// sendlev45, 
sendlev46, sendlev47;

String 
// sendlev1,
// sendlev2,
// sendlev3,
// sendlev4,
// sendlev5,
// sendlev6,
// sendlev7,
// sendlev8,
// sendlev9,
// sendlev10,

// sendlev11,
// sendlev12,
// sendlev13,
// sendlev14,
// sendlev15,
// sendlev16,
// sendlev17,
// sendlev18,
// sendlev19,
// sendlev20,

// sendlev21,
// sendlev22,
// sendlev23,
// sendlev24,
// sendlev25,
// sendlev26,
// sendlev27,
// sendlev28,
// sendlev29,
// sendlev30,

// sendlev31,
// sendlev32,
// sendlev33,
// sendlev34,
// sendlev35,
// sendlev36,
// sendlev37,
// sendlev38,
// sendlev39,
// sendlev40,

// sendlev41,
// sendlev42,
// sendlev43,
// sendlev44,
sendlev45,
// sendlev46,
// sendlev47,


postData, serverName;

void setup() {
  pinMode(D5, INPUT);
  pinMode(D6, INPUT);
  pinMode(D4, OUTPUT);
  pinMode(ledPin, OUTPUT); // Pin LED (output)
  Serial.begin(115200);         // Start the Serial communication to send messages to the computer
  delay(10);
  Serial.println('\n');
  digitalWrite(D4, HIGH);
  WiFi.begin(ssid, password);             // Connect to the network
  Serial.print("Connecting to ");
  Serial.print(ssid); Serial.println(" ...");

  int i = 0;
  while (WiFi.status() != WL_CONNECTED) { // Wait for the Wi-Fi to connect
    delay(1000);
    Serial.print(++i); Serial.print(' ');
  }

  Serial.println('\n');
  Serial.println("Connection established!");  
  Serial.print("IP address:\t");
  Serial.println(WiFi.localIP());         // Send the IP address of the ESP8266 to the computer

}

void loop() {
  int sensorValue1 = digitalRead(D5);
  int sensorValue2 = digitalRead(D6);

  int level45 = 0;  // Inisialisasi sendlev1 air

  // Kondisi sendlev1 
  if (sensorValue1 == LOW && sensorValue2 == LOW) {
    level45 = 3;  // Penuh
  } else if (sensorValue1 == LOW && sensorValue2 == HIGH) {
    level45 = 2;  // Setengah
  } else if (sensorValue1 == HIGH && sensorValue2 == HIGH) {
    level45 = 1;  // Habis
  }

  String bring45;

  if (level45 == 3){
      bring45 = "Penuh";
  } else if (level45 == 2){
      bring45 = "Setengah";
  } else if (level45 == 1){
      bring45 = "Habis";
  }



  // Tampilkan kondisi level air
  switch (level45) {
    case 1:
      Serial.println("Level Paper: Habis");
      break;
    case 2:
      Serial.println("Level Paper: Setengah");
      break;
    case 3:
      Serial.println("Level Paper: Penuh");
      break;
    default:
      Serial.println("Kondisi level Paper tidak valid");
      break;
  }

sendlev45= bring45;

// sendlev1 = random(1, 4);

int randomValue;

// Generate random values for sendlev1, sendlev2, sendlev3, and so on
randomValue = random(1, 4);
String sendlev1;
if (randomValue == 1) {
  sendlev1 = "Penuh";
} else if (randomValue == 2) {
  sendlev1 = "Setengah";
} else if (randomValue == 3) {
  sendlev1 = "Habis";
}

sendlev2 = random(1, 4);
sendlev3 = random(1, 4);
sendlev4 = random(1, 4);
sendlev5 = random(1, 4);
sendlev6 = random(1, 4);
sendlev7 = random(1, 4);
sendlev8 = random(1, 4);
sendlev9 = random(1, 4);
sendlev10 = random(1, 4);
sendlev11 = random(1, 4);

// sendlev12 = random(1, 4);

randomValue = random(1, 4);
String sendlev12;
if (randomValue == 1) {
  sendlev12 = "Penuh";
} else if (randomValue == 2) {
  sendlev12 = "Setengah";
} else if (randomValue == 3) {
  sendlev12 = "Habis";
}

sendlev13 = random(1, 4);
sendlev14 = random(1, 4);
sendlev15 = random(1, 4);
sendlev16 = random(1, 4);
sendlev17 = random(1, 4);
sendlev18 = random(1, 4);
sendlev19 = random(1, 4);
sendlev20 = random(1, 4);

sendlev21 = random(1, 4);
sendlev22 = random(1, 4);
sendlev23 = random(1, 4);
sendlev24 = random(1, 4);
sendlev25 = random(1, 4);

// sendlev26 = random(1, 4);

randomValue = random(1, 4);
String sendlev26;
if (randomValue == 1) {
  sendlev26 = "Penuh";
} else if (randomValue == 2) {
  sendlev26 = "Setengah";
} else if (randomValue == 3) {
  sendlev26 = "Habis";
}

sendlev27 = random(1, 4);
sendlev28 = random(1, 4);
sendlev29 = random(1, 4);
sendlev30 = random(1, 4);

sendlev31 = random(1, 4);
sendlev32 = random(1, 4);
sendlev33 = random(1, 4);
sendlev34 = random(1, 4);
sendlev35 = random(1, 4);
sendlev36 = random(1, 4);
sendlev37 = random(1, 4);
sendlev38 = random(1, 4);
sendlev39 = random(1, 4);
sendlev40 = random(1, 4);

sendlev41 = random(1, 4);
sendlev42 = random(1, 4);
sendlev43 = random(1, 4);
sendlev44 = random(1, 4);
// sendlev45 = random(1, 4);
sendlev46 = random(1, 4);

// sendlev47 = random(1, 4);

randomValue = random(1, 4);
String sendlev47;
if (randomValue == 1) {
  sendlev47 = "Penuh";
} else if (randomValue == 2) {
  sendlev47 = "Setengah";
} else if (randomValue == 3) {
  sendlev47 = "Habis";
}


WiFiClient client;
const int httpPort = 80;
if (!client.connect(HOST, httpPort)) {
  Serial.println("connection failed");
  return;
}
if (WiFi.status()== WL_CONNECTED)
{
HTTPClient http; 

postData = 
  "&r1lev=" + String(sendlev1) +
  "&r2lev=" + String(sendlev2) +
  "&r3lev=" + String(sendlev3) +
  "&r4lev=" + String(sendlev4) +
  "&r5lev=" + String(sendlev5) +
  "&r6lev=" + String(sendlev6) +
  "&r7lev=" + String(sendlev7) +
  "&r8lev=" + String(sendlev8) +
  "&r9lev=" + String(sendlev9) +
  "&r10lev=" + String(sendlev10) +

  "&r11lev=" + String(sendlev11) +
  "&r12lev=" + String(sendlev12) +
  "&r13lev=" + String(sendlev13) +
  "&r14lev=" + String(sendlev14) +
  "&r15lev=" + String(sendlev15) +
  "&r16lev=" + String(sendlev16) +
  "&r17lev=" + String(sendlev17) +
  "&r18lev=" + String(sendlev18) +
  "&r19lev=" + String(sendlev19) +
  "&r20lev=" + String(sendlev20) +

  "&r21lev=" + String(sendlev21) +
  "&r22lev=" + String(sendlev22) +
  "&r23lev=" + String(sendlev23) +
  "&r24lev=" + String(sendlev24) +
  "&r25lev=" + String(sendlev25) +
  "&r26lev=" + String(sendlev26) +
  "&r27lev=" + String(sendlev27) +
  "&r28lev=" + String(sendlev28) +
  "&r29lev=" + String(sendlev29) +
  "&r30lev=" + String(sendlev30) +

  "&r31lev=" + String(sendlev31) +
  "&r32lev=" + String(sendlev32) +
  "&r33lev=" + String(sendlev33) +
  "&r34lev=" + String(sendlev34) +
  "&r35lev=" + String(sendlev35) +
  "&r36lev=" + String(sendlev36) +
  "&r37lev=" + String(sendlev37) +
  "&r38lev=" + String(sendlev38) +
  "&r39lev=" + String(sendlev39) +
  "&r40lev=" + String(sendlev40) +

  "&r41lev=" + String(sendlev41) +
  "&r42lev=" + String(sendlev42) +
  "&r43lev=" + String(sendlev43) +
  "&r44lev=" + String(sendlev44) +
  "&r45lev=" + String(sendlev45) +
  "&r46lev=" + String(sendlev46) +
  "&r47lev=" + String(sendlev47)

;
// postData = "&r1tempc=" + sendval ;
// We can post values to PHP files as  example.com/dbwrite.php?name1=val1&name2=val2&name3=val3
// Hence created variable postDAta and stored our variables in it in desired format
// For more detials, refer:- https://www.tutorialspoint.com/php/php_get_post.htm

// Update Host URL here:-  
serverName = "http://192.168.137.1/post-fc51-db.php";  
http.begin(client, serverName);              // Connect to host where MySQL databse is hosted
http.addHeader("Content-Type", "application/x-www-form-urlencoded");            //Specify content-type header

  
 
int httpCode = http.POST(postData);   // Send POST request to php file and store server response code in variable named httpCode
//Serial.println("Values are, sendval = " + sendval + " and sendval2 = "+sendval2, + " and sendval3 = "+sendval3, + " and sendval4 = "+ sendval4 );


// if connection eatablished then do this
if (httpCode == 200) { Serial.println("Values uploaded successfully."); Serial.println(httpCode); Serial.println(postData);
//String webpage = http.getString();    // Get html webpage output and store it in a string
//Serial.println(webpage + "\n"); 
}

// if failed to connect then return and restart

else { 
  Serial.println(httpCode); 
  Serial.println("Failed to upload values. \n"); 
  http.end(); 
  return; }
unsigned long timeout = millis();
while (client.available() == 0) {
  if (millis() - timeout > 1000) {
    Serial.println(">>> Client Timeout !");
    client.stop();
    return;
  }
}
delay(1000); 
digitalWrite(D4, LOW);
delay(100);
digitalWrite(D4, HIGH);
delay (2000);
}
  delay(1000); // Jeda 1 detik
}
