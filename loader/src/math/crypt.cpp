#include "crypt.h"

#include "strings/strings.h"


std::unordered_map<char, const char*> map_encode_key = {
	{('A'),(const char*)morse_a},
	{('B'),(const char*)morse_b},
	{('C'),(const char*)morse_c},
	{('D'),(const char*)morse_d},

	{('E'),(const char*)morse_e},
	{('F'),(const char*)morse_f},

	{('G'),(const char*)morse_g},
	{('H'),(const char*)morse_h},

	{('I'),(const char*)morse_i},
	{('J'),(const char*)morse_j},
	{('K'),(const char*)morse_k},

	{('L'),(const char*)morse_l},
	{('M'),(const char*)morse_m},

	{('N'),(const char*)morse_n},
	{('P'),(const char*)morse_p},

	{('Q'),(const char*)morse_q},
	{('R'),(const char*)morse_r},
	
	{('S'),(const char*)morse_s},
	{('T'),(const char*)morse_t},

	{('U'),(const char*)morse_u},
	{('V'),(const char*)morse_v},
	{('O'),(const char*)morse_o},

	{('W'),(const char*)morse_w},
	{('X'),(const char*)morse_x},
	{('x'),(const char*)morse_x},

	{('Y'),(const char*)morse_y},
	{('Z'),(const char*)morse_z},


	{('0'),morse_0},
	{('1'),morse_1},
	{('2'),morse_2},
	{('3'),morse_3},
	{('4'),morse_4},
	{('5'),morse_5},
	{('6'),morse_6},
	{('7'),morse_7},
	{('8'),morse_8},
	{('9'),morse_9},

	{(','),morse_zap},
};

std::unordered_map<std::string, const char*> map_decode_key = {
{(const char*)morse_a, ("A")},
{(const char*)morse_b, ("B")},
{(const char*)morse_c, ("C")},
{(const char*)morse_d, ("D")},

{(const char*)morse_e, ("E")},
{(const char*)morse_f, ("F")},

{(const char*)morse_g, ("G")},
{(const char*)morse_h, ("H")},

{(const char*)morse_i, ("I")},
{(const char*)morse_j, ("J")},
{(const char*)morse_k, ("K")},

{(const char*)morse_l, ("L")},
{(const char*)morse_m, ("M")},

{(const char*)morse_n, ("N")},
{(const char*)morse_p, ("P")},

{(const char*)morse_q, ("Q")},
{(const char*)morse_r, ("R")},

{(const char*)morse_s, ("S")},
{(const char*)morse_t, ("T")},

{(const char*)morse_u, ("U")},
{(const char*)morse_v, ("V")},
{(const char*)morse_o, ("O")},

{(const char*)morse_w, ("W")},
{(const char*)morse_x, ("X")},
{(const char*)morse_x, ("x")},

{(const char*)morse_y, ("Y")},
{(const char*)morse_z, ("Z")},

{(const char*)morse_0, ("0")},
{(const char*)morse_1, ("1")},
{(const char*)morse_2, ("2")},
{(const char*)morse_3, ("3")},
{(const char*)morse_4, ("4")},
{(const char*)morse_5, ("5")},
{(const char*)morse_6, ("6")},
{(const char*)morse_7, ("7")},
{(const char*)morse_8, ("8")},
{(const char*)morse_9, ("9")},
{(const char*)morse_zap, (",")}
};


std::string encode(const char* str) {
    std::string new_string;

    for(int i = 0;i < strlen(str); i++){
		//std::cout << str[i] << std::endl;
		if(str[i] == ' ')
			continue;
			
        new_string += map_encode_key[str[i]];
		new_string += " ";
    }

    return new_string;
}


std::string decode(const char* str){
	std::string string;
	std::string new_string;
	
	for(int i = 0; i < strlen(str); i++ ){
		if(str[i] == ' ') {
			new_string  += map_decode_key[string];
			string.clear();
			continue;	
		}
		string += str[i];	
	}
	return new_string;
}