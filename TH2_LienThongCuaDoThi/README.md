# **Các bài tập ứng dụng về tính liên thông của đồ thị**
## 1. **Come and Go (nguồn: UVA Online Judge, Problem 11838)**
 Trong một thành phố có N địa điểm được nối với nhau bằng M con đường 1 chiều và 2 chiều. Yêu cầu tối thiểu của một thành phố là từ địa điểm này bạn phải có thể đi đến một địa điểm khác bất kỳ.

 Hãy viết chương trình kiểm tra xem các con đường của thành phố có thoả mãn yêu cầu tối thiểu này không.

 Dữ liệu đầu vào có dạng như sau:
```
4 5
1 2 1
1 3 2
2 4 1
3 4 1
4 1 2
```
Trong ví dụ này, có 4 địa điểm và 5 con đường, mỗi con đường có dạng a b p,  trong đó a, b là các địa điểm; và nếu p = 1, con đường đang xét là đường 1 chiều, ngược lại nó là đường 2 chiều.

**Đầu vào (Input)**

Dữ liệu đầu vào được nhập từ bàn phím (stdin) với định dạng:

* Dòng đầu tiên chứa 2 số nguyên N và M, tương ứng là số địa điểm và số con đường.
* M dòng tiếp theo mỗi dòng chứa 3 số nguyên a, b, p. Nếu p = 1, con đường (a, b) là con đường 1 chiều, ngược lại nếu p = 2, con đường (a, b) là con đường 2 chiều.

**Đầu ra (Output)**

* In ra màn hình OKIE nếu các con đường của thành phố có thoả mãn yêu cầu, ngược lại in ra NO.
* Xem thêm ví dụ bên dưới.

**For example:**

```
Input     Result
5 7       OKIE
1 2 1
2 3 1
3 1 1
2 4 1
3 4 1
4 5 1
5 3 1
```
```
Input     Result
8 10      NO
1 2 2
1 3 1
2 8 1
3 4 1
3 5 2
4 2 1
4 7 1
4 8 1
5 7 1 
6 7 2
```
```
Input     Result
3 2       OKIE
1 2 2
1 3 2
```

### **Giải quyết bài toán**

* [Come_and_Go](TH2/Come_and_Go.c)
-----
## 2. **Phân chia đội bóng**

David là huấn luyện viên của một đội bóng gồm N thành viên. David muốn chia đội bóng thành hai nhóm. Để tăng tính đa dạng của các thành viên trong nhóm, David quyết định không xếp hai thành viên đã từng thi đấu với nhau vào chung một nhóm. Bạn hãy lập trình giúp David phân chia đội bóng.

**Đầu vào (Input)**

Dữ liệu đầu vào được nhập từ bàn phím với định dạng:

* Dòng đầu tiên chứa 2 số nguyên N và M, tương ứng là số thành viên và số cặp thành viên đã từng thi đấu với nhau.
* M dòng tiếp theo mỗi dòng chứa 2 số nguyên u v nói rằng 2 thành viên u và v đã từng thi đấu chung với nhau.

**Đầu ra (Output):**

* Nếu phân chia được, hãy in ra các thành viên của mỗi nhóm. Nhóm của thành viên 1 sẽ được in trước, nhóm còn lại in ra sau. Các thành viên trong nhóm được in ra theo thứ tự tăng dần và in trên 1 dòng. Hai thành viên cách nhau 1 khoảng trắng.
* Nếu không thể phân chia, in ra IMPOSSIBLE

Xem thêm các ví dụ bên dưới.

**For example:**

```
Input     Result
3 2       1 3
1 2       2
2 3
```
```
Input     Result
3 3       IMPOSSIBLE
1 2
2 3
3 1
```
```
Input     Result
9 8       1
1 2       2 3 4 5 6 7 8 9
1 3
1 4
1 5
1 6
1 7
1 8
1 9
```

### **Giải quyết bài toán**

* [PhanChiaDoiBong](TH2/PhanChiaDoiBong.c)
-----
## 3. **Qua Đảo (ứng dụng kiểm tra đồ thị liên thông)**
 Có n hòn đảo và m cây cầu. Mỗi cây cầu bắt qua 2 hòn đảo. Một hôm chúa đảo tự hỏi là với các cây cầu hiện tại thì đứng ở một hòn đảo bất kỳ có thể nào đi đến được tất cả các hòn đảo khác mà không cần dùng đến thuyền hay không.

Hãy giúp chúa đảo viết chương trình kiểm tra.


**Đầu vào (Input)**

Dữ liệu đầu vào được nhập từ bàn phím với định dạng:

* Dòng đầu tiên chứa 2 số nguyên n và m, tương ứng là số đảo và số cây cầu.
* m dòng tiếp theo mỗi dòng chứa 2 số nguyên u v nói rằng có 1 cây cầu bắt qua hai hòn đảo u và v.

**Đầu ra (Output)**

* Nếu có thể đi được in ra màn hình YES, ngược lại in ra NO

**For example:**

```
Input     Result
4 3       YES
1 2
2 3
3 4
```
```
Input     Result
4 2       NO
3 4
1 2
```

### **Giải quyết bài toán**

* [QuaDao](TH2/QuaDao.c)
-----
## 4. **Trust Group (nguồn: UVA Online Judge, Problem 11709)**
 Phòng nhân sự của tổ chức Association of Cookie Monsters (ACM) nhận thấy rằng gần đây hiệu quả làm việc của các nhân viên có chiều hướng giảm sút. Vì thế họ đã lấy ý kiến các nhân viên và phát hiện ra nguyên nhân của vấn đề này, đó là: sự tin cậy. Một số nhân viên không tin cậy vào các nhân viên khác trong nhóm làm việc của mình. Điều này làm giảm động lực và niềm vui trong công việc của các nhân viên.

Phòng nhân sự muốn giải quyết triệt để vấn đề này nên họ quyết định tổ chức lại các nhóm làm việc sao cho ổn định. Một nhóm làm việc sẽ ổn định khi mà những người trong nhóm tin cậy lẫn nhau. Họ đã hỏi các nhân viên và biết được những người mà một nhân viên tin cậy trực tiếp. Ngoài ra, sự tin cậy có tính bắt cầu: nếu A tin cậy B và B tin cậy C thì A cũng sẽ tin cậy C. Lẽ dĩ nhiên, một nhân viên sẽ tự tin cậy chính bản thân mình. Tuy nhiên, cần chú ý là sự tin cậy lại không có tính đối xứng: A tin cậy B thì không nhất thiết B phải tin cậy A.

Phòng nhân sự muốn tổ chức thành ít nhóm nhất có thể. Hãy lập trình để giúp họ.

Giả sử các nhân viên được đánh số là 1, 2, ..., n.

**Đầu vào (Input)**

Dữ liệu đầu vào được nhập từ bàn phím (stdin) với định dạng:

* Dữ liệu đầu vào được nhập từ bàn phím theo định dạng:

* Dòng đầu tiên chứa 2 số nguyên n và m, tương ứng là số nhân viên và số cặp tin cậy.
* m dòng tiếp theo, mỗi dòng chứa 2 số nguyên a b, nói rằng người a tin cậy vào người b.

**Đầu ra (Output)**

* In ra màn hình số lượng nhóm ít nhất mà những người trong nhóm đều tin cậy lẫn nhau
* Xem thêm trong phần ví dụ

**For example:**

```
Input     Result
5 7       1
1 2 
2 3 
3 1 
2 4 
3 4 
4 5 
5 3 
```
```
Input     Result
8 13      3
1 2
1 3
2 1
2 8
3 4
3 5
4 2
4 7
4 8
5 3
5 7
6 7
7 6
```

### **Giải quyết bài toán**

* [Trust_Groups](TH2/Trust_Groups.c)
-----
## 5. **Tham chiếu vòng trong Microsoft Excel**
 Microsoft Excel là chương trình xử lý bảng tính nằm trong bộ Microsoft Office của hãng phần mềm Microsoft. Excel được thiết kế để giúp ghi lại, trình bày các thông tin xử lý dưới dạng bảng, thực hiện tính toán và xây dựng các số liệu thống kê trực quan.

Bảng tính Excel được chia thành nhiều hàng và cột. Giao điểm của hàng và cột gọi là một ô. Trong một ô của Excel, ta có thể nhập một giá trị hoặc một công thức có sử dụng giá trị của 1 hay nhiều ô khác. Khi ô A1 sử dụng giá trị của ô B2 ta nói A1 tham chiếu đến B2 hay A1 phụ thuộc vào B2.

Một lỗi thường gặp trong Excel là tham chiếu vòng (a circular reference). Tham chiếu vòng là trường hợp một ô tham chiếu đến chính nó hoặc như ví dụ bên dưới: A9 tham chiếu đến C2, C2 tham chiếu đến E9 và E9 tham chiếu đến A9.

Vấn đề đặt ra là làm thế nào để phát hiện có tham chiếu vòng trong bảng tính. Giả sử bảng tính có n ô, để đơn giản, ta đánh số các ô đang xét là 1, 2, 3, ..., n. Bạn biết được ô nào tham chiếu đến (các) ô nào. Hãy viết chương trình kiểm tra xem có xuất hiện tham chiếu vòng hay không.

**Đầu vào (Input)**

Dữ liệu đầu vào được nhập từ bàn phím (stdin) với định dạng:

* Dòng đầu tiên chứa 2 số nguyên n và m, tương ứng là số ô và số tham chiếu.
* m dòng tiếp theo mỗi dòng chứa 2 số nguyên u, v nói rằng ô u tham chiếu đến ô v.

**Đầu ra (Output)**

* In ra màn hình CIRCULAR REFERENCE nếu bảng tính có tham chiếu vòng, ngược lại in ra OK.

**For example:**

```
Input     Result
3 3       CIRCULAR REFERENCE
1 3
2 1
3 2
```
```
Input     Result
7 9       OK
1 2
1 3
1 4
2 3
2 6
3 5
3 7
4 5
5 7
```

### **Giải quyết bài toán**

* [ThamChieuVong_Excel](TH2/ThamChieuVong_Excel.c)
-----
## 6. **Thuyền trưởng Haddock (truyện Tintin)**
 Thuyền trưởng Haddock (truyện Tintin) là một người luôn say xỉn. Vì thế đôi khi Tintin không biết ông ta đang say hay tỉnh. Một ngày nọ, Tintin hỏi ông ta về cách uống. Haddock nói như thế này: Có nhiều loại thức uống (soda, wine, water, …), tuy nhiên Haddock lại tuân theo quy tắc “để uống một loại thức uống nào đó cần phải uống tất cả các loại thức uống tiên quyết của nó”. Ví dụ: để uống rượu (wine), Haddock cần phải uống soda và nước (water) trước. Vì thế muốn say cũng không phải dễ!

Cho danh sách các thức uống và các thức uống tiên quyết của nó. Hãy xét xem Haddock có thể nào say không ? Để làm cho Haddock say, ông ta phải uống hết tất cả các thức uống.

_Ví dụ 1:_

```
soda wine
water wine
```
Thức uống tiên quyết được cho dưới dạng a b, có nghĩa là để uống b bạn phải uống a trước. Trong ví dụ trên để uống wine, Haddock phải uống soda và water trước. Soda và water không có thức uống tiên quyết nên Haddock sẽ SAY.

_Ví dụ 2:_

```
soda wine
water wine
wine water
```
Để uống wine, cần uống water. Tuy nhiên để uống water lại cần wine. Vì thế Haddock không thể uống hết được các thức uống nên ông ta KHÔNG SAY.

Để đơn giản ta có thể giả sử các thức uống được mã hoá thành các số nguyên từ 1, 2, … và dữ liệu đầu vào được cho có dạng như sau (ví dụ 1):

```
3 2
1 2
3 2
```
Có loại thức uống (soda: 1, wine: 2 và water: 3) và có 2 điều kiện tiên quyết

>1 -> 2 và 3 -> 2.

Với ví dụ 2, ta có dữ liệu:

```
3 3
1 2
3 2
2 3
```
Viết chương trình đọc dữ liệu các thức uống và kiểm tra xem Haddock có thể say không. Nếu có in ra “YES”, ngược lại in ra “NO”.

**Đầu vào (Input)**

Dữ liệu đầu vào được nhập từ bàn phím (stdin) với định dạng:

* Dòng đầu tiên chứa 2 số nguyên n và m, tương ứng là số thức uống và số điều kiện tiên quyết
* m dòng tiếp theo mỗi dòng chứa 2 số nguyên u v nói rằng thức uống u là tiên quyết của thức uống v

**Đầu ra (Output)**

* Nếu Haddock có thể say in ra YES, ngược lại in ra NO.

**For example:**

```
Input     Result
3 3       NO
1 2
3 2
2 3
```
```
Input     Result
3 2       YES
1 2
3 2
```

### **Giải quyết bài toán**
Bài toán được giải quyết tương tự bài kiểm tra đồ thị có chu trình
* [KiemTra_ChuTrinh](TH2/KiemTra_ChuTrinh.c)
-----
