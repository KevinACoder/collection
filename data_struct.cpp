//
//  data_struct.cpp
//  boost_t
//
//  Created by KevinLiu on 2018/11/17.
//  Copyright © 2018 KevinLiu. All rights reserved.
//

#include "data_struct.hpp"
#include "stddefine.h"
#include <boost/array.hpp>
#include <boost/random.hpp>
#include <boost/generator_iterator.hpp>
#include <boost/dynamic_bitset.hpp>
#include <boost/unordered_map.hpp>
#include <boost/unordered_set.hpp>
#include <boost/assign/list_of.hpp>
#include <algorithm>
#include <set>
#include <map>

typedef boost::mt19937 RNGType;

void array_demo() //canot assign init val, can not grow size, do not have iter
{
    const size_t len = 5;
    RNGType rng;
    boost::uniform_int<> ont_to_hundrund(1, 100);
    boost::array<int, len> arr1;
    boost::variate_generator<RNGType, boost::uniform_int<>>
    dice(rng, ont_to_hundrund);
    
    //assign value to 0
    arr1.assign(0);
    
    //assign random value
    for(size_t i = 0; i < len; ++i){
        arr1[i] = dice();
        int *p = arr1.c_array(); //raw ptr
        cout<<*(p + i)<<" ";
    }
    cout<<endl;
    cout<<"last: "<<arr1.back()<<endl;
    
    //sort array
    std::sort(arr1.begin(), arr1.end());
    for(auto a : arr1){
        cout<<a<<" ";
    }
    cout<<endl;
    
    //referenc array
    /*unsigned char szInt[10];
    ref_array<unsigned char> rarr(szInt. 10);
    ra[0] = 25;
    for(auto a : ra){
        cout<<a<<" ";
    }
    cout<<endl;*/
}

void bitset_demo()
{
    //create bit set
    boost::dynamic_bitset<> db1;
    boost::dynamic_bitset<> db2(string("0100"));
    
    //print bit set
    db1 = db2;
    cout<<db1.to_ulong()<<endl;
    for(size_t i = 0; i < db2.size(); ++i){
        cout<<db2[i];
    }
    cout<<endl;
    
    //construct a compile time binary num
    boost::dynamic_bitset<> db3(5, BOOST_BINARY(01110));
    if(!db3.empty()){
        cout<<db3<<endl;
    }
    
    //operator as container
    db1.resize(64, true);
    cout<<"db1:"<<db1<<" block(memory size):"<<db1.num_blocks()<<endl;
    db2.resize(8, false);
    db1.push_back(true);
    db1.push_back(true);
    db1.push_back(true);
    db1.append(0x0101); //appebd nore bits
    cout<<"db1:"<<db1<<" block(memory size):"<<db1.num_blocks()<<endl;
    
    //access bit
    boost::dynamic_bitset<> db4(string("1111"));
    cout<<db4<<endl;
    if(db4.test(0)){
        cout<<"1st bit is true"<<endl;
    }
    
    if(db4.any()){
        cout<<"exist true bit"<<endl;
    }
    
    db4.resize(4, false);
    cout<<db4<<endl;
    if(db4.none()){
        cout<<db4<<"all false"<<endl;
    }
    
    db4.set(); //set all to true
    db4.flip(0);
    db4.reset();
    cout<<db4<<endl;
}

template<typename T>
void unordered_set_demo()
{
    T s = (boost::assign::list_of(1)(2)(3)(4)(5));
    for(auto it = s.begin(); it != s.end(); ++it){
        cout<<*it<<endl;
    }
    s.insert(8);
    s.insert(45);
    cout<<endl<<"size: "<<s.size()<<endl;
    
    if(s.find(8) != s.end()){
        cout<<*s.find(8)<<endl;
    }
    
    s.erase(45);
    if(s.find(45) == s.end()){
        cout<<"45 erased"<<endl;
    }
}

void unordered_map_demo()
{
    using namespace boost::assign;
    using namespace boost;
    
    //create unordered map
    boost::unordered_map<int, string> um = boost::assign::map_list_of(1, "one")(2, "two")(3, "three");
    um.insert(std::make_pair(10, "ten"));
    
    //iter
    for(auto p = um.begin(); p != um.end(); ++p){
        cout<<p->first<<"-"<<p->second<<endl;
    }
}

void data_struct_demo()
{
    //array_demo();
    //bitset_demo();
    //unordered_set_demo<boost::unordered_set<int>>();
    //unordered_set_demo<std::set<int>>();
    unordered_map_demo();
}
