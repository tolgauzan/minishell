**Geri:** [SUBJECT](../../README.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **tcsetattr()**

---

# tcsetattr() - [manual](https://man7.org/linux/man-pages/man3/tcsetattr.3.html)

#include <termios.h>

📌 **Prototip:** `int tcsetattr(int fd, int optional_actions, const struct termios *termios_p);`


📘 **Açıklama:**

- tcsetattr() fonksiyonu, belirtilen dosya tanımlayıcısına ait terminal özelliklerini (termios yapısı) ayarlar veya değiştirir.

- Genellikle tcgetattr() ile alınan terminal ayarları üzerinde değişiklik yapıldıktan sonra bu fonksiyon kullanılır.

- optional_actions parametresi, ayarların ne zaman geçerli olacağını belirtir.


📤 **Parametre:**
| **Parametre**      | **Tür**                  | **Açıklama**                                                    |
| ------------------ | ------------------------ | --------------------------------------------------------------- |
| `fd`               | `int`                    | Terminal dosya tanımlayıcısı (örneğin `STDIN_FILENO`)           |
| `optional_actions` | `int`                    | Ayarların uygulanma şekli. Aşağıdaki sabitlerden biri olabilir: |
|                    |                          | - `TCSANOW` (hemen uygula)                                      |
|                    |                          | - `TCSADRAIN` (çıktı tamamlanınca uygula)                       |
|                    |                          | - `TCSAFLUSH` (uygula ve giriş tamponunu temizle)               |
| `termios_p`        | `const struct termios *` | Ayarlanacak terminal özelliklerinin bulunduğu yapı              |

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

    // Canonical mod kapatılıyor (satır satır giriş değil, karakter karakter giriş)
    term.c_lflag &= ~(ICANON | ECHO);

    if (tcsetattr(STDIN_FILENO, TCSANOW, &term) == -1) {
        perror("tcsetattr hatası");
        return 1;
    }

    printf("Terminal ayarları değiştirildi.\n");

    // Burada terminalde karakter karakter giriş alınabilir

    return 0;
}
```

🛑 **Dikkat Et:**

- Terminal ayarlarını değiştirirken tcgetattr() ile önce mevcut ayarları almak ve sonra değiştirmek en güvenli yoldur.

- optional_actions doğru seçilmezse beklenmedik davranışlar olabilir.

- Yanlış terminal ayarları, terminalin kilitlenmesine sebep olabilir, dikkatli kullan!

💡 **minishell'de Kullanımı:**

- Terminalde kullanıcı girdisi modunu değiştirmek için kullanılır (örneğin satır tabanlıdan karakter tabanlıya geçiş).

- Prompt ve komut satırı girişinin özel işlenmesi gereken durumlarda terminal davranışlarını kontrol etmek için.

---

**Geri:** [SUBJECT](../subject/subject.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **tcsetattr()**