#include <stdio.h>
#include <string.h>
#include <stdlib.h>
float fadd_byValue(float a_firstValue, float a_secondValue)
{
    float a_resultValue;
    a_firstValue  += 41.0f;
    a_secondValue += 1.0f;
    a_resultValue = a_firstValue + a_secondValue;
    return a_resultValue;
}

float fadd_byAddress(float *a_firstValue, float *a_secondValue)
{
    float a_resultValue;
    *a_firstValue  += 41.0f;
    *a_secondValue += 1.0f;
    a_resultValue = *a_firstValue + *a_secondValue;
    return a_resultValue;
}

int main(void)
{
    float m_firstValue = 0.0f, m_secondValue = 0.0f;
    float m_resultValue;

    printf("Pass arguments by VALUE:\n");

    printf("before: m_firstValue=%lf\n", m_firstValue);
    printf("before: m_secondValue=%lf\n", m_secondValue);
    m_resultValue = fadd_byValue(m_firstValue, m_secondValue);
    printf("Result = %lf\n", m_resultValue);
    printf("after: m_firstValue=%lf\n", m_firstValue);
    printf("after: m_secondValue=%lf\n\n", m_secondValue);

    printf("Pass arguments by ADDRESS:\n");

    printf("before: m_firstValue=%lf\n", m_firstValue);
    printf("before: m_secondValue=%lf\n", m_secondValue);
    m_resultValue = fadd_byAddress(&m_firstValue, &m_secondValue);
    printf("Result = %lf\n", m_resultValue);
    printf("after: m_firstValue=%lf\n", m_firstValue);
    printf("after: m_secondValue=%lf\n", m_secondValue);

    return 0;
}
