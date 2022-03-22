# dup
hàm dup được sử dụng để tạo ra một file descriptor mới được copy từ file descriptor được truyền vào `int new_fd = dup(file_descriptor)`, `new_fd` sẽ có giá trị nhỏ nhất có thể
# dup2
hoạt động giống hàm dup nhưng ta có thể chỉ định ra giá trị file descriptor bằng tham số truyền vào: `int new_fd = dump(file_desciptor, number)`
