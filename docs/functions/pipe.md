**Geri:** [SUBJECT](../../README.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **pipe()**

---

# pipe() - [manual](https://man7.org/linux/man-pages/man2/pipe.2.html)

📌 **Prototip:** `int pipe(int pipefd[2]);`

📘 **Açıklama:**

- pipe() fonksiyonu, birbirine bağlı bir çift dosya tanımlayıcısı (file descriptor) oluşturur.

- Bu çift, bir uçtan yazılan verinin diğer uçtan okunmasını sağlar.

- Yani, bir süreç bu pipe’ın yazma ucuna veri yazarken, diğer süreç bu veriyi pipe’ın okuma ucundan okuyabilir.

- Genellikle komutlar arasında veri aktarımı için kullanılır (örneğin ls | grep txt gibi pipe işlemlerinde).

📤 **Parametre:**
| **Parametre** | **Tür**  | **Açıklama**                        |
| ------------- | -------- | ----------------------------------- |
| `pipefd`      | `int[2]` | İki elemanlı bir tam sayı dizisi:   |
|               |          | `pipefd[0]` → Okuma ucu (read end)  |
|               |          | `pipefd[1]` → Yazma ucu (write end) |

📤 **Dönüş Değeri:**
| **Durum** | **Açıklama**                                                  |
| --------- | ------------------------------------------------------------- |
| Başarı    | `0` döner, `pipefd` dizisi valid dosya tanımlayıcılar içerir. |
| Hata      | `-1` döner ve `errno` uygun hata kodu ile ayarlanır.          |

🧪 **Örnek:**
```c
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main() {
    int pipefd[2];
    char buf[20];
    if (pipe(pipefd) == -1) {
        perror("pipe hatası");
        return 1;
    }

    const char *msg = "Merhaba Pipe!";
    write(pipefd[1], msg, strlen(msg));

    ssize_t n = read(pipefd[0], buf, sizeof(buf) - 1);
    if (n == -1) {
        perror("read hatası");
        return 1;
    }

    buf[n] = '\0';  // Sonlandırıcı
    printf("Pipe’dan okunan: %s\n", buf);

    close(pipefd[0]);
    close(pipefd[1]);

    return 0;
}
```
🛑 **Dikkat Et:**

- Pipe’un iki ucu vardır, biri yazma, diğeri okuma için.

- Yazma ucuna veri yazılır, okuma ucundan okunur.

- Pipe ile sadece bir yönlü veri akışı olur, iki yönlü için iki pipe gerekebilir.

- Yazma ucunu kapatmazsanız okuma işlemi bekleyebilir.

- Genellikle fork sonrası çocuk ve ebeveyn arasında iletişim için kullanılır.

💡 **minishell'de Kullanımı:**

- Komutlar arasında çıktı-yönlendirme için (örneğin cmd1 | cmd2 komutunda komutlar arası veri aktarımı).

- Çocuk süreçlerin arasında iletişim sağlamak için.

---

**Geri:** [SUBJECT](../subject/subject.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **pipe()**