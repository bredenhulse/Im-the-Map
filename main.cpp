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
        size++;
        //adds to map if not there
        if(countz.find(num) != countz.end()){
            countz.insert(pair<int, int>(num, times));
            countz[num]++;
        }
        for(int j = 0; j < size; j++){
            if(info[j] == countz[num]){
                countz[num]++;
            }
        }
    }
    //print
        for(const auto &elem : countz){
            fout << elem.first << " " << elem.second << endl;
        }
        fout << endl;
        countz.clear();
}