import datetime

class Student:
    def __init__(self):
        self.PRN = None
        self.dob = datetime.date

# Theory: This class represents a student with attributes for PRN and date of birth.

class SEComputer:
    def __init__(self):
        self.n1 = 0  # Number of students in SE-A
        self.n2 = 0  # Number of students in SE-B
        self.n3 = 0  # Number of students in SE Computer
        self.SEAList = []  # List for SE-A division students
        self.SEBList = []  # List for SE-B division students
        self.SECOMPList = []  # Combined sorted list for SE Computer

# Theory: This class handles operations related to SE Computer students, such as reading, sorting, and merging student information.

    def readStudentdataSEA(self):
        self.n1 = int(input("Enter the number of students for SE-A:"))
        for i in range(self.n1):
            s = Student()
            print("Enter information for student-", i + 1)
            s.PRN = input("Enter your PRN::")
            day = int(input("Enter day of the birth::"))
            month = int(input("Enter month of the birth::"))
            year = int(input("Enter year of the birth, 4-digits::"))
            s.dob = datetime.date(year, month, day)
            self.SEAList.append(s)

# Theory: Reads and stores the PRN and date of birth details for students in SE-A division.

    def readStudentdataSEB(self):
        self.n2 = int(input("Enter the number of students for SE-B:"))
        for i in range(self.n2):
            s = Student()
            print("Enter information for student-", i + 1)
            s.PRN = input("Enter your PRN::")
            day = int(input("Enter day of the birth::"))
            month = int(input("Enter month of the birth::"))
            year = int(input("Enter year of the birth, 4-digits::"))
            s.dob = datetime.date(year, month, day)
            self.SEBList.append(s)

# Theory: Reads and stores the PRN and date of birth details for students in SE-B division.

    def displayStudentListSEA(self):
        for i in range(self.n1):
            print("\n\t", self.SEAList[i].PRN, "  ", str(self.SEAList[i].dob))

# Theory: Displays the list of students and their birth details for SE-A division.

    def displayStudentListSEB(self):
        for i in range(self.n2):
            print("\n\t", self.SEBList[i].PRN, "  ", str(self.SEBList[i].dob))

# Theory: Displays the list of students and their birth details for SE-B division.

    def displayStudentListSECOMP(self):
        for i in range(self.n3):
            print("\n\t", self.SECOMPList[i].PRN, "  ", str(self.SECOMPList[i].dob))

# Theory: Displays the combined and sorted list of SE Computer students.

    def sortStudentList(self, nos, List):
        for i in range(nos - 1):
            for j in range(0, nos - i - 1):
                if List[j].dob > List[j + 1].dob:
                    temp = List[j]
                    List[j] = List[j + 1]
                    List[j + 1] = temp

# Theory: Sorts a list of students based on their date of birth using the bubble sort algorithm.

    def mergeList(self):
        self.SECOMPList = []
        if self.n1 == 0 and self.n2 == 0:
            print("No students found in SE-A & SE-B")
        elif self.n1 == 0:
            self.SECOMPList.extend(self.SEBList)
        elif self.n2 == 0:
            self.SECOMPList.extend(self.SEAList)
        else:
            self.SECOMPList.extend(self.SEBList)
            self.SECOMPList.extend(self.SEAList)

# Theory: Merges the student lists of SE-A and SE-B into a combined list for SE Computer, handling empty lists as needed.

obj = SEComputer()
choice = 0
while choice != 5:
    print("\n***************SE COMPUTER STUDENT *******************")
    print("1. Read SE-A/SE-B Student Lists")
    print("2. Display SE-A/SE-B  Student Lists")
    print("3. Sort SE-A/SE-B Student Lists ")
    print("4. Merge SE-A/SE-B  Student Lists ")
    print("5. Exit Application")
    choice = int(input("Enter your choice:"))

    if choice == 1:
        print("Enter SE-A student information")
        obj.readStudentdataSEA()
        print("Enter SE-B student information")
        obj.readStudentdataSEB()
    elif choice == 2:
        print("List of SE-A")
        obj.displayStudentListSEA()
        print("List of SE-B")
        obj.displayStudentListSEB()
    elif choice == 3:
        print("1. Sort SE-A")
        print("2. Sort SE-B")
        choice1 = int(input("Enter your choice:"))
        if choice1 == 1:
            obj.sortStudentList(obj.n1, obj.SEAList)
        elif choice1 == 2:
            obj.sortStudentList(obj.n2, obj.SEBList)
    elif choice == 4:
        obj.mergeList()
        print("List of SE-COMPUTER")
        obj.displayStudentListSECOMP()
    elif choice == 5:
        print("Good Bye!!")
        break
    else:
        print("Wrong Choice!!!")

# Theory: The driver code provides a menu-driven interface to manage SE-A and SE-B student data, sort them, and merge them into a combined list.
