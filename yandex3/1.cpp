#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <string>

/*
Дан список интов, повторяющихся элементов в списке нет. Нужно преобразовать это множество в строку, сворачивая соседние по числовому ряду числа в диапазоны. Примеры:
[1,4,5,2,3,9,8,11,0] => "0-5,8-9,11"
[1,4,3,2] => "1-4"
[1,4] => "1,4"
*/

int convert(std::vector<int>& nums1, std::string& sout) {

	if (!nums1.size())
		return -1;

	std::sort(nums1.begin(), nums1.end());
	int lastNum = nums1[0];
	bool seq = false;
	int seqFirst = -1;
	for (int i = 1; i < nums1.size(); ++i)
	{
		if (nums1[i] == lastNum + 1)
		{
			if (!seq)
				seqFirst = lastNum;
			seq = true;
			lastNum = nums1[i];
		}
		else
		{
			if (seq)
				sout += std::to_string(seqFirst) + '-' + std::to_string(lastNum) + ',';
			else
				sout += std::to_string(lastNum) + ',';
			seq = false;
			lastNum = nums1[i];
		}
	}
	if (seq)
		sout += std::to_string(seqFirst) + '-' + std::to_string(lastNum);
	else
		sout += std::to_string(lastNum);

	return 0;
}

int main()
{
	std::string sout;
	std::vector<int> nums1{ 1, 4, 5, 2, 3, 9, 8, 11, 0 };
	std::vector<int> nums2{ 1, 5, 7, 11 };
	auto now = std::chrono::high_resolution_clock::now();
	int err = convert(nums1, sout);
	auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - now);
	//std::cout << "Answer= " << answer << "\n";
	std::cout << "Time : " << elapsed.count() << "ns.\n";
	return 0;
}