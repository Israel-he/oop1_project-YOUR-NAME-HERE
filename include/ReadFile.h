#include <iostream>
#include <fstream>
using namespace std;

class ReadFile
{
public:
	ReadFile();

	std::ifstream& getNewLevel(int indx);

private:

	ifstream m_inputFile[3];
	ifstream m_level1;
	ifstream m_level2;
	ifstream m_level3;
};
