**Geri:** [SUBJECT](../../README.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **rl_replace_line()**

---

# rl_replace_line() - [manual](https://tiswww.case.edu/php/chet/readline/rl_replace_line.html)


📌 **Prototip:** `void rl_replace_line(const char *text, int clear_undo);`


📘 **Açıklama:**

- rl_replace_line() fonksiyonu, GNU Readline kütüphanesine aittir ve readline’in düzenlenen mevcut satırını text ile değiştirir.

- Bu, komut satırında gösterilen mevcut girdiyi tamamen değiştirmek için kullanılır.

- clear_undo parametresi 1 olarak verilirse, önceki undo (geri alma) bilgisi temizlenir, 0 ise undo bilgisi korunur.

📤 **Parametre:**
| **Parametre** | **Tür**        | **Açıklama**                                |
| ------------- | -------------- | ------------------------------------------- |
| `text`        | `const char *` | Yeni satır içeriği olarak atanacak metin    |
| `clear_undo`  | `int`          | Undo bilgisini temizleme bayrağı (0 veya 1) |

📤 **Dönüş Değeri:**
| **Durum** | **Açıklama**             |
| --------- | ------------------------ |
| —         | `void`, dönüş değeri yok |


🧪 **Örnek:**
```c
#include <readline/readline.h>
#include <readline/history.h>

int main() {
    char *input;

    while ((input = readline("minishell$ ")) != NULL) {
        // Komut işleme...

        rl_replace_line("echo Hello, World!", 0); // Komut satırını değiştirme
        rl_redisplay(); // Yeni satırı ekranda göster

        free(input);
    }

    return 0;
}
```

🛑 **Dikkat Et:**

- rl_replace_line() sadece readline içindeki geçerli satırı değiştirir, ekrana yansıtmak için rl_redisplay() çağrılmalıdır.

- Undo bilgisini temizlemek, kullanıcı için geri alma işlemlerini sıfırlar. İhtiyaca göre clear_undo parametresi ayarlanmalıdır.

💡 **minishell'de Kullanımı:**

- Otomatik tamamlama veya komut düzenleme sırasında mevcut satırın hızlıca değiştirilmesi için kullanılır.

---

**Geri:** [SUBJECT](../subject/subject.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **rl_replace_line()**