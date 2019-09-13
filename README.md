# examcfpt
Em gửi thày đề bài và bài làm của Final Exam của em ạ !
C++ Final Exam

Thực hiện các yêu cầu sau trong một chương trình:
Tạo class Point có:
Các thuộc tính x, y dạng int cùng các hàm get, set tương ứng của x và y
Default Constructor không tham số
Constructor với 2 tham số đầu vào x, y
Copy constructor
Các operator:
+ với Point
+= với Point
- với Point
-= với Point
= với Point
== với Point
!= với Point
* với float
2. Tạo class Item có:
Constructor 1 tham số đầu vào Item* parentItem, trong đó parentItem có thể bằng nullptr
Hàm Item* getParentItem(): trả về parentItem
Hàm std::vector<Item*> getChildItems(): chứa danh sách các Item có parentItem là đối tượng hiện tại
Thuộc tính x, y, width, height dạng int cùng các hàm get, set tương ứng
Hàm getPosition: kiểu giá trị trả về là Point, không có tham số đầu vào
Hàm setPosition: có 1 tham số đầu vào kiểu là Point, kiểu giá trị trả về là void
3. Tạo class TextItem thừa hưởng từ Item và có:
Thêm thuộc tính text dạng char * cùng các hàm get, set tương ứng của text
Copy constructor
operator =
4. Trong hàm main, cho phép người dùng nhập một danh sách (std::vector) của các TextItem* bằng cách:
Hỏi người dùng có muốn thêm TextItem mới. Nếu người dùng nhập y hoặc Y là đồng ý, n hoặc N là không đồng ý. Lặp lại câu hỏi đến khi người dùng nhập đúng câu trả lời.
Nếu người dùng đồng ý, cho phép người dùng nhập lần lượt các giá trị x, y, text rồi tạo new TextItem (theo các giá trị đã nhập) đưa vào cuối danh sách.
Lặp lại từ bước hỏi người dùng để cho phép nhập thông tin TextItem mới.
Nếu người dùng không đồng ý:
Tạo một thread mới để ghi các TextItem đã tạo theo thứ tự vào file items.txt với định dạng như sau:
Mỗi TextItem ghi thành một dòng trong file
Mỗi dòng được ghi theo thứ tự giá trị của x, y, text và cách nhau bằng ký tự space (ví dụ x, y, text là 10, 15, “this is a text” thì ghi thành 10 15 this is a text)
Kết thúc chương trình
