**Geri:** [SUBJECT](../../README.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **lstat()**

---

# lstat() - [manual](https://man7.org/linux/man-pages/man2/lstat.2.html)


#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

📌 **Prototip:** `int lstat(const char *pathname, struct stat *statbuf);`

📘 **Açıklama:**

- lstat() fonksiyonu, stat() fonksiyonuna benzer şekilde çalışır ancak eğer pathname bir sembolik linkse, linkin kendisi hakkında bilgi verir, linkin hedef dosyası hakkında değil.

- Böylece sembolik linkin boyutu, izinleri, vs. öğrenilebilir.

📤 **Parametre:**
| **Parametre** | **Tür**         | **Açıklama**                                     |
| ------------- | --------------- | ------------------------------------------------ |
| `pathname`    | `const char *`  | Bilgisi alınacak dosya veya sembolik linkin yolu |
| `statbuf`     | `struct stat *` | Dosya/symlink bilgilerini alacak yapı            |

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

    if(lstat("symlink", &fileStat) < 0) {
        perror("lstat hatası");
        return 1;
    }

    if (S_ISLNK(fileStat.st_mode)) {
        printf("Bu bir sembolik linktir.\n");
        printf("Link boyutu: %ld byte\n", fileStat.st_size);
    } else {
        printf("Bu sembolik link değildir.\n");
    }

    return 0;
}
```

🛑 **Dikkat Et:**

- lstat() sembolik linkleri takip etmez, kendisi hakkında bilgi verir.

- Normal dosya için stat() kullanılır, sembolik linkin kendisini incelemek için lstat() tercih edilir.

💡 **minishell'de Kullanımı:**

- Sembolik linklerin olup olmadığını kontrol etmek için kullanılır.

- Komutun gerçek yolu değil, linkin kendisi ile ilgili bilgi gerektiğinde kullanılır.


---

**Geri:** [SUBJECT](../subject/subject.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **lstat()**