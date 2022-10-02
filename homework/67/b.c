#include<stdio.h>
#include<assert.h>

#define LIMIT 120.0

/**
 * @param speed 车速
 * @return 0：不处罚；1：200元罚款；2：吊销驾驶证
 */
char getPenalty(double speed)
{
    return speed > LIMIT*1.5 ? 2 :
        speed > LIMIT*1.1 ? 1 :
        0;
}

int main(int argc, char** argv)
{
    double speed;
    scanf("%lf", &speed);
    assert(speed >= 0);
    switch(getPenalty(speed))
    {
        case 0:
        {
            puts("不处罚");
            break;
        }
        case 1:
        {
            puts("200元罚款");
            break;
        }
        case 2:
        {
            puts("吊销驾驶证");
        }
    }
    return 0;
}
