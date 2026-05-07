#include<iostream>
using namespace std;

int main() {

    int n, tq, bt[10], rem[10], wt[10]={0}, tat[10], time=0;

    cout<<"Enter number of processes: ";
    cin>>n;

    for(int i=0;i<n;i++) {
        cout<<"Enter BT: ";
        cin>>bt[i];

        rem[i]=bt[i];
    }

    cout<<"Enter Time Quantum: ";
    cin>>tq;

    bool done;

    do {
        done=true;

        for(int i=0;i<n;i++) {

            if(rem[i]>0) {

                done=false;

                if(rem[i]>tq) {
                    time+=tq;
                    rem[i]-=tq;
                }
                else {
                    time+=rem[i];
                    wt[i]=time-bt[i];
                    rem[i]=0;
                }
            }
        }

    } while(!done);

    for(int i=0;i<n;i++) {
        tat[i]=bt[i]+wt[i];
    }

    cout<<"\nBT\tWT\tTAT\n";

    for(int i=0;i<n;i++) {
        cout<<bt[i]<<"\t"<<wt[i]<<"\t"<<tat[i]<<endl;
    }

    return 0;
}
