# **`Q.1] Given two variables, a and b, exchange values assigned to them.`**

# Given
```py
a = int(input("Enter the first number: "))
b = int(input("Enter the second number: "))
```
# Method 1
```py
a = a + b
b = a - b
a = a - b

print(f"{a} {b}")
```
# Method 2
```py
t = a
a = b
b = t

print(f"{a} {b}")
```
# **`Q.2] Given two variables, integer types, x & y, exchange there values without using extra space.`**

# Given
```py
a = int(input("Enter the first number: "))
b = int(input("Enter the second number: "))
```
# Method 1
```py
a = a + b # 4
b = a - b # -2
a = a - b

print(f"{a} {b}")
```
# Method 2
```py
a = a^b
b = a^b
a = a^b

print(f"{a} {b}")
```
# Method 3
```py
a = (a & b) + (a | b);
b = a + (~b) + 1;
a = a + (~b) + 1;

print(f"{a} {b} ")
```
# **`Q3.] Design an algorithm that makes the following exchanges:`**
                +-> a -> b -> c +
                |               |
                +---------------+ 
#**`The arrow indicates that b is to assume the value of a, c the value of b, and so on.`**
```py
def three_num_exchange(a, b, c):
    t = a
    a = c
    c = b
    b = t
    return a, b, c

if __name__ == '__main__':
    a = int(input("Enter the first number: "))
    b = int(input("Enter the second number: "))
    c = int(input("Enter the third number: "))

    print(f"{three_num_exchange(a, b, c)}")
```
# **`Q.4] Design an algorithm that makes the following exchanges:`**
                +-> a -> b -> c -> d +
                |                    |
                +--------------------+
#**`The arrow indicates that b is to assume the value of a, c the value of b, and so on.`**
```py
def four_num_exchange(a, b, c, d):
    t = a
    a = d
    d = c
    c = b
    b = t

    return a, b, c, d

if __name__ == '__main__':
    a = int(input("Enter the first number: "))
    b = int(input("Enter the second number: "))
    c = int(input("Enter the third number: "))
    d = int(input("Enter the fourth number: "))

    print(f"{four_num_exchange(a, b, c, d)}")

```
# **`Q.5] Given a set of n students' examination marks (in the range 0 to 100) make a count of the number of students that passed the examination. A pass is awarded for all marks of 50 and above.`**
```py
def passCount(marks, passing = 50):
    count = 0
    for i in marks:
        if i>=50:
            count += 1
    return count

if __name__ == '__main__':
    n = int(input("Enter number of students: "))
    print("Enter the marks one by one
    : ")

    marks = []
    for i in range(0, n):
        x = int(input())
        marks.append(x)
    
    print(f"Number of students passed: {passCount(marks)}")
```

# **`Q.6] Write a program to calculate average of n numbers.`**
```py
n = int(intput("Enter the 'n' numbers: "))

sum = 0
for i in range(n):
    num = int(input("Enter the number: "))
    sum += num
avg = sum/n
print("Average of ", n, " numbers is :", avg)
```
# **`Q.7] Write a program to calculate sum of squares of n numbers.`** 
```py
n = int(input("Enter the 'n' numbers: "))
sum = 0

for i in range(n):
    num = int(input(f"Enter the number: "))
    sum += i*i

print(f"Sum of squares of the entered n numbers is {sum}")
```
# **`Q.8] Compute sum of firts n terms of: 1+2+3...`**
```py
n = int(input(f"Enter the count of first 'n' natural numbers: "))

sum = n*(n+1)//2

print(f"Sum of first {n} terms is: {sum}")
```
# **`Q.9] Compute sum of first n terms of:1+3+5...`**
```py
n = int(input(f"Enter the 'n' numbers: "))

sum = n*n
print(f"Sum of of first {n} odd numbers is {sum}")
```
# **`Q.10] Compute sum of first n terms of:2+4+6...**`
```py
n = int(input(f"Enter the 'n' numbers: "))

sum = n*(n+1)
print(f"Sum of the first {n} even numbers is {sum}")
```
# **`Q.11] Compute sum of first n terms pf:1+1/2+1/3...`**
```py
n = int(input(f"Enter the 'n' numbers: "))

sum = 0
for i in range(1, n+1):
    sum += 1/i

print(f"The sum is {round(sum, 3)} ") 
```
# **`Q.12] Print the first n terms of the series 1 2 4 8 16 32`** 
```py
n = int(input(f"Enter the 'n' numbers: "))

for i in range(n):
    s = pow(2, i)
    print(s, end=" ")
```
# **`Q.13] Compute the sum of n terms of following 1-3+5-7+9...`**
```py
n = int(input(f"Enter the 'n' numbers: "))

if n&1:
    print(n)
else:
    print(-n)
```
# **`Q.14] Given a number n, calculate 1/n!`** 
```py
def facto(n):
    fact = 1
    for i in range(2, n + 1):
        fact *= i
    return(fact)

n = int(input(f"Enter 'n': "))
ans = 1/facto(n)

print(f"Answer is {ans} ")
```

# **`Q.15] Given a value for x and n, calculate balue of x^n/n!`**
```py
x = int(input(f"Enter x: "))
n = int(input(f"Enter n: "))

ans = pow(x, n)
ans /= facto(n)

print(f"Answer is {ans} ")
```
# **`Q.16] Compute sum of first n terms of series. 1!+2!+3!...`**
```py
n = int(input(f"Enter 'n': "))

sum = 1
for i in range(2, n+1):
    sum += facto(i)

print(f"Sum is {sum} ")
```
# **`Q.17] Compute value of n as 1/0!+ 1/1! +1/2!...`**
```py
def facto(n):
    fact = 1
    for i in range(2, n + 1):
        fact *= i
    return(fact)

n = int(input(f"Enter 'n': "))

sum = 1
for i in range(1, n+1):
    sum += 1/facto(i)

print(f"Sum is {sum} ")
```
# **`Q.18] Write a program to simulate multiplication by addition.`**
```py
first_num = int(input(f"Enter the first number: "))
second_num = int(input(f"Enter the second number: "))

sum = first_num
for i in range(1, second_num):
    sum += first_num

print(f"Answer is {sum} ")
```
# **`Q.19] Write a program to print sum of fibbonacci series.`**
```py
def SUM(n):
    sum=0
    x = 0
    y = 1
    for i in range(1, n+1):
        sum=x+y
        y=x
        x=sum

n = int(input(" Enter number of terms :"))
print(f"Fibbonacci Series is: {SUM(n)} ")
```
# **`Q.20] Write a program to calculate number of digits in an integer.`**
```py
def cal(n):
    c = 0
    while(n>0):
        c += 1
        n //= 10
    return c

n = int(input(f"Enter the number: "))
if n == 0:
    print(f"The number of digits in the given integer is: 0")
else:
    print(f"The number of digits in the given integer are/is: {cal(n)} ")
```
# **`Q.21] Write a program to convert binary number to decimal.`**
```py
def binToDeci(n):
    
    if(n == 0):
        return 0
    
    return (n % 10 + 2 * binToDeci(n // 10))

binary_num = int(input('Enter a binary number = '))

ans = binToDeci(binary_num)

print(f"The decimal Equivalent of the given binary number {binary_num} is : {ans}")
```
# **`Q.22] Write a program to find square root of a number.`**
```py
import math

n = int(input(f"Enter the number: "))
print(f"The square of given number is: {math.sqrt(n)} ")
```
# **`Q.23] Write a program to calculate geometric mean of n numbers.`**
```py
import math

def geoMean(n):
    c = 1
    for i in range(1, n+1):
        c *= n
    return c

n = int(input(f"Enter the number: "))
print(f"The geometric mean of given {n} numbers is: {math.sqrt(geoMean(n))} ")
```
# **`Q.24] Given that a=0,b=1,c=1. generate a sequendce in which next term is sum of three preeceding terms.`**
```py
def printTribRec(n) :
    if (n == 0 or n == 1 or n == 2) :
        return 0
    elif (n == 3) :
        return 1
    else :
        return (printTribRec(n - 1) +
                printTribRec(n - 2) +
                printTribRec(n - 3))
         
 
def printTrib(n) :
    for i in range(1, n) :
        print( printTribRec(i) , " ", end = "")
         
 
n = 10
printTrib(n)
```
# **`Q.25] Write a program to find minimum number in an array.`**
```py
import numpy

A = numpy.array([10, 20, 30, 40, 50])

min_ele = numpy.min(A)

print(f"The minimum element is: {min_ele} ")
```
# **`Q.26] Write a program to find maximum number in an array.`**
```py
import numpy

A = numpy.array([10, 20, 30, 40, 50])

max_ele = numpy.max(A)

print(f"The minimum element is: {max_ele} ")
```
# **`Q.27] Write a program to find number of occurences of maximum element in an array.`**

```py
import numpy
c = 0
A = numpy.array([1, 1, 2, 6, 6, 5, 4, 6, 3, 6])

max_ele = numpy.max(A)

for i in A:
    if(i == max_ele):
        c += 1

print(f"The frequency of maximum element is: {c} ")
```
# **`Q.28] Write a program to find a number and print it.`**
```py
import numpy 

def Find(arr, x):
    for i in arr:
        if(i == x):
            return i
    return -1

A = numpy.array([1, 2, 3, 4, 5, 6, 7, 8, 9])

n = int(input(f"Enter the number to find/search: "))
print(f"The element found at: {Find(A, n)} ")
```
# **`Q.29] Write a program to find second largest number in an array.`**
```py
import numpy as np

def secondLarge(arr):
    arr.sort()
    return arr[len(arr) - 1]

A = np.array([10, 3, 11, 56, 13, 64, 75, 6])
print(f"The second largest element of the array {A} is {secondLarge(A)} ")
```
# **`Q.30] Write a program to merge two arrays.`**
```py
import numpy as np

def Merge(A, B):
    C = np.concatenate([A, B])
    return C

A = np.array([1, 2, 3])
B = np.array([4, 5, 6])

print(f"The array after merging is: {Merge(A, B)} ")
```
