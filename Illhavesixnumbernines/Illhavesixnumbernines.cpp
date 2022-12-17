#include <iostream>
#include <fstream>

bool isCharacter(char c) {
    if (std::tolower(c) >= 97 && std::tolower(c) <= 125) {
        return true;
    }
    return false;
}

int main()
{
	std::string c;
	std::ifstream in("input1.txt", std::ios::in);
	in >> c;
	int count = 0;

	for (int i = 0; i < c.size(); i++) {
		if (isCharacter(c[i])) {
			count++;
		}
	}

		std::cout << count;
	}
