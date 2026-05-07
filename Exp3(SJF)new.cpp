#include<iostream>
using namespace std;

int main() {

    int n, bt[10], wt[10], tat[10];

    cout<<"Enter number of processes: ";
    cin>>n;

    for(int i=0;i<n;i++) {
        cout<<"Enter BT: ";
        cin>>bt[i];
    }

    // sorting
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {

            if(bt[i] > bt[j]) {
                swap(bt[i], bt[j]);
            }
        }
    }

    wt[0]=0;

    for(int i=1;i<n;i++) {
        wt[i]=wt[i-1]+bt[i-1];
    }

    for(int i=0;i<n;i++) {
        tat[i]=wt[i]+bt[i];
    }

    cout<<"\nBT\tWT\tTAT\n";

    for(int i=0;i<n;i++) {
        cout<<bt[i]<<"\t"<<wt[i]<<"\t"<<tat[i]<<endl;
    }

    return 0;
}
