**Geri:** [SUBJECT](../../README.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **wait4()**

---

# wait4() - [manual](https://man7.org/linux/man-pages/man2/wait4.2.html)

#include <sys/types.h>
#include <sys/wait.h>
#include <sys/resource.h>

📌 **Prototip:** `pid_t wait4(pid_t pid, int *status, int options, struct rusage *rusage);`


📘 **Açıklama:**

- wait4() fonksiyonu, belirtilen çocuk process’in durumunu bekler ve aynı zamanda kaynak kullanımı bilgilerini toplar.

- pid parametresi ile hangi child process’in beklenileceği seçilir.

- waitpid() fonksiyonunun rusage versiyonu olarak düşünülebilir.

- Kaynak kullanımı bilgileri rusage yapısına yazılır.

- Sistem çağrısı seviyesinde çocuk process durumu ve kaynak takibi için kullanılır.

📤 **Parametre:**
| **Parametre** | **Tür**           | **Açıklama**                                                                                                                              |
| ------------- | ----------------- | ----------------------------------------------------------------------------------------------------------------------------------------- |
| `pid`         | `pid_t`           | Beklenecek çocuk process’in PID’si<br>- `-1` → herhangi bir çocuk<br>- `0` → aynı process group içindeki çocuk<br>- `>0` → belirtilen PID |
| `status`      | `int *`           | Beklenen çocuk process’in çıkış durumunun yazılacağı değişken                                                                             |
| `options`     | `int`             | Bekleme davranışını kontrol eden bayraklar (örn. `WNOHANG`)                                                                               |
| `rusage`      | `struct rusage *` | Kaynak kullanımı bilgilerini alacak yapı adresi (NULL olabilir)                                                                           |

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

        pid_t waited_pid = wait4(pid, &status, 0, &usage);
        if (waited_pid == -1) {
            perror("wait4 hatası");
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

- pid parametresi ile hangi çocuk process’in beklenileceği seçilir.

- status ile çocuk process’in çıkış durumu okunur, rusage ile kaynak kullanımı.

- options parametresi sayesinde bekleme davranışı kontrol edilebilir (örn. WNOHANG).

💡 **minishell'de Kullanımı:**

- Çocuk process’in durumunu beklemek ve kaynak kullanımı takibi için.

- waitpid()'e alternatif olarak, kaynak kullanımı detaylarını almak istediğinde kullanılır.


---

**Geri:** [SUBJECT](../../README.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **wait4()**