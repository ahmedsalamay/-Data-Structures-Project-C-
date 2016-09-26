#include<iostream>
#include<string>

using namespace std;

class Restaurant {
public:
	string name;
	int rating;
	double distance;
	Restaurant(string n, int r, double d)
	{
		name = n;
		rating = r;
		distance = d;

	}
	Restaurant()
	{
		name = " ";
		rating =0 ;
		distance = 0.0;

	}
	Restaurant operator=(const Restaurant & R);
	friend istream& operator>>(istream&in,Restaurant &r);
	friend ostream& operator<<(ostream&out, Restaurant &r);

};
Restaurant Restaurant :: operator=(const Restaurant & R)
{
	this->name = R.name;
	this->rating = R.rating;
	this->distance = R.distance;
	return *this;
}
istream& operator>>(istream&in, Restaurant &r)
{
	in >> r.name;
	in >> r.rating;
	in >> r.distance;
	return in;
}
ostream& operator<<(ostream&out, Restaurant &r)
{
	out<< r.name<<endl;
	out<< r.rating<<endl;
	out<< r.distance<<endl;
	return out;
}
//////////////////////////////////////////
void swap(int first, int second,Restaurant R[])
{
	Restaurant temp;
	temp = R[first];	
	R[first] = R[second];
	R[second] = temp;
}
int minLocation(int first, int last,Restaurant R[])
{
	int minIndex, length = 8;
	minIndex = first;
 
		for (int loc = first + 1; loc <= last; loc++)
			if (R[loc].rating > R[minIndex].rating||(R[loc].rating==R[minIndex].rating&&R[loc].distance<R[minIndex].distance))
				minIndex = loc;
	return minIndex;
} //end minLocation

void selectionSort(Restaurant R[])
{
	int length = 8;

	int minIndex;
	for (int loc = 0; loc < length - 1; loc++)
	{
		minIndex = minLocation(loc, length - 1,R);
		swap(loc, minIndex,R);
	}
}
int main()
{
	Restaurant r[8];
	for (int i = 0; i < 8; i++)
		cin >> r[i];

	selectionSort( r);

	
	
	for (int i = 0; i < 8; i++)
		cout<< r[i]<<endl;
	
	

	return 0;
}

/*
void insertOrd(double item,int length)
{
	int first = 0;
	int last = length - 1;
	int mid;
	bool found = false;
	if (length == 0) //the list is empty
	{
		list[0] = item;
		length++;
	}
	else if (length == maxSize)
		cerr << "Cannot insert into a full list." << endl;
	else
	{
		while (first <= last && !found)
		{
			mid = (first + last) / 2;
			if (list[mid] == item)
				found = true;
			else if (list[mid] > item)
				last = mid - 1;
			else
				first = mid + 1;
		}//end while
		if (found)
			cerr << "The insert item is already in the list. "
			<< "Duplicates are not allowed." << endl;
		else
			9
			Search Algorithms | 507
		{
			if (list[mid] < item)
				mid++;
			insertAt(mid, item);
		}
	}
}//end insertOrd

*/



/*int partition(int first, int last, Restaurant R[])
{
int pivot;
int index, smallIndex;
swap(first, (first + last) / 2,R);
pivot = R[first].rating;
smallIndex = first;
for (index = first + 1; index <= last; index++)
if (R[index].rating < pivot)
{
smallIndex++;
swap(smallIndex, index);
}
swap(first, smallIndex);
return smallIndex;
}

void recQuickSort(int first, int last, Restaurant R[])
{
int pivotLocation;
if (first < last)
{
pivotLocation = partition(first, last,R);
recQuickSort(first, pivotLocation - 1,R);
recQuickSort(pivotLocation + 1, last,R);
}
}
*/
/**
Restaurant arr[8];
void sort(Restaurant R[], int first, int last)
{
int length = 8;
int curr = 1, min = 0, j = 0;
while (min != last){
for (curr; curr <= last; curr++)
{
if (R[min].rating == R[curr].rating)
{
j++;
arr[0] = R[min];
arr[j] = R[curr];

}
else if (R[min].rating != R[curr].rating)

{
j--;
selectionSort2(arr, j);
for (int i = 0; i < j; i++)
{
R[i] = arr[i];
}
min = curr; curr += 1; j = 0;
break;
}
}
}


}
*/
/////////////////////////////////////////