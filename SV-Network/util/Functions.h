//////////////////////////////////////////////////
//                                              //
// SV-Network                                   //
// Created by startVal                          //
//                                              //
// Twitter: @startval                           //
// Facebook: https://www.facebook.com/startval  //
// Website: http://www.startval.com             //
//                                              //
//////////////////////////////////////////////////
//                                              //
// Developer: Pau Sanchez                       //
//                                              //
// Twitter: @pausanchezv                        //
// Website: http://www.pausanchezv.com          //
//                                              //
//////////////////////////////////////////////////
//                                              //
// startVal © 2017 - All Rights Reserved        //
//                                              //
//////////////////////////////////////////////////

#ifndef SV_NETWORK_FUNCTIONS_H
#define SV_NETWORK_FUNCTIONS_H

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

/**
 * Class Functions
 *
 * This class contains general functions for working with strings, vectors, files...
 */
class Functions {

public:

    /**
     * Converts any object to a string
     */
    template <typename T> static string getString(T);

    /**
     * Check whether vector contains a certain element
     */
    template <typename T> static const bool contains(vector<T>, T);

    /**
     * Creates and returns a copy of array
     */
    template <typename TObj> static const vector<TObj> makeArrayCopy(vector<TObj>);

    /**
     * Remove item of vector
     */
    template <typename T> static void removeItem(vector<T> *, T);

    /**
     * Check whether file exists or not
     */
    static bool exists(const string &name);

};

/**
 * Converts any object to a string
 */
template<typename T>
string Functions::getString(T obj){
    stringstream ss;
    string str;
    ss << obj;
    //ss >> str;
    getline(ss, str);
    return str;
}

/**
 * Check whether vector contains a certain element
 */
template<typename T>
const bool Functions::contains(vector<T> array, T item) {
    return find(array.begin(), array.end(), item) != array.end();
}

/**
 * Creates and returns a copy of array
 */
template<typename TObj>
const vector<TObj> Functions::makeArrayCopy(vector<TObj> array) {
    vector<TObj> arrayCopy;
    for (TObj obj : array) {
        arrayCopy.push_back(obj);
    }
    return arrayCopy;
}

/**
 * Remove item of vector
 */
template<typename T>
void Functions::removeItem(vector<T> *array, T item) {
    array->erase(std::remove(array->begin(), array->end(), item), array->end());
}

/**
 * Check whether the file exists or not
 */
bool Functions::exists(const string &name) {
    if (FILE *file = fopen(name.c_str(), "r")) {
        fclose(file);
        return true;
    }
    return false;
}


#endif //SV_NETWORK_FUNCTIONS_H
