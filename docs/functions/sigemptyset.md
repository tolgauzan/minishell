**Geri:** [SUBJECT](../../README.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **sigemptyset()**

---

# sigemptyset() - [manual](https://man7.org/linux/man-pages/man3/sigemptyset.3.html)

#include <signal.h>

📌 **Prototip:** `int sigemptyset(sigset_t *set);`


📘 **Açıklama:**

- sigemptyset() fonksiyonu, sigset_t tipindeki sinyal setini boş (tüm sinyaller kaldırılmış) hale getirir.

- Yani, set içindeki tüm sinyaller temizlenir ve hiçbir sinyal işaretli olmaz.

- Sinyal maskesi oluştururken veya düzenlerken başlangıç için kullanılır.

📤 **Parametre:**
| **Parametre** | **Tür**     | **Açıklama**                       |
| ------------- | ----------- | ---------------------------------- |
| `set`         | `sigset_t*` | İşlem yapılacak sinyal seti adresi |

📤 **Dönüş Değeri:**
| **Durum** | **Açıklama**                    |
| --------- | ------------------------------- |
| Başarı    | `0` döner                       |
| Hata      | `-1` döner ve `errno` ayarlanır |

🧪 **Örnek:**
```c
#include <signal.h>
#include <stdio.h>

int main() {
    sigset_t set;

    if (sigemptyset(&set) == -1) {
        perror("sigemptyset hatası");
        return 1;
    }

    // Artık set boş, hiçbir sinyal işaretli değil
    printf("Sinyal seti boşaltıldı.\n");
    return 0;
}
```

🛑 **Dikkat Et:**

- sigemptyset() çağrıldıktan sonra set içine sigaddset() ile sinyal eklenebilir.

- Sinyal maskesi ayarlama veya değiştirme işlemlerinde temiz bir başlangıç noktası sağlar.

💡 **minishell'de Kullanımı:**

- sigaction() yapısı içinde sa_mask sıfırlamak için.

- Belirli sinyaller dışında diğer tüm sinyalleri maskelenmek istenmediğinde.


---

**Geri:** [SUBJECT](../subject/subject.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **sigemptyset()**