**Geri:** [SUBJECT](../../README.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **dup2()**

---

# exit() - [manual](https://man7.org/linux/man-pages/man3/exit.3.html)

📌 **Prototip:** `void exit(int status);`

📘 **Açıklama:**

- exit() fonksiyonu programın çalışmasını sonlandırır ve işletim sistemine bir çıkış durumu (status) bildirir.

- Programdan çıkarken belleği serbest bırakır, açık dosyaları kapatır ve atexit() ile kayıtlı fonksiyonları çağırır.

- status parametresi genellikle 0 başarılı çıkış, 0 dışı değerler hata anlamına gelir.

📤 **Parametre:**
| **Parametre** | **Tür** | **Açıklama**                                   |
| ------------- | ------- | ---------------------------------------------- |
| `status`      | `int`   | Çıkış durumu kodu (0 başarılı, diğerleri hata) |


📤 **Dönüş Değeri:**

exit() fonksiyonu geri dönmez, program çalışması burada sonlanır.

🧪 **Örnek:**
```c
#include <stdlib.h>
#include <stdio.h>

int main() {
    printf("Program sonlandırılıyor...\n");
    exit(0);  // Başarılı çıkış
    // Bu satır çalışmaz
    printf("Bu satır yazılmaz.\n");
    return 0;
}
```

🛑 **Dikkat Et:**

- exit() çağrıldıktan sonra programın kalan kodları çalışmaz.

- Programdan çıkmadan önce kaynakların temizlenmesi için uygun adımlar atılmalıdır (örneğin, free() çağrıları).

- return ile program sonlandırmak çoğu durumda yeterli olur, ancak exit() programın her yerinden çıkmak için kullanışlıdır.

💡 **minishell'de Kullanımı:**

- Kullanıcı exit komutu verdiğinde veya kritik hata durumlarında shell’i sonlandırmak için kullanılır.

- Çıkış durum kodunu doğru ayarlamak, shell’den çıkış sonrası sistem komutlarına bilgi verir.

---

**Geri:** [SUBJECT](../../README.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **dup2()**
