#include <iostream>
#include <algorithm> 
#include <random>  
#include <chrono>
using namespace std;

const size_t n = 20;
double bt = 0.f;
double st = 0.f;
double it = 0.f;
mt19937 gen { random_device()() };
uniform_int_distribution<int> uid(-20, 40);

void bubble_sort(vector<int> &v, int l, int r) 
{
	bool b = true;
	while (b) {
		b = false;
		for (int i = l; i < r - 1; i++) {
			if (v[i] > v[i + 1]) {
				swap(v[i], v[i + 1]);
				b = true;
			}
		}
		r--;
	}
}

void selection_sort(vector<int> &v, int l, int r) 
{
	for (int i = l; i < r; i++) {
		int minz = v[i], ind = i;
		for (int j = i + 1; j < r; j++) {
			if (minz > v[j]) minz = v[j], ind = j;
		}
		swap(v[i], v[ind]);
	}
}

void insertion_sort(vector<int> &v, int l, int r) 
{
	for (int i = l + 1; i < r; i++) {
		int j = i;
		while (j > l && v[j - 1] > v[j]) {
			swap(v[j - 1], v[j]);
			j--;
		}
	}
}

void sort(vector<int> &v, int l, int r)
{
	int sz = r - l;
	if (sz <= 1) return;
	chrono::high_resolution_clock::time_point t1, t2;
	////////////////////////////////////////////////////////////////
	t1 = chrono::high_resolution_clock::now();
	bubble_sort(v, 0, v.size());
	t2 = chrono::high_resolution_clock::now();
	double btime = chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count();
	bt += btime;
	cout << "Bubble: " << bt << "us" << endl;
	////////////////////////////////////////////////////////////////
	t1 = chrono::high_resolution_clock::now();
	selection_sort(v, 0, v.size());
	t2 = chrono::high_resolution_clock::now();
	double stime = chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count();
	st += stime;
	cout << "Selection: " << st << "us" << endl;
	////////////////////////////////////////////////////////////////
	t1 = chrono::high_resolution_clock::now();
	insertion_sort(v, 0, v.size());
	t2 = chrono::high_resolution_clock::now();
	double itime = chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count();
	it += itime;
	cout << "Insertion: " << it << "us" << endl;
	////////////////////////////////////////////////////////////////
}

int main()
{
	vector<int> v(n);
	generate(v.begin(), v.begin() + n, [&]() -> int { return uid(gen); });
	for (auto i : v) {
		cout << i << " ";
	}
	cout << endl;
	sort(v, 0, v.size());
	for (auto i : v) {
		cout << i << " ";
	}
	system("pause");
	return 0;
}