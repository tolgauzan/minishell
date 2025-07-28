**Geri:** [SUBJECT](../../README.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **signal()**

---

# signal() - [manual](https://man7.org/linux/man-pages/man2/signal.2.html)

#include <signal.h>

📌 **Prototip:** `void (*signal(int signum, void (*handler)(int)))(int);`

📘 **Açıklama:**

- signal() fonksiyonu, belirli bir sinyal (signum) için sinyal işleyici (handler) atanmasını sağlar.

- Bir sinyal geldiğinde, işletim sistemi bu işleyiciyi çağırır.

- İşleyici fonksiyon, sinyal numarasını argüman olarak alır.

- signal() eski tip sinyal yönetimi için kullanılır, daha güvenli ve esnek sigaction() tercih edilir.

📤 **Parametre:**
| **Parametre** | **Tür**         | **Açıklama**                                                                                                   |
| ------------- | --------------- | -------------------------------------------------------------------------------------------------------------- |
| `signum`      | `int`           | Sinyal numarası (örneğin `SIGINT`, `SIGTERM`, `SIGCHLD`, vs.)                                                  |
| `handler`     | `void (*)(int)` | Sinyal geldiğinde çalışacak fonksiyonun adresi veya özel değerler: `SIG_IGN` (ignore) veya `SIG_DFL` (default) |

📤 **Dönüş Değeri:**
| **Durum** | **Açıklama**                                      |
| --------- | ------------------------------------------------- |
| Başarı    | Önceki sinyal işleyici fonksiyonunun adresi döner |
| Hata      | `SIG_ERR` döner ve `errno` ayarlanır              |

🧪 **Örnek:**
```c
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void handler(int sig) {
    printf("Sinyal %d alındı!\n", sig);
}

int main() {
    // SIGINT sinyali (Ctrl+C) geldiğinde handler fonksiyonunu çağır
    signal(SIGINT, handler);

    printf("Ctrl+C'ye basana kadar bekleniyor...\n");
    while (1) {
        sleep(1);
    }

    return 0;
}
```

🛑 **Dikkat Et:**

- signal() bazı durumlarda işleyici fonksiyonun davranışı farklı olabilir, modern uygulamalarda sigaction() tercih edilir.

- Sinyal işleyicisi içerisinde sadece async-signal-safe fonksiyonlar kullanılmalıdır (örneğin printf risklidir).

- SIG_IGN sinyali yok sayar, SIG_DFL varsayılan davranışı uygular.

💡**minishell'de Kullanımı:**

- Kullanıcının Ctrl+C (SIGINT) veya Ctrl+\ (SIGQUIT) gibi sinyallerini yakalamak ve shell davranışını kontrol etmek için.

- Örneğin, Ctrl+C ile çalışan komut iptal edilir ama shell kapanmaz.

---

**Geri:** [SUBJECT](../../README.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **signal()**