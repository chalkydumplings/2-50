//
// Created by Julie Winer on 2019-10-02.
/// This method is similiar to how I did mvrm
#include "mycat.h"
#include "filemanager.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>


void mycat(string fileList) {
/*
    vector<string> result;
    istringstream iss(fileList);

    for (string s; iss >> fileList;)
        result.push_back(fileList);

    //return result;

    //iterator thorught array

    cout << result.size() << endl; //ok yah itemized
    int counter;
    counter = result.size(); //size of array

    while (counter != 0) {
        counter = counter - 1;
        const char *file;

        const char *toRemove;

        result[counter].c_str();


        filemanager(result[counter].c_str()).DumpAndPrint();
        cout << "" << result[counter] << endl;
*/
    }

int main(int argc, char *argv[]) {
//it works woo
    int i;

    for (i = 1; i < argc; i++) {

        filemanager(argv[i]).DumpAndPrint();


        //mycat("/Users/Julie/Desktop/a.txt /Users/Julie/Desktop/b.txt");
    }
}