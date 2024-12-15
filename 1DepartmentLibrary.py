class Book:
    def __init__(self):
        self.name = None
        self.cost = 0

# Theory: This class represents the blueprint for a Book. Each book has attributes like name and cost.

class DepartmentLibrary:
    def __init__(self):
        self.N = 0
        self.bookList = []
        self.newBookList = []  # Books costing less than 500

    def initialization(self):
        self.N = 0
        self.bookList = []

    def getBookDetail(self, nob):
        for i in range(nob):
            book = Book()
            print("Enter book name and cost for book-", i + 1)
            name = input("Enter Name of book::")
            cost = int(input("Enter book cost::"))
            book.name = name
            book.cost = cost
            self.bookList.append(book)

        self.N = self.N + nob

# Theory: This method allows users to input details for a specified number of books, adding them to the library.

    def displayBookList(self):
        print("\n\tName    Cost")
        for i in range(self.N):
            print("\n\t", self.bookList[i].name, "  ", self.bookList[i].cost)

# Theory: Displays the list of books with their names and costs in the library.

    def sortBookList(self):
        for i in range(self.N - 1):
            for j in range(0, self.N - i - 1):
                if self.bookList[j].cost > self.bookList[j + 1].cost:
                    temp = self.bookList[j]
                    self.bookList[j] = self.bookList[j + 1]
                    self.bookList[j + 1] = temp

# Theory: Implements bubble sort to arrange the books in ascending order based on their cost.

    def deleteDuplicates(self):
        i = 0
        flag = True
        while flag:
            count = 0
            j = i + 1
            curLen = len(self.bookList)
            while j < curLen:
                if self.bookList[i].name == self.bookList[j].name:
                    count += 1
                    if count >= 1:
                        self.bookList.pop(j)
                        curLen = len(self.bookList)
                j += 1

            i += 1
            if i >= len(self.bookList):
                flag = False

        self.N = len(self.bookList)

# Theory: Removes duplicate book entries by comparing book names and updating the library's book list.

    def moreCost(self):
        nob = 0
        for i in range(len(self.bookList)):
            if self.bookList[i].cost > 500:
                nob += 1

        print("Number of books having cost greater than 500::", nob)

# Theory: Counts and displays the number of books that cost more than 500.

    def underCostList(self):
        for i in range(len(self.bookList)):
            if self.bookList[i].cost < 500:
                self.newBookList.append(self.bookList[i])

        for i in range(len(self.newBookList)):
            print("\n\t", self.newBookList[i].name, "  ", self.newBookList[i].cost)

# Theory: Creates and displays a new list containing books that cost less than 500.

lib = DepartmentLibrary()
choice = 0

while choice != 7:
    print("*************DEPARTMENT LIBRARY****************")
    print("1. Read Book Details")
    print("2. Display List Book")
    print("3. Display List of Books in ascending order of cost")
    print("4. Delete the duplicate entries")
    print("5. Number of books having cost more than 500")
    print("6. Copy books in a new list which has cost less than 500")
    print("7. Exit Application")
    choice = int(input("What operation::"))

    if choice == 1:
        n = int(input("Enter number of books to be stored::"))
        lib.getBookDetail(n)
    elif choice == 2:
        lib.displayBookList()
    elif choice == 3:
        lib.sortBookList()
    elif choice == 4:
        lib.deleteDuplicates()
    elif choice == 5:
        lib.moreCost()
    elif choice == 6:
        lib.underCostList()
    elif choice == 7:
        print("Good Bye")
        break
    else:
        print("Wrong Choice")

# Theory: The driver code provides a menu-driven interface to perform various library-related operations, such as displaying books, sorting, deleting duplicates, and filtering based on cost.
