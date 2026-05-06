#include<iostream>
using namespace std;

int main() {
    int pages[50], frame[10], time[10];
    int n, f, faults = 0, counter = 0;

    cout<<"Enter number of pages: ";
    cin>>n;

    cout<<"Enter page reference string:\n";
    for(int i=0;i<n;i++)
        cin>>pages[i];

    cout<<"Enter number of frames: ";
    cin>>f;

    for(int i=0;i<f;i++) {
        frame[i] = -1;
        time[i] = 0;
    }

    for(int i=0;i<n;i++) {
        bool found = false;

        for(int j=0;j<f;j++) {
            if(frame[j] == pages[i]) {
                counter++;
                time[j] = counter;
                found = true;
                break;
            }
        }

        if(!found) {
            int lru = 0;

            for(int j=1;j<f;j++) {
                if(time[j] < time[lru])
                    lru = j;
            }

            frame[lru] = pages[i];
            counter++;
            time[lru] = counter;
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
