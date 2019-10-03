//
// Created by Julie Winer on 2019-10-01.
//
//

#include "mymv.h"
#include "filemanager.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

//@paramters destination and new name of file
//@return nothing



void mymv(const char *source,const char *target)
{

    ofstream fileDest(target);
    filemanager og(source); // create an object of the orginal file
    //og.getRenameError(newname);//renmame orginal file
    og.Dump(fileDest); //dump the file in the new location with new name
    og.RemoveFile(source);// remove orginal path

    filemanager newName(target);
    //newName.getRenameError(dest);



}

int main(int argc, char *argv[])
{
// OK WORKS GOLDEN !!!
   // mymv("/Users/Julie/Desktop/po77oppoo.txt","/Users/Julie/po77oppoo.txt");


   mymv(argv[1],argv[2]);
}