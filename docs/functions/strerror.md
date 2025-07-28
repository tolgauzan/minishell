**Geri:** [SUBJECT](../../README.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **strerror()**

---

# strerror() - [manual](https://man7.org/linux/man-pages/man3/strerror.3.html)

#include <string.h>

📌 **Prototip:** `char *strerror(int errnum);`

📘 **Açıklama:**

- strerror() fonksiyonu, verilen hata numarasına (errno değerine) karşılık gelen insan tarafından okunabilir hata mesajını döner.

- Bu mesaj genellikle hata ayıklama ve kullanıcıya anlamlı hata mesajı göstermek için kullanılır.

- Dönen string statik bir bellekte saklanır, bu yüzden kopyalanması gerekir eğer uzun süre kullanılacaksa.

📤 **Parametre:**
| **Parametre** | **Tür** | **Açıklama**                       |
| ------------- | ------- | ---------------------------------- |
| `errnum`      | `int`   | Hata numarası (genellikle `errno`) |

📤 **Dönüş Değeri:**
| **Durum** | **Açıklama**                                                      |
| --------- | ----------------------------------------------------------------- |
| Her zaman | Hata numarasına karşılık gelen hata mesajını içeren string döner. |


🧪 **Örnek:**
```c
#include <stdio.h>
#include <string.h>
#include <errno.h>

int main() {
    FILE *fp = fopen("olmayan_dosya.txt", "r");
    if (fp == NULL) {
        printf("Hata: %s\n", strerror(errno));
        return 1;
    }
    fclose(fp);
    return 0;
}
```

🛑 **Dikkat Et:**

- Dönen string statik bellekte olduğundan, sonraki strerror() çağrıları bu içeriği değiştirebilir.

- Çoklu iş parçacığı (multi-threaded) programlarda strerror_r() kullanmak daha güvenlidir.

💡 **minishell'de Kullanımı:**

- Hata durumlarında kullanıcıya anlamlı mesajlar göstermek için.

- Özellikle dosya açma, komut çalıştırma gibi başarısız işlemlerde geri bildirim vermek için kullanılır.


---

**Geri:** [SUBJECT](../../README.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **strerror()**