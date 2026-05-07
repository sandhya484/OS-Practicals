#include<iostream>
#include<unistd.h>
#include<sys/stat.h>
#include<dirent.h>

using namespace std;

int main()
{
    DIR *dir;
    struct dirent *entry;

    char path[100];

    // Create Directory
    if(mkdir("MyDirectory",0777)==0)
        cout<<"Directory Created Successfully\n";
    else
        cout<<"Directory Creation Failed\n";

    // Change Directory
    if(chdir("MyDirectory")==0)
        cout<<"Changed to MyDirectory\n";
    else
        cout<<"Cannot Change Directory\n";

    // Get Current Working Directory
    getcwd(path,sizeof(path));

    cout<<"Current Path: "<<path<<endl;

    // Go back to parent directory
    chdir("..");

    // Open Current Directory
    dir = opendir(".");

    if(dir == NULL)
    {
        cout<<"Cannot Open Directory\n";
        return 0;
    }

    cout<<"\nDirectory Contents:\n";

    // Read Directory
    while((entry = readdir(dir)) != NULL)
    {
        cout<<entry->d_name<<endl;
    }

    // Close Directory
    closedir(dir);

    // Remove Directory
    if(rmdir("MyDirectory")==0)
        cout<<"\nDirectory Removed Successfully\n";
    else
        cout<<"\nDirectory Remove Failed\n";

    return 0;
}
