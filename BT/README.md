# 1. File I/O
## BT1
Viết một chương trình mở một file bất kì và sử dụng cờ O_APPEND, 
sau đó thực hiện seek về đầu file rồi ghi một vài dữ  liệu vào file đó. 
Dữ liệu sẽ xuất hiện ở vị trí nào của file và tại sao lại như vậy?
## BT2
Sau mỗi lệnh write dưới đây, Cho biết nội dung sẽ được ghi vào file nào, nội dung là gì và giải thích tại sao? </br>
- `fd1 = open(file, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);` </br>
- `fd3 = open(file, O_RDWR);` </br>
- `write(fd1, "Hello,", 6);` </br>
- `write(fd2, "world", 6);` </br>
- `lseek(fd2, 0, SEEK_SET);` </br>
- `write(fd1, "HELLO,", 6);` </br>
- `write(fd3, "Gidday", 6);` </br>
## BT3
Viết một chương trình có só lượng command-line arguments là 3, Có dạng như sau: </br>
`$ ./example_program filename num-bytes [r/w] "Hello"` </br>
Trong đó: </br>
	1. example_grogram: Tên file thực thi </br>
	2. filename: Tên file</br>
	3. num-bytes: Số byte muốn read/write</br>
	4. [r/w]: r -> Thực hiện đọc từ  filename và in ra màn hình</br>
		        w -> Thực hiện ghi vào filename</br>
	5. "Hello": Nội dung bất kì muốn read/write vào filename</br>
# 2. Process
## BT1
Giả sử rằng một parent process đã thiết lập một handler cho SIGCHLD và cũng block tín hiệu này. 
Sau đó, một trong các child process của nó thoát ra và parent process sau đó thực hiện wait() để thu thập trạng thái của child process. 
Điều gì xảy ra khi parent process bỏ chặn SIGCHLD?  Viết một chương trình để xác minh câu trả lời.
## BT2
Điều gì xảy ra khi chúng ta sử dụng họ hàm execute (execl/exevp/exepv)? 
Giải thích và viết một chương trình để xác minh câu trả lời. Sau đó hãy cho biết bản chất khi lệnh system() hoạt động như thế nào.
## BT3
Trình bày cách sử dụng 2 hàm dup()/dup2(). Viết chương trình minh họa cho câu trả lời.
## BT4
Debug là một công việc quan trọng trong việc lập trình do đó hãy tìm hiểu về segmentation fault, 
core dumped và cho biết chúng là gì? Viết một chương trình tái hiện lại lỗi này. Sau khi tái hiện được lỗi, 
tìm hiểu về gdb và trình bày các bước fix cho lỗi này.
# 3. Thread
## BT1
Viết một chương trình để chứng minh rằng các thread khác nhau trong cùng một process có thể có các tập hợp signal đang chờ xử lý 
(set of pending signal) khác nhau,được trả về bằng sigpending(). Bạn có thể làm điều này bằng cách sử dụng pthread_kill() 
để gửi các tín hiệu khác nhau đến hai thread khác nhau đã bị block các tín hiệu này, và sau với mỗi thread gọi sigpending() 
hãy hiển thị thông tin về các tín hiệu đang chờ xử lý.
# 4. Signal
## BT1
Viết chương trình block tín hiệu SIGINT và sau đó in ra signal mask của process hiện tại.
## BT2
Realtime signal và standard signal là gì? Phân biệt sự khác nhau giữa chúng.
# 5. Pipe
## BT1
Viết một chương trình sử dụng hai pipe để cho phép giao tiếp hai chiều giữa hai tiến trình cha và con. 
Parent process lặp lại việc đọc dữ  liệu văn bản từ bàn phím và sử dụng một trong các pipe để gửi văn bản đến child process,
child process chuyển nó thành chữ hoa và gửi lại cho parent process qua pipe còn lại. Parent process đọc dữ liệu trả về từ 
child process và in ra màn hình trước khi lặp lại quá trình một lần nữa.
# 6. Shared memory
## BT1
Viết một chương trình sử dụng shared memory segment để gửi đi dữ liệu là các cặp tên-giá trị (name-value). 
Bạn sẽ cần cung cấp một vài API cho phép tạo tên mới, sửa đổi tên hiện có, xóa tên hiện có và truy xuất giá trị được liên kết với tên.
