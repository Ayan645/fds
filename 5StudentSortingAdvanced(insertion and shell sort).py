class FEStudent:
    def __init__(self):
        self.N = 0
        self.studentList = []
        self.iSortList = []
        self.sSortList = []

# Theory: This class represents students in the first year. It stores the count and percentage marks of students, and prepares lists for insertion and shell sorting techniques.

    def initialize(self):
        self.N = 0
        self.studentList = []
        self.iSortList = []
        self.sSortList = []

# Theory: Initializes or resets the lists and student count for a fresh start.

    def getStudentPercentage(self, nos):
        self.N = nos
        for i in range(self.N):
            print("Enter percentage of student", i + 1)
            percent = float(input())
            self.studentList.append(percent)
            self.iSortList.append(percent)
            self.sSortList.append(percent)

# Theory: Collects the percentage scores of a specified number of students and populates all lists with the same data.

    def displayStudentList(self, List):
        print("\nThe percentage of FE students")
        for i in range(self.N):
            print(List[i], end=" ")

# Theory: Displays the list of students' percentage scores.

    def insertionSort(self):
        for i in range(1, len(self.iSortList)):
            print("\nThe nos. after", i, "pass")
            key = self.iSortList[i]
            j = i - 1

            while j >= 0 and key < self.iSortList[j]:
                self.iSortList[j + 1] = self.iSortList[j]
                j -= 1

            self.iSortList[j + 1] = key

            for k in range(self.N):
                print(self.iSortList[k], end=" ")

# Theory: Implements insertion sort to arrange percentages in ascending order. It iteratively builds the sorted portion of the list by inserting elements into their correct positions.

    def shellSort(self):
        d = self.N // 2
        p = 1
        while d > 0:
            print("\nThe nos. after", p, "pass")
            for i in range(d, self.N):
                temp = self.sSortList[i]
                j = i
                while j >= d and self.sSortList[j - d] > temp:
                    self.sSortList[j] = self.sSortList[j - d]
                    j -= d
                self.sSortList[j] = temp

            d //= 2
            p += 1
            for k in range(self.N):
                print(self.sSortList[k], end=" ")

# Theory: Uses shell sort to sort percentages. This algorithm is a generalization of insertion sort that first sorts elements far apart and gradually reduces the gap between elements to be compared.

    def topFiveScores(self):
        if len(self.iSortList) == 0:
            print("Student List Empty!!")
        elif len(self.iSortList) < 5:
            print("Top Scores::", self.iSortList[-1:-(len(self.iSortList) + 1):-1])
        elif len(self.iSortList) >= 5:
            print("Top Scores::", self.iSortList[-1:-6:-1])

# Theory: Displays the top five scores from the list of sorted percentages.

std = FEStudent()
choice = 0

while choice != 6:
    print("\n*************SORTING ALGORITHMS****************")
    print("1. Read Student Percentage Marks")
    print("2. Display Student Percentage Marks")
    print("3. Sort Students List using Insertion sort")
    print("4. Sort Students List using Shell sort")
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
        std.insertionSort()
        std.displayStudentList(std.iSortList)
    elif choice == 4:
        std.shellSort()
        std.displayStudentList(std.sSortList)
    elif choice == 5:
        std.insertionSort()
        std.topFiveScores()
    elif choice == 6:
        print("Good Bye")
        break
    else:
        print("Wrong Choice")

# Theory: The driver code provides a menu-driven interface to collect student percentages, apply insertion and shell sort, and display the top five scores.
