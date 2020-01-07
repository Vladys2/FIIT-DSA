#include <stdio.h>
#include <string.h>

char *tempdata1[10000];
char *tempdata2[10000];
char *pathfinder[10000];
int collumn, row;

int mazeL(int x, int y)
{
    if(x == row && y == collumn - 2)
        return 0;

    if((x >= 0) && (x < row) && (y >= 0) && (y < collumn) && (tempdata1[x][y] == '.')) {
        tempdata1[x][y]='*';

        if (mazeL(x-1, y) == 0)
            return 0;

        if (mazeL(x, y+1) == 0)
            return 0;

        if (mazeL(x+1, y) == 0)
            return 0;

        if (mazeL(x, y-1) == 0)
            return 0;

        tempdata1[x][y]='.';
        return 1;
    }
    return 1;
}

int mazeR(int x, int y)
{

    if(x == row && y == collumn - 2)
        return 0;

    if((x >= 0) && (x < row) && (y >= 0) && (y < collumn) && (tempdata2[x][y] == '.')) 
    {
        tempdata2[x][y]='*';

        if(tempdata2[x][y] == tempdata1[x][y])
            pathfinder[x][y] = '!';

        if (mazeR(x+1, y) == 0)
            return 0;

        if (mazeR(x, y+1) == 0)
            return 0;

        if (mazeR(x-1, y) == 0)
            return 0;

        if (mazeR(x, y-1) == 0)
            return 0;

        tempdata2[x][y]='.';
        return 1;
    }
    return 1;
}

int main()
{
    int help = 0;
    char s[10000];

    while (scanf("%s", s) > 0){
        tempdata1[help] = strdup(s);
        tempdata2[help] = strdup(s);
        pathfinder[help] = strdup(s);
        collumn = strlen(s);
        help++;
    }
    row = help;
    
    mazeL(0, 1);
    mazeR(0,1);

    for(int i = 0; i < row; i++){
        printf("%s\n",pathfinder[i]);
    }

    return 0;
}
