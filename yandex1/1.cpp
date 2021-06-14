#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <chrono>
#include <cstdlib>
#include <unordered_map>

/*
Даны два массива: [1, 2, 3, 2, 0] и [5, 1, 2, 7, 3, 2]
Надо вернуть [1, 2, 2, 3] (порядок неважен)
*/

void mergeNums(std::vector<int>& nums1, std::vector<int>& nums2, std::vector<int>& nums3) {

	std::unordered_map<int, int> m;
	for (const auto &n : nums1)
	{
		if (n > 0 && m[n])
			m[n]++;
		else if (n > 0 && !m[n])
			m[n] = 1;
	}
	for (const auto &n : nums2)
	{
		if (n > 0 && m[n])
		{
			m[n]--;
			nums3.push_back(n);
		}
	}
}

int main()
{
	std::vector<int> nums3;
	std::vector<int> nums1{ 1, 2, 3, 2, 0 };
	std::vector<int> nums2{ 5, 1, 2, 7, 3, 2 };
	auto now = std::chrono::high_resolution_clock::now();
	mergeNums(nums1, nums2, nums3);
	auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - now);
	//std::cout << "Answer= " << answer << "\n";
	std::cout << "Time : " << elapsed.count() << "ns.\n";
	return 0;
}