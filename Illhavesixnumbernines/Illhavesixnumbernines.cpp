#include <iostream>
#include <fstream>
#include <vector>

bool isCharacter(char c) {
    if (std::tolower(c) >= 97 && std::tolower(c) <= 125) {
        return true;
    }
    return false;
}

bool isGlas(char c) {
	bool flag = false;
	if (c == 'а' || c == 'у' || c == 'о' || c == 'и' || c == 'э' || c == 'ы' || c == 'я' || c == 'ю' || c == 'е') {
		flag = true;
	}
	return flag;
}
void swap(std::string* xp, std::string* yp)
{
	std::string temp = *xp;
	*xp = *yp;
	*yp = temp;
}
void bubbleSort(std::string arr[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
			if (arr[j].size() < arr[j + 1].size())
				swap(&arr[j], &arr[j + 1]);
}
bool isWordRight(std::string word) {
	int glas = 0;
	int sogl = 0;

	for (int i = 0; i < word.size(); i++) {
		if ((int)word[i] >= -31 && (int)word[i] <= -1) {
			if (isGlas((char)std::tolower(word[i]))) {
				glas++;
			}
			else {
				sogl++;
			}
		}
	}

	if (glas == sogl && glas != 0) {
		return true;
	}
	else
	{
		return false;
	}
}

bool isWordsContain(std::string arr[], int n, std::string word) {
	bool flag = false;
	for (int i = 0; i < n; i++) {
		if (arr[i] == word) {
			flag = true;
		}
	}
	return flag;
}



int main()
{
	int no;
	std::cin >> no;
	switch (no) {
	case 1:
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
		break;
	}
	case 2:
	{
		int n;
		std::cin >> n;
		std::string words[10000];
		int count = 0;
		setlocale(LC_ALL, "Russian");

		std::ifstream in("input2.txt", std::ios::in);
		std::ofstream out("output2.txt", std::ios::out);
		while (!in.eof()) {
			std::string c;
			in >> c;
			if (isWordRight(c) && !isWordsContain(words, count, c)) {
				words[count] = c;
				count++;
			}
		}

		bubbleSort(words, count);
		if (n <= count) {
			for (int i = n - 1; i >= 0; i--) {
				out << words[i] << std::endl;
			}
		}
		else {
			for (int i = count - 1; i >= 0; i--) {
				out << words[i] << std::endl;
			}
		}	
		break;
	}
	}
}
