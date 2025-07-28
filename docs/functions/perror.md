**Geri:** [SUBJECT](../../README.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **perror()**

---

# perror() - [manual](https://man7.org/linux/man-pages/man3/perror.3.html)

📌 **Prototip:** `void perror(const char *s);`

📘 **Açıklama:**

- perror() fonksiyonu, son hata durumunu (errno) anlamlı bir hata mesajı olarak standart hata çıkışına (stderr) yazdırır.

- Parametre olarak verilen s stringi mesajın başında yazılır, ardından hata mesajı gelir.

- Hata mesajı sistem tarafından errno değerine göre otomatik olarak üretilir.

- Hata ayıklama ve kullanıcı bilgilendirmede çok faydalıdır.

📤 **Parametre:**
| **Parametre** | **Tür**        | **Açıklama**                                                                                |
| ------------- | -------------- | ------------------------------------------------------------------------------------------- |
| `s`           | `const char *` | Hata mesajının başına yazılacak açıklayıcı metin (genellikle fonksiyon adı veya kısa bilgi) |


📤 **Dönüş Değeri:**

- void döner, yani geri dönüş değeri yoktur.

🧪 **Örnek:**
```c
#include <stdio.h>
#include <fcntl.h>

int main() {
    int fd = open("olmayan_dosya.txt", O_RDONLY);
    if (fd == -1) {
        perror("Dosya açma hatası");
        return 1;
    }
    // Buraya ulaşılmaz çünkü dosya açılmadı
    return 0;
}
```

-  Çıktı örneği:
```bash
Dosya açma hatası: No such file or directory
```

🛑 **Dikkat Et:**

- perror() sadece errno global değişkeni anlamlı bir hata kodu içeriyorsa doğru bilgi verir.

- errno'yu elle değiştirmeyin, sistem çağrıları veya bazı kütüphane fonksiyonları otomatik ayarlar.

💡 **minishell'de Kullanımı:**

- Sistemde oluşan hataları kullanıcıya açıklamak için.

- Dosya açma, işlem yapma vb. hatalarını net ve anlaşılır şekilde göstermek için.


---

**Geri:** [SUBJECT](../subject/subject.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **perror()**