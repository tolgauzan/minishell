**Geri:** [SUBJECT](../../README.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **rl_on_new_line()**

---

# rl_on_new_line() - [manual](https://tiswww.case.edu/php/chet/readline/rl_on_new_line.html)


📌 **Prototip:** `void rl_on_new_line(void);`


📘 **Açıklama:**

- rl_on_new_line() fonksiyonu, GNU Readline kütüphanesine aittir ve readline içindeki satır düzenleyicinin yeni bir satıra geçeceğini belirtmek için kullanılır.

- Genellikle, kullanıcı girdisi işlendikten sonra, yeni bir komut satırı için readline’in iç durumunu güncellemek amacıyla çağrılır.

- Bu fonksiyon, readline’in prompt’u düzgün şekilde yerleştirmesi ve ekranda doğru satır başına geçiş yapması için gereklidir.

📤 **Parametre:**
| **Parametre** | **Tür** | **Açıklama**                      |
| ------------- | ------- | --------------------------------- |
| —             | —       | Parametre almaz, dönüş değeri yok |

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

        rl_on_new_line();  // Yeni komut satırı için readline iç durumunu ayarla
        free(input);
    }

    return 0;
}
```

🛑 **Dikkat Et:**

- rl_on_new_line() çağrısı readline’in satır düzenleyici durumunu sıfırlamaya yardımcı olur, aksi halde prompt ve girdiler karışabilir.

- Genellikle rl_replace_line() ve rl_redisplay() gibi diğer readline fonksiyonlarıyla birlikte kullanılır.

💡 **minishell'de Kullanımı:**

- Komut işlendiğinde yeni satıra geçiş için readline durumunu güncellemek ve terminalde doğru prompt görünmesini sağlamak için.

---

**Geri:** [SUBJECT](../../README.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **rl_on_new_line()**