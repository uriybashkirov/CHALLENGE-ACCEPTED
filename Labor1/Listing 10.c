#include <stdio.h>
int main(void)
{
    // before
    int IDEAL_METRIC_METER = 1;
    float PI = 3.14;
    char CHAR = 'A';

    printf("%d\n", IDEAL_METRIC_METER);
    printf("%f\n", PI);
    printf("%c\n\n", CHAR);

    // after
    IDEAL_METRIC_METER = 2;
    PI = 3.15;
    CHAR = 'B';

    printf("%d\n", IDEAL_METRIC_METER);
    printf("%f\n", PI);
    printf("%c\n", CHAR);

    return 0;
}