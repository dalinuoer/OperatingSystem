semaphore deskMutex = 1, aHwMutex = 0, bHwMutex = 0;

void aTeacher()// 甲老师
{
    while (1)
    {
        批作业;
        wait(deskMutex);
        把作业放在桌上;
        signal(aHwMutex);
    }
}

void bTeacher()// 乙老师
{
    while (1)
    {
        批作业;
        wait(deskMutex);
        把作业放在桌上;
        signal(bHwMutex);
    }
}

void aStudent()// 甲同学
{
    while (1)
    {
        wait(aHwMutex);
        拿走甲老师批完的作业;
        signal(deskMutex);
    }
}

void bStudent()// 乙同学
{
    while (1)
    {
        wait(bHwMutex);
        拿走乙老师批完的作业;
        signal(deskMutex);
    }
}