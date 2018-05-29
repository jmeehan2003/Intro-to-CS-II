#include <iostream>
#include <fstream>
#include <array>
#include <string>
using std::cout;
using std::endl;
using std::cin;

int simpleSearch(std::string file,int arr[]);
void selectionSort(int arr[], int size);
void binarySearch(int target, int arr[], int first, int last);

int main () 
{
	int numArr[100];
	int earlyArr[100];
	int middleArr[100];
	int endArr[100];

	std::string numFile = "num.txt";
	std::string earlyFile = "early.txt";
	std::string middleFile = "middle.txt";
	std::string endFile = "end.txt";
		
	int numSize = simpleSearch(numFile, numArr);	
	int earlySize = simpleSearch(earlyFile, earlyArr); 	
	int middleSize = simpleSearch(middleFile, middleArr); 	
	int endSize = simpleSearch(endFile, endArr); 	

	selectionSort(numArr, numSize);
	selectionSort(earlyArr, earlySize);
	selectionSort(middleArr, middleSize);
	selectionSort(endArr, endSize);

	int crazyArr[100];
	std::string crazy = "crazy.txt";
	int crSize = simpleSearch(crazy, crazyArr);
	selectionSort(crazyArr, crSize);

	int target;
	cout << "What is the target value we are searching for?" << endl;
	cin >> target;

	for (int i = 0; i < crSize; i++)
		cout << crazyArr[i] << " ";
	cout << endl;

	binarySearch(target, crazyArr, 0, crSize - 1);
	binarySearch(target, numArr, 0, numSize - 1);
	binarySearch(target, earlyArr, 0, earlySize - 1);
	binarySearch(target, middleArr, 0, middleSize - 1);
	binarySearch(target, endArr, 0, endSize - 1);


	return 0;
}

int simpleSearch(std::string file, int arr[])
{
	std::ifstream infile(file.c_str());
	if(!infile)
	{
		cout << "Error opening file " << file << endl;
		exit(-1);
	}	

	int size = 0;
	while(infile >> arr[size])
	{
		size++;
	}

//	for (int i = 0; i < size; i++)
//		cout << arr[i] << " ";
//	cout << endl;
	int target;
	cout << "What is the target value we are searching for?" << endl;
	cin >> target;
	// input validation needed
	bool found = false;
	for(int i = 0; i < size; i++)
	{
		if(target == arr[i])
		{
			found = true;
			break;
		}
	}
	
	if (found)
		cout << file << ": target value of " << target << " FOUND!" << endl;
	else
		cout << file << ": target value of " << target << " NOT found." << endl;
	
	cout << file << "size is " << size << endl;
	return size;	
}

void selectionSort(int arr[], int size)
{
	cout << "The unsorted array is: " << endl;
	for (int a = 0; a < size; a++)
		cout << arr[a] << " ";
	cout << endl << endl;

	for(int i = 0; i < size; i++)
	{
		int min = arr[i];
		int minPos = i;
		for (int j =  i + 1; j < size; j++)
		{
			if (arr[j] < min)
			{
				min = arr[j];
				minPos = j;
			}
		}
		
		if (minPos != i)
		{
			int temp = arr[i];
			arr[i] = arr[minPos];	
			arr[minPos] = temp;
		}		

	}
	
	cout << "The sorted array is: " << endl;
	for (int a = 0; a < size; a++)
		cout << arr[a] << " ";
	cout << endl;
}

void binarySearch(int target, int arr[], int first, int last)
{
//	cout << "first: " << first << "   last: " << last << endl;
	if (first > last)
	{
		cout << "Target value " << target << " NOT found." << endl;
		return;
	}
	
	int middle = (first + last)/2;	
//	cout << "middle: " << middle << "   array[middle]: " << arr[middle] << endl;

	if (arr[middle] == target)
	{
		cout << "Target value of " << target << " FOUND!" << endl;
		return;
	}
	else if (target < arr[middle])
		binarySearch(target, arr, first, middle - 1);
	else 
		binarySearch(target, arr, middle + 1, last);
	
}
