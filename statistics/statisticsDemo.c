#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "statistics.h"

int main(){

    float farr[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    int iarr[] = {1, 2, 3, 4, 5};
    double darr[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    float farr2[] = {2.0, 4.0, 6.0, 8.0, 10.0};
    float fconst[] = {7.0, 7.0, 7.0, 7.0, 7.0};
    int size = 5;

    // Normal tests
    printf("Float Mean: %.2f\n", calcMeanF(farr, size));
    printf("Int Variance: %.2f\n", calcVarianceI(iarr, size));
    printf("Double Std Dev: %.2f\n", calcDevStandardD(darr, size));
    printf("Float Skewness: %.2f\n", calcAsimmetriaF(farr, size));
    printf("Int Kurtosis: %.2f\n", calcCurtosiI(iarr, size));
    printf("Float Covariance: %.2f\n", calcCovarianceF(farr, farr2, size));
    printf("Float Correlation: %.2f\n", calcCoeffCorrelationF(farr, farr2, size));

    // Edge case tests
    float fedge[] = {10.0};
    int iedge[] = {42};
    double dedge[] = {3.14159};

    assert(calcMeanF(fedge, 1) == 10.0f);
    assert(calcMeanI(iedge, 1) == 42.0f);
    assert(fabs(calcMeanD(dedge, 1) - 3.14159f) < 1e-5);
    assert(calcVarianceF(fedge, 1) == 0.0f);
    assert(calcVarianceI(iedge, 1) == 0.0f);
    assert(fabs(calcDevStandardD(dedge, 1)) < 1e-6);

    printf("\nAll tests passed.\n");
    return 0;
}
    