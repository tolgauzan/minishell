>>>>> ---
>>>>> ---
># **Minishell** 

***"Bir kabuk kadar güzel"***

>>>>> ---

 **Proje:**
- *minishell*

 **Özet:**
- Bu proje basit bir kabuk (**shell**) oluşturmakla ilgilidir.
Evet, sizin kendi küçük Bash'iniz.
Prosesler ve dosya tanımlayıcıları (**file descriptors**) hakkında kapsamlı bilgi edineceksiniz.

 **Version:** 8.3

>>>>> ---
> ## **Giriş**

- Kabuklar, Bilişim Teknolojileri'nin (**BT**) en başından beri var olmuştur.O zamanlar, tüm geliştiriciler bir bilgisayarla hizalanmış **1/0** anahtarları aracılığıyla iletişim kurmanın son derece sinir bozucu olduğu konusunda hemfikirdi.
Bir bilgisayarla, insan diline oldukça yakın bir dilde etkileşimli komut satırları kullanarak iletişim kurmak için bir yazılım oluşturma fikrini bulmaları sadece mantıksal bir adımdı.
Minishell ile zamanda geriye yolculuk yapacak ve Windows var olmadan önce geliştiricilerin karşılaştığı zorlukları deneyimleyeceksiniz.

>>>>> ---
> ## **Zorunlu kısım**
 | | |
 | :--- | :--- |
 | **Program adı** | **`minishell`** |
 | **Teslim edilecek dosyalar** | **`Makefile`**, **`*.h`**, **`*.c`** |
 | **Makefile** | **`NAME`**, **`all`**, **`clean`**, **`fclean`**, **`re`** |
| **Argümanlar** | **Yok** |
| **Harici fonksiyonlar** | *`readline`, `rl_clear_history`, `rl_on_new_line`, `rl_replace_line`, `rl_redisplay`, `add_history`, `printf`, `malloc`, `free`, `write`, `access`, `open`, `read`, `close`, `fork`, `wait`, `waitpid`, `wait3`, `wait4`, `signal`, `sigaction`, `sigemptyset`, `sigaddset`, `kill`, `exit`, `getcwd`, `chdir`, `stat`, `lstat`, `fstat`, `unlink`, `execve`, `dup`, `dup2`, `pipe`, `opendir`, `readdir`, `closedir`, `strerror`, `perror`, `isatty`, `ttyname`, `ttyslot`, `ioctl`, `getenv`, `tcsetattr`, `tcgetattr`, `tgetent`, `tgetflag`, `tgetnum`, `tgetstr`, `tgoto`, `tputs`* |
| **Libft kullanım izni** | **Evet** |
| **Açıklama** | **Bir kabuk yazın** |

>>>>> ---
>## [👉**Minishell Harici Fonksiyonlar**🔗](docs/functions/minishell_functions.md)
>>>>> ---

***Kabuğunuz şunları yapmalıdır:***

 * Yeni bir komut beklerken bir istem **`(prompt)`** göstermelidir.
 * Çalışan bir geçmişe **`(history)`** sahip olmalıdır.
 * Doğru çalıştırılabilir dosyayı aramalı ve başlatmalıdır (**`PATH`** **değişkenine göre veya göreceli ya da mutlak bir yol kullanarak**).
 * Alınan bir sinyali belirtmek için ***en fazla bir adet*** **global değişken** kullanmalıdır.
 ***Bunun sonuçlarını göz önünde bulundurun:*** bu yaklaşım, sinyal işleyicinizin **`(signal handler)`** ana veri yapılarınıza erişmemesini sağlar. 
> **!** Dikkatli olun. Bu global değişken yalnızca sinyal numarasını saklamalı ve herhangi bir ek bilgi sağlamamalı veya verilere erişim sunmamalıdır.
 Bu nedenle, global kapsamda **`"norm"`** tipi yapılar kullanmak yasaktır. 
* Kapatılmamış tırnakları veya konu tarafından gerektirilmeyen **`\`** (**ters eğik çizgi**) veya **`;`** (**noktalı virgül**) gibi özel karakterleri yorumlamamalıdır. 
* **`'`** (**tek tırnak**) kullanımını işlemelidir; bu, kabuğun tırnak içindeki dizideki meta karakterleri yorumlamasını engellemelidir.
* **`"`** (**çift tırnak**) kullanımını *işlemelidir*; bu, kabuğun tırnak içindeki dizide **`$`** (**dolar işareti**) hariç meta karakterleri yorumlamasını *engellemelidir.*
* ***Aşağıdaki yönlendirmeleri (redirections) uygulamalıdır:***
    * **`<`** girdiyi yönlendirmelidir. 
    * **`>`** çıktıyı yönlendirmelidir. 
    * **`<<`** bir sınırlayıcı (**delimiter**) almalı, ardından sınırlayıcıyı içeren bir satır görülene kadar girdiyi okumalıdır.  Ancak, geçmişi (**history**) güncellemek zorunda değildir!
    * **`>>`** çıktıyı ekleme modunda (**append mode**) yönlendirmelidir.
* Pipe (**`|`** karakteri) uygulamalıdır.  Boru hattındaki (**pipeline**) her komutun çıktısı, bir pipe aracılığıyla bir sonraki komutun girdisine bağlanır. 
* Değerlerine genişlemesi gereken ortam değişkenlerini (**`$`** **ve ardından gelen karakter dizisi**) işlemelidir. 
* En son yürütülen ön plan boru hattının (foreground pipeline) çıkış durumuna (**exit status**) genişlemesi gereken **`$?`** ifadesini işlemelidir. 
* **`bash`**'teki gibi davranması gereken **`ctrl-C`**, **`ctrl-D`** ve **`ctrl-\`** tuş kombinasyonlarını işlemelidir. 
* ***Etkileşimli modda:***
    * **`ctrl-C`** yeni bir satırda yeni bir istem görüntüler. 
    * **`ctrl-D`** kabuktan çıkar. 
    * **`ctrl-\`** hiçbir şey yapmaz. 
* ***Kabuğunuz aşağıdaki gömülü (built-in) komutları uygulamalıdır:***
    * **`-n`** seçeneği ile **`echo`**
    * sadece göreceli veya mutlak bir yolla **`cd`**
    * seçeneksiz **`pwd`**
    * seçeneksiz **`export`**
    * seçeneksiz **`unset`**
    * seçeneksiz veya argümansız **`env`**
    * seçeneksiz **`exit`**


**`readline()`** fonksiyonu bellek sızıntılarına neden olabilir, ancak bunları düzeltmeniz gerekmemektedir. Ancak bu, kendi kodunuzun, evet sizin yazdığınız kodun, bellek sızıntılarına sahip olabileceği anlamına gelmez.

> **!** Kendinizi konu açıklamasıyla sınırlamalısınız. İstenmeyen hiçbir şey gerekli değildir. Bir gereksinim hakkında herhangi bir şüpheniz varsa, **`bash`**'i referans alın.

>>>>> ---
>## **Bonus kısım** 
***Programınız şunları uygulamalıdır:***

* Öncelikler için parantezlerle birlikte **`&&`** ve **`||`**.
* **`*`** joker karakterleri **(wildcards)**, mevcut çalışma dizini için çalışmalıdır.

>>---
>>>>> ---
#### Kurulum Gereksinimleri

Bu proje **Readline** kütüphanesini kullanmaktadır. Derleme hatası almamak için sisteminizde bu kütüphanenin kurulu olduğundan emin olun:

* **Debian/Ubuntu/WSL:**
    ```bash
    sudo apt update && sudo apt install libreadline-dev -y
    ```
* **macOS (Homebrew):**
    ```bash
    brew install readline
    ```

#### Kullanım

Gereksinimleri sağladıktan sonra projeyi klonlayıp çalıştırabilirsiniz:

```bash
git clone [https://github.com/tolgauzan/minishell.git](https://github.com/tolgauzan/minishell.git) && \
cd minishell && \
make && \
./minishell

#### Kullanım
```bash
git clone https://github.com/tolgauzan/minishell.git && \
cd minishell && \
make && \
./minishell
```

#### Makefile Komutları

```bash
make        # Projeyi derler
make clean  # Geçici dosyaları temizler
make fclean # Derlenmiş tüm dosyaları temizler
make re     # Temizleyip tekrar derler
```

#### Kabuktan Çıkmak

```bash
exit       # Çıkmak için yazabilirsiniz
CTRL+D     # Alternatif olarak bu tuş kombinasyonu ile de çıkabilirsiniz
```

📁 Proje GitHub Sayfası: [github.com/tolgauzan/minishell](https://github.com/tolgauzan/minishell)

🧑‍💻 Hazırlayanlar: Tolga Uzan & Ayşe Feyza Serbest

