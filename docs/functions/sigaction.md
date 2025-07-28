**Geri:** [SUBJECT](../../README.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **sigaction()**

---

# sigaction() - [manual](https://man7.org/linux/man-pages/man2/sigaction.2.html)

#include <signal.h>

📌 **Prototip:** `int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact);`

📘 **Açıklama:**

- sigaction() fonksiyonu, belirli bir sinyal için daha güvenli ve esnek sinyal işleyici ayarlamak amacıyla kullanılır.

- signal() fonksiyonuna göre daha detaylı kontrol sağlar (sinyal maskesi, flag’ler, vs).

- act parametresi ile yeni sinyal işleyici bilgisi verilir.

- oldact parametresi ile önceki işleyici bilgisi alınabilir (istersen NULL verilebilir).

📤 **Parametre:**
| **Parametre** | **Tür**                    | **Açıklama**                                               |
| ------------- | -------------------------- | ---------------------------------------------------------- |
| `signum`      | `int`                      | İşlem yapılacak sinyal numarası (örn. `SIGINT`, `SIGCHLD`) |
| `act`         | `const struct sigaction *` | Yeni sinyal eylemi tanımı (handler, mask, flags)           |
| `oldact`      | `struct sigaction *`       | Önceki sinyal eyleminin saklanacağı yapı (istersen `NULL`) |

📤 **Dönüş Değeri:**
| **Durum** | **Açıklama**                                         |
| --------- | ---------------------------------------------------- |
| Başarı    | `0` döner                                            |
| Hata      | `-1` döner ve `errno` uygun hata koduyla güncellenir |


```c
struct sigaction {
    void     (*sa_handler)(int);   // Sinyal işleyici fonksiyon (veya SIG_IGN, SIG_DFL)
    sigset_t sa_mask;              // İşleyici çalışırken engellenecek sinyaller
    int      sa_flags;             // İşleyici davranışını belirleyen flag'ler
    void     (*sa_sigaction)(int, siginfo_t *, void *); // Gelişmiş işleyici (sa_flags & SA_SIGINFO ise)
};
```

🧪 **Örnek:**
```c
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void handler(int sig) {
    printf("SIGINT yakalandı (sigaction)!\n");
}

int main() {
    struct sigaction sa;
    sa.sa_handler = handler;         // İşleyici fonksiyonu
    sigemptyset(&sa.sa_mask);        // İşleyici sırasında engellenen sinyal yok
    sa.sa_flags = 0;                 // Default davranış

    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("sigaction hatası");
        return 1;
    }

    printf("Ctrl+C bekleniyor (sigaction)...\n");
    while (1) {
        sleep(1);
    }
    return 0;
}
```

🛑 **Dikkat Et:**

- sigaction(), signal() fonksiyonuna göre sinyal yönetimini daha güvenli ve kararlı yapar.

- sa_mask ile işleyici çalışırken hangi sinyallerin engelleneceğini belirleyebilirsin.

- sa_flags ile gelişmiş ayarlar yapılabilir (örneğin SA_RESTART otomatik tekrar başlatma).

- Sinyal işleyici fonksiyonu içerisinde sadece async-signal-safe fonksiyonlar kullanılmalı.

💡 **minishell'de Kullanımı:**

- Ctrl+C ve Ctrl+\ gibi sinyallerin yakalanmasında sinyal yönetimini güvenli hale getirmek için.

- Komut iptali ve shellin kapanmasını kontrol etmek için tercih edilir.


---

**Geri:** [SUBJECT](../subject/subject.md) / [Minishell Harici Fonksiyonları](minishell_functions.md) / **sigaction()**