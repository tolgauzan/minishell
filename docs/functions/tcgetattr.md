**Geri:** [SUBJECT](../../README.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **tcgetattr()**

---

# tcgetattr() - [manual](https://man7.org/linux/man-pages/man3/tcgetattr.3.html)

#include <termios.h>

📌 **Prototip:** `int tcgetattr(int fd, struct termios *termios_p);`


📘 **Açıklama:**

- tcgetattr() fonksiyonu, belirtilen dosya tanımlayıcısına (genellikle terminale) ait terminal özelliklerini (termios yapısını) alır.

- Terminal modları, giriş/çıkış ayarları, satır işleme gibi parametreler bu yapı içindedir.

- Terminal ayarlarını okumak ve sonrasında değiştirmek için kullanılır.

📤 **Parametre:**
| **Parametre** | **Tür**            | **Açıklama**                                          |
| ------------- | ------------------ | ----------------------------------------------------- |
| `fd`          | `int`              | Terminal dosya tanımlayıcısı (örneğin `STDIN_FILENO`) |
| `termios_p`   | `struct termios *` | Terminal özelliklerinin yazılacağı yapı adresi        |

📤 **Dönüş Değeri:**
| **Durum** | **Açıklama**                    |
| --------- | ------------------------------- |
| Başarı    | `0` döner                       |
| Hata      | `-1` döner ve `errno` ayarlanır |

🧪 **Örnek:**
```c
#include <termios.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    struct termios term;
    if (tcgetattr(STDIN_FILENO, &term) == -1) {
        perror("tcgetattr hatası");
        return 1;
    }

    printf("Terminal özellikleri alındı.\n");
    // Örneğin, term yapısı üzerinde değişiklik yapılabilir.

    return 0;
}
```

🛑 **Dikkat Et:**

- fd parametresi mutlaka bir terminal dosya tanımlayıcısı olmalıdır, aksi halde hata verir.

- tcgetattr ile alınan ayarlar tcsetattr() ile değiştirilebilir.

💡 **minishell'de Kullanımı:**

- Terminal modu kontrolü ve kullanıcı girdisi işlemlerinde, özel terminal ayarlarını okumak için kullanılır.

- Örneğin, kullanıcı girişini satır satır almak için terminalde canonical modun açılıp kapatılmasında ön bilgi olarak alınır.

---

**Geri:** [SUBJECT](../../README.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **tcgetattr()**