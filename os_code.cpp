
// C++ program to implement Shortest Job first with Arrival
// Time
#include <iostream>
using namespace std;
int input[10][6];
// helper function to swap to integers
void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
//Arranging all the processes based on their arrival time
void arrangeArrival(int num, int input[][6])
{
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num - i - 1; j++) {
			if (input[j][1] > input[j + 1][1]) {
				for (int k = 0; k < 3; k++) {
					swap(input[j][k], input[j + 1][k]);
				}
			}
		}
	}
}
//function to calculate completion time, turnaround time and waiting time
void completionTime(int num, int input[][6])
{
	int temp, val;
	input[0][3] = input[0][1] + input[0][2];
	input[0][5] = input[0][3] - input[0][1];
	input[0][4] = input[0][5] - input[0][2];
    //calculation of process with shortest burst time
	for (int i = 1; i < num; i++) {
		temp = input[i - 1][3];
		int low = input[i][2];
		for (int j = i; j < num; j++) {
			if (temp >= input[j][1] && low >= input[j][2]) {
				low = input[j][2];
				val = j;
			}
		}
        //updating the completion time, turnaround time and
        //waiting time of process with shortest burst time
		input[val][3] = temp + input[val][2];
		input[val][5] = input[val][3] - input[val][1];
		input[val][4] = input[val][5] - input[val][2];
        //swapping the process that has completed it's execution

		for (int k = 0; k < 6; k++) {
			swap(input[val][k], input[i][k]);
		}
	}
}

int main()
{
    //inputting the arrival time , burst time .
	int num, temp;

	cout << "Enter number of Process: ";
	cin >> num;

	cout << "...Enter the process ID...\n";
	for (int i = 0; i < num; i++) {
		cout << "...Process " << i + 1 << "...\n";
		cout << "Enter Process Id: ";
		cin >> input[i][0];
		cout << "Enter Arrival Time: ";
		cin >> input[i][1];
		cout << "Enter Burst Time: ";
		cin >> input[i][2];
	}

	cout << "Before Arrange...\n";
	cout << "Process ID\tArrival Time\tBurst Time\n";
	for (int i = 0; i < num; i++) {
		cout << input[i][0] << "\t\t" << input[i][1] << "\t\t"
			<< input[i][2] << "\n";
	}
    //sorting all the processes on the basis of arrival time
    arrangeArrival(num, input);
    cout<<"After arranging on the basis of arrival time\n";
    cout << "Process ID\tArrival Time\tBurst Time\n";
    for (int i = 0; i < num; i++) {
		cout << input[i][0] << "\t\t" << mat[i][1] << "\t\t"
			<< input[i][2] << "\n";
	}
	cout<<endl;
    //invoking fucntion to calculate completion ,turnaround and
    //waiting time
	completionTime(num, input);

	cout << "Final Result...\n";
	cout << "Process ID\tArrival Time\tBurst Time\tCompletion Time\tWaiting "
			"Time\tTurnaround Time\n";
	for (int i = 0; i < num; i++) {
		cout << input[i][0] << "\t\t" << input[i][1] << "\t\t"
			<< input[i][2] <<"\t\t"<<input[i][3]<< "\t\t" << input[i][4] << "\t\t"
			<< input[i][5] << "\n";
	}
}
