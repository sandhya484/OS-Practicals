#include<iostream>
using namespace std;

int main() {
    int pages[50], frame[10];
    int n, f, faults = 0, index = 0;

    cout<<"Enter number of pages: ";
    cin>>n;

    cout<<"Enter page reference string:\n";
    for(int i=0;i<n;i++)
        cin>>pages[i];

    cout<<"Enter number of frames: ";
    cin>>f;

    // Initialize frames with -1
    for(int i=0;i<f;i++)
        frame[i] = -1;

    for(int i=0;i<n;i++) {
        bool found = false;

        // Check if page already in frame
        for(int j=0;j<f;j++) {
            if(frame[j] == pages[i]) {
                found = true;
                break;
            }
        }

        if(!found) {
            frame[index] = pages[i];
            index = (index + 1) % f; // circular replacement
            faults++;
        }

        // Display frames
        cout<<"Frame: ";
        for(int j=0;j<f;j++)
            cout<<frame[j]<<" ";
        cout<<endl;
    }

    cout<<"Total Page Faults = "<<faults;
    return 0;
}
