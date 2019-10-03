//
// Created by Julie Winer on 2019-09-30.
//



#ifndef filemanager_h
#define filemanager_h

#include <stdio.h>
#include <vector>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <errno.h>
#include <dirent.h>
using namespace std;
class filemanager
{
private:
    //gonna make all these attirbutes private
    //move this all to header
    const char* name;
    //int type;
    int type;
    int size;
    int intOwner;
    string stringOwner;
    int intGroup;
    string stringGroup;
    string permissions;
    string permission;
    int accesstime;
    int modetime;
    int statuschange;
    int blocksize;
    int errornum;
    string errorstring;
    struct dirent *entity;// var for children
    DIR *directory;// var for children
    //int renamed;
    std::vector <filemanager> children;


public:

    filemanager(const char *name);
    ~filemanager();
    void mycp(char const* source ,ofstream &dest);
    void RenameFile();
    int RemoveFile(const char *pathname);

    void Expand();
    int getChildren();
    int getRenameError(const char *newpath);
    int getErrornum();
    int getBlocksize();
    int getStatuschange();
    int getModetime();
    int getAccesstime();
    string getGroupString();
    int getGroupInt();
    string getOwnerString();
    string getPermissions();
    int getOwnerInt();
    size_t getFilesize();
    int getType();
    const char*  getName();
    //int renamed{};


    basic_string <char, char_traits<char>, allocator<char> > Compare(const char *pathname);

    const char *compareError;

    void Dump2(const char *name);


    void Dump(ostream &fileStream); //this is one I use other is a prototype

    void Dump2(ifstream &fileStream);

    void Dump(ofstream &fileStream);

    int Remove();

    void DumpAndPrint();


    void ExpandCharlie(const char *filePath);
};
#endif /* fileManager_hpp */
