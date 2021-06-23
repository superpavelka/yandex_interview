/*
Дан массив из нулей и единиц. Нужно определить, какой максимальный по длине 
подинтервал единиц можно получить, удалив ровно один элемент массива.

[1, 1, 0]
*/
// пример: [0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1]
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <string>

int getMaxOnes(std::vector<int>& nums) {

	int maxOnes = 0;
	int onesCount = 0;
	int zerosCount = 0;
	int prevOnesCount = 0;

	if (nums.size())
	{
		onesCount = nums[0] == 0 ? 0 : 1;
		zerosCount = nums[0] == 0 ? 1 : 0;
		for (size_t i = 1; i < nums.size(); ++i)
		{
			// если произошла смена числа
			if (nums[i] != nums[i - 1])
			{
				// если с ноля перешли на 1 
				if (nums[i] == 1)
				{
					// если был один ноль
					if (zerosCount == 1)
						// то продолжаем аккумулировать 1 
						onesCount = prevOnesCount;

					// аккумулируем 1
					onesCount++;
					// обнуляем аккумулятор 0
					zerosCount = 0;
				}
				// если с 1 перешли на 0 
				else
				{
					// надо посчитать сколько 1 накопилось
					maxOnes = std::max(maxOnes, onesCount);
					prevOnesCount = onesCount - prevOnesCount;
					// обнуляем аккумулятор 1
					onesCount = 0;
					zerosCount++;
				}
			}
			// если не было смены числа
			else
			{
				// если это единичка то аккумулируем ее к остальным
				if (nums[i] == 1)
					onesCount++;
				//если это 0 то то аккумулируем ее к остальным
				else
					zerosCount++;
			}
		}
		maxOnes = std::max(maxOnes, onesCount);

	}

	return maxOnes;
}

int main()
{
	std::vector<int> nums1{ 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1 };  //4
	std::vector<int> nums2{ 0,0,0,0,0,0 }; //0
	std::vector<int> nums3{ 0,1,0,0,1,0 }; //1
	std::vector<int> nums4{ 1,1,1,1,1,1 }; //6
	std::vector<int> nums5{ 0,1,0,1,1 }; //3
	std::vector<int> nums6{ 1,1,0,0,1 }; //2
	int onesNum = 0;
	auto now = std::chrono::high_resolution_clock::now();
	onesNum = getMaxOnes(nums1);
	onesNum = getMaxOnes(nums2);
	onesNum = getMaxOnes(nums3);
	onesNum = getMaxOnes(nums4);
	onesNum = getMaxOnes(nums5);
	onesNum = getMaxOnes(nums6);
	auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - now);
	std::cout << "Answer= " << onesNum << "\n";
	std::cout << "Time : " << elapsed.count() << "ns.\n";
	return 0;
}