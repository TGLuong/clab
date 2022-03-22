##segmentation fault, core dumped là lỗi xảy ra khi truy cập vào vùng nhớ không được cấp phép </br>
# GDB
Dể sử dụng `gdb`, chúng ta cần thêm cờ `-g` khi compile. ví dụ : `gcc -g -o main main.c` </br>
Sau đó chạy lệnh `gdb [tên chương trình]` </br>
Nếu chương trình có tham số đầu vào: `gdb --args [tên chương trình] args1 args2 args3` </br>
Một số thao tác cơ bản là:
- lệnh `l` để hiển thị ra 10 dòng theo thứ tự </br>
- lệnh `b [số dòng]` để đặt breakpoint
- lệnh `r` để chạy debug
