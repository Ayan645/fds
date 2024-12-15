class FEStudent:
    def __init__(self):
        self.N = 0
        self.studentList = []
        self.bSortList = []
        self.sSortList = []

# Theory: This class represents students in the first year. It stores the count and percentage marks of students, and prepares lists for different sorting techniques.

    def initialize(self):
        self.N = 0
        self.studentList = []
        self.bSortList = []
        self.sSortList = []

# Theory: Initializes or resets the lists and student count for a fresh start.

    def getStudentPercentage(self, nos):
        self.N = nos
        for i in range(self.N):
            print("Enter percentage of student", i + 1)
            percent = float(input())
            self.studentList.append(percent)
            self.bSortList.append(percent)
            self.sSortList.append(percent)

# Theory: Collects the percentage scores of a specified number of students and populates all lists with the same data.

    def displayStudentList(self, List):
        print("\nThe percentage of FE students")
        for i in range(self.N):
            print(List[i], end=" ")

# Theory: Displays the list of students' percentage scores.

    def bubbleSort(self):
        for i in range(self.N - 1):
            print("\nThe nos. after", i + 1, "pass")
            for j in range(0, self.N - i - 1):
                if self.bSortList[j] > self.bSortList[j + 1]:
                    temp = self.bSortList[j]
                    self.bSortList[j] = self.bSortList[j + 1]
                    self.bSortList[j + 1] = temp

            for k in range(self.N):
                print(self.bSortList[k], end=" ")

# Theory: Uses bubble sort to arrange the percentages in ascending order. The largest element "bubbles up" to the correct position in each pass.

    def selectionSort(self):
        for i in range(self.N - 1):
            print("\nThe nos. after", i + 1, "pass")
            for j in range(i + 1, self.N):
                if self.sSortList[i] > self.sSortList[j]:
                    temp = self.sSortList[i]
                    self.sSortList[i] = self.sSortList[j]
                    self.sSortList[j] = temp
            for k in range(self.N):
                print(self.sSortList[k], end=" ")

# Theory: Implements selection sort, where the smallest element from the unsorted section is selected and swapped with the first element of the unsorted section in each pass.

std = FEStudent()
choice = 0

while choice != 6:
    print("\n*************SORTING ALGORITHMS****************")
    print("1. Read Student Percentage Marks")
    print("2. Display Student Percentage Marks")
    print("3. Sort Students List using Selection sort")
    print("4. Sort Students List using Bubble sort")
    print("5. Display top five scores")
    print("6. Exit Application")
    choice = int(input("What operation::"))

    if choice == 1:
        std.initialize()
        n = int(input("Enter number of Students in FE::"))
        std.getStudentPercentage(n)
    elif choice == 2:
        std.displayStudentList(std.studentList)
    elif choice == 3:
        std.selectionSort()
        std.displayStudentList(std.sSortList)
    elif choice == 4:
        std.bubbleSort()
        std.displayStudentList(std.bSortList)
    elif choice == 5:
        pass
    elif choice == 6:
        print("Good Bye")
        break
    else:
        print("Wrong Choice")

# Theory: The driver code provides a menu-driven interface to collect student percentages and apply sorting algorithms (bubble and selection sort), along with additional operations like displaying scores.
