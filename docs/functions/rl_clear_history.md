**Geri:** [SUBJECT](../../README.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **rl_clear_history()**

---

# rl_clear_history() - [manual](https://tiswww.case.edu/php/chet/readline/history.html)


📌 **Prototip:** `void rl_clear_history(void);`

📘 **Açıklama:**

- rl_clear_history() fonksiyonu, GNU Readline kütüphanesinde bulunan komut geçmişini tamamen temizler.

- Bu fonksiyon çağrıldığında, add_history() ile eklenen tüm geçmiş girdileri silinir ve bellekteki ilgili alanlar serbest bırakılır.

- Özellikle shell kapanırken ya da geçmişi sıfırlamak istediğiniz durumlarda kullanılır.

📤 **Parametre:**
| **Parametre** | **Tür** | **Açıklama**                      |
| ------------- | ------- | --------------------------------- |
| —             | —       | Parametre almaz, boş fonksiyondur |

📤 **Dönüş Değeri:**
| **Durum** | **Açıklama**      |
| --------- | ----------------- |
| —         | `void`, dönüş yok |

🧪 **Örnek:**
```c
#include <readline/history.h>
#include <stdio.h>

int main() {
    // Önce bazı komutlar ekleyelim
    add_history("ls -l");
    add_history("echo Hello");

    printf("Geçmiş temizlenmeden önce komut sayısı: %d\n", history_length);

    // Geçmişi temizle
    rl_clear_history();

    printf("Geçmiş temizlendikten sonra komut sayısı: %d\n", history_length);

    return 0;
}
```

🛑 **Dikkat Et:**

- rl_clear_history() çağrıldıktan sonra, geçmiş tamamen temizlenir ve geri alınamaz.

- Bellek sızıntısı olmaması için geçmişi temizlemek önemlidir özellikle uzun süre çalışan programlarda.

💡 **minishell'de Kullanımı:**

- Kullanıcı shell’den çıkarken veya geçmişi sıfırlamak istediğinde, belleği boşaltmak ve komut geçmişini temizlemek için.


---

**Geri:** [SUBJECT](../subject/subject.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **rl_clear_history()**