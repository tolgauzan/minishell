**Geri:** [SUBJECT](../../README.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **dup()**

---

# dup() - [manual](https://man7.org/linux/man-pages/man2/dup.2.html)

📌 **Prototip:** `int dup(int oldfd);`

📘 **Açıklama:**

- dup() fonksiyonu, mevcut bir dosya tanımlayıcısını (file descriptor) kopyalar ve en düşük kullanılabilir dosya tanımlayıcısını döner.

- Yani, oldfd dosya tanımlayıcısının bir kopyası oluşturulur ve yeni dosya tanımlayıcısı döner.

- Yeni dosya tanımlayıcısı, aynı dosya açıklayıcısını (file description) paylaşır, yani dosya pozisyonu ve dosya durumları ortaktır.

- Genellikle standart giriş/çıkış yönlendirmelerinde kullanılır (örneğin dup2() ile birlikte).

📤 **Parametre:**
| **Parametre** | **Tür** | **Açıklama**                     |
| ------------- | ------- | -------------------------------- |
| `oldfd`       | `int`   | Kopyalanacak dosya tanımlayıcısı |

📤 **Dönüş Değeri:**
| **Durum** | **Açıklama**                                        |
| --------- | --------------------------------------------------- |
| Başarı    | Yeni dosya tanımlayıcısı (0'dan büyük int) döner    |
| Hata      | `-1` döner ve `errno` uygun hata kodu ile ayarlanır |

🧪 **Örnek:**
```c
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main() {
    int fd = open("test.txt", O_RDONLY);
    if (fd == -1) {
        perror("Dosya açılamadı");
        return 1;
    }

    int newfd = dup(fd);
    if (newfd == -1) {
        perror("dup hatası");
        close(fd);
        return 1;
    }

    printf("Orijinal fd: %d, Kopya fd: %d\n", fd, newfd);

    close(fd);
    close(newfd);

    return 0;
}

```

🛑 **Dikkat Et:**

- dup() ile kopyalanan dosya tanımlayıcıları aynı dosya açıklamasını paylaşır; bu yüzden biriyle yapılan değişiklikler diğerini etkiler.

- Kopyalanan dosya tanımlayıcısını kullanmayı bitirdiğinde close() ile kapatmalısın.

- Standart giriş/çıkış yönlendirmelerinde (stdin, stdout, stderr) yönlendirme yapmak için sıkça kullanılır.

💡 **minishell'de Kullanımı:**

- Komut yönlendirmelerinde (redirection) eski standart giriş veya çıkış dosya tanımlayıcısını yedeklemek veya değiştirmek için.

- Pipe veya dosya descriptor’larını uygun şekilde ayarlamak için.


---

**Geri:** [SUBJECT](../../README.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **dup()**