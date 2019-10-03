//
// Created by Julie Winer on 2019-09-30.
//

//#include "filemanager.h"

#include "filemanager.h"
#include <iostream>
#include <vector>
#include <string.h>
#include <fstream>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <errno.h>
#include <dirent.h>
#include<stdio.h>
#include<stdlib.h>


//how in the fuck do I add a header file I do not know lol
using namespace std; //saves typing later

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
int renamed;
std::vector <std::string> children;
string compareError;


filemanager::filemanager(const char *name)
{
//class filemanager // contstructor and class have same name remember !!
//{
//private:
    //gonna make all these attirbutes private
    //move this all to header




    // use this to append RWX permissions

    //string type=stat(name,&buf);

//public: //this will be all the getters for the class

    //~filemanager();
    //filemanager(const char* name) //keep this public maybe change later
    //{
    this->compareError="False";
    this->errornum=0;
    this->name=name;
    //struct passwd *getpwuid(uid_t);

    struct stat st;
    if(stat(name, &st) != 0) {
        cout<<"error file doesn't exist NOOB"<<endl;
        this->errornum=errno;
    }//later use this as counter increment

    struct passwd pass = *getpwuid(st.st_uid);
    this->stringOwner = pass.pw_name;


    this->size=st.st_size;
    this->type=st.st_mode;
    this->intOwner=st.st_uid;// int user id

    struct group grp = *getgrgid(st.st_gid);
    this->stringGroup = grp.gr_name;

    this->intGroup=st.st_gid;
    //this->stringOwner=getpwuid(501);

    //permissions
    this->permission = (S_ISDIR(st.st_mode)) ? "d" : "-";
    this->permissions=permissions.append(permission);
    this->permission = (st.st_mode & S_IRUSR) ? "r" : "-";
    filemanager::permissions.append(permission);
    permission = (st.st_mode & S_IWUSR) ? "w" : "-";
    filemanager::permissions.append(permission);
    permission = (st.st_mode & S_IXUSR) ? "x" : "-";
    filemanager::permissions.append(permission);
    permission = (st.st_mode & S_IRGRP) ? "r" : "-";
    filemanager::permissions.append(permission);
    permission = (st.st_mode & S_IWGRP) ? "w" : "-";
    filemanager::permissions.append(permission);
    permission = (st.st_mode & S_IXGRP) ? "x" : "-";
    filemanager::permissions.append(permission);
    permission = (st.st_mode & S_IROTH) ? "r" : "-";
    filemanager::permissions.append(permission);
    permission = (st.st_mode & S_IWOTH) ? "w" : "-";
    filemanager::permissions.append(permission);
    permission = (st.st_mode & S_IXOTH) ? "x" : "-";
    filemanager::permissions.append(permission);

    //acess time
    this->accesstime=st.st_atim.tv_nsec;
    this->modetime=st.st_mtim.tv_nsec;
    this->statuschange=st.st_ctim.tv_nsec;

    this->blocksize=st.st_blksize;
    // SPACE FOR CHILDREN GO  BACK
    //this->errorstring=strerror_r();


    //this is for rename

    if (S_ISDIR(st.st_mode))
    {
        directory = opendir(name);

        // for each entity within the directory add it's name to our children vector
        while((entity = readdir(directory)) != NULL)
        {
            filemanager::children.push_back(entity->d_name);
        }
    }

    // constructor deconstructor


    //_____________END OF CONTSRUCTOR_______________________

}

//this one is hards but looks like you just need it to rename from source to desitnation\
//ok using method form online we see
void filemanager::Dump2(const char *named)
{
    char ch, fname1[20], fname2[20];
    ifstream fs;
    ofstream ft;

    fs.open(name); // open original file to copy

    if(!fs)// if file has error just give error code and exit
    {
        cout<<"error opening first file go away";
        getchar(); // not sure what this does
        exit(1);

    }

    ft.open(named);
    if(!ft)
    {
        cout<<"error with second file provide";
        fs.close();
        getchar();
        exit(2); //what do the diff int error codes mean again????

    }

    while(fs.eof()==0) // while your not at end of file copy this file over to other file
        //maybe add in a codition that will see if file is big enought to copy stuff over to
    {
        fs>>ch;
        ft<<ch;
    }

    cout<<"file copied sucess";
    fs.close();
    ft.close();
    getchar();



}
void filemanager::DumpAndPrint() {


    char ch;
    ifstream f1(name);



    while (f1 && f1.get(ch)) {

        cout<< ch <<endl;
    }
}

    void filemanager::Dump(ofstream &f2)
    {


    char ch;
    ifstream f1(name);

        //cerr << "Can't open OUT file\n";

    while(f1 && f1.get(ch) ) {
        f2.put(ch);
    }
    /*
     *
    char line[blocksize + 1];
    int numRead= 0;
    ifstream myfile(name);
    if(!myfile.is_open())
    {
        cout<<"ERROR";
        errornum= errno;
        cout<< errornum <<endl;
        return;
    }
    while(numRead= myfile.readsome(line, blocksize))
    {
        line[numRead]=0;
        fileStream << line;
    }
    myfile.close();
     */
}

void filemanager::RenameFile() {

}
//still need to test this one out
int filemanager::RemoveFile(const char *pathname) {
    return unlink(pathname);// returns if unlink was sucessful

}



int filemanager::Remove()
        {
    return unlink(name);
        };

basic_string<char, char_traits<char>, allocator<char> > filemanager::Compare(const char *pathname) {

    if (filemanager(name).getBlocksize()==filemanager(pathname).getBlocksize()){
        cout<< "The files are the same size and will be compared line to line "<<endl;
        compareError="None";

        // this is where the bulk of the compare function comes in to play



        char ch; // this is for orginal file
        char ch2;// this if file being compared
        ifstream f1(name); //read stream
        ifstream f2(pathname);

        while (f1 && f1.get(ch) and f2 && f2.get(ch2))
        {
            if (ch!=ch2)
            {
                cout<< "They are not the same";

                exit(1);
                }
            //cout<< ch <<endl;
        }



        cout<< "update they are the same  "<<endl;

        //set compare attirbute
    }
    else if(filemanager(name).getBlocksize()>filemanager(pathname).getBlocksize())  {
        cout<< "The files are not the same"<<endl;compareError="None";
    }

    else if(filemanager(name).getBlocksize()<filemanager(pathname).getBlocksize())  {
        cout<< "The files are not the same "<<endl;
        compareError="None";
    }

    else{
        cout<< "Sorry the file can't be compared because there is an errror "<<endl;
        compareError="YES";
    }

    return compareError;

}


void filemanager::ExpandCharlie(const char* filePath) {
    directory = opendir(filePath);
    if (directory == NULL) {
        // if opendir was unsuccessful store errno
        filemanager::errornum = errno;
    } else {
        // for each entity within the directory add it's name to our children vector
        while ((entity = readdir(directory)) != NULL) {
            // im getting these entities appear even in empty directories for some reason, so im filtering them out
            if (strcmp(entity->d_name, ".") != 0 && strcmp(entity->d_name, "..") != 0 &&
                strcmp(entity->d_name, ".DS_Store") != 0) {
                printf("%s\n", entity->d_name);
                string path = filePath;
                path += "/";
                path += entity->d_name; // get the full path of the new file
                const string::size_type size = path.size();
                char *buffer = new char[size + 1];
                memcpy(buffer, path.c_str(), size + 1); // transfer the string to char *
                filemanager child(buffer); // create a new fileManager object for the child
                filemanager::children.push_back(child); // add it to the vector
            }
        }
    }
}


//getter for size amazing
size_t filemanager::getFilesize() {
    return size;
}

int filemanager::getOwnerInt(){
    return intOwner;
}

//getter for permissions
string filemanager:: getPermissions(){
    return permissions;
}





string  filemanager::getOwnerString()
{
    return stringOwner;
}

int filemanager::getGroupInt()
{
    return intGroup;

}

string filemanager::getGroupString(){
    return stringGroup;
}

// permissions obtained via conditional statements
// and the mask values defined in the debian manual for st_mode



int filemanager::getAccesstime() {
    return accesstime;
}

int filemanager::getModetime(){
    return modetime;
}
int filemanager::getStatuschange(){
    return statuschange;
}
int filemanager::getBlocksize(){
    return blocksize;
}

int filemanager::getErrornum(){
    return errornum;
}

int filemanager::getRenameError(const char *newpath){
    renamed=rename(name,newpath);
    return renamed; //this is the error code if sucessful
    //try this function with paths
    //0= sucess and _____ = fail
}

int filemanager::getChildren(){
    return children.size();
}

int filemanager::getType() {
    return type;
}

const char *filemanager::getName() {

    return name;
}

filemanager::~filemanager() {

}




//string getErrorstring(){s
//return errorstring;}

//children

// if the file is a directory






