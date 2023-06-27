#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int size;
    double sum;
    double *values;
    int oldest_index;
} MovingAverageFilter;

MovingAverageFilter* create_filter(int size) {
    MovingAverageFilter *filter = malloc(sizeof(MovingAverageFilter));
    filter->size = size;
    filter->sum = 0.0;
    filter->values = calloc(size, sizeof(double));
    filter->oldest_index = 0;
    return filter;
}

void destroy_filter(MovingAverageFilter *filter) {
    free(filter->values);
    free(filter);
}

double update_filter(MovingAverageFilter *filter, double new_value) {
    filter->sum -= filter->values[filter->oldest_index];
    filter->sum += new_value;
    filter->values[filter->oldest_index] = new_value;
    filter->oldest_index = (filter->oldest_index + 1) % filter->size;
    return filter->sum / filter->size;
}

int main() {
    int filter_size = 2;
    MovingAverageFilter *filter = create_filter(filter_size);

    // Sample data
    double input_data[] = {1.0, 1.0, 1.0, 2.0, 2.0, 2.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0};
    int data_length = sizeof(input_data) / sizeof(input_data[0]);

    for(int i = 0; i < data_length; ++i) {
        double new_average = update_filter(filter, input_data[i]);
        printf("New input: %f, Filtered output: %f\n", input_data[i], new_average);
    }

    destroy_filter(filter);
    return 0;
}
