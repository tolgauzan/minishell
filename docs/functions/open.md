
**Geri:** [SUBJECT](../../README.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **open()**

--- 

# open() - [manual](https://man7.org/linux/man-pages/man2/open.2.html)

📌 **Prototip:** `int open(const char *pathname, int flags, ...);`

📘 **Açıklama:**

- open() fonksiyonu, bir dosyayı açar veya oluşturur ve dosyaya erişim için bir dosya tanımlayıcısı (file descriptor) döner. Shell’de özellikle input/output yönlendirmelerinde (redirection) kullanılır.


📤 **Parametre:**
| **Parametre** | **Tür**        | **Açıklama**                                      |
|---------------|----------------|--------------------------------------------------|
| `pathname`    | `const char *` | Açılacak dosyanın yolu                           |
| `flags`       | `int`          | Dosya açma seçenekleri (örn. `O_RDONLY`, `O_CREAT`) |
| `mode`        | `mode_t`       | Dosya oluşturulacaksa erişim izinleri (opsiyonel)(örn: 0644)|

⚙️ **flags Seçenekleri**
- O_RDONLY : Sadece okuma

- O_WRONLY : Sadece yazma

- O_RDWR : Okuma ve yazma

- O_CREAT : Dosya yoksa oluştur

- O_APPEND : Yazma ekleme modunda (dosya sonuna)

- O_TRUNC : Dosya varsa içeriğini sıfırla

- O_EXCL : O_CREAT ile birlikte kullanılırsa, dosya zaten varsa hata verir

📤 **Dönüş Değeri:**

| **Durum** | **Açıklama**                                             |
|-----------|----------------------------------------------------------|
| Başarı    | Dosya tanımlayıcısı (0'dan büyük int) döner              |
| Hata      | -1 döner ve errno ayarlanır                              |

 🧪 **Örnek:**
```c
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int fd = open("test.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("Dosya açılamadı");
        return 1;
    }

    const char *metin = "Merhaba, Minishell!\n";
    write(fd, metin, 18);

    close(fd);
    return 0;
}
```
🛑 **Dikkat Et:**
- open() çağrısı başarılı olursa mutlaka close() ile kapatılmalıdır.
- flags parametresi dosyanın açılma şeklini belirler, yanlış ayarlanırsa beklenmedik sonuçlar olabilir.
- Dosya izinleri mode parametresi, sadece dosya oluşturulurken geçerlidir.

💡 **minishell'de Kullanımı:**
- Input/output redirection işlemlerinde (örneğin < input.txt, > output.txt, >> append.txt) dosyaları açmak için.
- Dosya descriptor’ları manipüle ederek standart giriş/çıkış yönlendirmesi yapılır.

---

**Geri:** [SUBJECT](../../README.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **open()**