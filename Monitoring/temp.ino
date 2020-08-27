//Tab temp untuk mengatur sensor suhu
//Fungsi yang akan dipanggil pada tab program utama
void temp() {
  //Inisialiasi variabel temp yang membaca nilai sensor suhu dengan fungsi readTemperature
  float temp = dht.readTemperature();
  //Inisialisasi variabel realTemp
  float realTemp = temp / 1;

  //Deklarasi variabel tempTemp untuk menyimpan nilai yang akan dikirim dengan MQTT
  static char tempTemp[6];
  //Mengkonversi variabel realTemp (float) menjadi tempTemp (char) dengan 5 char dan 2 angka dibelakang koma (,)
  dtostrf(realTemp, 5, 2, tempTemp);

  //Mengirimkan nilai pada variabel tempTemp dan topic s1 dengan MQTT
  client.publish("s1", tempTemp);

  //Mengoutputkan nilai suhu
  Serial.print(" \t Temperature : ");
  Serial.print(tempTemp);
}
