**Geri:** [SUBJECT](../../README.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **readdir()**

---

# readdir() - [manual](https://man7.org/linux/man-pages/man3/readdir.3.html)

#include <dirent.h>

📌 **Prototip:** `struct dirent *readdir(DIR *dirp);`

📘 **Açıklama:**

- readdir() fonksiyonu, daha önce opendir() ile açılmış olan dizin akışından bir sonraki dosya ya da dizin girişini okur.

- Her çağrıldığında dizindeki sıradaki bir dirent yapısını döner.

- Dizinin sonuna gelindiğinde NULL döner.

- Okunan dirent yapısı, dosya veya dizin adı gibi bilgiler içerir.

📤 **Parametre:**
| **Parametre** | **Tür** | **Açıklama**                             |
| ------------- | ------- | ---------------------------------------- |
| `dirp`        | `DIR *` | `opendir()` ile açılmış dizin işaretçisi |


📤 **Dönüş Değeri:**
| **Durum** | **Açıklama**                                                 |
| --------- | ------------------------------------------------------------ |
| Başarı    | Bir sonraki dizin girdisini gösteren `struct dirent *` döner |
| Son       | Dizin sonuna gelindiyse `NULL` döner                         |
| Hata      | `NULL` döner (hata durumunda `errno` ayarlanır)              |

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

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        printf("Dosya/Dizin: %s\n", entry->d_name);
    }

    closedir(dir);
    return 0;
}
```


🛑 **Dikkat Et:**

- readdir() çağrısı dizin sonuna geldiğinde NULL döner, dönen değerin NULL olup olmadığı her zaman kontrol edilmelidir.

- readdir() döndürdüğü pointer geçicidir, tekrar çağrıldığında üzerine yazılabilir. Eğer bilgiyi tutmak istersen, kopyalamalısın.

💡 **minishell'de Kullanımı:**

- Dizin içeriğini listelemek için, örneğin ls komutu implementasyonunda.

- Dizin içerisindeki dosyaların isimlerine erişmek için.

---

**Geri:** [SUBJECT](../../README.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **readdir()**