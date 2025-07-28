**Geri:** [SUBJECT](../../README.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **write()**

---

# write() - [manual](https://man7.org/linux/man-pages/man2/write.2.html)

📌 **Prototip:** `ssize_t write(int fd, const void *buf, size_t count);`

📘 **Açıklama:**
- write(), bir dosya tanımlayıcısına (file descriptor) belirli miktarda veri yazar. Bu terminal olabilir, bir dosya olabilir veya bir pipe.

📤 **Parametre:**

| **Parametre** | **Tür**        | **Açıklama**                                                          |
|---------------|----------------|-----------------------------------------------------------------------|
| `fd`          | `int`          | Hedef dosya tanımlayıcısı: 1 → stdout (ekran) 2 → stderr (hata ekranı)|
| `buf`         | `const void *` | Yazılacak verinin bulunduğu bellek adresi                             |
| `count`       | `size_t`       | Yazılacak byte sayısı                                                 |

📤 **Dönüş Değeri:**
| **Durum** | **Açıklama**                                             |
|-----------|----------------------------------------------------------|
| Başarı    | Yazılan byte sayısını döner                              |
| Hata      | -1 döner ve errno ayarlanır                              |

🧪 **Örnek:**
```c
#include <unistd.h>

int main() {
    char *msg = "Merhaba!\n";
    write(1, msg, 15);  // 1 = stdout
    return 0;
}
#include <unistd.h>

int main() {
    char *hata = "Bir hata oluştu!\n";
    write(2, hata, 18);  // 2 = stderr
    return 0;
}
```
🛑 **Dikkat Etmen Gerekenler:**
- write() sistem çağrısıdır. stdio.h içindeki printf() gibi buffered değildir. Doğrudan sistemle iletişim kurar.
- Her zaman tüm veriyi yazmaz. Özellikle dosya veya ağ işlemlerinde, kısmi yazma olabilir. Geri dönen değeri kontrol et!
- Başarısız olursa -1 döner ve errno ayarlanır.

💡 **minishell'de Kullanımı:**

- Standart çıktı veya hata çıktısına veri yazmak.

- Pipe veya yönlendirilmiş dosya tanımlayıcılarına ham veri yazmak.

---

**Geri:** [SUBJECT](../subject/subject.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **write()**