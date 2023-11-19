# **Quản lý các chuyến bay nội địa thuộc một hãng hàng không**
## Cấu trúc dữ liệu
Chương trình sẽ sử dụng các danh sách sau để quản lý thông tin về chuyến bay, máy bay và hành khách:

 **1. Danh sách máy bay:**
- Một mảng con trỏ có thể chứa tối đa 300 máy bay. Mỗi máy bay có các thông tin
(```Số hiệu MB (C15), loại máy bay (C40), số chỗ```), mỗi máy bay có 1 số hiệu duy nhất, số chỗ >=20.

**2. Danh sách chuyến bay:** Một danh sách liên kết đơn chứa thông tin về các chuyến bay. Mỗi chuyến bay bao gồm các thông tin sau:
- Chuyến bay : danh sách liên kết đơn (```Mã CB (C15), Ngày giờ khởi hành, sân bay đến, trạng thái, Số hiệu MB, danh sách vé```). Mỗi chuyến bay có 1 mã duy nhất; trạng thái chuyến
bay bao gồm: 0: hủy chuyến, 1: còn vé, 2: hết vé, 3: hoàn tất.
- Danh sách vé cho biết thông tin vé trên chuyến bay, và số CMND của hành khách đã đặt vé đó. Mỗi vé có số vé là số thứ tự trên chuyến từ số 1 đến số chỗ.

**3. Hành khách:** cây nhị phân tìm kiếm (```Số CMND, Ho, Ten, Phai```)

## Chức năng chương trình:
**1. Cập nhật danh sách máy bay:**
- Thêm - xóa - hiệu chỉnh.

**2. Cập nhật chuyến bay:**
- Cho phép lập chuyến bay mới, hiệu chỉnh ngày giờ khởi hành của
chuyến bay, hủy chuyến.

**3. Đặt vé:**

- Cho phép đặt vé trên 1 chuyến bay; nếu thông tin hành khách chưa có thì tự động
cập nhật vào danh sách hành khách, nếu có rồi thì in ra màn hình để kiểm tra
- Mỗi vé đều phải ghi nhận số CMND của hành khách; nếu hành khách chưa có số CMND thì yêu cầu nhập thông tin hành khách trước. Trên 1 chuyến bay, mỗi hành khách chỉ được mua 1 vé.

**4. Hủy vé:**
- Cho phép hủy vé đã đặt của hành khách.

**5. In danh sách các hành khách thuộc 1 chuyến bay dựa vào mã chuyến bay. Kết xuất:**
```
                        | DANH SÁCH HÀNH KHÁCH THUỘC CHUYẾN BAY ###### |
                | Ngày giờ khởi hành: dd/mm/yyyy hh:mm | Nơi đến: xxxxxxxxxxx |
                            | STT | SỐ VÉ | SỐ CMND | HỌ TÊN | PHÁI |
```
**6. In danh sách các chuyến bay khởi hành trong ngày "dd/mm/yyyy" đến nơi "XXXX" mà còn vé:**

- Hiển thị số lượng vé còn trống và giờ khởi hành của từng chuyến bay

**7. In danh sách các vé còn trống củamột chuyến bay có mã chuyến bay là "X":**


**8. Thống kê số lượt thực hiện chuyến bay của từng máy bay theo thứ tự số lượt thực hiện giảm dần. Kết xuất:**

```
            | Số hiệu máy bay | Số lượt thực hiện chuyến bay |
```
*Lưu ý: Chương trình cung cấp khả năng lưu các danh sách vào file và kiểm tra các điều kiện nhập liệu để đảm bảo tính chính xác của dữ liệu.*
______________________________________________________________________________
# plane-project
this is our stupid first project- plane management.
Done well by the master of code, the man-the myth-the legend programmer
  Behold:   ___Brjdyxter__

The UI was created and polished by the god of art, the guardian of color
Lord of the Visual effect.
 Behold: "The greatest contemporary art artist" :__INANITY_ without upcase.

ez 7đ, no bug. MR Thư smiled
