/*
Name: Breden Hulse
Class: Computer Science 2
Description: Will say how many times a number appears.
*/
#include <unordered_map>
#include <fstream>
#include <iostream>
#include <vector>

 using namespace std;

int main(){
    //Opens input file
    ifstream fin;
    fin.open("input.txt");
    //Opens and creates output file
    ofstream fout;
    fout.open("outfile");

    int num;
    int pos = 0;
    int times = 0;
    int size = 0;
    vector<int> info;
    unordered_map<int, int> countz;

    //adds all numbers to vector
    while(fin >> num){
        info.push_back(num);
    }

    for(int i = 0; i < info.size(); i++){
        //adds to map if not there
        if(countz.find(info[i]) == countz.end()){
            countz.insert(make_pair(info[i], 0));
        }
        countz[info[i]]++;
    }
    auto a = new int [countz.size()][2];

    for(const auto &elem : countz){
        a[pos][0] = elem.first;
        a[pos][1] = elem.second;
        pos++;
    }
    //print
    for(int i = countz.size() - 1; i >= 0; i -= 1){
        fout << a[i][0] << " " << a[i][1] << endl;
    }
}
