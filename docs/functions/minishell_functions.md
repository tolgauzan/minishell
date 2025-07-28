
>>>>> ---
**Geri:** [SUBJECT](../../README.md) / **Minishell Fonksiyonları**

### 📦 Minishell'de İzin Verilen Harici Fonksiyonlar

 Fonksiyonlar, Minishell projesinde kullanıldıkları amaca göre aşağıdaki şekilde gruplanmıştır:


### 1. Okuma/Yazma & Bellek Yönetimi Fonksiyonları

- [`readline`](readline.md): Kullanıcıdan satır satır giriş almak için (interaktif input).  
 
- [`rl_clear_history`](rl_clear_history.md), [`rl_on_new_line`](rl_on_new_line.md), [`rl_replace_line`](rl_replace_line.md), [`rl_redisplay`](rl_redisplay.md), [`add_history`](add_history.md): 
readline kütüphanesine ait, komut geçmişini yönetmek ve satırı düzenlemek için.  

- [`printf`](printf.md): Formatlı çıktı yazdırmak için.  
 
- [`malloc`](malloc.md), [`free`](free.md): Dinamik bellek tahsisi ve serbest bırakma.  

- [`write`](write.md): Dosyaya veya terminale ham veri yazmak için.  

- [`read`](read.md): Dosyadan veya terminalden ham veri okumak için.  


### 2. Dosya ve Dosya Tanımlayıcılarıyla İlgili Fonksiyonlar
- [`open`](open.md): Dosya açmak (okuma, yazma, oluşturma).  

- [`close`](close.md): Dosya tanımlayıcısını kapatmak.  

- [`access`](access.md): Dosyanın erişim izinlerini kontrol etmek.  

- [`stat`](stat.md), [`lstat`](lstat.md), [`fstat`](fstat.md): Dosya/dizin hakkında bilgi almak (boyut, tür, izinler vb.).  

- [`unlink`](unlink.md): Dosya silmek.  
  
- [`dup`](dup.md), [`dup2`](dup2.md): Dosya tanımlayıcılarını kopyalamak (örneğin yönlendirme için).  
 
- [`pipe`](pipe.md): İki süreç arasında veri aktarımı için boru hattı oluşturmak.  
  


### 3. Süreç Yönetimi Fonksiyonları
- [`fork`](fork.md): Yeni bir çocuk süreç oluşturmak.  
 
- [`wait`](wait.md), [`waitpid`](waitpid.md), [`wait3`](wait3.md), [`wait4`](wait4.md): Çocuk süreçlerin bitmesini beklemek, süreç durumu almak.  
 
- [`execve`](execve.md): Yeni bir program yürütmek (var olan sürecin üzerine).  
 
### 4. Sinyal Yönetimi Fonksiyonları
- [`signal`](signal.md): Sinyal yakalama (eski yöntem).  
 
- [`sigaction`](sigaction.md): Sinyal yakalama ve davranışını detaylı kontrol etmek.  
  
- [`sigemptyset`](sigemptyset.md), [`sigaddset`](sigaddset.md): Sinyal setlerini yönetmek.  

- [`kill`](kill.md): Sinyal göndermek (örneğin, bir süreci sonlandırmak).  
 

### 5. Çalışma Dizini ve Dosya Sistemi İşlemleri
- [`getcwd`](getcwd.md): Şu anki çalışma dizinini almak.  
 
- [`chdir`](chdir.md): Çalışma dizinini değiştirmek.  
 

### 6. Dizin İşlemleri
- [`opendir`](opendir.md): Bir dizini açmak.  
 
- [`readdir`](readdir.md): Dizin içeriğini okumak.  
 
- [`closedir`](closedir.md): Açık dizin işaretçisini kapatmak.  
  

### 7. Hata Yönetimi ve Terminal Özellikleri
- [`strerror`](strerror.md): Hata koduna karşılık gelen mesajı almak.  

- [`perror`](perror.md): Hata mesajını standart hataya yazdırmak.  

- [`isatty`](isatty.md): Dosya tanımlayıcısının terminal olup olmadığını kontrol etmek.  

- [`ttyname`](ttyname.md): Terminal cihazının adını almak.  

- [`ttyslot`](ttyslot.md): Terminal slot numarasını almak.  

- [`ioctl`](ioctl.md): Terminal ve cihaz ayarlarını kontrol etmek (çok genel, çeşitli amaçlarla kullanılır).  


### 8. Ortam Değişkenleri ve Terminal Kontrolleri
- [`getenv`](getenv.md): Ortam değişkenlerinin değerini almak.  

- [`tcsetattr`](tcsetattr.md), [`tcgetattr`](tcgetattr.md): Terminalin özelliklerini almak ve ayarlamak (örneğin, kanonik mod, ekolama).  

- [`tgetent`](tgetent.md), [`tgetflag`](tgetflag.md), [`tgetnum`](tgetnum.md), [`tgetstr`](tgetstr.md), [`tgoto`](tgoto.md), [`tputs`](tputs.md): Termcap kütüphanesi fonksiyonları — terminal özelliklerini sorgulamak ve terminal üzerinde hareket veya renk gibi işlemleri yapmak için.  

**Geri:** [SUBJECT](/subject/subject.md#) / **Minishell Fonksiyonları**
>>>>> ---