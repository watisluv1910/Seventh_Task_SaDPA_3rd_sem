#include <iostream>

#include "RLE.h";

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
			
			break;
		}
		case 3:
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
		"2)Enter <2> to initialize red-black tree.\n"
		"3)Enter <3> to rewrite a txt file.\n"
		"4)Enter <0> to exit.\n";
}

// Function to calculate compression ratio
double compressionRatio(std::string input, std::string output)
{
	return (double)input.length() / output.length();
}
