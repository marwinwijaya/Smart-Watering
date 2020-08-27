//Tab soil untuk mengatur sensor kelembapan tanah
//Fungsi yang akan dipanggil pada tab program utama
void soil() {
  //Inisialisasi variabel soil yang membaca nilai analog sensor kelembapan tanah yang berada pada pin 34
  float soil = analogRead(34);
  //Inisialisasi variabel realSoil yang membagi nilai dari variabel soil (basis ESP32s yaitu 2 pangkat 12 hasil maksimal nya 4095) sehingga harus dibagi 4 agar nilai maksimal menjadi 1023.75
  float realSoil = soil / 4;

  //Deklarasi variabel soilTemp untuk menyimpan nilai yang akan dikirim dengan MQTT
  static char soilTemp[7];
  //Mengkonversi variabel realSoil (float) menjadi soilTemp (char) dengan 6 char dan 2 angka dibelakang koma (,)
  dtostrf(realSoil, 6, 2, soilTemp);

  //Mengirimkan nilai pada variabel soilTemp dan topic kt1 dengan MQTT
  client.publish("kt1", soilTemp);

  //Mengoutputkan nilai kelembapan tanah
  Serial.print("Soil Moisture : ");
  Serial.println(soilTemp);

}
