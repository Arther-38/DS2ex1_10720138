/**電資三 10720138 陳尚宏 DSex110720138 **/

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <time.h>
#include <math.h>

using namespace std;

typedef struct HeapNode
{

    string schNum,schName,majorNum,majorName,genre,DayNight,Edu,City;
    int sNum,tNum,gradu;

    HeapNode():schNum(""),schName(""),majorNum(""),majorName(""),genre(""),DayNight(""),Edu(""),City(""),sNum(-1),tNum(-1),gradu(-1) {};

    HeapNode(string a,string b,string c,string d,string e,string f,
             string g,string h,int i,int j,int k):schNum(a),schName(b),majorNum(c),majorName(d)
        ,genre(e),DayNight(f),Edu(g),City(h),sNum(i),tNum(j),gradu(k) {};

} Node;

/** Note

Apply array-based data structure to implement Heap

Fundamental Heap-related data structures implementation

Project list:
------------------
Max/Mini Heap (f)
MinMaxHeap
Double-ended Priority Queue (Deap)(f)
binomial heap
Fibonacci Heap

**/

class MaxHeap
{
private:
    vector<Node> Maxvec ;
public:

    bool readfile(string filename)
    {
        filename="input"+filename+".txt";
        cout<<filename<<endl;
        ifstream fin(filename.c_str());
        if(!fin)
        {
            cout<<"read file failed!\n\n";
            return false;
        }

        const char *sep="\t";

        string s;

        if(fin)
        {
            int count=0;

            for(int i=0; i<2; i++)
                getline(fin,s);

            while(getline(fin,s))
            {
                title=s;
                break;
            }

            while(getline(fin,s))
            {
                int count=0;
                Node arr;
                char* line;
                int len = s.length();
                line=new char [len+1];
                strcpy(line,s.c_str());

                char *p;
                p=strtok(line,sep);

                while(p)
                {
                    stringstream myStreamString;
                    myStreamString << p;
                    p=strtok(NULL,sep);
                    string myString = myStreamString.str();
                    //cout << myString << endl;

                    if(count>10)
                        count=0;

                    if(count == 0)
                        arr.schNum=myString;
                    else if(count == 1)
                        arr.schName=myString;
                    else if(count == 2)
                        arr.majorNum=myString;
                    else if(count == 3)
                        arr.majorName=myString;
                    else if(count == 4)
                        arr.DayNight=myString;
                    else if(count == 5)
                        arr.Edu=myString;
                    else if(count == 6)
                        arr.sNum=atoi(myString.c_str());
                    else if(count == 7)
                        arr.tNum=atoi(myString.c_str());
                    else if(count == 8)
                        arr.gradu=atoi(myString.c_str());
                    else if(count == 9)
                        arr.City=myString;
                    else if(count == 10)
                        arr.genre=myString;

                    if(count==10)
                    {
                        Maxvec.push_back(arr);
                        adjust_up(bottom());
                    }

                    count++;

                    /* vec[row].insert(vec.end(),p,p+strlen(p));
                     vec.insert(vec.end(),'a');*/
                }

                delete [] line;
            }

        }
        return true;
    }

    MaxHeap() {}

    string title;

    int Left(int i)
    {
        return (2*i+1);
    }

    int Right(int i)
    {
        return (2*i+2);
    }

    int Parent(int i)
    {
        return (i-1)/2;
    }

    int Size()
    {
        return Maxvec.size();
    }

    /*void deletef()
    {
        string num;
        int cur=atoi(searchf(num));
        Assign(Maxvec[cur],Maxvec[bottom]);
        Maxvec[bottom--]=0;
        if(bottom > 1){
            if(Maxvec[cur].gradu > Maxvec[Parent(cur)].gradu && cur>1)
                adjust_up(cur);
            else
                adjust_down(cur);
        }

    }//end delete

    int searchf(string num){

        int flag=0; // find init
        for(int i=0;i<Size()-1;i++){
            if(Maxvec[i].gradu==atoi(num))
            {
                flag=1;
                  break;
            }
        }

        if(flag==1)
            return i;
        else{
            cout<<"Data not found!!\n";
            return -1;
        }
    }//end search

    void modify(){

        string data;
        cout<<"Input data to modify: ";
        cin>>data;

        if(searchf(data)!=-1)
        {
            if(isMaxhp)
            int cur = searchf(data);

            Maxvec[cur].gradu=atoi(data);
            if(Maxvec[cur].gradu > Maxvec[Parent(cur)].gradu && cur>1)
                adjust_up(cur);
            else
                adjust_down(cur);
        }

    }

    bool isMaxhp(){

    }

    void adjust_down(){

    }*/

    void adjust_up(int cur)
    {
        while(cur>0)
        {
            if(Maxvec[cur].sNum <= Maxvec[Parent(cur)].sNum)
                break;
            else
                swap(Maxvec[cur],Maxvec[Parent(cur)]);
            cur=Parent(cur);
        }
    }

    int leftmost()
    {
        int i=0;
        while(((int)pow(2,i)) < Size()+1)
        {
            i++;
        }
        return (int)pow(2,i-1)-1;

    }

    int bottom()      //rightmost
    {
        return Maxvec.size()-1;
    }

    void ShowHeap()
    {
        for(int i=0; i<Maxvec.size(); i++)
            cout<<Maxvec[i].sNum<<"\t";

        cout<<"\nLeftmost index= "<<leftmost()<<endl;
        cout<<"leftmost= "<< Maxvec[leftmost()].sNum <<endl;
        cout<<"bottom= "<< Maxvec[bottom()].sNum <<endl;;
        cout<<endl;
    }

}; ///End class MaxHeap

/*class MinHeap
{
private:
    vector<Node> Minvec;

public:

    bool readfile(string filename)
    {
        filename="input"+filename+".txt";
        cout<<filename<<endl;
        ifstream fin(filename.c_str());
        if(!fin)
        {
            cout<<"read file failed!\n\n";
            return false;
        }

        const char *sep="\t";

        string s;

        if(fin)
        {
            int count=0;

            for(int i=0; i<2; i++)
                getline(fin,s);

            while(getline(fin,s))
            {
                title=s;
                break;
            }

            while(getline(fin,s))
            {
                int count=0;
                Node arr;
                char* line;
                int len = s.length();
                line=new char [len+1];
                strcpy(line,s.c_str());

                char *p;
                p=strtok(line,sep);

                while(p)
                {
                    stringstream myStreamString;
                    myStreamString << p;
                    p=strtok(NULL,sep);
                    string myString = myStreamString.str();
                    //cout << myString << endl;

                    if(count>10)
                        count=0;

                    if(count == 0)
                        arr.schNum=myString;
                    else if(count == 1)
                        arr.schName=myString;
                    else if(count == 2)
                        arr.majorNum=myString;
                    else if(count == 3)
                        arr.majorName=myString;
                    else if(count == 4)
                        arr.DayNight=myString;
                    else if(count == 5)
                        arr.Edu=myString;
                    else if(count == 6)
                        arr.sNum=atoi(myString.c_str());
                    else if(count == 7)
                        arr.tNum=atoi(myString.c_str());
                    else if(count == 8)
                        arr.gradu=atoi(myString.c_str());
                    else if(count == 9)
                        arr.City=myString;
                    else if(count == 10)
                        arr.genre=myString;

                    if(count==10)
                    {
                        Minvec.push_back(arr);
                        adjust_up(bottom());
                    }

                    count++;

                }

                delete [] line;
            }

        }
        return true;
    }

    MinHeap() {}

    string title;

    int Left(int i)
    {
        return (2*i+1);
    }

    int Right(int i)
    {
        return (2*i+2);
    }

    int Parent(int i)
    {
        return (i-1)/2;
    }

    int Size()
    {
        return Minvec.size();
    }

    void adjust_up(int cur)
    {
        while(cur>0)
        {
            if(Minvec[cur].sNum >= Minvec[Parent(cur)].sNum)
                break;
            else
                swap(Minvec[cur],Minvec[Parent(cur)]);
            cur=Parent(cur);
        }
    }

    int leftmost()
    {
        int i=0;
        while(((int)pow(2,i)) < Size()+1)
        {
            i++;
        }
        return (int)pow(2,i-1)-1;

    }

    int bottom()      //rightmost
    {
        return Minvec.size()-1;
    }

    void ShowHeap()
    {
        for(int i=0; i<Maxvec.size(); i++)
            cout<<Maxvec[i].sNum<<"\t";

        cout<<"\nLeftmost index= "<<leftmost()<<endl;
        cout<<"leftmost= "<< Minvec[leftmost()].sNum <<endl;
        cout<<"bottom= "<< Maxvec[bottom()].sNum <<endl;;
        cout<<endl;
    }
};///End class MinHeap
//void Huffman(){};

class MMHeap
{
private:
    vector<Node> MMvec;
public:

    bool readfile(string filename)
    {
        filename="input"+filename+".txt";
        cout<<filename<<endl;
        ifstream fin(filename.c_str());
        if(!fin)
        {
            cout<<"read file failed!\n\n";
            return false;
        }

        const char *sep="\t";

        string s;

        if(fin)
        {
            int count=0;

            for(int i=0; i<2; i++)
                getline(fin,s);

            while(getline(fin,s))
            {
                title=s;
                break;
            }

            while(getline(fin,s))
            {
                int count=0;
                Node arr;
                char* line;
                int len = s.length();
                line=new char [len+1];
                strcpy(line,s.c_str());

                char *p;
                p=strtok(line,sep);

                while(p)
                {
                    stringstream myStreamString;
                    myStreamString << p;
                    p=strtok(NULL,sep);
                    string myString = myStreamString.str();
                    //cout << myString << endl;

                    if(count>10)
                        count=0;

                    if(count == 0)
                        arr.schNum=myString;
                    else if(count == 1)
                        arr.schName=myString;
                    else if(count == 2)
                        arr.majorNum=myString;
                    else if(count == 3)
                        arr.majorName=myString;
                    else if(count == 4)
                        arr.DayNight=myString;
                    else if(count == 5)
                        arr.Edu=myString;
                    else if(count == 6)
                        arr.sNum=atoi(myString.c_str());
                    else if(count == 7)
                        arr.tNum=atoi(myString.c_str());
                    else if(count == 8)
                        arr.gradu=atoi(myString.c_str());
                    else if(count == 9)
                        arr.City=myString;
                    else if(count == 10)
                        arr.genre=myString;

                    if(count==10)
                    {
                        MMvec.push_back(arr);
                        Heapify(bottom);
                    }

                    count++;

                }

                delete [] line;
            }

        }
        return true;
    }

    MMHeap() {}



};*/

class Deap
{
private:
    vector<Node> Dvec;
public:
    bool readfile(string filename)
    {
        Dvec.push_back(Node());
        cout<<"Dvec0= "<<Dvec[0].sNum<<endl;
        filename="input"+filename+".txt";
        cout<<filename<<endl;
        ifstream fin(filename.c_str());
        if(!fin)
        {
            cout<<"read file failed!\n\n";
            return false;
        }

        const char *sep="\t";

        string s;

        if(fin)
        {
            int count=0;

            for(int i=0; i<2; i++)
                getline(fin,s);

            while(getline(fin,s))
            {
                title=s;
                break;
            }

            while(getline(fin,s))
            {
                int count=0;
                Node arr;
                char* line;
                int len = s.length();
                line=new char [len+1];
                strcpy(line,s.c_str());

                char *p;
                p=strtok(line,sep);

                while(p)
                {
                    stringstream myStreamString;
                    myStreamString << p;
                    p=strtok(NULL,sep);
                    string myString = myStreamString.str();
                    //cout << myString << endl;

                    if(count>10)
                        count=0;

                    if(count == 0)
                        arr.schNum=myString;
                    else if(count == 1)
                        arr.schName=myString;
                    else if(count == 2)
                        arr.majorNum=myString;
                    else if(count == 3)
                        arr.majorName=myString;
                    else if(count == 4)
                        arr.DayNight=myString;
                    else if(count == 5)
                        arr.Edu=myString;
                    else if(count == 6)
                        arr.sNum=atoi(myString.c_str());
                    else if(count == 7)
                        arr.tNum=atoi(myString.c_str());
                    else if(count == 8)
                        arr.gradu=atoi(myString.c_str());
                    else if(count == 9)
                        arr.City=myString;
                    else if(count == 10)
                        arr.genre=myString;

                    if(count==10)
                    {
                        Dvec.push_back(arr);
                        Heapify();
                    }

                    count++;
                }

                delete [] line;
            }

        }
        return true;
    }

    Deap() {}

    string title;

    int Left(int i)
    {
        return (2*i+1);
    }

    int Right(int i)
    {
        return (2*i+2);
    }

    int Parent(int i)
    {
        return (i-1)/2;
    }

    int MinRoot()
    {
        return 1;
    }

    int MaxRoot()
    {
        return 2;
    }

    int Size()
    {
        return Dvec.size();
    }

    int bottom()      //rightmost
    {
        return Dvec.size()-1;
    }

    int Floor(int cur)
    {
        int f=log(cur+1)/log(2)+1;
        return f;
    }

    void Max_adjust_up(int cur)
    {
        while(cur>2)
        {
            if(Dvec[cur].sNum <= Dvec[Parent(cur)].sNum)
                break;
            else
                swap(Dvec[cur],Dvec[Parent(cur)]);
            cur=Parent(cur);
        }

    }///End Max_adjust_up

    void Min_adjust_up(int cur)
    {
        while(cur>2)
        {
            if(Dvec[cur].sNum >= Dvec[Parent(cur)].sNum )
                break;
            else
                swap(Dvec[cur],Dvec[Parent(cur)]);
            cur=Parent(cur);
        }

    }///End Min_adjust_up

    bool IsAtMax(int cur)
    {
        while( Parent(cur)!=0)
        {
            cur=Parent(cur);
        }

        if(cur == MaxRoot())
        {
            return true;
        }
        else
            return false;

    }///End IsAtMax

    bool IsAtMin(int cur)
    {
         while( Parent(cur)!=0)
        {
            cur=Parent(cur);
        }
        if(cur == MinRoot())
        {
            return true;
        }

        else
            return false;

    }///End IsAtMin

    int corr_find(int cur) ///correspond node
    {
        int floor = log(cur+1)/log(2)+1;
        int corr;

        if(IsAtMax(cur))
        {
             corr=cur-pow(2,floor-2);
        }

        if(IsAtMin(cur))
        {
            corr=cur+pow(2,floor-2);
            if(corr>Size()-1)
                corr=Parent(corr);
        }

        return corr;

    }///End Min_corr_find

    void Heapify()
    {
                        //cout<<"find= "<<corr_find(bottom())<<endl;
        if(IsAtMax(bottom()) && bottom()>2)
        {
            if(Dvec[bottom()].sNum < Dvec[corr_find(bottom())].sNum)
            {
                 swap(Dvec[bottom()],Dvec[corr_find(bottom())]);
                 Min_adjust_up(corr_find(bottom()));
            }

            else
            {
                Max_adjust_up(bottom());
            }

        }

        if(IsAtMin(bottom()) && bottom()>2)
        {
            if(Dvec[bottom()].sNum > Dvec[corr_find(bottom())].sNum)
            {
                 swap(Dvec[bottom()],Dvec[corr_find(bottom())]);
                 Max_adjust_up(corr_find(bottom()));
            }

            else
            {
                Min_adjust_up(bottom());
            }
        }

    } ///End Heapify

    int leftmost()
    {
        int i=0;
        while(((int)pow(2,i)) < Size()+1)
        {
            i++;
        }
        return (int)pow(2,i-1)-1;

    }

    void ShowHeap()
    {
        int floor=1;
        for(int i=1; i<Dvec.size(); i++)
        {
            cout<<Dvec[i].sNum<<"\t";
            if(Floor(i+1) != Floor(i))
                cout<<"\n";
        }
        cout<<"\n"<<Floor(5)<<endl;
        cout<<"\n\nLeftmost index= "<<leftmost()<<endl;
        cout<<"leftmost= "<< Dvec[leftmost()].sNum <<endl;
        cout<<"bottom= "<< Dvec[bottom()].sNum <<endl;;

        cout<<endl;
    }
};

/*
class binoHeap: public Heap{
private:
    vector<Node> Bvec;
public:

};

class FiboHeap: public Heap{
private:
    vector<Node> Fibo;
public:


};*/

int main()
{
    string filename;
    cin>>filename;
    Deap D;
    MaxHeap Max;
    D.readfile(filename);
    D.ShowHeap();
    Max.readfile(filename);
    Max.ShowHeap();
    return 0;
}
