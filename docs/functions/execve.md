**Geri:** [SUBJECT](../../README.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **execve()**

---

# execve() - [manual](https://man7.org/linux/man-pages/man2/execve.2.html)

📌 **Prototip:** `int execve(const char *pathname, char *const argv[], char *const envp[]);`


📘 **Açıklama:**

- execve() fonksiyonu, belirtilen dosyayı çalıştırır ve mevcut sürecin bellek görüntüsünü bu yeni programla değiştirir.

- Bu fonksiyon, çağrıldığı sürecin kodunu ve verilerini tamamen yenisiyle değiştirir.

- Başarılı olursa, execve() geri dönmez; program yeni yürütülebilir dosyaya geçer.

- Başarısız olursa -1 döner ve errno ayarlanır.

📤 **Parametre:**
| **Parametre** | **Tür**         | **Açıklama**                                               |
| ------------- | --------------- | ---------------------------------------------------------- |
| `pathname`    | `const char *`  | Çalıştırılacak programın dosya yolu (mutlak veya göreli)   |
| `argv`        | `char *const[]` | Programın argümanları (argv\[0] genellikle program adı)    |
| `envp`        | `char *const[]` | Yeni süreç için ortam değişkenleri (environment variables) |

📤 **Dönüş Değeri:**
| **Durum** | **Açıklama**                                        |
| --------- | --------------------------------------------------- |
| Başarı    | Fonksiyon dönmez, program çalışmaya başlar.         |
| Hata      | `-1` döner ve `errno` uygun hata koduyla ayarlanır. |

 🧪 **Örnek:**
```c
#include <unistd.h>
#include <stdio.h>

int main() {
    char *args[] = {"/bin/ls", "-l", NULL};
    char *env[] = {NULL};  // Ortam değişkenlerini boş bırakabiliriz

    printf("execve çağrılıyor...\n");
    if (execve("/bin/ls", args, env) == -1) {
        perror("execve hatası");
    }

    // Bu satır sadece hata durumunda çalışır
    return 1;
}
```

🛑 **Dikkat Et:**

- execve() çağrısı başarılıysa, sonraki kod çalıştırılmaz.

- Başarısız olursa -1 döner, mutlaka hata kontrolü yapılmalı.

- argv dizisinin son elemanı NULL olmalıdır.

- envp ortam değişkenleri dizisi genellikle environ veya mevcut ortamdan kopyalanır.

- execve() genellikle fork() sonrası çocuk süreçte kullanılır.

💡 **minishell'de Kullanımı:**

- Fork ile oluşturulan çocuk süreçte, çalıştırılacak komut dosyasını yüklemek ve çalıştırmak için kullanılır.

- Shell, kendi kodunu kaybetmeden komutu yeni bir program olarak çalıştırır.

---

**Geri:** [SUBJECT](../subject/subject.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **execve()**