//Tab Wifi untuk mengatur konektifitas
//Fungsi yang akan dipanggil pada tab program utama
void setup_wifi() {
  //Memulai menghubungkan Wifi
  delay(10);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  //Menghubungkan Wifi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  //Mengoutputkan IP ESP32sMonitoring
  Serial.println("");
  Serial.print("WiFi connected - ESP IP address: ");
  Serial.println(WiFi.localIP());
}
