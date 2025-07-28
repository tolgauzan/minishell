**Geri:** [SUBJECT](../../README.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **dup2()**

---

# dup2() - [manual](https://man7.org/linux/man-pages/man2/dup2.2.html)


📌 **Prototip:** `int dup2(int oldfd, int newfd);`


📘 **Açıklama:**

- dup2() fonksiyonu, oldfd dosya tanımlayıcısının bir kopyasını newfd olarak ayarlar.

- Eğer newfd zaten açıksa, önce kapatılır ve ardından oldfd kopyalanır.

- Böylece newfd, oldfd ile aynı dosya açıklamasını paylaşır.

- dup2() özellikle standart giriş/çıkış yönlendirmelerinde çok kullanılır çünkü belirli bir dosya tanımlayıcısını değiştirmek için kullanılır.

📤 **Parametre:**
| **Parametre** | **Tür** | **Açıklama**                     |
| ------------- | ------- | -------------------------------- |
| `oldfd`       | `int`   | Kopyalanacak dosya tanımlayıcısı |
| `newfd`       | `int`   | Kopyanın atanacağı hedef fd      |


📤 **Dönüş Değeri:**
| **Durum** | **Açıklama**                                            |
| --------- | ------------------------------------------------------- |
| Başarı    | `newfd` dosya tanımlayıcısını döner (her zaman `newfd`) |
| Hata      | `-1` döner ve `errno` uygun hata kodu ile ayarlanır     |

🧪 **Örnek:**
```c
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main() {
    int fd = open("test.txt", O_RDONLY);
    if (fd == -1) {
        perror("Dosya açılamadı");
        return 1;
    }

    // 0 → stdin, fd'yi stdin'e kopyala
    if (dup2(fd, 0) == -1) {
        perror("dup2 hatası");
        close(fd);
        return 1;
    }

    // Artık standart giriş "test.txt" dosyasına yönlendirildi
    // stdin üzerinden okuma yapılabilir

    close(fd);

    return 0;
}
```
🛑 **Dikkat Et:**

- newfd zaten açık ise önce kapatılır, bu yüzden newfd farklı bir dosya tanımlayıcısı ise dikkatli kullanılmalı.

- dup2() genellikle standart giriş (0), standart çıkış (1), standart hata (2) yönlendirmelerinde kullanılır.

- dup() ile farkı: dup2() hedef fd’yi belirtebilirsin, dup() ise otomatik en küçük kullanılabilir fd’yi döner.

💡 **minishell'de Kullanımı:**

- Komut redirection işlemlerinde standart giriş ve çıkış yönlendirmeleri yapmak için.

- Pipe ve dosya descriptor yönetiminde kritik rol oynar.

---

**Geri:** [SUBJECT](../subject/subject.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **dup2()**