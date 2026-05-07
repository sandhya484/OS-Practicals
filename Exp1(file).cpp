#include<iostream>
#include<fcntl.h>
#include<unistd.h>
#include<cstring>
using namespace std;

int main() {
    int fd;
    char data[] = "Hello Linux File";
    char buffer[100];

    fd = creat("demo.txt", 0777);

    write(fd, data, strlen(data));
    close(fd);

    fd = open("demo.txt", O_RDONLY);
    int n = read(fd, buffer, sizeof(buffer));
    buffer[n] = '\0';

    cout<<"File Data: "<<buffer<<endl;

    close(fd);
    unlink("demo.txt");

    return 0;
}
