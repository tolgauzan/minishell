**Geri:** [SUBJECT](../../README.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **close()**

---

# close() - [manual](https://man7.org/linux/man-pages/man2/close.2.html)

📌 **Prototip:** `int close(int fd);`

📘 **Açıklama:**

- close() fonksiyonu, daha önce open(), dup(), pipe() gibi sistem çağrılarıyla açılmış bir dosya tanımlayıcısını (file descriptor - fd) kapatır.

- Açık kalan dosya tanımlayıcıları sistem kaynaklarını tüketir. Bu yüzden her açılan dosya/kaynak mutlaka kapatılmalıdır.


📤 **Parametre:**
| **Parametre** | **Tür** | **Açıklama**                                             |
| ------------- | ------- | -------------------------------------------------------- |
| `fd`          | `int`   | Kapatılacak dosya ya da kaynak tanımlayıcısı (örn: 3, 4) |

📤 **Dönüş Değeri:**
| **Durum** | **Açıklama**                                       |
| --------- | -------------------------------------------------- |
| Başarı    | `0` döner                                          |
| Hata      | `-1` döner ve `errno` uygun hata koduyla ayarlanır |


🧪 **Örnek:**
```c
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int fd = open("example.txt", O_RDONLY);
    if (fd == -1) {
        perror("Dosya açılamadı");
        return 1;
    }

    // Dosyayla işlemler yapılabilir...

    if (close(fd) == -1) {
        perror("Dosya kapatılamadı");
        return 1;
    }

    return 0;
}
```
🛑 **Dikkat Et:**

- close() bir fd'yi kapattığında, aynı numara başka bir açık dosya için tekrar kullanılabilir.

- Aynı dosya tanımlayıcısını iki kez kapatmak tanımsız davranışa yol açar.

- Kapalı bir fd ile işlem yapılmaya çalışılırsa hata alınır (EBADF).

💡 **minishell'de Kullanımı:**

- Redirection işlemleri ve pipe kullanımlarında, kullanılmayan uçlar kapatılmalıdır.

- Bellek ve dosya tanımlayıcı sızıntılarını önlemek için her açılan fd uygun yerde close() ile kapatılmalı.

- Özellikle fork sonrası parent ve child process’lerde fd’lerin doğru şekilde kapatılması gerekir.

---

**Geri:** [SUBJECT](../../README.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **close()**