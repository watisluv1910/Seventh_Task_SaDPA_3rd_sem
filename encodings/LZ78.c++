#include "LZ78.h"

list<LZ78_Node> LZ78::Encode(string input)
{
	string buffer = "";
	map<string, int> dictionary = {};
	list<LZ78_Node> result;

	for (size_t i = 0; i < input.size(); i++)
	{
		if (dictionary.find(buffer + input[i]) == dictionary.end())
		{
			LZ78_Node node(dictionary[buffer], input[i]);
			result.push_back(node);
			dictionary[buffer + input[i]] = dictionary.size() + 1;
			buffer = "";
		}
		else
		{
			buffer += input[i];
		}
	}

	if (!buffer.empty())
	{
		char last = buffer.at(buffer.size() - 1);
		buffer.erase(buffer.size() - 1);
		LZ78_Node node(dictionary[buffer], last);
		result.push_back(node);
	}
	
	return result;
}

string LZ78::Decode(list<LZ78_Node> input)
{
	string result = "";
	string word;
	map<int, string> dictionary = {};
	
	for (LZ78_Node node : input)
	{
		word = dictionary[node.index] + node.next;
		result += word;
		dictionary[dictionary.size() + 1] = word;
	}
	
	return result;
}