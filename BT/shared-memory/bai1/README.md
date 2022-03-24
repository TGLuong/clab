# Hướng dẫn sử dụng

1. build mã nguồn: `make`
2. sử dụng 2 shell
3. shell 1 chạy server: `./server`
4. shell 2 chạy client: `./client`
## Cách sử dụng client
client được chạy có dạng: `./client [option] [server pid] [name] [value]` trong đó: </br>
- `option` thuộc một trong 4 dạng : `create` `edit` `delete` `show`
- `server pid` là process id của server
- `name` là giá trịvname truyền đến server theo cặp name-value
- `value` là giá trị value truyền đến server theo cặp name-value
### Ví dụ chạy client
- ví dụ create: `./client create 80720 name luong` lệnh này sẽ thêm cặp `name-luong` ở server
- ví dụ edit: `./client edit 80720 name haha` lệnh này sẽ sửa cặp `name-luong` thành `name-haha` ở server
- ví dụ delete: `./client delete 80720 name` lệnh này sẽ xoá cặp nào có name là `name` ở server
- ví dụ show: `./client show 80720 name` lệnh này sẽ lấy value ở server có name là `name`, trả về cho client, client sẽ hiện value này lên
