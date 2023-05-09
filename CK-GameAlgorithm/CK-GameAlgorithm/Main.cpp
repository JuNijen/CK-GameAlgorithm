#include "Main.h"


int main() 
{
	// 정렬 유형 구분
	enum SORT_TYPE
	{
		SORT_NONE = 0,
		SORT_SELECTION,
		SORT_BUBBLE,
		SORT_INSERTION,
		SORT_MERGE,
		SORT_QUICK,
		SORT_SHELL,
		SORT_MAX,
	};

	// 데이터 유형 구분
	enum DATA_TYPE 
	{
		DATA_NONE = 0,
		DATA_RANDOM,
		DATA_ASC,
		DATA__DESC,
		DATA_MAX,
	};

	// 표기용 고정 데이터
	const string amountGuideText = "\n정렬할 수량을 입력하세요 >> ";
	const string sortGuideText = "\n정렬 방식을 선택하세요 >> \n";
	const string dataGuideText = "\n데이터 방식을 선택하세요 >> ";
	const string dataType[3] = { "시드 기준 랜덤", "오름차순", "내림차순" };
	const string sortingType[6] = { "선택 정렬", "버블 정렬", "삽입 정렬", "합병 정렬", "퀵 정렬", "셀 정렬"};

	// 가변형 데이터
	//clock_t start = clock();
	int dataSelection, sortSelection, size, time = 0;
	int data[100000];

	do
	{
		// 데이터 수량 입력 안내 및 입력을 통한 데이터 수량 지정
		cout << amountGuideText;
		cin >> size;

		// 지정된 데이터 수량만큼 랜덤한 데이터를 생성 (비교를 위한 시드 고정)
		srand(12345);
		for (int i = 0; i < size; i++)
		{
			data[i] = rand();
		}

		// 데이터 유형 안내 및 입력을 통한 정렬 유형 지정
		for (int i = 0; i < DATA_MAX - 1; i++)
		{
			cout << i + 1 << " : " << dataType[i] << "\n";
		}
		cout << dataGuideText;
		cin >> dataSelection;

		// 지정된 데이터 유형에 따라 데이터를 사전 가공
		switch (dataSelection)
		{
		case DATA_ASC:
			sort(data, data + size);
			break;

		case DATA__DESC:
			sort(data, data + size, greater<>());
			break;

		default:
			break;
		}
		//TIME += ((int)clock() -start) / (CLOCKS_PER_SEC / 1000);
		//cout << "\n데이터 생성 완료 - TIME : " << TIME << "ms\n"; /* ms 단위로 출력 */

		/*
		// 데이터 정렬 방식 입력 안내 및 입력을 통한 데이터 정렬 방식 지정
		cout << sortGuideText;
		for (int i = 0; i < SORT_MAX - 1; i++)
		{
			cout << i + 1 << " : " << sortingType[i] << "\n";
		}
		cin >> sortSelection;

		// 정렬 시간 측정 준비 작업
		time = 0;
		start = clock();
		

		// 정렬 유형에 따른 정렬 처리
		switch (sortselection)
		{
		case sort_selection:
			selectionsort(data, size);
			break;

		case sort_bubble:
			bubblesort(data, size);
			break;

		case sort_insertion:
			insertionsort(data, size);
			break;

		case sort_merge:
			mergesort(data, size);
			break;

		case sort_quick:
			quicksort(data, size);
			break;

		case sort_shell:
			shellsort(data, size);
			break;

		default:
			break;
		}

		// 정렬 시간 측정 준비 작업
		time = 0;
		start = clock();
		// 정렬에 소요된 시간 표기
		time += ((int)clock() -start) / (clocks_per_sec / 1000);
		cout << "데이터 정렬 완료 - time : " << time << "ms\n";
		*/

		// 정렬 시간 측정 준비 작업
		auto startTime = std::chrono::system_clock::now();
		SelectionSort(data, size);
		// 정렬에 소요된 시간 표기
		auto endTime = std::chrono::system_clock::now();
		auto sec = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
		cout << "선택 정렬 완료 - TIME : " << sec.count() << "ms\n"; /* ms 단위로 출력 */

		// 정렬 시간 측정 준비 작업
		startTime = std::chrono::system_clock::now();
		BubbleSort(data, size);
		// 정렬에 소요된 시간 표기
		endTime = std::chrono::system_clock::now();
		sec = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
		cout << "버블 정렬 완료 - TIME : " << sec.count() << "ms\n"; /* ms 단위로 출력 */

		// 정렬 시간 측정 준비 작업
		startTime = std::chrono::system_clock::now();
		InsertionSort(data, size);
		// 정렬에 소요된 시간 표기
		endTime = std::chrono::system_clock::now();
		sec = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
		cout << "삽입 정렬 완료 - TIME : " << sec.count() << "ms\n"; /* ms 단위로 출력 */

		// 정렬 시간 측정 준비 작업
		startTime = std::chrono::system_clock::now();
		MergeSort(data, size);
		// 정렬에 소요된 시간 표기
		endTime = std::chrono::system_clock::now();
		sec = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
		cout << "합병 정렬 완료 - TIME : " << sec.count() << "ms\n"; /* ms 단위로 출력 */

		// 정렬 시간 측정 준비 작업
		startTime = std::chrono::system_clock::now();
		QuickSort(data, size);
		// 정렬에 소요된 시간 표기
		endTime = std::chrono::system_clock::now();
		sec = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
		cout << "퀵 정렬 완료 - TIME : " << sec.count() << "ms\n"; /* ms 단위로 출력 */

		// 정렬 시간 측정 준비 작업
		startTime = std::chrono::system_clock::now();
		ShellSort(data, size);
		// 정렬에 소요된 시간 표기
		endTime = std::chrono::system_clock::now();
		sec = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
		cout << "쉘 정렬 완료 - TIME : " << sec.count() << "ms\n"; /* ms 단위로 출력 */
	}
	// 0을 입력할 시 프로그램이 종료됨
	while (size != 0);//&& sortSelection != 0);


	return 0;
}

//int main()
//{
//	arrayList<int>* list = new arrayList<int>(100);
//
//	list->insert(0, 1);
//	list->insert(1, 2);
//	list->insert(2, 4);
//	list->insert(1, 5);
//
//	cout << list->retrieve(0);
//	cout << list->retrieve(1);
//	cout << list->retrieve(2);
//	cout << list->retrieve(3) << "\n";
//	list->remove(1);
//
//	cout << list->retrieve(0);
//	cout << list->retrieve(1);
//	cout << list->retrieve(2);
//}

//int main()
//{
//	ArrayStack<int>* stack = new ArrayStack<int>(100);
//
//	cout << stack->isEmpty();
//
//	stack->push(1);
//	stack->push(2);
//	stack->push(3);
//	stack->push(4);
//	cout << stack->isEmpty();
//
//	cout << stack->getTop();
//	stack->pop();
//	cout << stack->getTop();
//	stack->pop();
//	cout << stack->getTop();
//	stack->pop();
//
//	cout << stack->isEmpty();
//	cout << stack->isFull();
//
//	return 0;
//}

//int main()
//{
//	ArrayQueue<int>* queue = new ArrayQueue<int>(100);
//
//	cout << queue->empty();
//
//	queue->push(1);
//	queue->push(2);
//	queue->push(3);
//	queue->push(4);
//	cout << queue->empty();
//
//	cout << queue->front();
//	queue->pop();
//	cout << queue->front();
//	queue->pop();
//	cout << queue->front();
//	queue->pop();
//
//	cout << queue->empty();
//	cout << queue->full();
//
//	return 0;
//}

template <class T>
int SelectionSort(T data[], int size)
{
	Selection<T> selectionSort;

	selectionSort.initData(data, size);
	selectionSort.sorting();
	//selectionSort.printAll();

	return 0;
}

template <class T>
int BubbleSort(T data[], int size)
{
	Bubble<T> bubbleSort;

	bubbleSort.initData(data, size);
	bubbleSort.sorting();
	//bubbleSort.printAll();

	return 0;
}

template <class T>
int InsertionSort(T data[], int size)
{
	Insertion<T> insertionSort;

	insertionSort.initData(data, size);
	insertionSort.sorting();
	//insertionSort.printAll();

	return 0;
}

template <class T>
int MergeSort(T data[], int size) 
{
	Merge<T> mergeSort;

	mergeSort.initData(data, size);
	mergeSort.sorting();
	//mergeSort.printAll();

	return 0;
}

template <class T>
int QuickSort(T data[], int size)
{
	Quick<T> quickSort;

	quickSort.initData(data, size);
	quickSort.sorting();
	//quickSort.printAll();

	return 0;
}

template <class T>
int ShellSort(T data[], int size)
{
	Shell<T> shellSort;

	shellSort.initData(data, size);
	shellSort.sorting();
	//shellSort.printAll();

	return 0;

}

//int main()
//{
//	int data[100];
//	Shell<int> shellSort;
//	LinearInterpolation<int> lsearch;
//
//	data[0] = 50;
//	for (int i = 1; i < 100; i++)
//	{
//		data[i] = rand();
//	}
//
//	shellSort.initData(data, 100);
//	shellSort.sorting();
//	shellSort.printAll();
//
//	lsearch.initData(shellSort.getData(), 100);
//	cout << "결과값 :: "  << lsearch.searching(12316);
//
//	return 0;
//}