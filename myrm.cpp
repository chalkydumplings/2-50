//
// Created by Julie Winer on 2019-10-02.
//
#include <fstream>
#include "myrm.h"
#include "filemanager.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

// takes a list of files to remove with whitespace and then I parse each file and remove
void myrm(string files)
{

}

/*
    vector<string> result;
    istringstream iss(files);

    for(string s;iss>>files;)
        result.push_back(files);

    //return result;

    //iterator thorught array

    cout<< result.size() <<endl; //ok yah itemized
    int counter;
    counter=result.size(); //size of array

    while(counter!=0)
    {    counter=counter-1;
        const char *file;

        const char* toRemove;

        result[counter].c_str();


        filemanager(result[counter].c_str()).Remove();
        cout<<"removed "<<result[counter]<<endl;
    */



    ;
//ok WORKS!!!!
int main(int argc, char *argv[])
{
//it works woo
    int i;

    for(i=1; i < argc; i++) {

            filemanager(argv[i]).Remove();

    }


}




