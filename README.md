
<h1 align="left">
  Audio Sistem Pengingat Penyiram Tanaman <br>Workshop Mikrokontroler
<br></br>
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
  - <a href="avr-program">AVR Program</a> 
* <a href="#social-media">Social Media</a>
<br></br>

## Deskripsi
<div align="justify">
Sebuah projek mata kuliah Workshop Mikrokontroler membuat Sistem Pendeteksi Penyiram Tanaman diharap mampu membantu masyarakat diberbagai kalangan usia untuk dapat menentukan waktu yang tepat dalam menyiram tanaman yang dapat dikontrol dengan sensor kelembapan. Dengan adanya project ini juga dapat mencapai lingkungan khususnya pada taman ataupun tanaman dapat lebih segar dan tidak layu. Project ini juga sangat bermanfaat bagi kalangan pertanian, perkebunan, serta perladangan.
</div><br></br>

## Komponen
### 1. Arduino Uno
<img src="https://github.com/HanindaAgyanti/Microcontroller-Project/blob/main/Audio%20Sistem%20Pengingat%20Penyiram%20Tanaman/bahan-readme/nekhil-r-hz7EFrw06Qk-unsplash.jpg" width="400">

### 2. Soil Humidity Sensor
<img src="https://github.com/HanindaAgyanti/Microcontroller-Project/blob/main/Audio%20Sistem%20Pengingat%20Penyiram%20Tanaman/bahan-readme/Sensor_Hygrometer_Detection_Humidity.jpg" width="400">

### 3. Amplifier PAM8403 
<img src="https://github.com/HanindaAgyanti/Microcontroller-Project/blob/main/Audio%20Sistem%20Pengingat%20Penyiram%20Tanaman/bahan-readme/3649295_a3e90273-d1d2-495b-a6fd-0e51735fddb6_1080_1080.jpg" width="400">

### 4. Buck Boost Converter
<img src="https://github.com/HanindaAgyanti/Microcontroller-Project/blob/main/Audio%20Sistem%20Pengingat%20Penyiram%20Tanaman/bahan-readme/71zYfhZLfrL.jpg" width="400">

### 5. Speaker 0.5W
<img src="https://github.com/HanindaAgyanti/Microcontroller-Project/blob/main/Audio%20Sistem%20Pengingat%20Penyiram%20Tanaman/bahan-readme/WhatsApp%20Image%202024-05-17%20at%2016.39.24_a167ff00.jpg" width="400"><br></br>


## Electric
### Simulasi Tinkercad
<img src="https://github.com/HanindaAgyanti/Microcontroller-Project/blob/main/Audio%20Sistem%20Pengingat%20Penyiram%20Tanaman/Simulasi%20Tinkercad/Simulasi%20Tinkercad.jpg" width ="700">

### Schematic
<img src="https://github.com/HanindaAgyanti/Microcontroller-Project/blob/main/Audio%20Sistem%20Pengingat%20Penyiram%20Tanaman/Schematic/Schematic.png" width="700">

### PCB
#### Silkscreen
<img src="https://github.com/HanindaAgyanti/Microcontroller-Project/blob/main/Audio%20Sistem%20Pengingat%20Penyiram%20Tanaman/Schematic/Silkscreen.png" width="700">

#### Bottom Layer
<img src="https://github.com/HanindaAgyanti/Microcontroller-Project/blob/main/Audio%20Sistem%20Pengingat%20Penyiram%20Tanaman/Schematic/Bottom%20Layer.png" width="700">

### Audio
On progress...<br></br>

## 3D Design
### Preview Img
<img src="https://github.com/HanindaAgyanti/Microcontroller-Project/blob/main/Audio%20Sistem%20Pengingat%20Penyiram%20Tanaman/3D%20Design/Progress1.png" width="700">
<img src= "https://github.com/HanindaAgyanti/Microcontroller-Project/blob/main/Audio%20Sistem%20Pengingat%20Penyiram%20Tanaman/3D%20Design/progres%202-3.jpeg" width="700">
<br></br>


## Program
### Flowchart
<img src="https://github.com/HanindaAgyanti/Microcontroller-Project/blob/main/Audio%20Sistem%20Pengingat%20Penyiram%20Tanaman/Program/Flowchart.jpg" width="500"><br></br>

### Arduino Program
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

### AVR Program
On progress...<br></br>

## Social Media
> Youtube Channel -[Haninda Agyanti](http://www.youtube.com/@060_HanindaAgyantiF)
