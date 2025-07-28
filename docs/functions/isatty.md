**Geri:** [SUBJECT](../../README.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **isatty()**

---

# isatty() - [manual](https://man7.org/linux/man-pages/man3/isatty.3.html)

📌 **Prototip:** `int isatty(int fd);`

📘 **Açıklama:**

- isatty() fonksiyonu, verilen dosya tanımlayıcısının (fd) bir terminal (TTY) cihazına bağlı olup olmadığını kontrol eder.

- Eğer fd terminale bağlı ise 1 döner, değilse 0 döner.

- Bu fonksiyon genellikle programın giriş/çıkışının terminal olup olmadığını anlamak için kullanılır.

📤 **Parametre:**
| **Parametre** | **Tür** | **Açıklama**                                        |
| ------------- | ------- | --------------------------------------------------- |
| `fd`          | `int`   | Kontrol edilecek dosya tanımlayıcısı (örnek: 0,1,2) |


📤 **Dönüş Değeri:**
| **Durum** | **Açıklama**                    |
| --------- | ------------------------------- |
| 1         | `fd` terminal cihazına bağlıdır |
| 0         | `fd` terminale bağlı değildir   |


```c
#include <unistd.h>
#include <stdio.h>

int main() {
    if (isatty(STDIN_FILENO)) {
        printf("Girdi bir terminal.\n");
    } else {
        printf("Girdi terminal değil.\n");
    }
    return 0;
}

```

🛑 **Dikkat Et:**

- isatty() sadece dosya tanımlayıcısının terminal olup olmadığını kontrol eder, terminalin türü hakkında bilgi vermez.

- Shell ve interaktif programlarda kullanıcı girişinin terminalden gelip gelmediğini anlamak için sıkça kullanılır.

💡 **minishell'de Kullanımı:**

- Komutların interaktif modda mı yoksa pipe/redirection ile mi çalıştırıldığını anlamak için.

- Prompt’un terminal ortamında gösterilip gösterilmeyeceğine karar vermek için.


---

**Geri:** [SUBJECT](../../README.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **isatty()**