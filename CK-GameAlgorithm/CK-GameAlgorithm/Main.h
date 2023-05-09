#pragma once
#include <time.h>
#include <algorithm>
#include <chrono>

#include "ArrayList.h"
#include "ArrayStack.h"
#include "ArrayQueue.h"
#include "Selection.h"
#include "Bubble.h"
#include "Insertion.h"
#include "Merge.h"
#include "Quick.h"
#include "Shell.h"
#include "LinearInterpolationSearch.h"

using namespace std;

template <class T>
int SelectionSort(T data[], int size);

template <class T>
int BubbleSort(T data[], int size);

template <class T>
int InsertionSort(T data[], int size);

template <class T>
int MergeSort(T data[], int size);

template <class T>
int QuickSort(T data[], int size);

template <class T>
int ShellSort(T data[], int size);