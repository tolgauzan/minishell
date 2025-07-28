**Geri:** [SUBJECT](../../README.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **ttyname()**

---

# ttyname() - [manual](https://man7.org/linux/man-pages/man3/ttyname.3.html)

 
📌 **Prototip:** `char *ttyname(int fd);`

📘 **Açıklama:**

- ttyname() fonksiyonu, verilen dosya tanımlayıcısının (fd) bağlı olduğu terminal aygıtının (TTY) dosya yolunu (yani cihaz dosyasının yolunu) döner.

- Eğer fd terminale bağlı değilse veya hata varsa NULL döner.

- Dönen string statik bir alanda tutulur, bu yüzden üzerinde değişiklik yapmamalısın.

📤 **Parametre:**
| **Parametre** | **Tür** | **Açıklama**                                                |
| ------------- | ------- | ----------------------------------------------------------- |
| `fd`          | `int`   | Terminal olup olmadığı kontrol edilecek dosya tanımlayıcısı |

📤 **Dönüş Değeri:**
| **Durum** | **Açıklama**                           |
| --------- | -------------------------------------- |
| `char *`  | Terminal cihazının dosya yolu stringi  |
| `NULL`    | `fd` terminal değilse veya hata oluştu |


🧪 **Örnek:**
```c
#include <stdio.h>
#include <unistd.h>

int main() {
    char *tty = ttyname(STDIN_FILENO);
    if (tty != NULL) {
        printf("Terminal aygıtı: %s\n", tty);
    } else {
        printf("Dosya tanımlayıcısı terminale bağlı değil.\n");
    }
    return 0;
}
```

🛑 **Dikkat Et:**

- Dönen string statik alanda olduğu için üzerinde değişiklik yapmamalısın.

- ttyname() yalnızca terminal aygıtlarını tanımlamak için anlamlıdır.

💡 **minishell'de Kullanımı:**

- Kullanıcının terminalde çalışıp çalışmadığını anlamak veya terminal cihaz yolunu öğrenmek için kullanılabilir.

---

**Geri:** [SUBJECT](../../README.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **ttyname()**