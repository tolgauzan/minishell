**Geri:** [SUBJECT](../../README.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **tgetflag()**

---

# tgetflag() - [manual](https://man7.org/linux/man-pages/man3/tgetflag.3.html)

#include <term.h>

📌 **Prototip:** `int tgetflag(char *id);`


📘 **Açıklama:**

- tgetflag() fonksiyonu, termcap veritabanında tanımlı olan boolean (doğru/yanlış) tipindeki terminal özelliklerini sorgulamak için kullanılır.

- Fonksiyon, tgetent() ile yüklenen terminal verileri içinde id ile belirtilen flag'in (bayrağın) durumunu kontrol eder.

- Eğer flag aktifse 1, değilse 0 döner.

📤 **Parametre:**
| **Parametre** | **Tür**  | **Açıklama**                                             |
| ------------- | -------- | -------------------------------------------------------- |
| `id`          | `char *` | Kontrol edilecek flag’in adı (iki karakter, örn: `"am"`) |

📤 **Dönüş Değeri:**
| **Durum** | **Açıklama**                   |
| --------- | ------------------------------ |
| `1`       | Flag terminalde aktif (doğru)  |
| `0`       | Flag terminalde pasif (yanlış) |

🧪 **Örnek:**
```c
#include <term.h>
#include <stdio.h>

int main() {
    char buffer[2048];
    if (tgetent(buffer, "xterm") != 1) {
        printf("Terminal bilgisi yüklenemedi\n");
        return 1;
    }

    int hasAutoMargin = tgetflag("am");
    if (hasAutoMargin) {
        printf("Terminal otomatik margin (satır sonu kaydırma) destekliyor.\n");
    } else {
        printf("Terminal otomatik margin desteklemiyor.\n");
    }

    return 0;
}
```

🛑 **Dikkat Et:**

- Önce tgetent() ile terminal bilgileri yüklenmiş olmalıdır, yoksa tgetflag() çalışmaz.

- Flag isimleri genellikle iki karakterlidir ve termcap veritabanından alınır.

💡 **minishell'de Kullanımı:**

- Terminal özelliklerinin boolean durumlarını kontrol etmek için (örneğin otomatik satır kaydırma gibi).

- Terminal davranışına göre shell’in kullanıcı arayüzünü uyarlamak için.

---

**Geri:** [SUBJECT](../../README.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **tgetflag()**