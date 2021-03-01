//	Daljeet Singh
//  105165075


#include <iostream>
#include <stdio.h>             //declaring libraries
#include <string>
#include <map>
 
using namespace std;
 
typedef struct                         //declaring structure
{
    string full;
    string name;
    string ext;  
    bool candidate;
}FILENAME;
 
map<string, int> namemap;
map<string, int> extmap;  
 
int main()                                   //main function
{ 
    int test;
    bool blank = false;
    scanf("%d", &test);
 
    while(test--)                              //while loop
    {
        if(blank) puts("");
        else blank = true;
 
        if(!namemap.empty()) namemap.clear();
        if(!extmap.empty()) extmap.clear();
 
        int fileNum, message;
        scanf("%d%d", &fileNum, &message);                       //scanning
        FILENAME filename[fileNum];
 
        for(int i = 0 ; i < fileNum ; i++)                    //for loop
        {
            cin>>filename[i].full;
            int len = filename[i].full.length();
            bool hasExt = false;
            int dot = 0;
            for(dot = 0 ; dot < len ; dot++) //for loop
            {
                if(filename[i].full[dot] == '.' && dot != len - 1)                     /if condition
                { 
                    hasExt = true;
                    break;
                }
            }
            if(hasExt) //if condition
            {
                filename[i].name = filename[i].full.substr(0, dot);
                filename[i].ext = filename[i].full.substr(dot + 1);
            }
 
            else //else condition
            {
                if(filename[i].full[len - 1] == '.')
                {
                    filename[i].name = filename[i].full.substr(0, len - 1);
                }
                else
                {
                    filename[i].name = filename[i].full.substr(0);
                }
                filename[i].ext = " ";
            }
            if(extmap.find(filename[i].ext) != extmap.end()) //assigning and  comparing key
            {
                extmap[filename[i].ext]++;
            }
            else //else condition
            {
                extmap[filename[i].ext] = 1;
            }
 
            if(namemap.find(filename[i].name) != namemap.end()) //if condition
            {
                namemap[filename[i].name]++;
            }
            else
            {
                namemap[filename[i].name] = 1;
            }
            filename[i].candidate = true; //assigning candidate
        }
 
        int count = fileNum;
 
        for(int round = 1 ; round <= message ; round++)
        {
            for(int i = 0 ; i < fileNum ; i++)
            {
                if(filename[i].candidate)
                {
                    if(round&1) //if condition
                    {
                        if(extmap[filename[i].ext] == 1) //if condition
                        {
                            filename[i].candidate = false; //declaring
                            count--;
                            if(namemap[filename[i].name] > 1) //if condition
                            {
                                namemap[filename[i].name]--;
                            }
                        }
                    }
 
                    else //else condition
                    {
                        if(namemap[filename[i].name] == 1)
                        {
                            filename[i].candidate = false;
                            count--;
                            if(extmap[filename[i].ext] > 1)
                            {
                                extmap[filename[i].ext]--;
                            }
                        }
                    }
                }
            }
        }
 
        printf("%d\n", count);                                                              //printing result
        if(count)
        {
            for(int i = 0 ; i < fileNum ; i++)
            {
                if(filename[i].candidate)
                {
                    cout<<filename[i].full<<endl;
                }
            }
        }
    }
    return 0;
}