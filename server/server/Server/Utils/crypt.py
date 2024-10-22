
# MORSE CRYPT
morse_encode = {
"A" : ".-",
"B" : "-...",
"C" : "-.-.",
"D" : "-..",
"E" : ".",
"F" : "..-.",
"G" : "--.",
"H" : "....",
"I" : "..",
"J" : ".---",
"K" : "-.-",
"L" : ".-..",
"M" : "--",
"N" : "-.",
"O" : "---",
"P" : ".--.",
"Q" : "--.-",
"R" : ".-.",
"S" : "...",
"T" : "-",
"U" : "..-",
"V" : "...-",
"W" : ".--",
"Y" : "-.--",
"Z" : "--..",
"x" : "-..-",


"a" : ".-",
"b" : "-...",
"c" : "-.-.",
"d" : "-..",
"e" : ".",
"f" : "..-.",
"g" : "--.",
"h" : "....",
"i" : "..",
"j" : ".---",
"k" : "-.-",
"l" : ".-..",
"m" : "--",
"n" : "-.",
"o" : "---",
"p" : ".--.",
"q" : "--.-",
"r" : ".-.",
"s" : "...",
"t" : "-",
"u" : "..-",
"v" : "...-",
"m" : ".--",
"y" : "-.--",
"z" : "--..",

"," : "--..--",

"1" : ".----",
"2" : "..---",
"3" : "...--",
"4" : "....-",
"5" : ".....",
"6" : "-....",
"7" : "--...",
"8" : "---..",
"9" : "----.",
"0" : "-----",
}

morse_decode = {
".-" : "A",
"-..." : "B",
"-.-." : "C",
"-.." : "D",
"." : "E",
"..-." : "F",
"--." : "G",
"...." : "H",
".." : "I",
".---" : "J",
"-.-" : "K",
".-.." : "L",
"--" : "M",
"-" : "N",
"---" : "O",
".--." : "P",
"--.-" : "Q",
".-." : "R",
"..." : "S",
"-" : "T",
"..-" : "U",
"...-" : "V",
".--" : "W",
"-.--" : "Y",
"--.." : "Z",
"-..-" : "x",

"--..--" : ",",

".----" : "1",
"..---" : "2",
"...--" : "3",
"....-" : "4",
"....." : "5",
"-...." : "6",
"--..." : "7",
"---.." : "8",
"----." : "9",
"-----" : "0"
}


def encode(str_c : str) -> str:
    new_string  = ""
    for i in range(len(str_c)):
        if str_c[i] == " " or  str_c[i] == "\n":
            continue

        new_string += morse_encode[str_c[i]]
        new_string += " "

    return new_string
        


