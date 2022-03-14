
# Định nghĩa
## Realtime signal
Real time signal là những signal từ `SIGRTMIN` đến `SIGRTMAX` </br>
Danh sách Real time signal bao gồm: </br>
`SIGRTMIN` `SIGRTMIN+1` `SIGRTMIN+2` `SIGRTMIN+3` `SIGRTMIN+4` `SIGRTMIN+5` `SIGRTMIN+6` `SIGRTMIN+7` `SIGRTMIN+8` `SIGRTMIN+9` `SIGRTMIN+10` `SIGRTMIN+11` `SIGRTMIN+12` `SIGRTMIN+13` `SIGRTMIN+14` `SIGRTMIN+15` `SIGRTMAX-14` `SIGRTMAX-13` `SIGRTMAX-12` `SIGRTMAX-11` `SIGRTMAX-10` `SIGRTMAX-9` `SIGRTMAX-8` `SIGRTMAX-7` `SIGRTMAX-6` `SIGRTMAX-5` `SIGRTMAX-4` `SIGRTMAX-3` `SIGRTMAX-2` `SIGRTMAX-1` `SIGRTMAX` </br>
## Regular signal
Regular signal là những signal từ `SIGHUP` tới `SIGSYS`
Danh sách Regular signal bao gồm: </br>
`SIGHUP` `SIGINT` `SIGQUIT` `SIGILL` `SIGTRAP` `SIGABRT` `SIGBUS` `SIGFPE` `SIGKILL` `SIGUSR1` `SIGSEGV` `SIGUSR2` `SIGPIPE` `SIGALRM` `SIGTERM` `SIGSTKFLT` `SIGCHLD` `SIGCONT` `SIGSTOP` `SIGTSTP` `SIGTTIN` `SIGTTOU` `SIGURG` `SIGXCPU` `SIGXFSZ` `SIGVTALRM` `SIGPROF` `SIGWINCH` `SIGIO` `SIGPWR` `SIGSYS` </br>
# Mức độ ưu tiên của signal
Mức độ ưu tiên của các regular signal và realtime signal là không xác định, tuy nhiên trong tập các realtime signal, các signal có số thứ tự bé thì được ưu tiên xử lý trước so với các signal có số thứ tự cao
# Khả năng đính kèm data của realtime signal
Một điểm khác biệt giữa Realtime signal và Regular signal là Realtime signal có thể gán thêm dữ liệu vào signal


