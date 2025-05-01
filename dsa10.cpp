/*Read the marks obtained by students of second year in an online examination of
particular subject. Find out maximum and minimum marks obtained in that subject. Use
heap data structure. Analyze the algorithm.*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {
int n;
cout << "Enter number of students: ";
cin >> n; 
priority_queue<int>maxHeap;
priority_queue<int, 
vector<int>, 
greater<int>>minHeap;
cout << "Enter marks of " << n << " students:\n";
for (int i = 0; i < n; i++) {
	int mark;
	cin >> mark;
	maxHeap.push(mark);
	minHeap.push(mark);
}
cout << "Maximum marks: " << maxHeap.top() << endl;
cout << "Minimum marks: " << minHeap.top() << endl;
return 0;
}
