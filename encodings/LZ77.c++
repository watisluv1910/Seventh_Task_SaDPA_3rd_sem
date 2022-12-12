#include "LZ77.h"

list<LZ77_Node> LZ77::Encode(string input)
{
	list<LZ77_Node> output;
	for (int i = 0; i < input.size(); i++)
	{
		int offset = 0;
		int length = 0;
		for (int j = i - 1; j >= 0; j--) // walk back
		{
			int k = 0;
			while (input[i + k] == input[j + k]) // walk forward
			{
				k++;
				if (i + k >= input.size()) // end of input
				{
					break;
				}
			}
			if (k > length) // found a longer match
			{
				offset = i - j;
				length = k;
			}
		}
		LZ77_Node node(offset, length, input[i + length]);
		output.push_back(node);
		i += length;
	}
	return output;
}

string LZ77::Decode(list<LZ77_Node> input)
{
	string output;
	for (auto node : input)
	{
		for (int i = 0; i < node.length; i++)
		{
			output += output[output.size() - node.offset];
		}
		output += node.next;
	}
	return output;
}