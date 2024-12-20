class magicsquare:
    def num(self):
        n = int(input("Enter any odd number: "))
        if n % 2 == 0:
            while n != 0:
                n = input("Entered number was even, Please enter odd number: ")
                for no in n:
                    if int(no) % 2 != 0:
                        return int(no)
        else:
            return int(n)

# Theory: This method ensures the user inputs an odd number, as it is required to generate a magic square.

    def generateSquare(self, n):
        magicSquare = [[0 for x in range(n)] for y in range(n)]

        i = n // 2
        j = n - 1

        num = 1
        while num <= (n * n):
            if i == -1 and j == n:
                j = n - 2
                i = 0
            else:
                if j == n:
                    j = 0
                if i < 0:
                    i = n - 1

            if magicSquare[int(i)][int(j)]:
                j = j - 2
                i = i + 1
                continue
            else:
                magicSquare[int(i)][int(j)] = num
                num = num + 1

            j = j + 1
            i = i - 1

        print("Magic Square for n =", n)
        print("Sum of each row or column", n * (n * n + 1) // 2, "\n")

        for i in range(0, n):
            for j in range(0, n):
                print('%2d ' % (magicSquare[i][j]), end='')
                if j == n - 1:
                    print()

# Theory: This method generates an n x n magic square using the Siamese method, where the sum of every row, column, and diagonal is the same.

if __name__ == "__main__":
    choice = 0
    sq = magicsquare()
    while choice != 3:
        print("*************** MAGIC SQUARE ***********************")
        print("1. Read the Size of Matrix")
        print("2. Print the Magic Square Matrix")
        print("3. Exit Application")
        choice = int(input("Enter your choice::"))
        if choice == 1:
            n = sq.num()
        elif choice == 2:
            sq.generateSquare(n)
        elif choice == 3:
            print("Good Bye!!")
            break
        else:
            print("Wrong choice!!")

# Theory: The driver code provides a menu-driven interface to input the size of the matrix and generate the magic square, ensuring seamless user interaction.
