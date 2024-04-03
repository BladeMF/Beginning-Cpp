#include <iostream>

using namespace std;

int *apply_all(int *array1, size_t array1_size, int *array2, size_t array2_size);
void print(const int *const array, size_t array_size);

int main()
{
	const size_t array1_size{5};
	const size_t array2_size{3};

	int array1[]{1, 2, 3, 4, 5};
	int array2[]{10, 20, 30};

	cout << "Array 1: ";
	print(array1, array1_size);

	cout << "Array 2: ";
	print(array2, array2_size);

	int *results = apply_all(array1, array1_size, array2, array2_size);
	constexpr size_t results_size{array1_size * array2_size};

	cout << "Result: ";
	print(results, results_size);

	cout << endl;

	delete[] results;

	return 0;
}

int *apply_all(int *array1, size_t array1_size, int *array2, size_t array2_size)
{
	int *result = new int[array1_size * array2_size];
	for (size_t i{0}; i < array1_size; i++)
	{
		for (size_t j{0}; j < array2_size; j++)
		{
			result[i * array2_size + j] = array1[i] * array2[j];
		}
	}
	return result;
}

void print(const int *const array, size_t array_size)
{
	if (array == nullptr)
	{
		return;
	}
	cout << "[ ";
	for (size_t i{0}; i < array_size; ++i)
	{
		cout << array[i] << " ";
	}

	cout << "]" << endl;
}
