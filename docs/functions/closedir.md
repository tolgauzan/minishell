**Geri:** [SUBJECT](../../README.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **closedir()**

---

# closedir() - [manual](https://man7.org/linux/man-pages/man3/closedir.3.html)

📌 **Prototip:** `int closedir(DIR *dirp);`


📘 Açıklama:

- closedir() fonksiyonu, opendir() ile açılmış bir dizin akışını kapatır ve sistem kaynaklarını serbest bırakır.

- Artık o dizin akışına erişim yapılamaz, ve dosya tanımlayıcısı kapatılır.

- Açılmış dizinleri kapatmak sistem kaynaklarını doğru kullanmak için önemlidir.

📤 **Parametre:**
| **Parametre** | **Tür** | **Açıklama**                             |
| ------------- | ------- | ---------------------------------------- |
| `dirp`        | `DIR *` | `opendir()` ile açılmış dizin işaretçisi |

📤 **Dönüş Değeri:**
| **Durum** | **Açıklama**                  |
| --------- | ----------------------------- |
| Başarı    | 0 döner                       |
| Hata      | -1 döner ve `errno` ayarlanır |

🧪 **Örnek:**
```c
#include <dirent.h>
#include <stdio.h>

int main() {
    DIR *dir = opendir(".");
    if (dir == NULL) {
        perror("Dizin açılamadı");
        return 1;
    }

    // Dizin içeriğini okumak için kod buraya gelir...

    if (closedir(dir) == -1) {
        perror("Dizin kapatılamadı");
        return 1;
    }

    return 0;
}
```

🛑 **Dikkat Et:**

- opendir() ile açılan her dizin mutlaka closedir() ile kapatılmalıdır.

- closedir() başarısız olursa hata kontrolü yapılmalıdır.

💡 **minishell'de Kullanımı:**

- ls gibi dizin içeriği okuyan komutlarda, dizin açıldıktan sonra iş bitince mutlaka kapatılır.

- Sistem kaynaklarını yönetmek ve bellek sızıntılarını önlemek için önemlidir.


---

**Geri:** [SUBJECT](../../README.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **closedir()**