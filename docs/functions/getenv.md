**Geri:** [SUBJECT](../../README.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **getenv()**

---

# getenv() - [manual](https://man7.org/linux/man-pages/man3/getenv.3.html)


📌 **Prototip:** `char *getenv(const char *name);`


📘 **Açıklama:**

- getenv() fonksiyonu, işletim sisteminde tanımlı ortam değişkenlerinden (environment variables) birinin değerini alır.

- name parametresi, aranacak ortam değişkeninin adıdır (örneğin "PATH", "HOME").

- Eğer ortam değişkeni bulunursa, değere işaret eden bir işaretçi döner; bulunamazsa NULL döner.

- Dönen değer doğrudan sistem tarafından yönetilen belleğe işaret eder, kopyalamak gerekebilir.

📤 **Parametre:**
| **Parametre** | **Tür**        | **Açıklama**                           |
| ------------- | -------------- | -------------------------------------- |
| `name`        | `const char *` | Alınmak istenen ortam değişkeninin adı |

📤 **Dönüş Değeri:**
| **Durum** | **Açıklama**                                        |
| --------- | --------------------------------------------------- |
| Başarı    | Ortam değişkeninin değerini gösteren `char *` döner |
| Hata      | Ortam değişkeni yoksa `NULL` döner                  |

🧪 **Örnek:**
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    char *path = getenv("PATH");
    if (path == NULL) {
        printf("PATH değişkeni bulunamadı.\n");
    } else {
        printf("PATH: %s\n", path);
    }
    return 0;
}
```

🛑 **Dikkat Et:**

- Dönen değer üzerinde doğrudan değişiklik yapmak güvenli değildir.

- Ortam değişkenini kopyalamak istersen strdup() kullanılabilir.

- getenv() fonksiyonu thread-safe değildir, çoklu thread ortamlarında dikkatli kullanılmalıdır.

💡 **minishell'de Kullanımı:**

- Kullanıcının ortam değişkenlerini okumak ve komutları ararken $PATH gibi değişkenleri çözmek için kullanılır.

- Ortam değişkenleri shell’in davranışını kontrol eder, örneğin çalıştırılacak dosyanın yeri gibi.

---

**Geri:** [SUBJECT](../subject/subject.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **getenv()**