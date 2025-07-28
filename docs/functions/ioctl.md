**Geri:** [SUBJECT](../../README.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **ioctl()**

---

# ioctl() - [manual](https://man7.org/linux/man-pages/man2/ioctl.2.html)

#include <sys/ioctl.h>

📌 **Prototip:** `int ioctl(int fd, unsigned long request, ...);`

📘 **Açıklama:**

- ioctl() fonksiyonu, "input/output control" anlamına gelir ve cihazlar veya dosya tanımlayıcıları üzerinde özel kontrol işlemleri yapmak için kullanılır.

- Standart sistem çağrılarının yapamadığı, cihazlara özgü veya özel ayarları değiştirmek için tasarlanmıştır.

- Parametre olarak dosya tanımlayıcısı (fd), yapılacak işlem kodu (request) ve isteğe bağlı bir üçüncü argüman alır.

- Üçüncü argüman genellikle bir işaretçi (void *) veya değer olabilir, işlemin türüne göre değişir.

📤 **Parametre:**
| **Parametre** | **Tür**              | **Açıklama**                               |
| ------------- | -------------------- | ------------------------------------------ |
| `fd`          | `int`                | Kontrol edilecek dosya tanımlayıcısı       |
| `request`     | `unsigned long`      | Yapılacak özel işlem kodu                  |
| `...`         | `void *` (opsiyonel) | İşlemle ilgili ek parametre (isteğe bağlı) |

📤 **Dönüş Değeri:**
| **Durum** | **Açıklama**                                                                     |
| --------- | -------------------------------------------------------------------------------- |
| Başarı    | İşlem başarılı ise genellikle `0` döner veya işleme bağlı farklı değer dönebilir |
| Hata      | `-1` döner ve `errno` ayarlanır                                                  |


🧪 **Örnek:**
```c
#include <sys/ioctl.h>
#include <unistd.h>
#include <stdio.h>
#include <termios.h>

int main() {
    struct winsize w;
    int ret = ioctl(STDOUT_FILENO, TIOCGWINSZ, &w); // Terminal pencere boyutunu al

    if (ret == -1) {
        perror("ioctl hatası");
        return 1;
    }

    printf("Terminal boyutu: %d sütun, %d satır\n", w.ws_col, w.ws_row);
    return 0;
}
```

🛑 **Dikkat Et:**

- ioctl() işlemleri cihaz türüne ve işletim sistemine göre değişiklik gösterir, bu yüzden kullanımı karmaşık olabilir.

- Hangi request kodlarının desteklendiğini ilgili cihaz veya sistem dokümantasyonundan kontrol etmek gerekir.

- Çoğu zaman terminal ayarları (termios), ağ cihazları ve özel cihazlar için kullanılır.

💡 **minishell'de Kullanımı:**

- Terminal özelliklerini almak veya değiştirmek (örn. terminal modlarını ayarlamak için).

- Sinyal ve terminal kontrolü için.

---

**Geri:** [SUBJECT](../../README.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **ioctl()**