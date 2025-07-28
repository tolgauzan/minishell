**Geri:** [SUBJECT](../../README.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **chdir()**

---

# chdir() - [manual](https://man7.org/linux/man-pages/man2/chdir.2.html)


📌 **Prototip:** `int chdir(const char *path);`

📘 **Açıklama:**

- chdir() fonksiyonu, çalışan programın geçerli çalışma dizinini (current working directory) path ile belirtilen dizine değiştirir.

- Başarılı olursa, sonraki görevlere göre dosya yolları yeni dizin baz alınarak değerlendirilir.

- Shell içinde cd komutunun temelinde bu fonksiyon vardır.

📤 **Parametre:**
| **Parametre** | **Tür**        | **Açıklama**              |
| ------------- | -------------- | ------------------------- |
| `path`        | `const char *` | Değiştirilecek dizin yolu |

📤 **Dönüş Değeri:**
| **Durum** | **Açıklama**                    |
| --------- | ------------------------------- |
| Başarı    | `0` döner                       |
| Hata      | `-1` döner ve `errno` ayarlanır |

```c
#include <unistd.h>
#include <stdio.h>

int main() {
    if (chdir("/tmp") == -1) {
        perror("Dizin değiştirilemedi");
        return 1;
    }
    printf("Geçerli dizin başarıyla değiştirildi.\n");
    return 0;
}

```

🛑 **Dikkat Et:**

- Belirtilen dizin mevcut değilse veya erişim izni yoksa hata döner.

- Shell’de cd komutunun çalışması için kullanılır, fakat execve ile çalıştırılan programlarda chdir sonrası süreç devam eder.

💡 **minishell'de Kullanımı:**

- cd built-in komutunu uygularken geçerli dizini değiştirmek için.

- Komutun çalıştığı ortamın dizinini güncellemek için kritik fonksiyon.

---

**Geri:** [SUBJECT](../../README.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **chdir()**