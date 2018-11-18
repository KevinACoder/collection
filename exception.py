#!/usr/bin/env python3

""" try:
    print(5/0)
except ZeroDivisionError:
    print('illeagle to have zero divided') """

print('Divide two Given num')
print('Enter q to exit')

#file operation exception
try:
    with open('alice.txt') as f_obj:
        contents = f_obj.read()
except FileNotFoundError:
    print('file not found')

#zero divide exception
while True:
    num1 = input('first num\n')
    if num1 == 'q':
        break
    num2 = input('second num\n')
    try:
        ans = int(num1)/int(num2)
    except ZeroDivisionError:
        print("You can't divide by 0!")
    except ValueError:
        print("Input value is illeagle")
    else:
        print(ans)