**Geri:** [SUBJECT](../../README.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **readline()**

---

# readline() - [manual](https://man7.org/linux/man-pages/man3/readline.3.html)
# readline Documantation - [LINK](https://tiswww.case.edu/php/chet/readline/readline.html)

📌 **Prototip:** `char *readline(const char *prompt);`

📘 **Açıklama:**

- readline() fonksiyonu, kullanıcıdan satır bazında girdi almak için kullanılır.

- Konsola prompt olarak verilen metni yazdırır ve kullanıcıdan satır girişi bekler.

- Kullanıcı Enter’a bastığında, girilen satır dinamik olarak allocate edilmiş bir char * olarak döner.

- Dönen string heap'te saklanır ve iş bitince free() ile serbest bırakılmalıdır.

- readline() kullanıcı dostu özellikler sunar: satır düzenleme, geçmiş (history) desteği gibi.

- readline() fonksiyonu GNU readline kütüphanesine aittir.

📤 **Parametre:**
| **Parametre** | **Tür**        | **Açıklama**                            |
| ------------- | -------------- | --------------------------------------- |
| `prompt`      | `const char *` | Kullanıcıya gösterilecek mesaj (prompt) |


📤 **Dönüş Değeri:**
| **Durum** | **Açıklama**                                                        |
| --------- | ------------------------------------------------------------------- |
| Başarı    | Kullanıcının girdiği satırı içeren `char *` (dynamically allocated) |
| Hata      | EOF veya hata durumunda `NULL` döner                                |

🧪 **Örnek:**
```c
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

int main() {
    char *input = readline("minishell$ ");
    if (input == NULL) {
        printf("Girdi alınamadı (EOF veya hata).\n");
        return 1;
    }

    printf("Girilen komut: %s\n", input);
    free(input);  // belleği serbest bırak
    return 0;
}
```


🛑 **Dikkat Et:**

- readline() tarafından dönen string free() ile serbest bırakılmalıdır.

- readline() otomatik olarak satır geçmişi kaydetmez, bunun için add_history() fonksiyonu kullanılmalıdır.

- readline() sadece terminalden giriş alır; pipe veya dosyadan giriş için uygun değildir.

💡 **minishell'de Kullanımı:**

- Komut satırında kullanıcıdan satır bazında komut almak için kullanılır.

- Satır düzenleme ve geçmiş yönetimi için readline fonksiyonları seti birlikte kullanılır.

---

**Geri:** [SUBJECT](../subject/subject.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **readline()**
