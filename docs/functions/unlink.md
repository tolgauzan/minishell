**Geri:** [SUBJECT](../../README.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **unlink()**

---

# unlink() - [manual](https://man7.org/linux/man-pages/man2/unlink.2.html)


📌 **Prototip:** `int unlink(const char *pathname);`


📘 **Açıklama:**

- unlink() fonksiyonu, verilen pathname ile belirtilen dosya sistemindeki dosyanın bağlantısını (linkini) siler.

- Eğer bu dosya başka linklere sahip değilse ve açık dosya tanımlayıcıları yoksa, dosyanın disk üzerindeki içeriği de silinir.

- Kısaca dosyayı dosya sisteminden kaldırmak için kullanılır.

📤 **Parametre:**
| **Parametre** | **Tür**        | **Açıklama**            |
| ------------- | -------------- | ----------------------- |
| `pathname`    | `const char *` | Silinecek dosyanın yolu |

📤 **Dönüş Değeri:**
| **Durum** | **Açıklama**                               |
| --------- | ------------------------------------------ |
| `0`       | Başarıyla dosya silindi                    |
| `-1`      | Hata oluştu, `errno` uygun kodla ayarlandı |


🧪 **Örnek:**
```c
#include <unistd.h>
#include <stdio.h>

int main() {
    const char *dosya = "silinecek_dosya.txt";

    if (unlink(dosya) == -1) {
        perror("Dosya silme hatası");
        return 1;
    } else {
        printf("%s dosyası başarıyla silindi.\n", dosya);
    }
    return 0;
}
```

🛑 **Dikkat Et:**

- unlink() yalnızca dosya bağlantısını kaldırır, eğer dosyanın başka linkleri varsa dosya diskten hemen kaldırılmaz.

- Açık dosya tanımlayıcıları varsa dosya fiziksel olarak ancak tüm açık dosya kapandığında silinir.

- Dizinleri silmek için unlink() kullanılmaz; bunun yerine rmdir() kullanılır.

💡 **minishell'de Kullanımı:**

- rm gibi dosya silme işlemlerinde, dosyanın dosya sisteminden kaldırılması için kullanılır.

- Kullanıcı komutlarının sistemde dosya manipülasyonu yapması gerektiğinde önemli fonksiyonlardan biridir.

---

**Geri:** [SUBJECT](../subject/subject.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **unlink()**