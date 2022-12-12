#pragma once

#include <string>

using std::string;

class RLE
{
public:
	static string Encode(string input);
	static string Decode(string input);
};