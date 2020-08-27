//Tab MQTT untuk mengatur MQTT
//Fungsi yang akan dipanggil pada tab program utama

//Inisialisasi variabel statPompa untuk mengirimkan kondisi pompa dengan MQTT
static char statPompa[3];

//Inisialisasi variabel statusPompa untuk mengatur kondisi pompa
int statusPompa;

//Fungsi untuk menghubungkan kembali ke MQTT saat belum terhubung
void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");

    //Indentifikasi ID Client
    if (client.connect("ESP32sControlling")) {
      Serial.println("connected");

      //Subscribe topic
      client.subscribe("control");
      client.subscribe("control/pompa1");
      client.subscribe("control/pompa2");
      client.subscribe("control/pompa3");
    } else {
      Serial.print("failed, rc = ");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");

      delay(5000);
    }
  }
}

//Fungsi untuk membaca pesan dari publish
void callback(String topic, byte* message, unsigned int length) {
  Serial.print("Message arrived on topic: ");
  Serial.print(topic);
  Serial.print(". Message: ");
  String messageTemp;

  for (int i = 0; i < length; i++) {
    Serial.print((char)message[i]);
    messageTemp += (char)message[i];
  }
  Serial.println();

  if (topic == "control") {
    Serial.print("Changing Pompa to ");
    if (messageTemp == "false") {
      digitalWrite(relay, HIGH);
      Serial.print("On");
      statusPompa = 100;
      dtostrf(statusPompa, 3, 0, statPompa);
      client.publish("statusPompa", statPompa);
    }
    else if (messageTemp == "true") {
      digitalWrite(relay, LOW);
      Serial.print("Off");
      statusPompa = 0;
      dtostrf(statusPompa, 3, 2, statPompa);
      client.publish("statusPompa", statPompa);
    }
  }

  if (topic == "control/pompa1") {
    Serial.print("Changing Pompa to ");
    if (messageTemp == "true") {
      statusPompa = 100;
      dtostrf(statusPompa, 3, 0, statPompa);
      client.publish("statusPompa", statPompa);

      digitalWrite(relay, HIGH);
      Serial.println("On");
      Serial.println("Melakukan penyiraman sedikit selama 5 Detik");
      delay(5000);

      statusPompa = 0;
      dtostrf(statusPompa, 3, 2, statPompa);
      client.publish("statusPompa", statPompa);

      Serial.print("Changing Pompa to ");
      digitalWrite(relay, LOW);
      Serial.println("Off");
    }
  }

  if (topic == "control/pompa2") {
    Serial.print("Changing Pompa to ");
    if (messageTemp == "true") {
      statusPompa = 100;
      dtostrf(statusPompa, 3, 0, statPompa);
      client.publish("statusPompa", statPompa);

      digitalWrite(relay, HIGH);
      Serial.println("On");
      Serial.println("Melakukan penyiraman sedikit selama 7.5 Detik");
      delay(7500);

      statusPompa = 0;
      dtostrf(statusPompa, 3, 2, statPompa);
      client.publish("statusPompa", statPompa);

      Serial.print("Changing Pompa to ");
      digitalWrite(relay, LOW);
      Serial.println("Off");
    }
  }

  if (topic == "control/pompa3") {
    Serial.print("Changing Pompa to ");
    if (messageTemp == "true") {
      statusPompa = 100;
      dtostrf(statusPompa, 3, 0, statPompa);
      client.publish("statusPompa", statPompa);

      digitalWrite(relay, HIGH);
      Serial.println("On");
      Serial.println("Melakukan penyiraman sedikit selama 10 Detik");
      delay(10000);

      statusPompa = 0;
      dtostrf(statusPompa, 3, 2, statPompa);
      client.publish("statusPompa", statPompa);

      Serial.print("Changing Pompa to ");
      digitalWrite(relay, LOW);
      Serial.println("Off");
    }
  }
  Serial.println();
}
