#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <string>

/*Дана строка(возможно, пустая), состоящая из букв A - Z: AAAABBBCCXYZDDDDEEEFFFAAAAAABBBBBBBBBBBBBBBBBBBBBBBBBBBB
Нужно написать функцию RLE, которая на выходе даст строку вида : A4B3C2XYZD4E3F3A6B28
И сгенерирует ошибку, если на вход пришла невалидная строка.
Пояснения : Если символ встречается 1 раз, он остается без изменений;
Если символ повторяется более 1 раза, к нему добавляется количество повторений.*/

void convert(std::string& s, std::string& sout)
{
	if (!s.length())
		return;
	int result = 0;
	char lastChar = s[0];
	for (const auto& c : s)
	{
		if (lastChar && lastChar != c)
		{
			sout += lastChar;
			if (result > 1)
				sout += std::to_string(result);

			result = 1;
			lastChar = c;
		}
		else
			++result;
	}
	sout += lastChar;
	if (result > 1)
		sout += std::to_string(result);
}

int main()
{
	std::string s("AAAABBBCCXYZDDDDEEEFFFAAAAAABBBBBBBBBBBBBBBBBBBBBBBBBBBB");
	std::string sout;
	auto now = std::chrono::high_resolution_clock::now();
	convert(s, sout);
	auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - now);
	//std::cout << "Answer= " << answer << "\n";
	std::cout << "Time : " << elapsed.count() << "ns.\n";
	return 0;
}