/*
 * SlidingWindow.h
 *
 *  Created on: Feb 27, 2019
 *      Author: Vidula Kopli
 */

#ifndef SLIDINGWINDOW_H_
#define SLIDINGWINDOW_H_

// COMMENT OUT to debug in C++
#include <Arduino.h>

class SlidingWindow {

private:
  int m_size;
  int* m_window;
  int m_idx_fill = 0; // the index that window is filled to so far
  int m_idx = m_size - 1; // current index of start of window (newest value)
  int m_sum = 0;

private:
  void populate(float value);

public:

  SlidingWindow(int size);

  ~SlidingWindow();

  void update(float value);

  float getMean();

  float getMaxDeviation();

  float get(int idx); // for testing purposes

  float lineLength();

};


#endif /* SLIDINGWINDOW_H_ */
