#pragma once
#include "Util/ByteArray.h"

class EncodingTable
{
public:
	EncodingTable();
	~EncodingTable();
	bool load(std::string fileName);
	bool isLoaded() { return entries.size() != 0; };
	void addEntry(unsigned char* hex, int hexLength, std::wstring& value);
	void setTerminationEntry(unsigned char* hex, int hexLength);
	ByteArray encodeString(std::wstring& str, bool writeTermination = true);
	ByteArray encodeTermination();
private:
	int searchStringMatch(std::wstring& str, size_t pos = 0);

	struct TableEntry
	{
		int hexPos;
		int hexLen;
		int valuePos;
		int valueLen;
	};

	ByteArray hexData;
	std::wstring valueData;
	std::vector<TableEntry> entries;
	TableEntry terminationEntry;
};