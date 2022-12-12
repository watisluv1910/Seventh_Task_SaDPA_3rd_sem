#pragma once

#include <string>
#include <list>

using std::list;
using std::string;

struct LZ77_Node
{
	int offset;
	int length;
	char next;

	LZ77_Node()
	{
		offset = 0;
		length = 0;
		next = 0;
	}

	LZ77_Node(int offset, int length, char next)
	{
		this->offset = offset;
		this->length = length;
		this->next = next;
	}
};

class LZ77
{
public:
	static list<LZ77_Node> Encode(string input);
	static string Decode(list<LZ77_Node> input);
};