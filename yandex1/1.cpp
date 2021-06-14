#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <chrono>
#include <cstdlib>
#include <unordered_set>

/*
Даны два массива: [1, 2, 3, 2, 0] и [5, 1, 2, 7, 3, 2]
Надо вернуть [1, 2, 2, 3] (порядок неважен)
*/

void mergeNums(std::vector<int>& nums1, std::vector<int>& nums2, std::vector<int>& nums3) {

	std::unordered_set<int> s;
	for (const auto &n : nums1)
	{
		if (s.insert(n).second && n > 0)
			nums3.push_back(n);
	}
	for (const auto &n : nums2)
	{
		if (s.insert(n).second && n > 0)
			nums3.push_back(n);
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