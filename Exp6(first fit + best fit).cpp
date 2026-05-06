#include<iostream>
using namespace std;

int main() {
    int nb, np;
    int b1[10], b2[10], p[10];

    cout<<"Enter number of blocks: ";
    cin>>nb;

    cout<<"Enter block sizes:\n";
    for(int i=0;i<nb;i++) {
        cin>>b1[i];
        b2[i] = b1[i]; // copy for best fit
    }

    cout<<"Enter number of processes: ";
    cin>>np;

    cout<<"Enter process sizes:\n";
    for(int i=0;i<np;i++)
        cin>>p[i];

    // 🔹 FIRST FIT
    cout<<"\n--- First Fit ---\n";
    for(int i=0;i<np;i++) {
        bool allocated = false;

        for(int j=0;j<nb;j++) {
            if(b1[j] >= p[i]) {
                cout<<"Process "<<i<<" -> Block "<<j<<endl;
                b1[j] -= p[i];
                allocated = true;
                break;
            }
        }

        if(!allocated)
            cout<<"Process "<<i<<" not allocated\n";
    }

    // 🔹 BEST FIT
    cout<<"\n--- Best Fit ---\n";
    for(int i=0;i<np;i++) {
        int best = -1;

        for(int j=0;j<nb;j++) {
            if(b2[j] >= p[i]) {
                if(best == -1 || b2[j] < b2[best])
                    best = j;
            }
        }

        if(best != -1) {
            cout<<"Process "<<i<<" -> Block "<<best<<endl;
            b2[best] -= p[i];
        }
        else {
            cout<<"Process "<<i<<" not allocated\n";
        }
    }

    return 0;
}
