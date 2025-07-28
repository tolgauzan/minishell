**Geri:** [SUBJECT](../../README.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **tgetnum()**

---

# tgetnum() - [manual](https://man7.org/linux/man-pages/man3/tgetnum.3.html)

#include <term.h>

📌 **Prototip:** `int tgetnum(char *id);`


📘 **Açıklama:**

- tgetnum() fonksiyonu, termcap veritabanında tanımlı olan sayısal (integer) terminal özelliklerinin değerini almak için kullanılır.

- Fonksiyon, tgetent() ile yüklenen terminal verilerinde, id ile belirtilen sayısal özelliğin değerini döner.

- Eğer özellik mevcut değilse veya sayısal değilse, -1 döner.

📤 **Parametre:**
| **Parametre** | **Tür**  | **Açıklama**                                                              |
| ------------- | -------- | ------------------------------------------------------------------------- |
| `id`          | `char *` | Alınacak sayısal özelliğin adı (iki karakter, örn: `"co"` - sütun sayısı) |

📤 **Dönüş Değeri:**
| **Durum** | **Açıklama**                        |
| --------- | ----------------------------------- |
| `>=0`     | Özelliğin sayısal değeri            |
| `-1`      | Özellik tanımlı değil veya geçersiz |

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

    int cols = tgetnum("co");  // Terminal sütun sayısı
    int lines = tgetnum("li"); // Terminal satır sayısı

    if (cols == -1 || lines == -1) {
        printf("Terminal boyut bilgisi alınamadı.\n");
    } else {
        printf("Terminal boyutu: %d sütun x %d satır\n", cols, lines);
    }

    return 0;
}
```

🛑 **Dikkat Et:**

- Önce tgetent() ile terminal verisi yüklenmelidir.

- id genellikle iki karakterli termcap kodudur.

- Terminalde bu özellik yoksa -1 döner, bunu kontrol etmek gerekir.

💡 **minishell'de Kullanımı:**

- Terminal ekranının satır ve sütun sayısı gibi sayısal özelliklerini almak için.

- Terminalin boyutuna göre prompt veya çıktı düzeni ayarlanabilir.

---

**Geri:** [SUBJECT](../../README.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **tgetnum()**