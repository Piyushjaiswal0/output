#include <iostream>
#include <vector>
#include <omp.h>

// Parallel reduction for finding the minimum value
int parallelMin(const std::vector<int>& data) {
    int min_val = data[0];

    #pragma omp parallel for reduction(min: min_val)
    for (int i = 1; i < data.size(); ++i) {
        if (data[i] < min_val) {
            min_val = data[i];
        }
    }

    return min_val;
}

// Parallel reduction for finding the maximum value
int parallelMax(const std::vector<int>& data) {
    int max_val = data[0];

    #pragma omp parallel for reduction(max: max_val)
    for (int i = 1; i < data.size(); ++i) {
        if (data[i] > max_val) {
            max_val = data[i];
        }
    }

    return max_val;
}

// Parallel reduction for finding the sum
int parallelSum(const std::vector<int>& data) {
    int sum = 0;

    #pragma omp parallel for reduction(+: sum)
    for (int i = 0; i < data.size(); ++i) {
        sum += data[i];
    }

    return sum;
}

// Parallel reduction for finding the average
double parallelAverage(const std::vector<int>& data) {
    int sum = parallelSum(data);
    return static_cast<double>(sum) / data.size();
}

int main() {
    std::vector<int> numbers = {1, 5, 3, 8, 2, 9, 4, 7, 6};

    int min_val = parallelMin(numbers);
    int max_val = parallelMax(numbers);
    int sum = parallelSum(numbers);
    double average = parallelAverage(numbers);

    std::cout << "Min: " << min_val << std::endl;
    std::cout << "Max: " << max_val << std::endl;
    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Average: " << average << std::endl;

    return 0;
}