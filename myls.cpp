//
// Created by Julie Winer on 2019-10-02.
//

#include "myls.h"
#include "filemanager.h"
using namespace std;
const string getcwd()
{
    size_t buf_size = 1024;
    char* buf = NULL;
    char* r_buf;

    do {
        buf = static_cast<char*>(realloc(buf, buf_size));
        r_buf = getcwd(buf, buf_size);
        if (!r_buf) {
            if (errno == ERANGE) {
                buf_size *= 2;
            } else {
                free(buf);
                throw __error();
                // Or some other error handling code
            }
        }
    } while (!r_buf);

    string str(buf);
    free(buf);
    return str;
}
int main(int argc, char *argv[])
{
    if(argv[1]=="") //if no argument provided expand current working path
    {
       getcwd().c_str();
        filemanager(getcwd().c_str()).Expand(getcwd().c_str());
    }
    else {
        if (argv[2] == "-l") {
            cout << "Displaying Long Option" << endl;


        } else {

            filemanager(argv[1]).Expand(argv[1]);// your run of the mill expand
        }
    }

}