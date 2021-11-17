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
            countz.insert(pair<int, int>(num, times));
            countz[info[i]]++;
        }
        //increases value of key if there again
        for(int j = 0; j < info.size(); j++){
            if(info[j] == countz[info[i]]){
                countz[info[i]]++;
            }
        }
    //print
        for(const auto &elem : countz){
            fout << elem.first << " " << elem.second << endl;
        }
    }
}
