**Geri:** [SUBJECT](../../README.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **free()**

---

# free() - [manual](https://man7.org/linux/man-pages/man3/free.3.html)


📌 **Prototip:** `void free(void *ptr);`

📘 **Açıklama:**

- free() fonksiyonu, daha önce malloc(), calloc(), realloc() ile ayrılmış olan dinamik bellek bloğunu serbest bırakır.

- Bu fonksiyon çağrılmazsa, programın bellek kullanımı artar ve bellek sızıntısı (memory leak) oluşur.

- ptr işaretçisi NULL ise, fonksiyon hiçbir işlem yapmaz (güvenlidir).

📤 **Parametre:**
| **Parametre** | **Tür**  | **Açıklama**                               |
| ------------- | -------- | ------------------------------------------ |
| `ptr`         | `void *` | Serbest bırakılacak bellek bloğunun adresi |


📤 **Dönüş Değeri:**
- free() dönüş değeri yoktur (void).

🧪 **Örnek:**
```c
#include <stdlib.h>
#include <stdio.h>

int main() {
    int *dizi = (int *)malloc(5 * sizeof(int));
    if (dizi == NULL) {
        perror("Bellek ayırma başarısız");
        return 1;
    }

    // Belleği kullan
    for (int i = 0; i < 5; i++) {
        dizi[i] = i * 10;
        printf("%d ", dizi[i]);
    }
    printf("\n");

    // Belleği serbest bırak
    free(dizi);

    return 0;
}
```

🛑 **Dikkat Et:**

- free() sadece malloc ailesi ile ayrılmış bellekler için kullanılmalıdır.

- Bir kez free() ile serbest bırakılan belleğe tekrar erişmek (dangling pointer) ciddi hatalara yol açar.

- Aynı belleği birden fazla kez free() etmek de program hatasına sebep olur (double free).

💡 **minishell'de Kullanımı:**

- Dinamik olarak ayrılan tüm bellekleri iş bitiminde serbest bırakmak için kullanılır.

- Bellek sızıntısını önlemek ve programın stabil çalışmasını sağlamak için kritik önemdedir.

---

**Geri:** [SUBJECT](../subject/subject.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **free()**