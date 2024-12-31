#include <iostream>
#include <algorithm>
using namespace std;

template<typename T>
class SimpleVector {
private:
	T* data;
	int currentSize;
	int currentCapacity;

public:
	SimpleVector(int capacity = 10) : currentCapacity(capacity), currentSize(0) {
		data = new T[currentCapacity];
	}
	SimpleVector(const SimpleVector<T>& other) {
		currentSize = other.currentSize;
		currentCapacity = other.currentCapacity;

		data = new T[currentCapacity];
		memcpy(data, other.data, sizeof(T) * currentSize);
	}
	~SimpleVector() {
		delete[] data;
	}

public:
	void push_back(const T& value) {
		if (currentSize >= currentCapacity) {
			resize(currentCapacity + 5);
		}
		data[currentSize] = value;
		currentSize++;
	}
	void pop_back() {
		data[--currentSize] = 0;
	}

	void resize(int newCapacity) {
		if (newCapacity > currentCapacity) {
			currentCapacity = newCapacity;

			T* newData = new T[currentCapacity];
			memcpy(newData, data, sizeof(T) * currentSize);

			delete[] data;
			data = newData;
		}
	}
	void sortData() {
		sort(data, data + currentSize);
	}

	int size() { return currentSize; }
	int capacity() { return currentCapacity; }
};

int main() {
	SimpleVector<int> sv;
	SimpleVector<int> sv2(5);

	sv2.push_back(6);
	sv2.push_back(2);
	sv2.push_back(1);
	sv2.push_back(10);
	sv2.push_back(8);
	
	SimpleVector<int> sv3 = sv2;

	sv3.push_back(4);
	sv3.push_back(3);
	sv3.pop_back();
	sv3.pop_back();
	sv3.pop_back();
	sv3.push_back(4);
	sv3.push_back(3);
	sv3.push_back(8);

	sv3.sortData();
}