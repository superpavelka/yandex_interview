#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <string>
#include <unordered_set>
#include <unordered_map>

/*
Sample Input ["eat", "tea", "tan", "ate", "nat", "bat"]
Sample Output [ ["ate", "eat", "tea"], ["nat", "tan"], ["bat"] ]

Т.е. сгруппировать слова по "общим буквам".*/

std::vector<std::vector<std::string>> getGroupWords(std::vector<std::string> words)
{
	std::unordered_set<std::string> groupsSet;
	std::vector<std::vector<std::string>> groups;
	std::vector<std::string> wordsInGroup;
	std::unordered_map<std::string, int> groupsNum;
	int groupNum = 0;
	for (auto word : words)
	{
		std::string sortedWord = word;
		std::sort(sortedWord.begin(), sortedWord.end());
		if (groupsSet.insert(sortedWord).second)
		{
			groupsNum[sortedWord] = groupNum;
			wordsInGroup.push_back(word);
			groups.push_back(wordsInGroup);
			groupNum++;
			wordsInGroup.clear();
		}
		else
			groups[groupsNum[sortedWord]].push_back(word);
	}

	return groups;
}

int main()
{
	std::vector<std::string> words{ "eat", "tea", "tan", "ate", "nat", "bat" };
	auto now = std::chrono::high_resolution_clock::now();
	auto answer = getGroupWords(words);
	auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - now);
	//std::cout << "Answer= " << answer << "\n";
	std::cout << "Time : " << elapsed.count() << "ns.\n";
	return 0;
}