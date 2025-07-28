**Geri:** [SUBJECT](../../README.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **access()**

---

# access() - [manual](https://man7.org/linux/man-pages/man2/access.2.html)

📌 **Prototip:** `int access(const char *pathname, int mode);`

📘 **Açıklama:**

- access() fonksiyonu, belirtilen dosyanın erişim izinlerini kontrol eder.

- Dosyanın var olup olmadığını ve belirtilen erişim türlerinin (okuma, yazma, çalıştırma) izinli olup olmadığını test etmek için kullanılır.

- Gerçek kullanıcı kimlik bilgileri (effective değil) ile kontrol yapar, bu yüzden setuid programlarda dikkatli kullanılmalıdır.

📤 **Parametre:**
| **Parametre** | **Tür**        | **Açıklama**                                                                                                                                                                                                                  |
| ------------- | -------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| `pathname`    | `const char *` | Erişim kontrolü yapılacak dosya ya da dizin yolu                                                                                                                                                                              |
| `mode`        | `int`          | Kontrol edilecek erişim türü, aşağıdaki değerlerin birleşimi olabilir: <br> - `R_OK` (okuma izin kontrolü) <br> - `W_OK` (yazma izin kontrolü) <br> - `X_OK` (çalıştırma izin kontrolü) <br> - `F_OK` (dosya var mı kontrolü) |

📤 **Dönüş Değeri:**
| **Durum** | **Açıklama**                                       |
| --------- | -------------------------------------------------- |
| Başarı    | `0` döner (erişim mümkün)                          |
| Hata      | `-1` döner ve `errno` uygun hata koduyla ayarlanır |

 🧪 **Örnek:**
```c
#include <unistd.h>
#include <stdio.h>

int main() {
    const char *file = "test.txt";

    if (access(file, F_OK) == 0) {
        printf("Dosya mevcut.\n");
    } else {
        perror("Dosya bulunamadı");
    }

    if (access(file, R_OK) == 0) {
        printf("Dosya okunabilir.\n");
    } else {
        perror("Dosya okunamaz");
    }

    return 0;
}
```

🛑 **Dikkat Et:**

- access() sadece dosyanın erişim izinlerini kontrol eder, dosya açma işlemi yapmaz.

- Kontrol ile açma arasında dosya durumu değişebilir, bu yüzden TOCTOU (Time Of Check to Time Of Use) hatalarına dikkat.

- Özellikle setuid/setgid programlarda access() kullanımı güvenlik riski oluşturabilir.

💡 **minishell'de Kullanımı:**

- Komut çalıştırmadan önce, yürütülebilir dosyanın erişilebilirliğini kontrol etmek için.

- PATH dizinlerinde program var mı, izinleri uygun mu diye kontrol etmekte kullanılır.

---

**Geri:** [SUBJECT](../../README.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **access()**