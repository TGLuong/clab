1. Tạo tạo FIFOserver để lắng nghe request (well-know adress/name)
5. Có bản tin tới, thực bóc tách dữ liệu.
- ./fifoclient101
- 8
- key_request 
- <data kèm theo>

6. Kiểm tra dữ liệu
- hợp lệ: Gửi lại một bản tin ack thông báo request thành công tới ./fifoclient101 
	key hợp lệ
	service hợp lệ
- không hợp lệ: Gửi lại một bản tin ack thông báo request không thành công tới ./fifoclient101 

>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Client

2. Tạo ra 1 FIFO để gửi nhận bản tin (FIFOclient).

template = ./fifoclient + PID
Client1 (101) ./fifoclient101
Client2 (102) ./fifoclient102

3. Đóng bản tin request để gửi tới Server
- Tên file fifo 
- Service đăng kí (là một số nguyên dương)
- Key: key_request

./fifoclient101 + 8 + key_request + <data kèm theo>

4. Gủi bản tin tới server thông qua well-know adress/name (FIFOserver)
7. Sau khi nhận ack
- Nếu request thành công: Thực hiện gửi nhận dữ liệu giữa client-server
- Nếu request không thành công: Thì báo lỗi, xóa file FIFO và kết thúc tiến trình.
