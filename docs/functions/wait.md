**Geri:** [SUBJECT](../../README.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **wait()**

---

# wait() - [manual](https://man7.org/linux/man-pages/man2/wait.2.html)

#include <sys/types.h>
#include <sys/wait.h>

📌 **Prototip:** `pid_t wait(int *status);`


📘 **Açıklama:**

- wait() fonksiyonu, çağıran process’in (genellikle parent process), çocuk process’lerinden birinin bitmesini beklemesini sağlar.

- Çocuk process tamamlandığında, onun pid'si döner ve exit durumu status parametresine yazılır.

- Eğer beklenen çocuk process yoksa veya hata oluşursa -1 döner.

- status değişkeni, çocuk process’in nasıl sonlandığına dair bilgi içerir ve makrolarla yorumlanabilir.

📤 **Parametre:**
| **Parametre** | **Tür** | **Açıklama**                                                         |
| ------------- | ------- | -------------------------------------------------------------------- |
| `status`      | `int *` | Çocuk process’in çıkış durumunun yazılacağı adres. NULL da olabilir. |

📤 **Dönüş Değeri:**
| **Durum** | **Açıklama**                                         |
| --------- | ---------------------------------------------------- |
| Başarı    | Bitmiş çocuk process’in PID’si (pozitif tamsayı)     |
| Hata      | `-1` döner ve `errno` uygun hata koduyla güncellenir |

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
        _exit(42);  // Çıkış kodu 42
    } else {
        // Parent process
        int status;
        pid_t waited_pid = wait(&status);

        if (waited_pid == -1) {
            perror("wait hatası");
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

- wait() çağrısı bloklayıcıdır, yani çocuk process bitene kadar parent bekler.

- Eğer birden fazla çocuk process varsa, herhangi birinin bitmesini bekler.

- status değişkeni makrolar (WIFEXITED, WEXITSTATUS, WIFSIGNALED, vb.) ile analiz edilmelidir.

💡 **minishell'de Kullanımı:**

- Fork ile oluşturulan child process’lerin bitmesini beklemek ve çıkış durumlarını almak için.

- Böylece shell, komutların tamamlanmasını kontrol edip kullanıcıya uygun geri bildirim verebilir.

---

**Geri:** [SUBJECT](../../README.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **wait()**