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

#ifndef GRAPHS_DATA_H
#define GRAPHS_DATA_H


#include <map>
#include <cstdlib>
#include <typeinfo>

#include "../util/Functions.h"
#include "../exceptions/Exceptions.h"
#include "../arrays/MapArray.h"


using namespace std;

/**
 * Data Structure
 *
 * Class that contains all attributes of nodes and edges of the graph
 */
struct Data {

protected:

    // Hash table that hold attributes
    MapArray<string, string> _attrs;

    /**
     * Add attribute
     */
    template<typename T> void _add(string, T);

public:

    /**
     * Returns attributes
     */
    MapArray<string, string> attrs() const;

    /**
     * Check whether data has this attribute key
     */
    const bool has(string);

    /**
     * Remove node's attribute
     */
    void removeAttr(string);

    /**
     * Remove all attributes
     */
    void clear();

    /**
     * Set attribute
     */
    template<typename T> const void set(string, T);

    /**
     * Rename attribute
     */
    void rename(string, string);

    /**
     * Get attribute by key
     */
    template<typename T> const T get(string);

    const string gets(string);
};

/**
 * Add attribute
 */
template<typename T> void Data::_add(string key, T value)  {

    string type = typeid(T).name();
    bool clause = (type.find("Node") != string::npos || type.find("Edge") != string::npos);
    _attrs[key] = clause ? Functions::getString(&value) : Functions::getString(value);


}

/**
 * Set attribute
 */
template<typename T> const void Data::set(string key, T value) {

    if (!has(key))
        throw KeyError(key);
    _add(key, value);
}

/**
 * Get attribute by key
 */
template<typename T> const T Data::get(string key) {

    if (has(key)) {

        T convertedValue;
        stringstream ss(_attrs[key]);

        if (ss >> convertedValue)
            return convertedValue;
        throw ConversionError(key);
    }
    throw KeyError(key);
}

/**
 * Returns attributes
 */
MapArray<string, string> Data::attrs() const {
    return _attrs;
}

/**
 * Check whether data has this attribute
 */
const bool Data::has(string attr) {

    for (map<string, string>::iterator it=_attrs.begin(); it!=_attrs.end(); it++) {
        if (attr.compare(it->first) == 0 && it->first.length() == attr.length()) {
            return true;
        }
    }
    return false;
}

/**
 * Removes attribute
 */
void Data::removeAttr(string attr) {
    if (has(attr)) {
        _attrs.erase(_attrs.find(attr));
    }
}

/**
 * Removes all attributes
 */
void Data::clear() {
    _attrs.clear();
}

/**
 * Renames attribute
 */
void Data::rename(string oldKey, string newKey) {

    if (!has(oldKey)) throw KeyError(oldKey);

    for (map<string, string>::iterator it = _attrs.begin(); it != _attrs.end(); it++) {
        if (it->first == oldKey) {
            _add(newKey, _attrs[oldKey]);
        }
    }
    removeAttr(oldKey);
}

const string Data::gets(string key) {
    if (has(key)) {
        return Functions::getString(_attrs[key]);
    }
    throw KeyError(key);
}


#endif //GRAPHS_DATA_H