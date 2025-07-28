**Geri:** [SUBJECT](../../README.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **wait3()**

---

# wait3() - [manual](https://man7.org/linux/man-pages/man2/wait3.2.html)


#include <sys/types.h>
#include <sys/wait.h>

📌 **Prototip:** `pid_t wait3(int *status, int options, struct rusage *rusage);`

📘 **Açıklama:**

- wait3() fonksiyonu, child process’lerden birinin durumunu bekler ve bekleme sırasında o process'in kaynak kullanım bilgilerini toplar.

- waitpid() gibi çocuk process’lerin durumunu beklemek için kullanılır, ancak ek olarak kaynak kullanımı (rusage) bilgisini de sağlar.

- Genellikle BSD tabanlı sistemlerde bulunur, POSIX standardında olmayabilir. Linux’ta wait4() tercih edilir.

📤 **Parametre:**
| **Parametre** | **Tür**           | **Açıklama**                                                    |
| ------------- | ----------------- | --------------------------------------------------------------- |
| `status`      | `int *`           | Beklenen çocuk process’in çıkış durumunun yazılacağı değişken   |
| `options`     | `int`             | Bekleme davranışını kontrol eden bayraklar (örn. `WNOHANG`)     |
| `rusage`      | `struct rusage *` | Kaynak kullanımı bilgilerini alacak yapı adresi (NULL olabilir) |

📤 **Dönüş Değeri:**
| **Durum** | **Açıklama**                                         |
| --------- | ---------------------------------------------------- |
| Başarı    | Bitmiş çocuk process’in PID’si (pozitif tamsayı)     |
|           | Eğer `WNOHANG` seçili ve çocuk bitmemişse 0 döner    |
| Hata      | `-1` döner ve `errno` uygun hata koduyla güncellenir |

🧪 **Örnek:**
```c
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/resource.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork hatası");
        return 1;
    }

    if (pid == 0) {
        // Child process
        sleep(1);
        _exit(0);
    } else {
        int status;
        struct rusage usage;

        pid_t waited_pid = wait3(&status, 0, &usage);
        if (waited_pid == -1) {
            perror("wait3 hatası");
            return 1;
        }

        printf("Çocuk PID: %d\n", waited_pid);
        printf("User CPU time used: %ld.%06ld sec\n",
               (long)usage.ru_utime.tv_sec, (long)usage.ru_utime.tv_usec);
        printf("System CPU time used: %ld.%06ld sec\n",
               (long)usage.ru_stime.tv_sec, (long)usage.ru_stime.tv_usec);
    }

    return 0;
}
```


🛑 **Dikkat Et:**

- wait3() POSIX standartlarında olmayabilir, Linux’ta yerine wait4() kullanılması tavsiye edilir.

- rusage yapısı ile process'in CPU zamanı, I/O istatistikleri gibi bilgiler alınabilir.

- status parametresi, çocuk process’in exit durumunu içerir.

💡 **minishell'de Kullanımı:**

- Genelde waitpid() tercih edilir, ama çocuk process kaynak kullanımı takip edilmek istenirse wait3() veya wait4() kullanılabilir.

---

**Geri:** [SUBJECT](../../README.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **wait3()**