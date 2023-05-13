#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int main() {

    if (chdir("..") == -1) {
        perror("chdir");
        return 1;
    }

    printf("New working directory: %s\n", getcwd(NULL, 0));
    return 0;
}
