**Geri:** [SUBJECT](../../README.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **fork()**

---

# fork() - [manual](https://man7.org/linux/man-pages/man2/fork.2.html)

📌 **Prototip:** `pid_t fork(void);`

📘 **Açıklama:**

- fork() fonksiyonu, mevcut süreçten (process) yeni bir çocuk süreç (child process) oluşturur.

- Yeni süreç, mevcut sürecin (parent process) tam bir kopyasıdır; aynı kodu, veri ve dosya tanımlayıcılarını paylaşır.

- fork() çağrısından sonra iki süreç paralel olarak çalışmaya devam eder.

- Dönen değer ile hangi süreçte olunduğu anlaşılır.

📤 **Parametre:**
| **Parametre**     | **Tür** | **Açıklama**     |
| ----------------- | ------- | ---------------- |
| — (parametre yok) | —       | Parametre almaz. |


📤 **Dönüş Değeri:**
| **Durum** | **Açıklama**                                                                    |
| --------- | ------------------------------------------------------------------------------- |
| Pozitif   | Yeni oluşturulan çocuk sürecin PID (Process ID) döner (parent process içindir). |
| 0         | Çocuk süreçte döner.                                                            |
| -1        | Hata oluştu, yeni süreç oluşturulamadı.                                         |

🧪 **Örnek:**
```c
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>

int main() {
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork hatası");
        return 1;
    }

    if (pid == 0) {
        // Çocuk süreç
        printf("Bu çocuk süreçtir. PID: %d\n", getpid());
    } else {
        // Ana süreç (parent)
        printf("Bu ana süreçtir. Çocuk PID: %d\n", pid);
    }

    return 0;
}

```

🛑 **Dikkat Et:**

- fork() sonrası her iki süreç de aynı kodu çalıştırmaya devam eder; ayrım dönüş değeri ile yapılır.

- Dosya tanımlayıcıları, bellek içerikleri kopyalanır ancak iki süreç birbirinden bağımsızdır.

- Çok fazla fork() çağrısı sistem kaynaklarını tüketebilir, dikkatli kullanılmalıdır.

💡 **minishell'de Kullanımı:**

- Komut çalıştırırken yeni bir süreç oluşturmak için kullanılır.

- Böylece shell, çocuk süreçte komutu çalıştırır, kendi ana süreci bekler ve başka işlemler yapmaya devam eder.

---

**Geri:** [SUBJECT](../subject/subject.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **fork()**