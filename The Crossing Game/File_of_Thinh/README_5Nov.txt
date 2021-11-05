Kết hợp với Khang - Thịnh: 70% (còn phần save và load là xong)

Tạm thời chạy khá ổn, nhưng phần CANIMAL phải xài thread sau này.
Nó cực kỳ phức tạp, ít ra có chú thích và code cũng có mạch lạc rồi.

Thứ tự nên tìm hiểu trước: Console -> Draw -> Menu -> CPeople -> CAnimal -> Bird -> CGame
Thứ tự code chạy: Main -> Menu -> CGame -> Cpeople + Bird

Thay đổi file của Khang:
1) Lược đi mấy hàm và tham số đưa vào không cần.
2) Thêm các hàm hỗ trợ (nó tương đối khác với cái đề xuất trong đồ án)
3) Thêm chú thích
4) Bỏ đi Template
5) Lượt thành một hàng chỉ có một con vật (cho dễ thao tác)
6) Chỉnh code (khá nhiều)

Lưu ý:
1) Sprite ban đầu là hình ảnh, nhưng để thao tác trên console thì nó được dùng là string.
2) Timer cũng được xài, nhưng không phải thời gian thực, mà là trừ từ từ theo hàm while() và Sleep()
3) Code này khá dài nhưng đảm bảo không lú nhất có thể. Yên tâm (khá bám sát cách code của những người làm game) =))
4) Cho dễ nhìn thì đưa từng cái nào chung chung vào filter trong visual studio, nó mang biểu tượng thư mục ấy. Tạo filter mới rồi đưa mấy file .h và .cpp vào (nhưng KHÔNG làm trên folder, vì filter và folder khác nhau hoàn toàn)
