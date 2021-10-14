/* File Name: Lab4EC3.cpp
* Lab # and Assignment #: Lab #4 Exercise C
* Lab section: 1
* Completed by: Graydon Hall and Jared Kraus
* Submission Date: 2021-10-19
*/

//  ENSF 614 Lab 4 - Exercise C
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>

const int size = 6;
using namespace std;
struct City {
    double x, y;
    char name[30];
};

void write_binary_file(City cities[], int size, char* filename);
/* PROMISES: attaches an ofstream object to a binary file named "filename" and
 * writes the content of the array cities into the file.
 */

void print_from_binary(char* filename);
/* PROMISES: uses ifstream library object to open the binary file named
 * "filename", reads the content of the file which are objects of struct City
 * (one record at a time), and displays them on the screen. It also saves the records
 * into a text-file that its name must be the filename argument, but with the extension
 * of .txt
 */


int main() {
    char bin_filename[] = "cities.bin";
    
    City cities[size] = {{100, 50, "Calgary"},
        {100, 150, "Edmonton"},
        {50, 50, "Vancouver"},
        {200, 50, "Regina"},
        {500, 50, "Toronto"},
        {200, 50, "Montreal"}};
    
    write_binary_file(cities, size, bin_filename);
    cout << "\nThe content of the binary file is:" << endl;
    print_from_binary(bin_filename);
    return 0;
}

void write_binary_file(City cities[], int size, char* filename){
    ofstream stream(filename, ios::out | ios::binary);
    if(stream.fail()){
        cerr << "failed to open file: " << filename << endl;
        exit(1);
    }
    
    for(int i =0; i < size; i++)
        stream.write((char*)&cities[i], sizeof(City));
    stream.close();
}

void print_from_binary(char* filename) {


    // open input file stream we get cities from
    ifstream is(filename, ios::binary);
    if(is.fail()){
        cerr << "failed to open file: " << filename << endl;
        exit(1);
    }

    // output file we will write to
    ofstream ofs("output.txt", std::ofstream::trunc);
    if(ofs.fail()){
        cerr << "failed to open file: " << filename << endl;
        exit(1);
    }

    // read cities from input file
    City* cityHolder;
    
    // find nummber of cities, help from https://www.cppstories.com/2019/01/filesize/
    int begin = is.tellg();  // beginning value
    is.seekg (0, ios::end);  // go to end of file
    int end = is.tellg();  // find end value
    int num_cities = (end-begin)/sizeof(City);  // total number of cities
    is.seekg (0, ios::beg);  // go to beginning of stream again

    // read cities from file into array
    cityHolder = new City[num_cities];
    for(int i=0; i<num_cities; i++){
        is.read((char*)(&cityHolder[i]), sizeof(City));
    }

    // write to ouptput file
    for(int i=0; i<6; i++){
        cout << "Name: " << cityHolder[i].name << ", x coordinate: " 
        << cityHolder[i].x << ", y coordinate: " << cityHolder[i].y << endl;
        
        ofs << "Name: " << cityHolder[i].name << ", x coordinate: " 
        << cityHolder[i].x << ", y coordinate: " << cityHolder[i].y << endl;
    }

    // close our files
    is.close();
    ofs.close();
}




