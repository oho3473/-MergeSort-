#include<iostream>

void PrintArray(int input[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		std::cout << input[i] << " ";
	}
}

void Merge(int input[], int start, int half, int end, int temp[])
{
	int i{ start };
	int j{ half + 1 };
	int tempIndex{};

	while(i <= half && j <= end)
	{
		if (input[i] < input[j])
		{
			temp[tempIndex++] = input[i++];
		}
		else
		{
			temp[tempIndex++] = input[j++];
		}
	}

	while (i <= half)
	{
		temp[tempIndex++] = input[i++];
	}

	while (j <= end)
	{
		temp[tempIndex++] = input[j++];
	}

	tempIndex = 0;
	for (int i = start; i <= end; ++i)
	{
		input[i] = temp[tempIndex++];
	}
}

void MergeSort(int input[], int start, int end, int temp[])
{
	if (start >= end)
	{
		return;
	}

	int half = (start + end) / 2;

	MergeSort(input, start, half, temp);
	MergeSort(input, half + 1, end, temp);

	Merge(input, start, half, end, temp);
}



int main()
{
	int array[5]{ 8,7,2,3,1 };
	int tempArray[5]{};

	MergeSort(array, 0, 4, tempArray);
	PrintArray(array, 5);

}