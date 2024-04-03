#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> vector1{};
	vector<int> vector2{};

	vector1.push_back(10);
	vector1.push_back(20);

	cout << "Vector1[0]=" << vector1.at(0) << "\n"
			 << "Vector1[1]=" << vector1.at(1) << "\n"
			 << "Vector1.size=" << vector1.size() << "\n"
			 << endl;

	vector2.push_back(100);
	vector2.push_back(200);

	cout << "Vector2[0]=" << vector2.at(0) << "\n"
			 << "Vector2[1]=" << vector2.at(1) << "\n"
			 << "Vector2.size=" << vector2.size() << "\n"
			 << endl;

	vector<vector<int>> vector_2d{};
	vector_2d.push_back(vector1);
	vector_2d.push_back(vector2);

	cout << "Vector2D[0][0]=" << vector_2d.at(0).at(0) << "\n"
			 << "Vector2D[0][1]=" << vector_2d.at(0).at(1) << "\n"
			 << "Vector2D[1][0]=" << vector_2d.at(1).at(0) << "\n"
			 << "Vector2D[1][1]=" << vector_2d.at(1).at(0) << "\n"
			 << endl;

	cout << "Setting vector1[0] to 1000" << endl;
	vector1.at(0) = 1000;

	cout << "Vector2D[0]=&" << &vector_2d.at(0) << "\n"
			 << "Vector2D[0][0]=" << vector_2d.at(0).at(0) << "\n"
			 << "Vector2D[0][1]=" << vector_2d.at(0).at(1) << "\n"
			 << "Vector2D[1]=&" << &vector_2d.at(1) << "\n"
			 << "Vector2D[1][0]=" << vector_2d.at(1).at(0) << "\n"
			 << "Vector2D[1][1]=" << vector_2d.at(1).at(0) << "\n"
			 << endl;

	cout << "Vector1=&" << &vector1 << "\n"
			 << "Vector1[0]=" << vector1.at(0) << "\n"
			 << "Vector1[1]=" << vector1.at(1) << "\n"
			 << "Vector1.size=" << vector1.size()
			 << endl;
}