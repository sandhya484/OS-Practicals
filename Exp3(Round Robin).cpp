#include<iostream>
using namespace std;

int main() {
    int n, tq, bt[10], rem[10], wt[10], tat[10];

    cout<<"Enter number of processes: ";
    cin>>n;

    cout<<"Enter burst time:\n";
    for(int i=0;i<n;i++) {
        cin>>bt[i];
        rem[i] = bt[i];
    }

    cout<<"Enter time quantum: ";
    cin>>tq;

    int time = 0;

    while(true) {
        bool done = true;

        for(int i=0;i<n;i++) {
            if(rem[i] > 0) {
                done = false;

                if(rem[i] > tq) {
                    time += tq;
                    rem[i] -= tq;
                } else {
                    time += rem[i];
                    wt[i] = time - bt[i];
                    rem[i] = 0;
                }
            }
        }

        if(done) break;
    }

    for(int i=0;i<n;i++)
        tat[i] = wt[i] + bt[i];

    cout<<"\nBT\tWT\tTAT\n";
    for(int i=0;i<n;i++)
        cout<<bt[i]<<"\t"<<wt[i]<<"\t"<<tat[i]<<endl;

    return 0;
}
