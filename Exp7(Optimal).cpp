#include<iostream>
using namespace std;

int main() {
    int pages[50], frame[10];
    int n, f, faults = 0;

    cout<<"Enter number of pages: ";
    cin>>n;

    cout<<"Enter page reference string:\n";
    for(int i=0;i<n;i++)
        cin>>pages[i];

    cout<<"Enter number of frames: ";
    cin>>f;

    for(int i=0;i<f;i++)
        frame[i] = -1;

    for(int i=0;i<n;i++) {
        bool found = false;

        for(int j=0;j<f;j++) {
            if(frame[j] == pages[i]) {
                found = true;
                break;
            }
        }

        if(!found) {
            int pos = -1, farthest = i;

            for(int j=0;j<f;j++) {
                int k;
                for(k = i+1; k<n; k++) {
                    if(frame[j] == pages[k])
                        break;
                }

                if(k == n) {  // not used again
                    pos = j;
                    break;
                }

                if(k > farthest) {
                    farthest = k;
                    pos = j;
                }
            }

            if(pos == -1)
                pos = 0;

            frame[pos] = pages[i];
            faults++;
        }

        cout<<"Frame: ";
        for(int j=0;j<f;j++)
            cout<<frame[j]<<" ";
        cout<<endl;
    }

    cout<<"Total Page Faults = "<<faults;
    return 0;
}
