import random

array = [random.randint(-10, 10) for _ in range(10)]
print(array)

i = 0
while (i < len(array)):
    if array[i] % 2 == 0:
        array.insert(i+1, array[i]+1)
        i += 1
    i += 1

print(array)
