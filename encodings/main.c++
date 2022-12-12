#include <iostream>

#include "RLE.h";
#include "LZ77.h";
#include "LZ78.h";

void printMenu();
double compressionRatio(std::string input, std::string output);

int main()
{
	printMenu();

	std::cout << "\nYour choise is:\n";

	size_t path = 0; // Menu navigation variable
	std::cin >> path;

	// cin.clear and cin.ignore are used to prevent fake input:
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<int>::max(), '\n');

	while (path)
	{
		switch (path)
		{
		case 1:
		{
			// Test RLE
			std::string input = "WWWWWWWWWBBBWWWWWWWWWWWWWWWWWWWWWWWWBWWWWWWWWWWWWWW";
			std::string output = RLE::Encode(input);
			std::cout << "\nInput string with long sequencies: " << input << '\n';
			std::cout << "\nEncoded string with long sequencies:\n" << output << '\n';
			std::cout << "\nEncoding compression ratio:\n" << compressionRatio(input, output) << '\n';

			input = "ABCABCABCDDDFFFFFF";
			output = RLE::Encode(input);
			std::cout << "\nInput string with short sequencies: " << input << '\n';
			std::cout << "\nEncoded string with short sequencies:\n" << output << '\n';
			std::cout << "\nEncoding compression ratio:\n" << compressionRatio(input, output) << '\n';
			break;
		}
		case 2:
		{
			// Test LZ77 encoding with 0100101010010000101
			std::string input = "0100101010010000101";
			std::list<LZ77_Node> output = LZ77::Encode(input);
			std::cout << "\nInput string: " << input << '\n';
			std::cout << "\nEncoded string:\n";
			for (auto& node : output)
			{
				std::cout << node.offset << " " << node.length << " " << node.next << '\n';
			}
			std::cout << "\nDecoded string:\n" << LZ77::Decode(output) << '\n';
			break;
		}
		case 3:
		{
			// Test LZ78 encoding with roporopoterropoterter
			std::string input = "roporopoterropoterter";
			std::list<LZ78_Node> output = LZ78::Encode(input);
			std::cout << "\nInput string: " << input << '\n';
			std::cout << "\nEncoded string:\n";
			std::string output_string = "";
			for (auto& node : output)
			{
				// Form output string
				output_string += std::to_string(node.index);
				output_string += node.next;
			}
			std::cout << output_string << '\n';
			std::cout << "\nDecoded string:\n" << LZ78::Decode(output) << '\n';
			std::cout << "\nEncoding compression ratio:\n" << compressionRatio(input, output_string) << '\n';
			break;
		}
		case 4:
		{
			
			break;
		}
		default:
			std::cerr << "\nError: Wrong path entered.\n"; // Error message
			break;
		}

		system("pause");
		system("cls"); // Clear screen

		printMenu();

		// Next menu navigation step:
		std::cout << "\nYour choise is:\n";
		std::cin >> path;

		// cin.clear and cin.ignore are used to prevent fake input
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<int>::max(), '\n');
	}

	return 0;
}

void printMenu()
{
	std::cout << "Practical task num.7\nIKBO-24-21 Nasevich V.V.\n"
		"Variant num. 16.\n\nMenu:\n"
		"1)Enter <1> to run RLE.\n"
		"2)Enter <2> to run LZ77.\n"
		"3)Enter <3> to run LZ78.\n"
		"4)Enter <4> to run LZ78.\n"
		"4)Enter <0> to exit.\n";
}

// Function to calculate compression ratio
double compressionRatio(std::string input, std::string output)
{
	return (double)input.length() / output.length();
}
