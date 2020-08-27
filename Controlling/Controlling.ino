//Library Wifi ESP32s
#include <WiFi.h>
//Library MQTT
#include <PubSubClient.h>

//Deklarasi Variabel Network & MQTT
const char* ssid = "Arri";
const char* password = "12345678";
const char* mqtt_server = "192.168.43.156"; //"192.168.0.101"; 

//Deklarasi variabel pin relay pada pin 14
const int relay = 14;

//Deklarasi espClient berfungsi untuk menghubungkan dengan MQTT
WiFiClient espClient;
PubSubClient client(espClient);

//Fungsi setup yang mengeksekusi hanya satu kali
void setup() {
  //Inisialisasi serial monitor dengan baud rate 115200
  Serial.begin(115200);
  //Menjalankan fungsi setup_wifi yang berada pada tab wifi
  setup_wifi();
  //Inisialisasi MQTT Server
  client.setServer(mqtt_server, 1883);
  //Inisialisasi callback sebagai subscriber
  client.setCallback(callback);
  //Inisialisasi pin relay sebagai output
  pinMode(relay, OUTPUT);
}

//Fungsi loop yang mengeksekusi berulang-ulang
void loop() {
  //Mengecek konektifitas Wifi dan MQTT
  if (!client.connected()) {
    //jika belum terhubung maka akan menjalankan fungsi reconnect pada tab mqtt
    reconnect();
  }
  //Mengecek konektifitas Wifi yang berulang
  if (!client.loop())
    //jika tidak berulang maka akan terhubung dengan ID Client ESP32sControlling
    client.connect("ESP32sControlling");
}
