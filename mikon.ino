#include <ESP8266WiFi.h>        // Include the Wi-Fi library
#include <ESP8266HTTPClient.h>
//#include <WiFiClient.h>
#define HOST "192.168.137.1"          // Enter HOST URL without "http:// "  and "/" at the end of URL

const char* ssid     = "DESKTOP-4IP5KD8 0072";         // The SSID (name) of the Wi-Fi network you want to connect to
const char* password = "wifippicrusak";     // The password of the Wi-Fi network



//String sendval, sendval2, sendval3, postData, serverName;

void setup() {
  pinMode(D4, OUTPUT);
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
  int sensorValue1 = digitalRead(D2);
  int sensorValue2 = digitalRead(D3);

  int sendlev1 = 0;  // Inisialisasi sendlev1 air

  // Kondisi sendlev1 air
  if (sensorValue1 == HIGH && sensorValue2 == HIGH) {
    sendlev1 = 3;  // Penuh
  } else if (sensorValue1 == HIGH && sensorValue2 == LOW) {
    sendlev1 = 2;  // Setengah
  } else if (sensorValue1 == LOW && sensorValue2 == LOW) {
    sendlev1 = 1;  // Habis
  }

  // Tampilkan kondisi level air
  switch (sendlev1) {
    case 1:
      Serial.println("Level air: Habis");
      break;
    case 2:
      Serial.println("Level air: Setengah");
      break;
    case 3:
      Serial.println("Level air: Penuh");
      break;
    default:
      Serial.println("Kondisi level air tidak valid");
      break;
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

postData = "&r1lev=" + sendlev1 ;
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
