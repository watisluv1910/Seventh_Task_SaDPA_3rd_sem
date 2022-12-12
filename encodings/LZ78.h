#pragma once

#include <list>
#include <string>
#include <map>

using std::list;
using std::map;
using std::string;

struct LZ78_Node
{
	int index;
	char next;

	LZ78_Node() {
		index = 0;
		next = '\0';
	}

	LZ78_Node(int index, char next)
	{
		this->index = index;
		this->next = next;
	}
};

class LZ78
{
public:
	static list<LZ78_Node> Encode(string input);
	static string Decode(list<LZ78_Node> input);
};