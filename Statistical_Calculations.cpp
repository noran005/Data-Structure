/*
 Author: Noran Mohamed Mokhtar
 ID: 20230451
 Course: Data Structures
 Assignment: Assignment 1
 Group: A
 Section: S5
*/

#include <iostream>
#include <fstream>

using namespace std;

// Template class for statistical calculations on an array of any data type
template<typename T>
class StatisticalCalculation {
private:
    T* data;  // Dynamically allocated array to hold the data for sorting and operations
    int size; // Number of elements in the array
public:
    // Constructor to initialize size and allocate memory for the array
    StatisticalCalculation(int size);

    // Destructor to free the dynamically allocated memory
    ~StatisticalCalculation();

    // Function to sort the array
    void sort();

    // Statistical Calculation Functions
    double findMedian();     // Function to find the median of the array
    T findMin();             // Function to find the minimum value in the array
    T findMax();             // Function to find the maximum value in the array
    double findMean();       // Function to find the mean (average) of the array
    T findSummation();       // Function to find the summation of all elements in the array

    // Utility Functions
    void displayArray();     // Function to display the elements of the array
    void inputData(ifstream &file);  // Function to input data from a file
    void statisticsMenu(ifstream &file);  // Menu to choose operations for statistical calculations
};

// Constructor: Initializes the size and allocates memory for the array
template <typename T>
StatisticalCalculation<T>::StatisticalCalculation(int size) : size(size) {
    data = new T[size]; // Dynamically allocate memory for the array of type T
}

// Destructor: Frees the dynamically allocated memory for the array
template <typename T>
StatisticalCalculation<T>::~StatisticalCalculation() {
    delete[] data; // Free the memory allocated for data
}

// Sort function: Sorts the array in ascending order using Bubble Sort
template <typename T>
void StatisticalCalculation<T>::sort() {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (data[j] > data[j + 1]) {
                // Swap the elements
                T temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}

// Find the median of the array
template <typename T>
double StatisticalCalculation<T>::findMedian() {
    if (size % 2 == 0) {  // If the size is even, calculate the average of the middle two elements
        return (double(data[size / 2]) + double(data[size / 2 - 1])) / 2.0;
    } else {  // If the size is odd, return the middle element
        return data[size / 2];
    }
}

// Find the minimum value in the array
template <typename T>
T StatisticalCalculation<T>::findMin() {
    return data[0];  // Since the array is sorted, the first element is the minimum
}

// Find the maximum value in the array
template <typename T>
T StatisticalCalculation<T>::findMax() {
    return data[size - 1];  // Since the array is sorted, the last element is the maximum
}

// Find the mean (average) of the array
template <typename T>
double StatisticalCalculation<T>::findMean() {
    return double(findSummation()) / size;  // The mean is the summation divided by the size
}

// Find the summation of all elements in the array
template <typename T>
T StatisticalCalculation<T>::findSummation() {
    T sum = 0;
    for (int i = 0; i < size; i++) {
        sum += data[i];  // Sum up all elements in the array
    }
    return sum;
}

// Display the sorted array
template <typename T>
void StatisticalCalculation<T>::displayArray() {
    for (int i = 0; i < size; i++) {
        cout << data[i] << " ";  // Print each element of the sorted array
    }
    cout << endl;  // Move to the next line after displaying all elements
}

// Input data from the file and sort it
template <typename T>
void StatisticalCalculation<T>::inputData(ifstream &file) {
    for (int i = 0; i < size; i++) {
        file >> data[i];  // Read each element from the file and store it in the array
    }
    sort();  // Sort the data after loading it
    cout << "Data successfully loaded and sorted" << endl;  // Inform the user that the data was loaded and sorted
}

// Display a menu for statistical operations and process the user's choices from the file
template <typename T>
void StatisticalCalculation<T>::statisticsMenu(ifstream &file) {
    int choice;
    while (file >> choice) {  // Read the user's choice for the operation from the file
        cout << "Operation " << choice << ": ";  // Display the operation number

        if (choice == 7) {  // If the choice is 7, exit the loop and end the test case
            cout << "Exiting this test case." << endl;
            break;
        }

        // Perform the appropriate operation based on the user's choice
        if (choice == 1) {
            cout << "Displaying sorted elements: ";
            displayArray();  // Display the sorted array
        } else if (choice == 2) {
            cout << "Median = " << findMedian() << endl;  // Display the median
        } else if (choice == 3) {
            cout << "Minimum = " << findMin() << endl;  // Display the minimum value
        } else if (choice == 4) {
            cout << "Maximum = " << findMax() << endl;  // Display the maximum value
        } else if (choice == 5) {
            cout << "Mean = " << findMean() << endl;  // Display the mean value
        } else if (choice == 6) {
            cout << "Summation = " << findSummation() << endl;  // Display the summation of the elements
        }
    }
}

// Main function: Reads input data, runs test cases, and performs statistical operations
int main() {
    ifstream file("input.txt");  // Open the input file
    if (!file.is_open()) {  // Check if the file is open
        cout << "Error opening input.txt" << endl;
        return 1;  // Return error code 1 if the file couldn't be opened
    }

    int test_case_number = 1;  // Initialize the test case number
    int data_type, size;  // Variables to store the data type and size of the array

    // Process each test case from the file
    while (file >> data_type >> size) {
        cout << "\n===== Running Test Case " << test_case_number++ << " ===== " << endl;  // Display the test case number
        cout << "Data Size: " << size << endl;  // Display the size of the data

        // Based on the data type, create the appropriate StatisticalCalculation object
        if (data_type == 1) {
            cout << "Data Type: Integer" << endl;
            StatisticalCalculation<int> stats(size);  // Integer type data
            stats.inputData(file);
            stats.statisticsMenu(file);
        } else if (data_type == 2) {
            cout << "Data Type: Double" << endl;
            StatisticalCalculation<double> stats(size);  // Double type data
            stats.inputData(file);
            stats.statisticsMenu(file);
        } else if (data_type == 3) {
            cout << "Data Type: Float" << endl;
            StatisticalCalculation<float> stats(size);  // Float type data
            stats.inputData(file);
            stats.statisticsMenu(file);
        }
    }
    file.close();  // Close the input file after processing all test cases
    return 0;
}
