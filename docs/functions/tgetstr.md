**Geri:** [SUBJECT](../../README.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **tgetstr()**

---

# tgetstr() - [manual](https://man7.org/linux/man-pages/man3/tgetstr.3.html)

#include <term.h>

📌 **Prototip:** char *tgetstr(char *id, char **area);

📘 **Açıklama:**

- tgetstr() fonksiyonu, termcap veritabanında tanımlı olan string (karakter dizisi) terminal özelliklerini almak için kullanılır.

- id ile belirtilen özelliğin değerini döner.

- area işaretçisi, fonksiyonun içsel olarak kullanacağı ve stringleri depolayacağı bellek alanını gösterir. Eğer *area NULL ise, uygun alan ayrılmalıdır.

- Fonksiyon, özellik yoksa NULL döner.

📤 **Parametre:**
| **Parametre** | **Tür**   | **Açıklama**                                                                |
| ------------- | --------- | --------------------------------------------------------------------------- |
| `id`          | `char *`  | Alınacak string özelliğin adı (iki karakter, örn: `"cl"` - ekran temizleme) |
| `area`        | `char **` | Stringlerin kopyalanacağı buffer'ın adresi. `*area` pointer'ını günceller.  |

📤 **Dönüş Değeri:**
| **Durum** | **Açıklama**               |
| --------- | -------------------------- |
| != NULL   | Özelliğin string değeri    |
| NULL      | Özellik yok veya alınamadı |

🧪 **Örnek:**
```c
#include <term.h>
#include <stdio.h>

int main() {
    char buffer[2048];
    char *area = buffer;
    
    if (tgetent(buffer, "xterm") != 1) {
        printf("Terminal bilgisi yüklenemedi\n");
        return 1;
    }

    char *clear_screen = tgetstr("cl", &area); // Ekran temizleme stringi
    
    if (clear_screen == NULL) {
        printf("Terminal temizleme komutu alınamadı.\n");
    } else {
        printf("Terminal temizleme komutu: %s\n", clear_screen);
        // Örneğin: printf("%s", clear_screen) ile ekran temizlenebilir
    }

    return 0;
}
```

🛑 **Dikkat Et:**

- area işaretçisi yeterince büyük bir buffer göstermelidir.

- Önce tgetent() çağrılmalı, terminal verisi yüklenmelidir.

- id genellikle iki karakterli termcap kodudur.

- String özellikler terminale özgüdür, her terminalde farklı olabilir.

💡 **minishell'de Kullanımı:**

- Terminalde ekran temizleme, cursor hareketi gibi kontrol dizilerini almak için.

- Terminal çıktısını kontrol etmek ve daha kullanıcı dostu shell yapmak için.


---

**Geri:** [SUBJECT](../subject/subject.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **tgetstr()**