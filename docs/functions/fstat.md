**Geri:** [SUBJECT](../../README.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **fstat()**

---

# fstat() - [manual](https://man7.org/linux/man-pages/man2/fstat.2.html)

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

📌 **Prototip:** `int fstat(int fd, struct stat *statbuf);`

📘 **Açıklama:**

- fstat() fonksiyonu, açık olan bir dosya tanımlayıcısına (fd) karşılık gelen dosya hakkında bilgi alır.

- stat() ve lstat() fonksiyonlarından farklı olarak, dosya yoluna değil, dosya tanımlayıcısına göre çalışır.

- Dosyanın boyutu, izinleri, tipi, zaman bilgileri gibi dosya metadata'sını statbuf yapısına yazar.

📤 **Parametre:**
| **Parametre** | **Tür**         | **Açıklama**                                                         |
| ------------- | --------------- | -------------------------------------------------------------------- |
| `fd`          | `int`           | Bilgisi alınacak açık dosyanın dosya tanımlayıcısı (file descriptor) |
| `statbuf`     | `struct stat *` | Dosya bilgilerini alacak yapı                                        |

📤 **Dönüş Değeri:**
| **Durum** | **Açıklama**                    |
| --------- | ------------------------------- |
| Başarı    | `0` döner                       |
| Hata      | `-1` döner ve `errno` ayarlanır |

🧪 **Örnek:**
```c
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    struct stat fileStat;
    int fd = open("test.txt", O_RDONLY);
    if (fd == -1) {
        perror("Dosya açılamadı");
        return 1;
    }

    if (fstat(fd, &fileStat) == -1) {
        perror("fstat hatası");
        close(fd);
        return 1;
    }

    printf("Dosya boyutu: %ld byte\n", fileStat.st_size);

    close(fd);
    return 0;
}
```

🛑 **Dikkat Et:**

- fd geçerli bir açık dosya tanımlayıcısı olmalıdır.

- Dosya yolu yerine fd ile çalışır, bu sayede açık dosyalar hakkında doğrudan bilgi alabilirsin.

💡 **minishell'de Kullanımı:**

- Açık dosya descriptor’ları üzerinden dosya bilgisi almak için.

- Özellikle yönlendirme (redirection) yapılırken dosya durumu kontrolünde kullanılabilir.

---

**Geri:** [SUBJECT](../../README.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **fstat()**