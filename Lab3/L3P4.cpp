#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of values: ";
    cin >> n;

    // Dynamically allocate an array of floating-point values.
    float *arr = new float[n];
    float sum = 0.0f;

    cout << "Enter " << n << " numbers:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    float average = sum / n;

    cout << fixed << setprecision(2);
    cout << "Sum = " << sum << endl;
    cout << "Average = " << average << endl;

    // Release the dynamically allocated array.
    delete[] arr;
    arr = nullptr;

    return 0;
}
