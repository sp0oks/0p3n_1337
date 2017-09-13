import sys

str1 = "temor"
str2 = "canil"
out = ""

for letter in sys.argv[1]:
    if (letter in str1) or (letter in str2) or (letter.lower() in str1) or (letter.lower() in str2):
        for i in range(0,5):
            if letter == str1[i] or letter.lower() == str1[i]:
                if letter.isupper():
                    out += str2[i].upper()
                else:
                    out += str2[i]
            elif letter == str2[i] or letter.lower() == str2[i]:
                if letter.isupper():
                    out += str1[i].upper()
                else:
                    out += str1[i]
    else:
        out += letter
print(out)
