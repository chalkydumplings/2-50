//
// Created by Julie Winer on 2019-10-02.
//

#include "mydiff.h"
#include "filemanager.h"


 void mydiff(const char *file1 , const char *file2)
{


    filemanager(file1).Compare(file2);


}



int main(int argc, char *argv[])
{

    //mydiff("/Users/Julie/Desktop/poo.txt","/Users/Julie/Desktop/poo2.txt");
    mydiff(argv[1],argv[2]);

}