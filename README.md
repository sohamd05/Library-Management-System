<h1 align=>LIBRARY MANAGEMENT SYSTEM </h1>
<h3 align=>This repository contains a Library Management System implemented in C, which provides functionalities for both administrators and students. The system utilizes 2D arrays, linked lists, and file handling to manage books, students, and their interactions within the library.</h3>


<h3 align="left">Features</h3>
<h3 align="left">Admin Features</h3>

![Screenshot from 2023-08-18 10-22-22](https://github.com/sohamd05/Library-Management-System/assets/118821338/e7a71c1c-dc7c-439d-a0cd-3941c507d9fd)


Add Book: Admins can add new books to the library database, including details such as title, author, ISBN, and availability.

Delete Book: Admins can remove books from the library database based on the book's ISBN.

View Books: Admins can view all books currently available in the library.

Add Student: Admins can register new students by collecting their details, such as name, ID, and contact information.

Delete Student: Admins can remove students from the system based on their student ID.

View Students: Admins can view all registered students in the library.

<h3 align="left">Student Features </h3>

![Screenshot from 2023-08-18 10-18-56](https://github.com/sohamd05/Library-Management-System/assets/118821338/92d663ad-7ee5-4b66-9e14-de552adf1b33)


Issue Book: Students can borrow books from the library by providing the book's ISBN. The system checks availability and assigns the book to the student.

Submit Book: Students can return books to the library, updating the availability status for the particular book.

View Books: Students can view all books available in the library.

Check Issued Books: Students can view the books they have borrowed from the library.

<h3 align="left">Data Management</h3>

2D Arrays: The system uses 2D arrays to store and manage book and student data efficiently.

Linked List: Linked lists are employed for dynamic data storage, providing flexibility for managing and modifying student and book records.

File Handling: The system utilizes file handling operations to read and write data to two CSV files: one for books and another for students. This ensures data persistence between sessions.

