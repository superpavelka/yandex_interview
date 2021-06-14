/*
��� ������ �� ����� � ������. ����� ����������, ����� ������������ �� ����� 
����������� ������ ����� ��������, ������ ����� ���� ������� �������.

[1, 1, 0]
*/
// ������: [0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1]
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
			// ���� ��������� ����� �����
			if (nums[i] != nums[i - 1])
			{
				// ���� � ���� ������� �� 1 
				if (nums[i] == 1)
				{
					// ���� ��� ���� ����
					if (zerosCount == 1)
						// �� ���������� �������������� 1 
						onesCount = prevOnesCount;

					// ������������ 1
					onesCount++;
					// �������� ����������� 0
					zerosCount = 0;
				}
				// ���� � 1 ������� �� 0 
				else
				{
					// ���� ��������� ������� 1 ����������
					maxOnes = std::max(maxOnes, onesCount);
					prevOnesCount = onesCount - prevOnesCount;
					// �������� ����������� 1
					onesCount = 0;
					zerosCount++;
				}
			}
			// ���� �� ���� ����� �����
			else
			{
				// ���� ��� �������� �� ������������ �� � ���������
				if (nums[i] == 1)
					onesCount++;
				//���� ��� 0 �� �� ������������ �� � ���������
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