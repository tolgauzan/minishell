**Geri:** [SUBJECT](../../README.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **malloc()**

---

# malloc() - [manual](https://man7.org/linux/man-pages/man3/malloc.3.html)

📌 **Prototip:** `void *malloc(size_t size);`

📘 **Açıklama:**

- malloc() fonksiyonu, belirtilen size kadar baytlık (byte) bellek bloğu dinamik olarak ayırır.

- Başarılı olursa, ayırdığı bellek bloğunun başlangıç adresini void * tipinde döner.

- Başarısız olursa NULL döner.

- Ayırdığı bellek içeriği başlangıçta tanımsız (garbage) değerler içerir, sıfırlanmaz.

- Kullanım sonrası free() ile bellek geri verilmelidir, aksi halde bellek sızıntısı (memory leak) olur.

📤 **Parametre:**
| **Parametre** | **Tür**  | **Açıklama**                               |
| ------------- | -------- | ------------------------------------------ |
| `size`        | `size_t` | Ayırılacak bellek miktarı (byte cinsinden) |

📤 **Dönüş Değeri:**
| **Durum** | **Açıklama**                              |
| --------- | ----------------------------------------- |
| Başarı    | Ayırdığı bellek bloğunun adresi (void \*) |
| Hata      | `NULL` döner, bellek ayırılamadı          |

🧪 **Örnek:**
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *dizi = (int *)malloc(5 * sizeof(int));
    if (dizi == NULL) {
        perror("Bellek ayırma başarısız");
        return 1;
    }

    for (int i = 0; i < 5; i++) {
        dizi[i] = i * 10;
        printf("%d ", dizi[i]);
    }
    printf("\n");

    free(dizi);
    return 0;
}
```

🛑 **Dikkat Et:**

- malloc() ile ayırılan bellek otomatik olarak sıfırlanmaz, içeriği rastgele olabilir.

- Ayırdıktan sonra kullanmadan önce bellek içeriğini sıfırlamak için memset() veya calloc() kullanılabilir.

- Kullanımı bitince mutlaka free() ile serbest bırakılmalıdır.

- malloc() NULL döndüğünde bellek yetersizdir, bu durum kontrol edilmeli.

💡 **minishell'de Kullanımı:**

- Komut satırından alınan girdiler, argüman dizileri, token listeleri gibi dinamik büyüklükteki verileri tutmak için.

- Çalışma sırasında değişken boyutta veri depolamak gerektiğinde.


---

**Geri:** [SUBJECT](../../README.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **malloc()**