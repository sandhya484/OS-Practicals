#include<iostream>
#include<thread>   // for threads
using namespace std;

bool flag[2] = {false, false};  // indicates interest of processes
int turn;                       // whose turn it is

// function for critical section
void critical_section(int i) {
    cout << "Process " << i << " is in Critical Section\n";
}

// function for remaining section
void remainder_section(int i) {
    cout << "Process " << i << " is in Remainder Section\n";
}

// Peterson solution implementation
void process(int i) {
    int j = 1 - i;  // other process

    flag[i] = true;   // I want to enter
    turn = j;         // give chance to other

    // wait until other process is done
    while(flag[j] && turn == j);

    // critical section
    critical_section(i);

    flag[i] = false;  // I am done

    // remainder section
    remainder_section(i);
}

int main() {
    thread t1(process, 0);
    thread t2(process, 1);

    t1.join();
    t2.join();

    return 0;
}
