#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <string>


void generate(std::string s, int l, int r, int pairs) {

	if ((l == pairs) && (r == pairs))
		std::cout << s << "\n";
	else
	{
		if (l < pairs)
			generate(s + "(", l + 1, r, pairs);
		if (r < l)
			generate(s + ")", l, r + 1, pairs);
	}

}

int main()
{
	std::string sout;
	std::vector<int> nums1{ 1, 4, 5, 2, 3, 9, 8, 11, 0 };
	std::vector<int> nums2{ 1, 5, 7, 11 };
	auto now = std::chrono::high_resolution_clock::now();
	std::string s("");
	generate(s, 0, 0, 3);
	auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - now);
	//std::cout << "Answer= " << answer << "\n";
	std::cout << "Time : " << elapsed.count() << "ns.\n";
	return 0;
}