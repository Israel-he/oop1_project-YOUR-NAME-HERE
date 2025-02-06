#include "ReadFile.h"
#include <string>
 
 
ReadFile::ReadFile()
	:m_inputFile{std::ifstream("Level1.txt"), std::ifstream("Level2.txt"), std::ifstream("Level3.txt")}
{ 
}

std::ifstream& ReadFile::getNewLevel(int index)
{
	if (index < 0 || index >= 3) {
		throw std::out_of_range("Index out of range");
	}
	return  m_inputFile[index];
}
