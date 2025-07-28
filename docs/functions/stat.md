**Geri:** [SUBJECT](../../README.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **stat()**

---

# stat() - [manual](https://man7.org/linux/man-pages/man2/stat.2.html)


#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

📌 **Prototip:** `int stat(const char *pathname, struct stat *statbuf);`

📘 **Açıklama:**

- stat() fonksiyonu, belirtilen dosyanın durum bilgilerini (metadata) statbuf yapısına doldurur.

- Dosyanın türü, boyutu, izinleri, oluşturulma/değiştirilme zamanı gibi bilgileri almanızı sağlar.

- pathname ile verilen dosya veya dizinin bilgilerini döner.

📤 **Parametre:**
| **Parametre** | **Tür**         | **Açıklama**                             |
| ------------- | --------------- | ---------------------------------------- |
| `pathname`    | `const char *`  | Bilgisi alınacak dosya veya dizinin yolu |
| `statbuf`     | `struct stat *` | Dosya bilgilerini alacak yapı            |

📤 **Dönüş Değeri:**
| **Durum** | **Açıklama**                    |
| --------- | ------------------------------- |
| Başarı    | `0` döner                       |
| Hata      | `-1` döner ve `errno` ayarlanır |

🧪 **Örnek:**
```c
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    struct stat fileStat;

    if(stat("test.txt", &fileStat) < 0) {
        perror("stat hatası");
        return 1;
    }

    printf("Dosya boyutu: %ld byte\n", fileStat.st_size);
    printf("Son erişim zamanı: %ld\n", fileStat.st_atime);
    printf("Dosya izinleri: %o\n", fileStat.st_mode & 0777);

    return 0;
}
```

🛑 **Dikkat Et:**

- stat() sembolik linkler üzerinde çalışır ve linkin hedef dosyasının bilgilerini döner.

- Linkin kendisi hakkında bilgi almak için lstat() kullanılır.

- st_mode alanı dosya türünü ve izinlerini içerir, dikkatlice parse edilmelidir.

💡 **minishell'de Kullanımı:**

- Dosyanın türünü ve erişim izinlerini kontrol etmek için kullanılır (örneğin, komut veya dosya mı olduğuna bakmak).

- Redirection için dosya var mı, erişim izni uygun mu kontrolü yapılır.


---

**Geri:** [SUBJECT](../../README.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **stat()**