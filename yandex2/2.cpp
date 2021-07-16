#include <iostream>
#include <algorithm>
#include <chrono>
#include <string>
#include <sstream>
#include <tuple>

using namespace std;

/*Дана строка(возможно, пустая), состоящая из букв A - Z: AAAABBBCCXYZDDDDEEEFFFAAAAAABBBBBBBBBBBBBBBBBBBBBBBBBBBB
Нужно написать функцию RLE, которая на выходе даст строку вида : A4B3C2XYZD4E3F3A6B28
И сгенерирует ошибку, если на вход пришла невалидная строка.
Пояснения : Если символ встречается 1 раз, он остается без изменений;
Если символ повторяется более 1 раза, к нему добавляется количество повторений.*/

template <typename It>
tuple < It, char, size_t> occurences(It it, It end_it)
{
	if (it == end_it)
		return { it, '?', 0 };
	const char c{ *it };
	const auto diff(find_if(it, end_it,
		[c](char x) {return c != x; }));

	return { diff, c, distance(it, diff) };
}

void convert2(string& s, string& sout)
{
	const auto end_it(end(s));
	stringstream r;

	for (auto it(begin(s)); it != end_it;)
	{
		const auto [next_diff, c, n](occurences(it, end_it));
		if (n != 1)
			r << c << n;
		else
			r << c;
		it = next_diff;
	}

	sout = r.str();
}

int main()
{
	string s("AAAABBBCCXYZDDDDEEEFFFAAAAAABBBBBBBBBBBBBBBBBBBBBBBBBBBB");
	string sout;
	auto now = chrono::high_resolution_clock::now();
	convert2(s, sout);
	auto elapsed = chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now() - now);
	//std::cout << "Answer= " << answer << "\n";
	cout << "Time : " << elapsed.count() << "ns.\n";
	return 0;
}