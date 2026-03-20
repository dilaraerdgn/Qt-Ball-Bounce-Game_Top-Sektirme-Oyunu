# Qt Ball Bounce Game (Top Sektirme Oyunu)

Bu proje, **C++** ve **Qt Framework** kullanılarak geliştirilmiş, fizik tabanlı bir top sektirme oyunudur. Oyuncunun fare hareketleriyle bir platformu kontrol ederek topu düşürmemeye çalıştığı, hız ve dikkat odaklı bir masaüstü uygulamasıdır.

---

## Oyunun Özellikleri ve Mekanikleri

- **Fare ile Kontrol:** `mouseMoveEvent` ve `setMouseTracking` kullanılarak platformun (paddle) fare yatay hareketlerine anlık tepki vermesi sağlanmıştır.
- **Çarpışma Algılama (Collision Detection):** Topun (`QLabel`) ve platformun (`QPushButton`) koordinatları `QRect::intersects` metodu ile sürekli taranarak gerçek zamanlı sekme efektleri oluşturulmuştur.
- **Dinamik Skor Sistemi:** Her başarılı sekmede skor güncellenir ve platform üzerinde anlık olarak gösterilir.
- **Responsive Arayüz:** `resizeEvent` override edilerek, pencere boyutu değiştiğinde platformun konumu ve oyun sınırları otomatik olarak yeniden hesaplanır.
- **Oyun Sonu Efekti:** Top alt sınırı geçtiğinde oyun durdurulur ve topun görseli bir "patlama" animasyonu/görseli ile değiştirilir.

---

## Teknik Detaylar

- **Framework:** Qt 5 / Qt 6
- **Zamanlama:** `QTimer` (40ms interval) ile akıcı oyun döngüsü.
- **Rastgelelik:** `QRandomGenerator` ile her oyun başlangıcında farklı top fırlatma noktaları.
- **Görsel Yönetimi:** `QPixmap` ve `scaledContents` ile dinamik görsel boyutlandırma.

---

## Nasıl Çalıştırılır?

1.  **Qt Creator** IDE'sini açın.
2.  Proje klasöründeki `.pro` uzantılı dosyayı seçerek projeyi içe aktarın.
3.  Kullanmak istediğiniz derleyiciyi (Kit) seçin (Örn: Desktop Qt 6.x MinGW).
4.  **Run (Ctrl + R)** butonuna basarak oyunu derleyin ve başlatın.

### Kontroller
- **Fare Hareketi:** Platformu sağa ve sola hareket ettirmek için fareyi sürükleyin.
- **Amaç:** Topu ekranın altına düşürmeden platformla yukarı sektirerek en yüksek skoru yapın.

---

## 📂 Proje Yapısı

```text
 
├── main.cpp          # Uygulama başlatıcı
├── mainwindow.cpp    # Oyun döngüsü, çarpışma ve fare kontrol mantığı
├── mainwindow.h      # Sinyal ve değişken tanımlamaları
└── mainwindow.ui     # Ana pencere tasarımı
├
└── images/           # Top ve patlama görsel varlıkları
└── Odev2_2360.pro    # Qt yapılandırma dosyası
