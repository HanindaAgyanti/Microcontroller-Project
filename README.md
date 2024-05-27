<h1 align="left">
  Audio Sistem Pengingat Penyiraman Tanaman
<br></br>
<img src="https://github.com/HanindaAgyanti/Microcontroller-Project/blob/main/Audio%20Sistem%20Pengingat%20Penyiram%20Tanaman/bahan-readme/AUDIO%20PENGINGAT%20PENYIRAM%20TANAMAN.png">
</h1>

## Daftar Isi
* <a href="#deskripsi">Deskripsi</a>
* <a href="#komponen">Komponen</a>
* <a href="#electric">Electric</a>
  - <a href="#simulasi-tinkercad">Simulasi Tinkercad</a>
  - <a href="#schematic">Schematic</a>
  - <a href="#pcb">PCB</a>
  - <a href="#audio">Audio</a>
* <a href="#3d-design">3D Design</a>
  - <a href="#preview-img">Preview Img</a>
* <a href="#program">Program</a>
  - <a href="#flowchart">Flowchart</a>
  - <a href="arduino-program">Arduino Program</a>
* <a href="#progress">Progress</a>
* <a href="#social-media">Social Media</a>
<br></br>

## Deskripsi
<div align="justify">
Sebuah projek mata kuliah Workshop Mikrokontroler membuat Sistem Pendeteksi Penyiram Tanaman diharap mampu membantu masyarakat diberbagai kalangan usia untuk dapat menentukan waktu yang tepat dalam menyiram tanaman yang dapat dikontrol dengan sensor kelembapan. Dengan adanya project ini juga dapat mencapai lingkungan khususnya pada taman ataupun tanaman dapat lebih segar dan tidak layu. Project ini juga sangat bermanfaat bagi kalangan pertanian, perkebunan, serta perladangan.
</div><br></br>

## Komponen
### 1. Arduino Uno
<img src="https://github.com/HanindaAgyanti/Microcontroller-Project/blob/main/Audio%20Sistem%20Pengingat%20Penyiram%20Tanaman/bahan-readme/nekhil-r-hz7EFrw06Qk-unsplash.jpg" width="400">
<div align = "justify">
Arduino Uno adalah salah satu papan mikrokontroler paling populer dan mudah digunakan untuk pemula serta pengembang berpengalaman. Arduino Uno dirancang berdasarkan mikrokontroler ATmega328P dari Microchip. Berikut adalah penjelasan lebih rinci tentang Arduino Uno:

Fitur Utama Arduino Uno
Mikrokontroler:

ATmega328P
Tegangan Operasional:

7-12V
Tegangan Input:

6-20V
Pin Digital I/O:

14 (termasuk 6 pin PWM)
Pin Analog Input:

6 (A0 hingga A5)
Arus Maksimum per Pin I/O:

40 mA
Arus untuk Pin 3.3V:

50 mA
Memori:

Flash Memory: 32 KB (0.5 KB digunakan oleh bootloader)
SRAM: 2 KB
EEPROM: 1 KB
Clock Speed:

16 MHz
</div><br></br>

### 2. Soil Moisture Sensor
<img src="https://github.com/HanindaAgyanti/Microcontroller-Project/blob/main/Audio%20Sistem%20Pengingat%20Penyiram%20Tanaman/bahan-readme/Sensor_Hygrometer_Detection_Humidity.jpg" width="400">
<div align = "justify">

Sensor kelembaban tanah (soil moisture sensor) adalah alat yang digunakan untuk mengukur kadar air dalam tanah. Sensor ini sangat berguna dalam aplikasi seperti sistem irigasi otomatis, pemantauan kondisi tanaman, dan proyek-proyek agrikultur berbasis IoT (Internet of Things). Berikut adalah penjelasan lebih detail tentang cara kerja sensor kelembaban tanah, cara menghubungkannya ke Arduino Uno, dan contoh kode untuk menggunakannya.

Cara Kerja Sensor Kelembaban Tanah
Sensor kelembaban tanah biasanya terdiri dari dua probe yang dimasukkan ke dalam tanah. Prinsip kerjanya adalah mengukur resistansi atau kapasitansi antara dua probe. Air dalam tanah akan mengurangi resistansi atau meningkatkan kapasitansi, sehingga semakin banyak air yang ada, semakin rendah resistansinya (atau semakin tinggi kapasitansinya). Nilai ini kemudian diubah menjadi sinyal analog yang dapat dibaca oleh mikrokontroler seperti Arduino.
</div><br></br>

### 3. Amplifier PAM8403 
<img src="https://github.com/HanindaAgyanti/Microcontroller-Project/blob/main/Audio%20Sistem%20Pengingat%20Penyiram%20Tanaman/bahan-readme/3649295_a3e90273-d1d2-495b-a6fd-0e51735fddb6_1080_1080.jpg" width="400">
<div align = "justify">
PAM8403 adalah amplifier audio kelas D yang sangat efisien dan sering digunakan dalam proyek DIY karena ukurannya yang kecil dan kemampuannya untuk menghasilkan output suara yang cukup keras dengan konsumsi daya yang rendah. PAM8403 dapat memberikan daya 3W per kanal pada beban 4 ohm dengan distorsi yang rendah, menjadikannya pilihan yang populer untuk speaker portabel dan perangkat audio lainnya.
</div><br></br>

### 4. Speaker 0.5W
<img src="https://github.com/HanindaAgyanti/Microcontroller-Project/blob/main/Audio%20Sistem%20Pengingat%20Penyiram%20Tanaman/bahan-readme/WhatsApp%20Image%202024-05-17%20at%2016.39.24_a167ff00.jpg" width="400"><br></br>


## Electric
### Simulasi Tinkercad
<img src="https://github.com/HanindaAgyanti/Microcontroller-Project/blob/main/Audio%20Sistem%20Pengingat%20Penyiram%20Tanaman/Simulasi%20Tinkercad/Simulasi%20Tinkercad.jpg" width ="700">
Berikut link untuk video <a href="https://youtu.be/MZAg9T-eXJ4">Simulasi Tinkercad</a><br>
Program Simulasi Tinkercad:

```aruino
int sensorPin = A0;
int buzzerPin = 6;
int ledPin = 4;

void setup() {
  pinMode(sensorPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int value = analogRead(sensorPin);
  Serial.println(value); // Menampilkan nilai kelembaban tanah di Serial Monitor
  if (value <= 150) {
    tone(buzzerPin, 200); // Menghasilkan suara pada buzzer
    digitalWrite(ledPin, LOW); // LED mati
    delay(1000); // Menunggu selama 1000 milidetik (1 detik)
  } else {
    noTone(buzzerPin); // Mematikan buzzer
    digitalWrite(ledPin, HIGH); // LED menyala
    delay(1000); // Menunggu selama 1000 milidetik (1 detik)
  }
}
```
<br>

### Schematic
<img src="https://github.com/HanindaAgyanti/Microcontroller-Project/blob/main/Audio%20Sistem%20Pengingat%20Penyiram%20Tanaman/Schematic/Schematic.png" width="700"><br></br>

### PCB
#### Silkscreen
<img src="https://github.com/HanindaAgyanti/Microcontroller-Project/blob/main/Audio%20Sistem%20Pengingat%20Penyiram%20Tanaman/Schematic/Silkscreen.png" width="700"><br></br>

#### Bottom Layer
<img src="https://github.com/HanindaAgyanti/Microcontroller-Project/blob/main/Audio%20Sistem%20Pengingat%20Penyiram%20Tanaman/Schematic/Bottom%20Layer.png" width="700"><br></br>

### Audio

<img src="https://github.com/HanindaAgyanti/Microcontroller-Project/blob/main/Audio%20Sistem%20Pengingat%20Penyiram%20Tanaman/Audio/Progress%202.jpg" width="700">
<img src="https://github.com/HanindaAgyanti/Microcontroller-Project/blob/main/Audio%20Sistem%20Pengingat%20Penyiram%20Tanaman/Audio/Progres%201.jpg" width="700">
<img src="https://github.com/HanindaAgyanti/Microcontroller-Project/blob/main/Audio%20Sistem%20Pengingat%20Penyiram%20Tanaman/Audio/Progess%203.jpg" width="700">

Cara mengkonversi audio menjadi bahasa C
1. Membuka audacity
2. Record suara
3. Export -  other uncompressed files - 8000Hz - Raw (header-less) - Unsigned 8-bit PCM
3. Import - Raw Data - File audacity
4. Buka HxD
5. File - Open - File Raw
6. Export - C
7. Masukkan program C ke program

Link <a href="https://www.youtube.com/watch?v=oBMv-TfjefU&ab_channel=055_FadilatulIlmiM">Tutorial Konversi Audio</a><br></br>

## 3D Design
### Preview Img
<img src="https://github.com/HanindaAgyanti/Microcontroller-Project/blob/main/Audio%20Sistem%20Pengingat%20Penyiram%20Tanaman/3D%20Design/Progress1.png" width="700">
<img src= "https://github.com/HanindaAgyanti/Microcontroller-Project/blob/main/Audio%20Sistem%20Pengingat%20Penyiram%20Tanaman/3D%20Design/progres%202-3.jpeg" width="700">
<br></br>


## Program
### Flowchart
<img src="https://github.com/HanindaAgyanti/Microcontroller-Project/blob/main/Audio%20Sistem%20Pengingat%20Penyiram%20Tanaman/Program/Flowchart.jpg" width="500">

Cara Kerja:
1. Start (Mulai)
2. Sistem diaktifkan dan memulai proses
3. Inisialisasi Komponen. Pada tahap ini, semua komponen yang diperlukan seperti sensor kelembapan tanah, speaker, dan tombol reset diinisialisasi. Ini bisa melibatkan konfigurasi pin input/output dan inisialisasi modul ADC (Analog to Digital Converter) serta komunikasi serial jika diperlukan.
4. Deteksi Kelembapan Tanah. Sistem membaca nilai kelembapan tanah dari sensor. Nilai ini diambil melalui ADC yang mengonversi sinyal analog dari sensor menjadi nilai digital yang bisa dibaca oleh mikrokontroler.
5. IF Tanah Lembab (Jika Tanah Lembab) Nilai yang didapatkan dari sensor dibandingkan dengan ambang batas yang telah ditentukan. Jika nilai menunjukkan bahwa tanah lembab (misalnya nilai sensor lebih rendah dari ambang batas tertentu), maka proses berikutnya adalah menonaktifkan speaker.
6. True (Benar) - Speaker OFF. Jika kondisi tanah lembab terpenuhi (kondisi benar), speaker akan dimatikan. Ini berarti tidak ada alarm atau indikasi suara yang dihasilkan karena tanah cukup lembab.
7. False (Salah) - Speaker ON. Jika kondisi tanah tidak lembab (kondisi salah), speaker akan diaktifkan. Ini berarti sistem akan memberikan alarm atau indikasi suara untuk menandakan bahwa tanah tidak cukup lembab dan mungkin memerlukan penyiraman.
8. Reset Button (Tombol Reset). Pada titik ini, pengguna dapat menekan tombol reset untuk menonaktifkan speaker meskipun kondisi tanah tidak lembab. Ini memungkinkan pengguna untuk secara manual mengatur ulang status alarm suara.
9. Loop Kembali ke Deteksi Kelembapan Tanah. Setelah kondisi diperiksa dan aksi diambil, sistem kembali ke tahap deteksi kelembapan tanah untuk terus memonitor kondisi tanah.
10. Stop (Berhenti)
<br></br>


### Arduino Program

## Progress
### 1. Hasil PCB
<img src="https://github.com/HanindaAgyanti/Microcontroller-Project/blob/main/Audio%20Sistem%20Pengingat%20Penyiram%20Tanaman/Progress/Hasil%20PCB%20Jadi.jpg" width="700">

### 2. Perakitan PCB
<img src="https://github.com/HanindaAgyanti/Microcontroller-Project/blob/main/Audio%20Sistem%20Pengingat%20Penyiram%20Tanaman/Progress/Perakitan%20PCB.jpg" width="700">

### 3. Pinout PCB
<img src="https://github.com/HanindaAgyanti/Microcontroller-Project/blob/main/Audio%20Sistem%20Pengingat%20Penyiram%20Tanaman/Progress/Bagian-bagian%20pada%20Shield%20PCB.jpg" width="700">

### 4. 3D
<img src="https://github.com/HanindaAgyanti/Microcontroller-Project/tree/main/Audio%20Sistem%20Pengingat%20Penyiram%20Tanaman/Progress" width="700">

### 5. Input Progam
<img src="https://github.com/HanindaAgyanti/Microcontroller-Project/blob/main/Audio%20Sistem%20Pengingat%20Penyiram%20Tanaman/Progress/Input%20Program.jpg" width="700"><br></br>

## Social Media
> Instagram [@ryan.carlsenn](https://www.instagram.com/ryan.carlsenn/)
