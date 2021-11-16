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
    int times = 0;
    vector<int> info;
    unordered_map<int, int> countz;

    //adds all numbers to vector
    while(fin >> num){
        info.push_back(num);
    }

    //to see how many times a number happens
    for(int i = 0; i < info.size(); i++){
        //adds to map if not there
        if(countz.find(num) != countz.end()){
            countz.insert(pair<int, int>(num, times));
            times++;
        }
        for(int j = 0; j < info.size(); j++){
            if(info[j] == countz[i]){
                times++;
            }
        }
        //print
        fout << countz[i, times];
        times = 0;
    }
}