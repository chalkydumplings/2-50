#include <iostream>
#include "filemanager.h"
#include "mycp.h"
#include <stdio.h>
using namespace std;


int main() {
//this is the main function

        //ok let's try making an instance of the name
        filemanager poo("/Users/Julie/Desktop/poo.txt");

        cout <<"Hello World HEHE" <<poo.getName()<<poo.getFilesize()<< endl;
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
        ofstream file2("/Users/Julie/Desktop");
        poo.ExpandCharlie("/Users/Julie/Desktop/Crap");
        //cout << "Remove File Error code: " <<poo.RemoveFile("poo33.txt") << endl;
        //cout << "Comparing functions" <<poo.Compare() << endl;

        ofstream   file("fuckyes.txt");

    poo.Dump(file);



    //cout<<"The Error number: " <<poo.getErrornum()<<endl;
        //cout<<"The Rename int code: " <<poo.getRenameError("poo33.txt")<<endl;

        //cout<<"The Error string is: " <<poo.getErrorstring()<<endl;





        //filemanager nowork("sdjhsdsid.txt");
        //cout<<"The Error number: " <<nowork.getErrornum()<<endl;
        //cout<<"The Rename is: " <<nowork.getRenameError("thistext.txt")<<endl;


        //test if nowork

/*
    char ch;




    ifstream document1("poo333.txt");
    ofstream document2("thistestt.txt");
    string str;

    
        getline(document1, str);

        document2 << str << endl;

    
    document1.close();
    document2.close();


    ifstream f1("poo33.txt");
    ofstream f2("2020yo.txt");

    if(!f1)
        cerr <<"Can't open IN file\n";
    if(!f2)
        cerr << "Can't open OUT file\n";

    while(f1 && f1.get(ch) )
        f2.put(ch);op

*/
    return 0;
}