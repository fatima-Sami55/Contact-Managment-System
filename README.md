# Contacts Book Application 📖

An advanced, feature-rich **Contacts Book Application** built in **C++** for managing personal and professional contacts. This project demonstrates object-oriented programming concepts such as **inheritance**, **polymorphism**, **operator overloading**, **templates**, and **file handling**. The application operates through a **console-based interface** and incorporates advanced features like group management, search history, and persistent storage.

---

## Features ✨

### Core Functionality
1. **Create Contacts List**: Initialize a contacts book of a specified size.
2. **Add New Contact**: Add new contacts with details such as name, phone, email, and address.
3. **Merge Duplicates**: Automatically detect and merge duplicate contacts.
4. **Store to File**: Save all contact data to a specified file for persistence.
5. **Load from File**: Load previously saved contacts from a file.
6. **Print Contacts**: Print all contacts, sorted or unsorted by attributes like `First Name` or `Last Name`.
7. **Search Contacts**: Search through contacts using advanced multi-attribute search.
8. **Count Contacts**: Display the total number of contacts.

### Advanced Features
- **Search History**:
  - Stores all search queries with date and time.
  - Displays recent searches sorted by time (most recent first).
  - Keeps track of frequently searched contacts.
  
- **Group Management**:
  - Create and manage groups of contacts.
  - Add or remove contacts from groups.
  - View all groups a contact belongs to.
  - Delete groups while maintaining contact integrity.

- **Resizable Arrays**:
  - Implements reusable template-based resizable arrays for efficient data storage.

- **Persistent Storage**:
  - Saves and loads all application data, including contacts, groups, and search history, across sessions.

### Bonus Features (Optional GUI Integration)
- **Graphical User Interface (GUI)** using **Windows Forms**.
- Cloud-based contact synchronization using **Google Firebase**.

---

## Technologies Used 🛠️
- **Programming Language**: C++
- **Object-Oriented Concepts**: Inheritance, Polymorphism, Operator Overloading, Templates
- **Data Persistence**: File Handling
- **Optional**: Windows Forms for GUI, Google Firebase for cloud synchronization

---

## Code Structure 🗂️
The project follows a **three-file structure** with separate files for classes and their implementations:

1. **Header Files**:
   - `Address.h`: Defines the `Address` class.
   - `Contact.h`: Defines the `Contact` class.
   - `ContactsBook.h`: Defines the `ContactsBook` class for managing contacts.

2. **Implementation Files**:
   - `Address.cpp`
   - `Contact.cpp`
   - `ContactsBook.cpp`

3. **Main File**:
   - `main.cpp`: Contains the driver code and the menu-driven interface.

---

## Installation and Setup 🚀

1. **Clone the Repository**:
```bash
   git clone https://github.com/your-username/contacts-book.git
```
```bash
   cd contacts-book
```
2. Compile the Code: Ensure you have a C++ compiler installed (e.g., g++).

```bash
   g++ -o ContactsBook main.cpp Address.cpp Contact.cpp ContactsBook.cpp
```
3. Run the Program
```bash
 ./ContactsBook
```

## Usage 🖥️
Follow the on-screen menu to interact with the Contacts Book Application. Example scenarios include:

- Adding new contacts
- Viewing and updating contact details
- Grouping contacts
- Searching and printing contacts
- Saving and loading data

## Acknowledgments 🙌
Special thanks to **Lecturer Mr. Muhammad Yousaf** and **Instructor Ms. Maham Saleem** for providing the starter code and guidance throughout this project.

