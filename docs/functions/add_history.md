**Geri:** [SUBJECT](../../README.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **add_history()**

---

# add_history() - [manual](https://tiswww.case.edu/php/chet/readline/add_history.html)


📌 **Prototip:** `void add_history(const char *string);`


📘 **Açıklama:**

- add_history() fonksiyonu, GNU Readline kütüphanesine ait olup, kullanıcı tarafından girilen bir komutu veya satırı history (komut geçmişi) listesine ekler.

- Bu sayede kullanıcı, geçmişte yazdığı komutlara geri dönebilir ve kolayca tekrar kullanabilir.

- readline() fonksiyonuyla alınan satırlar, işlendikten sonra genellikle add_history() ile geçmişe eklenir.

📤 **Parametre:**
| **Parametre** | **Tür**        | **Açıklama**                   |
| ------------- | -------------- | ------------------------------ |
| `string`      | `const char *` | Geçmişe eklenmek istenen komut |

📤 **Dönüş Değeri:**
| **Durum** | **Açıklama**      |
| --------- | ----------------- |
| —         | `void`, dönüş yok |

🧪 **Örnek:**
```c
#include <readline/readline.h>
#include <readline/history.h>
#include <stdio.h>

int main() {
    char *input;

    while ((input = readline("minishell$ ")) != NULL) {
        if (*input) {  // Boş olmayan satırsa
            add_history(input);  // Komutu geçmişe ekle
        }

        printf("Girilen komut: %s\n", input);
        free(input);
    }

    return 0;
}
```

🛑 **Dikkat Et:**

- Boş satırlar genellikle history’ye eklenmez, bu yüzden input'un boş olup olmadığı kontrol edilmelidir.

- add_history() fonksiyonunu çağırdıktan sonra belleği serbest bırakabilirsiniz; fonksiyon kendi iç yapısını yönetir.

💡 **minishell'de Kullanımı:**

- Kullanıcı komut satırına yazdığı her geçerli komutu geçmişe eklemek için.

- Komut geçmişinden önceki komutların tekrar getirilmesi ve kullanıcının kolayca gezinebilmesi için.


---

**Geri:** [SUBJECT](../../README.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **add_history()**
