#include <stdio.h>
int main(void)
{
    int IDEAL_METRIC_METER;
    float car_length;
    char _char;
    scanf("%d", &IDEAL_METRIC_METER);
    scanf("%f", &car_length);
    flushall();
    scanf("%c", &_char);
    printf("%d\n", IDEAL_METRIC_METER);
    printf("%f\n", car_length);
    printf("%c\n\n", _char);
    return 0;
}