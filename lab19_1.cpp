#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstdlib>

using namespace std;

char score2grade(int score){
    if(score >= 80) return 'A';
    if(score >= 70) return 'B';
    if(score >= 60) return 'C';
    if(score >= 50) return 'D';
    else return 'F';
}

string toUpperStr(string x){
    string y = x;
    for(unsigned i = 0; i < x.size();i++) y[i] = toupper(x[i]);
    return y;
}

void importDataFromFile(string filename,vector<string> &names,vector<int> &scores,vector<char> &grades){
    string textline;
    char name[100];
    int x,y,z,count=0;
    ifstream source(filename.c_str());
    while (getline(source,textline)){
        sscanf(textline.c_str(),"%[^:]:%d %d %d",name,&x,&y,&z);
        names.push_back(name);
        scores.push_back(x+y+z);
        grades.push_back(score2grade(scores[count]));
        count+=1;
    }
}

void getCommand(string &command,string &key){
    cout<<"Please input your command: ";
    string ccc;
    char c[100],k[100];
    getline(cin,ccc);
    sscanf(ccc.c_str(),"%s %[^1234567890]",c,k);
    command=c;
    key=k;
}

void searchName(vector<string> names,vector<int> scores,vector<char> grades,string key){
    bool x=1;
    cout << "---------------------------------\n";
    for (unsigned int i=0;i<names.size();i++){
        if(toUpperStr(names[i])==toUpperStr(key)){
            printf("%s's score = %d\n%s's grade = %c\n",names[i].c_str(),scores[i],names[i].c_str(),grades[i]);
            x=0;
        }
    }
    if(x) cout<<"Cannot found.\n";
    cout << "---------------------------------\n";
}

void searchGrade(vector<string> names,vector<int> scores,vector<char> grades,string key){
    bool x=1;
    cout << "---------------------------------\n";
    for (unsigned int i=0;i<names.size();i++){
        if(grades[i]==key[0]){
            printf("%s (%d)\n",names[i].c_str(),scores[i]);
            x=0;
        }
    }
    if(x) cout<<"Cannot found.\n";
    cout << "---------------------------------\n";
}


int main(){
    string filename = "name_score.txt";
    vector<string> names;
    vector<int> scores;
    vector<char> grades; 
    importDataFromFile(filename, names, scores, grades);
    
    do{
        string command, key;
        getCommand(command,key);
        command = toUpperStr(command);
        key = toUpperStr(key);
        if(command == "EXIT") break;
        else if(command == "GRADE") searchGrade(names, scores, grades, key);
        else if(command == "NAME") searchName(names, scores, grades, key);
        else{
            cout << "---------------------------------\n";
            cout << "Invalid command.\n";
            cout << "---------------------------------\n";
        }
    }while(true);
    
    return 0;
}
