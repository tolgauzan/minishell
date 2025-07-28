**Geri:** [SUBJECT](../../README.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **opendir()**

---

# opendir() - [manual](https://man7.org/linux/man-pages/man3/opendir.3.html)

#include <dirent.h>

📌 **Prototip:** `DIR *opendir(const char *name);`


📘 **Açıklama:**

- opendir() fonksiyonu, belirtilen dizin yolunu (name) açar ve bu dizini okumak için bir DIR yapısı pointer’ı döner.

- DIR * tipi, dizin üzerinde gezinmek için kullanılır.

- Dizin başarıyla açılmazsa NULL döner ve errno uygun hata koduyla ayarlanır.

📤 **Parametre:**
| **Parametre** | **Tür**        | **Açıklama**          |
| ------------- | -------------- | --------------------- |
| `name`        | `const char *` | Açılacak dizinin yolu |


📤 **Dönüş Değeri:**
| **Durum** | **Açıklama**                           |
| --------- | -------------------------------------- |
| Başarı    | Dizin akışı için `DIR *` pointer döner |
| Hata      | `NULL` döner ve `errno` ayarlanır      |

🧪 **Örnek:**
```c
#include <stdio.h>
#include <dirent.h>

int main() {
    DIR *dir = opendir(".");
    if (dir == NULL) {
        perror("Dizin açılamadı");
        return 1;
    }

    printf("Dizin başarıyla açıldı.\n");

    closedir(dir);
    return 0;
}
```

🛑 **Dikkat Et:**

- opendir() ile açılan dizin, işiniz bittiğinde closedir() ile kapatılmalıdır.

- Sadece dizinler için kullanılır, dosyalar için değil.

💡 **minishell'de Kullanımı:**

- ls komutunun çalışması için dizin içeriğini okumada,

- Dizin listeleme işlemlerinde,

- Dosya ve dizin yapısını işlemek için.

---

**Geri:** [SUBJECT](../subject/subject.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **opendir()**