//
// Created by Julie Winer on 2019-10-02.
//

#include "mystat.h"
#include "filemanager.h"

#include <iostream>
using namespace std;

void mystat(const char *fileName)
{
    filemanager poo(fileName);

    cout<<"The FileName is : "<<poo.getName()<<endl;
    cout<<"The FileType is : "<<poo.getType()<<endl;
    cout<<"The FileSize is : "<<poo.getFilesize()<<endl;
    cout<<"The INT Owner is: "<<poo.getOwnerInt()<<endl;
    cout<<"The String owner is: "<<poo.getOwnerString()<<endl;
    cout<<"The INT group is:" <<poo.getGroupInt()<<endl;
    cout<<"The String group is: " <<poo.getGroupString()<<endl;
    cout<<"The permissions are: " <<poo.getPermissions()<<endl;
    cout<<"The Access time is: " <<poo.getAccesstime()<<endl;
    cout<<"The Mod time is: " <<poo.getModetime()<<endl;
    cout<<"The Status change time is: " <<poo.getStatuschange()<<endl;
    cout<<"The Blocksize is: " <<poo.getBlocksize()<<endl;
    cout << "number of children: " <<poo.getChildren() << endl;
}

int main(int argc, char *argv[])
{   mystat(argv[1]);
    //mystat("/Users/Julie/Desktop/poo.txt");

}