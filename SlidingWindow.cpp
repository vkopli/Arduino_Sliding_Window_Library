/*
 * SlidingWindow.cpp
 *
 *  Created on: Feb 27, 2019
 *      Author: Vidula Kopli
 */

#include "SlidingWindow.h"

//// COMMENT IN to debug in C++
//#include <iostream>
//#include <cmath>
//using namespace std;

SlidingWindow::SlidingWindow(int size) : m_size(size) {
    this->m_window = new int[size];
}

SlidingWindow::~SlidingWindow() {
    delete[] m_window;
}

void SlidingWindow::populate(float value) {
    if (m_idx_fill >= m_size) {
        return;
    }
    m_window[m_idx_fill++] = value;
    m_sum += value;
}

void SlidingWindow::update(float value) {
    if (m_idx_fill < m_size) { // if still filling window
        SlidingWindow::populate(value);
    } else {                   // if updating oldest value
        m_idx = (m_idx + 1) % m_size;
        float old_value = m_window[m_idx];
        m_window[m_idx] = value;
        m_sum = m_sum + value - old_value;
    }
}

float SlidingWindow::getMean() {
    return m_sum / (float) m_size;
}

float SlidingWindow::getMaxDeviation() {
    float mean = this->getMean();
    float max_deviation = 0;
    for (int i = 0; i < m_size; i++) {
        float deviation = abs(m_window[i] - mean);
        if (deviation > max_deviation) {
            max_deviation = deviation;
        }
    }
    return max_deviation;
}

float SlidingWindow::get(int idx) {
    return m_window[idx];
}

float SlidingWindow::lineLength() {
	float value = 0;
	for (int i = 1; i < m_size; i++) {
		value += abs(m_window[i] - m_window[i - 1]);
	}
	return value;
}


//// COMMENT IN to debug in C++ (create new sliding window operations)
//int main() {
//
//    SlidingWindow window(5);
//    for (int i = 0; i < 5; i++) {
//        window.update((float) i);
//    }
//    for (int i = 0; i < 5; i++) {
//        cout << "index " << i << ": " << window.get(i) << endl;
//    }
//    cout << "mean: " << window.getMean() << " max dev: " << window.getMaxDeviation() << endl;
//    cout << "-------------" << endl;
//    window.update(100.0);
//    for (int i = 0; i < 5; i++) {
//        cout << "index " << i << ": " << window.get(i) << endl;
//    }
//    cout << "mean: " << window.getMean() << " max dev: " << window.getMaxDeviation() << endl;
//    cout << "-------------" << endl;
//    window.update(6.0);
//    window.update(7.0);
//    for (int i = 0; i < 5; i++) {
//        cout << "index " << i << ": " << window.get(i) << endl;
//    }
//    cout << "mean: " << window.getMean() << " max dev: " << window.getMaxDeviation() << endl;
//    cout << "-------------" << endl;
//    window.update(8.0);
//    window.update(9.0);
//    window.update(10.0);
//    for (int i = 0; i < 5; i++) {
//        cout << "index " << i << ": " << window.get(i) << endl;
//    }
//    cout << "mean: " << window.getMean() << " max dev: " << window.getMaxDeviation() << endl;
//
//    cout << window.printTest() << endl;
//
//    return 0;
//}
