**Geri:** [SUBJECT](../../README.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **getcwd()**

---

# getcwd() - [manual](https://man7.org/linux/man-pages/man3/getcwd.3.html)

📌 **Prototip:** `char *getcwd(char *buf, size_t size);`

📘 **Açıklama:**

- getcwd() fonksiyonu, programın geçerli çalışma dizininin (current working directory) tam yolunu alır ve buf tarafından gösterilen belleğe yazar.

- size parametresi, buf'un kapasitesini (byte cinsinden) belirtir.

- Eğer buf NULL ise, fonksiyon dinamik olarak yeterli büyüklükte bir bellek ayırır ve pointer döner (bu durumda geri çağıran kişi belleği free() ile serbest bırakmalı).

- Başarısız olursa NULL döner ve errno ayarlanır.

📤 **Parametre:**
| **Parametre** | **Tür**  | **Açıklama**                                   |
| ------------- | -------- | ---------------------------------------------- |
| `buf`         | `char *` | Geçerli dizin yolunun yazılacağı bellek adresi |
| `size`        | `size_t` | `buf` için ayrılan bellek boyutu (byte)        |

📤 **Dönüş Değeri:**
| **Durum** | **Açıklama**                               |
| --------- | ------------------------------------------ |
| Başarı    | `buf` işaretçisini döner (yol içeriği ile) |
| Hata      | `NULL` döner ve `errno` ayarlanır          |


```c
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) == NULL) {
        perror("Geçerli dizin alınamadı");
        return 1;
    }
    printf("Geçerli dizin: %s\n", cwd);
    return 0;
}

```

🛑 **Dikkat Et:**

- buf boyutu size yeterli olmalıdır, yoksa fonksiyon hata verir.

- buf NULL ise fonksiyon malloc ile bellek ayırır, sonra serbest bırakılmalıdır.

- Shell’de prompt veya dizin gösteriminde kullanılır.

💡 **minishell'de Kullanımı:**

- Prompt’ta geçerli dizini göstermek için.

- pwd komutunun işleyişinde temel fonksiyon.

---

**Geri:** [SUBJECT](../../README.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **getcwd()**