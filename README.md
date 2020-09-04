# Smart-Watering
![alt text](https://img.shields.io/github/issues/marwinwijaya/Smart-Watering)
![alt text](https://img.shields.io/github/license/marwinwijaya/Smart-Watering)

 Tugas Akhir - Muhamad Arwin Wijaya Teknik Informatika 2016 Institut Teknologi Sumatera

 Penyiraman Otomatis berbasis IoT dengan arsitektur MQTT dan Logika Fuzzy Logic Sugeno

 Alat yang dibutuhkan :
 1. ESP32s
 2. Sensor Suhu - DHT11
 3. Sensor Kelembapan Tanah - YL-69
 4. Relay 2 Pin

Prosedur Install :
 - Install NodeJS
    - https://nodejs.org/en/download/

- Install Node-RED
    - https://github.com/node-red/node-red

- Jalankan Node-RED
    - ``` npm start```

- Install Pallete
    - Pengaturan -> Manage pallete -> Pada menu sidebar pilih **Pallete** -> Pilih tab Install
        - Install Node node-red-contrib-firebase *v1.1.1*
        - Install Node node-red-dashboard *v2.21.0*

- Import **flows.json** pada Node-RED dengan cara 
    - Pengaturan -> Import -> *select a file to import* -> Import
    - Tampilan Node-RED setelah di import
    ![alt text](https://github.com/marwinwijaya/Smart-Watering/blob/master/images/NodeRED.png)
    - Tampilan antarmuka dashboard web
    ![alt text](https://github.com/marwinwijaya/Smart-Watering/blob/master/images/Dashboard.png)

- Library yang dibutuhkan pada Arduino IDE
    - Wifi.h
    - PubSubClient.h

- Pengaturan Arduino IDE bagian *Tools*
    - Board *ESP32 Dev Module*
    - Upload Speed *921600*
    - CPU Frequency *240 MHz (Wifi/BT)*
    - Flash Frequency *80 MHz*
    - Flash Mode *QIO*
    - Flash Size *4 MB (32 Mb)*
    - Partition Scheme *Default 4 MB with spiffs (1.2 MB APP / 1.5 MB SPIFFS)
    - Core Debug Level *None*
    - PSRAM *Disabled*
    - Port *COM Detected*

- Upload file *monitoring.ino* pada ESP32s-Monitoring

- Upload file *controlling.ino* pada ESP32s-Controlling

- Perbandingan nilai fuzzy sistem dengan MathLab
    - Purwarupa Penyiraman Otomatis.fis

- Versi yang digunakan :
    - [x] Node-RED *v1.0.3*
    - [x] NodeJS *v10.18.1*
    - [x] MathLab *v R2008a*
    - [x] Arduino IDE *v1.8.10*
    - [x] Broker Mosquitto *v1.6.7*