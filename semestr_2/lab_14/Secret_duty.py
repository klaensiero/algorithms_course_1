import re
import sys

def check_txt(txt):
    name = r'([A-Z][a-z]*\s){3}'
    age = r'\d\d\s'
    phone_number = r'[+]?[7|8]+[(]?\d{3}[)]?[-]?\d{3}[-]?\d{2}[-]?\d{2}\s'
    address = r'g\.[A-Z]{3}(,\s)' + r'ul\.[A-Za-z]*(,\s)' + r'd\.\d*'
    total = (name + age + phone_number + address)

    if re.search(total, ' '.join(txt)):
        return 'YES'
    else:
        return 'NO'

input = open(0).readline
n = int(input())

for i in range(n):
    txt = input().split()
    print(check_txt(txt))
