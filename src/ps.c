#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        write(1, "Not enough arguments\n", 22);
        return (0);
    }
    write(1, argv+1, 1);
}