
**Geri:** [SUBJECT](../../README.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **read()**

---

# read() - [manual](https://man7.org/linux/man-pages/man2/read.2.html)

📌 **Prototip:** `ssize_t read(int fd, void *buf, size_t count);`


 📘 **Açıklama:**
- read() fonksiyonu, açık olan bir dosya tanımlayıcısından (fd) veri okur ve bu veriyi buf adlı bellek alanına yazar. Okuma işlemi genellikle dosyalar, borular (pipes), terminal veya soketlerden veri almak için kullanılır.

📤 **Parametre:**
| **Parametre** | **Tür**  | **Açıklama**                                                                      |
| ------------- | -------- | --------------------------------------------------------------------------------- |
| `fd`          | `int`    | Okunacak dosya veya cihazın dosya tanımlayıcısı <br> (0 → **stdin**, yani klavye) |
| `buf`         | `void *` | Verilerin yazılacağı bellek adresi (**buffer**)                                   |
| `count`       | `size_t` | Maksimum okunacak byte sayısı                                                     |


📤 **Dönüş Değeri:**
| **Durum** | **Açıklama**                                                                     |
| --------- | -------------------------------------------------------------------------------- |
| Başarı    | Okunan byte sayısını döner. <br> `0` dönerse **dosya sonuna** (EOF) gelinmiştir. |
| Hata      | `-1` döner ve `errno` uygun hata koduyla güncellenir.                            |


🧪 **Örnek:**
```c
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main() {
    char buffer[100];
    int fd = open("test.txt", O_RDONLY);
    if (fd == -1) {
        perror("Dosya açılamadı");
        return 1;
    }

    ssize_t bytesRead = read(fd, buffer, sizeof(buffer) - 1);
    if (bytesRead == -1) {
        perror("Okuma hatası");
        close(fd);
        return 1;
    }

    buffer[bytesRead] = '\0'; // Sonlandırıcı koyuyoruz (string için)
    printf("Okunan veri: %s\n", buffer);

    close(fd);
    return 0;
}
```
🛑 **Dikkat Et:**
- read() okuma yaptığı byte sayısını döner, bu sayı count parametresinden küçük olabilir.
- Okunan veri binary olabilir, metin değilse string sonlandırıcı koymamalısın.
- Dosya sonu (EOF) read() 0 döner.

💡**minishell'de Kullanımı:**
- Komut satırından kullanıcı girdisini almak veya borulardan veri okumak için.
- Dosya input redirection işlemlerinde dosyadan veri çekmek için kullanılır.

---

**Geri:** [SUBJECT](../subject/subject.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **read()**