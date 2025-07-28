**Geri:** [SUBJECT](../../README.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **rl_redisplay()**

---

# rl_redisplay() - [manual](https://tiswww.case.edu/php/chet/readline/rl_redisplay.html)

📌 **Prototip:** `void rl_redisplay(void);`


📘 **Açıklama:**

- rl_redisplay() fonksiyonu, GNU Readline kütüphanesine ait olup, komut satırında gösterilen mevcut satırı yeniden ekrana çizer.

- Özellikle rl_replace_line() veya satır üzerinde değişiklik yapıldıktan sonra, güncellenen satırın kullanıcıya gösterilmesini sağlar.

- Bu fonksiyon, manuel olarak kullanıcı arayüzünü yenilemek için kullanılır.

📤 **Parametre:**
| **Parametre** | **Tür** | **Açıklama**    |
| ------------- | ------- | --------------- |
| —             | —       | Parametre almaz |

📤 **Dönüş Değeri:**
| **Durum** | **Açıklama**      |
| --------- | ----------------- |
| —         | `void`, dönüş yok |

🧪 **Örnek:**
```c
#include <readline/readline.h>
#include <readline/history.h>

int main() {
    char *input;

    while ((input = readline("minishell$ ")) != NULL) {
        // Komut işleme...

        rl_replace_line("echo Hello, World!", 0); // Satırı değiştir
        rl_redisplay(); // Yeni satırı ekranda göster

        free(input);
    }

    return 0;
}
```

🛑 **Dikkat Et:**

- rl_redisplay() fonksiyonu, ekranda sadece mevcut satırı yeniden çizmek için kullanılır.

- Bu fonksiyon, readline’in kendi otomatik güncelleme mekanizması dışında manuel kontrol gerektiğinde faydalıdır.

💡 **minishell'de Kullanımı:**

- Kullanıcı komut satırında değişiklik yapıldıktan sonra ekranın güncellenmesi için, örneğin rl_replace_line() sonrası.

---

**Geri:** [SUBJECT](../../README.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **rl_redisplay()**