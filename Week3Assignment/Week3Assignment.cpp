// Week3Assignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include<sstream>

using namespace std;

class Student
{
public:
    string firstName;
    string lastName;
    int grade;
};

Student BreakStringIntoStudent(string line);

void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)

        for (j = 0; j < n - i - 1; j++)
            if (arr[j] < arr[j + 1])
                swap(arr[j], arr[j + 1]);
}



void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    vector <Student> students;

    ifstream myfile ("test.txt.txt");
    
    string currentLine;
    int i;
    double sum = 0, avg;

    
    if (myfile.is_open())
    {
        while (getline(myfile, currentLine))
        {
            Student s = BreakStringIntoStudent(currentLine);
            students.push_back(s);
        }
    }
    else
        cout << "Unable to open file\n";
    
    for (int i = 0; i < students.size(); i++)
    {
        cout << students[i].firstName << " " << students[i].lastName << " " << students[i].grade << endl;
    }

    
    int arr[] = { 93, 84, 95, 74, 82, 71 };
    int N = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, N);
    cout << "Sorted array: \n";
    printArray(arr, N);
    
    for (i = 0; i < N; i++)
        sum += arr[i];
    avg = sum / N;
    cout << "Average: " << avg;
    
    return 0;
    

}

Student BreakStringIntoStudent(string line)
{
    vector <string> students;
 
    string grade;

    stringstream s_stream(line);
    while (s_stream.good()) 
    {
        string substr;
        getline(s_stream, substr, ' ');
        students.push_back(substr);
    }

    int i;
    istringstream(students[2]) >> i;


    
    Student s;
    s.firstName = students[0];
    s.lastName = students[1];
    s.grade = i;

    return s;
}
