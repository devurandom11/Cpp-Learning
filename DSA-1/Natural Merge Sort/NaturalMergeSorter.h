#ifndef NATURALMERGESORTER_H
#define NATURALMERGESORTER_H

class NaturalMergeSorter {
 public:
  virtual int GetSortedRunLength(int* array, int arrayLength, int startIndex) {
    if (startIndex >= arrayLength - 1) {
      return 0;
    }
    int count = 1;
    for (int i = startIndex; i < arrayLength - 1; i++) {
      if (array[i] > array[i + 1]) {
        return count;
      }
      count++;
    }
    return arrayLength - startIndex;
  }

  virtual void NaturalMergeSort(int* array, int arrayLength) {
    // Your code here
  }

  virtual void Merge(int* numbers, int leftFirst, int leftLast, int rightLast) {
    int mergedSize = rightLast - leftFirst + 1;
    int* mergedNumbers = new int[mergedSize];
    int mergePos = 0;
    int leftPos = leftFirst;
    int rightPos = leftLast + 1;

    // Add smallest element from left or right partition to merged numbers
    while (leftPos <= leftLast && rightPos <= rightLast) {
      if (numbers[leftPos] <= numbers[rightPos]) {
        mergedNumbers[mergePos] = numbers[leftPos];
        leftPos++;
      } else {
        mergedNumbers[mergePos] = numbers[rightPos];
        rightPos++;
      }
      mergePos++;
    }

    // If left partition isn't empty, add remaining elements to mergedNumbers
    while (leftPos <= leftLast) {
      mergedNumbers[mergePos] = numbers[leftPos];
      leftPos++;
      mergePos++;
    }

    // If right partition isn't empty, add remaining elements to mergedNumbers
    while (rightPos <= rightLast) {
      mergedNumbers[mergePos] = numbers[rightPos];
      rightPos++;
      mergePos++;
    }

    // Copy merged numbers back to numbers
    for (mergePos = 0; mergePos < mergedSize; mergePos++) {
      numbers[leftFirst + mergePos] = mergedNumbers[mergePos];
    }

    // Free temporary array
    delete[] mergedNumbers;
  }
};

#endif