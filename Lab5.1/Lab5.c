#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to hold the month and sales data
struct MonthlyData {
    char month[20];
    double sales;
};

// Function to calculate the average of sales
double calculateAverage(double sales[], int numMonths) {
    double sum = 0;
    for (int i = 0; i < numMonths; i++) {
        sum += sales[i];
    }
    return sum / numMonths;
}

// Function to sort monthly data by sales (highest to lowest)
void sortMonthlyData(struct MonthlyData data[], int numMonths) {
    int i, j;
    struct MonthlyData temp;
    for (i = 0; i < numMonths - 1; i++) {
        for (j = i + 1; j < numMonths; j++) {
            if (data[i].sales > data[j].sales) {
                temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }
}

int main() {
    FILE *inputFile = fopen("Sales.txt", "r"); // Replace "sales.txt" with your input file name
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    double sales[12];
    struct MonthlyData monthlyData[12];

    // Read sales data from the input file
    for (int i = 0; i < 12; i++) {
        fscanf(inputFile, "%lf", &sales[i]);
    }
    fclose(inputFile);

    // Create the month names
    const char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    // Initialize monthly data
    for (int i = 0; i < 12; i++) {
        strcpy(monthlyData[i].month, months[i]);
        monthlyData[i].sales = sales[i];
    }

    // Calculate the minimum, maximum, and average sales
    double minSales = sales[0];
    double maxSales = sales[0];
    double avgSales = calculateAverage(sales, 12);

    for (int i = 1; i < 12; i++) {
        if (sales[i] < minSales) {
            minSales = sales[i];
        }
        if (sales[i] > maxSales) {
            maxSales = sales[i];
        }
    }

    // Sort monthly data by sales (highest to lowest)
    sortMonthlyData(monthlyData, 12);

    // Print the reports
    printf("Monthly sales report for 2022:\n");
    for (int i = 0; i < 12; i++) {
        printf("%s $%.2lf\n", monthlyData[i].month, monthlyData[i].sales);
    }

    printf("\nSales summary:\n");
    printf("Minimum sales: $%.2lf (%s)\n", minSales, months[0]);
    printf("Maximum sales: $%.2lf (%s)\n", maxSales, months[11]);
    printf("Average sales: $%.2lf\n", avgSales);

    printf("\nSix-Month Moving Average Report:\n");
    // Calculate and print the moving averages (e.g., average of Jan-Feb, Feb-Mar, Mar-Apr, ...)
    for (int i = 0; i < 12 - 6; i++) {
        double movingAvg = 0;
        for (int j = 0; j < 6; j++) {
            movingAvg += sales[i + j];
        }
        movingAvg /= 6;
        printf("Moving Avg %s-%s: $%.2lf\n", months[i], months[i + 5], movingAvg);
    }

    printf("\nSales Report (Highest to Lowest):\n");
    for (int i = 0; i < 12; i++) {
        printf("%s $%.2lf\n", monthlyData[i].month, monthlyData[i].sales);
    }

    return 0;
}
