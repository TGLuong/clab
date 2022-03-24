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
