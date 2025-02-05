#include "ReadFile.h"
#include <string>
#include <fstream> 
 
ReadFile::ReadFile()
	:m_inputFile{std::ifstream("Level1.txt"), std::ifstream("Level2.txt"), std::ifstream("Level3.txt")}
{ 
}

std::ifstream& ReadFile::getNewLevel(int index)
{
	if (index < 0 || index >= 3) {
		throw std::out_of_range("Index out of range");
	}
	// //Close the file if it is already open
	//if (m_inputFile[index].is_open()) {
	//	m_inputFile[index].close();
	//}
	//// Reopen the file with the correct name
	///*std::string fileName = "Level" + std::to_string(index + 1) + ".txt";
	//m_inputFile[index].open(fileName);*/
	return  m_inputFile[index];
}
