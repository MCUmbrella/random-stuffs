#include<stdio.h>
#include<malloc.h>
#include<assert.h>

struct stats
{
    int a = 0, b = 0, c = 0, d = 0, e = 0;
};

char getGrade(double score)
{
    return score >= 90 ? 'a' :
        score >= 80 ? 'b' :
        score >= 70 ? 'c' :
        score >= 60 ? 'd' :
        'e';
}

stats* statistic(double* scores, int scoresLength)
{
    stats s, *sp = &s;
    for(int i = 0; i != scoresLength; i++)
        switch(getGrade(scores[i]))
        {
            case 'a':
            {
                s.a++;
                break;
            }
            case 'b':
            {
                s.b++;
                break;
            }
            case 'c':
            {
                s.c++;
                break;
            }
            case 'd':
            {
                s.d++;
                break;
            }
            case 'e':
                s.e++;
        }
    return sp;
}

int main(int argc, char** argv)
{
    double* scores;
    int scoresLength;

    scanf("%d", &scoresLength);
    assert(scoresLength >= 0);
    scores = (double*)malloc(sizeof(double) * scoresLength);

    for(int i=0; i!=scoresLength; i++)
    {
        double score;
        scanf("%lf", &score);
        assert(score >= 0 && score <= 100);
        scores[i] = score;
    }

    stats* s = statistic(scores, scoresLength);
    printf("A: %d\nB: %d\nC: %d\nD: %d\nE: %d\n", s->a, s->b, s->c, s->d, s->e);
    return 0;
}
