#include<iostream>
#include<unistd.h>
#include<sys/wait.h>
using namespace std;

int main() {
    pid_t pid;

    pid = fork();

    if(pid == 0) {
        cout<<"Child Process\n";
        cout<<"Child PID: "<<getpid()<<endl;
    }
    else {
        wait(NULL);
        cout<<"Parent Process\n";
        cout<<"Parent PID: "<<getpid()<<endl;
    }

    return 0;
}
