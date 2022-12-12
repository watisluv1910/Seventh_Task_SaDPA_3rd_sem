#include "RLE.h"

#include <string>
#include <sstream>

using std::string;

//string RLE::Encode(string input)
//{
//	std::stringstream output;
//	int count = 1;
//	char last = input.at(0);
//	for (size_t i = 1; i < input.length(); i++)
//	{
//		if (input.at(i) == last)
//		{
//			count++;
//		}
//		else
//		{
//			output << count << last;
//			count = 1;
//			last = input.at(i);
//		}
//	}
//	output << count << last;
//	return output.str();
//}

// Encode RLE algorithm with grouping of repeating characters sequences
// Use positive numbers to display the number of repetitions of a sequence of characters
// Use negative numbers to display the number of non-repeating symbols following each other
// Count non-repeating symbols in a sequence of repeating characters until the character starts repeating again
// Example: "WWWWWWWWWBBBWWWWWWWWWWWWWWWWWWWWWWWWBWWWWWWWWWWWWWW" -> "9W3B24W1B14W"
// Example: "ABCABCABCDDDFFFFFF" -> "-9ABCABCABC3D6F"

string RLE::Encode(string input)
{
	std::string output;
	int count = 1,
		non_repeat_count = 1;
	char last = input.at(0);
	
	for (size_t i = 1; i < input.length(); i++)
	{
		if (input.at(i) == last)
		{
			count++;
			if (non_repeat_count > 1)
			{
				output += ((non_repeat_count > 2) ? "-" : "") + std::to_string(non_repeat_count - 1) + input.substr(i - non_repeat_count, non_repeat_count - 1);
			}
			non_repeat_count = 1;
		}
		else
		{
			if (count > 1)
			{
				output += std::to_string(count) + last;
				count = 1;
			}
			else
			{
				non_repeat_count++;
			}
			last = input.at(i);
		}
	}
	if (count > 1)
	{
		output += std::to_string(count) + last;
	}
	else
	{
		output += "-" + std::to_string(non_repeat_count) + last;
	}
	return output;
}
