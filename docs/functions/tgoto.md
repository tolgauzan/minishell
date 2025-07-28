**Geri:** [SUBJECT](../../README.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **tgoto()**

---

# tgoto() - [manual](https://man7.org/linux/man-pages/man3/tgoto.3.html)

#include <term.h>

📌 **Prototip:** `char *tgoto(const char *cap, int col, int row);`


📘 **Açıklama:**

- tgoto() fonksiyonu, terminalde cursor (imleç) hareketini sağlayan kontrol dizilerini oluşturur.

- cap parametresi, cursor hareketi için kullanılan termcap stringini (genellikle "cm" - cursor motion) belirtir.

- col ve row parametreleri, cursor'un hareket edeceği sütun ve satır koordinatlarını belirtir.

- Fonksiyon, koordinatları termcap kontrol dizisi formatına dönüştürür ve bu stringi döner.

- Dönen string doğrudan terminale yazılabilir.

📤 **Parametre:**
| **Parametre** | **Tür**        | **Açıklama**                               |
| ------------- | -------------- | ------------------------------------------ |
| `cap`         | `const char *` | Cursor hareket kontrol dizisi (ör: `"cm"`) |
| `col`         | `int`          | İmlecin yeni kolonu (sütun numarası)       |
| `row`         | `int`          | İmlecin yeni satırı (satır numarası)       |

📤 **Dönüş Değeri:**
| **Durum** | **Açıklama**                                          |
| --------- | ----------------------------------------------------- |
| != NULL   | İstenen pozisyona gitmek için kontrol dizisi (string) |
| NULL      | Hata veya geçersiz parametre                          |


🧪 **Örnek:**
```c
#include <term.h>
#include <stdio.h>

int main() {
    char term_buffer[2048];
    if (tgetent(term_buffer, getenv("TERM")) != 1) {
        printf("Terminal bilgisi yüklenemedi\n");
        return 1;
    }
    
    char *cm = tgetstr("cm", NULL); // cursor motion stringini al
    if (!cm) {
        printf("Cursor hareket dizisi bulunamadı\n");
        return 1;
    }

    char *move_cursor = tgoto(cm, 10, 5); // İmleci 5.satır 10.sütuna götür
    if (move_cursor) {
        printf("Cursor hareket dizisi: %s\n", move_cursor);
        // Örneğin terminale yazabilirsiniz:
        // printf("%s", move_cursor);
    }

    return 0;
}
```

🛑 **Dikkat Et:**

- tgoto sonucu terminale yazılmalıdır ki hareket gerçekleşsin.

- tgetent ile terminal verisi önceden yüklenmeli.

- col ve row değerleri terminalin desteklediği koordinatlarda olmalı.

- Bazı terminaller farklı davranabilir.

💡**minishell'de Kullanımı:**

- Terminalde imleç pozisyonunu değiştirmek için, örneğin çok satırlı kullanıcı girdilerinde doğru satıra imleç kaydırmak için.

---

**Geri:** [SUBJECT](../../README.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **tgoto()**