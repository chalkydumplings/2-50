//
// Created by Julie Winer on 2019-10-01.
//This is used to make a copy of a file from a source to a destination
//

#include "filemanager.h" // learn why its .h and not CPP later
//YAH IT WORKS
using namespace std;

void mycp(const char* source ,const char *target) // this copies file to stream of choice should work
{
    ofstream fileDest(target);
    filemanager og(source);
    og.Dump(fileDest);

 cout<<"SUCESS DUMP"<<endl;


}
//FUCK YAH IT WORKS!!
int main(int argc, char *argv[]) {

    ofstream   file("/Users/Julie/Desktop/mymom.pdf");

    mycp(argv[1], argv[2]);

}

