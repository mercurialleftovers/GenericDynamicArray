#include <iostream>
using namespace std;

#define GROWTH_FACTOR 2

template <typename T>
class DynamicArray {
private:
	T* array;
	size_t size;
	size_t cursor;

public:
	DynamicArray(size_t size = 16) {
		this->array = new T[size];
		this->size= size;
		this->cursor= 0; // initiating cursor to 0
	};


	T operator[](int i) {
		if (i < size - 1) {
			cout << array[i] << endl;
			return this->array[i];
		}

		else {
			cout << "so you want element number " << i << "but we only have " << this->size << endl;
			return (T) 0;
		}
	}

	bool add(T value) {
		if (cursor < size - 1) {
			this->array[cursor] = value;
			this->cursor++;

			return true;
		}
		else {
			cout << "resizing at: cursor = " << this->cursor << endl;
			// resizing the array
			size_t newSize = this->size * GROWTH_FACTOR;
			T* newArray = new T[newSize];
			// moving the old array to the newer one
			for (size_t i = 0; i < this->size; i++) {
				newArray[i] = this->array[i];
			}
			delete this->array;
			this->array = newArray;

			this->size = newSize;
			// adding the value to the new array:
			this->add(value);
			return false;
		}
	}

	void printAll() {
		for (size_t i = 0; i < this->cursor; i++)
			cout << this->array[i] << endl;
	}
};


int main() {

	DynamicArray<int> b;
	

	for (size_t i = 0; i < 256; i++) {
		b.add(i);
	}

	b.printAll();


	return EXIT_SUCCESS;
}