**Geri:** [SUBJECT](../../README.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **waitpid()**

---

# waitpid() - [manual](https://man7.org/linux/man-pages/man2/waitpid.2.html)

#include <sys/types.h>
#include <sys/wait.h>

📌 **Prototip:** `pid_t waitpid(pid_t pid, int *status, int options);`

📘 **Açıklama:**

- waitpid() fonksiyonu, belirli bir çocuk process'in durumunu beklemek veya sorgulamak için kullanılır.

- wait() fonksiyonundan farklı olarak, hangi child process'in beklenileceği pid parametresiyle belirlenebilir.

- Ayrıca options parametresiyle fonksiyonun davranışı değiştirilir (örneğin bloklayıcı/non-bloklayıcı).

- status parametresine çocuk process'in çıkış durumu yazılır.

📤 **Parametre:**
| **Parametre** | **Tür** | **Açıklama**                                                     |
| ------------- | ------- | ---------------------------------------------------------------- |
| `pid`         | `pid_t` | Beklenecek process ID'si:                                        |
|               |         | - Pozitif sayı: sadece bu pid'ye sahip çocuk beklenir            |
|               |         | - `-1`: Tüm çocuk process'ler beklenir (wait() ile aynı)         |
|               |         | - `0`: Aynı process group'daki çocuklar beklenir                 |
|               |         | - `< -1`: `-pid` ile aynı process group ID'sine sahip çocuklar   |
| `status`      | `int *` | Çocuk process’in çıkış durumunun yazılacağı adres, NULL olabilir |
| `options`     | `int`   | Bekleme davranışı kontrolü için bayraklar:                       |
|               |         | - `0`: Bloklayıcı (varsayılan)                                   |
|               |         | - `WNOHANG`: Bloklamadan hemen döner, çocuk bitmediyse 0 döner   |
|               |         | - `WUNTRACED`: Durdurulan çocuklar da rapor edilir               |


📤 **Dönüş Değeri:**
| **Durum** | **Açıklama**                                             |
| --------- | -------------------------------------------------------- |
| Başarı    | Bitmiş çocuk process’in PID’si (pozitif tamsayı)         |
|           | Eğer `WNOHANG` kullanıldıysa ve çocuk bitmemişse 0 döner |
| Hata      | `-1` döner ve `errno` uygun hata koduyla güncellenir     |


🧪 **Örnek:**
```c
#include <sys/types.h>
#include <sys/wait.h>
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
        printf("Çocuk process çalışıyor\n");
        sleep(2);
        _exit(42);
    } else {
        // Parent process
        int status;
        pid_t waited_pid;

        // Bloklayıcı bekleme
        waited_pid = waitpid(pid, &status, 0);
        if (waited_pid == -1) {
            perror("waitpid hatası");
            return 1;
        }

        if (WIFEXITED(status)) {
            printf("Çocuk process %d başarıyla tamamlandı, çıkış kodu: %d\n", waited_pid, WEXITSTATUS(status));
        } else {
            printf("Çocuk process beklenmedik şekilde sonlandı\n");
        }
    }
    return 0;
}
```


🛑 **Dikkat Et:**

- waitpid() ile spesifik çocuk process beklenebilir, bu da kontrolü artırır.

- WNOHANG seçeneği ile non-blocking (bloklamayan) bekleme yapılabilir, yani çocuk henüz bitmediyse hemen döner.

- status makrolarla (örneğin WIFEXITED, WEXITSTATUS) analiz edilmelidir.

💡 **minishell'de Kullanımı:**

- Minishell, fork ile çalıştırdığı komutların child process’lerini spesifik olarak beklemek için waitpid() kullanabilir.

- Böylece eş zamanlı çalışan birçok child process kontrol edilebilir.


---

**Geri:** [SUBJECT](../subject/subject.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **waitpid()**