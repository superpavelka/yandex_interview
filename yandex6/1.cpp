#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <string>
#include <unordered_map>

/*
Даны даты заезда и отъезда каждого гостя. Для каждого гостя дата заезда строго 
раньше даты отъезда (то есть каждый гость останавливается хотя бы на одну ночь). 
В пределах одного дня считается, что сначала старые гости выезжают, а затем въезжают 
новые. Найти максимальное число постояльцев, которые одновременно проживали в гостинице 
(считаем, что измерение количества постояльцев происходит в конце дня).
sample = [ (1, 2), (1, 3), (2, 4), (2, 3), ]
*/

int getGuestsNum(std::vector<std::pair<int, int>>& g)
{
	int res = 0;

	std::unordered_map<int, int> arriving;
	std::unordered_map<int, int> leaving;
	std::vector<int> days;

	for (auto guest : g)
	{
		arriving[guest.first] += 1;
		leaving[guest.second] += 1;
		days.emplace_back(guest.first);
		days.emplace_back(guest.second);
	}

	int current = 0;
	std::sort(days.begin(), days.end()); 
	auto last = std::unique(days.begin(), days.end());
	days.erase(last, days.end());
	for (auto day : days)
	{
		current -= leaving[day];
		current += arriving[day];

		res = std::max(current, res);
	}
	
	return res;
}

int main()
{
	std::vector<std::pair<int, int>> g{ {1, 2}, {1, 3}, {2, 4}, {2, 3} };
	auto now = std::chrono::high_resolution_clock::now();
	auto answer = getGuestsNum(g);
	auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - now);
	std::cout << "Answer= " << answer << "\n";
	std::cout << "Time : " << elapsed.count() << "ns.\n";
	return 0;
}