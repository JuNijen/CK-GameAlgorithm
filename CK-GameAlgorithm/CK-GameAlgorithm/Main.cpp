#include "Main.h"


int main() 
{
	// ���� ���� ����
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

	// ������ ���� ����
	enum DATA_TYPE 
	{
		DATA_NONE = 0,
		DATA_RANDOM,
		DATA_ASC,
		DATA__DESC,
		DATA_MAX,
	};

	// ǥ��� ���� ������
	const string amountGuideText = "\n������ ������ �Է��ϼ��� >> ";
	const string sortGuideText = "\n���� ����� �����ϼ��� >> \n";
	const string dataGuideText = "\n������ ����� �����ϼ��� >> ";
	const string dataType[3] = { "�õ� ���� ����", "��������", "��������" };
	const string sortingType[6] = { "���� ����", "���� ����", "���� ����", "�պ� ����", "�� ����", "�� ����"};

	// ������ ������
	//clock_t start = clock();
	int dataSelection, sortSelection, size, time = 0;
	int data[100000];

	do
	{
		// ������ ���� �Է� �ȳ� �� �Է��� ���� ������ ���� ����
		cout << amountGuideText;
		cin >> size;

		// ������ ������ ������ŭ ������ �����͸� ���� (�񱳸� ���� �õ� ����)
		srand(12345);
		for (int i = 0; i < size; i++)
		{
			data[i] = rand();
		}

		// ������ ���� �ȳ� �� �Է��� ���� ���� ���� ����
		for (int i = 0; i < DATA_MAX - 1; i++)
		{
			cout << i + 1 << " : " << dataType[i] << "\n";
		}
		cout << dataGuideText;
		cin >> dataSelection;

		// ������ ������ ������ ���� �����͸� ���� ����
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
		//cout << "\n������ ���� �Ϸ� - TIME : " << TIME << "ms\n"; /* ms ������ ��� */

		/*
		// ������ ���� ��� �Է� �ȳ� �� �Է��� ���� ������ ���� ��� ����
		cout << sortGuideText;
		for (int i = 0; i < SORT_MAX - 1; i++)
		{
			cout << i + 1 << " : " << sortingType[i] << "\n";
		}
		cin >> sortSelection;

		// ���� �ð� ���� �غ� �۾�
		time = 0;
		start = clock();
		

		// ���� ������ ���� ���� ó��
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

		// ���� �ð� ���� �غ� �۾�
		time = 0;
		start = clock();
		// ���Ŀ� �ҿ�� �ð� ǥ��
		time += ((int)clock() -start) / (clocks_per_sec / 1000);
		cout << "������ ���� �Ϸ� - time : " << time << "ms\n";
		*/

		// ���� �ð� ���� �غ� �۾�
		auto startTime = std::chrono::system_clock::now();
		SelectionSort(data, size);
		// ���Ŀ� �ҿ�� �ð� ǥ��
		auto endTime = std::chrono::system_clock::now();
		auto sec = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
		cout << "���� ���� �Ϸ� - TIME : " << sec.count() << "ms\n"; /* ms ������ ��� */

		// ���� �ð� ���� �غ� �۾�
		startTime = std::chrono::system_clock::now();
		BubbleSort(data, size);
		// ���Ŀ� �ҿ�� �ð� ǥ��
		endTime = std::chrono::system_clock::now();
		sec = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
		cout << "���� ���� �Ϸ� - TIME : " << sec.count() << "ms\n"; /* ms ������ ��� */

		// ���� �ð� ���� �غ� �۾�
		startTime = std::chrono::system_clock::now();
		InsertionSort(data, size);
		// ���Ŀ� �ҿ�� �ð� ǥ��
		endTime = std::chrono::system_clock::now();
		sec = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
		cout << "���� ���� �Ϸ� - TIME : " << sec.count() << "ms\n"; /* ms ������ ��� */

		// ���� �ð� ���� �غ� �۾�
		startTime = std::chrono::system_clock::now();
		MergeSort(data, size);
		// ���Ŀ� �ҿ�� �ð� ǥ��
		endTime = std::chrono::system_clock::now();
		sec = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
		cout << "�պ� ���� �Ϸ� - TIME : " << sec.count() << "ms\n"; /* ms ������ ��� */

		// ���� �ð� ���� �غ� �۾�
		startTime = std::chrono::system_clock::now();
		QuickSort(data, size);
		// ���Ŀ� �ҿ�� �ð� ǥ��
		endTime = std::chrono::system_clock::now();
		sec = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
		cout << "�� ���� �Ϸ� - TIME : " << sec.count() << "ms\n"; /* ms ������ ��� */

		// ���� �ð� ���� �غ� �۾�
		startTime = std::chrono::system_clock::now();
		ShellSort(data, size);
		// ���Ŀ� �ҿ�� �ð� ǥ��
		endTime = std::chrono::system_clock::now();
		sec = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
		cout << "�� ���� �Ϸ� - TIME : " << sec.count() << "ms\n"; /* ms ������ ��� */
	}
	// 0�� �Է��� �� ���α׷��� �����
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
//	cout << "����� :: "  << lsearch.searching(12316);
//
//	return 0;
//}