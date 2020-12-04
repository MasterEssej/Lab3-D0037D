#include <iostream>
using namespace std;

void swap_sort(int** a, int** b, int** c, bool order) {

	int hold;
	int n = 3;

	int array1[] = { **a, **b, **c };

	if (order) {
		for (int i = 0; i < n; i++) {
			for (int x = i + 1; x < n; x++) {
				if (array1[i] > array1[x]) {
					hold = array1[i];
					array1[i] = array1[x];
					array1[x] = hold;
				}
			}
		}
	}
	else {
		for (int i = 0; i < n; i++) {
			for (int x = i + 1; x < n; x++) {
				if (array1[i] < array1[x]) {
					hold = array1[i];
					array1[i] = array1[x];
					array1[x] = hold;
				}
			}
		}
	}

	**a = array1[0];
	**b = array1[1];
	**c = array1[2];
	cout << endl;
}


int main() {

	int a, b, c;

	bool order;

	//test
	int d = 7, e = 6, f = 1;
	int* p1 = &d, * p2 = &e, * p3 = &f;
	swap_sort(&p1, &p2, &p3, true);
	cout << *p1 << " " << *p2 << " " << *p3 << "\n" << endl;

	while (true) {

		cout << "Give a (0 to quit): ";
		cin >> a;

		if (a == 0) {
			break;
		}

		cout << "Give b: ";
		cin >> b;

		cout << "Give c: ";
		cin >> c;

		cout << "Sort ascending/descending (1/0): ";
		cin >> order;

		cout << endl;

		int* num1 = &a;
		int* num2 = &b;
		int* num3 = &c;

		swap_sort(&num1, &num2, &num3, order);

		cout << *num1 << " " << *num2 << " " << *num3 << endl;

		cout << endl;
		system("pause");
		system("cls");

	}

	return 0;
}