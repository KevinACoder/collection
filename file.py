#!/usr/bin/env python3

filename = './pi_digits.txt'

#read all contents
with open(filename) as file_obj:
    contents = file_obj.read()
    print(contents.lstrip())

#read file line by line
with open(filename) as file_obj:
    for line in file_obj:
        print(line.strip())
#another way
with open(filename) as file_obj:
    pi_str = ''
    lines = file_obj.readlines()
    for line in lines:
        print(line.strip())
        pi_str += line.strip()
    print(pi_str, len(pi_str))

greate_file_name = './pi_million_digits.txt'
#handle great size file
with open(greate_file_name) as file_obj:
    lines = file_obj.readlines()
    pi_str = ''
    for line in lines:
        pi_str += line.strip()
    print(pi_str[:50], '...')
    #birthday = input('Enter you birthday, in mmddyy:')
    #if birthday in pi_str:
    #    print('birthday exist in pi')
    #else:
    #    print('birthday not exist in pi')

output_file_name = 'programming.txt'

#write multi-line string
with open(output_file_name, 'w') as file_obj:
    file_obj.write('kevin\n')
    file_obj.write('is programming\n')
    print('writing done')

#append to file
with open(output_file_name, 'a') as file_obj:
    file_obj.write('with python\n')

with open(output_file_name, 'r') as file_obj:
    contents = file_obj.read()
    contents.split()