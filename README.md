## Lab 2: UTF-8 Analyzer

For lab 2, your group will write a program that reads UTF-8 input and prints out some information about it.

The program should take a UTF-8 encoded string as input and print out the following information in the terminal:

1. whether the string is valid ASCII (e.g. all bytes are 127 or less).
2. the same input string, but any ASCII lowercase characters `a`-`z` are changed to their uppercase versions. Leaves all other characters unchanged. 
3. length of the string in bytes.
4. the number of UTF-8 codepoints represented by the string.
5. decimal representations of each codepoint.
6. how many bytes are used to represent each codepoint.
7. substring of the input string containing only the first 6 codepoints.
8. all animal emojis in the input string
9. the code point with value one higher at index 3 (e.g. for ”é“ U+00E9 that would be “ê” (U+00EA), and for “🐩” (U+1F429) that would be “🐪” (U+1F42A)). 

Here's what the output of a sample run of your program should look like:
```

$ ./utf8analyzer "My 🐩’s name is Erdős."
Valid ASCII: false
Uppercased ASCII: MY 🐩’S NAME IS ERDőS.
Length in bytes: 27
Number of code points: 21
Code points as decimal numbers: 77 121 32 128041 8217 115 32 110 97 109 101 32 105 115 32 69 114 100 337 115 46
Bytes per code point: 1 1 1 4 3 1 1 1 1 1 1 1 1 1 1 1 1 1 2 1 1
Substring of the first 6 code points: "My 🐩’s"
Animal emojis: 🐩
Next character of Codepoint at index 3: 🐪

```