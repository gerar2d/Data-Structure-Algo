#include <iostream>
#include <string>

using namespace std;

struct fnode{
    string d;
    int n, s, tSize;
    fnode **ptr;
};

class Disk{
    public:
        Disk(){};
        void create(fnode* &f);
        int totalSize(fnode* &f);
        void fileSize(fnode* f, string s);
        void dirSizess(fnode* f, string s);
        void dirS(fnode* f, string s);
};

void Disk::create(fnode* &f){
    f = new fnode;
    cout<<"Directory or file name:  ";
    cin>>f->d;
    cout<<"size of the "<<f->d<<" disk in Ks.   ";
    cin>>f->s;
    cout<<"how many files or folder in the "<<f->d<<"   ";
    cin>>f->n;
    f->ptr = new fnode*[f->n];
    for (int i = 0; i < (f->n); i++) {f->ptr[i] = NULL;}

    for (int i = 0; i < (f->n); i++){create(f->ptr[i]);}
}

int Disk::totalSize(fnode* &f){
    f->tSize = f->s; 
    if (f->n != 0){
        for (int i = 0; i < f->n; i++) f->tSize += totalSize(f->ptr[i]);
     
    }
    return f->tSize;
}


void Disk::fileSize(fnode* f, string s){
    if (f->d == s){
        for (int i = 0; i < f->n; i++){
            if (f->ptr[i]->n == 0) cout<<f->ptr[i]->d<<" : "<<f->ptr[i]->s<<"K"<<endl;
        }
    }
    else{
        for (int i = 0; i < f->n; i++){
            fileSize(f->ptr[i], s);
        }
    }
}

void Disk::dirSizess(fnode* f, string s){
    if (f->d == s){
        int n = 0;
        for (int i = 0; i < f->n; i++){
            if (f->ptr[i]->n != 0) n += f->ptr[i]->tSize;   
        }
        cout<<"Size of the files or folder inside the disk: "<<n<<"K"<<endl;
    }
    else{
        for (int i  = 0; i < f->n; i++) dirSizess(f->ptr[i], s);
    }
}

void Disk::dirS(fnode* f, string s){
    if (f->d == s){
        cout<<"size of directory: "<<f->tSize<<"K"<<endl;
    }else{
        for (int i = 0; i < f->n; i++) dirS(f->ptr[i], s);
    }
}

int main(){
    Disk dk;
    fnode* f = NULL;
    dk.create(f);
    int n = dk.totalSize(f);
    cout<<"Total size of the Disk used = "<<n<<"K"<<endl;
    return 0;
}