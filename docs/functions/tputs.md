**Geri:** [SUBJECT](../../README.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **tputs()**

---

# tputs() - [manual](https://man7.org/linux/man-pages/man3/tputs.3.html)

#include <term.h>

📌 **Prototip:** `int tputs(const char *str, int affcnt, int (*putc)(int));`

📘 **Açıklama:**

- tputs() fonksiyonu, terminal kontrol dizilerini (termcap stringleri) yazdırmak için kullanılır.

- Özellikle terminal kontrol dizilerinde bulunan gecikme sürelerini de hesaba katarak, verilen stringi terminale yazar.

- str parametresi terminale gönderilecek kontrol dizisini belirtir.

- affcnt, dizinin etkilediği satır sayısıdır; bazı diziler satır sayısına göre gecikme süreleri içerir.

- putc fonksiyon işaretçisi, karakterleri yazmak için kullanılır (genellikle putchar veya benzeri).

📤 **Parametre:**
| **Parametre** | **Tür**        | **Açıklama**                                   |
| ------------- | -------------- | ---------------------------------------------- |
| `str`         | `const char *` | Yazdırılacak terminal kontrol dizisi           |
| `affcnt`      | `int`          | Dizinin etkilediği satır sayısı (genellikle 1) |
| `putc`        | `int (*)(int)` | Karakter yazma fonksiyonu, örn: `putchar`      |

📤 **Dönüş Değeri:**
| **Durum** | **Açıklama**                |
| --------- | --------------------------- |
| 0         | Başarıyla yazıldı           |
| EOF       | Yazma sırasında hata oluştu |

🧪 **Örnek:**
```c
#include <term.h>
#include <stdio.h>

int putchar_wrapper(int c) {
    return putchar(c);
}

int main() {
    char term_buffer[2048];
    if (tgetent(term_buffer, getenv("TERM")) != 1) {
        printf("Terminal bilgisi yüklenemedi\n");
        return 1;
    }

    char *clear_screen = tgetstr("cl", NULL); // Ekranı temizleme dizisi
    if (clear_screen) {
        tputs(clear_screen, 1, putchar_wrapper);
    } else {
        printf("Ekran temizleme dizisi bulunamadı\n");
    }

    return 0;
}
```

🛑 **Dikkat Et:**

- tputs fonksiyonunu kullanmadan önce tgetent ile terminal bilgileri yüklenmelidir.

- putc fonksiyon işaretçisi uygun şekilde tanımlanmalı, genellikle putchar kullanılır.

- affcnt parametresi genellikle 1 olarak verilir; özel durumlarda satır sayısı belirtilir.

💡 **minishell'de Kullanımı:**

- Terminale özel kontrol dizilerini güvenli şekilde yazdırmak için.

- Örneğin, ekranı temizlemek, imleci hareket ettirmek veya renkleri değiştirmek için.

---

**Geri:** [SUBJECT](../../README.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **tputs()**