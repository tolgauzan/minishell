**Geri:** [SUBJECT](../../README.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **kill()**

---

# kill() - [manual](https://man7.org/linux/man-pages/man2/kill.2.html)

#include <sys/types.h>
#include <signal.h>
 
📌 **Prototip:** `int kill(pid_t pid, int sig);`

📘 **Açıklama:**

- kill() fonksiyonu, belirtilen pid (process ID) numarasına sinyal (sig) gönderir.

- Bu sinyal, işlem üzerinde belirli bir etki yapar (örneğin, durdurma, sonlandırma, vb).

- pid değeri farklı anlamlara gelir:

- Pozitif değer: Belirtilen pid'ye sahip tek bir işleme sinyal gönderilir.

- 0: Aynı süreç grubundaki tüm işlemlere sinyal gönderilir.

- -1: Geçerli kullanıcıya ait tüm işlemlere sinyal gönderilir (kök kullanıcı hariç).

- -N (negatif ve -1 dışında): N process grubundaki tüm işlemlere sinyal gönderilir.

📤 **Parametre:**
| **Parametre** | **Tür** | **Açıklama**                                                       |
| ------------- | ------- | ------------------------------------------------------------------ |
| `pid`         | `pid_t` | Sinyal gönderilecek işlem kimliği veya özel anlamlar               |
| `sig`         | `int`   | Gönderilecek sinyal numarası (örn: `SIGINT`, `SIGKILL`, `SIGTERM`) |

📤 **Dönüş Değeri:**
| **Durum** | **Açıklama**                    |
| --------- | ------------------------------- |
| Başarı    | `0` döner                       |
| Hata      | `-1` döner ve `errno` ayarlanır |


🧪 **Örnek:**
```c
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = getpid(); // Kendi işlemimizin PID'si

    printf("Kendi işlemimize SIGINT sinyali gönderiliyor...\n");
    if (kill(pid, SIGINT) == -1) {
        perror("kill hatası");
        return 1;
    }

    return 0;
}
```

🛑 **Dikkat Et:**

- Sinyal gönderilen işlem sinyali yakalamıyorsa (veya engellemiyorsa), varsayılan davranış gerçekleşir (örn. işlem sonlanabilir).

- SIGKILL sinyali yakalanamaz veya engellenemez, işlemi zorla sonlandırır.

- kill() sinyali göndermek için yeterli yetkiye sahip olmanız gerekir (örn. başka bir kullanıcının işlemi için root olmalısınız).

💡 **minishell'de Kullanımı:**

- Kullanıcı tarafından Ctrl+C (SIGINT) veya Ctrl+\ (SIGQUIT) gibi sinyaller yakalandığında, çocuk süreçlere sinyal göndermek için.

- Çalışan komutları durdurmak veya sonlandırmak için.

---

**Geri:** [SUBJECT](../subject/subject.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **kill()**