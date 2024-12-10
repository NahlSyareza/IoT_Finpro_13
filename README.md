# Green Building Comfort

## Pendahuluan Masalah dan Solusi
Dalam konteks bangunan ramah lingkungan, efisiensi energi dan keberlanjutan lingkungan menjadi aspek yang sangat penting. Pengendalian pencahayaan dan ventilasi secara manual sering kali menyebabkan pemborosan energi. Untuk mengatasi hal ini, kami mengembangkan **Green Building Comfort**, yang mengoptimalkan pencahayaan berdasarkan sinar matahari alami serta mengatur ventilasi sesuai dengan jumlah orang di dalam ruangan.

## Fitur Utama
1. **Penyesuaian Otomatis Pencahayaan**  
   - Menggunakan sensor cahaya untuk memantau intensitas cahaya alami.  
   - Lampu menyala otomatis ketika cahaya alami tidak mencukupi.

2. **Ventilasi Berdasarkan Jumlah Orang**  
   - Menghitung jumlah orang di ruangan menggunakan sensor inframerah.  
   - Kipas dinyalakan otomatis jika jumlah orang melampaui batas yang ditentukan, dengan pengaturan kecepatan hingga 5 level.  

3. **Mode Manual dan Otomatis via Aplikasi Blynk**  
   - Memungkinkan pengguna beralih antara mode manual dan otomatis.  
   - Memberikan kontrol manual untuk mengatur lampu dan kipas, serta mengatur ambang batas sensor sesuai kebutuhan.

---

## Desain dan Implementasi Perangkat Keras

### Komponen yang Digunakan
- **ESP32**: Mikrokontroler utama untuk pemrosesan data dan komunikasi dengan aplikasi Blynk.  
- **Sensor Cahaya**: Memantau tingkat kecerahan dalam ruangan.  
- **Sensor Infrared**: Mendeteksi jumlah orang yang masuk dan keluar ruangan.  
- **Motor DC**: Menggerakkan kipas untuk ventilasi udara.  
- **Lampu**: Mensimulasikan pengaturan pencahayaan di ruangan.  

### Diagram Rangkaian
Sistem ini mengintegrasikan ESP32 dengan sensor dan aktuator. Sensor cahaya dihubungkan ke pin input analog, sedangkan sensor infrared terhubung ke pin digital. Motor DC dan lampu dikontrol melalui modul relay yang dihubungkan ke GPIO ESP32.
![rangkaian full](https://github.com/user-attachments/assets/fa51e7e1-0372-495a-9292-ff89e1fcb2f9)

---

## Detail Implementasi Perangkat Lunak

### Logika Sistem
1. **Otomasi Pencahayaan**  
   - Sensor cahaya membaca tingkat kecerahan secara kontinu.  
   - Jika tingkat kecerahan di bawah ambang batas, lampu akan menyala otomatis.  

2. **Otomasi Ventilasi**  
   - Sensor infrared melacak jumlah orang di ruangan.  
   - Kipas menyala otomatis jika jumlah orang melampaui ambang batas, dengan kecepatan yang disesuaikan berdasarkan jumlah orang.

3. **Integrasi dengan Aplikasi Blynk**  
   - Mode otomatis: Pengguna dapat menetapkan ambang batas pencahayaan dan level kecepatan kipas.  
   - Mode manual: Pengguna dapat menyalakan/mematikan lampu dan mengatur kecepatan kipas.  
   - Pengguna dapat beralih antara mode manual dan otomatis kapan saja.

### Pengaturan Kecepatan Kipas
Ambang batas jumlah orang untuk setiap level kecepatan kipas:
- **Level 1**: 1–10 orang → Kecepatan rendah.  
- **Level 2**: 11–20 orang → Kecepatan sedang-rendah.  
- **Level 3**: 21–30 orang → Kecepatan sedang.  
- **Level 4**: 31–40 orang → Kecepatan sedang-tinggi.  
- **Level 5**: 41+ orang → Kecepatan tinggi.

---

## Hasil Pengujian dan Evaluasi Performa

### Skenario Pengujian
1. **Sistem Pencahayaan**  
   - Mensimulasikan perubahan intensitas cahaya alami dan memverifikasi bahwa lampu merespons sesuai perubahan.  

2. **Deteksi Okupansi dan Ventilasi**  
   - Mensimulasikan masuk/keluarnya orang dari ruangan untuk memeriksa respons kipas.  

3. **Integrasi dengan Blynk**  
   - Menguji pergantian mode manual dan otomatis, serta pengaturan melalui aplikasi Blynk.

### Observasi
- **Efisiensi Energi**: Konsumsi energi berkurang saat tingkat pencahayaan alami mencukupi dan okupansi rendah.  
- **Respon Cepat**: Sistem merespons perubahan lingkungan dengan cepat.  
- **Kemudahan Penggunaan**: Aplikasi Blynk mempermudah pengaturan dan pengendalian.

---

## Kesimpulan dan Pekerjaan Masa Depan

### Kesimpulan
Sistem **Otomatisasi Pencahayaan dan Ventilasi Ruangan** berhasil meningkatkan efisiensi energi di ruangan sekaligus menjaga kenyamanan pengguna. Teknologi IoT yang digunakan memungkinkan pengendalian yang responsif dan adaptif sesuai kondisi lingkungan.

### Pekerjaan Masa Depan
1. **Integrasi Sensor Tambahan**: Penambahan sensor suhu dan kelembapan untuk kontrol lingkungan yang lebih komprehensif.  
2. **Pencatatan Data dan Analitik**: Mengumpulkan data untuk analisis penggunaan energi dan optimasi.  
3. **Skalabilitas**: Mengadaptasi sistem untuk ruang yang lebih besar atau multi-ruangan.  
4. **Pembelajaran Mesin**: Mengintegrasikan model prediktif untuk mengantisipasi kebutuhan pencahayaan dan ventilasi berdasarkan data historis.
