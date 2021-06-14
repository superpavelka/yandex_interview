#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <string>

/*���� ������(��������, ������), ��������� �� ���� A - Z: AAAABBBCCXYZDDDDEEEFFFAAAAAABBBBBBBBBBBBBBBBBBBBBBBBBBBB
����� �������� ������� RLE, ������� �� ������ ���� ������ ���� : A4B3C2XYZD4E3F3A6B28
� ����������� ������, ���� �� ���� ������ ���������� ������.
��������� : ���� ������ ����������� 1 ���, �� �������� ��� ���������;
���� ������ ����������� ����� 1 ����, � ���� ����������� ���������� ����������.*/

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