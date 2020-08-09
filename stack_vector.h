#pragma once

#include <array>
#include <iterator>
#include <stdexcept>

using namespace std;

template<typename T, size_t N>
class StackVector {
public:
	explicit StackVector(size_t a_size = 0) 
	: size_(a_size) {
		if (size_ > N) {
			throw invalid_argument("too big vector");
		}
	}

	T& operator[](size_t index) {
		return data_[index];
	}
	const T& operator[](size_t index) const {
		return data_[index];
	}

	T* begin() {
		return &data_[0];
	}
	T* end() {
		return begin() + size_;
	}
	const T* begin() const {
		return &data_[0];
	}
	const T* end() const {
		return begin() + size_;
	}

	size_t Size() const {
		return size_;
	}
	size_t Capacity() const {
		return N;
	}

	void PushBack(const T& value) {
		if (size_ == Capacity()) {
			throw overflow_error("Vector is full");
		}
		data_[size_] = value;
		size_++;
	}
	T PopBack() {
		if (size_ == 0) {
			throw underflow_error("Vector is empty");
		}
		size_--;
		return data_[size_];
	}
private:
	array<T, N> data_;
	int size_;
};