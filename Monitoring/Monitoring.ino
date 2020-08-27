//Library Wifi ESP32s
#include <WiFi.h>
//Library MQTT
#include <PubSubClient.h>
//Library SensorDHT11
#include "DHT.h"

//Deklarasi Variabel Network & MQTT
const char* ssid = "Arri";
const char* password = "12345678";
const char* mqtt_server =  "192.168.43.156"; //"192.168.0.101";

//Deklarasi Variabel Sensor DHT11
#define DHTPIN 14
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

//Deklarasi espClient berfungsi untuk menghubungkan dengan MQTT
WiFiClient espClient;
PubSubClient client(espClient);

//Variabel Timer untuk pengiriman data MQTT
long now = millis();
long lastMeasure = 0;

//Fungsi untuk menghubungkan kembali ke MQTT saat belum terhubung
void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    if (client.connect("ESP8266Client")) {
      Serial.println("connected");
    } else {
      Serial.print("failed, rc = ");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

//Fungsi setup yang mengeksekusi hanya satu kali
void setup() {
  //Inisialisasi sensor DHT
  dht.begin();
  //Inisialisasi serial monitor dengan baud rate 115200
  Serial.begin(115200);
  //Menjalankan fungsi setup_wifi yang berada pada tab wifi
  setup_wifi();
  //Inisialisasi MQTT Server
  client.setServer(mqtt_server, 1883);
}

//Fungsi loop yang mengeksekusi berulang-ulang
void loop() {
  //Mengecek konektifitas Wifi dan MQTT
  if (!client.connected()) {
    //jika belum terhubung maka akan menjalankan fungsi reconnect
    reconnect();
  }
  //Mengecek konektifitas Wifi yang berulang
  if (!client.loop())
    //jika tidak berulang maka akan terhubung dengan ID Client ESP32sMonitoring
    client.connect("ESP32sMonitoring");

  //Inisialisasi variabel now dengan millis(waktu internal setiap mili seconds secara independen)
  now = millis();
  
  //Mengirimkan data suhu dan kelembapan tanah setiap 30 detik
  if (now - lastMeasure > 30000) {
    //Insialisasi variabel lastMeasure dengan variabel now
    lastMeasure = now;

    //Menjalankan fungsi soil yang berada pada tab soil
    soil();
    //Menjalankan fungsi temp yang berada pada tab temp
    temp();

    //Mengirimkan pesan enter pada serial monitor
    Serial.println("");
  }
}
