**Geri:** [SUBJECT](../../README.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **sigadddset()**

---

# sigadddset() - [manual](https://man7.org/linux/man-pages/man3/sigaddset.3.html)

#include <signal.h>

📌 **Prototip:** `int sigaddset(sigset_t *set, int signo);`


📘 **Açıklama:**

- sigaddset() fonksiyonu, belirtilen sinyali (signo) sigset_t tipindeki sinyal setine ekler (işaretler).

- Bu fonksiyon, sinyal setine yeni bir sinyal eklemek için kullanılır. Örneğin, sinyal maskesine bir sinyal eklemek istediğinde.

📤 **Parametre:**
| **Parametre** | **Tür**     | **Açıklama**                                                |
| ------------- | ----------- | ----------------------------------------------------------- |
| `set`         | `sigset_t*` | İşlem yapılacak sinyal setinin adresi                       |
| `signo`       | `int`       | Eklenmek istenen sinyal numarası (örn: `SIGINT`, `SIGTERM`) |

📤 **Dönüş Değeri:**
| **Durum** | **Açıklama**                    |
| --------- | ------------------------------- |
| Başarı    | `0` döner                       |
| Hata      | `-1` döner ve `errno` ayarlanır |

🧪 **Örnek:**
```c
#include <signal.h>
#include <stdio.h>

int main() {
    sigset_t set;

    if (sigemptyset(&set) == -1) {
        perror("sigemptyset hatası");
        return 1;
    }

    if (sigaddset(&set, SIGINT) == -1) {
        perror("sigaddset hatası");
        return 1;
    }

    printf("SIGINT sinyali set'e eklendi.\n");
    return 0;
}
```

🛑 **Dikkat Et:**

- sigaddset() kullanmadan önce sigemptyset() ile set temizlenmelidir, aksi halde eski set içeriği korunur.

- Geçersiz veya sistemde olmayan bir sinyal numarası verirseniz hata alırsınız.

💡 **minishell'de Kullanımı:**

- Sinyal maskesi oluşturup, belirli sinyalleri engellemek ya da kontrol etmek için kullanılır.

- sigaction() içinde maske ayarlarken yardımcı olur.

---

**Geri:** [SUBJECT](../subject/subject.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **sigadddset()**