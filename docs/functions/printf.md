**Geri:** [SUBJECT](../../README.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **printf()**

---

# printf() - [manual](https://man7.org/linux/man-pages/man3/printf.3.html)


📌 **Prototip:** `int printf(const char *format, ...);`

📘 **Açıklama:**

- printf() fonksiyonu, standart çıktıya (genellikle terminal) formatlanmış metin yazmak için kullanılır.

- format parametresi, yazdırılacak metnin nasıl biçimlendirileceğini belirtir. İçinde metin ve biçim belirleyiciler (format specifiers) olabilir.

- Sonrasında değişken sayıda argüman (...) gelebilir, bunlar format belirleyiciler tarafından okunup işlenir.

- Oldukça esnek ve yaygın kullanılan bir çıktı fonksiyonudur.

📤 **Parametre:**
| **Parametre** | **Tür**        | **Açıklama**                                             |
| ------------- | -------------- | -------------------------------------------------------- |
| `format`      | `const char *` | Yazdırılacak metnin formatını belirten C dizisi (string) |
| `...`         | değişken       | Format belirleyicilere göre yazdırılacak argümanlar      |

📤 **Dönüş Değeri:**
| **Durum** | **Açıklama**                                 |
| --------- | -------------------------------------------- |
| Pozitif   | Başarıyla yazdırılan karakter sayısını döner |
| Negatif   | Yazdırma hatası olduysa negatif değer döner  |

🧪 **Örnek:**
```c
#include <stdio.h>

int main() {
    int num = 10;
    float pi = 3.14159;
    char *str = "Merhaba, Minishell!";

    printf("Sayi: %d\n", num);
    printf("Pi sayisi: %.2f\n", pi);
    printf("Mesaj: %s\n", str);

    return 0;
}
```

🛑 **Dikkat Et:**

- Format belirleyiciler (%d, %s, %f vb.) ile verilen argümanların türü doğru eşleşmelidir, aksi halde davranış tanımsız olur.

- Güvenlik açısından, dışarıdan alınan format string'ler doğrudan printf()'e verilmemeli, format string sabit veya kontrollü olmalıdır.

💡 **minishell'de Kullanımı:**

- Kullanıcıya bilgi, hata mesajı veya komut çıktısı göstermek için kullanılır.

- Debugging ve kullanıcı arayüzü metinlerini yazdırmakta sıkça gereklidir.



---

**Geri:** [SUBJECT](../../README.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **printf()**